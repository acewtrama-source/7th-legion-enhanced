#!/usr/bin/env python3
"""Compare classic vs enhanced PathStep on scenarios; validates enhanced paths (legality + optimality).
usage: bench_path.py EXE SCENDIR PATCHDIR   (PATCHDIR from tools/build_patch.sh)"""
import sys,glob,struct,subprocess,heapq,re,statistics
exe,sd,pd=sys.argv[1:4]
meta=dict(l.split() for l in open(pd+'/meta.txt'))
DX=[0,1,0,-1,-1,1,1,-1];DY=[-1,0,1,0,-1,-1,1,1]
def load(f):
    d=open(f,'rb').read(); _,selfi,maxc,p,ns=struct.unpack_from('<4sIIII',d,0); o=20; seg={}
    for _ in range(ns):
        a,l=struct.unpack_from('<II',d,o); o+=8; seg[a]=d[o:o+l]; o+=l
    return selfi,seg
def run(f,enh):
    a=[ '/tmp/oracle32',exe,f]
    if enh!=None: a+=[pd+'/patch.bin','ade000',meta['path_dispatch'],meta['g_ruleset'],str(enh),meta['g_inited']]
    r=subprocess.run(a,capture_output=True,text=True)
    lines=[l for l in r.stdout.split('\n') if l]
    cyc=int(re.search(r'cycles (\d+)',r.stderr).group(1))
    calls=[l for l in lines if l[0]!='W']; st=int(calls[-1].split()[1],16)
    wp=None
    if lines and lines[-1][0]=='W': wp=[tuple(map(int,t.split(','))) for t in lines[-1].split()[2:]]
    return st,len(calls),wp,cyc
def cost(wp): return sum(14 if wp[i][0]!=wp[i+1][0] and wp[i][1]!=wp[i+1][1] else 10 for i in range(len(wp)-1))
def s16(b,o): return struct.unpack_from('<h',b,o)[0]
def walk_fn(selfi,seg):
    ents=seg[0x67fe10]; cls=seg[0x8352f0]; occg=seg[0x6d3920]; tile=struct.unpack('<16384H',seg[0x773450]); own=seg[0x8464f0]; bl=seg[0x805df0]; tt=seg[0x4c0874]
    E=lambda i,o:s16(ents,i*0x6d0+o)
    tb=E(selfi,0x46); te=E(selfi,0x48)
    def w(nx,ny):
        idx=nx*128+ny; occ=occg[idx]
        if occ==selfi+1: occ=0
        if te-occ==-1: occ=0
        if occ:
            o=occ-1
            if E(selfi,0)!=E(o,0) and s16(tt,E(selfi,2)*0x4c)!=0 and s16(tt,E(o,2)*0x4c)==0: occ=0
            if occ and (struct.unpack_from('<i',ents,o*0x6d0+0x2c)[0] or struct.unpack_from('<i',ents,o*0x6d0+0x30)[0]): occ=0
            if occ and E(o,0x62)==5: occ=0
        c=cls[idx]
        if tb!=-1:
            x0,y0,ww,hh=struct.unpack_from('<4I',bl,tb*0xe0+0x18)
            if x0<=nx<x0+ww and y0<=ny<y0+hh: c=1
        if c!=1: return False
        if tile[idx] in (0x3e5,0x3e6) and (own[idx]&15)==E(selfi,0): return False
        return occ==0
    return w
def opt(w,s,g,flee):
    dist={s:0};q=[(0,s)]
    while q:
        d,u=heapq.heappop(q)
        if u==g: return d
        if d>dist[u]: continue
        for k in range(8):
            v=(u[0]+DX[k],u[1]+DY[k])
            if 0<=v[0]<128 and 0<=v[1]<128 and w(*v):
                nd=d+(10 if k<4 else 14)
                if nd<dist.get(v,1e9): dist[v]=nd;heapq.heappush(q,(nd,v))
    return None
res=[];bad=0;n_opt=0;n_chk=0
for f in sorted(glob.glob(sd+'/sc*.bin')):
    selfi,seg=load(f); ps=seg[0x67fe10][selfi*0x6d0+0xd4:selfi*0x6d0+0xd4+20]
    sx,sy,gx,gy=struct.unpack_from('<4h',ps,6)
    c=run(f,None); e=run(f,1)
    w=walk_fn(selfi,seg); mode=s16(seg[0x67fe10],selfi*0x6d0+0x64); flee=s16(seg[0x67fe10],selfi*0x6d0+0x6e) in (6,9)
    if e[0]==3:
        wp=e[2]
        ok=wp[0]==(sx,sy) and all(abs(wp[i][0]-wp[i+1][0])<=1 and abs(wp[i][1]-wp[i+1][1])<=1 and wp[i]!=wp[i+1] for i in range(len(wp)-1)) and all(w(*q) for q in wp[1:])
        if not ok: bad+=1; print('ILLEGAL',f)
        if mode!=2 and not flee and wp[-1]==(gx,gy) and len(wp)<299:
            n_chk+=1; o=opt(w,(sx,sy),(gx,gy),False)
            if o is None or cost(wp)!=o: print('NOT OPTIMAL',f,cost(wp),o); bad+=1
            else: n_opt+=1
    res.append((f,c,e))
N=len(res)
for name,i in (('classic',1),('enhanced',2)):
    ok=sum(1 for r in res if r[i][0]==3); print(f'{name}: path found {ok}/{N}  mean calls {statistics.mean(r[i][1] for r in res):.1f}  mean kcycles {statistics.mean(r[i][3] for r in res)/1000:.0f}  max kcycles {max(r[i][3] for r in res)/1000:.0f}')
both=[r for r in res if r[1][0]==3 and r[2][0]==3 and r[1][2][-1]==r[2][2][-1]]
rat=[cost(r[2][2])/max(1,cost(r[1][2])) for r in both if cost(r[1][2])>0]
print(f'same-goal pairs {len(both)}: enhanced/classic path cost mean {statistics.mean(rat):.3f}  worse {sum(1 for x in rat if x>1.0001)}  better {sum(1 for x in rat if x<0.9999)}  max gain {min(rat):.2f}')
print('classic fail but enhanced ok:',sum(1 for r in res if r[1][0]!=3 and r[2][0]==3),' enhanced fail but classic ok:',sum(1 for r in res if r[1][0]==3 and r[2][0]!=3))
print(f'optimality verified on {n_opt}/{n_chk}; illegal/non-optimal: {bad}')
for r in both:
    if cost(r[1][2])>0 and cost(r[2][2])/cost(r[1][2])>1.0001:
        selfi,seg=load(r[0]); print('worse:',r[0],cost(r[1][2]),cost(r[2][2]),'mode',s16(seg[0x67fe10],selfi*0x6d0+0x64),'flee',s16(seg[0x67fe10],selfi*0x6d0+0x6e))

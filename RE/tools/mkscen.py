#!/usr/bin/env python3
"""Generate PathStep (0x439a00) differential-test scenarios from real decoded maps.
usage: mkscen.py DATADIR LEGION_EXE OUTDIR COUNT [SEED]
Scenario file: 'SCN1' u32 self u32 maxcalls u32 pathstate_va u32 nseg, then nseg*(u32 addr,u32 len,bytes)."""
import sys,os,struct,random,collections
sys.path.insert(0,os.path.dirname(__file__))
import mapdec
datadir,exe,outdir,count=sys.argv[1],sys.argv[2],sys.argv[3],int(sys.argv[4]); seed=int(sys.argv[5]) if len(sys.argv)>5 else 1
rnd=random.Random(seed); os.makedirs(outdir,exist_ok=True)
ex=open(exe,'rb').read()
def fo(va): return 0xa9c00+va-0x4ac000
dxdy=ex[fo(0x4b66e0):fo(0x4b66e0)+0x40]; typetab=ex[fo(0x4c0874):fo(0x4c0874)+48*0x4c]
maps=[n for n in ('000','001','002','003','004','005','006','007','020','030','040','050') if os.path.exists(os.path.join(datadir,f'MAPL.{n}'))]
cache={n:mapdec.load(datadir,n) for n in maps}
DX=[0,1,0,-1,-1,1,1,-1];DY=[-1,0,1,0,-1,-1,1,1]
def comp(L,s):
    seen={s};q=collections.deque([s])
    while q:
        a,b=q.popleft()
        for k in range(8):
            na,nb=a+DX[k],b+DY[k]
            if 0<=na<128 and 0<=nb<128 and (na,nb) not in seen and L[na*128+nb]==1: seen.add((na,nb));q.append((na,nb))
    return seen
def s16(v): return struct.pack('<h',v)
def u16(v): return struct.pack('<H',v&0xffff)
made=0;tries=0
while made<count and tries<count*20:
    tries+=1
    n=rnd.choice(maps); L,T=cache[n]
    land=[i for i in range(16384) if L[i]==1]
    if len(land)<200: continue
    si=rnd.choice(land); s=(si//128,si%128); C=comp(L,s)
    if len(C)<30: continue
    kind=rnd.random()
    far=[c for c in C if max(abs(c[0]-s[0]),abs(c[1]-s[1]))>=(3 if rnd.random()<.3 else 15)]
    if kind<.82 and far: g=rnd.choice(far)
    elif kind<.9: g=(rnd.randrange(128),rnd.randrange(128))   # maybe blocked/unreachable
    elif kind<.95: g=s
    else: g=rnd.choice(list(C))
    cls=bytearray(L); tile=list(T); occ=bytearray(16384); own=bytearray(rnd.randrange(256) for _ in range(16384))
    near=list(C)
    NE=190; ents=bytearray(NE*0x6d0)
    def E16(i,off,v): ents[i*0x6d0+off:i*0x6d0+off+2]=u16(v)
    def E32(i,off,v): ents[i*0x6d0+off:i*0x6d0+off+4]=struct.pack('<I',v&0xffffffff)
    K=rnd.choice([0,2,10,40,120,185]); selfi=rnd.randrange(0,K+1) if K else 0
    for i in range(K+1):
        E16(i,0,rnd.randrange(1,7)); E16(i,2,rnd.randrange(48)); E16(i,0xc,1 if rnd.random()<.93 else 0)
        E32(i,0x2c,rnd.choice([0,0,0,5])); E32(i,0x30,rnd.choice([0,0,0,0,7])); E16(i,0x62,rnd.choice([0,0,1,5,3]))
        if i!=selfi and rnd.random()<.9:
            c=rnd.choice(near)
            if rnd.random()<.5:  # cluster around the straight line start->goal
                t=rnd.random(); c=(int(s[0]+(g[0]-s[0])*t+rnd.randint(-2,2)),int(s[1]+(g[1]-s[1])*t+rnd.randint(-2,2)))
                if not(0<=c[0]<128 and 0<=c[1]<128): continue
            occ[c[0]*128+c[1]]=i+1
    # mover
    E16(selfi,0,rnd.randrange(1,7)); E16(selfi,2,rnd.choice([1,3,3,4,5,12,13,30,40,47])); E16(selfi,0xc,1)
    E16(selfi,0x64,rnd.choice([0,1,2,2,2,5])); E16(selfi,0x6e,rnd.choice([0,0,0,6,9,3])); E16(selfi,0x92,rnd.choice([32,64,128,200,320]))
    blds=bytearray(64*0xe0); tb=-1; te=-1
    for bi in range(64):
        o=bi*0xe0; w,h=rnd.randint(1,5),rnd.randint(1,5); x0=rnd.randrange(0,120); y0=rnd.randrange(0,120)
        if bi==0 and rnd.random()<.35:   # target building around goal, even over blocked terrain
            x0=min(max(g[0]-rnd.randrange(w),0),122); y0=min(max(g[1]-rnd.randrange(h),0),122); tb=0
        blds[o:o+4]=struct.pack('<I',1 if rnd.random()<.97 else 0); blds[o+8:o+12]=struct.pack('<I',1)
        blds[o+0x18:o+0x28]=struct.pack('<4I',x0,y0,w,h)
    if tb==-1 and rnd.random()<.1: tb=rnd.randrange(64)
    if rnd.random()<.2 and K>=1: te=(selfi+1)%(K+1)
    E16(selfi,0x46,tb); E16(selfi,0x48,te)
    if rnd.random()<.7: E16(selfi,0x40,g[0]*32+rnd.randrange(32)); E16(selfi,0x42,g[1]*32+rnd.randrange(32))
    else: E16(selfi,0x40,0xffff); E16(selfi,0x42,0xffff)
    for _ in range(rnd.choice([0,0,5,60])):   # mines
        c=rnd.choice(near); tile[c[0]*128+c[1]]=rnd.choice([0x3e5,0x3e6,0x3e5])
    infl=bytearray(7*0x2000)
    for _ in range(rnd.choice([0,0,200,3000])):
        p=rnd.randrange(1,7); i=rnd.randrange(4096); infl[p*0x2000+i*2:p*0x2000+i*2+2]=s16(rnd.choice([-2,1,3,8,30]))
    # path state
    po=selfi*0x6d0+0xd4
    ents[po:po+2]=u16(1); ents[po+2:po+4]=s16(-1)
    ents[po+6:po+14]=struct.pack('<4h',s[0],s[1],g[0],g[1])
    slots=bytearray(13*0x2ef4)
    used=rnd.choice([0,0,0,3,12,13])
    for i in range(13): slots[i*0x2ef4:i*0x2ef4+2]=u16(0 if i<used else 0xffff)
    segs=[(0x8352f0,bytes(cls)),(0x6d3920,bytes(occ)),(0x773450,b''.join(u16(t) for t in tile)),(0x8464f0,bytes(own)),(0x78fde0,bytes(infl)),
          (0x67fe10,bytes(ents)),(0x805df0,bytes(blds)),(0x6e75c0,bytes(slots)),(0x4b66e0,dxdy),(0x4c0874,typetab)]
    with open(os.path.join(outdir,f'sc{made:04d}.bin'),'wb') as f:
        f.write(b'SCN1'+struct.pack('<4I',selfi,400,0x67fe10+selfi*0x6d0+0xd4,len(segs)))
        for a,d in segs: f.write(struct.pack('<2I',a,len(d))+d)
    made+=1
print('made',made)

#!/usr/bin/env python3
"""mkpe.py: wrap code ranges of legion.exe into a minimal PE32 (same VAs, image base 0x400000) with an
export per function address, so Ghidra/REA can decompile pointer-only functions it did not define.
usage: mkpe.py legion.exe out.exe START-END[,START-END...] ADDR[,ADDR...]   (hex, ranges page-aligned by us)"""
import sys,struct
exe,out,ranges,addrs=sys.argv[1:5]
d=open(exe,'rb').read()
pe=struct.unpack_from('<I',d,0x3c)[0]
nsec=struct.unpack_from('<H',d,pe+6)[0]; opt=struct.unpack_from('<H',d,pe+20)[0]
sec=pe+24+opt; secs=[]
for i in range(nsec):
    n,vs,va,rs,ro=struct.unpack_from('<8sIIII',d,sec+i*40); secs.append((va+0x400000,max(vs,rs),ro))
def off(v):
    for va,sz,ro in secs:
        if va<=v<va+sz: return ro+v-va
    raise SystemExit('va not in exe: %x'%v)
IB=0x400000
rng=[]
for r in ranges.split(','):
    a,b=[int(x,16) for x in r.split('-')]
    a&=~0xfff; b=(b+0xfff)&~0xfff; rng.append((a,b))
addrs=sorted(set(int(x,16) for x in addrs.split(',')))
FA=0x200
def al(x,a): return (x+a-1)//a*a
# sections
sections=[]  # (name, rva, data)
for a,b in rng:
    o=off(a); sections.append(('.t%x'%(a>>12),a-IB,d[o:o+(b-a)]))
top=max(r+len(dd) for _,r,dd in sections); edrva=al(top,0x1000)
names=['f_%x'%a for a in addrs]; order=sorted(range(len(names)),key=lambda i:names[i])
n=len(addrs)
ed=bytearray(40+4*n+4*n+2*n)
strs=bytearray(); dllname=b'legion_slice.exe\0'
base_str=edrva+len(ed)
dllrva=base_str; strs+=dllname
nrvas=[]
for i in order:
    nrvas.append(base_str+len(strs)); strs+=names[i].encode()+b'\0'
afr=edrva+40; anr=afr+4*n; aor=anr+4*n
struct.pack_into('<IIHHIIIIIII',ed,0,0,0,0,0,dllrva,1,n,n,afr,anr,aor)
for i,a in enumerate(addrs): struct.pack_into('<I',ed,40+4*i,a-IB)
for k,i in enumerate(order):
    struct.pack_into('<I',ed,40+4*n+4*k,nrvas[k]); struct.pack_into('<H',ed,40+8*n+2*k,i)
sections.append(('.edata',edrva,bytes(ed)+bytes(strs)))
edsize=len(ed)+len(strs)
hdr=bytearray(0x400)
hdr[0:2]=b'MZ'; struct.pack_into('<I',hdr,0x3c,0x80)
hdr[0x80:0x84]=b'PE\0\0'
entry=addrs[0]-IB
struct.pack_into('<HHIIIHH',hdr,0x84,0x14c,len(sections),0,0,0,0xE0,0x0102)
o=0x98
sizeimg=al(max(r+len(dd) for _,r,dd in sections),0x1000)
struct.pack_into('<HBBIIIIIIIIIHHHHHHIIIIHHIIIIII',hdr,o,0x10b,6,0,0,0,0,entry,0x1000,0,IB,0x1000,FA,4,0,0,0,4,0,0,sizeimg,0x400,0,3,0,0x100000,0x1000,0x100000,0x1000,0,16)
# data directories
dd=o+96
struct.pack_into('<II',hdr,dd,edrva,edsize)
so=dd+16*8
raw=0x400; body=b''
for nme,rva,data in sections:
    rs=al(len(data),FA)
    ch=0x60000020 if nme!='.edata' else 0x40000040
    struct.pack_into('<8sIIIIIIHHI',hdr,so,nme.encode(),len(data),rva,rs,raw,0,0,0,0,ch)
    so+=40; raw+=rs; body+=data+bytes(rs-len(data))
open(out,'wb').write(bytes(hdr)+body)
print('wrote',out,len(hdr)+len(body),'sections',[(s[0],hex(s[1]+IB),len(s[2])) for s in sections],'exports',n)

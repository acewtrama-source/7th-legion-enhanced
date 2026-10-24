#!/usr/bin/env python3
"""Safety check for patch_exe.py hooks: no direct branch/call in legion.exe may land INSIDE an overwritten range (after its first byte).
usage: check_hooks.py legion.exe legion_enh.exe   (needs objdump). Compares .text of both exes to find patched ranges.
Lesson (Oct 23): hook at 0x465356 overwrote 0x46535a, a jump target => crash 'Called From MainGameLoop ... 0x0046535a'."""
import sys,re,subprocess
a=open(sys.argv[1],'rb').read(); b=open(sys.argv[2],'rb').read()
lo,hi=0x400,0x400+(0x4a9000-0x401000)
ranges=[]; i=lo
while i<hi:
    if a[i]!=b[i]:
        j=i
        while j<hi and (a[j]!=b[j] or (j+1<hi and a[j+1]!=b[j+1])): j+=1
        ranges.append((i-0x400+0x401000, j-i)); i=j
    i+=1
dis=subprocess.run(['objdump','-d','-M','intel','--start-address=0x401000','--stop-address=0x4a9000',sys.argv[1]],capture_output=True,text=True).stdout
tg={}
for l in dis.splitlines():
    m=re.match(r'\s+([0-9a-f]+):\t.*\t(j[a-z]+|call)\s+0x([0-9a-f]+)$',l)
    if m: tg.setdefault(int(m.group(3),16),[]).append(m.group(1))
bad=0
for s,n in ranges:
    hit=[(hex(t),v) for t,v in tg.items() if s<t<s+n]
    if hit: bad+=1; print('BAD',hex(s),n,hit)
print(len(ranges),'patched ranges,',bad,'with branch targets inside')
sys.exit(1 if bad else 0)

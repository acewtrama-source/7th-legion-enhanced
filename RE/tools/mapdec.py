#!/usr/bin/env python3
"""Decode 7th Legion map files (DATA/MAP*.NNN). Verified vs loader 0x402c40 + decoder 0x438f50.
usage: mapdec.py DATADIR NNN  -> dict via import; CLI prints class-grid ASCII.
Layout: all grids 128x128, index = a*128+b  (a = pathfinder 'x', b = 'y').
  MAPL u8   -> terrain class grid 0x8352f0 ; decoded: v ^= a ; 1=passable, 0=void/water?, 64=blocked(?)
  MAPT u16  -> tile art grid 0x773450     ; decoded: running di=0x7530 (dec per cell, row-major): v=((v^di)-b)&0xffff
  MAPO u8   -> 0x67bd90 (objects?)  MAPOVL u16(32768B=128x128 u16) -> 0x84a500 (overlay)  [not decoded here]
  MAPCX/MAPCY/MAPCT -> 0x6df710/0x6e5c50/0x6e4e80 (size 6000/6000/3000, not decoded)
"""
import struct,sys,os
def load(datadir,n):
    L=bytearray(open(os.path.join(datadir,f'MAPL.{n}'),'rb').read())
    T=list(struct.unpack('<16384H',open(os.path.join(datadir,f'MAPT.{n}'),'rb').read()))
    di=0x7530
    for a in range(128):
        for b in range(128):
            i=a*128+b
            T[i]=((T[i]^di)-b)&0xffff; di=(di-1)&0xffff
            L[i]^=a
    return bytes(L),T
if __name__=='__main__':
    L,T=load(sys.argv[1],sys.argv[2])
    for a in range(128):
        print(''.join('.' if L[a*128+b]==0 else '+' if L[a*128+b]==1 else '#' for b in range(128)))

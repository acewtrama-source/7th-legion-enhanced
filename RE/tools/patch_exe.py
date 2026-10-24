#!/usr/bin/env python3
"""Make legion_enh.exe: adds section .patch (VA 0xADE000) with the enhanced pathfinder and redirects
the single `call 0x439a00` inside PathStart (0x438fcf) to path_dispatch. Classic stays default
(Siege.ini [options] ruleset=1 enables enhanced). usage: patch_exe.py legion.exe PATCHDIR out.exe [--no-call]   (--no-call: add the section but leave the call site unpatched; for bisecting loader problems)"""
import sys,struct
src,pd,out=sys.argv[1:4]; grow=False
d=bytearray(open(src,'rb').read()); blob=open(pd+'/patch.bin','rb').read()
meta=dict(l.split() for l in open(pd+'/meta.txt')); disp=int(meta['path_dispatch'],16); end=int(meta['_end'],16)
pe=struct.unpack_from('<I',d,0x3c)[0]; nsec=struct.unpack_from('<H',d,pe+6)[0]; opt=struct.unpack_from('<H',d,pe+20)[0]
secoff=pe+24+opt; base=struct.unpack_from('<I',d,pe+24+28)[0]; assert base==0x400000
falign=struct.unpack_from('<I',d,pe+24+36)[0]; salign=struct.unpack_from('<I',d,pe+24+32)[0]; hdrsz=struct.unpack_from('<I',d,pe+24+60)[0]
assert d[secoff+nsec*40:secoff+nsec*40+40]==bytes(40) and secoff+(nsec+1)*40<=hdrsz, 'no room for section header'
# redirect call
fo=0x400+(0x438fcf-0x401000); assert d[fo]==0xe8 and 0x438fd4+struct.unpack_from('<i',d,fo+1)[0]==0x439a00
if '--no-call' not in sys.argv: struct.pack_into('<i',d,fo+1,disp-0x438fd4)
# UI hooks (Ctrl+click = aggressive move): replace 9-byte movw at 0x46321d and 7-byte mov at 0x463687 by call+nops
def hook(va_site,orig,target):
    fo=0x400+(va_site-0x401000); assert bytes(d[fo:fo+len(orig)])==orig,(hex(va_site),bytes(d[fo:fo+len(orig)]).hex())
    d[fo]=0xe8; struct.pack_into('<i',d,fo+1,target-(va_site+5))
    for i in range(5,len(orig)): d[fo+i]=0x90
if '--ui' in sys.argv and '--no-call' not in sys.argv and 'hook_style' in meta:  # OFF by default: A+click aggressive move did not work in-game (menu defaults to Normal at press)
    hook(0x463687,bytes.fromhex('668b1d80958500'),int(meta['hook_style'],16))
# paged save/load menus (ruleset=1 at runtime): redirect the 3 menu call sites to the dispatchers in saves.c
def redirect(site,old,new):
    fo=0x400+(site-0x401000); assert d[fo]==0xe8 and site+5+struct.unpack_from('<i',d,fo+1)[0]==old,hex(site)
    struct.pack_into('<i',d,fo+1,new-(site+5))
if '--no-call' not in sys.argv and 'load_menu_dispatch' in meta:
    redirect(0x40dc2b,0x40e1d0,int(meta['load_menu_dispatch'],16)); redirect(0x43fb1b,0x40e1d0,int(meta['load_menu_dispatch'],16))
    redirect(0x43fafd,0x40e340,int(meta['save_menu_dispatch'],16))
# Phase 2 fix A: PostOrder dedupe bypass when idle (cmp %si,0x67fe88(%edi) -> jmp stub)
if '--no-call' not in sys.argv and 'post_dedupe_stub' in meta:
    site=0x42383f; fo=0x400+(site-0x401000); assert bytes(d[fo:fo+7])==bytes.fromhex('6639b788fe6700')
    d[fo]=0xe9; struct.pack_into('<i',d,fo+1,int(meta['post_dedupe_stub'],16)-(site+5)); d[fo+5]=0x90; d[fo+6]=0x90
if '--no-call' not in sys.argv and 'mode_stub' in meta:   # Fix B: fire-on-move for Move mode
    site=0x44f471; fo=0x400+(site-0x401000); assert bytes(d[fo:fo+7])==bytes.fromhex('668b867efe6700')
    d[fo]=0xe9; struct.pack_into('<i',d,fo+1,int(meta['mode_stub'],16)-(site+5)); d[fo+5]=0x90; d[fo+6]=0x90
if '--no-call' not in sys.argv and 'camp_btn' in meta:   # Back button on campaign screen
    redirect(0x40d48a,0x4758b0,int(meta['camp_btn'],16)); redirect(0x40d49c,0x476aa0,int(meta['camp_poll_stub'],16))
if '--no-call' not in sys.argv and 'camp_esc_stub' in meta:   # Esc on campaign screen: exit on release
    site=0x40d560; fo=0x400+(site-0x401000); assert bytes(d[fo:fo+9])==bytes.fromhex('66c705b4745400e703')
    d[fo]=0xe9; struct.pack_into('<i',d,fo+1,int(meta['camp_esc_stub'],16)-(site+5)); d[fo+5:fo+9]=b'\x90'*4
if '--no-call' not in sys.argv and 'text_load_hook' in meta:   # UI text overrides (ruleset=1): wrap language-text loader 0x450cb0
    redirect(0x40db87,0x450cb0,int(meta['text_load_hook'],16)); redirect(0x4510b0,0x450cb0,int(meta['text_load_hook'],16))
def jmp_over(site,orig_hex,target):
    fo=0x400+(site-0x401000); orig=bytes.fromhex(orig_hex); assert bytes(d[fo:fo+len(orig)])==orig,(hex(site),bytes(d[fo:fo+len(orig)]).hex())
    d[fo]=0xe9; struct.pack_into('<i',d,fo+1,target-(site+5))
    for i in range(5,len(orig)): d[fo+i]=0x90
if '--no-call' not in sys.argv and 'lobby_row_stub' in meta:   # MP/skirmish lobby: editable bot rows + AI faction, pack AI rows at start
    jmp_over(0x440add,'66393500ee4a00',int(meta['lobby_row_stub'],16))
    jmp_over(0x441563,'6633f666a3f8748500',int(meta['lobby_start_stub'],16))
if '--no-call' not in sys.argv and 'tm_h1' in meta:   # TEAMS (src/sim/teams.c): allied() checks replace owner==owner compares
    for site,orig,h in [(0x4556a4,'668b450066398610fe67000f84a8010000','tm_h1'),(0x44f4f3,'663bc17453','tm_h2'),
        (0x45a6ce,'8b86f05d80003bc8747c','tm_h3'),(0x45a954,'8b8ef05d80003bc10f8424060000','tm_h4'),
        (0x46898d,'3b1574cd5b00745f','tm_h5'),(0x46ad47,'390d74cd5b00740f','tm_h6'),(0x46adb0,'390574cd5b00747f','tm_h7'),
        (0x4686e3,'668b44241266394424187419','tm_h8'),(0x44d6e0,'8b1574cd5b003bd00f847b010000','tm_h9'),
        (0x41c4f4,'3bd9741e6639b2d0e78500','tm_h10'),(0x41c554,'663b05cc8c66007406','tm_h11')]:
        jmp_over(site,orig,int(meta[h],16))
    jmp_over(0x424caf,'0fbfd603d266398200478000',int(meta['tm_h12'],16))   # fair unit cap 178/N
    for site in (0x40f4b2,0x40ff65,0x416941,0x416ce9,0x41cf21): redirect(site,0x433a60,int(meta['load_game_hook'],16))  # teams from SAVEn.TMS
    redirect(0x440720,0x4758b0,int(meta['lobby_opts_btn'],16))           # team buttons in the lobby
    for site in (0x441203,0x441513):                                       # host broadcasts option ids 100..0x6e (was ..0x68)
        fo=0x400+(site-0x401000); assert d[fo]==0x68; d[fo]=0x6e
    fo=0x400+(0x40dc2b-0x401000); assert d[fo]==0xe8                         # main-menu Load clears teams
    struct.pack_into('<i',d,fo+1,int(meta['load_menu_main'],16)-(0x40dc2b+5))
if '--no-call' not in sys.argv and 'cheat_stub' in meta:   # dev chat cheats (src/sim/cheats.c), chat case of ExecuteCommands
    jmp_over(0x445fff,'8d81f4fd7900',int(meta['cheat_stub'],16))
if '--no-call' not in sys.argv and 'hq_list_stub' in meta:   # 'RE-ASSEMBLE HQ' entry in the build list (src/sim/cheats.c)
    jmp_over(0x465a5a,'668b2dc81f4c00',int(meta['hq_list_stub'],16))
    jmp_over(0x465d01,'668b0de0648500663df4017d51',int(meta['hq_hover2_stub'],16))
    jmp_over(0x465dcf,'668b166681faf401',int(meta['hq_click_stub'],16))
if '--no-call' not in sys.argv and 'deploy_try' in meta:   # truck deploy: try nearby spots, 'no room' message
    redirect(0x45746b,0x421d40,int(meta['deploy_try'],16))
va=0xade000; vsize=(end-va+salign-1)//salign*salign
while len(d)%falign: d.append(0)
raw=len(d)
if grow:
    last=secoff+(nsec-1)*40
    lvs,lva,lrs,lrp=struct.unpack_from('<4I',d,last+8); assert lrp+lrs==len(d) and base+lva+((lvs+salign-1)//salign*salign)==va
    pad=(va-base-lva)-lrs; assert pad>=0
    d+=bytes(pad); d+=blob
    while len(d)%falign: d.append(0)
    rsize=len(d)-lrp
    struct.pack_into('<II',d,last+8,(va-base-lva)+vsize,rsize)
    struct.pack_into('<I',d,last+36,0xE0000040)   # R+W+X, initialised data, not discardable
else:
    d+=blob
    while len(d)%falign: d.append(0)
    rsize=len(d)-raw
    hdr=b'.patch\0\0'+struct.pack('<IIIIIIHHI',vsize,va-base,rsize,raw,0,0,0,0,0xE0000060)
    d[secoff+nsec*40:secoff+nsec*40+40]=hdr
    struct.pack_into('<H',d,pe+6,nsec+1)
struct.pack_into('<I',d,pe+24+56,(va-base)+vsize)      # SizeOfImage
open(out,'wb').write(d); print('wrote',out,'section VA',hex(va),'vsize',hex(vsize),'raw',hex(raw),hex(rsize),'dispatch',hex(disp),'grow' if grow else '')

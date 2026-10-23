# Dev chat cheats (enhanced ruleset) - src/sim/cheats.c, rev 1 (Oct 23), untested in-game
Hook: 0x445fff (chat case, cmd kind 0x65, of ExecuteCommands 0x445930; `lea eax,[ecx+0x79fdf4]` -> cheat_stub). Runs on every peer at the
same lockstep point for the SENDER (record +0x21 byte = player, filled from 0x668ccc by chat poster 0x4657c6; text at +4, max 28 chars).
| phrase | effect |
|---|---|
| cheese steak khaos | credits 0x834a00[p] += 10000 |
| khaos car | random own-faction unit next to HQ (bldg type 0), random rank 1..4 (50/30/13/7%); nothing if HQ missing / no free tile / unit cap |
| khaos box | crate (effect 0x1b) next to HQ, content from crate table 0x4af878 |
Facts used [O]: chat record layout; ExecuteCommands zeroes 0x71667c (direct mode) so CreateUnit 0x424c20 runs directly; crate = 0x429de0(0x1b,1,x,y,-1,kind) (cmd kind 2 owner 0x2707 path 0x445a45); random crate drop 0x41a8f9: kind = 0x4af878[rand&0x3f] (tech filter), max 5 (0x4af8fc), CRT rand 0x49c540; free tile 0x4245c0(bldg, size UnitType+4) -> x | y<<16 (0 none); occupancy 0x6d3920[(x>>5)*128+(y>>5)] = ent+1; buildings 800 slots (0x805df0, stride 0xe0, +0 owner, +4 type, +8 alive).
Rank [O]: ENT +0xae (0..4), xp +0xb0, thresholds 0x4af820 = {6,20,50,100,180,256}; promotion (0x42cafc) = rank++, sparkle effect 0x1c, maxhp(+0x14) += 2, hp += 1 (clamped), 0x9d5ff0[owner] = max rank (HowToWin 5). Cheat sets rank, xp, maxhp += 2*rank, full hp; does not touch 0x9d5ff0.
Faction rosters = AI build lists: side 0 (7th) 0x4c4260 {2,4,6,8,10,14,19,21,33,34,36,38}; side 1 (Chosen) 0x4c4210 {2,3,9,15,19,21,33,34,37,38}; weights 60000/cost (UnitTypeTable +0xc): 500cr infantry ~41-47%, 10000cr type 38 ~2%.
Unit costs (type:cr): 2:3000 3:4000 4:4000 6:2250 8:7500 9:7500 10:3750 14:500 15:500 19:1500 21:4250 33:5000 34:6000 36:7000 37:7000 38:10000.
RNG: xorshift seeded from tick 0x6df3b0, sender, use count (deterministic across peers; game RNGs untouched).

## rev 2 (Oct 23): 'khaos car' reliability fix
CreateUnit 0x424c20 (decompiled in full, see below) searches a free ENT slot ONLY when word 0x6e5a60==0; otherwise it uses the preset
slot int 0x4b5650 (set by the cmd executor from record +0x16) and returns 0xffff0001 when it is -1. 0x6e5a60 is written by menu/UI code
(0x41cfcc, 0x43fb3f, 0x445fd1...), so spawns failed intermittently. Fix: create_unit() does CreateUnit's own slot search (owner slice
(p-1)*180/N..+180/N-1, or 0..0xb1 when H==1), checks the cap, presets 0x4b5650 when 0x6e5a60!=0, clears rally 0x4b5bb0/b4.
CreateUnit facts [O]: type 0x26 (38) becomes 0x2b (43) for side 1 (Chosen); cap check before slot search; queue mode 0x71667c==1 posts
cmd kind 2 (0x26-byte record 0x773410: type,owner,x,y,cost,cash,rally x/y/idx,slot) instead of creating; class byte (type>>8) 1/2 halve hp,
3 hp 0x2000, 4 flag 0x4000, 2 also pushes slot to 0x835040 list; owner 0x5a.. = 'allied' owner-0x5a with flipped side.

## HQ -> truck ("pack up", ruleset=1)
Truck = unit type 42 (0x2a), handler 0x4573a0: when order state ent+0x62 == 0x14 (set by PostOrder kind 7 'stop' for type 0x2a, i.e. the
deploy cursor) it clears occupancy +-6 tiles, CreateBuilding(0, owner, tileX-2, tileY-1) and on success removes itself with 0x4210c0.
UI facts [O]: hover fn 0x464ee0 returns the cursor id (stored to 0x83a3f4 by 0x462fb7/0x462ff8); own building -> -1 at 0x465356 (esi =
bldg*0xe0). Per-frame dispatch 0x463429: id-2 -> table 0x463530 -> UI_MapCommand 0x463550(kind) (2->1 move, 3->7 stop/deploy, 4->2 attack,
0x14->8 bless); other ids -> 0x463447 (clear). Pointer sprite = word 0x77b762 (5 = deploy arrows ptrdepl.bim 0x66cdc4, drawn at 0x41a314),
mouse held word 0x66cd84. Quiet building removal 0x420240(b) (counts, footprint class->1, 'base destroyed' msg if 0x716d70[owner]==b,
'has no buildings left' if last); 0x4207a0(b) = ground art restore (random 0x4b5b50[rand&15]) + crater decal + ReDrawArea 0x41e900.
Hooks: 0x465347 hq_hover_stub (19 bytes; rev 3 - the rev 2 site 0x465356 overwrote branch target 0x46535a and crashed) (own HQ, not constructing -> cursor 0x15); 0x463429 hq_disp_stub (cursor 0x15 -> pointer 5, click edge ->
PostCommand 0x444c00(0x65, record "\x01HQnnn" + player byte 0x77342d)); executor cheat_chat: hidden (skips chat log via 0x4460ea),
checks owner/type/alive/not constructing, free slot + cap first (HQ never lost), clears 0x716d70[p], restore ground (no crater),
0x420240, CreateUnit(42) at HQ tile +2,+1 (px*32+16), truck hp = same fraction as the HQ.

## rev 4 (Oct 24): hover cursor DROPPED (user: cursor never showed); replaced by a build-list entry "RE-ASSEMBLE HQ"
Removed hooks 0x465347 / 0x463429 (bytes back to original). hq_pack executor + hidden '\x01HQnnn' chat command kept.
Build list (construction icons, fn ~0x4659c2..0x465eb7) [O]: window of building types word 0x4c1fc8..0x4c1fcc (1..0x16; type 0 HQ is never
listed), type shown if 0x754fb0[p*0x50+type]!=0, max 8 icons drawn with 0x4932f0(sheet 0x6ce120 = ICONSB.BIM / ICONSB1.BIM, frame
0x4bb7ec[type*0x102+side], x si, y di), si += 0x34. Entry tables: active 0x6682e0[k], value 0x4e1180[k] (type / 500 more / 600 back),
x 0x4e1230[k], y 0x4e0f88[k] (0x3e7 = end). Hit test 0x465c79 (52x52); hover 0x465d01: value<500 and 0x8564e0==0 -> sprintf(name 0x4bb7cc,
cost 0x4bb7c4) + message 0x41fa90(text,3). Release 0x465dc6 (latched 0x754fa0, button up 0x66cd84==0): too many buildings (0x85e7d0[p]>0x85)
-> refuse; >=500 -> page nav (600 back to 1, 500 -> first hidden); 0 ignored; else 0x6729b0 = type to place + click sound 0x46f640(
[0x8595fc],[0x71a03c],0x40), 0x7733b0=3. Building icon frames (both sides): HQ 1, slab 7, power 3, mine 4, refinery 2, barracks 11,
wall/radar 5, hospital 12, vehicle fac 0, gun 7, hi-tech 9, repair 10, robot 13, bmine 14, advcomms 6, naval 14, air 8, pad/chem 6, supergun 8.
Hooks: 0x465a5a hq_list_stub (page 1 + own finished HQ -> entry 700 first, HQ icon frame 1), 0x465d01 hq_hover2_stub (700 -> text
'RE-ASSEMBLE HQ'), 0x465dcf hq_click_stub (700 -> post pack command + click sound, skip placement).
Graphics files [O/I]: BIM = sprite set loaded by LoadFile 0x4081a0 (optional 'VCLZ' LZSS container, 0x475120), offset table at start,
frame count in the last dword, RLE frames; RemapSpritePalette 0x408480 maps them to the screen palette. COL = 768-byte palette (256 RGB).

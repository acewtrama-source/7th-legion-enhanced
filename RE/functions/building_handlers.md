---
addr: 0x458a10..0x45b0c0
name: Building state handlers (bldg+0x84 fn ptr, set by CreateBuilding from 0x4bb7e0+type*0x204)
subsystem: sim/buildings
status: decompiled (9 of 13 read)
rev: 1
---
Wrapper PE data/code/handlers3.exe (tools/mkpe.py) needed: Ghidra doesn't define them. Called per building by UpdateBuildings 0x457bf0 with bldg idx. Building record base 0x805df0 stride 0xE0: +0x68 state (0 ready/idle, 1 constructing/countdown, 2/4/0x388 other), +0x6c timer (0x805e5c) counts down by frame delta 0x6df0f8.
Type -> handler:  0 base 0x459840 | 1 slab 0x459940 | 2 power 0x458e10 | 3 mine 0x458fc0 | 4 refinery 0x459480 | 5,9,11,13,18,19 production 0x459a80 | 6 wall 0x4599e0 | 7,15,20,21 generic 0x458a10 | 8 hospital & 12 repair 0x458b40 | 10 gun & 22 supergun 0x45a520 | 14 bmine 0x458a90 | 16 silo 0x45a3f0 | 17 shield 0x45b0c0.
Table 0x4bb7c0+type*0x204: +0 maxhp(short), +4 cost(int), +0x10 power produced, +0x12 power used. Types: base(0) hp400 cost0; power(2) 1500 hp200 makes 15 power; mine(3) 2000 hp60; refinery(4) 6000; barracks(5) 1500 hp200; wall(6) 500 hp70; radar(7) 250; hospital(8) 5000 hp200; vehicle fac(9) 10000 hp300; gun(10) 1250 hp600; randd(11) 15000 hp500; repair(12) 6000 hp400; robot(13) 20000 hp500; bmine(14) 250 hp1; advcomms(15) 12000; silo(16) 1000; shield(17) 2000; naval/air 5000; pad/chem 500; supergun(22) 3250 hp1200. (manual: wall 150, hi-tech 12000 differ [?])
0x458a10 generic: if state==1, countdown timer; at 0 state=0, local player gets 'construction complete' message (0x85fc30) + sound.
0x458a90 bmine(14): same countdown; on completion writes terrain tile 0x3e5 (0x3e6 if local owner) at its tile, marks tile class 1 (passable), redraw, 0x420240(bldg) (remove building record) => it is a hidden/placed MINE that vanishes into a map tile; units on tile 0x3e5/0x3e6 are destroyed by crushers (see 0x454690) [I].
0x458b40 hospital/repair: if idle and power OK (0x763380[p] <= 0x6683d0[p] i.e. power used <= produced): every 8th ent per tick scan own units inside bldg rect: repair(12) heals vehicles (+0x1e0000=+30 hp 16.16) costing 30 credits (needs credits>9); hospital(8) heals infantry (+0x180000=+24hp) costing 4 credits (needs >0). Units with state 2/3 are set idle.
0x458e10 power plant: state0: idle anim (frame +0x1c every 8 ticks), emits smoke effect 1 randomly (0x40ca60 stream), state1: construction timer then random delay.
0x458fc0 MINE(3): when hp > 1/3 max and owner is human slot0?: ore accumulates in bldg+0xa0 (0x805e90) from adjacent ore-map tiles 0x67bd90 (decrement ore density per tile; rate dependent on bldg type (+0x4) and dt) up to chunk 0x4bbde2; animates; stops when full => harvester picks it up. 
0x459480 REFINERY(4): state1 constructing; on complete: spawns a type-1 harvester via 0x4245c0(find free tile near)+CreateUnit(1,owner,...). Idle: drains bldg+0xa0 (ore) by 2*dt and ADDS 4*dt credits to owner (0x834a00) -> ore->credits conversion 2:4 (x2). Animation + sound.
0x459840 base(0): idle anim cycling 30 frames; state1 countdown.
0x459940 slab(1): marks tile class 1; after 4 ticks calls 0x45b1e0(x,y) and 0x420240 (self-removing foundation tile).
0x4599e0 wall(6): on completion calls 0x45b280(x,y,owner) (wall/tile linking) + redraw.
0x459a80 PRODUCTION (types 5,9,11,13,18,19): bldg+0x68 state: 1 construction countdown (msg on done), 2 PRODUCING item id bldg+0x94 (0x805e94; -1 none), 0x388 = STALLED for funds (resumes to 2 when credits >= cost). Each tick in state 2: if credits[owner] < UnitType[item].cost (+0x24 @0x4c0864) -> state 0x388 + 'insufficient funds' msg; else timer bldg+0x6c -= dt (in slow mode only every 8th tick). At timer<=0 the item completes AND IS PAID NOW (no progressive payment): 
  item < 0x1a: unit type -> find free tile 0x4245c0(bldg, UnitType+0x1c), CreateUnit(item,owner,x,y, cost) (deducts credits); type 0xb building (randd) special items 0x27-0x29 spawn projectiles-owner 0x2707 units (types 0xc,1,2 with cost 0x4c13f8/1444/1490).
  items 0x1a..0x20 = TECH/UPGRADE research (7 kinds, per-player level counters at 0x70db60/0x6dd2a0/0x719f90/0x6dd180/0x8046d0/0x66d8f0, max level 5): cost = 0x4b97c8[level] * base(0x4c1068,10b4,1100,114c,1198,11e4); item 0x1a = flat cost 0x4c101c; item 0xc = build an add-on (finds own type-0x10 building w/o flag, sets its +0xa0=1, counter 0x71b330[p]++, cost 0x4c0bf4).
  Rally/queue count bldg+0x98 decrements per completion (multi-queue), items +0x9c/+0xa0 = rally target; when count hits 0 item cleared. Local/AI-host UI updated via 0x423250.
UNREAD: 0x45a3f0 silo, 0x45a520 gun/supergun, 0x45b0c0 shield.

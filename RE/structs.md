# Structures

Single source for layouts. Offsets are hex bytes. Tags: [O] observed, [I] inferred, [?] unknown. Fields not listed are not yet seen.

## GP: guard point   (table @ 0x666620, 50 entries, stride 0x20)
```
+0x00 int   x        pixel coord [I]; tile = x>>5 [O]
+0x04 int   y        pixel coord [I]; tile = y>>5 [O]
+0x08 int   life     countdown; nonzero = in use [O] (set by 0x46b820, aged by 0x46b6e0)
+0x0c ?
+0x10 int   A        reset each pass; copied from node +0x1c [O]; role [?]
+0x14 int   B        reset each pass; copied from node +0x28 [O]; role [?]; divisor in ratio
+0x18 int   ratio    16.16 fixed = (A<<16)/B, or A if B==0 [O]
+0x1c int   refresh  copy of the life value, restored while units stay near [O]
```
Seen in: 0046b260 (read/write), 0046bec0 (not directly). Created by 0x46b820, aged by 0x46b6e0. Table is global (shared by all AI players). Radius for merge 0xa0 px, for unit assignment 5 tiles.
Note: 0x666610 (per-player timer array in 0046bec0) sits just before this table; do not confuse.

## UNIT: entry of the per-player lists (head @ 0x5bbd50 + p*0x20, next @ +0x04) and of the array @ 0x4c2350
The same layout is used for both; whether they are the same objects is [I].
```
+0x04 ptr   next
+0x0c ptr   obj      -> OBJ
+0x00 ptr   next A (list A, head 0x5bbd48+p*0x20; see PLR)
+0x10 short ent_id   index into the per-entity table (stride 0x6D0), first arg of 0x423710 [I]  (earlier records called this "type")
+0x12 short rank     sort key in 0x4697b0, compared in 0x469020 [?]
+0x14 int   thr0     threat value category 0 (0x469020 cat 0) [I]
+0x18 int   f18      threat category 1; nonzero = acts; divided by f24 in tick loop A [O]
+0x36 byte  kind     0 = vehicle (obj = ENT, x/y 16.16), 1 = building (obj x/y plain tiles) [O]
+0x1c int   f1c      copied into GP.A by reinforce [O]; = enemy strength near unit [I]
+0x20 int   base strength (buildings), added in 0x46af10 [I]
+0x24 int   f24      divisor for f18 [O]
+0x28 int   f28      copied into GP.B by reinforce [O]; = friendly strength near unit [I] (0x46b640 attacks when f28 > f1c != 0)
+0x2c int   str      "strength", summed into GP.A when recruited [I]
+0x37 byte  cadence  counter, wraps after 2 increments [O]
+0x38 byte  state    values seen 0..6 [O]; 2 = sent to guard point, 4 = attacking assigned target (0x469020), 5 = defending a building ring tile (0x46af10), 6 = locked; 6 only tested, not set here
+0x3c int   f3c      cleared on reassignment [O]; for state 4 = reference unit node (attack leader) [O]
+0x40 int   tgt      target ent id when state 4 [O]
+0x4c byte  order_id queued order, 0xff = none [O/I]
+0x50 int   f50      queued order arg [O]
+0x54 short f54, +0x56 short f56, +0x58 short f58, +0x5a short f5a   queued order args [O]
+0x5c int   f5c      cleared on reassignment [O]
```

## OBJ: position/status object pointed to by UNIT +0x0c
```
+0x18 int   x     16.16 fixed pixels [I]; tile = x>>0x15 [O]
+0x1c int   y     same
+0x54 int   cur   used in tick case 7 vs max (looks like current HP/level) [I]
+0x58 int   max   (<<16 compared with cur) [I]
+0x5c int   flag  0/1 hysteresis flag for the event in tick case 7 [O]
```
Note: tick case 7 walks a second list (head @ 0x5bbd4c + p*0x20) whose nodes have +0x0c -> OBJ-like and +0x10 id; layout of those nodes not yet separated from UNIT. [?]

## ENT: unit (vehicle) record, base 0x67fe10, stride 0x6D0, index = ent_id (max 0xb2 slots) -- same object as OBJ (OBJ x/y = ENT +0x18/+0x1c) [I]
Offsets from record start; absolute for slot 0 in brackets. Source: 0x424c20 init [O].
```
+0x00 short owner         [0x67fe10] 0 = free slot. AI-owned if owner > H (global 0x803c40)
+0x02 short type          [0x67fe12] vehicle type 0..0x2b
+0x04 short side          [0x67fe14] 0x6df140[owner]
+0x08 int   created       [0x67fe18] DAT_00803c48 + 10 (time stamp)
+0x0c short alive         [0x67fe1c] =1
+0x0e short serial        [0x67fe1e] per owner+type counter
+0x10 int   stat16        [0x67fe20] type stat <<16 (halved class 1,2)
+0x14 short stat          [0x67fe24]
+0x18 int   x   16.16 px  [0x67fe28]
+0x1c int   y   16.16 px  [0x67fe2c]
+0x20 short, +0x22 short  [0x67fe30/32] from type table +0x00/+0x02
+0x62 short mode          [0x67fe72] 0 idle(set at create); 1 moving to point; 2 attacking building; loop B in AI tick acts only if 0
+0x6a short tileX, +0x6c short tileY   [0x67fe7a/7c] px>>5
+0x78 short cmd [0x67fe88], +0x7a x px, +0x7c y px, +0x7e a, +0x80 target ent  = current order (0x423710)
+0x90 short new-order flag; +0x64 stop/aux; +0xd0/+0xd4/+0xd6 path state/slot; +0x648/+0x64c AI move marker; +0x688 flags (0x8000, 0x20000, 0x4000)
+0xa0 short               [0x67feb0] -1 none; last attacker/target ent (AI tick case 7 -> attack order cmd 2)
```
Type table: base 0x4c0858, stride 0x4c (44 types).
Building record (0x805df0, stride 0xE0): +0x68 state (1 constructing, 0 idle, 2 producing), +0x6c/+0x70 timer/total, +0xa4/+0xa8 production unit type/flag, +0xac/+0xb0 rally tile; +0 owner, +4 type, +8 alive, +0x0c time, +0x10 side, +0x14 serial, +0x18 x tile, +0x1c y tile, +0x20 w, +0x24 h, +0x54 hp16, +0x58 hp. See functions/00421d40.md.

## PLR: per-player AI struct, base 0x5bbd40 + p*0x20 [O/I]
```
+0x04 short unit count (list A)
+0x08 ptr   head list A (next link at node +0)
+0x0c ptr   head list C: BUILDINGS (node +0x0c obj = building record; obj+4 type, obj+0x68 production state 0 idle / 2 producing)
+0x10 ptr   head list B (next link at node +4); used by most AI loops
+0x14 int   power score (max of other players' read in 0x4698f0)
```
Building record extra: +0x68 production state (0 idle, 2 producing) [I].

## UNIT node corrections (from 0x467bd0/0x468600/0x468740)
+0x00 next in list A (all) | +0x04 next in list B (units) or C (buildings) | +0x08 last enemy node nearby | +0x0c ptr to ENT/BLDG record | +0x10 ent id (kind 0) or building idx (kind 1) | +0x12 rank (0x4c4390[type] / 0x4c4440[btype]) | +0x14/+0x18/+0x1c ENEMY strength within <5/<7/<10 tiles | +0x20/+0x24/+0x28 FRIENDLY strength same bands | +0x2c own power (0x468300) | +0x36 kind | +0x37 cadence | +0x38 state | +0x3c ref | +0x4c byte 0xff.
(Supersedes earlier notes that called +0x24 a divisor and +0x20 base strength.)
PLR+0 short = #buildings, +2 = #units, +4 = #nodes; +0x1c = pending building type (-1 none).
## Command record (table 0x79fdf0, 0x2c bytes)
+0 kind, +1 player, +2 order, +4.. shorts args. See functions/00445930.md.

## Card name table [O]
0x4afae0: dword ptrs, stride-0x50 strings at 0x863150+id*0x50 (all zero in the exe image = filled at runtime). Only xref to 0x863150 is the pointer table; no "card"/.txt/.dat strings found by search. Loader not yet found: look for writes through 0x86xxxx or a file read into a 0x50-stride array.

## Building record additions (from 0x457bf0) [O]
b=0x805df0+i*0xE0: +0 owner, +4 type, +8 alive, +0x0c grace counter, +0x18/+0x1c tile x/y, +0x20/+0x24 w/h tiles, +0x54 hp(16.16), +0x58 maxhp, +0x5c repair flag, +0x60 repair timer, +0x64 hp last frame, +0x68 state(1 constructing), +0x94 per-state handler fn ptr, +0xdc packed timer (hi mode, lo count), +0xec disruption/special (cards 0x29/0x2f/0x30).
Per-type table 0x4bb7c0 + type*0x204: +0x10 power produced(short 0x4bb7d0), +0x12 power used (0x4bb7d2), +0x1c.. damaged-tile ids (0x4bb7f0, 0x4bb980).
## Effect pool entry (0x71b600, stride 0x410) [O]: +0 active, +4 type, +8/+0xc pos x/y 16.16, +0x90 ent id, +0x94 bldg id, +0x9c callback, +0xac timer.

## ENT additions (0x451b00) [O]: +0xc8 per-unit handler fn ptr; +0x68c + 2*bit = status timer (short) for each flag bit of +0x688 (card effects); +0x98 reload; +0xae rank; +0x66a redraw-dirty; +0x6cc burning flag. Occupancy byte maps 0x6d3920 (ground, idx+1) / 0x83a4d0 (air); fog maps 0x66da10 visible, 0x672d80 seen; heat map 0x79dde0 (64x64) + snapshots 0x78fde0.

## UnitTypeTable 0x4c0858 (see functions/004c0858_UnitTypeTable.md) [O]: stride 0x4c, +0xa maxhp, +0x3c per-unit update handler fn ptr, +0x40 second fn ptr. CreateUnit 0x424c20 copies it into ENT (ent+0xc8/+0xcc handlers; ent+0xe4 etc). Command packet from CreateUnit queue: 0x26-byte record kind 2 (see 0x445930).

## ENT additions (rev 3, from 0x454d20/0x44e8d0/0x452f30)
+0x34 facing16.16(64dirs) +0x44?? see fn files; +0x40/42 dest px; +0x46 tgt bldg; +0x48 tgt ent; +0x50 body dir; +0x54 want dir; +0x62 order state; +0x64 return/abort(7=abort); +0x68 inrange; +0x6e mode; +0x70 moving; +0x78..0x80 last order (kind,x,y,bldg,tgt); +0x82 queued state(+0x84..0x8a args); +0x92 range; +0x98 fire stagger; +0xae rank (+0.125px/tick speed); +0xc4 harvester cargo; +0xd4 path state; +0xd6 path slot; +0xf2/f4 cur wp tile; +0xf8 wp idx; +0xfa/+0x352/+0x5b8 wp arrays; +0x5aa wp count; +0x648 path age; +0x652 cloak-capable; +0x654 cloak counter (0..0x7f, >0x78 hidden).
Order states ent+0x62: 0 idle,1 move-turn,2 attack-approach,3 attack-fire,5 path-wait,6 move-execute,8 special(type 0x11 drain),0xa-0xe harvester (home/to-ore/harvest/to-refinery/unload),0x14 idle-special.
Order kinds (PostOrder): 1 move,2 attack,7 stop,10/0xb/0xd harvester,0x15 set +0x26,0x29a set pos/state,0x29b set credits.

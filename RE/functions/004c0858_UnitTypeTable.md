---
addr: 0x4c0858
name: UnitTypeTable
subsystem: data/units
status: located
rev: 1
---
44 records (types 0..0x2b), stride 0x4c, at 0x4c0858 [O]. Raw dump: data/unit_type_table_0x4c0858.bin (3344 bytes). CreateUnit (0x424c20) copies fields into the ENT (0x67fe10) and sets ent+0xc8/+0xcc from +0x3c/+0x40 [O].
Record (offset from rec): +0 short, +2 short, +4 short(->ent+0x68?), +6 width(px), +8 height(px) (->ent+0xe4/0xe6 collision), +0xa maxhp (ent+0x14; hp 16.16 = maxhp<<16), +0xc.. ints/shorts [?], +0x14 short (->ent+0x92 range?), +0x16 short (->ent+0x94 weapon type), +0x1a (->ent+0x96), +0x1c flag (burns/big), +0x3c fn ptr = per-unit UPDATE handler (ent+0xc8), +0x40 fn ptr = second fn (ent+0xcc; probably draw/death hook [?]).
Unit type ids are the low byte of CreateUnit's first arg (param_1 & 0xff <= 0x2b); the high byte = creation class (1,2: hp halved; 3: hp 0x2000; 4: flag 0x4000).
Known: types 0,1 = harvesters (ore carriers) (message "Ore Carrier Destroyed"); type 0x11 regenerates hp (+0x2000/frame).
| type | w,h(+6,+8) | maxhp(+0xa) | handler(+0x3c) | fn2(+0x40) |
|---|---|---|---|---|
| 0 | 50,38 | 10 | 0x452f30 | 0x426f30 |
| 1 | 84,56 | 20 | 0x452f30 | 0x426f30 |
| 2 | 76,40 | 300 | 0x454d20 | 0x4271a0 |
| 3 | 64,42 | 400 | 0x4574d0 | 0x4282b0 |
| 4 | 92,51 | 400 | 0x456d60 | 0x427400 |
| 5 | 52,32 | 16 | 0x4574e0 | 0x428410 |
| 6 | 80,52 | 75 | 0x454d20 | 0x4276d0 |
| 7 | 60,65 | 75 | 0x4574f0 | 0x428430 |
| 8 | 92,58 | 600 | 0x457500 | 0x428530 |
| 9 | 88,58 | 600 | 0x456d70 | 0x427560 |
| 10 | 88,58 | 120 | 0x457510 | 0x428690 |
| 11 | 0,0 | 0 | 0x457520 | 0x4287f0 |
| 12 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 13 | 76,63 | 3 | 0x456e80 | 0x427b30 |
| 14 | 56,48 | 50 | 0x456e80 | 0x427e30 |
| 15 | 76,63 | 50 | 0x456e80 | 0x427e50 |
| 16 | 68,54 | 70 | 0x457530 | 0x428800 |
| 17 | 96,65 | 40 | 0x457540 | 0x428a60 |
| 18 | 31,32 | 3 | 0x457550 | 0x428c50 |
| 19 | 120,90 | 25 | 0x457560 | 0x428c70 |
| 20 | 176,131 | 50 | 0x457610 | 0x428f70 |
| 21 | 90,61 | 80 | 0x457620 | 0x4291e0 |
| 22 | 50,38 | 9 | 0x457740 | 0x4293d0 |
| 23 | 50,38 | 9 | 0x457a70 | 0x4295a0 |
| 24 | 50,38 | 9 | 0x457a80 | 0x4295c0 |
| 25 | 54,29 | 9 | 0x457a90 | 0x4295e0 |
| 26 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 27 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 28 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 29 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 30 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 31 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 32 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 33 | 64,78 | 400 | 0x456d80 | 0x427870 |
| 34 | 64,78 | 600 | 0x456d80 | 0x427e70 |
| 35 | 64,78 | 32 | 0x457b10 | 0x4296e0 |
| 36 | 64,78 | 400 | 0x457b20 | 0x429700 |
| 37 | 104,66 | 400 | 0x457b30 | 0x429870 |
| 38 | 64,78 | 300 | 0x457bb0 | 0x429980 |
| 39 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 40 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 41 | 0,0 | 0 | 0x452f10 | 0x426f20 |
| 42 | 96,60 | 30 | 0x4573a0 | 0x428140 |
| 43 | 104,66 | 300 | 0x457bb0 | 0x429980 |
Handlers shared: 0x452f30 (types 0,1), 0x452f10 (inert: 12, 26-32, 39-41 = projectiles/props?), 0x454d20 (2,6), 0x456d60 (4), 0x456d70 (9), 0x456d80 (33,34), 0x456e80 (13,14,15), tiny stubs 0x4574d0..0x457620 and 0x457740..0x457bb0 (probably thunks into a shared routine with a type constant).
TODO: decompile each distinct handler; names for types from manual (Mk-vehicles list in manual-map).

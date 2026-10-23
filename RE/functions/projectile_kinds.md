---
addr: 0x45bf90 (+ siblings)
name: Per-kind projectile UPDATE functions (template +0x14) and DRAW fns (+0x18)
subsystem: sim/combat
status: decompiled (std bullet, 0x45bd70, 0x45be60); rest located
rev: 1
---
Table: data/proj_kinds.md (kind, life, speed, update ptr, draw ptr). Slot layout see 0x42a140.md. Slots alive when slot+0 != 0; max index in 0x804310.
STD BULLET update 0x45bf90 (kinds 0xf,0x14,0x1f,0x21,0x26,0x28,0x2b): per game-tick step (dt steps): life(+0x688)-- ; life<1 -> free slot (0x4215d0). Else: call impact test 0x42a140 (which may free slot => stops); pos(+0x610/+0x614 16.16) += vel(+0x640/+0x644); while life>0x7e velocity *= (1+1/256) per step (slight acceleration over first part of flight); kind 0x1f/0x26 leave trail effect 0xd; 0x21 rotates sprite frame +0x630. On expiry of kind 0x1f spawn crater effect 4 + scorch decal. Mode 3 (0x70db34==3): tile flag '@' => immediate crater 0x429d10.
 vel = dirTable[dir] (0x4b9e88 x / 0x4ba288 y, 256 dirs, 16.16) * speed(template +0xa: 6 or 7 => 6-7 px/step) set in SpawnShot 0x43e280; building-fired shots (0x45a520) use dirTable*4... Max flight ~ life*speed px (140*6~840px) but ends when 0x42a140 sees target within ~8px.
 INSTANT-ish: kind 0x12 (life 140 speed 7, 'beam'?), kind 2 update 0x45bd30 -> 0x495530 (separate renderer module).
0x45bd70 (kind 0x29 = life 100): spiral/shock: frame counter +0x630 advances every +0x634 ticks, dies after 15 frames; each step impact test then pos += vel/2.
0x45be60 (kind 0x2a = life 900): spiral orbit around origin (+0x6b0,+0x6b4 centre): radius +0x640 grows 0xc000/step (0.75px), angle +0x658 += 6 (of 256) per step; impact test each step; animation as above. (Used by life-drain special / 'orbit' cards.)
Unread update fns: 0x45bc70,0x45bcd0,0x45c1f0..0x45c980 (effects/explosions kinds 0-0x1a), 0x45d4b0 (kind 0x10, life 9000), 0x45d8d0, 0x45d930, 0x45da60/70, 0x45ed00 (0x1c), 0x45b5a0 (0x1d), 0x45ed70, 0x45edf0 (0x22 flame), 0x45ee00, 0x45ee60, 0x45eea0. DRAW fns: 0x42e2f0.. ; 0x42f570 (kind 0x22 'flame stream': random zigzag, per-step impact test), 0x42fac0, 0x42fda0, 0x430120, 0x4301a0, 0x430290.
Timing: per 'step' count = frame delta (0x6df0f8); weapons are therefore frame-rate independent only via repeated steps.

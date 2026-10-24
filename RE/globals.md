# Globals

One row per address. `p` = per-player index. Tags: [O] observed, [I] inferred, [?] unknown. Functions: R read, W write.

| addr | type | role | used by | conf |
|---|---|---|---|---|
| 0x666620 | GP[50] | guard point table (see structs.md GP) | 0046b260 RW | O |
| 0x666630 / 0x666634 | int | GP.A / GP.B (in the table above) | 0046b260 RW | O (role ?) |
| 0x666610[p] | int[] | per-player countdown, decremented to 0 | 0046bec0 RW | O (role ?) |
| 0x8750d0[p] | int[] | per-player countdown, decremented to 0 | 0046bec0 RW | O (role ?) |
| 0x5bb500[p] | int[] | per-player countdown; gates tick case 5 when < 1 | 0046bec0 RW | O (role ?) |
| 0x665660[p] | int[] | per-player tick counter; (value & 7) selects the routine | 0046bec0 RW | O |
| 0x875160[p] | short[] | per-player counter, ++ each tick | 0046bec0 RW | O |
| 0x8753d0[p] | short[] | limit for 0x875160; at limit call 0x44da70 | 0046bec0 R | O |
| 0x4b8b28[p] | int[] | tick case 1 throttle counter (indexed by 0x5bcd74, not p) | 0046bec0 RW | O |
| 0x5bcd74 | int | current player index used for list heads | 0046bec0 R | I |
| 0x5bbd50 + p*0x20 | ptr | head of player p's UNIT list; p runs 1..0x834f88 in 0046b260 | 0046b260 R, 0046bec0 R | O |
| 0x5bbd4c + p*0x20 | ptr | head of a second per-player list (tick case 7) | 0046bec0 R | O |
| 0x4c2350 | ptr[] | null-terminated array of UNIT pointers | 0046b260 R, 0046bec0 R | O |
| 0x67fe10 / 0x67fe72 / 0x67feb0 | short | ENT table fields (see structs.md ENT) | both R | O |
| 0x803c40 | short | H = number of HUMAN players (1 single player). owner > H = AI player | many | O |
| 0x507484 | short | Missions.ini Difficulty (default 9); AI unit cap = Difficulty*8+8; tick case 1 throttle | 00403350 W, 0046bec0 R, 00424c20 R | O |
| 0x4b8b20 | int | debug flag; ==1 enables AI log lines | 0046b260 R | O |
| 0x834f88 | short | N = total players (H + NumAIs, max 6) | 00403350 W | O |
| 0x668ccc | short | local human player index | many | O |
| 0x834a00[p] | int[] | cash per player | 00403350, 00421d40, 00424c20 | O |
| 0x7533e0[p] | int[] | AI cheat timer (AICheatCount*60); >0 halves AI costs | 00403350 W | O |
| 0x804700[p] | short[] | unit count per owner | 00424c20 | O |
| 0x85e7d0[p] | short[] | building count per owner | 00421d40 | O |
| 0x805df0 | rec[] | building table, stride 0xE0 | 00421d40 | O |
| 0x4adb30 | int | force-placement flag set by .ai loader | 00403350, 00421d40 | O |
| 0x773410 | 4 bytes | event record {short id, short flag} for 0x444c00 | 0046bec0 W | O |
| 0x4af630 | int | ==1 writes training rows to nub.dat on each human production order | 00423250 R | O |
| 0x6665f0[p] | byte[] | AI production boost counter (shift of power ceiling), decremented per production | 004698f0 | O |

## Strings of interest
| addr | text | xref |
|---|---|---|
| 0x4c44fc | AI Sending unit to guard point | 0x46b5a2 (0046b260) |
| 0x4c451c | AI Forcing group to attack | 0x46b629 |
| 0x4c4538 | AI Guard Point Attacking:%d %d,%d | 0x46b6ad |
| 0x4c455c | AI Removed guard point | 0x46b7e6 |
| 0x4c4574 | AI Setting new guard point. | 0x46b8e4 |
| 0x4c4590 | AI Merging new guard point. | 0x46b89b |
| 0x4c4484 / 0x4c4498 / 0x4c44ac / 0x4c44d4 | ATTACKING ENTITY / GUARDING / PATROLLING / GUARDING BASE | none found |

## Added (AI driver/build batch)
| addr | meaning | conf |
|---|---|---|
| 0x6df3b0 | game tick counter | I |
| 0x879cb0 | round-robin AI player index (1..6) | O |
| 0x8781e0[p] | per-player visit counter; full AI tick every 4th visit | O |
| 0x87aa30 | AI enabled flag | I |
| 0x5bbd5c + p*0x20 | = PLR+0x1c pending building type (-1 none) | O |
| 0x666c60[23] | building desire scores (16.16) | O |
| 0x4addc0 | building availability by tech level [type*10+level] | I |
| 0xa23500 | TechLevel | I |
| 0x4bb7c4 / 0x4bb7cc | building cost / name, stride 0x204 | O |
| 0x8030f0[p] / 0x803100[p] | AI chosen build site x / y (-1 none) | I |
| 0x70d860[p] / 0x70db40[p] / 0x70d840[p] | AI anchor x / y / anchor building index | I |
| 0x6e5c30[p] | site finder result (0 ok, 9 no room, -1 no money) | I |
| 0x7f7df0[p] | build wait timer | I |
| 0x4b5ef0 | unit-class ratio table, rows 0x14 ints, via 0x468220 | I |
| 0x667f00[ent] | scratch flag array "already counted" | I |
| 0x5bbe20[] / 0x5bb530[] | attack recruit list / target ids | I |
| 0x75ba20 / 0x4b9080 / 0x92ab00[p] | AI event trigger index / callback table / cooldown | I |
| 0x85ef60 | char[..][0x50] | UI text table, slot i = GameText line i+1 (pre-filled 'TextError'), up to 0x872f60 | 00450cb0 W, all UI R | O |
| 0x4b9608 | int | language: 0 English gametext, 1 jive, 2 French, 3 Spanish | 00450cb0 R, loaders R | O |
| 0x4aee00 | short | 1 = lobby host (created game) | 00440450 | O |
| 0x719fa4 | int | 1 = skirmish protocol | 00440450 | O |
| 0x9e7600 | short | humans in lobby; names 0x9e6e80+i*0x20 | 00440450 | O |
| 0x6df140[p] | short[] | faction (side) per player 1..6 (0 7th Legion, 1 Chosen) from lobby | 00440450 W, 00424c20 R | O |
| 0x9d5a90 | int | AI players enabled | 00440450 W | O |
| 0x90a268 | short | total players (H+AIs) | 00440450 W | O |

## Added at Phase 2 close-out (Oct 24 2026) [O unless noted]
| addr | type | role | used by | conf |
|---|---|---|---|---|
| 0x803c40 / 0x834f88 / 0x668ccc / 0x75ba10 | short | humans H / total players N / local player / fog viewer | many | O |
| 0x4aee00 / 0x719fa4 | short / int | host flag (1) / skirmish protocol (1) | lobby, AI | O |
| 0x6df140[p] | short | side (0 7th Legion, 1 Chosen) | many | O |
| 0x834a00[p] | int | credits | many | O |
| 0x85e7d0[p] | short | building count | win check, special orders | O |
| 0x804700[p] | short | unit count (cap compare 0x424caf) | CreateUnit | O |
| 0x6e5a60 | short | 1 for whole game when H<=1: CreateUnit/CreateBuilding use preset slots 0x4b5650 / 0x4b5654 | create fns | O |
| 0x71667c | short | 1 = queue mode (create/destroy post commands), 0 = direct (inside ExecuteCommands) | create/destroy | O |
| 0x671a20 / 0x66ccf0 / 0x834f94 | rec[64] / short / short | command ring (0x2a per slot) / head / peer ack (full when head+2 == ack) | 0x444c00, 0x42d420 | O |
| 0x773410 / 0x9e2d80 | rec / int | command record being posted (0x26 bytes) / its size | PostCommand callers | O |
| 0x79fdf0 | table | commands being executed (text +4, chat sender +0x21) | 0x445930 | O |
| 0x6df3b0 | int | game tick (++ at 0x41bec7) | sim, RNG seeds | O |
| 0x90a27c | int | game RNG index (table 0x4afc00/0x4afbfc) | sim | O |
| 0x66da10 / 0x672d80 | byte / short [128*128] | fog (3 written on reveal; bit 0 tested as visible) / seen map | fog | I |
| 0x6d3920 | byte[128*128] | unit occupancy (slot+1) | movement, create | O |
| 0x71b3e0 + sc*2 / 0x71b4e0 + sc*2 | short | key down by scancode / extended keys | input | O |
| 0x834fb0 | short | chat typing active | chat | O |
| 0x6df160[40] / 0x6dd208 / 0x858514 | short | selected unit slots / count / selected building | UI | O |
| 0x4c1fc8 / 0x4c1fcc | short | build list page first / last type (1..0x16) | UI_BuildList | O |
| 0x6682e0 / 0x4e1180 / 0x4e1230 / 0x4e0f88 [0x50] | short | build list entry active / value / x / y | UI_BuildList | O |
| 0x6683f0[p*0x50+k] / 0x7ffef0[b*0x50+k] | short | unit k unlocked / vdepend (building b can build k) | factory panel | O |
| 0x754fb0[p*0x50+t] | short | building type t available | build list | O |
| 0x6df1b0 / 0x773408 / 0x805a54 | char[] / short / short | centre message text / show flag / timer | messages | O |
| 0x85ef60 + i*0x50 | char[80] | GameText line i+1 | UI | O |
| 0x78b770 + p*128 | char[] | player name | chat | O |
| 0x9d6340 / 0x90aad0 / 0x9e2d90 / 0x9dbbd0 / 0x9e2520 [p] | int | special order type / target player / building type / count / timer | 0x41ac80 | O |
| 0x6ce120 / 0x6ccad0 / 0x803438 | ptr | icon sheet / card sheet / other UI sheet | UI | O |
| 0x66cd44 | ptr | palette RGB (6-bit) used by RemapSprites | gfx | O |
| 0xa133c0 | int | size of the last loaded file | LoadFile, RemapSprites | O |

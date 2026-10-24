# Data formats (install folder: D:\rea_work\7th Legion\Install files)

Tags: [O] observed in files, [E] exe string/xref evidence, [?] unknown. No legion.pdb in the install folder [O]; exe is stripped.

## Files
| file | format | notes |
|---|---|---|
| Siege.ini | ini; [debug] WinDirect FullScreen UseSound humans priority; [options] difficulty(=7) hardness(1=more cash for computers) gamespeed detail side(0 good,1 order) res name | [O]. exe reads difficulty/hardness [E] |
| DATA/Missions.ini, jivmis.ini | ini; sections `[GMission n]` (good) | keys: Map, Difficulty(0-10), Terrain(0 desert,1 winter,2 grass), StartCash, AIXtraCash, AICheatCount, Brief1-4, HowToWin(0 credits,1 destroyv,2 destroyb,3 destroyvb), StartX1-4/StartY1-4, NumAIs(1-3), TechLevel, PVStart, PAStart (43 digit strings, one digit per vehicle type [I]) [O] |
| DATA/*.ai (Gmaps2.ai, GMAPS11.AI, GMAPS22.AI, GMAPS2.AIO) | text, `<prefix>_<name>=xxyy` per line | xxyy hex via sscanf %x: high byte X tile, low byte Y tile [O code, order I]; path "DATA\%cmaps%d.ai" letter G/B, number = map [O]. bt_ = building for first AI; yt_/dt_ = building for last human (cash 200000/20000); vt_ = AI vehicle; pt_ = local human vehicle; xt_ = opposing-side vehicle; ft_ = neutral vehicle [O code]; see functions/00403350.md |
| DATA/build.dat, vdepend.dat | `bt_<building>=vt_a,vt_b,...` | which units each building can produce [O] |
| DATA/depend.dat | `bt_<a>=bt_b,bt_c` | tech tree: a unlocks b,c [O]. Spelling: depend.dat `bt_shield`, exe string `bt_sheild` [?] mismatch |
| DATA/GameText.txt (Jivtext.txt = 'jive' language variant, same line numbers) | text, CRLF, 434 lines, one UI string per line, referenced by LINE NUMBER (not in exe) [O] | menu/UI text. Key lines (1-based): 242-247 colour names Blue/Red/Green/Yellow/Black/White; 251-257 main menu (253 = Multiplayer button); 311-314 Create/Join game; 316-331 lobby (317 'Players...', 318/320 side '7th|Ch', 319/331 slot 'None\|AI Player', 322 Hard/Medium/Easy, 324 tech, 325 start credits 15000..75000, 326 'Outside Normal\|Outside CTF'); 332 'Select Protocol....'; 348 'Internet UDP', 349 'Skirmish' (= protocol choice). Loaded by 0x450cb0 into 0x85ef60 + (line-1)*0x50 (80-byte slots; language 0x4b9608: 0 gametext, 1 jivtext, 2 fretext, 3 spmtext). Files are NOT modified: legion_enh.exe overrides line 253 -> 'Multiplayer or Skirmish' (font has no '/' glyph: 'Multiplayer/Skirmish' rendered as 'MultiplayerSkirmish') in memory when ruleset=1 (src/ui/text.c) |
| DATA/stuff.dat, gene.gp | not decoded | stuff.dat loaded by 0x4714b0 and 0x4716e0 [E] |
| DATA/MAP*.NNN (NNN=000-015,017,018,020-040,050-057,060) | binary, per-map | see "Map files" below [O] |

## Loader functions in exe (all hypotheses from string xrefs, [E])
| addr | size | reads |
|---|---|---|
| 0x403350 | 6635 | .ai loader + Missions.ini + Difficulty + AICheatCount + AIXtraCash + bt_ table. START HERE |
| 0x402ae0 | 2151 | Missions.ini, Difficulty |
| 0x402390 | 1863 | build.dat, bt_ table |
| 0x404f30 | 303 | Missions.ini |
| 0x41cd90 | 2434 | Missions.ini |
| 0x4368a0 | 9066 | bt_ table |
| 0x4714b0 | 546 | stuff.dat |
| 0x4716e0 | 777 | stuff.dat |

## Missions.ini keys confirmed in exe [O]
Map, Difficulty(def 9), BAvail, VAvail, TechLevel(999), HowToWin(3), HowToWinData1-4, TriggerType/Val/Effect/Data/Time 1-3, StartCash(25000), AIXtraCash, AICheatCount(x60 ticks), StartX/StartY 1-4 (multiplayer MStartX/MStartY 1-6), NumAIs(1, max total 6), PVStart, PAStart. Section = [GMission n] / [BMission n] / [MMission n]. Other mission files: jivmis.ini, fremis.ini, spmmis.ini.
Difficulty directly caps AI unit count (Difficulty*8+8). AICheatCount = seconds of half-price AI buying.

## Open questions
- yt_/xt_ prefix meaning; xxyy coordinate encoding; PVStart/PAStart digit-to-unit map; Siege.ini difficulty vs global 0x507484; hardness effect.

## Map files (DATA/MAP*.NNN) [O unless tagged]
Loader = fn at 0x402c40 (sprintf names, 0x408360 loads file -> dest), then decoder 0x438f50 (tools/mapdec.py reproduces it). All grids 128x128, **index = a*128+b** (a = pathfinder "x", b = "y"; pixel = tile*32).
| file | size | dest | content |
|---|---|---|---|
| MAPL.NNN | 16384 u8 | 0x8352f0 | terrain CLASS grid; stored `v^a` (decode: v ^= a). 0 = void/water [I], **1 = passable**, 64 = blocked [I]; only ==1 is walkable |
| MAPT.NNN | 32768 = 16384 u16 | 0x773450 | tile art id; stored obfuscated: running di=0x7530 (dec per cell, row-major a,b): `v=((v^di)-b)&0xffff` decode; ids seen up to ~4134; 0x3e5/0x3e6 = mine tiles (pathfinder) |
| MAPO.NNN | 16384 u8 (values 0..16) | 0x67bd90 | object/resource layer [?] not decoded (maybe obfuscated) |
| MAPOVL.NNN | 32768 B | 0x84a500 | overlay, mostly 0 [?] |
| MAPCX / MAPCY .NNN | 6000 B each | 0x6df710 / 0x6e5c50 | [?] (coords lists?) |
| MAPCT.NNN | 3000 B | 0x6e4e80 | [?] |
Editor (0x438c00..0x438e90) loads from `data//MAP*.%03d`; same files. Another buffer 0x8464f0 = per-tile owner map (low nibble = owner; used for mines), 0x6d3920 = occupancy (ent idx+1), filled at runtime.

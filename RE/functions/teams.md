# Teams / alliances (enhanced ruleset) and the owner checks they replace
status: implemented, src/sim/teams.c, rev 2 (Oct 23). rev1 in-game: teams worked (5 bots on team 2 all attacked team-1 human).
The original has NO alliance concept [O]: ~100 sites compare owners directly (ENT +0 / building +0 / AI current player 0x5bcd74).
Only campaign leftovers: owners >= 0x5a are 'allied' with owner-0x5a in the idle scan (0x4556c0..) and gun scan (0x45a6e5..) [O].
Colour = player index p (1 Blue, 2 Red, 3 Green, 4 Yellow, 5 Black, 6 White) [O by in-game test Oct 23]; p = lobby row + 1.

## allied(a,b)  (a==b, or ruleset=1 && teams on && g_team[a]==g_team[b]!=0)
| hook | site | original | where |
|---|---|---|---|
| H1 | 0x4556a4 | target.owner==self.owner -> skip | idle auto-acquire, 0x454d20 state 0 |
| H2 | 0x44f4f3 | cmp ax,cx (target,self) | fire-on-move scan, 0x44e8d0 |
| H3 | 0x45a6ce | ent owner == gun owner | gun/supergun target scan 0x45a520 |
| H4 | 0x45a954 | current target owner == gun owner | gun 0x45a520 |
| H5 | 0x46898d | node owner == AI player | AI_GatherEnemyCandidates 0x468920 |
| H6/H7 | 0x46ad47 / 0x46adb0 | player k == AI player | AI_PickAttackTargets 0x46ad10 |
| H8 | 0x4686e3 | k == p -> friendly band | AI_ScoreSurroundings 0x468600 (friendly/enemy strength) |
| H9 | 0x44d6e0 | player == AI player | AI card target 0x44d680 |
| H10 | 0x41c4f4 | player == local -> skip | Update winlose: others have buildings/units |
| H11 | 0x41c554 | ent owner == local | Update winlose, mode 0x70db34==3 ent scan |

## Update winlose (inline in a frame routine, 0x41c346..0x41c818) [O]
Result 0x9e2d84: 1 win, -1 lose, 0 none. Lose: local player (0x75ba10) has 0 buildings (0x85e7d0[p]) and 0 units (0x804700[p]) for >30 checks (counter 0x92ab20). Win flags: 0x4e0080 = some other player has buildings, 0x4dee74 = has units. Rule 0x835250 (HowToWin; forced 3 when humans>1 or skirmish): jump table 0x41c844: 0 credits>=0x71a168, 1 no enemy units, 2 no enemy buildings, 3 neither, 4 escort list 0x835040 (0x8349f0 count) all at full hp, 5 per-player counter 0x9d5ff0[p] >= 0x71a168. 0x83e4d0==2: special (0x9d6b70[p] >= 10).

## Lobby
Team buttons ids 0x69+r ("No Team|Team 1|Team 2|Team 3", x 0xa0, row y), created by redirecting the 'Options...' header call at 0x440720; host/skirmish editable; synced to joiners by widening the host's gv broadcast loops 100..0x68 -> 100..0x6e (cmp imm at 0x441203, 0x441513). Packed with AI rows at start (lobby_pack_ai) -> teams_from_lobby() fills g_team[1..6].
Team button x = 0xa0; faction buttons (ids 0x32..0x37, orig x 0xf0) are moved right to 0xa0+width("NO TEAM")+14 by editing slot +4 (rev 3, user preference).
Cleared: campaign side screen (camp_btn), main-menu Load (0x40dc2b -> load_menu_main).
## Saves (rev 2)
Companion file data//SAVE<n>.TMS, 13 bytes: 'TMS1', on, team[8]. Written after SaveGame 0x4321f0 in src/ui/saves.c (enhanced save menu; classic menu never writes it), deleted with the save. Read by load_game_hook wrapping LoadGame 0x433a60(slot) at all 5 call sites (0x40f4b2 0x40ff65 0x416941 0x416ce9 0x41cf21; first 4 guarded by [0x835034]!=-1). Missing/bad file => no teams.
## Unit cap (rev 2) [O]
CreateUnit 0x424c20: cap = 180/N (0xb4/[0x834f88]); owner > H (AI): Difficulty*8+8 ([0x507484]); compare 0x424caf..0x424cbb vs 0x804700[owner]. With H==1 every owner searches all 178 ENT slots => bots can exhaust the table; the human's finished units then fail silently (no spawn, no charge) = in-game 'buggy production' report Oct 23. H12 (tm_h12 @0x424caf): ruleset=1 => cap = min(cap, 178/N).

## Not done yet
Shared vision (fog writers 0x66da10: 0x4528f1 units in 0x451b00, 0x418642/0x418edd frame loop, 0x45aee0 gun, 0x45dd37, 0x45e0ec, 0x444a16, 0x4231a6, 0x42b6a2), mines (bmine trigger), radar/minimap, AI tick case 7 revenge on ally splash, selection/attack cursor on allies (force-attack still possible), local player eliminated while ally alive = lose.

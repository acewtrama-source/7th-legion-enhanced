# Phase 4: enhancements (plan, started Oct 26 2026)

Goal (user): new features and quality of life on top of the dependable multiplayer from Phase 3, always keeping the classic ruleset
(ruleset=0 = original game). Tick items here and put dated notes in CHANGELOG.md. Tags [O]/[I]/[?] as everywhere else.

## P4.1 Windowed / fullscreen option (user request, first item) - DONE Oct 26 2026 via cnc-ddraw (user tested, works; documented in
## the README). Native mode (option B) only if the wrapper ever falls short.
What the game does today [O]:
- 640x480, 16-bit, DirectDraw exclusive fullscreen. Window: CreateWindowExA WS_POPUP 640x480 at (0,0) (0x495031). DirectDraw object
  0x4d85a8. Frame: 0x494060 locks the render surface 0x4d7dc0 (pixels pointer 0x4d7dc8), 0x496140 draws the draw list into it,
  0x493f20 unlocks and shows it. Other code locks surfaces too (bitmap screens 0x497270, video, fades) [I].
- A developer switch exists: Siege.ini [debug] FullScreen (dword 0xaa2244, default 2, read at 0x494da4). With 0 the code calls the
  windowed helpers 0x4948d0 / 0x4948e0 / 0x4948f0 (WM_PAINT path 0x4054c5) and reads the mouse differently (0x4060cc, 0x40620c), but
  those helpers are empty (ret) in the release exe, so the windowed renderer was removed before release.
Options:
- A. **DirectDraw wrapper (no code):** a modern ddraw.dll replacement such as cnc-ddraw runs old 640x480 DirectDraw games windowed,
  borderless or fullscreen with sharp scaling (also covers HD/4K screens). Ask the user to test it with legion_enh.exe first. If it
  works, an Options button 'Display Fullscreen|Windowed' can simply write the wrapper's ini (ddraw.ini [ddraw] windowed=true/false,
  takes effect at the next start) and the README documents it.
- B. **Native windowed mode (code):** in windowed mode keep our own 640x480 16-bit buffer instead of locking DirectDraw surfaces
  (hook the Lock in 0x494060 and the other lock sites), show it with GDI (StretchDIBits via GetProcAddress, scaled to the window, so
  any window size and HD/4K scaling come for free), cooperative level normal and no SetDisplayMode, WS_OVERLAPPEDWINDOW instead of
  WS_POPUP, mouse from window client coordinates scaled back to 640x480, Alt+Enter toggles. Needs: map every surface lock / blit /
  palette path (video playback, fades, bitmap screens, credits), the DirectDraw creation and restore paths (0x493d20, 0x405470..
  focus handlers), and the mouse readers 0x406000 / 0x406140. Medium to large; do after A has been tried.
Exit: a windowed game the user can move, resize and alt-tab out of, in menus, skirmish and multiplayer.

## P4.2 HD / 4K
- Sharp scaling: covered by P4.1 (A or B).
- Real wider view (more of the map on screen): the engine is built for 640x480 (DDSetMode(640,480,16) and about 140 hardcoded
  0x280 / 0x1e0 plus derived constants in the renderer, panels, minimap and menus; camera view size words 0x80315c / 0x7166a4).
  Plan: map the constants, make the game view larger with the side panel anchored to the right, keep menus at 640x480 centred.
  Large; only after P4.1.

## P4.3 Multiplayer items carried over from Phase 3
1. 3+ player Internet UDP test (needs a third PC).
2. Confirm in a real match: desync check (no 'Sync lost'), silent player handed to a bot.
3. Lost orders: PostCommand 0x444c00 drops a command silently when the ring 0x671a20 is full (head+2 == ack 0x834f94); count drops,
   keep a small local backlog and retry next frame. Candidate cause of 'units ignore orders'.
4. Seats in a lobby-loaded save: renumber the players inside the save (owner fields, per-player tables) so person k plays player k,
   instead of changing the turn loop's player numbers (a16 froze).
5. Quitting joiner handed to a bot: find the a15 crash first (log around the quit command 0x445dd8).
6. Score screen: a 'buildings destroyed' column (needs the killer of a building).
Status Nov 1 2026 (a39): 3 partly (cap 30 per turn, ring stats logged, no backlog); 1, 2, 4, 5, 6 open. a25..a39 added the lockstep
hardening (RELEASES.md). New open items: host mixer crash after MP (sound off stopgap), units drifting to old orders, an a39
out-of-sync awaiting logs, score differences between PCs (recheck). Full list: START-HERE.md 'Known open items'.

## P4.4 Gameplay and controls (from the original Phase 4 list; to be prioritised with the user)
- Fire-on-move for plain Move (Fix B never worked) and attack-move.
- 'Units ignore commands / wander to enemy camp' investigation.
- Teams: mines, radar colours, AI revenge on ally splash damage, gun-fire reveal.
- Bigger unit table (178 slots, ENT 0x67fe10) for larger battles.
- In-game choice of classic or enhanced ruleset (lobby option), instead of the Siege.ini line.
- Extra units, balance changes, custom maps (data formats in data-formats.md).

## P4.5 Diablo demons as units (user request Oct 27 2026; plan in D:\rea_work\Diablo\RE\PLAN.md)
Read Diablo sprites at run time from the user's own DIABDAT.MPQ, named in a new Demons.ini next to legion_enh.exe (Siege.ini
and data files untouched; nothing copied from Diablo). Steps: D0 preview on the PC, D1 MPQ reader + CL2-to-BIM in the patch,
D2 reskins (graphics only, lockstep-safe), D3 new unit types (UnitTypeTable relocation, ruleset gated, Demons.ini hash in the
lobby version check), D4 sounds, icons, projectiles, AI.
New facts found for it [O]: BIM span x is absolute (not a skip); UnitTypeTable+0x40 is the per-type draw function (Priest
0x428a60: sheet by side ent+0x04, 8 directions from ent+0x50, walk frame anim ent+0x656 + dir*12, idle dir*4+0xe0, death
anim >= 900, draw 0x426600); .bim load sites: D:\rea_work\Diablo\RE\data\legion_bim_loads.txt.

## P4.6 Multiplayer modernisation (user document Nov 1 2026: ref/7th_Legion_Multiplayer_Modernisation_Recommendations.docx)
Direction agreed with the document: keep deterministic lockstep, make the command stream reliable, observable and recordable.
What already exists [O] and changes the scope:
- Network turns are already reliable by waiting: no PC passes a turn without every player's turn data (wait 0x401d30, type 8 'Q'
  turn data, 'R' resend request; UDP is relayed by the host, 'SERVER: GetUDP() Passing to N'). The silent loss is LOCAL: PostCommand
  0x444c00 drops when its 64-entry ring is full. So step 1 is a backlog in front of the ring, not a new transport. [?] how 'R' resend
  works and whether a turn can be lost without a wait: read before building.
- Execution order is already global and identical: frame slot 0x83a3f6 -> 0x79fdf0[slot][player 1..H][0..63]; exec_cmds sees every
  executed record (including the host's AI commands), so recording a replay is a tap on an existing hook.
- Sync check exists (a15 M5: '\x01CK' every 64 ticks, four 16-bit hashes; SYNC.LOG with tables + unit/building hash history).
- Fixed point: positions and hp are 16.16 integers (no float worries found so far) [I, verify per subsystem].
- Auto-target (local fog 0x66da10) only ever acts through a posted command, so it cannot diverge; its problem was stale orders (a35).
Plan (one alpha or two per step; each ends with a 2-PC test):
1. Reliable posting + diagnostics: overflow backlog for PostCommand (FIFO, retried before new posts each frame, never dropped, order
   kept per PC); counters (posted, backlog high water, turn wait time per player, resend requests); Ctrl+Alt+D overlay: tick, ring
   depth, backlog, who we wait for, last sync status. Read the 'R' resend path first.
2. Subsystem checksums: 32-bit FNV/xxhash per subsystem over chosen fields in slot order: players (credits, tech, quit flags), units
   (owner, type, alive, x, y, hp, order/target/mode fields), buildings (hp, state, queue, timer, rally), projectiles, RNG index, AI
   per-player state. Every 64 ticks; after a mismatch every tick. Mismatch writes a per-entity field dump; tools/syncdiff.py diffs two
   PCs' dumps and prints the first divergent tick / entity / field. Needs: projectile table and AI state layout (RE).
3. Score ledger: score events (tick, player, kind, points, entity) logged; score screen derived from them; building killer
   attribution -> 'buildings destroyed' column. RE: where kills 0x9d5a00 are counted and whether that runs on every PC.
4. Replays: record = header (build id, ruleset, map, options, players, teams, factions, colours, RNG index, or the save file for a
   lobby load) + per-turn executed records + checksums, data\REPLAYn.REP. Playback = start the game with every player remote, feed the
   frame slots from the file, posting and host AI off, local player = observer (fog off, camera free), speed control. Bonus: replaying
   a recorded MP game and comparing checksums reproduces a desync on one PC.
5. Spectators: first a 'spectator seat' (a human player number that gets no army and full vision, still sends empty turns); delayed
   observers later via streamed replay. Constraint: player number == UDP id, every human is in the turn wait.
6. Lobby / hosting: LAN discovery, NAT help, relay or dedicated host need an outside server or a headless sim; last, decide later.
Status: steps 1 and 2 BUILT in a40 (Nov 1; see CHANGELOG a40). The 'R' path was read first: see the transport notes there.

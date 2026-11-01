# Releases and engine behaviour (overview)

One line per alpha build plus what each round taught us about the engine. Details, addresses and sha256 per build:
`CHANGELOG.md` (search the alpha number). Tags: [O] observed in code or in a test, [I] inferred. Newer facts win over older ones.
Test builds ship as `legion_enh_alpha.exe`; the main menu shows "1.00 Enh aNN". Everything is active only with Siege.ini
`[options] ruleset=1`.

## Release list

| Build | Date | Changes | Bug found by the test / cause | Result |
|---|---|---|---|---|
| mp1-mp4 | Oct 24 | MP Save Game, 'Game paused by', lobby slot taking, colour follows row, lobby Load Saved Game, music back in the MP lobby | colours stayed per player (teams_clear also cleared slots) | fixed |
| a2 | Oct 24 | building tiles and player list boxes in the slot colour | - | verified |
| a3 | Oct 24 | bot names follow colour, cheat 'khaos mission' | - | verified |
| a4 | Oct 24 | cheat 'khaos card', UDP join screen (Cancel, remembered address, numpad) | Cancel returned 0 = connect | fixed a5 |
| a5 | Oct 25 | UDP join Cancel, firewall rules, MP lobby sound | - | verified |
| a6 | Oct 25 | Chosen tribute icons, faction '?', lobby colour bars | tribute icons used the local palette; alt-tab froze both PCs; bars invisible | fixed a7/a8 |
| a7 | Oct 25 | recent addresses, bars drawn before the poll present | alt-tab still froze; leaving joiner stayed listed | fixed a8 |
| a8 | Oct 25 | PeekMessage hook sends 'OP' while paused; host removes leaving joiners | Esc in MP did not pause (MP Esc box is not modal) | fixed a9 |
| a9 | Oct 25 | MP Esc = modal pausing menu, Tech Lab Off, sell (double S), faction '??', options page 2 | one PC in a menu -> other timed out (UDP turn wait 0x401d30 ignores 'OP') | fixed a10 |
| a10 | Oct 25 | turn wait honours 'OP'; silent player -> bot; team '??' auto balance; Sell option | - | verified |
| a11 | Oct 25 | lobby load WAIT/READY + locked options; quitting joiner -> main menu; T# in minimap list | host crash after a joiner left; joiner saw host's base after a load (LoadGame runs twice, viewer from the save) | a12/a14 |
| a12 | Oct 25 | viewer/camera/selection reset after a lobby load | - | verified |
| a13 | Oct 26 | 'Players and map...', team chat (T) | - | verified |
| a14 | Oct 26 | 'Message To Team...', Edge Scroll option | T typed an extra 't' | fixed a15 |
| a15 | Oct 26 | T fix, version check (build id), desync check (SYNC.LOG every 64 ticks) | - | verified |
| a16 | Oct 26 | seat choice in lobby loads, quitting joiner -> bot | both froze/crashed (net layer needs player number == UDP id) | reverted a17 |
| a17 | Oct 26 | reverts; emergency exit (Ctrl+Alt+End / Alt+F4 2 s); numpad in chat | - | verified |
| a18 | Oct 26 | numpad in edit fields, version on main menu, protocol order, Cancel to Create/Join | protocol order unchanged (16-bit locals pushed as dwords) | fixed a19 |
| a19 | Oct 26 | s16 cast, version label width | - | verified |
| a20 | Oct 26 | address screen Cancel -> protocol list | - | verified |
| a21 | Oct 26 | score screen | crash leaving skirmish (in-game font freed) | fixed a22 |
| a22 | Oct 26 | score screen after cleanup, toolkit font | text doubled and yellow | a23 |
| a23 | Oct 26 | white rows, shadow pass off | text bold (glyphs queued twice) | a24 |
| a24 | Oct 26 | keep second glyph pass, columns | - | verified |
| a25 | Oct 26 | right click = previous map in the lobby | kills differed between PCs; later: score screen exits | diag a26 |
| a26 | Oct 26 | RNG caller log (diagnostic) | desync: rng index differed; then credits of a bot | diag a27 |
| a27 | Oct 26 | command + credits log, click sound on right click | identical commands, one bot unit position differed | diag a28 |
| a28 | Oct 26 | 3 -> 16 commands per turn, lasting rally points, unit hash history | orders still late; building hp 'rubber band' | a29 |
| a29 | Oct 26 | damage applied on every PC (no more kind 14 per hit) | group orders worked ~30%; host froze when an AI HQ died | a30 |
| a30 | Oct 27 | damage runs in exec context (0x71667c=0); hang sampler | units rubber band / alternate stop-go (host-only 0x29a position resyncs) | a31 |
| a31 | Oct 28 | 0x29a resyncs done on every PC at once; Win32 crash logger; building history | unit+research both paid; units to ally base; score screen exit | a32 |
| a32 | Oct 28 | production units created on every PC (cu_direct), rally synced, ally-building rally ignored | MP: no units ('unit ready', no cost) - the slot bug fixed in a39 | a39 |
| a33 | Oct 29 | 10 minute network wait, Ctrl+Alt+S STATE.LOG, crash module name | crash = music mixer after the post-game music reload | a34.. |
| a34 | Oct 29 | stop sound before cleanup (did not help), path slot wait (group orders), double tap group key | units drift back to old orders | a35 |
| a35 | Oct 29 | auto-target held back while a player order is pending; chat history; host silent after MP | production 'stuck' (really the a32 slot bug) | a39 |
| a36 | Oct 30 | heap checks (heap was fine), fuller STATE.LOG | main menu music crashed the host | a37 |
| a37 | Oct 31 | repeat filters for queued orders/modes, 30 commands per turn, host sound off after MP | - | ok |
| a38 | Oct 31 | keyboard menu navigation (arrows + Enter) | robot hangar made ore carriers (a35 watchdog misread fields) | a39 |
| a39 | Oct 31 | direct CreateUnit picks the unit slot like the command path; watchdog off | - | unit creation verified |
| a40 | Nov 1 | P4.6 steps 1+2: order backlog (never dropped), resend history 32 per turn (was 8: wrong resends since a28), Ctrl+Alt+D net overlay, six subsystem sync hashes, shared dump at the same tick, tools/syncdiff.py | sync lost in buildings at tick 282: second RNG stream advanced by the click voice on one PC | a41 |
| a41 | Nov 1 | second RNG stream re-aligned every MP tick, Detail held at 3 in MP, syncdiff field fix | false 'sync lost in buildings' (+0x98 is a minimap counter); resend storm ~6 per tick | a42 |
| a42 | Nov 1 | +0x98 out of the hash; command records zeroed past the sent length on every PC; resend requests logged in SYNC.LOG (N lines) | sync lost in shots: a click (order voice) shifted the second RNG before the same tick's shot updates | a43 |
| a43 | Nov 1 | order voice on a private stream; three draw calls keep the second RNG index | not sent (a44 same + logging) | a44 |
| a44 | Nov 1 | a43 + end of turn markers logged (sent and received with count) | sync lost in buildings from tick 1: host AI acted directly on the first frame | a45 |
| a45 | Nov 1 | AI driver always runs in queue mode in MP | scores equal on both PCs (first time); sync lost in buildings: AI building 641 under attack drifted a few ticks, finished 6 ticks apart | a46 |
| a46 | Nov 1 | building field change log (W lines, 256 ticks) + syncdiff section 5; command log window 256 ticks | sync lost in units: host skipped one sim step (local Esc pause flag) | a47 |
| a47 | Nov 1 | MP: sim step never skipped for the local pause flag, speed word held at 1, speed+delta hashed | - | in a48 |
| a48 | Nov 1 | a47 + per unit order/path trace in STATE.LOG (Ctrl+Alt+S with the stuck units selected) | only the first 4 units of a group obey (8 commands per player per turn executed); sync lost in buildings: flame/beam damage applied while drawing | a49 |
| a49 | Nov 1 | ExecTurnCommands runs 32 sub-orders per player (was 8) | large group moves/attacks perfect (user); sync lost in buildings: flame/beam hits only on drawn frames | a50 |
| a50 | Nov 1 | MP: draw list (with flame/beam hits) processed every frame, also catch-up and pause frames | ran nicely until a big fight: flame shots at different positions (draw order decides their random values) | a51 |
| a51 | Nov 1 | each projectile draw call gets its own second-RNG position (tick, slot); whole render keeps the stream | sync lost in units: two new units in swapped slots (slot reserved only on the posting PC) | a52 |
| a52 | Nov 1 | queued CreateUnit reserves its slot locally (not the shared stamp); kind 2 falls back to first free slot if taken; free-slot stamps hashed | sync lost in shots (big fight): projectile functions still ran in camera-dependent draw order | a53 |
| a53 | Nov 1 | MP: projectile functions run in slot order before the renderer (drawn under units); Shift+1..0 adds the selection to a group | Shift+number works; sync lost in shots: display-only effects shift projectile slots between PCs | a54 |
| a54 | Nov 1 | MP: display-only effects (smoke, impact puffs) take the highest free projectile slot, so weapon projectiles get the same slot on every PC | longer games, several big fights; sync lost in shots at 4864, but only shots and one AI unit's order fields differed, briefly; units, buildings, players equal | a55 |
| a55 | Nov 2 | diagnostics: per-tick shot list (K) and unit order-field change log (V) in SYNC.LOG; syncdiff sections 6-7 | sync lost in shots: same shots, different SLOTS (28 vs 27, 10 vs 16) from 3551 | a56 |
| a56 | Nov 2 | MP: every spawn sorted by kind: damage-dealing kinds take the first free slot, all other effects the highest; each projectile update gets its own second-RNG position | sync lost in buildings at check 64: AI HQ timers 0 on the host, -2 on the joiner from tick 1 (HQ timer step is a per-PC clock value) | a57 |
| a57 | Nov 2 | MP: HQ timer step 0x71b5f4 held at 1 (was the timer-interrupt count at game start, per PC); included in the rng hash | - | test |

Open items after a39: START-HERE.md 'Known open items' (kept current there).

## How the engine works (what the bugs taught us)

### Multiplayer model
- [O] **Lockstep with owner-decided commands.** Every PC runs the same simulation; input travels as commands in a ring (0x671a20,
  64 entries, head 0x66ccf0, ack 0x834f94, posters drop silently when head+2 == ack). The turn sender 0x401961 sends at most 3 commands per
  turn originally (now min(30, 60/humans)); ExecTurnCommands 0x445930 runs a turn's commands on every PC with 0x71667c = 0
  ("direct mode"). Outside it 0x71667c = 1 ("queue mode"): game functions do not change state, the owner PC posts a command instead.
- [O] **Who posts.** Each queue-mode function posts only on the PC of the unit's owner, or on the host for AI owners: PostOrder
  0x423710 (kind 6), BuildingOrder 0x423250 (kind 5), CreateUnit 0x424c20 (kind 2, carries the slot and credits), SetUnitMode 0x424300
  (kind 13), damage 0x42bd90 (kind 14, by the VICTIM's owner, with an absolute new hp), DestroyBuilding/unit removal, chat (kind 0x65,
  also our hidden '\x01..' commands). The AI 0x447d80 runs on the host only (RNG saved/restored around it) and acts through commands.
- [O] **Consequences of the design** (each found as a bug): one command per hit flooded the ring (late or lost orders); several hits in
  flight all reported 'hp minus one hit' (rubber-band health, lost damage, different kills); the host alone posted 0x29a position resets
  that arrived late and snapped units back; owner-side auto-target used the stale state and its order replaced the player's newer one;
  code that decides every tick re-posted the same order until the first executed. Fixes keep the lockstep: damage, its follow-ups,
  position resets and production completion now run directly on every PC; remaining owner-side posts are filtered.
- [O] **Second RNG stream** (a40 test): table 0x4afc00 (read via 0x4afbfc) with index 0x9d49c0, Rand_Mask2 0x40ca60 and many inline
  copies. Used by the simulation (building handler 0x458e10 timers, impacts 0x42a140, deaths 0x42cea7/0x42d1c6/0x42d647) and by
  local things (order voice 0x464355 on the clicking PC, draw functions 0x42f570..0x42fda0, Detail-dependent debris 0x429d10 and
  Detail branches; Detail 0x5474a0 is per PC, Siege.ini). Fix a41: index set from the tick at every MP tick start, Detail held at 3.
  The AI driver saves/restores both indexes (host only). Frame order [O]: ExecTurnCommands 0x417dbb -> UI input (orders, voice) ->
  buildings 0x457bf0 / units 0x451b00 / shots 0x45b430 -> draw 0x426410, 0x42de70, 0x4303f0 -> AI 0x447d80 -> 0x4368a0. a43: voice
  on a private stream, the three draw calls inside a save/restore of 0x9d49c0.
- [O] **Command packet length** = table 0x9e37c0[kind] data bytes (set at 0x415301: kind 1 10, 2 24, 5 10, 6 12, 7 12, 8..13 4,
  14 12, 0x14 2, 0x32 8, 0x63 6, 0x65 30; unused kinds 0). Receivers still store 0x26 bytes, so the tail was leftovers (zeroed a42).
- [O] Building +0x98 is not production state: set to 4 by CreateBuilding (0x422cbc), counted down by the minimap drawing (0x41eb4b).
- [O] **Sim steps per frame:** game loop 0x41866f skips buildings/units/shots updates while the local pause flag 0x7ffe50 is set
  (Esc 0x41c224, cleared 0x438b7a/0x438bd2) and runs them per speed word 0x507478 (>0 every N frames, <=0 1-N times; MP starts at
  1, 0x4171e0; after the Esc menu it becomes 4 - local option 0x4afbe0 at 0x41c9de). a47: in MP the skip is ignored and speed held at 1.
- [O] **Group orders:** one PostOrder (kind 6) per unit plus usually a SetUnitMode (kind 13): a 13 unit move = ~24 commands in one turn.
- [O] **ExecTurnCommands runs only sub-orders 0..7 per player per turn** (0x446136 cmp eax,8): with the original 3 per turn harmless;
  since a28 (16, then 30 per turn) everything past the 8th was silently skipped on every PC = 'only part of the group obeys', units
  that got the order but not the mode ('move but do not attack'). a49: 32.
- [O] **Flame/beam weapons (projectile kinds 0x22, 0x23, 0x27) hit while being DRAWN:** their draw functions 0x42f570 / 0x42fac0 /
  0x42fda0 (template 0x4c1730 + kind*0x20, +0x18; copied to slot +0x98/+0x9c/+0xa0) call the impact/damage routine 0x42a140;
  they run from the list renderer 0x431040 (0x431102), which the game loop skips on catch-up frames (draw argument 0, 0x4189ab)
  and while paused (0x7ffe50, 0x4188da). So hits depended on which frames each PC drew (the PC that is behind skips drawing).
  a50: in MP the list is processed every frame; on skipped frames its queued items are dropped and 0x493840 not called.
  Flame segments take second-RNG values (0x42f5ba, 0x42f80a) in DRAW ORDER: the list is depth sorted (unstable selection sort
  0x4189e9..) and also holds the on-screen units, so the order differed per PC. a51: per call stream position from (tick, slot).
- [O] **Unit slots:** free = owner 0 and stamp +8 == 0; removal sets stamp 0x803c48+10 (=19, 0x803c48 is set once at game start)
  and every unit update counts free slots' stamps down (0x451c89). A queued CreateUnit (0x424de6.., posting PC only) stamps its
  chosen slot at once (0x424ecd) = a reservation only that PC has; kind 2 with owner 0x2707 is an effect (0x1b) only. a52: the
  reservation is local (g_resv), the shared stamp only changes on every PC.
- [O] **Deterministic pieces:** game RNG = table 0x4afc00[1024] with index 0x90a27c (RandMask 0x40ca00, RandMod 0x40ca30); C rand
  0x49c540 is seeded from the clock (local, UI only). Auto-target reads the local fog map 0x66da10, so it cannot run on every PC.
- [O] **Unit slots in a running game:** with 0x6e5a60 = 1 CreateUnit does not search a slot; it takes dword 0x4b5650, which the kind 2
  handler sets from the command. Player p's slots: (p-1)*(0xb4/N) .. +0xb4/N-1 (whole table with one human).
- [O] **Transport (a40 reading).** One UDP packet per command: 'Q' kind frame idx + 0x26 bytes, then a 'Q' 0x7f end marker with the
  count; receivers flag each (frame, idx, sender) in 0xa239f0 (48 per frame, duplicates ignored), ask the sender with 'R' frame idx
  for a missing one, and the sender resends from its history (0x92ab60, only 8 per frame in the original; ours 32 per frame). No turn
  runs until every player's turn is complete, so the network is reliable by waiting; the only silent loss was PostCommand 0x444c00
  dropping when its 64-entry ring is full (now a 512 backlog, ruleset 1).
- [O] **'R frame f idx 0' is also a nudge:** the turn wait 0x401d30 sends it to the missing player every 0x41 passes (0x401eb4..
  0x401ed7), whatever is missing; the answer is the end marker. So 'resend' counts measure waiting, not packet loss (a44: 1254 at
  tick 0 = joiner waiting for the host to finish loading).
- [O] **AI first frame:** LoadMission 0x403350 sets 0x71667c=0 and the loop in 0x40f2d0 runs the AI (0x416a40, host) before its
  first ExecTurnCommands, so the original AI acts directly on the host in that frame (a45: AI calls forced to queue mode in MP).
- [O] **Turn wait** 0x401d30: missing player in esi, 'Network timed out in BeginFrame!' after the timeout (now 10 min; silent non-host
  player -> bot after 60 s). Player number == UDP id throughout the net layer (why seat choice in loads failed).

- [O] Projectile pool 0x71b600 (stride 0x410, 0..205; kind 0x1b up to 219): 0x429de0 spawns into the FIRST free slot. Display-only
  spawns share it: building smoke 0x41eab0 (render path, C rand), unit smoke 0x425820 (from renderer 0x431040, on-screen only),
  kind 0x1d draw 0x42e130 (local option 0x4afbe4); many sim spawn sites are gated by local options (0x4af814, 0x4afbe4) or use
  C rand. Kinds that deal damage (reach 0x42a140 / 0x42bd90): 2 0xf 0x12 0x14 0x1d 0x1f 0x21 0x22 0x23 0x26 0x27 0x28 0x29 0x2a
  0x2b. a56: in MP all 68 spawn calls go to spawn_fx: those kinds first-free from 0, everything else highest free slot.
  Update loop 0x45b430 calls each slot's +0x9c in slot order (0x45b564).

### Sound and music
- [O] GLX sound library: load module 0x46f810 (fails if one is loaded), start 0x46f7f0, stop 0x46f800, unload 0x46fbc0, restart output
  0x46f580 (0x486eda stop + 0x490d31 start), play sample 0x46f640/0x46f780 (-> 0x489a5b voice, sample, rate, vol, pan, loop),
  in-game music position 0x489696(1,pos) via 0x4b565c. Sound on/off word 0x4d85a0 (read from Siege.ini once).
- [O] After a single player game the shell stops music and restarts output before the cleanup 0x408110; the MP path does not.
- **Open:** on the host only, the first music started after a multiplayer game crashes the mixer thread (generated code, bad sample
  pointer) although the heap is valid. Stopgap since a37: the host keeps sound off until the game is restarted.

### Production and buildings
- [O] Building record 0x805df0 + i*0xe0: +0 owner, +4 type, +8 alive, +0x14 serial, +0x18.. tile rect, +0x54 hp, +0x68 state
  (1 building, 2 producing, 0x388 waiting for credits), +0x6c timer, +0x70 total, +0x94 handler, +0x98 count, +0xa4 item, +0xac/+0xb0
  rally. The cost is paid when the item completes. Original rally = per order (BuildingOrder 999, mouse over the map when ordering);
  ours is lasting, set by clicking ground with the factory selected (hidden command '\x01RP').
- [O] A rally tile inside another owner's building makes new units target that building (state 2) - allies included unless filtered.

### Units and orders
- [O] PostOrder 'same as last order' filter (+0x78..) and SetUnitMode 'same mode' (+0x6e) compare with state that in MP changes only at
  execution. 0x29a = set position (integer px) and state. Unit update 0x454d20 retries a failed path 4 times (+0xd0) and then idles.
- [O] Pathfinder: 13 search slots (0x6e75c0); the enhanced A* (ruleset 1) now waits for a slot instead of failing and does 1024
  expansions per call.

### UI
- [O] Menu toolkit: slots 0x592bb0 (stride 0x3c0), poll 0x476aa0 reads the mouse first, present hook 0x476dea before hit tests; text
  0x494230 queues each glyph twice (shadow + text). Key words 0x71b3e0 + scancode*2 (extended + 0x100). Chat line 0x4e0d88 (22 chars),
  length 0x4e0f58. Control groups 0x66cdd0 (+ g*80), counts 0x67fde0; camera request 0x859528/0x85952a.

### Diagnostics in the enhanced exe
- SYNC.LOG (first mismatch: tables, commands, unit/building hash history), STATE.LOG (Ctrl+Alt+S), CRASH.LOG (unhandled exception:
  address, module, registers, crumbs, stack), HANG.LOG (no PeekMessage for 6 s), SLOTS.LOG (lobby/after-game steps).

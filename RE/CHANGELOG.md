# Change log (session notes, oldest first)

Moved out of START-HERE.md at the end of Phase 2 (Oct 24 2026). Verbatim session notes; newer facts win over older ones.
Per-feature detail lives in functions/cheats.md (rev 1..13), functions/teams.md, functions/00440450.md, functions/patch-hooks.md.

## Phase 2 (movement/combat) - in progress
- **Fix A (done, untested in-game):** `src/sim/orders.c`. PostOrder 0x423710 drops an order equal to the unit's last-order record (ent+0x78..0x80), and nothing clears that record when the unit goes idle -> re-issuing the same move/attack after the unit stopped short is silently ignored ("units ignore commands"). With ruleset=1 the dedupe is bypassed when ent+0x62 (order state)==0. Patched at 0x42383f (jmp to `post_dedupe_stub`). Poster-side only, lockstep-safe.
- Open hypotheses: mode 8 never aborts a chase (units wander to enemy camp); kind-7 mode 2 reset to 1 on first idle tick; idle auto-acquire range 0x280 for mode 2.
- **Fix B (done, untested in-game):** fire-on-move for plain Move. 0x44e8d0's opportunistic-fire scan ran only for modes 5/8 or AI owners; with ruleset=1 mode 4 (normal move) is treated as 5 (stub `mode_stub`, patched at 0x44f471). Defensive move (6) stays quiet.
- Analysis: mode-8 chase has no leash (0x454d20) but only player-issued attack orders use it; auto-acquire from idle (mode 1) is leashed at 3x range. So "wander to enemy camp" is not explained by that; needs an in-game repro.
- **Campaign-screen Back button (ruleset=1, untested):** `src/ui/campaign.c`. Screen 0x40d3a0 (side choice) already exits on Esc ([0x71b3e2] -> [0x5474b4]=0x3e7, esi=1); we add button id 7 at (centre,0x1c2) via redirect of call 0x4758b0 at 0x40d48a, and a poll stub at 0x40d49c that does the Esc action on click of id 7.
- Fire-on-move (Fix B) reported NOT working in-game: needs investigation (check mode actually 4 when moving, order state, scan break at UnitType+0x34 / 0x4c0874 == 0).
- Campaign screen (0x40d3a0): its title button text (==0x866cb0) puts the menu toolkit into mode [0x4c5894]=2, where poll 0x476aa0 only draws and returns -1 (no hit-test/hover/click). `src/ui/campaign.c` adds a Cancel button (id 7) with our own hit-test/hover/click+sound (toolkit hit-test is off in mode 2; click sound = 2x 0x46f780 with [0x4b95f0]); Esc is swallowed (cleared for 30 polls, then exit) because the main menu otherwise sees Esc still set and quits. Untested.

## Lobby / skirmish / teams / features (Oct 23-24; folded into Phase 2 at close-out)
- Goal (user): bots in solo skirmish AND in MP, with teams and clear per-player colours.
- Skirmish already exists: Multiplayer -> Create/Join -> protocol list (GameText 332 'Select Protocol', 348 'Internet UDP', 349 'Skirmish'); lobby slots 'None|AI Player' (319/331). Colour names GameText 242-247; CTF flag sprites GFX/CTF{BLUE,RED,GREEN,YEL,BLACK,WHITE}.BIM; tank colour variants MTANKB{B,G,R,Y}.
- DONE (untested in-game): main-menu label 'Multiplayer or Skirmish' (font has no '/' glyph: 'Multiplayer/Skirmish' rendered as 'MultiplayerSkirmish') via src/ui/text.c (ruleset=1, English+jive): wraps text loader 0x450cb0 at its 2 call sites 0x40db87/0x4510b0, then overwrites slot 252 (0x863e20). Data files untouched (an earlier GameText.txt edit was reverted; leftover backups DATA/GameText.orig.txt, Jivtext.orig.txt can be deleted). Previous exe kept as legion_enh.prev.exe.
- BUG FIXED Oct 23: src/sim/orders.c declared `extern int g_ruleset` but it is u8 with g_inited (=1) right after it, so Fix A and Fix B ran even with ruleset=0 (classic not classic; MP desync risk vs legion.exe). Now `extern unsigned char`. Rule: always declare g_ruleset as u8.
- Build check: tools/build_patch.sh + patch_exe.py reproduced the Oct 22 legion_enh.exe byte-identical before these changes.
- Net strings: DPLAYX.dll import + own Winsock UDP/TCP ('Server bind() TCP', 'sendto()...host send', 'System 0x00/0x01 player list' ~0x4b8c0c..0x4b8f94); lockstep 'Network timed out in BeginFrame!' 0x4ad610, '$SYNC!%02d' 0x4af514, 'SyncPlayers()' 0x4b6b68. Next: xref these, map the lobby/protocol screen and how GameText lines are indexed in code.
- Lobby = 0x440450 (functions/00440450.md). Original locks all empty rows and AI factions; skirmish forces exactly one bot. ENH (src/ui/lobby.c, untested): host/skirmish can toggle None/AI per row and pick AI faction; AI rows packed at start. NEXT: colours (find where player colour/remap is chosen; likely player index), teams (needs alliance in sim: who is enemy), Start button needs >=2 humans in MP (allow 1 human + bots?), MP joiner path.
- TEAMS (Oct 23, untested): functions/teams.md, src/sim/teams.c. Lobby team buttons (0x69+r), allied() in 11 hooks (unit/turret targeting, AI target lists, win check). User choices: team per player (No Team/1/2/3), SHARED VISION wanted (next), friendly fire kept. Colour = player index (1 Blue 2 Red 3 Green 4 Yellow 5 Black 6 White, verified in-game).
- Skirmish with 5 bots VERIFIED in-game Oct 23 (bases built, factions correct).
- Delivery gotcha: device_commit_files may reuse a cached upload for a stagedPath it has seen before -> always commit exes from a NEW stagedPath filename and read back (sha256) before reporting.
- Oct 23 rev 2: teams saved in data//SAVE<n>.TMS (companion file), team button moved right of faction, fair unit cap 178/N (fixes factories finishing units that never spawn when bots fill the 178-slot ENT table). Untested. NEXT: shared vision; maybe raise unit limit (ENT table 0x67fe10 is fixed 0xb2 slots; relocating it = big job).
- Oct 23: teams rev 3 VERIFIED in-game (placement, saves, cap). DEV CHEATS added (functions/cheats.md, src/sim/cheats.c): 'cheese steak khaos' +10000cr, 'khaos car' random faction unit w/ rank near HQ, 'khaos box' crate near HQ. Untested.
- Oct 23 later: cheats credits/box VERIFIED; car fixed (slot preassign, see cheats.md rev 2); HQ->truck pack-up added (hover own HQ = deploy cursor, click). Untested.
- Oct 24: HQ hover cursor removed; 'RE-ASSEMBLE HQ' build-list entry added (functions/cheats.md rev 4). Untested.
- Oct 24: in-game: units attack-move only after having attacked (user OK for now); RE-ASSEMBLE HQ works; deploy sometimes failed -> deploy_try (cheats.md rev 5). Untested.
- Oct 24 rev 6 (untested): shared vision for teammates (teams.md H13-H16: unit/building fog reveal gated by allied(owner, viewer 0x75ba10));
  khaos car tells the sender "<name> at rank N has spawned at HQ."; HQ truck (Mobile Base, 25000) buyable at the vehicle factory only while
  the player has no HQ building, no truck and none in production (cheats.md rev 6). tools/check_hooks.py: 43 ranges clean.
- Oct 24 rev 6 VERIFIED in-game (shared vision, khaos car message, HQ truck buy). rev 7 (untested): truck icon = HQ picture, HQ <-> truck
  keep hp percentage both ways, Doom Fist II card border red (in-memory art fix). cheats.md rev 7. check_hooks: 47 ranges clean.
- Oct 24 rev 8 (untested): Ctrl+D self destruct of the selection with 5 s countdown, Ctrl+D again cancels (cheats.md rev 8). check_hooks: 48 clean.
- Oct 24 rev 9 (untested): self destruct = double tap D (rev 8 Ctrl+D failed: Ctrl = force attack, and only one of two input gathers was
  hooked); lobby option 'HQ Deassemble On/Off' (id 0x6f, saved in .TMS 'TMS2'). rev 7 verified (truck icon, Doom Fist II border). check_hooks 49 clean.
- Oct 24 rev 10 (untested): ally hover = select cursor; tribute 1000 cr entries in HQ list (+ lobby 'Tribute Enemies' id 0x70);
  special orders never target allies. rev 9 verified (double-D self destruct, HQ Deassemble option). cheats.md rev 10. check_hooks 54 clean.
- Oct 24 rev 11 (untested): tribute entries after the buildings (own paging), icons tinted with the receiver's colour, 'more' page fixed.
  rev 10 verified (ally cursor, tribute, Tribute Enemies option). check_hooks 57 clean.
- Oct 24 rev 12 (untested): build list page 3+ (back next to more), cheat 'show <colour> credits', lobby 'Cheat Codes' (id 0x71, default
  Off). rev 11 verified (tribute at end, coloured icons, pages 1-2). check_hooks 58 clean.
- Oct 24 rev 13 (untested): build list 'back' returns to the previous page; middle pages show back then forward. rev 12 page 3 verified.

## Phase 3 (multiplayer) - started Oct 24 2026 (plan: PHASE3.md)
- Oct 24: menu animations ran 2.4x fast on the user's 144 Hz monitor. Cause [O]: toolkit poll 0x476aa0 has no timing; each call presents
  once via 0x494060 (Lock primary DDLOCK_WAIT, copy 640x480 back buffer, Unlock; no Flip, no WaitForVerticalBlank anywhere), menu loops
  call it back to back, so speed = how fast Windows lets the primary lock go (refresh paced; Siege.ini FullScreen=0 = windowed).
  Fix (ruleset=1): src/ui/framecap.c menu_present, redirect of the call at 0x476ae0; deadline pacing, Siege.ini [options] menufps
  (default 60, 0 off), timeBeginPeriod(1). Untested in-game. exe sha256 4977aac3a64587471357f4074bfa4b0d573a3dff7ef400bab07e71626192e192
  (previous kept as legion_enh.prev.exe, acb85a96...). Unused 0x450c70 = 50-present timing benchmark (no callers).
- Oct 24 M0: classic legion.exe on 2 LAN PCs (host 192.168.1.18, joiner .24, ping ok) via DirectPlay TCP/IP: joiner cannot find the host.
  Host also has a Radmin VPN adapter (26.168.174.58). Suspects: Windows Firewall (DirectPlay 47624 + 2300..2400 TCP/UDP), multi-adapter
  address advertised by DirectPlay. Imports [O]: DPLAYX ordinals 1 and 9 only; WSOCK32 listen/accept/connect/bind/sendto/recvfrom etc.
- Oct 24: menu frame cap VERIFIED in-game (menus right, gameplay speed unaffected at 144 Hz). Firewall rules added on both PCs (README).
  After that only the game's own Internet UDP finds the host; DirectPlay TCP/IP still finds nothing -> Phase 3 targets Internet UDP.
- Oct 24 (untested): main menu 'Credits' (src/ui/credits.c). The credits sequence existed only at the end of a won campaign
  (0x41d4a2..0x41d684: bgm17.xm, gfx\credits01..04.bmp, 400 x Sleep(16) per page or click/Esc, fade, unload all). Main menu buttons [O]:
  ids 0 New 0xb2, 1 Load 0xcd, 2 Multiplayer 0xe8, 3 Options 0x103, 4 Exit 0x126 (x centred, w 0x84, h 0x16; BtnCreate(id,type,x,y,w,h,text));
  ids 5 (0x40d230) and 6 (0x4719f0) are dispatched but never created (dev screens; GameText 'Online News', 'Encyclopedia').
  Menu music is SFX\stats.xm (not title.xm), restored after the credits like the shell does (0x4513d3..0x4514a3). Esc leaves the credits,
  a click turns the page. gfx\credits05.bmp = exit screen (0x45171e). exe sha256 9f9083cd65f31425e8196d92b642efcda05c7eda1e7e0f21b62299c47363b2a7.
- Oct 24 credits rev 2: rev 1 crashed on click with 'glxLoadMusic Failed - SFX\bgm17.xm code 1!' (then exception box 'GT_TEXT type').
  Cause [O]: 0x46f810 -> glx load 0x48ff5e fails (code 1) while a module is loaded (menu stats.xm); fatal via 0x405060. Fix: unload
  (0x46f800, 0x46fbc0, 0x46f580, flags) before loading bgm17. exe sha256 07a549a9299103f7992cf5e12f96bbc4368f13428694603eb764f8a7fabe0a73. Untested.
- Oct 24 credits rev 3: credits music = SFX\title.xm (0x4b96e4, user choice) instead of bgm17.xm. exe sha256
  4e6fb68cb4ed0305e3a38720a5ac6ba7e5848c87104c04ae11e2c84cc08c61fe. Untested.
- Oct 24 credits rev 3 VERIFIED in-game (title.xm). Phase 3 M8 builds (all untested, need 2 PCs):
  mp1 (514b89f3): MP in-game menu Save Game (paged), 'OP' keep-alive in sub menus, 'Game paused by <name>' overlay on waiting peers.
  mp2 (af557207): lobby slot taking (ui/slots.c), colour follows the row (colour index owner+side*8 via renderer item type 0xd queued by
  0x4930d0 at 0x4313d4 units / 0x418c26 panel), TMS5 save companion (32 bytes: + slots_on, colours[8], H, N).
  mp3 (13ad06e3): lobby 'Load Saved Game': host button id 0xa8 cycles existing saves (TMS5 required), file sent to joiners over '!L'
  datagrams (480 byte chunks, pull with 16-chunk bursts, FNV check) into SAVE9999, rows locked to the save, Start only when H matches and
  all joiners have the file; at Start 0x835034 = slot on every peer; load_game_hook keeps the local player 0x668ccc after LoadGame.
  Facts: LoadGame 0x433a60 field list (raw in ui/slots.c comment); NetRecv max 0x200 bytes incl. 4 byte check; MP start positions are
  random (MStartX1..6) so a row = colour + faction + team; frame-sync packet 'Q'+0x7f carries frame, RNG index and dword 0xa55e00[frame]
  (an existing per-frame check value -> M5).
- Oct 24 test round 1 (user): colours fixed per player regardless of slot -> cause: teams_from_lobby called teams_clear, which also
  ran slots_clear right after slots_pack. Fix: teams_reset (teams only). After the host leaves a running MP game everyone returns to the
  MP lobby silently (new game then works): shell path 0x451686 (H>1) -> 0x4516ea call 0x408110 -> jmp 0x4514d7 skips the music reload;
  redirect 0x4516ea -> mp_back_to_lobby (ui/credits.c) = 0x408110 + menu_music. UDP layer is host-relayed ('SERVER: GetUDP() Passing
  to N', 'System 0x01 - player list ... numplayers'), debug logs udplog.txt / udpstat.txt exist. mp4 exe sha256 d407266e25db570fad3371d759feccfada21e08225647828b47c82461b26c26d. Untested.
- Oct 24/25 alpha builds (legion_enh_alpha.exe, user tests these beside legion_enh.exe):
  a2: building tiles coloured by slot (tile renderer 0x4967e0: owner nibble of 0x8464f0 -> palette [ctx+0x34]+idx*0x200; hook
  0x49687e), player list colour boxes (frame table 0x4afbd8[p], remapped in memory). Units+tiles+boxes VERIFIED by user Oct 25.
  a3: bot names follow slot colour (sprintf at 0x415f00 from colour-name pointers 0x4b0ca8[p]; special orders print names
  0x78b770+p*0x80), cheat 'khaos mission' (hook 0x41abfb forces a new special order draw at 0x41ac6d). Colours VERIFIED.
  a4: cheat 'khaos card' (hand words 0x75ba20+p*16, 5 slots, -1 empty; deck 0x4afa58[64]; crate code 0x45eafe), Internet UDP join
  screen (src/ui/netui.c): Cancel returned 0 = connect (0x441e8f) -> wrapper returns -1; address remembered in Siege.ini lastip
  (default text push 0x441caf); numpad digits in edit fields (scancode table 0x4c1d70 at 0x477426). Diagnostic SLOTS.LOG still on.
  alpha a4 sha256 20ed70e3e69aa5b501225ce5a14696a02bcc88715d000e4368c8810b30d5accd. Untested.
- Oct 25 alpha a5 VERIFIED by user: UDP join Cancel (id 999 = Cancel, 900 = Connect; cancel_stub 0x441e43, conn_end 0x441e8f),
  lastip remembered, Hamachi works after firewall port rules (game port 25666 UDP+TCP, INADDR_ANY bind 0x4492e0), MP lobby sound.
- Oct 25 alpha a6 (untested): tribute icons for Chosen (iconsb1.bim frame 2 is empty -> tints built from iconsb.bim; offline render
  confirmed 7th tints incl. blue are right), lobby faction '?' (cycle text '7th|Ch|?', value 2 resolved 50/50 at Start from a host
  seed sent as gv id 0xab), lobby colour bars (drawn into the locked back surface from menu_present).
  alpha a6 sha256 c530207b35ac7bad544bed0c04d425cc4b9ba9779fba6162f4dffe4e392367dc.
- Oct 25 alpha a7 (untested). User a6 report: Chosen tribute icons all showed the local colour; alt-tab froze both PCs then
  'Network timed out in BeginFrame!'; lobby bars invisible. Causes/fixes [O]: the build panel is drawn with the local player's
  palette state (0x418c14 -> 0x4930d0), Chosen palettes recolour the tint pixels -> tribute icons drawn with state 0 and restored.
  Focus loss: WM_KILLFOCUS 0x405470, WM_ACTIVATEAPP iconic 0x405554, handlers 0x405a33/0x405b35 minimise and set 0x507364=1, input
  readers 0x406000.. spin until 0 -> in MP (H>1) these take the no-DirectDraw branch (focus_stub1..4, ui/mpmenu.c). Lobby bars: the
  toolkit poll presents with 0x493f20 at 0x476dea after drawing (0x494060 at the top only re-locks) -> bars drawn there (poll_present).
  New: recent addresses lastip1..5 as buttons 960..964 in the UDP join screen (edit field create 0x441cc6 redirected, click dispatch
  in cancel_stub/join_click). alpha a7 sha256 75a637052a93a1c0eda7c1e72ae47180f5aa67b714f2b920db5dc8d2a0e258c4.
- Oct 25 alpha a8 (untested). User a7 report: colour bars and recent addresses VERIFIED; alt-tab still froze everyone and the
  alt-tabbed game could not be resumed; a joiner who left the UDP lobby stayed listed (Start hung, rejoin crashed both PCs).
  Alt-tab: focus_stub1..4 removed (original pause back). New: the PeekMessageA import slot 0xac45fc (.idata writable) is swapped at the
  first menu present for peek_hook (ui/mpmenu.c): while paused (0x507364==1) in MP it sends 'OP' (NetSend(8,0)) every 100 ms and naps
  2 ms, so the others show 'Game paused by <name>' instead of timing out. Lobby leave [O]: a joiner's Back sends '#leave#' x15
  (0x440d9f), receivers set result 700 (0x440ecc) -> lobby top 0x4409e6 -> GetPlayerList; the UDP server table (0x8754a0, 0x9c per
  entry, count 0x877bc8) never removes anyone. Host now removes entry r-1 on '#leave#' (udp_remove, ui/slots.c), renumbers ids/names,
  resends the 0x81 0x01 list to every client, shifts slot ids, and sends '!LR'+count (also every 16 polls); a joiner with a different
  count sets 0x877bc8 and turns the message into '#leave#' so the original rebuilds its list. check_hooks 81 ranges clean.
  alpha a8 sha256 51ed7b284068626ad5e400f3339a3fe7c7aeeaa2b6cbd86b57a2809abdaa423b.
- Oct 25 alpha a9 (untested). User a8 report: lobby leave + rejoin VERIFIED; alt-tab pauses everyone and resumes on return (works but
  looks like a freeze); Esc in MP does not pause. [O] Esc handler 0x41c860: with H>1 it only toggles 0x66d3a0, a non-modal box drawn by
  the game loop (0x4199ac, GameText 9..12 Options/Continue/Give Up/Leave Game) while the game runs on. The SP path 0x41c8ef is MP aware
  ('OP' around the modal menu 0x43f7f0, whose MP mode has Continue/Options/Quit; Quit = 0x9d6310[local]++ like Leave Game). NOTE: so
  the a1..a8 MP menu additions (Save Game, 'Game paused by' overlay) were never reachable before. esc_stub (0x41c8d6) sends MP Esc to
  the modal path; esc_frame (redirects of call 0x41c860 at 0x41cd20, 0x41d1bf) presses Esc on the first frame after an alt-tab pause.
  Faction label '?' -> '??'. Lobby options page 2: 'More...'/'Back' button 0xb0 at (0x1a0,0x7e); hidden options = toolkit type 2
  (drawer 0x476200 draws nothing for it) + disabled; page 2 = 'Tech Lab Off|On' (id 0x72, host broadcast range now 100..0x72, TMS5
  byte 27). Tech Lab Off: tech mask 0x70db80[11] (Hi Tech Lab) = 0 every frame (people availability only comes from it, 0x443565 and
  0x4582e9) and ai_tech_stub at 0x46a602 (AI_ChooseBuilding) treats type 11 as not allowed. Building table facts: cost 0x4bb7c4 +
  t*0x204, name ptr +8 into GameText; tech table 0x4addc0[t*10+level] has the lab from level 4 (Lo=4, Med=6, Hi=9), so it was already
  buildable in MP after the Vehicle Factory (depend.dat bt_tank -> bt_randd). Sell: double tap S (word 0x71b41e) on an own finished
  building -> 5 s countdown -> hidden '\x01SS' + index + type+1 -> every peer refunds cost/2 and calls DestroyBuilding 0x42ccc0.
  check_hooks 85 ranges clean. alpha a9 sha256 628663f31d9a3ef776cc10a9eb55b139571f7e77d6d69e4a9a0a0fa0ead6d01f.
- Oct 25 alpha a10 (untested). User a9 report: sell, Tech Lab Off, MP Esc menu, Quit (joiner destroyed, host plays on) VERIFIED;
  but while one PC sat in the menu (saving) the other froze without 'Game paused by' and both died with 'Network timed out in
  BeginFrame!'; lobby 'Load saved game NONE' did nothing. [O] UDP games wait for turns in 0x401d30 (not 0x4450bb): net pump 0x4011a0
  (NetRecv at 0x4011f3, types 'Q' turn data, 'R' resend; others ignored), missing player in esi, 40 s timeGetTime timeout at
  0x401e24..0x401e42 -> fatal 0x401f1a. Fix: pump_recv notes 'OP' senders; wait_stub restarts the timer while someone is paused (shows
  'Game paused by') and after 40 s of silence from a non-host player sets 0x9d6310[p]=1 (no quit command, army stays) and the host AI
  plays them: AI driver 0x447d80 gates ai_any_stub (0x447d92 H==N early exit, pending builds 0x5bbd5c+p*0x20 -> 0x448390) and ai_p_stub
  (0x447e41 H<p). Lost host still fatal. Lobby load: skip unusable saves (no TMS5, e.g. SAVE0) instead of stopping at the first one.
  More button x = 0x140 + 1.1 * width('Options...') + 8. Page 2 row 2 'Sell Buildings Off|On' (id 0x73, broadcast 100..0x73, TMS byte
  28). Team '??' (value 4): auto balance into the teams in use (opens team 2 if only one is used) or, with no manual teams, deal the
  '??' players into 1v1 / 1v1v1 / 2v2 / 3v2 / 3v3 or 2v2v2; seeded with the host seed (gv 0xab). alpha a10 sha256
  8165ff9fdb7fc08415a536a1d51f2912df4d08175981c07e1f649f332d741804 (check_hooks: 89 ranges; the one flag is the jns inside the replaced
  0x401e24 block itself).
- Oct 25 alpha a11 (untested). User a10 report: 'Game paused by' and MP save + lobby load VERIFIED. New: host load label 'LOAD <name>
  WAIT..' until every joiner has the file (load_gate), then 'READY'. TMS6 (48 bytes): +32..36 lobby options 100..104 (globals 0x9d6b64,
  0x9d5aec, 0x9d6330, 0x9d5ae4, 0x92ab5c as stored at Start 0x4415d2..), +37..42 sides of players 1..6; lobby load writes the saved
  options/teams/sides into the buttons (host gv broadcast shows them to joiners) and locks them (slots_locked -> opage_apply; team
  buttons re-enabled when NONE). The joiner transfer now carries 48 TMS bytes. After a game [O]: 0x4516ea (lobby) vs 0x45169e (0x408110,
  close net 0x40b8d0, main menu 0x451216): after_game_stub sends a joiner who quit (0x9d6310[local]) to the main menu after 3x '#leave#';
  the host removes quitters (0x9d6310[p]) from its UDP table before the lobby (slots_drop_quitters). Minimap player list: sprintf at
  0x41aa4e/0x41aa86/0x41ab53 -> list_sprintf prefixes 'T<team> ' to the name when teams are on. alpha a11 sha256
  2139e22df3241b53e365e7e1ca2b41b291790be9b01dd5a4bcd1855d2fd807c0.
- Oct 25 alpha a12 (untested). User a11 report: host crashes when it returns to the lobby after a joiner left the game (crash is on the
  host PC, no log here yet); after a lobby load the joiner saw the host's base and build lists while its orders went to its own player.
  [O] the session loader calls LoadGame twice (0x416941, then 0x416ce9 after 0x416c62 copied 0x668ccc into the viewer 0x75ba10), so
  the viewer, camera and selection came from the save. mp_load_local (sim/teams.c, from load_game_hook in MP): viewer = local, clear
  selection 0x6dd208/0x858514, camera on own HQ (else start point 0x6dd210/0x6dd250[p]) like the mission start (0x403c85..0x403d1e,
  camera 0x7168ce/0x71693e + 0x859528/0x85952a). Diagnostics for the host crash in SLOTS.LOG (after_game, drop_quitters, drop).
  alpha a12 sha256 602fd53a4d126bd91e877412029866205a07d915f48ea868ee4a39c6551756b2.
- Oct 26 alpha a13 (untested). Host crash after a joiner quit: host SLOTS.LOG shows drop_quitters finished (udp remove 1 of 2, count 1)
  before the silent hang; only one direction reproduces; PARKED (logging kept). Lobby header GameText 317 'Players...' -> 'Players and
  map...' (text.c). Team chat [O]: chat input 0x465540 opens on last-key 0x67fdbc == 0x1c (jne 0x465570), posts kind 0x65 at 0x4657c8;
  key scan 0x417cb4.. turns a held key into 0xfffb. tchat_stub (0x465570) also opens it on T (0x14) when teams are on and the local
  player has a team; chat_post (redirect 0x4657c8) prefixes "\x02<team> "; cheat_chat shows it as "T<team> ..." to the sender's team
  only (allied) and hides it from others. alpha a13 sha256 ddb0cd5e02183cef9f203e7ccbada0c106ededf9331ffe56df1173eef9b12d8f.
- Oct 26 alpha a14 (untested). User a13 report: 'Players and map...' and team chat VERIFIED; the host hang after a joiner quit no longer
  happens (returns to the lobby fine). Chat prompt [O]: 'Message To All...' GameText 188 (0x8629d0) pushed at 0x46589b -> g_chat_prompt,
  'Message To Team...' when opened with T. Options screen [O] 0x40dce0 (Back id 999 created at 0x40ddfd, poll 0x40df37, ids > 0x11 ->
  default 0x40e13b): new cycle button id 0x50 'Edge Scroll On|Off' at (0x168,0xa0), Siege.ini [options] edgescroll (default 1). Mouse edge
  scroll [O] 0x41dbc8..0x41dcc8 in camera routine 0x41d750 (arrow keys separate) -> edge_stub skips it when off. alpha a14 sha256
  795f4ce29d39b1a22f8d281b7ca05c136a34cd88eac37d539ab54c7a4d7b9944.
- Oct 26 alpha a15 (untested). User a14 report: edge scroll option VERIFIED; T sometimes typed an extra 't'.
  T fix: the key scan (0x417cb4..) saw T as a new press after the chat opened (0x67fdbc reset to -1) -> clear T's key-down word 0x71b408
  like the original clears Enter's (0x465597). Quit -> bot [O]: kind 0x63 handler sub 2/3 destroys the player's units/buildings
  (0x445e1b..0x445eb7), sub 3 sets 0x9d6310[p] and prints 'has quit'; quit_stub (0x445e0b) skips the destruction for a non-host quitter
  and sets g_dropped so the host AI plays them (same turn on every peer). Version check (M4): patch_exe.py stamps g_build_id = first 4
  bytes of sha256(patch.bin) (this build 7bd03059); every peer sends '!LV'+id every 16 lobby polls; host keeps Start disabled and shows
  'WAITING FOR <name>' / 'VERSION MISMATCH <name>' on the load line until every person matches; joiner shows 'HOST VERSION DIFFERS'.
  Desync check (M5): every 64 ticks each peer posts hidden '\x01CK'+tick+4 x 16-bit hashes (credits, units owner/type/alive/x/y,
  buildings owner/type/alive/hp/state, RNG index+tick); receivers compare with their own for that tick; first mismatch -> 'Sync lost at
  tick N with <name>' + data//SYNC.LOG (tables at detection). Scoreboard request PARKED. alpha a15 sha256
  0fc9cbe6cfd993e1b49551c8060c6f3eb7be4663bbaecdf15fea89c4407d05d7 (reproducible build checked).
- Oct 26 alpha a16 (untested). Seat choice in lobby loads: rows = saved players (by saved colour); host seats each person (own saved
  number if that was a person, else a free saved person, else a free saved bot) and anyone can click a free saved row (joiners via gv
  0xa6); free saved bots show 'AI Player', free saved people 'Empty Player'; Start needs >= 2 people seated and the file everywhere.
  Problem [O]: the net layer uses player number == UDP id (UDP NetSend passes dest straight to 0x4499d0 at 0x40c2ed; NetRecv returns
  the sender's UDP id from 0x449d80 at 0x40c024; the turn loop 0x4011a0/0x401d30 indexes turn data by it). Fix: lload_plan at Start
  (player <-> UDP id, same on all peers), udp_send_map/udp_recv_map translate while g_remap is on (first LoadGame .. after_game);
  lload_apply after each LoadGame: H = N, free saved players quit (0x9d6310) + g_dropped (host AI plays them), names of taken players =
  current people, local player = chosen seat, g_host_pl for the drop/quit rules. TMS byte 43 = players a bot played when saved.
  Skirmish loads keep the old behaviour (no seat clicks). alpha a16 sha256 b9fed0f0ac462ff7c4025a471e676769a04847defbd256e9a21e2eb804d13dd8,
  build id 7e80fefe.
- Oct 26 alpha a17 (untested). User a16 report: version check VERIFIED; joiner leaving crashed both PCs; empty seats in a lobby load
  not clickable; lobby-loaded MP game froze both PCs. REVERTED to a15 behaviour: seat choice in lobby loads (slots.c/mpmenu.c/teams.c
  back to the a15 files, no net remap, no H=N) and quit -> bot (quit_stub no longer patched; a quitter's army is destroyed again;
  timeout drop -> bot stays). Last joiner SLOTS.LOG showed the plan ok ('lload plan me 2 p2u 1 2', 'apply my 2 n 4') before the freeze,
  so the freeze is in the H=N / player-number mapping. New: watchdog thread (CreateThread/GetAsyncKeyState via GetProcAddress) ends the
  process on Ctrl+Alt+End or Alt+F4 held 2 s; numpad digits in the in-game chat line (chat_key_stub 0x4657d5 maps 0x47..0x53 to the
  main row). alpha a17 sha256 40c9ee040eb269870af4cd1145fa916d720cec0454c5321a59b71290459d50cf, build id 5b1daca1.
- Oct 26 alpha a18 (untested). User a17 report: reverts OK (joiner who leaves is destroyed again, MP load works), chat numpad VERIFIED;
  connect screen still ignored the numpad. [O] edit field handler tests 'cmp bl,0x35; ja' at 0x4773ea before the table lookup
  0x477426, so the a4 key_stub was never reached -> edit_key_stub maps numpad scancodes first. Main menu version line ('1.00' 0x4af628
  pushed at 0x40da56/0x40da6b) -> g_ver_label '1.00  Enhanced a18' (credits.c ENH_VER). Protocol screen 0x441a60 (entries 0x9e8660+i*0x100,
  count 0x9e8060, UDP and Skirmish appended last by 0x40b320): proto_btn (redirect 0x441b37) keeps the ids but places Internet UDP,
  TCP/IP, other providers, Skirmish and drops the modem button. Cancel: proto_screen (imm32 0x44042c) notes -1, create_join (redirect
  0x40dc82) shows Create/Join again instead of the main menu. alpha a18 sha256
  8ad001cfaeedbf176c9f0a4c3cd396210d6d3d1c1f663aa38a549b270c664475, build id c8f2359e.
- Oct 26 alpha a19 (untested). User a18 report: connect-screen numpad and protocol Cancel VERIFIED; version line cut off; protocol order
  unchanged. Cause [O]: the protocol entry loop pushes dwords read from 16-bit locals ([ebp-2] index, [ebp-4] y), so the high words hold
  other locals and proto_btn's 'id < 16' never matched -> id cast to s16. Version label: text '1.00 Enh a19', label width byte at
  0x40da76 0x46 -> 0x70. alpha a19 sha256 f2d6fe911f7b33407799d4c758a2ab901399ca1108c93e3c9974a211dbebe355, build id a60c6536.
- Oct 26 alpha a20 (untested). User a19 report: protocol order and version line VERIFIED. Cancel on the 'Enter Host Address' screen now
  returns to the protocol list: net_manager (redirect of call 0x40b320 at 0x440431) sees the address-screen Cancel (join_click), closes
  the network (0x40b8d0, as the main menu does on that result) and runs the manager again. Version line 'Enh a20'. alpha a20 sha256
  ad8a84310edd16f551c4a5a2ddc7a43c6e63f33874cea46825e916109d6ad941, build id 14eb1071.
- Oct 26 alpha a21 (untested). User a20 report: address-screen Cancel VERIFIED; team '??', Chosen tribute icons VERIFIED; a quitting
  joiner already lands on the main menu. GITHUB-README rewritten for the current feature set. Score screen (sim/score.c): counters
  from the game state each frame (kills = game counter 0x9d5a00[p], incremented at 0x42cbdd; units made/lost from the ENT table
  creation stamps; buildings made from building serials; research = Hi Tech Lab producing -> idle; tribute moved by trib_tick),
  points kill 100 / unit 20 / building 50 / research 200 / tribute 1 per 10 cr. Shown after skirmish and MP games: redirect of the
  main game loop call 0x41cd90 at 0x451656, title music, toolkit screen with 'Return to Menu', table drawn in poll_present via the
  game text queue. HD/4K assessed: the engine is fixed at 640x480 (DDSetMode(640,480,16), ~140 hardcoded 0x280/0x1e0 plus derived
  constants in renderer, panels, minimap, menus); recommended a DirectDraw wrapper for sharp scaling now, a real wider view later.
  Version line 'Enh a21'. alpha a21 sha256 a9f247e44a84384b3f2e118f7aa9ef6486501fcafcec013c3fd6808d51f6be87, build id af08c927.
- Oct 26 alpha a22 (untested). a21 crashed when leaving a skirmish ('InitGame(). GT_BUTTON Type'): the score screen opened straight
  after the game loop and drew with the in-game font [0x6683e0], freed by then. Now the game-loop wrapper only marks the score as due;
  mp_back_to_lobby shows it after 0x408110 (frees the game resources) and before the lobby music. Text drawn with the toolkit's own
  call 0x494230 and font [0x5926bc] (with [0x4d7dd0]=0 it appends to the list at [0x4d7dd4]). alpha a22 sha256
  9f45d4b8aac5b2b4c76e41ec5a468024de570b38d53c7810cd6a36bc403fce3e, build id 5cb70c29.
- Oct 26 alpha a23 (untested). User a22 report: score screen shows, layout fine, text doubled and yellow. [O] 0x494230 draws every
  string twice (0x49427c.. then 0x4943c6..), the second pass offset by its 5th argument (the toolkit's shadow); in list mode both
  passes look the same -> argument 0. The menu font newfont.bim is yellow; the player rows are now rendered into a scratch 640x480
  surface and copied as white with a 1 px dark shadow (title, headers and footer stay in the menu yellow). alpha a23 sha256
  46669440a518ee17b4a44fe5fee8a761211c05893d52cb55db059da4f4de4c20, build id 47373fdd.
- Oct 26 (Phase 4 start). Phase 3 closed; START-HERE.md rewritten, PHASE4.md created, README updated. Windowed / borderless / HD
  scaling: cnc-ddraw (ddraw.dll wrapper) tested by the user with legion_enh.exe and works; documented in the README (P4.1 done).
- Oct 26 alpha a24 (untested). Score screen text looked bold: [O] 0x494230 queues each glyph twice (shadow pass, then text pass);
  put() now keeps only the second half of the items each call added. Columns spread (Kills..Score right edges 0xf8..0x270), footer
  shortened and centred ('Kill 100  Unit 20  Bldg 50  Tech 200  Tribute 1 per 10cr'). alpha a24 sha256
  a2448997d44566de5c2a48fdf955f33197015b6b975f77ce010c72e49cba28bd, build id a34629cc.

## Phase 4 alphas a25.. (one section per build)
### a25 (Oct 26 2026) - right click cycles lobby maps backwards
- Lobby (host and skirmish, not in Load Saved Game mode): right click on the map button (id 0x96) picks the previous map, wrapping
  from the first map to the last. [O] right button word 0x4aea48 (WM_RBUTTONDOWN/UP in the wndproc 0x40572b/0x405739); left is
  0x4aea44. Toolkit slot rect: +4 x, +6 y, +8 w, +0xa h (hit test 0x476e42..). Mouse x/y from 0x406000 / 0x406140.
- How: `lobby_poll` is now a 2-instruction asm entry that saves the lobby's ebp (g_lobby_ebp) and jumps to `lobby_poll_c`. On a right
  button press edge over the enabled map button, `map_back` sets the map local [ebp-0x10] to target-1 and reports a click on 0x96, so
  the original code (0x440cfd: inc, '@' wrap, SETT, '!gv!' broadcast) shows the map and tells the joiners. No new patch sites.
- sha256 5cb67df37d6cd03adc2a4008c1983fc2cb6c0b7074df67acf699b4136b562717, build id 74d21034.

### a26 (Oct 26 2026) - desync diagnostic (kills differed between PCs)
- User: full 2-human MP game (a25), score screen kills differed (host 77/19, joiner 74/20); units, buildings, tech, tribute equal.
- Host SYNC.LOG: first mismatch at tick 1920: credits, units, buildings hashes equal, only the rng hash differs (index 0x90a27c).
  So the shared game RNG (table 0x4afc00[1024], index 0x90a27c; RandMask 0x40ca00(mask), RandMod 0x40ca30(n), seed 0x40c9e0) is
  advanced differently on the two PCs; combat that uses it then credits different killers ([O] kill credit 0x42cbdd = owner of the
  target's last attacker, unit field +0xa4).
- [O] The original already protects one local-only user: on the host the AI 0x447d80 runs between a save and restore of the rng
  index (0x419089..0x4190b6). CRT rand 0x49c540 is seeded from the clock (0x440482, 0x450df5), so it is local per PC.
- [O] Inline (no call) rng uses: 0x403350, 0x40f2d0 (init, 10), frame 0x416fe0 (0x41a9bf, 0x41ac94), 0x435580 (reset), 0x4368a0
  (0x438108: gated by CRT rand, but 0x4368a0 only runs with 0x7ffe50 set, looks like a developer map editor), 0x43efb0, 0x44d440,
  0x44d960, 0x457bf0, 0x467d80, 0x4698f0, 0x46c300 (24), 0x46efc7.
- Diagnostic: RandMask / RandMod replaced by identical C versions (rng_mask / rng_mod, jmp at 0x40ca00 / 0x40ca30) that log
  (tick, index, caller) into a 64k ring; esc_frame logs a frame marker (caller 0). At the first 'Sync lost' each PC appends the
  ring since the previous good check to data/SYNC.LOG. Compare both PCs' files: first line that differs = local-only caller.
- sha256 ecd94042fc793e2b7c8b5871f97da7085f18edc6a065951743e368ebcbf956d4, build id 977f82c4.

### a27 (Oct 26 2026) - desync diagnostic 2, click sound on right-click map
- a26 result (both SYNC.LOGs, desync at tick 6144, previous check 6080 fine): rng index equal, units and buildings equal, only
  credits differ: player 4 (a bot) 11830 on the host, 11730 on the joiner (100 less). No RandMask/RandMod calls in that window; the
  only rng use was one inline step per frame (0x41a9bf). So this desync is a credit change applied on one PC only.
- [O] ExecTurnCommands 0x445930 (called at 0x417dbb): slot word 0x83a3f6, count word 0x66d910[slot], records 0x79fdf0 +
  (slot*64+i)*0x2c: +0 kind byte, +1 player byte, +2 word, +4 data. [O] AI 0x447d80 runs on the host only (0x419079); the
  AI-reachable credit writes: 0x42302a (CreateBuilding 0x421d40, cost from 0x4bb7c4, halved), 0x423abd (0x423710),
  0x42cc6c (0x42bd90).
- Diagnostic now logs per tick: frame rng (F), rng calls (R), every executed command before execution (C: slot kind player word
  data) and all credits after ExecTurnCommands (M), dumped into SYNC.LOG at the first mismatch (from the previous good check).
- Lobby right-click map now plays the toolkit click (sample 0x4b95f0, 0x46f780 twice, as at 0x4772d2).
- sha256 0e0f6945bfa8eed03cbf1eade8e01c299c0851990deb3075cb2df72e6dde39ca, build id d78b51c9.

### a28 (Oct 26 2026) - more commands per turn (lag fix), lasting rally points, desync diagnostic 3
- a27 result (desync at tick 9344): credits and rng equal, executed commands identical on both PCs (bytes past the command length
  differ but no handler reads them), only bot unit 109 (owner 4) at a slightly different position (1959,2232 vs 1962,2228).
- [O] Netcode facts found: damage is not computed in lockstep but reported by the VICTIM's owner PC (0x42bd90 in queue mode
  0x71667c==1: victim owned by the local player, or an AI on the host -> command kind 14 {bldg, ent, damage, new hp}; all PCs apply
  it when the command executes). Unit orders (PostOrder 0x423710, kind 6), production (0x423250, kind 5) and unit creation
  (CreateUnit 0x424c20, kind 2, carries the owner's credits and the rally) work the same way: the owner PC decides, everyone applies.
  The AI 0x447d80 runs on the host only and acts through these commands (they show as player 1 = the host).
- [O] LAG CAUSE: the turn sender 0x401961 sends at most 3 commands per turn in multiplayer (6 alone) from the 64-entry ring
  0x671a20; every hit is a command, so in fights orders queue behind damage reports (late orders) and PostCommand drops new ones
  when the ring is full (ignored orders). Fix: cmdcap_stub at 0x401961 -> min(16, 60 / humans) per turn (receive tables allow 48
  per player per turn, the turn record table 64 for all).
- RALLY (src/sim/rally.c): [O] BuildingOrder cmd 999 stores a rally tile in bldg +0xac/+0xb0; the production handler copies it to
  0x4b5bb0/0x4b5bb4 at 0x45a183 for CreateUnit, which sends the new unit there; the original UI only sets it while ordering (mouse
  on the map) and every new order clears it. New: select your production building, left click empty ground in the map view =
  lasting rally point (used when the order has none); left click on the building = clear. rally_stub at 0x45a183 (31 bytes).
  Selection is put back for 8 frames if the click deselected the building.
- Diagnostic: per tick hash of every unit (x, y, hp, state +0x62, order +0x78, alive) for 128 ticks (taken at the start of
  ExecTurnCommands) + raw unit records (0x6d0 bytes) appended to SYNC.LOG.
- sha256 06b29ae0d342c95db2a33a005c2238f27ea9ba3915324e0a822b44621b03c506, build id 4cbd2922.

### a29 (Oct 26 2026) - lockstep damage, crash logger
- User (a28): crash after the score screen again; movement still needs re-clicking; a building under fast attacks has a health bar
  that 'rubber bands'.
- [O] Cause of the rubber band and of much of the order lag: damage 0x42bd90 outside ExecTurnCommands only posts command kind 14
  from the victim's owner PC (host for AI victims) with the new hp computed from the CURRENT hp; every PC then applies damage and
  sets hp to that value. Several hits in flight all report 'current hp minus one hit' -> damage lost, bar jumps back; one command
  per hit floods the 64-entry command ring (3 sends per turn originally) -> orders late or dropped. Kills also come from this path.
- Fix (ruleset=1, multiplayer): damage applied directly on every PC (the callers are the projectile code 0x42a140, unit update
  0x454690/0x454d20, 0x45b430 and the frame 0x41bbbd, all lockstep sim): dmg_stub at 0x42be75 -> 0x42c009 (direct path), except
  the two local UI callers 0x463145/0x4631e7. heal_stub at 0x456ced opens an owner/host-only heal (-80 hp damage to unit +0x58) to
  every PC. g_lockdmg = ruleset && humans > 1, refreshed every tick in exec_cmds. No more kind 14 traffic from combat.
- Crash logger (src/ui/crash.c): SetUnhandledExceptionFilter -> data/CRASH.LOG with code, address, registers, the last 16
  breadcrumbs (game_start / game_end / back_to_lobby / after_408110 / score_show / score_close / score_music_stop / score_done /
  music / lobby_poll) and the code addresses found on the stack.
- sha256 449288b632ba9d433e43d3ffe049a2c8018b95b589c49de3a844c09469e4e435, build id 8e0aacd2.

### a30 (Oct 27 2026) - damage in exec context (order fix), hang sampler
- User (a29): damage looks much better (no rubber band); no 'Sync lost' (no SYNC.LOG); but group orders now work ~30% of the time;
  host froze (no crash, no CRASH.LOG) when White's (AI) HQ was destroyed, joiner timed out.
- Cause of the order problem: a29 sent damage to the direct path 0x42c009 but 0x71667c stayed 1, so what the direct path calls
  (PostOrder retaliation, DestroyBuilding, CreateUnit...) ran in queue mode: the owner PC posted an extra command per hit, executed
  turns later, overriding the player's newer orders. Originally the direct path ran inside ExecTurnCommands with 0x71667c==0.
- Fix: dmg_wrap at the entry 0x42bd90 (prologue 'push ebp; mov eax,[esp+0x10]; mov ebp,esp', 7 bytes, trampoline back to 0x42bd97):
  when g_lockdmg, 0x71667c==1 and the caller is not the UI (0x46314a / 0x4631ec): 0x71667c=0, call the body with the same 3 args,
  0x71667c=1. dmg_stub (0x42be75) removed; heal_stub kept. May also fix the HQ freeze if it came from queue-mode calls there
  ([O] 0x41bb12..0x41bc05: after a player is out (counter 0x9d5a24[p] > 0) every 15th building gets 5000 damage per frame).
- Hang sampler (src/ui/crash.c): g_hb counted in peek_hook; a thread samples the main thread (SuspendThread / GetThreadContext,
  16 KB stack guarded with IsBadReadPtr) after 6 s without PeekMessage and writes EIP, registers, crumbs and stack code addresses
  to data/HANG.LOG (Win32 file calls), 4 samples per hang.
- sha256 a908a849c03f8e6ecddbb6ca2aba32b410d80eb8136da7ca929d44070d199e01, build id b8fbdcb6.

### a31 (Oct 28 2026) - position resyncs in lockstep, crash logger without CRT, building history
- User (a30): orders better but in a group some units stop with a 'rubber band'; next click the moving ones snap back and stop and
  the stopped ones go (alternating). Host quits to desktop at the score screen; score screens differ. Host files: SYNC.LOG (sync lost
  tick 4160, buildings hash only), HANG.LOG (only loading screens and the paused Esc menu, no real hang), CRASH.LOG EMPTY.
- [O] Rubber band cause: 7 places (unit update 0x454d20: 0x455086, 0x45513c, 0x455a88, 0x455cef, 0x456372, 0x4566c8; and 0x44fb8a)
  let only the HOST post PostOrder(ent, 0x29a, state, 0/-1, x, y) = 'unit is at x,y in state s' when a unit finishes a path / idles;
  other PCs return. Executed turns later on every PC it snaps a unit that has a newer order back and stops it. Fix: gate_host (call
  replacing the 8-byte host compare) makes these checks true on every PC when g_lockdmg, and po_direct (redirect of the 7 PostOrder
  calls 0x4550b8 0x45517a 0x455ab6 0x455d1d 0x4563a4 0x4566fa 0x44fbb4) runs them with 0x71667c=0 = applied at once, no command.
- Still owner-gated (left for now): auto-target decisions 0x455556 / 0x455892 (owner PC posts PostOrder kind 2 + SetUnitMode).
- CRASH.LOG empty = the CRT path (fopen buffer malloc) probably hit a corrupted heap; the filter now writes with CreateFileA /
  WriteFile and its own hex formatting. Hang sampler skips tick 0 (loading screens).
- SYNC.LOG now also has per-tick building hashes (G lines: hp, state, alive, type, timer +0x6c, item +0x94, owner) for 128 ticks
  and raw building records (BR lines).
- sha256 da957d8feb52860326210d6ac2a9776c0e6bd732c7ee2c0a8ee0fca01fe23b64, build id 81f515da.

### a32 (Oct 28 2026) - score screen crash, production in lockstep, rally points synced
- User (a31): movement a lot better; sometimes units go to the ally's base instead of the move target; unit + research finishing
  together both got paid though only one was affordable; host exits at the score screen again.
- CRASH.LOG (a31 Win32 logger worked): access violation at 0x041c5955 (outside the exe) in another thread (odd esp), stack code
  pointer 0x488d97 = XM mixer 0x488b8f calling the mixing routine [0x549340]; crumbs ... after_408110 score_show. The score screen
  called music_title (unload + load title.xm) and on exit music_stop (unload), then mp_back_to_lobby's menu_music unloaded again
  (0x46f580 twice in a row) -> mixer thread on freed data. Fix: mp_back_to_lobby plays the menu music first (proven M9.3 path) and
  the score screen no longer touches the music player (stats.xm plays under the scores).
- Production: [O] CreateUnit 0x424c20 in queue mode is posted by the owner (kind 2, executed turns later, carries the owner's
  credits), so the cost was not yet deducted when a research finished. cu_direct (redirect of 0x45a148 / 0x45a1c2 production and
  0x459831 refinery harvester) creates the unit at once on every PC (0x71667c=0).
- Rally points are now lockstep state: the click posts hidden "\x01RP" + bldg(3) + x(3) + y(3) (999 = clear), rally_exec in
  cheat_chat sets them on every PC (needed because creation is direct everywhere).
- [O] CreateUnit 0x4256c1: a rally tile inside a building of another owner makes the new unit target that building (state 2).
  rally_pick drops a rally on an ALLIED building (possible source of 'units go to the ally base').
- sha256 91b8c3bb75e4070270640c42c71edd985b457a3ae37f70165d89bf297c732843, build id b5640def.

### a33 (Oct 29 2026) - 10 minute network wait, state dump key, crash module name
- User (a32): a long pause -> joiner 'timed out' and exits, then the host crashed too; after a joiner crash the host played on but
  had no sounds and could not make units, and this stayed in the next game; asks about MP vs skirmish balance; score screen crash again.
- CRASH.LOG (a32): same as a31: access violation at 0x065d8bdd outside the exe, other thread (esp ...fe2a), right after
  game_end / back_to_lobby / after_408110 / music / score_show. Another a32 score screen (tick 10742) closed normally. The menu-music
  reload alone does not avoid it. a33: 400 ms Sleep after the music reload before the score screen (crumb music_settled), and
  CRASH.LOG now names the module containing the crash address (GetModuleHandleExA FROM_ADDRESS + GetModuleFileNameA).
- Network wait (wait_check): a silent non-host player is handed to a bot after 60 s (was 40 s); 'Network timed out in BeginFrame'
  only after 10 minutes without data from the missing player (was 40 s; the stub still compares with 0x9c40, wait_check returns at
  most 0x9c40 below 10 min). After 5 s the waiting PC shows 'Waiting for <name> <seconds>' (pause_overlay with g_wait_secs).
- Ctrl+Alt+S (watchdog thread sets g_dump_req, esc_frame writes): data/STATE.LOG with H/N/local/host, 0x71667c, g_lockdmg, sound
  flags and sample pointers, dropped players, per player credits/quit/unit count/cap/side, and the local player's buildings
  (type, hp, state, timer, item, queue, rally). For the 'no sounds, no units' state.
- Balance check [O]: damage uses the unit type table and the per-player research levels (0x6dd180, 0x6dd2a0, 0x719f90, 0x8046d0,
  0x66d8f0) only; no multiplayer/skirmish multiplier in 0x42a140..0x42ccc0. Mode-dependent: lobby option 104 (0x92ab5c ->
  0x83e4d0 at game start): 1 = HQ (building type 0) takes no damage (0x42bdee), 2 = new units get flag +0x688 = 1 (0x425606).
  Siege.ini 'difficulty'/'hardness' are not read by the exe (strings absent). Before a29 MP damage was partly lost (kind 14).
- sha256 5781c348ee13656d864ea20a5043d8bb5cf12de992307150e3b7c6c4e967e222.

### a34 (Oct 29 2026) - post-game sound crash, group attack orders, double tap group key
- User (a33): group attack needs 2-3 clicks (some attack, some stop in range, some never move), skirmish and MP; quitting a game now
  exits straight to the desktop (both PCs); wants double tap of a group key to move the camera to the group.
- CRASH.LOG (a33): crash in the mixer's generated code (no module) right after game_end / back_to_lobby / after_408110 / music, i.e.
  during the 400 ms wait. [O] Single player end (jmp 0x451216): 0x46f800 stop music, 0x46fbc0 unload, 0x46f580 restart output,
  THEN 0x408110 cleanup. MP/skirmish end (0x4516ea) calls 0x408110 with the music still playing -> mixer on freed data. Fix:
  mp_back_to_lobby does music_unload() before 0x408110 (crumb sound_stopped). Probably also behind the lost sounds after a drop.
- Pathfinder (ruleset 1, path_new.c): no free slot (13) set state 0, which the unit update counts as a failed path (0x456a2f retries
  while +0xd0 <= 4, then the unit gives up and idles) -> part of a big group never moved. Now the request stays in state 1 and
  retries next call; expansions per call 128 -> 1024 so searches finish in the call and free the slot. Lockstep: both PCs same build.
- Double tap 1..0 (group_stub at 0x462e2b): [O] groups 0x66cdd0 + g*80 (40 words), counts 0x67fde0[g]; camera request
  0x859528/0x85952a (+ 0x7168ce/0x71693e), view 0x80315c x 0x7166a4 tiles. Same key within 400 ms without Ctrl centres the camera
  on the average position of the group's living units.
- sha256 5405a3c1f0ff9623dd31d973f404ba0e0bcea414840d94727086541ed7a3c986.

### a35 (Oct 29 2026) - orders not replaced by auto-target, stuck production, chat history, host silent after MP game
- User (a34): units drift back to old orders; production stopped (STATE.LOG); host crashed before the score screen (joiner fine);
  wants Up/Down arrow chat history.
- CRASH.LOG (a34): host only, mixer generated code, after sound_stopped / after_408110 / music (within the 400 ms). The stop before
  cleanup did not help. a35: the host does not reload music after a multiplayer game (crumb host_silent), joiner still does.
- STATE.LOG: local factories (types 5, 9, 11) state 0 with queue +0x98 = 4 (field printed as 'item' is the handler pointer +0x94;
  the item is +0xa4). [O] after a completion with more queued the handler sets state 0 and re-issues BuildingOrder(b, 2, +0x70,
  +0xa4, queue) as a command (0x45a2fb); if that command is lost the building idles and new orders only grow the queue. prod_watch
  (rally_frame, owner PC) re-posts it after 3 s of 'state 0 + queue > 0 + item >= 0'.
- [O] Auto-target (0x455545..0x455a2b, owner PC only, uses the local fog map 0x66da10 so it cannot be made lockstep) posts
  PostOrder kind 2 + SetUnitMode from the unit's current state, which does not yet include the player's newer order still in flight,
  and its command executes after the player's and replaces it. po_entry (jmp at 0x423710, 6-byte prologue) marks a unit 'order
  pending' when any other order is queued for it (multiplayer, 0x71667c==1); exec_cmds clears the mark when a kind 6 command for the
  unit executes (or 150 ticks). While pending, the auto-target PostOrder (return 0x45562e 0x4558df 0x4559f8 0x455a21) and
  SetUnitMode (redirects 0x455614 0x4558e5 0x4559dd 0x455a06 -> sum_auto) are skipped.
- Chat history: chat_post records sent lines (16); chat_key_map maps Up 0xc8 / Down 0xd0 to recall into 0x4e0d88 / 0x4e0f58.
- sha256 176a3b75850ebb1907fb79fa3391ca3df30aadd1a6f902e408c62886779075a4.

### a36 (Oct 30 2026) - heap check crumbs, fuller STATE.LOG
- User (a35): chat history works; score screen OK (host silent); back to the main menu the host plays music for a moment and exits;
  production stuck again (STATE.LOG saved). This PC's data has no new STATE.LOG / CRASH.LOG since a34 (last MP game here 21:28
  Oct 29; today only a skirmish start 05:53), so the a35 files are on the other PC.
- heap_check (crash.c): HeapValidate over GetProcessHeaps; crumbs heap_ok/heap_bad + where, every 500 ticks in a game
  (exec_cmds) and at back_to_lobby / after 0x408110. Shows in CRASH.LOG whether the heap was damaged before the mixer crash.
- STATE.LOG buildings now print the real item (+0xa4), qty (+0xa8), total time (+0x70), grace (+0x0c); plus command ring head /
  ack, tech mask words 0x70db8a.. and the local player's availability bytes 0x754fb0[p*0x50+t].
- sha256 c9aa67cf06aa0fd8a53aec41bdf6d6c47cefefa766203eba834c1c6e95eacdd5.

### a37 (Oct 31 2026) - command repeat filters, ring stats, host sound off after MP game
- User (a36): no units can be made by any player (credits not spent, nothing comes out); host: score screen silent, lobby, then
  main menu plays music for a second and crashes. CRASH.LOG: heap_at_end and heap_after_cleanup OK (heap valid), crash in the mixer
  (stack 0x488d97) when the main menu music started (tick 0, crumbs ... score_done lobby_poll). No STATE.LOG this time.
- [O] In queue mode the game's repeat filters (PostOrder: last order fields +0x78..; SetUnitMode 0x424300: +0x6e mode) compare
  with the unit state, which only changes when the command executes, so code that decides every tick (host AI, retaliation 0x455614)
  posts the same order/mode every tick until then -> the 64-entry ring overflows and other commands (production re-issue, deaths,
  player orders) are dropped: likely cause of the production stop. po_check now keeps the last queued order signature per unit and
  skips identical ones for 60 ticks or until the kind 6 command executes; sum_entry (jmp at 0x424300, 7-byte prologue) does the
  same for SetUnitMode (cleared when kind 13 executes; record +4 mode, +6 ent). Commands per turn min(30, 60/humans).
- STATE.LOG: per player unit slot range usage and 'dead but not freed' count, ring occupancy now/max/full ticks (sampled each tick),
  production buildings of every owner (with owner).
- Host after a multiplayer game: sound flag 0x4d85a0 = 0 for the rest of the session (only read from Siege.ini at start 0x494dc8,
  never written back), so the main menu music cannot start the crashing mixer. Stopgap until the mixer issue is found.
- sha256 1dd5e0bc870f949da384d773a8cbbfc8d315d3fa652b710fb357e60379516253.

### a38 (Oct 31 2026) - keyboard navigation in menus
- menu_nav (framecap.c, from poll_present = toolkit poll 0x476aa0 before its hit tests): Up/Left previous, Down/Right next enabled
  toolkit button (types other than -1 / 2 hidden / 6, sorted top to bottom, left to right) -> mouse words 0x4aea3c/0x4aea40 set to
  its centre (game cursor and hover follow); Enter / keypad Enter = left click (0x4aea44 down one poll, up the next). Active from
  the first arrow press until the real mouse moves; otherwise Enter is untouched. Each key-down message is one step (key word
  cleared after use). Includes all a37 changes.
- sha256 8558e502282bcc1d5ff9064c1c94a4377a1bd18ee448ac8f5f8ba94b247726a8.

### a39 (Oct 31 2026) - multiplayer production fixed, robot hangar ore carriers
- User (a38): MP: no units, only the 'unit ready' sound, no cost; skirmish: the robot hangar keeps making ore carriers.
- [O] Cause of the MP production failure since a32: in a running game (word 0x6e5a60 = 1, 0x41cfcc) CreateUnit 0x424c20 skips its own
  slot search (0x424d2b) and uses dword 0x4b5650, set by the kind 2 handler from the slot the owner picked when queueing
  (0x445a37 <- record +0x16). cu_direct called it directly with 0x4b5650 = -1 -> silent failure (the 'unit ready' message comes
  after the call). cu_direct now picks the slot like the queue path 0x424e2e (owner range (owner-1)*(0xb4/N) .. +0xb4/N-1, whole
  table for 1 human or owner 0x2707; first record with owner 0 and +8 == 0) and resets 0x4b5650 to -1 after the call.
- The 'stuck queue' STATE.LOGs were this failure; prod_watch (a35) is switched off: in skirmish it re-issued orders from fields that
  do not mean 'queued item' for every building (robot hangar making ore carriers).
- sha256 7ced27b8381d9bd0fedcef932b54eac814991ee300c02ad17c556c18e9e826b8.

### a40 (Nov 1 2026) - P4.6 steps 1 and 2: reliable posting, net diagnostics, subsystem sync hashes
sha256 7b10f77299b3a0e16a47a2e7280eea943e07905b3771c3a34d65a99105284987. New file src/sim/netcmd.c; tools/syncdiff.py.
- Transport read [O]: per-command 'Q' packets + 0x7f end marker; received flags 0xa239f0[(frame*48+idx)*8+sender]; missing -> 'R'
  frame idx (0x401877) -> sender resends from history 0x92ab60 + (frame*8+idx)*0x2c (0x40171b) + end marker. Turn wait waits for all.
- BUG: history has 8 slots per frame; cap 30 since a37 (16 since a28) overwrote the next frames' entries, so a resend of command 8+
  sent another command (ignored as duplicate) -> endless 'R' -> long waits / 'Waiting for' after packet loss. Fixed: g_rhist
  128 x 32 x 0x2c; stubs hist_w_stub 0x401b66 (18), hist_z_stub 0x401bf2 (7, keeps flags), hist_r_stub 0x40171b (31). Always on.
- PostCommand 0x444c00 replaced by post_cmd (jmp): ruleset 1 keeps a FIFO backlog of 512 when the ring is full (flushed before
  every post, at every turn send (cmd_cap) and every frame (esc_frame)); order kept; 'lost' counted only past 512. Classic: original
  drop. Native test: 4900 orders in bursts of 200, 30 per turn: all delivered in order, backlog max 138 (all would have been lost).
- Counters: posted, backlog max/lost, 'R' sent (redirect 0x40189d net_send_r) / received (pump_recv), turn wait ms/max/who/count.
  Ctrl+Alt+D toggles a 4 line overlay (text queue 0x4945a0 from esc_frame); STATE.LOG and SYNC.LOG get a net line.
- Sync check: 6 x 32-bit FNV subsystem hashes (players, units, orders, buildings, shots, rng; AI not hashed - host only) every 64
  ticks as three hidden '\x01CK' + part 0..2 + tick + 2 hashes; per exec tick history of the six (128 ticks, S lines). On mismatch:
  'Sync lost at tick N in <parts>' + hidden '\x01CKD' + tick: executes on every PC in the same turn, each writes 'DUMP tick ...' with
  canonical P/U/B/J lines, S history, rng/command log, unit/building hash history, raw records. tools/syncdiff.py A B prints the
  first differing tick/subsystem, first differing unit/building, field differences and the commands around it.

### a41 (Nov 1 2026) - second RNG stream desync
sha256 084e021f1884df9218911285dc3bbb1dd87bc8dd34bef92e3165ccf6d7b7b00a.
- a40 test (2 PCs): 'Sync lost in buildings'. syncdiff: first difference tick 282, building 1 (player 1, type 2, handler 0x458e10)
  timer +0x6c 160 vs 168. 0x458e10 sets it from Rand_Mask2 0x40ca60(0x1f)<<3 (and 0x40ca60(0x7f)+0xe6): the SECOND RNG stream
  (index 0x9d49c0, table 0x4afbfc+4). That stream is also used by the order voice 0x464355/0x464368 (only the clicking PC), draw
  functions 0x42f570/0x42fac0/0x42fda0 and Detail (0x5474a0, per PC Siege.ini; set 0x40e0a9.., 0x450e4a/0x450ea5) dependent debris
  0x429d10 and branches in 0x42a140, 0x42b11c, 0x42b7a7, 0x42cea7, 0x42d1c6, 0x42d647. All direct users of 0x9d49c0 listed by
  address in this entry's source comment (ui/mpmenu.c rng2_align).
- Fix (MP, ruleset 1): exec_cmds start (= start of each tick, one frame per tick) sets 0x9d49c0 = (tick*2654435761 >> 22) & 0x3ff on
  every PC; Detail held at 3 during MP games (det_restore after: score_after_game, mp_back_to_lobby, sync_reset).
- syncdiff.py: the dump also has the older short U/B lines further down; the first (canonical) line now wins.
- Seen in the a40 logs: 'R' resend requests 562/1307 and received 1199/562 in 338 ticks; wait max 387/924 ms. Next to look at.

### a42 (Nov 1 2026) - false building alarm, command record tails, resend log
sha256 e44dfd3a4994b5f0aadda1b00cd6b56f6028a4266d0c252496ec391da00b1c18.
- a41 test: 'Sync lost in buildings' at tick 1445: building 3 (owner 1, type 9, just placed by command kind 1 at 1444) +0x98 = 4 on
  the placing PC, 0 on the other. +0x98 has only 3 references: CreateBuilding sets 4 (0x422cbc), the minimap drawing routine reads
  and counts it down (0x41eb4b / 0x41ec61, gated by word 0x668cce). Not sim state: removed from the buildings hash (dump: 'radar').
  Everything else was equal: the a41 second RNG fix held for 1490 ticks.
- Same logs: the kind 1 record differed in bytes 11..19 between the PCs: a command packet carries only 0x9e37c0[kind] data bytes
  (kind 1 = 10) and the receiver keeps whatever its packet buffer 0x9e77b0 held after that. Executors read inside their length, so
  harmless, but now post_cmd zeroes the tail on the sender and pump_recv clears 0x30 bytes of the buffer before every receive.
- Resend storm: 'R' asked 591 / 9358, received 9247 / 584 in 1490 ticks (B asks A ~6 times per tick). Each request is now logged
  (rl type 4 asked: frame idx to; 5 was asked: frame idx from; plus send frame 0x67fd94 and exec slot 0x83a3f6) and printed in the
  SYNC.LOG dump as 'N' lines.

### a43 (Nov 1 2026) - click voice and drawing off the second RNG stream
sha256 8eb9553e05c7316438801fa6c9c3cf36261a7c31b5c1e808530c4131cb01a0c8.
- a42 test: 'Sync lost in shots'. S history: shots differ 3441..3461, units only at 3445 (unit 1 hash, one tick), then equal; final
  dump equal apart from 'radar'. Player 1's order (k6, executed 3443) was clicked at ~3441. Game loop after ExecTurnCommands
  (0x417dbb): 0x41d750, 0x41ea90, 0x41e0e0 (UI), 0x457bf0 buildings, 0x451b00 units, 0x45b430 shots (twice, dt), 0x426410,
  0x42de70, 0x4303f0 (draw), ..., 0x447d80 AI, 0x4368a0. The order voice (0x464355/0x464368, Rand_Mask2) runs in the UI part on
  the clicking PC only, i.e. AFTER the a41 re-align and BEFORE the shot updates of the same tick.
- Fix: voice calls redirected to rand2_local (private index, same table); calls 0x418927 / 0x418962 / 0x41899d (draw) wrapped in a
  save/restore of 0x9d49c0 (ruleset 1, MP). Battle Rage (user's guess) was not involved.
- Note: the received k6 records still show bytes past the 12 sent (000049ff): they do not come from the sender's packet buffer
  (zeroed since a42) nor from 0x9e77b0 (cleared before NetRecv); the UDP layer must copy a longer stale block. Executors do not
  read them.

### a44 (Nov 1 2026) - a43 + end of turn marker log
sha256 7d67f207018c25ca5b813d7dbf1e3056011611036079fbbd59fc6befe8acf028. a43 was built but replaced before testing.
- a42 log N lines: PC 2 asks PC 1 for 'frame f idx 0' right when its exec slot reaches f (f = 64, 66, 74, 76, 79, 84, 86, 91, 106,
  113, 127, 5, 9, 11 x17 ...), but PC 1 executed no command of its own in most of those frames (its C log: slots 65, 67, 73, 90,
  115, 122). So PC 2 believes those frames hold a command from PC 1: either the end marker count (packet [6]) is wrong, or a
  marker from another frame or a resend is taken for this one. Overall rate this game ~0.5 per tick (a41 game ~6 per tick).
- New log: rl type 6 'end sent' (frame [2], count [6], to; redirects of NetSend at 0x401c91 and 0x401800 -> net_send_end) and
  type 7 'end got' (only count > 0, from pump_recv). SYNC.LOG N lines.

### a45 (Nov 1 2026) - AI on its first frame; what the resend requests really are
sha256 cd8bc720e8d3cddb860a40c80f5711903100babcd3e84c9e8a7d4abb0a3e11ae.
- a44 test: 'Sync lost in buildings' from tick 1: AI players' HQs 320/480/640 timer +0x6c = 0 on the host, -2 on the joiner
  (+0x70 total 1 on both, so not CreateBuilding's /4 card bonus path 0x422b9f/0x422be7). [O] LoadMission 0x403350 sets the queue
  flag 0x71667c = 0 at 0x40335b; the loop in 0x40f2d0 calls the AI driver (0x416a40, host only, RNG saved/restored) before its first
  ExecTurnCommands (0x417d86 flag 0, 0x417dc5 flag 1), so in that first frame the AI changed its buildings directly on the host.
  Fix: ai_call_w (sim/netcmd.c) redirects 0x416a40 and 0x41909f: in MP the AI always runs with 0x71667c=1.
- Side facts found while looking: CreateBuilding sets timer/total from 0x4bb7c8[type] and divides by 4 while 0x7533e0[p] (AI
  cheat timer = Missions.ini AICheatCount*60, zeroed in MP at 0x4039db) or 0x9d5a70[p] (card bonus, +1000 at 0x44286a) is > 0;
  both count down by the frame delta in the panel code 0x41a472.. (local player sees a countdown).
- Resend 'storm' explained: the turn wait 0x401d30 itself sets 0xa239dc/d4/d8 = (exec frame, idx 0, missing player) every 0x41
  passes (0x401eb4..) and the pump sends it as 'R'; the answer is the end marker. So the counts measure waiting. a44 logs: 1254 at
  tick 0 (joiner waiting for the host to load), then a few per waited turn. The real lag question is why the joiner waits for the
  host (wait max 924 ms on the joiner vs 386 ms on the host).

### a46 (Nov 1 2026) - building field change log
sha256 89bff05e02c0e2e64e77af18b2dc373c0f08a2cd2a34f4f4b29b9b3c45109883.
- a45 test: score screens equal on both PCs (first time). 'Sync lost in buildings' at check 3328: only building 641 (AI player 5)
  differed, from 3243; its hash went through the same values on both PCs but at different ticks (steps at irregular times
  3219..3343, i.e. hits while under construction / being attacked by player 1; shots differed briefly 3303-3306 and 3312-3316),
  finished ('a1cb') at 3327 on the joiner and 3333 on the host (players hash differed exactly then) and was destroyed at 3343 on
  both. Cause not found from the code: frame delta 0x6df0f8 is a per-game constant (0x40f9cb, 0x416ffc, 0x4171fc).
- New: per exec tick every word of every building is compared with the previous tick; changes go to a ring (tick, building,
  offset, value; +0x98 skipped) and the dump prints the last 256 ticks as 'W' lines; syncdiff.py section 5 prints the first
  differing change per building field. Command/event log window in the dump widened from 64 to 256 ticks.

### a47 (Nov 1 2026) - local pause skipped a simulation step
sha256 14f12c9072ee677d7d37752694db0c2ade7c0d43105e471d3ebad130387df533.
- a46 test: 'Sync lost in units' (check 1216). syncdiff: units 0, 3, 4 differ from 1164; W log: every building's animation words
  (+0x2c, +0x30, +0x44) change one tick later on the host from 1164 on (= host ran one update less). [O] game loop 0x41866f:
  'cmp word [0x7ffe50],0; jne 0x4188ac' skips 0x457bf0 / 0x451b00 / 0x45b430 while the local pause flag is set: Esc sets it
  (0x41c224, needs 0x716632), menu close clears it (0x438b7a, 0x438bd2). The frame's commands and tick++ still run, so the PC that
  pressed Esc (or alt-tabbed: a8 opens the menu) lost one step. Speed word 0x507478: >0 update every N frames (countdown
  0x80315e), <=0 run 1-N updates; MP starts at 1 (0x4171e0, 0x41ccf0, command 0x445d8d); after the Esc menu 0x41c9de sets
  4 - 0x4afbe0 (local speed option) and Options 0x43fa9f sets it too.
- Fix (MP, ruleset 1): pause_skip_stub (jmp at 0x41866f, 13 bytes) ignores 0x7ffe50; rng2_align holds 0x507478 = 1 each tick;
  rng hash now includes frame delta 0x6df0f8 and 0x507478. The a45 drift of AI building 641 fits the same cause (not proven).
- syncdiff section 5 ignores building animation words (+1c +20 +2c +30 +34 +38 +3c +44).
- User report: 'some units of a group never move until selected alone'. a46 log 1103: a 13 unit move = 13 PostOrder + 10 SetUnitMode
  commands in one turn, all executed on both PCs, backlog max 0, nothing lost. So not the command queue. Candidates: path search
  (13 slots 0x6e75c0, unit gives up after 4 failed paths, +0xd0), or our po_check/sum filters suppressing a re-click with the same
  signature. Next: count path give-ups and filter suppressions per unit.

### a48 (Nov 1 2026) - per unit order / path trace
sha256 9a93e0a086f057ffe8dfb928ab6c9bf55c00473a3cb829977faca4ca7c04fa61. Includes a47 (not tested separately).
- sim/netcmd.c ut_ev / ut_dump: last 16 events per unit: P posted / p repeat filter (a37) / a auto-target skipped (a35) from
  po_check (rally.c, now a wrapper around po_check2), X kind 6 executed / M kind 13 executed (exec_cmds), S path started (goal
  tile) / W waiting for one of the 13 search slots (once per wait) / D path found (waypoints) / F failed / B aborted (path_new.c,
  self in g_self). Local only, no sim change.
- Ctrl+Alt+S: STATE.LOG ends with the selected units (or all own units if none selected): type, order state +0x62, mode +0x6e,
  path state +0xd4, retries +0xd0 (gives up when > 4, 0x456a2f -> +0x8e = 1), slot +0xd6, position, last order +0x78..+0x7c, then
  their events; plus how many of the 13 path search slots are busy.

### a49 (Nov 1 2026) - only 8 commands per player per turn were executed
sha256 3a73b4232b38d46f466d1bcffc4382ec111720fb9e0eb40e22dd27a3f6114ebe.
- a48 traces (both roles): host move of 6 units at 644: units 0-3 pathed (S/D), units 4-5 never did and their order fields
  stayed empty (+0x7a/+0x7c 0); joiner attack on building 268 with 8 units: 37, 40, 41, 42 attacked, 43-46 nothing. Always the
  first 4 units = 8 commands (PostOrder + SetUnitMode each). [O] ExecTurnCommands 0x445930 loops players 1..H, sub-order w
  0..7 (0x446136 'cmp eax,8; jl 0x44595e'), and for each w all records of the slot with that player and w. Records with w >= 8
  are never executed, on any PC. Our cap allows 30 per turn since a37 (16 since a28): every group order beyond 4 units lost
  orders, and a unit whose order was w7 and mode w8 moved but did not attack (user: 'move but do not attack').
  Fix: imm8 at 0x446138 = 0x20 (patch_exe.py byte patch). Note: the a48 X/M trace events come from the record list, so before
  a49 they also showed commands that were then skipped.
- Sync lost in buildings (check 2048): HQ 665 (player 6) took 60 instead of 40 from one hit at 2026 on the PC of the attacker
  (player 2); later hits equal. Flame/beam kinds 0x22, 0x23, 0x27 apply damage from their DRAW functions (0x42f570, 0x42fac0,
  0x42fda0 -> 0x42a140, with C rand 0x49c540), and 0x42de70 culls projectiles outside the local view (0x42dfb1..). Not fixed yet.
- Unit raw records differ by design in +0x65c..+0x67c (per viewer display words).

### a50 (Nov 1 2026) - flame / beam hits on every frame in multiplayer
sha256 3075c3d1a00aca3807fb9a97b6b9b59d14407dcc464678e5828753669ae2de67.
- a49 test: user: large group moves and attacks look perfect. 'Sync lost in buildings' (check 2176): building 532 hp 20 lower on
  the joiner from 2122; +0x74/+0x7c (last attacker unit) already differed at 2084 (0x29 vs 0x21); +0xb8/+0xbc written only on the
  joiner = label screen position (renderer 0x4320d6), display only (syncdiff ignores them now).
- [O] Flame/beam kinds 0x22/0x23/0x27 hit from their draw functions (slot +0xa0, from template +0x18; slot +0x98/+0x9c/+0xa0 copy
  the template's 3 function pointers, 0x433f61 on load) called by the list renderer 0x431040 (0x431102). The list (0x6729c0,
  count 0x77b4d8, filled by 0x430ab0 from 0x42de70 for every slot with +0x98 set) is sorted and rendered only when the game loop's
  draw argument is non zero (0x4189ab 'cmp ecx,esi; je 0x418b06') and the local pause flag 0x7ffe50 is clear (0x4188da). A PC
  that is behind skips drawing to catch up -> fewer flame/beam hits on that PC (here the host).
  The flame draw function's own camera check (0x42f753..) only stores/reloads the second RNG index and marks redraw maps
  0x668cf0/0x70e620 (renderer, 0x41dfaf), so it is not a sim difference.
- Fix (MP, ruleset 1): pause_render_stub (0x4188da, 13 bytes) and render_gate (0x4189ab, 8 bytes) never skip; on a frame the game
  wanted to skip, render_w (call 0x418aed) drops the items 0x431040 queued (draw list 0x4d7dd4 count +4 restored) and present_w
  (call 0x418afe) does not call 0x493840.

### a51 (Nov 1 2026) - flame randomness independent of draw order
sha256 dcf9f50d05bc60bf631191d820b40d9ab14344add14983ca21ad490ca67d46ff.
- a50 test: user: 'everything was running really nicely until a big fight'. syncdiff: shots differ from 2344 (four kind 0x22
  flame shots at slightly different x/y), units 8 and 10 hp later. [O] 0x42f570 takes second-RNG values per flame segment
  (0x42f5ba start, 0x42f80a each step) without any camera condition, so the values depend on how many were taken before it in
  the frame. 0x431040 calls the per-kind functions in draw list order; the list (0x6729c0) holds every projectile with +0x98 set
  plus the units added by the unit pass (camera dependent) and is sorted by world y/x with an unstable selection sort, so the
  flames' relative order (and the values each got) could differ between PCs. The two C rand calls in 0x42fda0 are dead results.
- Fix (MP, ruleset 1): call at 0x431102 -> proj_draw_w: 0x9d49c0 = ((tick*2654435761) ^ (slot*40503)) >> 20 & 0x3ff for that
  call, restored after; render_w also restores the index after the whole 0x431040 (unit draws).
- Remaining risk: the ORDER in which flames apply their hits is still the draw order (matters only when two hit the same target in
  one frame and one kills). If a desync shows that, run the three functions in slot order from the sim and skip them in drawing.

### a52 (Nov 1 2026) - queued CreateUnit slot reservation
sha256 ea758bc7757af77979787e0e84285c2c4cb37f6be41c7d7419521f105a35a2c0.
- a51 test: 'Sync lost in units' at 2026: units 8 and 14 swapped between the PCs (type 6 created at 2026, type 16 at 2048;
  positions/hp/dest swapped with them); everything else equal. No flame or draw involvement this time.
- [O] Free unit slot = owner 0 and stamp +8 == 0 (searches 0x421072, 0x424d86, 0x424e7d). Removal (0x421570) sets the stamp to
  0x803c48+10 (0x803c48 = 9, set once at game start 0x416847/0x41d013), the unit update 0x451c89 counts free slots' stamps down by
  1. In queue mode CreateUnit's posting branch (0x424de6: local owner, host for AI, or cx==1) searches the owner's range and
  stamps the slot immediately (0x424ecd) before posting kind 2 with it (record +0x1a -> 0x4b5650 at 0x445a37). Kind 2 with owner
  0x2707 only spawns effect 0x1b (0x445a3f..0x445a59, update 0x45da70 / draw 0x42f150, no unit). Here the host posted such a
  command at ~2015, reserving slot 8 on the host only; production (cu_direct, every PC) then used 14 on the host and 8 on the
  joiner.
- Fix (MP, ruleset 1): resv_mark (0x424ecd) writes g_resv[slot] = tick+64 instead of the shared stamp; resv_check (0x424e82)
  makes the queued search skip slots with a live reservation; k2_slot_stub (0x445a37) uses the first free slot of the owner's
  range if the command's slot was filled meanwhile (identical on every PC). Units hash includes stamps of free slots.

### a53 (Nov 1 2026) - projectile functions in slot order; Shift + number adds to a group
sha256 2e3eb00049457b7da62a1b33d065634f15d4cb27ce549afd68d13dd242d6922b.
- a52 test: 'Sync lost in shots' at 2707 in a big fight (kinds 15, 34, 43 at different positions, units from 2730). The a51 note
  came true: the per-kind projectile functions (slot +0xa0, flame/beam hits) still ran in the depth-sorted draw list order, which
  depends on the units each camera adds. Fix (MP, ruleset 1): render_w takes the set of slots that 0x42de70 would list (active,
  +0xac <= 0 (0x42deda), +0x98 set), sets the view clip like 0x431040 (0x493090), calls their functions in SLOT order (second RNG
  per (tick, slot) as in a51), then runs 0x431040 with proj_draw_w skipping them. Visual cost: projectiles are drawn under units.
- Shift + 1..0 (user request): group_key (rally.c, hook 0x462e2b) merges the current selection (own living units, no duplicates,
  max 40) into group g; the original code then selects the merged group. Shift state word 0x716632 (= L|R shift keys 0x71b434 /
  0x71b44c at 0x416b43; Ctrl 0x803154 at 0x416b56). Local UI only.
- Offline simulation tester (user idea, not built): no emulator here (no package index, no Wine). Workable plan: a test mode
  inside legion_enh.exe on the user's PC: Ctrl+Alt+M saves a full snapshot (writable sections + net/turn state) and the command
  log; 'legion_enh.exe -simtest' loads it, runs N ticks twice with different local player / camera / draw-skip / detail settings
  (no window, no network), writes per-tick subsystem hashes to SIMTEST.LOG; syncdiff-style tool reports the first divergence.
  Finds 'depends on who is looking' bugs without two PCs playing.

### a54 (Nov 1 2026) - display-only effects out of the simulation's projectile slots
sha256 97169044b3b6cb92837e75a937317cabe53de78bf503521b7e19f9f455408155.
- a53 test: Shift + number works (user). 'Sync lost in shots' at 3219 (check 3328): one AI (player 5) flame, kind 0x22, only on
  the joiner; unit 120 (player 5) position differed from 3266; rng, buildings, players equal. The user's own flame units were not
  in the fight.
- [O] 0x429de0 puts every new projectile into the FIRST free slot of the pool 0x71b600. Display-only effects are spawned into the
  same pool from local code: building smoke 0x41eab0 (game loop render part, C rand 0x49c540: 0x41eff0, 0x41f06c), unit smoke
  0x425820 called by the renderer for units on screen (0x4259b7), and the kind 0x1d draw function 0x42e130 (impact effect 0xb,
  only when the local option 0x4afbe4 is 0: 0x42e185). They are not in the shots hash, but every weapon projectile spawned after
  them gets a different slot on each PC, and since a51/a53 the slot picks the flame's second-RNG values and the order its hits
  apply. 0x429de0's other callers are simulation code.
- Fix (MP, ruleset 1): the four calls go to spawn_fx (netcmd.c), which takes the HIGHEST free slot of 0..204 (field setup copied
  from 0x429e49..0x429f62, 0x804310 raised). The simulation's first-free search only meets them when the pool is nearly full.

### a55 (Nov 2 2026) - per-tick shot list and unit order-field log in SYNC.LOG
sha256 1932a33b4e0fc2eb23c09d7fed155cddd1a753ee9e8bee3c0d1f689297ba157d. Includes a54 (tested: longer game, several big fights before the loss).
- a54 test: 'Sync lost in shots' at check 4864. syncdiff: only the shots hash differed, in three short stretches (4755-4760,
  4806-4832, 4845-4867), plus the orders hash at 4855-4866 (unit 65, AI player 3: order state / last order, H history). Units
  (position, hp), buildings, players and rng never differed, and the dump at 4882 had no field or shot difference: the
  difference comes and goes. The existing dump only lists shots at the dump tick, so the cause can't be seen.
- New (mpmenu.c shot_watch, called with unit_hist each exec tick): K lines = every weapon projectile per tick for the last 128
  ticks (slot, kind, owner, x, y, life +0x88, unit link +0x90); V lines = changes of unit words +0x00 +0x08 +0x0c +0x10 +0x40
  +0x44 +0x48 +0x60 +0x64 +0x6c +0x78..+0x88 +0xd4 for the last 256 ticks. syncdiff.py section 6 prints the first 4 ticks whose
  shot lists differ (entries only on A / only on B), section 7 the first differing change per unit field.

### a56 (Nov 2 2026) - weapon projectiles separated from effects in the slot pool
sha256 b502ee396ce5128370c7ff3165330411b95eee2a5b15d716f8ab0f4ffeab4f3a.
- a55 test: 'Sync lost in shots' (check 3648). The new K log: the shots were the same on both PCs (owner, kind 43, position, life,
  link) but in different slots: from 3551 slot 28 on one PC / 27 on the other, at 3554 slot 10 / 16. So the a54 move of four
  display spawn sites was not enough: other non-weapon items still sat in the low slots differently. [O] Of the 68 spawn calls,
  many are gated by local options (0x4af814, 0x4afbe4) or use C rand 0x49c540 (debris, sparks, smoke). Per kind, only
  2 0xf 0x12 0x14 0x1d 0x1f 0x21 0x22 0x23 0x26 0x27 0x28 0x29 0x2a 0x2b have update/draw functions that reach the hit code
  0x42a140 or damage 0x42bd90.
- Fix (MP, ruleset 1): all 68 call sites go to spawn_fx: those kinds keep the original first-free search from slot 0, every other
  kind takes the highest free slot (0..204, kind 0x1b 0..219). The weapon slots then depend only on the weapon shots, which are
  the same on every PC. Also the slot update call (0x45b462 jle -> upd_stub -> upd_w, replaces 0x45b563 'call [esi-0x10]') runs
  each item with its own second-RNG position per (tick, slot), restored after, so effect updates cannot shift the stream.

### a57 (Nov 2 2026) - HQ timer step was a per-PC clock value
sha256 03d876271c77eff908de9edd14870e271dc56f855cf93f1ed3d15f82b0c82e68. Includes a56 (its projectile change got no big-fight test yet: this game lost sync at the start).
- a56 test: 'Sync lost in buildings' at check 64. The AI HQs (266, 399, 532, 665) had timer +0x6c = 0 on the host and -2 on the
  joiner from tick 1; nothing else differed. [O] Building update 0x459480 (state +0x58 == 0): timer > 0 counts down by
  0x71b5f4 (0x4594b0); at <= 0 it marks a redraw and sets -182 (0x4594ee); a negative timer counts UP by 0x71b5f4 and stops at 0
  (0x459564..0x459578). 0x71b5f4 is set once when the game starts (0x417003) from 0x8564ec, the timer-interrupt counter (0x416f60,
  reset at 0x40eb58), so it depends on how long each PC took to get there; only the 0x9e2570 == 1 path sets it to 1 (0x417202).
  Here the joiner had 0 (timer stuck at -2, as in all earlier logs) and the host >= 2.
- Fix (MP, ruleset 1): rng2_align holds 0x71b5f4 = 1 every tick (before the commands and the building update); the rng hash
  includes it.

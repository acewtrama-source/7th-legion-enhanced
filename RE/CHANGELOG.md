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

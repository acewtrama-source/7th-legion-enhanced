# 7th Legion: Enhanced

Reverse-engineering and fix/enhancement project for **7th Legion** (1997 RTS, x86-32 Windows). The original `legion.exe` is never
modified; a patched copy, `legion_enh.exe`, adds fixes and features that are switched on by a single ini setting, so the classic game
stays one setting away. No game data files are changed.

> You need your own copy of the game. This repository contains no game files, only documentation, source and patch tooling.

## Features (with `ruleset=1`)

| Area | What changes |
|---|---|
| Pathfinding | New A* pathfinder: optimal paths, far fewer "can't find a path" failures. Verified against a bit-exact port of the original. |
| Orders | Re-issuing an identical move/attack after a unit has stopped short now works (the original silently dropped it). |
| Save / load | Unlimited save slots in pages of 10 with Prev/Next, plus a Delete button (Yes/No confirm) on each save. |
| Menus | "Multiplayer or Skirmish" on the main menu; Cancel on the campaign-selection screen; Esc returns to the main menu. |
| Skirmish lobby | Add or remove bots per row, choose each bot's faction, put every player on a team (No Team, Team 1, 2, 3). |
| Lobby options | HQ Deassemble (On), Tribute Enemies (Off), Cheat Codes (Off), next to the original options. Saved with save games. |
| Teams | Allies don't shoot each other automatically (friendly fire still possible by force attack), shared victory, shared vision, normal select cursor over allies, special orders only target enemies. |
| Fair unit cap | Every player gets an equal share of the 178-unit table, so bots can no longer starve your factories. |
| HQ | "RE ASSEMBLE HQ" turns your HQ back into a truck (health kept); a truck that can't deploy tries nearby spots and says "No room to deploy here."; a new HQ truck can be bought at the vehicle factory when you have none. |
| Tribute | Send 1000 credits to an ally (or any player, with Tribute Enemies on) from the HQ build list; icons show the receiver's colour. |
| Self destruct | Double tap **D**: 5 second countdown for the selected units (or a selected building); double tap again to cancel. |
| Build list | Any number of pages; Back returns to the previous page. |
| Cheats (lobby option) | `cheese steak khaos` (+10000 credits), `khaos car` (random ranked unit at your HQ), `khaos box` (crate), `show red credits` (any colour, private). |
| Cosmetic | Doom Fist II card gets the red attack-card border. |

With `ruleset=0` (default) everything behaves like the original game.

Player colours follow the player number: 1 Blue, 2 Red, 3 Green, 4 Yellow, 5 Black, 6 White.

## Install

1. Install the original game and make sure it runs.
2. Copy `legion_enh.exe` into the game folder next to `legion.exe`.
3. Open `Siege.ini` and add under `[options]`:
   ```
   ruleset=1
   ```
   Use `ruleset=0` (or remove the line) for classic behaviour.
4. Run `legion_enh.exe` instead of `legion.exe`.

Multiplayer: every player must use the same `legion_enh.exe` and the same ruleset (the simulation differs). Until the lobby checks
this, set it identically on all machines. Multiplayer across PCs with the new features is not tested yet (next phase).

## Building the patched exe

Requires a 32-bit gcc, ld, objcopy and Python 3.

```
sh tools/build_patch.sh /tmp/patch
python3 tools/patch_exe.py path/to/legion.exe /tmp/patch legion_enh.exe
python3 tools/check_hooks.py path/to/legion.exe legion_enh.exe
```

The patch is linked as a new `.patch` section at VA `0xADE000` and hooks the original code at a list of call sites and short
instruction ranges (catalogue: `RE/functions/patch-hooks.md`). `check_hooks.py` verifies that no original branch lands inside the
bytes a hook overwrote. Native tests (`tools/*test*.c`, the oracle in `tools/oracle32.c`) run the real game functions or mocks on Linux.

## Repository layout

- `RE/` reverse-engineering notes: function table (`index.md`), structs, globals, data formats, per-function write-ups, raw decompiler
  output, hook catalogue, change log. Start with `RE/START-HERE.md`.
- `RE/src/` patch code: `path/` (pathfinder + reference port), `sim/` (orders, teams, HQ, tribute, self destruct, cheats),
  `ui/` (save menus, campaign screen, menu text, lobby).
- `RE/tools/` patch builder, hook checker, test harnesses, benchmarks.

## Plan

1. **Recover and document** the engine (ongoing; the important subsystems are done).
2. **Fix the simulation and first enhancements**: done (Oct 2026). Open items carried forward: fire-on-move for plain Move,
   attack-move, the occasional "unit ignores orders" report.
3. **Dependable multiplayer** (next): 2-player LAN match, then 4 players, ruleset/version check in the lobby, sync checking,
   disconnect/reconnect.
4. **More enhancements**: extra units, balance, custom maps, better controls, an in-game choice of classic or enhanced ruleset.
   The classic ruleset is always kept.

## Status

Work in progress. Skirmish against bots is well tested on one machine; multiplayer across machines is not yet.
Back up your saves (`DATA/SAVE*.SAV`, and the `SAVE*.TMS` files next to them) before trying new builds.

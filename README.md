# 7th Legion: Enhanced

Reverse-engineering and fix/enhancement project for **7th Legion** (1997 RTS, x86-32 Windows). The original `legion.exe` is never modified; a patched copy, `legion_enh.exe`, adds fixes and features that are switched on by a single ini setting, so the classic game stays one setting away.

> You need your own copy of the game. This repository contains no game files, only documentation, source and patch tooling.

## Features (with `ruleset=1`)

| Area | What changes |
|---|---|
| Pathfinding | New A* pathfinder: optimal paths, far fewer "can't find a path" failures. Verified against a bit-exact port of the original. |
| Orders | Re-issuing an identical move/attack after a unit has stopped short now works (the original silently dropped it). |
| Save / load | Unlimited save slots in pages of 10 with Prev/Next, plus a Delete button (Yes/No confirm) on each save. |
| Menus | Cancel button on the campaign-selection screen; Esc now returns to the main menu instead of quitting the game. |
| Combat (experimental) | Fire-on-move for plain Move orders. Not working yet, see the plan. |

With `ruleset=0` (default) everything behaves like the original game.

## Install

1. Install the original game and make sure it runs.
2. Copy `legion_enh.exe` into the game folder next to `legion.exe`.
3. Open `Siege.ini` and add under `[options]`:
   ```
   ruleset=1
   ```
   Use `ruleset=0` (or remove the line) for classic behaviour.
4. Run `legion_enh.exe` instead of `legion.exe`.

Multiplayer: every player must use the same ruleset (the simulation differs). Until the lobby enforces this, set it identically on all machines.

## Building the patched exe

Requires a 32-bit gcc, ld, objcopy and Python 3.

```
sh tools/build_patch.sh /tmp/patch
python3 tools/patch_exe.py path/to/legion.exe /tmp/patch legion_enh.exe
```

The patch is linked as a new `.patch` section at VA `0xADE000` and hooks the original code at a handful of call sites. Native tests (`tools/*test*.c`, the oracle in `tools/oracle32.c`) run the real game functions or mocks on Linux.

## Repository layout

- `RE/` reverse-engineering notes: function table (`index.md`), structs, globals, data formats, per-function write-ups, raw decompiler output. Start with `RE/START-HERE.md`.
- `RE/src/` reimplemented and patch code (pathfinder, UI hooks, save menus, campaign screen, order fixes).
- `RE/tools/` patch builder, test harnesses, benchmarks.

## Plan

1. **Recover and document** the engine (ongoing, about 7% of functions read, the important subsystems done).
2. **Fix the simulation**: pathfinding done; order handling partly done. Open items: fire-on-move, units going rogue when moving through crowds, attack-move.
3. **Dependable multiplayer**: 2-player LAN match, then 4 players, sync checking, disconnect/reconnect. The menu becomes **Multiplayer / Skirmish**, with skirmish (human vs one or more AI bots) built into the same menu.
4. **Enhancements**: extra units, balance changes, custom maps, better controls, a start-of-game choice of classic or enhanced ruleset. The classic ruleset is always kept.

## Status

Work in progress and untested on many machines. Back up your saves (`DATA/SAVE*.SAV`) before trying new builds.

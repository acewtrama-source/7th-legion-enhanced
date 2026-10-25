# 7th Legion: Enhanced

Reverse-engineering and fix/enhancement project for **7th Legion** (1997 RTS, x86-32 Windows). The original `legion.exe` is never
modified; a patched copy, `legion_enh.exe`, adds fixes and features that are switched on by a single ini setting, so the classic game
stays one setting away. No game data files are changed.

> You need your own copy of the game. This repository contains no game files, only documentation, source and patch tooling.

## Features (with `ruleset=1`)

### Gameplay

| Area | What changes |
|---|---|
| Pathfinding | New A* pathfinder: optimal paths, far fewer "can't find a path" failures. Verified against a bit-exact port of the original. |
| Orders | Re-issuing an identical move/attack after a unit has stopped short now works (the original silently dropped it). |
| Teams | Allies don't shoot each other automatically (friendly fire still possible by force attack), shared victory, shared vision, normal select cursor over allies, special orders only target enemies. Team numbers (T1, T2, T3) are shown before the names in the player list under the minimap. |
| Fair unit cap | Every player gets an equal share of the 178-unit table, so bots can no longer starve your factories. |
| HQ | "RE ASSEMBLE HQ" turns your HQ back into a truck (health kept); a truck that can't deploy tries nearby spots and says "No room to deploy here."; a new HQ truck can be bought at the vehicle factory when you have none. |
| Tribute | Send 1000 credits to an ally (or any player, with Tribute Enemies on) from the HQ build list; icons show the receiver's colour. |
| Self destruct | Double tap **D**: 5 second countdown for the selected units (or a selected building); double tap again to cancel. |
| Sell buildings | Double tap **S** with one of your finished buildings selected: 5 second countdown, then the building is removed and you get half its cost back. Double tap again to cancel. Lobby option. |
| Build list | Any number of pages; Back returns to the previous page. |
| Cheats (lobby option) | `cheese steak khaos` (+10000 credits), `khaos car` (random ranked unit at your HQ), `khaos box` (crate), `khaos mission` (a special order now), `khaos card` (a free card if there is room), `show red credits` (any colour, private). |
| Score screen | After a game: points per player for kills, buildings and units made, research and tribute sent, with the title music (see below). |
| Cosmetic | Doom Fist II card gets the red attack-card border. |

### Menus and screens

| Area | What changes |
|---|---|
| Main menu | "Multiplayer or Skirmish"; Credits button (credits pages with the title music); version shown bottom right ("1.00 Enh a21"). Menu animations capped at 60 fps so they run at the right speed on high refresh monitors (`menufps`). |
| Options | "Edge Scroll On/Off": turn off camera scrolling when the mouse touches the screen edge (arrow keys still scroll). |
| Save / load | Unlimited save slots in pages of 10 with Prev/Next, plus a Delete button (Yes/No confirm) on each save. |
| Campaign screen | Cancel button; Esc returns to the main menu. |
| Multiplayer setup | Protocol list: Internet UDP first, then TCP/IP, then Skirmish (modem removed). Cancel on the protocol list goes back to Create/Join; Cancel on the address screen goes back to the protocol list. The address screen remembers the last address, shows the 5 most recent ones as buttons, and accepts the numpad. |
| Emergency exit | **Ctrl+Alt+End**, or hold **Alt+F4** for 2 seconds, closes the game even when it is stuck (no Task Manager needed). |

### Lobby (multiplayer and skirmish)

| Area | What changes |
|---|---|
| Players and map | Click an empty or bot row to move there (joiners too); the host clicks an empty row to add a bot. Every row has its colour bar, a faction choice (7th, Chosen or "??" = random) and a team (No Team, Team 1 to 3, or "??" = auto balance). |
| Team "??" | Players set to "??" join the smallest team in use; if nobody picked a team they are dealt into 1v1, 1v1v1, 2v2, 3v2, 3v3 or 2v2v2. |
| Options | Page 1: the original options plus HQ Deassemble, Tribute Enemies, Cheat Codes. "More..." opens page 2: Tech Lab On/Off (Off = nobody can build the Hi Tech Lab), Sell Buildings On/Off. Saved with save games. |
| Load saved game | The host can load a saved multiplayer game in the lobby. The save is sent to the joiners ("LOAD name WAIT.." until everyone has it, then "READY"); the save's options and teams are shown and locked. |
| Version check | Start stays disabled until everyone runs the same build ("VERSION MISMATCH name" / "WAITING FOR name"; joiners see "HOST VERSION DIFFERS"). |

### Multiplayer in game

| Area | What changes |
|---|---|
| Pause | Esc opens the menu and pauses the game for everyone; the others see "Game paused by name". Alt-tab pauses the same way and opens the menu when you come back. |
| Save | Save Game in the multiplayer menu (paged slots). Only the saving PC gets the file; that PC hosts the reload from the lobby. |
| Team chat | **T** opens the chat line as "Message To Team...": only your team sees it, marked T1/T2/T3. Enter still sends to everyone. Numpad digits work in the chat line. |
| Dropped players | A player (not the host) who goes silent for 40 seconds is taken over by a bot on the host and the game goes on. A player who quits is removed and their army destroyed (original behaviour). |
| Sync check | Every few seconds the PCs compare a checksum of the game; on the first difference everyone sees "Sync lost at tick N with name" and `data\SYNC.LOG` is written (send it with a bug report). |
| Colours | Player colours follow the lobby row (Blue, Red, Green, Yellow, Black, White) on units, buildings, the minimap list and messages. |

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

Optional settings under `[options]` (the game writes some of them itself):
```
menufps=60
edgescroll=1
lastip=192.168.1.18
```
- `menufps`: frame rate of the menus (default 60; `0` = uncapped like the original, which runs the menu animations too fast on
  120 to 240 Hz screens).
- `edgescroll`: 1 = the camera scrolls when the mouse touches the screen edge (default), 0 = off. Also in Options.
- `lastip`, `lastip1`..`lastip5`: the remembered join addresses.

### Multiplayer on a LAN or over the internet

Every player must use the same `legion_enh.exe` with `ruleset=1`; the lobby refuses to start otherwise.

Windows Firewall blocks the game's network traffic by default (the PCs can still ping each other, which makes this confusing). On
**every** PC, open a Command Prompt **as administrator**, change to the game folder and run:

```
cd /d "C:\path\to\7th Legion"
netsh advfirewall firewall add rule name="7th Legion" dir=in action=allow program="%CD%\legion.exe" profile=any
netsh advfirewall firewall add rule name="7th Legion enh" dir=in action=allow program="%CD%\legion_enh.exe" profile=any
netsh advfirewall firewall add rule name="DirectPlay helper" dir=in action=allow program="%windir%\SysWOW64\dplaysvr.exe" profile=any
netsh advfirewall firewall add rule name="DirectPlay ports TCP" dir=in action=allow protocol=TCP localport=47624,2300-2400 profile=any
netsh advfirewall firewall add rule name="DirectPlay ports UDP" dir=in action=allow protocol=UDP localport=2300-2400 profile=any
netsh advfirewall firewall add rule name="7th Legion Internet UDP port" dir=in action=allow protocol=UDP localport=25666 profile=any
netsh advfirewall firewall add rule name="7th Legion Internet TCP port" dir=in action=allow protocol=TCP localport=25666 profile=any
```

The game's own Internet UDP mode uses port 25666 (UDP and TCP). The two port rules cover every copy of the exe, whatever it
is called, and every network type, including VPN adapters such as Hamachi or Radmin, which Windows usually treats as Public.

(On 32-bit Windows use `%windir%\System32\dplaysvr.exe`.) To remove them later:
`netsh advfirewall firewall delete rule name="7th Legion"` and the same for the other names.

Then use **Internet UDP** (works on a LAN too): the host picks Multiplayer or Skirmish, Create Game, Internet UDP; the others pick
Join Game, Internet UDP and type the host's IPv4 address (`ipconfig` on the host, for example 192.168.1.18). Playing over the
internet works through a VPN such as LogMeIn Hamachi: use the host's Hamachi address (25.x.x.x). The DirectPlay **TCP/IP** option
does not find games on current Windows in our tests. VPN adapters can make the game pick the wrong address on a plain LAN; disable
them there, or use their addresses on purpose to play through the VPN.

Tested: 2 players over LAN and Hamachi, with bots, teams, pause, save and lobby load. 3 or more people not tested yet.

## Building the patched exe

Requires a 32-bit gcc, ld, objcopy and Python 3.

```
sh tools/build_patch.sh /tmp/patch
python3 tools/patch_exe.py path/to/legion.exe /tmp/patch legion_enh.exe
python3 tools/check_hooks.py path/to/legion.exe legion_enh.exe
```

The patch is linked as a new `.patch` section at VA `0xADE000` and hooks the original code at a list of call sites and short
instruction ranges (catalogue: `RE/functions/patch-hooks.md`). `check_hooks.py` verifies that no original branch lands inside the
bytes a hook overwrote. `patch_exe.py` stamps a build id (first 4 bytes of the SHA-256 of the patch) that the lobby version check
compares, and prints it. Builds are reproducible. Native tests (`tools/*test*.c`, the oracle in `tools/oracle32.c`) run the real game
functions or mocks on Linux.

## Repository layout

- `RE/` reverse-engineering notes: function table (`index.md`), structs, globals, data formats, per-function write-ups, raw decompiler
  output, hook catalogue, change log (`CHANGELOG.md`), multiplayer plan (`PHASE3.md`). Start with `RE/START-HERE.md`.
- `RE/src/` patch code: `path/` (pathfinder + reference port), `sim/` (orders, teams, HQ, tribute, self destruct, sell, cheats,
  score), `ui/` (save menus, campaign screen, menu text, lobby and slots, multiplayer menu/pause/sync/drop, network screens, menu
  frame cap, credits).
- `RE/tools/` patch builder, hook checker, test harnesses, benchmarks.

## Plan

1. **Recover and document** the engine (ongoing; the important subsystems are done).
2. **Fix the simulation and first enhancements**: done (Oct 2026). Open items carried forward: fire-on-move for plain Move,
   attack-move, the occasional "unit ignores orders" report.
3. **Dependable multiplayer** (current): 2 players over Internet UDP work with bots, teams, pause, save/load, version and sync
   checks, dropped player to bot. Still open: a 3+ player test, recovering lost orders when the order queue is full, choosing seats
   when loading a saved game, a quitting player handed to a bot.
4. **More enhancements**: higher resolutions (HD/4K), extra units, balance, custom maps, better controls, an in-game choice of
   classic or enhanced ruleset. The classic ruleset is always kept.

## Status

Work in progress. Skirmish against bots is well tested; 2-player multiplayer over LAN and Hamachi is tested.
Back up your saves (`DATA/SAVE*.SAV`, and the `SAVE*.TMS` files next to them) before trying new builds.

# Test tooling (pathfinding foundation)
- `tools/mapdec.py DATADIR NNN` decode MAPL/MAPT (formats in data-formats.md); prints class grid.
- `tools/oracle32.c` native 32-bit harness: loads legion.exe sections at their VAs and CALLS the real 0x439a00 (no emulator). Needs `gcc -m32 -nostdlib` (works in the cloud container; Linux x86-64 runs 32-bit ELF).
- `src/path/path_ref.c` bit-exact C port of PathStep over a flat memory image; also the scenario runner.
- `tools/mkscen.py DATADIR EXE OUTDIR COUNT [SEED]` random scenarios from real maps (units, occupancy, buildings, mines, flee influence, slot pressure).
- `tools/run_path_diff.sh EXE SCENDIR` oracle vs ref; prints ok/bad. Last run: 3000/3000 identical.
Reuse the oracle trick for any pure function (no imports/calls): map exe, overlay state, call, hash memory. Staging map files: device_stage_files from `Install files\DATA\MAPL.NNN`+`MAPT.NNN` into /mnt/user-data/uploads/Install files/DATA/.

## Enhanced pathfinder (ruleset 1) — build/test/ship
- `src/path/path_new.c` enhanced A* (+ `path_dispatch`). `tools/build_patch.sh [OUT]` -> OUT/patch.bin + meta.txt (VA 0xAE0000, ~3.6 KB code, 3.6 MB bss).
- `tools/bench_path.py EXE SCENDIR PATCHDIR` runs classic vs enhanced on the real code (oracle32 with patch overlay), validates legality, proves optimality vs Dijkstra, prints success/length/CPU. Needs /tmp/oracle32 built (see run_path_diff.sh).
- `tools/patch_exe.py legion.exe PATCHDIR legion_enh.exe` adds section `.patch`, redirects the one call at 0x438fcf (PathStart -> 0x439a00) to `path_dispatch`. Original exe untouched. Ruleset read once from Siege.ini `[options] ruleset=0|1` (default 0 = classic = byte-identical behaviour).
- Results (700 scenarios, real maps): enhanced finds path 564 vs 485 classic; 0 cases classic-ok/enhanced-fail; same-goal path cost mean x0.935 (up to -48%); 183/183 optimal; half the calls; ~0.37x CPU.
- NOT yet validated in the live game (needs Windows run): cannot execute the PE here. Classic mode path is the unchanged original.

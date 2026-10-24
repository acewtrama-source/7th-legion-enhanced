#!/bin/sh
# Builds the enhanced-pathfinder patch blob (loaded at VA 0xADE000) + meta (addresses). Needs gcc -m32 (no libc).
T=$(cd $(dirname "$0")/.. && pwd); O=${1:-/tmp/patch}; mkdir -p $O
CF="-m32 -ffreestanding -fno-pic -fno-stack-protector -fno-asynchronous-unwind-tables -fno-builtin -O2"
gcc $CF -c $T/src/path/path_new.c -o $O/p.o || exit 1
gcc $CF -c $T/src/ui/ui_hooks.c -o $O/u.o || exit 1
gcc $CF -c $T/src/ui/saves.c -o $O/s.o || exit 1
gcc $CF -c $T/src/sim/orders.c -o $O/o.o || exit 1
gcc $CF -c $T/src/ui/campaign.c -o $O/c.o || exit 1
gcc $CF -c $T/src/ui/text.c -o $O/t.o || exit 1
gcc $CF -c $T/src/ui/lobby.c -o $O/l.o || exit 1
gcc $CF -c $T/src/sim/teams.c -o $O/tm.o || exit 1
gcc $CF -c $T/src/sim/cheats.c -o $O/ch.o || exit 1
ld -m elf_i386 -nostdlib -z noseparate-code -z norelro --build-id=none -Ttext=0xade000 -e path_dispatch -o $O/p.elf $O/p.o $O/u.o $O/s.o $O/o.o $O/c.o $O/t.o $O/l.o $O/tm.o $O/ch.o || exit 1
objcopy -O binary $O/p.elf $O/patch.bin
nm $O/p.elf | awk '/ path_dispatch$| g_ruleset$| g_inited$| _end$| hook_style$| load_menu_dispatch$| save_menu_dispatch$| post_dedupe_stub$| mode_stub$| camp_btn$| camp_poll_stub$| camp_esc_stub$| text_load_hook$| lobby_row_stub$| lobby_start_stub$| lobby_opts_btn$| load_menu_main$| tm_h[0-9]+$| load_game_hook$| cheat_stub$| hq_list_stub$| hq_hover2_stub$| hq_click_stub$| deploy_try$/{print $3, $1}' > $O/meta.txt
cat $O/meta.txt; ls -l $O/patch.bin

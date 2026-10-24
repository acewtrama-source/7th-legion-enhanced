#!/bin/sh
# usage: run_path_diff.sh LEGION_EXE SCENDIR  -> diffs real code (oracle32) vs C reference per scenario
EXE="$1"; D="$2"; T=$(dirname "$0")/..
[ -x /tmp/oracle32 ] || gcc -m32 -nostdlib -ffreestanding -static -fno-pic -no-pie -O1 -fno-tree-loop-distribute-patterns -fno-stack-protector -o /tmp/oracle32 $T/tools/oracle32.c
[ -x /tmp/path_ref ] || gcc -O2 -o /tmp/path_ref $T/src/path/path_ref.c
ok=0; bad=0
for s in $D/sc*.bin; do
  /tmp/oracle32 "$EXE" $s > /tmp/o.txt 2>/dev/null; /tmp/path_ref $s > /tmp/r.txt 2>&1
  if cmp -s /tmp/o.txt /tmp/r.txt; then ok=$((ok+1)); else bad=$((bad+1)); echo "MISMATCH $s"; fi
done
echo "ok=$ok bad=$bad"

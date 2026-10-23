---
addr: 0x40e1d0 / 0x40e340
name: Load menu / Save menu (slot pickers)
status: decompiled [O]
rev: 1
---
0x40e1d0 LoadMenu (callers 0x40d910 main menu @0x40dc2b, 0x43f7f0 in-game @0x43fb1b); 0x40e340 SaveMenu (caller 0x43f7f0 @0x43fafd).
Both: begin 0x4752b0+0x475700; for i<11 (only 10 shown) text buf[i*0x28] = "..Empty.." (fmt 0x4b69a4 / 0x864410) then first 0x14 bytes of "data\save%d.sav" if it exists; buttons 0x4758b0(id,type,x,y,w,h,text): load type 0 x=-1 w=200 h=0x10 ids 0..9 at y=0xa0+0x1b*i; save type 5 (EDIT FIELD) x=0x4b w=0x1ea h=0x16; Back id 600 (text 0x8644b0) y=0x1c2. Poll 0x476aa0 (==1 click, id [0x59f890], hover [0x5927a4]; load plays 0x476160(900) on hover). End 0x4757c0.
Result: load -> word [0x835034] = slot (only if the file exists; -1 = none) consumed by loader 0x433a60(slot) at 0x40f4b2/0x40ff65/0x416941/0x416ce9/0x41cf21; save -> SaveGame 0x4321f0(slot, 0x475fc0(id) edited text) (writes data//save.tmp then data//SAVE%d.SAV).
Slot number is ONLY used in sprintf("data//SAVE%d.SAV") (0x432203,0x433ac7,0x435521) => any int works. 0x435510 (preview reader) has no callers.
Menu toolkit: 50 button slots (0x592bb0 stride 0x3c0), text strncpy'd 0xff and UPPERCASED IN PLACE (unless starts with [ ] \), '|' splits lines.
ENHANCED: src/ui/saves.c replaces both (call sites redirected; ruleset=0 -> originals). Pages of 10, buttons 601 "<< PAGE n" / 602 "PAGE n >>", save gets a new page once the last page is full. Tests: tools/saves_test*.c (mocked toolkit, native).

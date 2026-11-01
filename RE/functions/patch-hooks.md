# legion_enh.exe hook catalogue (end of Phase 2, Oct 24 2026)

Every place where `tools/patch_exe.py` changes the original code. All new code lives in section `.patch` at VA 0xADE000 (built by
`tools/build_patch.sh` from `src/**/*.c`). Every stub checks `g_ruleset` (u8, Siege.ini `[options] ruleset=1`); with ruleset=0 it
runs the original instructions, so classic behaviour is unchanged.

Kinds: **call** = the rel32 of an existing `call` is redirected (helper `redirect(site, old, new)`); **jmp** = the bytes at the site are
replaced by `jmp stub` + NOPs and the stub re-executes them (helper `jmp_over(site, orig_hex, stub)`); **imm** = one immediate byte edited.
After every build: `python3 tools/check_hooks.py legion.exe legion_enh.exe` (71 ranges, 0 branch targets inside, at exe sha256 d407266e...).

| site | kind | original | stub (file) | feature |
|---|---|---|---|---|
| 0x438fcf | call | 0x439a00 PathStep | path_dispatch (path/path_new.c) | A* pathfinder |
| 0x42383f | jmp | cmp si,[edi+0x67fe88] | post_dedupe_stub (sim/orders.c) | Fix A: re-issued identical order after idle |
| 0x44f471 | jmp | mov ax,[esi+0x67fe7e] | mode_stub (sim/orders.c) | Fix B: fire-on-move (NOT working in-game) |
| 0x40dc2b, 0x43fb1b | call | 0x40e1d0 load menu | load_menu_dispatch / load_menu_main (ui/saves.c, sim/teams.c) | paged load menu; main-menu Load clears teams |
| 0x43fafd | call | 0x40e340 save menu | save_menu_dispatch (ui/saves.c) | paged save menu + delete |
| 0x40d48a / 0x40d49c / 0x40d560 | call/call/jmp | button create / poll / esc | camp_btn / camp_poll_stub / camp_esc_stub (ui/campaign.c) | campaign screen Cancel |
| 0x40db87, 0x4510b0 | call | 0x450cb0 LoadLanguageText | text_load_hook (ui/text.c) | 'Multiplayer or Skirmish' |
| 0x440add | jmp | cmp [0x4aee00],si | lobby_row_stub (ui/lobby.c) | editable bot rows + bot faction |
| 0x441563 | jmp | xor si,si; mov [0x8574f8],ax | lobby_start_stub (ui/lobby.c) | pack AI rows, read teams + options |
| 0x440720 | call | 0x4758b0 BtnCreate ('Options...') | lobby_opts_btn (sim/teams.c) | team buttons 0x69..0x6e, options 0x6f..0x71 |
| 0x441203, 0x441513 | imm | cmp si,0x68 | 0x71 | host broadcasts option ids 100..0x71 |
| 0x4556a4 0x44f4f3 0x45a6ce 0x45a954 0x46898d 0x46ad47 0x46adb0 0x4686e3 0x44d6e0 0x41c4f4 0x41c554 | jmp | owner == owner compares | tm_h1..tm_h11 (sim/teams.c) | allies: targeting, AI lists, win check |
| 0x424caf | jmp | unit cap compare | tm_h12 (sim/teams.c) | fair unit cap 178/N |
| 0x45271e 0x452770 0x423031 0x42b56d | jmp | owner == viewer | tm_h13..tm_h16 (sim/teams.c) | shared vision |
| 0x4652a8 / 0x465347 | jmp | owner == local (hover cursor) | tm_cur_unit / tm_cur_bld (sim/teams.c) | select cursor over allies |
| 0x40f4b2 0x40ff65 0x416941 0x416ce9 0x41cf21 | call | 0x433a60 LoadGame | load_game_hook (sim/teams.c) | read SAVE<n>.TMS |
| 0x445fff | jmp | lea eax,[ecx+0x79fdf4] | cheat_stub (sim/cheats.c) | chat cheats + hidden lockstep commands |
| 0x465a5a | jmp | mov bp,[0x4c1fc8] | hq_list_stub | 'RE ASSEMBLE HQ' first on build page 1 |
| 0x4659f4 | jmp | cmp bx,8; jge | hq_count_stub | build-list page pre-count incl. our entries |
| 0x465b17 | jmp | mov eax,[esp+0x14]; test | hq_tail_stub | tribute entries after building types |
| 0x465b56 | jmp | cmp [0x4c1fc8],1; jle | hq_back_stub | back + more on middle pages |
| 0x465d01 | jmp | hover value check | hq_hover2_stub | entry tooltips 700..799 |
| 0x465dcf | jmp | click value check | hq_click_stub | entry clicks, page history |
| 0x45746b | call | 0x421d40 CreateBuilding (truck deploy) | deploy_stub -> deploy_try | deploy search + 'No room' + hp carry |
| 0x445a1d | call | 0x421d40 (queued kind 1) | hq_cmd_create | HQ hp carry in queue mode |
| 0x466030 | jmp | mov di,[0x7733b2] | truck_stub | HQ truck buyable at vehicle factory |
| 0x466315, 0x466dd9 | call | 0x4932f0 QueueSprite | icon_stub1 / icon_stub2 | HQ picture for the truck |
| 0x410b93 | call | 0x408480 RemapSprites (cards) | card_remap | Doom Fist II red border |
| 0x410d64, 0x410dd2 | call | 0x408480 (icon sheets) | icon_remap | player-coloured tribute icons |
| 0x416b49, 0x417c97 | jmp | mov ax,[R ctrl]; or ax,[L ctrl] | sd_stub / sd_stub2 | double-tap D self destruct (poll) |
| 0x41bebb | jmp | tick read before tick++ | trib_stub | tribute transfer per sim tick |
| 0x41ad45 | jmp | special-order target check | mission_stub | special orders never target allies |
| 0x476ae0 | call | 0x494060 present (in toolkit poll 0x476aa0) | menu_present (ui/framecap.c) | menu frame cap, Siege.ini menufps (default 60, 0 off); UI only |
| 0x40d9fb | call | 0x4758b0 BtnCreate ('Exit', id 4) | mm_exit_btn (ui/credits.c) | adds 'Credits' id 7 at y 0x11e, Exit moved to 0x141 |
| 0x40dc6d | jmp | cmp bx,6; jne 0x40dcc4 | mm_disp_stub (ui/credits.c) | id 7 runs credits_show (title.xm + credits01..04), back to menu top 0x40d938 |
| 0x41c9e5 | call | 0x43f7f0 in-game menu | ingame_menu_wrap (ui/mpmenu.c) | flag g_ingame_menu while the menu runs |
| 0x43f934 | jmp | cmp [0x803c40],di; jne 0x43f98c | mp_menu_stub (ui/mpmenu.c) | 'Save Game' in the MP in-game menu |
| 0x445123 | jmp | mov [ebp-8],0; mov [ebp-0x10],1; jmp 0x445613 | op_recv_stub (ui/mpmenu.c) | 'Game paused by <name>' while a peer is in the menu ('OP') |
| (0x476ae0 hook) | - | menu_present also calls mp_menu_keepalive | ui/framecap.c | keeps 'OP' flowing in MP sub menus |
| 0x440be7 | call | 0x476aa0 lobby poll | lobby_poll (ui/slots.c) | slot taking, row table, Load Saved Game button, Start gate |
| 0x4409d2, 0x440f52 | call | 0x475cd0 (gv apply) | gv_recv (ui/slots.c) | row table ids 0xa0..0xa5, take request 0xa6 |
| 0x440e63 | call | 0x40bf90 NetRecv (lobby) | lobby_recv (ui/slots.c) | '!L' saved-game transfer messages |
| 0x4516ea | call | 0x408110 (MP game over -> lobby) | mp_back_to_lobby (ui/credits.c) | music and click sounds back in the MP lobby |
| 0x4313d4 / 0x418c26 | jmp | push eax/edx; call 0x4930d0 (colour state) | col_stub1 / col_stub2 (ui/slots.c) | unit and panel colour follow the lobby row |

Hidden lockstep commands (chat command kind 0x65, never shown, executed by `cheat_chat` for the sender byte +0x21 on every peer):
`\x01HQnnn` pack HQ, `\x01SD`+(slot+1,type+1) pairs / `\x01SBnnn` self destruct, `\x01TRq` tribute to player q.

## Hooks added after the table above (a7..a39)
The table above stops at about a10. `tools/patch_exe.py` is the source of truth (every site with its original bytes); this list
says what each later site is for. File = where the stub lives.
| site(s) | kind | replaces | ours (file) | purpose |
|---|---|---|---|---|
| 0x40ca00, 0x40ca30 | jmp | RandMask / RandMod prologue | rng_mask / rng_mod (ui/mpmenu.c) | a26: game RNG caller log for SYNC.LOG |
| 0x401961 | jmp | mov [esp+0x18],3 | cmdcap_stub (sim/rally.c) | a28/a37: commands per turn 3 -> min(30, 60/humans) |
| 0x401e24 | jmp | turn wait timeout block | wait_stub (ui/mpmenu.c) | 'OP' keeps waiting; silent player -> bot after 60 s; fatal after 10 min; 'Waiting for <name>' (check_hooks reports this range, expected) |
| 0x447d92, 0x447e41 | jmp | AI driver player checks | ai_any_stub / ai_p_stub (ui/mpmenu.c) | host AI also drives dropped players |
| 0x417dbb | call | 0x445930 ExecTurnCommands | exec_cmds (ui/mpmenu.c) | a27+: SYNC.LOG commands/credits/hash history, ring stats, order filter reset, heap check |
| 0x45a183 | jmp | rally read in the production finish | rally_stub -> rally_pick (sim/rally.c) | a28/a32: lasting rally, allied buildings ignored |
| 0x42bd90 | jmp | damage entry | dmg_wrap (sim/rally.c) | a29/a30: damage applied on every PC in exec context (no kind 14 per hit) |
| 0x456ced | jmp | host check in heal | heal_stub (sim/rally.c) | a30: healing lockstep |
| 0x455086 0x45513c 0x455a88 0x455cef 0x456372 0x4566c8, 0x44fb8a | call+nops | host-only gates of the 0x29a position resyncs | gate_host / gate_host_eax (sim/rally.c) | a31: resync runs on every PC |
| 0x4550b8 0x45517a 0x455ab6 0x455d1d 0x4563a4 0x4566fa 0x44fbb4 | call | 0x423710 PostOrder | po_direct (sim/rally.c) | a31: those resync orders applied directly |
| 0x45a148 0x45a1c2 0x459831 | call | 0x424c20 CreateUnit | cu_direct (sim/rally.c) | a32/a39: produced unit created directly on every PC; a39 picks the unit slot into 0x4b5650 like the kind 2 handler |
| 0x423710 | jmp | PostOrder prologue | po_entry -> po_check (sim/rally.c) | a35/a37: owner side order dedupe while an order is in flight |
| 0x424300 | jmp | SetUnitMode prologue | sum_entry (sim/rally.c) | a37: mode repeat filter |
| 0x455614 0x4558e5 0x4559dd 0x455a06 | call | 0x424300 from auto-target | sum_auto (sim/rally.c) | a35: auto-target held back while a player order is pending |
| 0x462e2b | jmp | mov [0x67fdbc],-1 | group_stub (sim/rally.c) | a34: double tap group key centres the camera |
| 0x476dea | call | 0x493f20 present in toolkit poll | poll_present (ui/framecap.c) | lobby bars, menu_nav (a38 arrows + Enter) |
| 0x445e0b | - | (quit_stub exists in ui/mpmenu.c) | NOT INSTALLED | a15 quitter -> bot, reverted a17 (crash) |
| 0x444c00 | jmp | PostCommand prologue (7) | post_cmd (sim/netcmd.c) | a40: whole PostCommand; backlog of 512 in ruleset 1 |
| 0x401b66, 0x401bf2 | jmp | resend history writes (18, 7) | hist_w_stub / hist_z_stub (sim/netcmd.c) | a40: history 32 per frame in g_rhist |
| 0x40171b | jmp | 'R' resend read (31) | hist_r_stub (sim/netcmd.c) | a40: same history |
| 0x40189d | call | 0x40c170 NetSend of an 'R' request | net_send_r (sim/netcmd.c) | a40: counter |
| all 68 calls of 0x429de0 (list in patch_exe.py) | call | projectile/effect spawn | spawn_fx (sim/netcmd.c) | a54/a56: MP: damage kinds first free slot, others highest free |
| 0x45b462 | jle rel32 | per-slot update call 0x45b563 | upd_stub -> upd_w (sim/netcmd.c) | a56: own second-RNG position per (tick, slot) |
Other a11..a24 sites (chat, edge scroll, protocol list, score screen, version label, keys): see the commented lines in patch_exe.py.
Hidden commands since a28: `\x01RP` + building + tile = lasting rally point (sim/cheats.c -> rally_exec).

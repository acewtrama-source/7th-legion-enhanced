# Function index

Names in (parentheses) are unverified hypotheses. Sizes are bytes where known. `conf`: O observed, I inferred.

| addr | name | subsystem | status | conf | size | src | notes |
|---|---|---|---|---|---|---|---|
| 0x46b260 | AI_ReinforceGuardPoints | AI | decompiled | I | 874 | - | scores guard points, sends idle units; runs tick case 4. functions/0046b260.md |
| 0x46bec0 | AI_PlayerTick | AI | decompiled | I | 995 | - | per-player AI tick, 8-way time slice on tick&7. functions/0046bec0.md |
| 0x46b820 | AI_AddOrMergeGuardPoint | AI | understood | O | ~230 | - | add/merge guard point (5-tile merge). functions/0046b820.md |
| 0x46b6e0 | AI_AgeGuardPoints | AI | understood | O | ~280 | - | tick case 7; decrement life unless units nearby. functions/0046b6e0.md |
| 0x46b640 | AI_GuardPointAttack | AI | understood | O | ~120 | - | tick case 6; first state-2 unit with f28>f1c!=0 -> 0x469020(unit,2). functions/0046b640.md |
| 0x423710 | VehicleOrders | orders | decompiled | I | 2135 | - | (ent,cmd,a,target,x,y); cmd 1 move, 2 attack, 7 stop; dup filter, network queue, FindGoodDest. functions/00423710.md |
| 0x468920 | AI_GatherEnemyCandidates | AI | understood | O | ~420 | - | enemy list 0x665690 nearest-first. functions/00468920.md |
| 0x423250 | BuildingOrder | production | decompiled | I | ~1100 | - | produce/rally order; nub.dat logger. functions/00423250.md |
| 0x424460 | FindGoodDest | orders | understood | O | ~300 | - | nearest free tile toward the unit, max 30 steps. functions/00424460.md |
| 0x423f70 | VehicleOrdersInterrupt | orders | understood | I | ? | - | like 0x423710 but saves the current task; tick case 7 attacker response. functions/00423f70.md |
| 0x46c300 | AI_SetUnitState | AI/orders | understood | O | ~110 | - | sets u.state, maps state->order cmd, calls 0x423710; AI units only. functions/0046c300.md |
| 0x4687e0 | AI_SortOwnUnitsByDistance | AI | understood | O | 315 | - | array 0x666cc0 nearest-first. functions/004687e0.md |
| 0x469020 | AI_AssignAttackers | AI | decompiled | I | ~1500 | - | assigns own units to attack nearest candidates until strength sum > target. state 4. functions/00469020.md |
| 0x4697b0 | AI_BuildSortedUnitArray | AI | understood | O | ~330 | - | fills 0x4c2350. functions/004697b0.md |
| 0x469e80 | AI_ScoreBuildings | AI | decompiled | I | ~900 | - | tick 1: building desire scores 0x666c60. functions/00469e80.md |
| 0x46a5b0 | AI_ChooseBuilding | AI | understood | O | ~110 | - | tick 1: best allowed type -> 0x448390. functions/0046a5b0.md |
| 0x46bd80 | AI_IdleUnitsNearPickups | AI | decompiled | ? | ~300 | - | tick cases 1,6. functions/0046bd80.md |
| 0x4698f0 | AI_ProduceUnits | AI | decompiled | I | ~900 | - | tick case 2: pick unit type, queue production. functions/004698f0.md |
| 0x46af10 | AI_DefendBuildings | AI | decompiled | I | ~700 | - | tick 3: guard units -> state 5 around base buildings. functions/0046af10.md |
| 0x46ad10 | AI_PickAttackTargets | AI | decompiled | I | ~600 | - | tick 5: weakest enemy objects -> 0x46a690. functions/0046ad10.md |
| 0x44da70 | AI_PlayBattleCard | AI/events | decompiled | I | ~900 | - | voice/alert-like event (id+900). functions/0044da70.md |
| 0x447d80 | AI_TickDriver | engine/AI | decompiled | I | 607 | - | round-robin AI players, power recompute, calls 0x46bec0. functions/00447d80.md |
| 0x429cd0 | Dist | util | understood | O | ~60 | - | max+min/4 distance. functions/00429cd0.md |
| 0x46a690 | AI_LaunchAttack | AI | decompiled | I | ~1500 | - | gather idle units to beat target strength; state 1 attack. functions/0046a690.md |
| 0x448390 | AI_BuildStep | AI/production | decompiled | I | ~1000 | - | choose site, pay, CreateBuilding. functions/00448390.md |
| 0x46b610 | AI_ForceGroupAttack | AI | understood | O | ~30 | - | wrapper 0x469020(u,2)+log. functions/0046b610.md |
| 0x468300 | UnitPower | AI | understood | I | ~330 | - | functions/00468300.md |
| 0x468740 | AI_RefreshPlayerNodes | AI | understood | I | ~200 | - | functions/00468740.md |
| 0x468600 | AI_ScoreSurroundings | AI | understood | I | ~330 | - | functions/00468600.md |
| 0x448730 | AI_FindBuildSite | AI/production | decompiled | I | ~1500 | - | functions/00448730.md |
| 0x468220 | UnitClassRow | AI | understood | I | ~90 | - | functions/00468220.md |
| 0x44d960 | AI_PickEventDefault | AI/events | decompiled | I | ~230 | - | functions/0044d960.md |
| 0x44d440 | AI_PickEventByRatio | AI/events | decompiled | I | ~230 | - | functions/0044d440.md |
| 0x44d680 | AI_FindEventTarget | AI/events | decompiled | I | ~420 | - | functions/0044d680.md |
| 0x44d510 | AI_PickEventId | AI/events | decompiled | I | ~330 | - | functions/0044d510.md |
| 0x444c00 | PostCommand | net/queue | understood | I | ~110 | - | functions/00444c00.md |
| 0x41fff0 | DebugLog | util | understood | I | ~135 | - | functions/0041fff0.md |
| 0x448e00 | AI_PickStartPosition | AI | decompiled | I | ~900 | - | functions/00448e00.md |
| 0x40ca00 | Rand_Mask | util/rng | understood | I | ~15 | - | functions/0040ca00.md |
| 0x40ca30 | Rand_Mod | util/rng | understood | I | ~15 | - | functions/0040ca30.md |
| 0x40ca60 | Rand_Mask2 | util/rng | understood | I | ~20 | - | functions/0040ca60.md |
| 0x467bd0 | AI_AddNode | AI | understood | I | ~330 | - | functions/00467bd0.md |
| 0x41e900 | ReDrawArea | gfx/map | decompiled | I | ~350 | - | functions/0041e900.md |
| 0x429de0 | AllocProjectile | world | decompiled | I | ~600 | - | functions/00429de0.md |
| 0x46f640 | SfxPlay | audio | decompiled | I | ~60 | - | functions/0046f640.md |
| 0x49d4c0 | _strncpy | crt | understood | O | - | - | MSVC 6 (VS 1998) library function |
| 0x49c430 | _sprintf | crt | understood | O | - | - | MSVC 6 library function |
| 0x445930 | ExecuteCommands | engine/net | decompiled | I | ~3000 | - | functions/00445930.md |
| 0x424300 | SetUnitMode | orders | understood | I | ~120 | - | functions/00424300.md |
| 0x42ccc0 | DestroyBuilding | world | decompiled | I | ~1100 | - | functions/0042ccc0.md |
| 0x42d420 | DestroyUnit | world | decompiled | I | ~1300 | - | functions/0042d420.md |
| 0x42bd90 | ApplyDamage | combat | decompiled | I | ~2400 | - | functions/0042bd90.md |
| 0x441ec0 | ApplyBattleCard | combat | decompiled | I | ~5000 | raw/00441ec0.c | special powers 0..0x33; AI event ids 900+id land here. functions/00441ec0.md |
| 0x40f2d0 | GameSession_Main | engine | located | I | 31365 | raw/0040f2d0.asm | session init + main loop; AI driver call at 0x416a40 wrapped in RNG save/restore. functions/0040f2d0.md |
| 0x416fe0 | (GameStart/Frame) | engine | located | ? | ? | - | calls 0x447d80 and 0x424c20 |
| 0x41f090 | ? | engine | located | ? | ? | - | calls 0x424c20 |
| 0x4207a0 / 0x420240 / 0x416e20 / 0x4210c0 | ? | world | located | ? | ? | - | free/redraw helpers from destroy functions |
| 0x403350 | (LoadMissionAndAIScript) | loader | decompiled | I | 6635 | - | .ai + Missions.ini parsing understood; PAStart loop skimmed. functions/00403350.md |
| 0x421d40 | CreateBuilding | world | decompiled | I | ? | - | validate+place building, fill 0x805df0 record. functions/00421d40.md |
| 0x420180 | AllocBuildingSlot | world | decompiled | O | ~120 | - | free slot in building table. functions/00420180.md |
| 0x424c20 | CreateUnit | world | decompiled | I | ? | - | creates ENT record 0x67fe10; AI unit cap by Difficulty. functions/00424c20.md |
| 0x49c410 / 0x49c4e0 / 0x49c330 | fopen/fgets/fclose wrappers | crt | located | I | ? | - | |
| 0x402ae0 | (LoadMissionDifficulty) | loader | located | I | 2151 | - | Missions.ini, Difficulty |
| 0x402390 | (LoadBuildDat) | loader | located | I | 1863 | - | build.dat + bt_ |
| 0x404f30 | (LoadMissionsIni2) | loader | located | ? | 303 | - | Missions.ini |
| 0x41cd90 | (LoadMissionsIni3) | loader | located | ? | 2434 | - | Missions.ini |
| 0x4368a0 | (BuildingTypeTable) | loader | located | ? | 9066 | - | bt_ strings |
| 0x4714b0 | (LoadStuffDat) | loader | located | ? | 546 | - | stuff.dat |
| 0x4716e0 | (LoadStuffDat2) | loader | located | ? | 777 | - | stuff.dat |

## QUEUE (read in this order)
0. Done: 0x403350 (PAStart loop lines 860-977 skimmed), 0x421d40, 0x424c20, 0x420180, all AI tick slices, driver 0x447d80, 0x46a690, 0x448390. Done too: 0x41f090 UpdateBuildingPanel (UI), 0x416fe0 asm scanned (second AI-driver call site). Done: 0x441ec0 cases 6..0x30 (effect table in record). NOTE: 0x40f2d0 is mostly a session LOADER with progress bar (see record). DONE: helpers verified, 0x475120 LZSS decoder, RNG table dumped to data/rng_table.h. DONE 0x457bf0, 0x45b430, 0x45f3a0. NEW NEXT: decompile per-unit handlers from UnitTypeTable +0x3c: 0x452f30 (harvesters), 0x454d20, 0x456d60, 0x456d70, 0x456d80, 0x456e80, stubs 0x4574d0..; (handler ptr is set in CreateUnit 0x424c20 from the type table), building state handlers (b+0x94), 0x460680/0x461750/0x45fcb0/0x4626b0 panel modes, 0x41d750 (scroll), input 0x406000/406140/406280 = real unit sim core. (old note) verify helpers 0x4081a0/0x408480/0x494850/0x494060 by decompiling; find loader of card names 0x863150; RNG dump; split 0x40f2d0 (asm) into routines, identify 0x4081a0/0x408480/0x494850/0x494060 helpers, then writers of PLR+0x14 users, bit-exact plan.
1. DONE 0x447d80: sets 0x5bcd74 = 0x879cb0 round-robin 1..6.
2. 0x46c300: used by both tick loops, probably the core of unit behaviour.
3. DONE guard point lifecycle. Remaining question: what f18/f24 (life value) and f1c/f28 are computed from (probably 0x469020 / 0x4697b0).
4. DONE order functions.
5. Tick cases 0 to 3 and 5: 0x4697b0, 0x469020, 0x469e80, 0x46a5b0, 0x46bd80, 0x4698f0, 0x46af10, 0x46ad10.
6. Remaining helpers: 0x4687e0, 0x444c00, 0x44da70, 0x41fff0.
7. Later: the unit state value to string mapping (0x4c4484 ATTACKING ENTITY, 0x4c4498 GUARDING, 0x4c44ac PATROLLING, 0x4c44d4 GUARDING BASE; no direct xrefs found, likely indexed).

## Other leads
- Strings with order meaning: PT_BUILDINGORDERS 0x4ac108, PT_VEHICLEORDERS 0x4ac130, PT_VEHICLESUBORDERS 0x4ac158, VA_ATTACK 0x4af6f8, "In VehicleOrders - ..." 0x4b817c to 0x4b81f4, "Attack" 0x4bae88. Not traced yet.
- Coverage so far: ~60 of 1068 read or located; ~45 decompiled/understood.

| 0x41f090 | UpdateBuildingPanel | ui | understood | functions/0041f090.md |
| 0x416fe0 | GameFrame_Update (per-frame) | core | understood(stage map) | functions/00416fe0.md |

| 0x4081a0 | LoadFile | io | understood | functions/004081a0.md |
| 0x408480 | RemapSpritePalette | gfx | understood | functions/00408480.md |
| 0x494850 | DrawBar_thunk | gfx | located | functions/00494850.md |
| 0x494060 | LockScreenSurface? | gfx | understood | functions/00494060.md |

| 0x475120 | LzssDecompress | io | understood | functions/00475120.md |

| 0x45b430 | UpdateEffects | sim | understood | functions/0045b430.md |
| 0x45f3a0 | UpdateLocalPlayer | ui | understood(shape) | functions/0045f3a0.md |
| 0x457bf0 | UpdateBuildings | sim | understood | functions/00457bf0.md |
| 0x451b00 | UpdateVehicles | sim | understood | functions/00451b00.md |
| 0x4c0858 | UnitTypeTable (data) | data | located | functions/004c0858_UnitTypeTable.md |
| 0x456e80 | UnitHandler_Infantry | sim/unit | decompiled | functions/00456e80.md |
| 0x454d20 | UnitCore_OrderStateMachine | sim/unit | decompiled | functions/00454d20.md |
| 0x452f30 | UnitHandler_Harvester | sim/unit | decompiled | functions/00452f30.md |
| 0x423710 | PostOrder | sim/orders | decompiled | functions/00423710.md |
| 0x454690 | UnitPreStep_CloakCrush | sim/unit | decompiled | functions/00454690.md |
| 0x44e8d0 | UnitMoveAlongPath | sim/movement | decompiled | functions/0044e8d0.md |
| 0x458a10-0x45b0c0 | BuildingStateHandlers | sim/buildings | decompiled(9/13) | functions/building_handlers.md |
| 0x421d40 | CreateBuilding | sim/buildings | read | functions/00421d40.md |
| (in 0x416fe0 @0x417325) | BudgetPayout | economy | located | manual-map.md |
| 0x423f70 | PostQueuedOrder | sim/orders | decompiled | functions/00423f70.md |
| 0x45a3f0/0x45a520/0x45b0c0 | silo/turret/shield handlers | sim/buildings | decompiled | functions/building_handlers.md |
| UnitTypeTable costs | types 0/1 + cost map | data | read | functions/unit_types_0_1.md |
| 0x42bd90 | DealDamage (subtract+rewards) | sim/combat | decompiled | functions/0042bd90.md |
| 0x43efb0 | UnitAimFire | sim/combat | decompiled | functions/0043efb0.md |
| 0x43e280 | SpawnShot | sim/combat | decompiled | functions/0043e280.md |
| 0x438fb0 | PathStart wrapper (state[2]=1 -> 0x439a00) | sim/path | decompiled | functions/00439a00.md |
| 0x463550 | UI_MapCommand + move-style menu (read) | ui | read | functions/00463550.md |
| 0x439a00 | PathStep (greedy best-first) | sim/path | verified (bit-exact, src/path/path_ref.c) | functions/00439a00.md |
| 0x42a140 | ProjectileImpact+damage calc | sim/combat | decompiled | functions/0042a140.md, data/damage_table.md |
| 0x429de0 | SpawnProjectile/effect (slot alloc, template copy) | sim/combat | decompiled | functions/0042a140.md |
| 0x429fa0 | ScorchDecal | sim/fx | decompiled | functions/0042a140.md |
| 0x45bf90.. | per-kind projectile update fns (std bullet/spiral) | sim/combat | decompiled(3/27) | functions/projectile_kinds.md, data/proj_kinds.md |
| 0x452f10-0x457bb0 | per-type unit handlers (thin wrappers) | sim/units | decompiled(all +0x3c) | functions/unit_class_handlers.md |
| 0x450cb0 | LoadLanguageText | ui/text | understood | O | 300 | src/ui/text.c (hook) | fills 0x85ef60+i*0x50 from DATA\{game,jiv,fre,spm}text.txt by 0x4b9608; callers 0x40db87, 0x4510b0 |
| 0x440450 | MP_Lobby | ui/net | decompiled | O | 5638 | src/ui/lobby.c (hooks) | MP/skirmish lobby: slots, factions, options, gv sync, start handshake. functions/00440450.md |
| 0x4758b0/0x475be0/0x475cd0/0x476010/0x475dc0 | Btn Create/Enable/SetValue/GetValue/SetText | ui | understood | O | - | - | button toolkit, slot table 0x592bb0 stride 0x3c0 |
| 0x41c346.. | UpdateWinLose (inline stage) | core/rules | understood | O | - | src/sim/teams.c (H10,H11) | functions/teams.md |
| (teams) | allied() hooks H1..H11, H13..H16 shared vision | sim/teams | implemented | O | - | src/sim/teams.c | functions/teams.md |
| 0x466030 | factory unit panel (draw) | ui/build | understood | O | - | src/sim/cheats.c (truck_stub) | HQ truck at vehicle factory; functions/cheats.md |
| 0x445fff | ExecuteCommands chat case (kind 0x65) | net/chat | understood | O | - | src/sim/cheats.c | dev cheats; functions/cheats.md |
| 0x4245c0 | FindFreeTileNearBuilding(bldg,size)->x|y<<16 | world | understood | O | - | - | used by production and cheats |
| 0x4657c6.. | Chat_Post (cmd 0x65, text 0x4e0d88) | ui/chat | located | O | - | - | |
| 0x4573a0 | UnitHandler_MBU (type 42 truck deploy) | sim/unit | understood | O | - | - | functions/cheats.md |
| 0x420240 | RemoveBuildingQuiet | world | understood | O | - | - | functions/cheats.md |
| 0x4207a0 | RestoreGroundUnderBuilding(+crater) | world | understood | O | - | - | |
| 0x4210c0 | RemoveUnitQuiet | world | understood | O | - | - | |
| 0x464ee0 | UI_HoverCursor (2 ground, 4 attack, 3 own selected, -1 select, 0x14 priest) | ui | understood | O | - | src/sim/teams.c (tm_cur_unit/bld) | ally = select cursor; functions/cheats.md rev 10 |
| 0x4659c2.. | UI_BuildList (construction icons, click -> 0x6729b0) | ui | understood | O | - | src/sim/cheats.c (hooks) | functions/cheats.md rev 4 |
| 0x4932f0 | QueueSprite(sheet,frame,x,y) | gfx | understood | O | - | - | |
| 0x42d420 | DestroyUnit(slot) | world | decompiled | O | ~1300 | src/sim/cheats.c (self destruct) | direct mode: death fx + removal; queue mode posts kind 0xb. functions/0042d420.md |
| 0x42ccc0 | DestroyBuilding(idx) | world | decompiled | O | ~1100 | src/sim/cheats.c (self destruct) | functions/0042ccc0.md |
| 0x41ac80.. (in 0x416fe0) | SpecialOrders_Pick | rules | understood | O | - | src/sim/cheats.c (mission_stub @0x41ad45) | type 0x9d6340[p], target 0x90aad0[p]; functions/cheats.md rev 10 |
| 0x41bebb (in 0x416fe0) | sim tick ++ (0x6df3b0) | engine | located | O | - | src/sim/cheats.c (trib_stub) | per-tick hook point |
| 0x416b36 / 0x417c97 (in 0x416fe0) | input gathers (Ctrl, Shift words) | ui/input | located | O | - | src/sim/cheats.c (sd_stub/sd_stub2) | both must be hooked |
| 0x405747 | WndProc WM_KEYDOWN/UP -> key words 0x71b3e0/0x71b4e0 | ui/input | understood | O | - | - | scancode from lParam |
| 0x465543.. | Chat input (typing flag 0x834fb0, Enter 0x1c posts) | ui/chat | located | O | - | - | |
| 0x408480 | RemapSprites(buf) (palette 0x66cd44 -> screen via cube 0xaa210c; low-res halves rows) | gfx | decompiled | O | - | src/sim/cheats.c (card_remap, icon_remap) | |
| 0x4081a0 | LoadFile(name) (VCLZ LZSS or raw; size -> 0xa133c0) | io | decompiled | O | - | - | |
| 0x493ab0 / 0x4939c0 / 0x493090 | QueueSprite variants (type 9 / 7 / clip 0xb) | gfx | decompiled | O | - | - | draw queue PTR 0x4d7dd4, 0x1c per item, max 0x800 |
| 0x410b65.. / 0x410d1b.. | load cards.bim or incards.bim (0x6ccad0), iconsb.bim or iconsb1.bim (0x6ce120) | gfx | located | O | - | src/sim/cheats.c | |
| 0x4659f4 / 0x465b17 / 0x465b56 | UI_BuildList paging (pre-count, more, back) | ui | understood | O | - | src/sim/cheats.c | back and more shared one slot in the original; functions/cheats.md rev 11-13 |
| 0x4c20d0 | battle card power table (stride 0xc, flags dword +0) | data | located | O | - | - | cards.bim frame = id (-1 if id >= 0x19) |
| (all patch sites) | legion_enh.exe hook catalogue | patch | implemented | O | - | tools/patch_exe.py | functions/patch-hooks.md |

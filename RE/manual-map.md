# Manual <-> code map  (source: ref/manual-text.txt from 'Manual v2.pdf', 68 pp, partly OCR-garbled; ref/readme-original.txt)
Tags: [O] observed in code/data, [M] from manual, [I] inferred. Update when a row is verified.

## Building types (table 0x4ba688, 23 names, stride 0x14) [O]
0 base(HQ) 1 slab 2 power 3 mine 4 refinery 5 barracks 6 wall 7 radar 8 hospital 9 tank(=Vehicle Factory) 10 gun 11 randd(=Hi-Tech Lab) 12 repair 13 robot(=Robot Hangar) 14 bmine 15 advcomms 16 silo 17 sheild(sic) 18 naval 19 air 20 pad 21 chem 22 supergun
Manual costs [M]: HQ 0, Power 1500, Barracks 1500, Wall 150, Hospital 5000, Repair 6000, Vehicle Fac 10000, Robot Hangar 20000, Hi-Tech Lab 12000, Mine 250, Gun 1250, Super Gun 3250. Several table names (slab, refinery, radar, silo, naval, air, pad, chem, advcomms) are unused leftovers [I].
Construction levels [M]: L1 MBU -> L2 Power Plant -> L3 Barracks/Wall -> L4 Vehicle Factory, Hospital, Gun, Mine, Super Gun -> L5 Hi-Tech Lab, Repair Bay, Robot Hangar.
Verified in code: AI desire scoring (0x469e80) keeps only types 2 (power), 5 (barracks), 9 (vehicle factory), 0xd (robot hangar); defence (0x46af10) guards types 0 (HQ) and 10 (gun); 0x44d680 'tech target' prefers 5/9/0xd (production buildings). "bt_sheild" in the .ai files is the game's own spelling: resolved.

## Game rules -> code
| Manual feature | Code evidence |
|---|---|
| Tech level Hi/Medium/Low (skirmish) | TechLevel 0xa23500 / Missions.ini TechLevel; availability table 0x4addc0[type*10+level] (0x46a5b0) [I] |
| Power plant/power meter | AI treats power plant (type 2) specially in 0x469e80 (needs more when short 0x763380[p] >= 0x6683d0[p]) [I] |
| Credits per rank | player ranks 6 (Sergeant..General) [M]; UNIT rank +0x12 uses table 0x4c4390/0x4c4440 [I] |
| Unit ranks (4) | ENT rank fields not yet traced |
| Mobile Base Unit deploy | 0x448e00 creates HQ (type 0) at start position; CreateBuilding 0x421d40 [I] |
| Hospital / Repair bay / Priest bless | not read yet |
| Move modes Normal/Defensive/Aggressive | VehicleOrders 0x423710 'stance' cmd 0x15 and ent+0x6e (0x424300 SetUnitMode) [I] |
| Detachments Ctrl+1..0 | UI, not read |
| Infrared radar (I key) | strength shown per unit: likely 0x468300 UnitPower [?] |
| Crates (power-ups) | not read; 0x46bd80 AI 'idle units near pickups' [I] |
| Interior missions: AI will not move marines [readme] | explains per-mission AI exceptions |
| Skirmish vs AI | Missions.ini NumAIs, AIXtraCash, AICheatCount [O] |
| Special orders (timed sub-missions) | Missions.ini TriggerType/Val/Effect [O] |

## Battle Cards = special powers  [I, strong]
0x441ec0 ApplyBattleCard(target, cardEffect, p) executes them; 0x44da70 AI_PlayBattleCard: the AI's hand is 5 card ids at 0x75ba20[p*8+k] ("Re-deal", "Fate", "Steal Card" exist in manual); table 0x4c20d0 (stride 0xc) = card table; command kind 0xb with id+900.
Manual list (1-49+): 1 Machine Curse, 2 Battle Psychosis (L2,L3 = longer), 5 One in a Million, 6 God Hammer (L2), 8 Equilibrium, 9 Skill Strip, 10 Battle Rage, 11 Domination, 12 Immolation (L2), 14 Doom Fist (L2), 16 Chaos (+one unit), 18 Displacement Warp, 19 Skill Steal, 20 Damage Transfer, 21 Life Siphon, 22 Deception, 23 Infiltrate, 24 Surveillance Jam, 25 Holy Blessing (+one unit), 27 Summon Darkness, 28 Blizzard, 29 Apparition, 30 Dark Legion, 31 Armageddon, 32 Blast Fog (L2), 34 Holy Curse (L2), 36 Balance, 37 Teleport, 38 Stealth (L2, L3), 41 Reveal, 42 Steal Credits (L2), 44 Demolition, 45 System Disruption, 46 Reveal Cards, 47 Re-deal, 48 Fate, 49 Steal Card (+Joker per readme).
Effect-id guesses from 0x441ec0 [I]:
- ids 1, 0x1e, 0x1f: flag 0x400 timer 2000/3000/4000 radius 256/288/320 = Battle Psychosis L1/L2/L3 (manual: L2/L3 last longer).
- ids 3, 0x1c: hp halved then -60 / -120 = God Hammer L1/L2. ids 4, 0x32: = Immolation L1/L2 (armoured units take less).
- id 5: copies unit state across units = Equilibrium. id 2: flag 0x200 timer 3000 = Machine Curse (slow) [?]. id 0: flag 0x100 one-shot = One in a Million [?].
- ids 0x1b/0x31 position-targeted (Blast Fog?/Armageddon?), 0x10,0x28,0x29,0x2f,0x30 building-sourced.
Priests invoke a card effect by attacking after a card is dropped [M].

## Readme facts worth keeping [readme]
Kill credits only for gun/ray/missile kills (not overruns, cards, gun emplacements). Max unit cap exists (extra builds consume no money). Chaos fire does not stop after Skill Strip. Doom Fist hits all walls in MP. Balance gives credits evenly to all human and AI. Venom Typhoon labelled Revelator for Chosen in MP.

## Card effect ids 6..0x30 (from 0x441ec0, see functions/00441ec0.md table)
Strong: 8 Domination, 0x20 Balance, 0x26/0x27 Steal Credits L1/L2, 0x2a Reveal Cards, 0x2b/0x2c Re-deal/Fate, 0x12 Summon Darkness. Likely: 6 Battle Rage, 7/0x1a Chaos, 0x14/0x19 Holy Blessing, 0x15/0x16 Apparition/Dark Legion, 0x22-24 Stealth, 0x28 Demolition, 0x10 Infiltrate. Card id->name table 0x4afae0 is filled at runtime (data file) [O].

## Economy (manual v2 vs code)  [rev: session 3]
Manual [M]: NO harvesting. Credits = periodic "budget allocation" auto-added to bank, amount scales with player rank (kills); special orders give extra credits; MP start credits setting (max 75,000). Kill credits only gun/ray/missile kills (readme).
Code [O]: credits 0x834a00[p] (int, clamped 0..999,999 in the 'Update Credits' stage at 0x419e73; display value 0x6ccad8 counts up/down by (diff&~0x3f0)/16+50 per tick). Player rank 0x835260[p]. Start credits set at 0x404ce8: min 0x1f40 (8000), slot 0x834a1c is a setting (/2 or /4 per level). Repair cost 10 credits/0x12 ticks (0x457bf0). Card 0x45dfe9 grants +0x4e20 (20000) credits [I: special/bonus pickup]. 
UNLOCATED: the periodic budget payout (rank-based). Not in 'Update Credits'. Next: look for timer + rank table lookup near 0x45f3a0 UpDateLocalPlayer / 0x4443b6 / 0x44462a / 0x42c178 (ApplyDamage rank-up).
Harvester code (0x452f30, unit types 0/1, bldg types 3 'mine' and 4 'refinery') is probably a VESTIGIAL/cut feature: manual has no harvesting, table names 'refinery','slab' are unused leftovers, and manual's 'Mine' (250 cr, L4) is a defensive structure. Treat types 0/1 as unknown role until their names/buildability are checked in UnitTypeTable / manual unit list.

### BUDGET PAYOUT FOUND [O]  (rev session 3b)
Location: inside per-frame loop 0x416fe0 at 0x417325..0x4173bb (after 'Update winlose'). Timer 0x8046e8 += frame delta 0x6df0f8; when > period 0x8046f0 (init 5000 = 0x1388 at 0x404d1e; may be changed by mission/level) timer -= period and for each player p=0..7:
  budget = (rank[p]*4 + 20) * 375   (rank = 0x835260[p], 0..5)  => 7500, 9000, 10500, 12000, 13500, 15000
  if credits[p] >= 50,000 (0xc350) then budget = 0   (no payout when rich)
  paid only if skirmish TechLevel 0xa23500 > 0 or p <= 0x803c40 (human count) [I]
  credits[p] += budget; 0x9094e0[p] += budget (lifetime earned stat); local player gets message (format 0x4dc128) + sound.
  ([ebp-0x10] = max(0, 15 - 0x994980[p]) computed but used later [?]).
Player rank thresholds: score 0x7f7e00[p] vs table 0x4af830 = {5,13,23,35,49,99}; score +2 per building kill, +2 more for HQ(type 0), (units: elsewhere).
Kill credit: credits[killer] += 0x4af7e0[victim class] = {100,250,300,400,500,600,700,800,1000,1250,1500,1750,2000}.
Harvest economy IS fully implemented in code (mine type 3 digs ore map 0x67bd90, harvester carries, refinery type 4 converts ore at +4 credits per tick-unit and spawns a harvester CreateUnit(1) on completion) but the manual has no such buildings; availability tables decide if buildable [?].

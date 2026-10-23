---
addr: 0x452f10-0x457bb0
name: UnitType +0x3c handler functions (ent+0xc8), by type
subsystem: sim/units
status: decompiled
rev: 1
---
Most handlers are thin wrappers: [O]
- 0x454d20 generic order state machine (see 00454d20.md) <- types 2,6 direct; wrappers 0x456d60 (t4), 0x456d70 (t9), 0x4574d0 (t3), 0x4574e0 (t5), 0x4574f0 (t7), 0x457500 (t8), 0x457510 (t10)
- 0x456e80 (see 00456e80.md) <- types 13,14,15 direct; wrappers 0x457530 (t16), 0x457540 (t17), 0x457550 (t18), 0x457610 (t20); 0x457560 (t19) and 0x457620 (t21) add: when anim frame +0x680466 in 900..0x38b => spawn 3 scorch/blood decals 0x429d10 around unit (death/burn visual). 0x457620 also sets weapon kind +0xa4/+0xa6 from table 0x4c0eaa/ae, but in state 3 (attack-fire) vs a target whose class(UnitType+0x1c)!=0 (i.e. vehicle) uses kind 0x26 with reload x3 => type 21 has anti-vehicle mode.
- 0x456d80 (t33,34 direct; wrappers 0x457b10 t35, 0x457b20 t36): run 0x454d20 then ANIMATE walk cycle: if position changed since entry advance anim frame +0x680466 every 4 ticks (6 if +0x14==1) wrapping at 0x14 (0xc for +0x14==1), else when idle (state not 5/6) show standing frame 0x11 (5 for +0x14==1). 0x457b30 (t37) additionally snaps body dir +0x44 and turret dir +0x60 to desired (+0x54/+0x64) when state 3 (no turn delay = tank-like fast turret); 0x457bb0 (t38,43) snaps body dir for +0x14==1.
- Empty (return only): 0x457520 (t11), 0x457a70/80/90 (t23,24,25) => those unit types are pure data/placeholder records with no update; 0x452f10 (t12,26-32,39-41): clears fields +0x680458/5c only (pickups/crates & upgrade pseudo-units).
- 0x4573a0 (t42, cost 25000, hp 30: the 'new base' unit of Special Orders): state 0x14 = DEPLOY: clears occupancy 0x6d3920 in a 13x13 box around it for itself, then CreateBuilding(type 0=base, owner, tx-2, ty-1); success => remove unit via 0x4210c0, else state 0. Other states -> 0x454d20.
- 0x457740 (t22): FORMATION LEADER: ent+0xc2..+0xc8 hold up to 4 child ent indexes (-1 none); each tick children snap to leader pos with +0x48 (target?) -=2. States +0x72: 0 idle (decay +0x48 speed), 1 move to (+0x50,+0x52) with smooth turning (dir +0x44 toward heading, speed ramp +0x48 up to 0x60000), arrives within 4 px => state 0; 2 wait for children all gone => state 0.
Type 22-25 table cost 3000 hp 9 ('shell' infantry?) - identity unverified.

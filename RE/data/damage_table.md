# Damage table @0x4b5ee8: 14 weapon classes x 20 armor classes (int 16.16; only first 5 armor cols nonzero)
weapon class -> projectile kind: 0=default(bullets) 1=kind2 2=0xf 3=0x14 4=0x1f 5=0x21 6=0x22 7=0x23 8=0x26 9=0x27 10=0x28 11=0x29 12=0x2a 13=0x2b (0x12 -> class 0)
armor class = UnitType+0x1c (0 = infantry; else vehicle/AC class) or building table +0x4bb7d4 (-1 -> 2)

| wclass | a0 | a1 | a2 | a3 | a4 |
|---|---|---|---|---|---|
| 0 | 16 | 8 | 8 | 4 | 4 |
| 1 | 90 | 80 | 40 | 40 | 40 |
| 2 | 6 | 19 | 19 | 25 | 19 |
| 3 | 10 | 30 | 30 | 40 | 60 |
| 4 | 30 | 100 | 90 | 50 | 100 |
| 5 | 39 | 30 | 26 | 13 | 30 |
| 6 | 90 | 80 | 40 | 40 | 80 |
| 7 | 90 | 80 | 40 | 40 | 80 |
| 8 | 8 | 22 | 22 | 30 | 22 |
| 9 | 68 | 60 | 30 | 30 | 60 |
| 10 | 50 | 35 | 35 | 13 | 35 |
| 11 | 50 | 35 | 35 | 13 | 35 |
| 12 | 50 | 35 | 35 | 13 | 35 |
| 13 | 6 | 19 | 19 | 25 | 19 |


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441ec0(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  short sVar3;
  ushort uVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  short sVar14;
  int iVar15;
  undefined4 *puVar16;
  uint *puVar17;
  int iVar18;
  ushort *puVar19;
  char *pcVar20;
  short *psVar21;
  int *piVar22;
  int *piVar23;
  int iVar24;
  char *pcVar25;
  uint *puVar26;
  short *psVar27;
  int *piVar28;
  ushort *puVar29;
  short *psVar30;
  int iVar31;
  int iVar32;
  bool bVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  int local_1b0 [56];
  short *local_d0;
  short *local_cc;
  short *local_c8;
  int local_c4;
  short *local_c0;
  short *local_bc;
  uint local_b8;
  int *local_b0;
  int *local_ac;
  int local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_60;
  uint *local_5c;
  undefined4 *local_58;
  int local_54;
  uint *local_4c;
  ushort *local_48;
  uint *local_44;
  int local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  pbVar8 = DAT_0066cd44;
  sVar3 = DAT_00668ccc;
  local_18 = 0;
  if ((param_2 == 0x1b) || (param_2 == 0x31)) {
    local_8 = param_3;
    local_c = 0;
    local_10 = 0;
  }
  else {
    if ((((param_2 == 0x10) || (param_2 == 0x28)) || (param_2 == 0x29)) ||
       ((param_2 == 0x2f || (param_2 == 0x30)))) {
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      local_c = (int)((&DAT_00805e10)[param_1 * 0x38] << 5) / 2 +
                (&DAT_00805e08)[param_1 * 0x38] * 0x20;
      local_10 = (int)((&DAT_00805e14)[param_1 * 0x38] << 5) / 2 +
                 (&DAT_00805e0c)[param_1 * 0x38] * 0x20;
    }
    else {
      local_8 = (int)(short)(&DAT_0067fe10)[param_1 * 0x368];
      local_c = (int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10;
      local_10 = (int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10;
      if (0x59 < local_8) {
        local_8 = local_8 + -0x5a;
      }
      if (local_8 == 9) {
        local_8 = 1;
      }
      if ((&DAT_0067fe12)[param_1 * 0x368] == 0x11) {
        *(short *)(&DAT_00680486 + param_1 * 0x6d0) =
             *(short *)(&DAT_00680486 + param_1 * 0x6d0) + 1;
        if ((&DAT_0067fe10)[param_1 * 0x368] == sVar3) {
          _sprintf(&DAT_004dd968,&DAT_008658b0);
          iVar15 = DAT_0092ab58 * 0x100;
          uVar10 = 0xffffffff;
          pcVar20 = &DAT_004dd968;
          do {
            pcVar25 = pcVar20;
            if (uVar10 == 0) break;
            uVar10 = uVar10 - 1;
            pcVar25 = pcVar20 + 1;
            cVar1 = *pcVar20;
            pcVar20 = pcVar25;
          } while (cVar1 != '\0');
          uVar10 = ~uVar10;
          pcVar20 = pcVar25 + -uVar10;
          pcVar25 = &DAT_0090a5c0 + iVar15;
          for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
            *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
            pcVar20 = pcVar20 + 4;
            pcVar25 = pcVar25 + 4;
          }
          for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *pcVar25 = *pcVar20;
            pcVar20 = pcVar20 + 1;
            pcVar25 = pcVar25 + 1;
          }
          (&DAT_0090a5ed)[iVar15] = 0;
          DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
          if (DAT_0092ab58 == DAT_009d5a44) {
            DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
          }
          DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
          if (((DAT_0083a3f0 != 1) ||
              (iVar15 = _strncmp(&DAT_004dd968,&DAT_00864640,8), iVar15 == 0)) ||
             (iVar15 = _strncmp((char *)&DAT_0066d1a0,&DAT_00864640,8), iVar15 != 0)) {
            uVar10 = 0xffffffff;
            DAT_0083a3f0 = 1;
            DAT_00834f80 = 0;
            pcVar20 = &DAT_004dd968;
            do {
              pcVar25 = pcVar20;
              if (uVar10 == 0) break;
              uVar10 = uVar10 - 1;
              pcVar25 = pcVar20 + 1;
              cVar1 = *pcVar20;
              pcVar20 = pcVar25;
            } while (cVar1 != '\0');
            uVar10 = ~uVar10;
            pcVar20 = pcVar25 + -uVar10;
            pcVar25 = (char *)&DAT_0066d1a0;
            for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
              *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
              pcVar20 = pcVar20 + 4;
              pcVar25 = pcVar25 + 4;
            }
            for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
              *pcVar25 = *pcVar20;
              pcVar20 = pcVar20 + 1;
              pcVar25 = pcVar25 + 1;
            }
            iVar15 = -1;
            pcVar20 = &DAT_004dd968;
            do {
              if (iVar15 == 0) break;
              iVar15 = iVar15 + -1;
              cVar1 = *pcVar20;
              pcVar20 = pcVar20 + 1;
            } while (cVar1 != '\0');
            DAT_008350e0 = ~(ushort)iVar15 - 1;
            DAT_00859526 = DAT_008350e0 * 2 + 300;
          }
        }
        FUN_0046f6b0(DAT_008596ac,DAT_0071a0ec,0x40,0x20);
        return;
      }
    }
    if (local_8 == 0) {
      return;
    }
    if (6 < local_8) {
      return;
    }
    if (param_2 == 0x34) {
      param_2 = (local_8 + (local_c >> 4) + param_1) % 0x34;
      if (param_2 == 0x18) {
        param_2 = 0x11;
      }
      if (DAT_00803c40 == 1) {
        if (param_2 == 0xf) {
          param_2 = 4;
        }
        if (param_2 == 0x11) {
          param_2 = 0x20;
        }
        if (param_2 == 0x12) {
          param_2 = 3;
        }
        if (param_2 == 0xf) {
          param_2 = 4;
        }
        if (param_2 == 0x34) {
          param_2 = 4;
        }
      }
      else {
        if (param_2 == 0x2a) {
          param_2 = 4;
        }
        if (param_2 == 0x2d) {
          param_2 = 0x20;
        }
      }
      if ((((param_2 == 0x10) || (param_2 == 0x28)) || (param_2 == 0x29)) ||
         ((param_2 == 0x2f || (param_2 == 0x30)))) {
        param_2 = 4;
      }
    }
    switch(param_2) {
    case 0:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) {
        (&DAT_00680498)[param_1 * 0x1b4] = (&DAT_00680498)[param_1 * 0x1b4] | 0x100;
        *(undefined2 *)(&DAT_006804ac + param_1 * 0x6d0) = 0;
      }
      break;
    case 1:
    case 0x1e:
    case 0x1f:
      _DAT_004b565c = 0x1b;
      FUN_00489696(1,0x1b);
      if ((DAT_004d85a0 == 1) && (DAT_004c4620 == 1)) {
        FUN_00489d51((int)DAT_00507368,0);
      }
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        local_d0 = &DAT_0067fe10 + param_1 * 0x368;
        do {
          if ((((short)puVar17[-0x1a2] == *local_d0) && ((short)puVar17[-0x19f] != 0)) &&
             ((*puVar17 & 0x40000) == 0)) {
            iVar31 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
            iVar24 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
            if (iVar31 < 0) {
              iVar31 = -iVar31;
            }
            if (iVar24 < 0) {
              iVar24 = -iVar24;
            }
            iVar13 = 0x100;
            if (param_2 == 0x1e) {
              iVar13 = 0x120;
            }
            if (param_2 == 0x1f) {
              iVar13 = 0x140;
            }
            if ((iVar31 < iVar13) && (iVar24 < iVar13)) {
              *puVar17 = *puVar17 | 0x400;
              *(undefined2 *)(puVar17 + 6) = 2000;
              if (param_2 == 0x1e) {
                *(undefined2 *)(puVar17 + 6) = 3000;
              }
              if (param_2 == 0x1f) {
                *(undefined2 *)(puVar17 + 6) = 4000;
              }
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 2:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if (((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
             ((short)puVar17[-0x19f] != 0)) {
            if ((*puVar17 & 0x1000) == 0) {
              iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
              iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                *puVar17 = *puVar17 | 0x200;
                *(undefined2 *)((int)puVar17 + 0x16) = 3000;
              }
            }
            else {
              local_18 = 1;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 3:
    case 0x1c:
      sVar3 = FUN_00429de0(0xb,1,local_c,local_10,0xffffffff,0xffffffff);
      FUN_00416e20(DAT_0085959c,DAT_00719fdc,local_c >> 5,local_10 >> 5);
      local_20 = 0;
      bVar33 = -1 < DAT_006e5b38;
      *(int *)(&DAT_009e3bc0 + DAT_00719fdc * 4) = (int)sVar3;
      if (bVar33) {
        piVar22 = &DAT_0067fe20;
        local_cc = &DAT_0067fe10 + param_1 * 0x368;
        do {
          if (((short)piVar22[-4] == *local_cc) && ((short)piVar22[-1] != 0)) {
            if ((*(byte *)((int)piVar22 + 0x679) & 0x10) == 0) {
              iVar31 = (piVar22[2] >> 0x10) - local_c;
              iVar15 = (piVar22[3] >> 0x10) - local_10;
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if (iVar15 < 0) {
                iVar15 = -iVar15;
              }
              iVar24 = 0x100;
              if (param_2 == 0x1c) {
                iVar24 = 0x120;
              }
              if ((iVar31 < iVar24) && (iVar15 < iVar24)) {
                FUN_00429de0(4,1,piVar22[2] >> 0x10,piVar22[3] >> 0x10,0xffffffff,0xffffffff);
                iVar15 = *piVar22 >> 1;
                *piVar22 = iVar15;
                if (*(short *)(&DAT_004c0874 + *(short *)((int)piVar22 + -0xe) * 0x4c) == 0) {
                  *piVar22 = iVar15 + -0x3c0000;
                  if (param_2 == 0x1c) {
                    iVar15 = iVar15 + -0x780000;
LAB_00442555:
                    *piVar22 = iVar15;
                  }
                }
                else {
                  *piVar22 = iVar15 + -0x1e0000;
                  if (param_2 == 0x1c) {
                    iVar15 = iVar15 + -0x3c0000;
                    goto LAB_00442555;
                  }
                }
              }
            }
            else {
              local_18 = 1;
            }
          }
          piVar22 = piVar22 + 0x1b4;
          local_20 = local_20 + 1;
        } while ((int)local_20 <= (int)DAT_006e5b38);
      }
      break;
    case 4:
    case 0x32:
      sVar3 = FUN_00429de0(0xb,1,local_c,local_10,0xffffffff,0xffffffff);
      FUN_00416e20(DAT_0085959c,DAT_00719fdc,local_c >> 5,local_10 >> 5);
      local_20 = 0;
      bVar33 = -1 < DAT_006e5b38;
      *(int *)(&DAT_009e3bc0 + DAT_00719fdc * 4) = (int)sVar3;
      if (bVar33) {
        piVar22 = &DAT_0067fe20;
        local_c8 = &DAT_0067fe10 + param_1 * 0x368;
        do {
          if (((short)piVar22[-4] == *local_c8) && ((short)piVar22[-1] != 0)) {
            if ((*(byte *)((int)piVar22 + 0x679) & 0x10) == 0) {
              iVar31 = (piVar22[2] >> 0x10) - local_c;
              iVar15 = (piVar22[3] >> 0x10) - local_10;
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if (iVar15 < 0) {
                iVar15 = -iVar15;
              }
              iVar24 = 0x100;
              if (param_2 == 0x32) {
                iVar24 = 0x120;
              }
              if ((iVar31 < iVar24) && (iVar15 < iVar24)) {
                FUN_00429de0(4,1,((local_20 & 0x1f) - 0xf) + (piVar22[2] >> 0x10),
                             ((local_20 & 0x1f) - 0xf) + (piVar22[3] >> 0x10),0xffffffff,0xffffffff)
                ;
                iVar15 = *piVar22;
                if (*(short *)(&DAT_004c0874 + *(short *)((int)piVar22 + -0xe) * 0x4c) == 0) {
                  *piVar22 = iVar15 + -0xa0000;
                  if (param_2 == 0x32) {
                    iVar15 = iVar15 + -0x140000;
LAB_004426d9:
                    *piVar22 = iVar15;
                  }
                }
                else {
                  *piVar22 = iVar15 / 2;
                  iVar15 = iVar15 / 2 + -0x640000;
                  *piVar22 = iVar15;
                  if (param_2 == 0x32) {
                    iVar15 = iVar15 / 2;
                    *piVar22 = iVar15;
                    iVar15 = iVar15 + -0x640000;
                    goto LAB_004426d9;
                  }
                }
              }
            }
            else {
              local_18 = 1;
            }
          }
          piVar22 = piVar22 + 0x1b4;
          local_20 = local_20 + 1;
        } while ((int)local_20 <= (int)DAT_006e5b38);
      }
      break;
    case 5:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) == 0) {
        bVar33 = -1 < DAT_006e5b38;
        (&DAT_00680498)[param_1 * 0x1b4] = (&DAT_00680498)[param_1 * 0x1b4] & 0xfffffff7;
        if (bVar33) {
          puVar17 = &DAT_00680498;
          local_78 = DAT_006e5b38 + 1;
          do {
            if ((((short)puVar17[-0x1a2] != 0) && ((short)puVar17[-0x19f] != 0)) &&
               ((*puVar17 & 0x1000) == 0)) {
              uVar10 = (&DAT_00680498)[param_1 * 0x1b4];
              *puVar17 = uVar10;
              puVar26 = puVar17 + 1;
              *puVar17 = uVar10 & 0xfffffff7;
              puVar5 = &DAT_0068049c + param_1 * 0x368;
              *(undefined2 *)((int)puVar17 + -0x5da) = (&DAT_0067febe)[param_1 * 0x368];
              *(undefined2 *)(puVar17 + -0x176) = (&DAT_0067fec0)[param_1 * 0x368];
              iVar15 = 0x20;
              do {
                uVar2 = *puVar5;
                puVar5 = puVar5 + 1;
                *(undefined2 *)puVar26 = uVar2;
                puVar26 = (uint *)((int)puVar26 + 2);
                iVar15 = iVar15 + -1;
              } while (iVar15 != 0);
              *(undefined2 *)((int)puVar17 + -0x5f6) =
                   *(undefined2 *)(&DAT_004c086c + *(short *)((int)puVar17 + -0x686) * 0x4c);
              *(undefined2 *)((int)puVar17 + -0x36) = (&DAT_00680462)[param_1 * 0x368];
              *(undefined2 *)(puVar17 + -0xd) = 0;
            }
            puVar17 = puVar17 + 0x1b4;
            local_78 = local_78 + -1;
          } while (local_78 != 0);
          local_78 = 0;
        }
      }
      else {
        local_18 = 1;
      }
      break;
    case 6:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) {
        _DAT_004b565c = 0x1b;
        FUN_00489696(1,0x1b);
        if ((DAT_004d85a0 == 1) && (DAT_004c4620 == 1)) {
          FUN_00489d51((int)DAT_00507368,0);
        }
        (&DAT_009d5a70)[(ushort)(&DAT_0067fe10)[param_1 * 0x368] & 7] =
             (&DAT_009d5a70)[(ushort)(&DAT_0067fe10)[param_1 * 0x368] & 7] + 1000;
      }
      break;
    case 7:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if (((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
             ((short)puVar17[-0x19f] != 0)) {
            if ((*puVar17 & 0x1000) == 0) {
              iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
              iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                *puVar17 = *puVar17 | 0x800;
                *(undefined2 *)((int)puVar17 + 0x1a) = 3000;
                *(undefined2 *)((int)puVar17 + -0x626) = 0;
                *(undefined2 *)(puVar17 + -0x189) = 0;
                *(undefined2 *)(puVar17 + -0x184) = 0;
                *(undefined2 *)((int)puVar17 + -0x606) = 0;
              }
            }
            else {
              local_18 = 1;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 8:
      psVar27 = (short *)0x0;
      psVar30 = (short *)(param_1 * 0x6d0);
      local_c4 = (int)psVar30[0x33ff08];
      if (-1 < DAT_006e5b38) {
        psVar21 = &DAT_0067fe10;
        do {
          psVar30 = (short *)CONCAT22((short)((uint)psVar30 >> 0x10),*psVar21);
          if ((*psVar21 == local_c4) && (psVar21[6] != 0)) {
            if ((*(byte *)((int)psVar21 + 0x689) & 0x10) == 0) {
              iVar31 = (*(int *)(psVar21 + 0xc) >> 0x10) - local_c;
              iVar15 = (*(int *)(psVar21 + 0xe) >> 0x10) - local_10;
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if (iVar15 < 0) {
                iVar15 = -iVar15;
              }
              if ((iVar31 < 0x60) && (iVar15 < 0x60)) {
                FUN_004678d0(psVar30,0xffffffff,psVar27);
                *psVar21 = (short)param_3;
                psVar21[0x31] = 0;
                psVar21[0x32] = 0;
                psVar21[0x3c] = 0;
                psVar21[0x41] = 0;
                psVar21[0x37] = 1;
                psVar21[0x24] = -1;
                FUN_00467bd0(param_3,0xffffffff,psVar27);
                psVar21[0x31] = 0;
                psVar30 = (short *)(int)DAT_0078bd70;
                psVar21[0x32] = 0;
                psVar21[0x3c] = 0;
                psVar21[0x41] = 0;
                psVar21[0x37] = 1;
                psVar21[0x24] = -1;
                if (psVar30 == psVar27) {
                  DAT_0078bd70 = -1;
                  DAT_00858514 = 0xffff;
                }
                if ((short *)(int)DAT_006df160 == psVar27) {
                  DAT_006df160 = -1;
                }
                iVar15 = 0;
                if (0 < DAT_006dd208) {
                  psVar30 = &DAT_006df160;
                  do {
                    if ((short *)(int)*psVar30 == psVar27) {
                      DAT_0078bd70 = -1;
                      DAT_00858514 = 0xffff;
                      *psVar30 = -1;
                      DAT_006dd208 = 0;
                    }
                    psVar30 = psVar30 + 1;
                    iVar15 = iVar15 + 1;
                  } while (iVar15 < DAT_006dd208);
                }
                if (-1 < DAT_006e5b38) {
                  psVar30 = (short *)&DAT_0067fe58;
                  iVar15 = DAT_006e5b38 + 1;
                  do {
                    if ((psVar30[-0x24] == param_3) && ((short *)(int)*psVar30 == psVar27)) {
                      *psVar30 = -1;
                      psVar30[0xd] = 0;
                    }
                    psVar30 = psVar30 + 0x368;
                    iVar15 = iVar15 + -1;
                    local_c0 = psVar21;
                  } while (iVar15 != 0);
                }
              }
            }
            else {
              local_18 = 1;
            }
          }
          psVar21 = psVar21 + 0x368;
          psVar27 = (short *)((int)psVar27 + 1);
        } while ((int)psVar27 <= (int)DAT_006e5b38);
      }
      break;
    case 9:
      iVar15 = 0;
      if (-1 < DAT_006e5b38) {
        local_14 = &DAT_0067fe28;
        do {
          if (((short)local_14[-6] != 0) && ((short)local_14[-3] != 0)) {
            if ((*(byte *)((int)local_14 + 0x671) & 0x10) == 0) {
              iVar24 = (*local_14 >> 0x10) - local_c;
              iVar31 = (local_14[1] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                sVar3 = *(short *)(&DAT_00716d70 + local_8 * 2);
                sVar14 = -1;
                if (sVar3 != -1) {
                  sVar14 = sVar3;
                }
                uVar10 = 0;
                if (sVar14 != -1) {
                  uVar10 = FUN_004245c0(sVar3,0x12);
                }
                if (uVar10 == 0) {
                  iVar31 = 0;
                  if (-1 < DAT_0083a402) {
                    piVar22 = &DAT_00805df0;
                    local_bc = &DAT_0067fe10 + param_1 * 0x368;
LAB_00442c9d:
                    if (((((int)*local_bc != *piVar22) || (piVar22[2] == 0)) ||
                        (*(short *)(&DAT_00716d70 + local_8 * 2) == iVar31)) ||
                       (uVar10 = FUN_004245c0(iVar31,0x12), uVar10 == 0)) goto LAB_00442cd1;
                    iVar31 = (*local_14 >> 0x15) * 0x80;
                    if ((uint)*(byte *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31) -
                        iVar15 == 1) {
                      *(undefined1 *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31) = 0;
                    }
                    *local_14 = uVar10 << 0x10;
                    iVar31 = 0x80;
                    local_14[1] = uVar10 & 0xffff0000;
                    *(undefined2 *)((int)local_14 + 0x4a) = 0;
                    *(undefined2 *)(local_14 + 0x13) = 0;
                    *(undefined2 *)(local_14 + 0x18) = 0;
                    *(undefined2 *)((int)local_14 + 0x6a) = 0;
                    psVar30 = &DAT_009014a0;
                    do {
                      iVar24 = 0x80;
                      do {
                        if (*psVar30 == iVar15) {
                          *psVar30 = -1;
                        }
                        psVar30 = psVar30 + 1;
                        iVar24 = iVar24 + -1;
                      } while (iVar24 != 0);
                      iVar31 = iVar31 + -1;
                    } while (iVar31 != 0);
                    iVar31 = (*local_14 >> 0x15) * 0x80;
                    cVar1 = *(char *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31);
                    pcVar20 = (char *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31);
                    goto joined_r0x00442d82;
                  }
                }
                else {
                  iVar31 = (*local_14 >> 0x15) * 0x80;
                  if ((uint)*(byte *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31) - iVar15
                      == 1) {
                    *(undefined1 *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31) = 0;
                  }
                  *local_14 = uVar10 << 0x10;
                  psVar30 = &DAT_009014a0;
                  local_14[1] = uVar10 & 0xffff0000;
                  *(undefined2 *)((int)local_14 + 0x4a) = 0;
                  *(undefined2 *)(local_14 + 0x13) = 0;
                  *(undefined2 *)(local_14 + 0x18) = 0;
                  *(undefined2 *)((int)local_14 + 0x6a) = 0;
                  iVar31 = 0x80;
                  do {
                    iVar24 = 0x80;
                    do {
                      if (*psVar30 == iVar15) {
                        *psVar30 = -1;
                      }
                      psVar30 = psVar30 + 1;
                      iVar24 = iVar24 + -1;
                    } while (iVar24 != 0);
                    iVar31 = iVar31 + -1;
                  } while (iVar31 != 0);
                  iVar31 = (*local_14 >> 0x15) * 0x80;
                  cVar1 = *(char *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31);
                  pcVar20 = (char *)((int)&DAT_006d3920 + (local_14[1] >> 0x15) + iVar31);
joined_r0x00442d82:
                  if (cVar1 == '\0') {
                    *pcVar20 = (char)iVar15 + '\x01';
                  }
                }
              }
            }
            else {
              local_18 = 1;
            }
          }
LAB_00442d89:
          iVar15 = iVar15 + 1;
          local_14 = local_14 + 0x1b4;
        } while (iVar15 <= DAT_006e5b38);
      }
      break;
    case 10:
    case 0x33:
      FUN_00429de0(0xb,1,local_c,local_10,0xffffffff,0xffffffff);
      iVar15 = 0;
      FUN_00416e20(DAT_0085959c,DAT_00719fdc,local_c >> 5,local_10 >> 5);
      if (-1 < DAT_006e5b38) {
        piVar22 = &DAT_0067fe20;
        do {
          if ((((int)(short)(&DAT_0067fe10)[param_1 * 0x368] - (int)(short)piVar22[-4] == -0x5a) &&
              ((short)piVar22[-1] != 0)) ||
             (((&DAT_0067fe10)[param_1 * 0x368] == (short)piVar22[-4] && ((short)piVar22[-1] != 0)))
             ) {
            if ((*(byte *)((int)piVar22 + 0x679) & 0x10) == 0) {
              iVar31 = *piVar22 >> 1;
              *piVar22 = iVar31;
              *piVar22 = iVar31 + -0x1e0000;
              if (param_2 == 0x33) {
                *piVar22 = iVar31 + -0x3c0000;
              }
              FUN_00429de0(4,1,piVar22[2] >> 0x10,piVar22[3] >> 0x10,0xffffffff,0xffffffff);
            }
            else {
              local_18 = 1;
            }
          }
          piVar22 = piVar22 + 0x1b4;
          iVar15 = iVar15 + 1;
        } while (iVar15 <= DAT_006e5b38);
      }
      if ((1 < DAT_00803c40) && (uVar10 = 0, -1 < DAT_0083a402)) {
        piVar22 = &DAT_00805e44;
        do {
          if ((((piVar22[-0x15] != 0) && (piVar22[-0x13] != 0)) && (piVar22[-0x14] == 6)) &&
             (*piVar22 = *piVar22 + -0x640000, (uVar10 & 3) == 0)) {
            FUN_00429de0(4,1,CONCAT22((short)((uint)piVar22[-0xf] >> 0x10),(short)piVar22[-0xf] << 5
                                     ),
                         CONCAT22((short)((uint)piVar22[-0xe] >> 0x10),(short)piVar22[-0xe] << 5),
                         0xffffffff,0xffffffff);
          }
          piVar22 = piVar22 + 0x38;
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 <= (int)DAT_0083a402);
      }
      break;
    case 0xb:
      if (-1 < DAT_006e5b38) {
        puVar16 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if ((*(short *)(puVar16 + -0x1a2) == (&DAT_0067fe10)[param_1 * 0x368]) &&
             (*(short *)(puVar16 + -0x19f) != 0)) {
            if ((*(byte *)((int)puVar16 + 1) & 0x10) == 0) {
              iVar24 = ((int)puVar16[-0x19c] >> 0x10) - local_c;
              iVar31 = ((int)puVar16[-0x19b] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                *puVar16 = 0x4000;
                if ((*(byte *)((int)puVar16 + 1) & 0x40) == 0) {
                  *puVar16 = 0;
                }
                *(undefined2 *)((int)puVar16 + -0x5f6) =
                     *(undefined2 *)(&DAT_004c086c + *(short *)((int)puVar16 + -0x686) * 0x4c);
                *(undefined2 *)((int)puVar16 + -0x36) = 0;
                *(undefined2 *)(puVar16 + -0xd) = 0;
              }
            }
            else {
              local_18 = 1;
            }
          }
          puVar16 = puVar16 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      (&DAT_009d5a70)[local_8] = 0;
      break;
    case 0xc:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        if (-1 < DAT_006e5b38) {
          psVar30 = &DAT_0067fe10;
          local_74 = DAT_006e5b38 + 1;
          do {
            if ((((*psVar30 != 0) && (psVar30[6] != 0)) &&
                ((*(uint *)(psVar30 + 0x344) & 0x40000) == 0)) && (*psVar30 == param_3)) {
              iVar31 = (*(int *)(psVar30 + 0xc) >> 0x10) - local_c;
              iVar15 = (*(int *)(psVar30 + 0xe) >> 0x10) - local_10;
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if (iVar15 < 0) {
                iVar15 = -iVar15;
              }
              if ((iVar31 < 0x100) && (iVar15 < 0x100)) {
                *(undefined4 *)(psVar30 + 0x344) = (&DAT_00680498)[param_1 * 0x1b4];
                psVar30[0x49] = (&DAT_0067fea2)[param_1 * 0x368];
                psVar30[0x329] = (&DAT_00680462)[param_1 * 0x368];
                psVar27 = &DAT_0068049c + param_1 * 0x368;
                psVar30[0x32a] = (&DAT_00680464)[param_1 * 0x368];
                psVar21 = psVar30 + 0x346;
                (&DAT_00680498)[param_1 * 0x1b4] = (&DAT_00680498)[param_1 * 0x1b4] & 0xfffffff7;
                iVar15 = 0x20;
                do {
                  sVar3 = *psVar27;
                  psVar27 = psVar27 + 1;
                  *psVar21 = sVar3;
                  psVar21 = psVar21 + 1;
                  iVar15 = iVar15 + -1;
                } while (iVar15 != 0);
                if ((*(byte *)(&DAT_00680498 + param_1 * 0x1b4) & 0x20) != 0) {
                  psVar30[8] = 0;
                  psVar30[9] = 0x3c;
                  psVar30[10] = 0x3c;
                }
              }
            }
            psVar30 = psVar30 + 0x368;
            local_74 = local_74 + -1;
          } while (local_74 != 0);
        }
        uVar12 = (&DAT_009d5a70)[local_8];
        (&DAT_00680498)[param_1 * 0x1b4] = 0;
        (&DAT_009d5a70)[param_3] = uVar12;
        sVar3 = (&DAT_0067fe12)[param_1 * 0x368];
        (&DAT_009d5a70)[local_8] = 0;
        (&DAT_0067fea2)[param_1 * 0x368] = *(undefined2 *)(&DAT_004c086c + sVar3 * 0x4c);
        (&DAT_00680462)[param_1 * 0x368] = 0;
        (&DAT_00680464)[param_1 * 0x368] = 0;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0xd:
      local_60 = param_1 * 0x6d0;
      if ((*(byte *)((int)&DAT_00680498 + local_60 + 1) & 0x10) == 0) {
        uVar10 = 0;
        uVar11 = 0;
        if (-1 < DAT_006e5b38) {
          psVar30 = &DAT_0067fe24;
          iVar15 = DAT_006e5b38 + 1;
          do {
            if ((psVar30[-10] == param_3) && (psVar30[-4] != 0)) {
              if ((int)*psVar30 != *(int *)(psVar30 + -2) >> 0x10) {
                uVar11 = uVar11 + 1;
                uVar10 = (uVar10 - (*(int *)(psVar30 + -2) >> 0x10)) + (int)*psVar30;
              }
            }
            psVar30 = psVar30 + 0x368;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        if (-1 < DAT_0083a402) {
          piVar22 = &DAT_00805e44;
          iVar15 = DAT_0083a402 + 1;
          do {
            if ((piVar22[-0x15] == param_3) && (piVar22[-0x13] != 0)) {
              if (*piVar22 >> 0x10 != piVar22[1]) {
                uVar11 = uVar11 + 1;
                uVar10 = (uVar10 - (*piVar22 >> 0x10)) + piVar22[1];
              }
            }
            piVar22 = piVar22 + 0x38;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        if (uVar11 != 0) {
          uVar10 = uVar10 / uVar11;
        }
        if (-1 < DAT_006e5b38) {
          piVar22 = &DAT_0067fe20;
          iVar15 = DAT_006e5b38 + 1;
          do {
            if (((short)piVar22[-4] == (&DAT_0067fe10)[param_1 * 0x368]) &&
               ((short)piVar22[-1] != 0)) {
              if ((*(byte *)((int)piVar22 + 0x679) & 0x10) == 0) {
                *piVar22 = *piVar22 + uVar10 * -0x10000;
              }
              else {
                local_18 = 1;
              }
            }
            piVar22 = piVar22 + 0x1b4;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        if (-1 < DAT_0083a402) {
          piVar22 = &DAT_00805e44;
          sVar3 = (&DAT_0067fe10)[param_1 * 0x368];
          iVar15 = DAT_0083a402 + 1;
          do {
            if ((piVar22[-0x15] == (int)sVar3) && (piVar22[-0x13] != 0)) {
              iVar31 = *piVar22 + uVar10 * -0x10000;
              *piVar22 = iVar31;
              if ((piVar22[-0x14] == 0) && (iVar31 < 1)) {
                *piVar22 = 0xa0000;
              }
            }
            piVar22 = piVar22 + 0x38;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
      }
      else {
        local_18 = 1;
      }
      break;
    case 0xe:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        iVar15 = 0x40000;
        if (-1 < DAT_006e5b38) {
          piVar22 = &DAT_0067fe20;
          iVar31 = DAT_006e5b38 + 1;
          do {
            if (((short)piVar22[-4] != 0) && ((short)piVar22[-1] != 0)) {
              if ((*(byte *)((int)piVar22 + 0x679) & 0x10) == 0) {
                iVar24 = (piVar22[2] >> 0x10) - local_c;
                iVar13 = (piVar22[3] >> 0x10) - local_10;
                if (iVar24 < 0) {
                  iVar24 = -iVar24;
                }
                if (iVar13 < 0) {
                  iVar13 = -iVar13;
                }
                if (((iVar24 < 0x140) && (iVar13 < 0x140)) && ((short)piVar22[-4] == local_8)) {
                  *piVar22 = *piVar22 - iVar15;
                }
                if (((short)piVar22[-4] == param_3) && ((piVar22[0x19e] & 0x40000U) == 0)) {
                  iVar24 = (int)(short)piVar22[1];
                  if (*piVar22 >> 0x10 != iVar24) {
                    iVar15 = iVar24 * 0x10000 - *piVar22;
                    *piVar22 = iVar24 << 0x10;
                  }
                }
              }
              else {
                local_18 = 1;
              }
            }
            piVar22 = piVar22 + 0x1b4;
            iVar31 = iVar31 + -1;
          } while (iVar31 != 0);
        }
        (&DAT_009d5a70)[local_8] = 0;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0xf:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if ((((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
              ((short)puVar17[-0x19f] != 0)) && ((*puVar17 & 0x40000) == 0)) {
            iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
            iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
            if (iVar24 < 0) {
              iVar24 = -iVar24;
            }
            if (iVar31 < 0) {
              iVar31 = -iVar31;
            }
            if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
              *puVar17 = *puVar17 | 0x2000;
              *(undefined2 *)((int)puVar17 + 0x1e) = 20000;
              *(undefined2 *)((int)puVar17 + -0x662) = 0;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 0x10:
      local_1c = param_1 * 0xe0;
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      piVar22 = &DAT_00805df0 + param_1 * 0x38;
      if ((&DAT_00805df4)[param_1 * 0x38] != 0) {
        piVar23 = piVar22;
        piVar28 = local_1b0;
        for (iVar15 = 0x38; iVar15 != 0; iVar15 = iVar15 + -1) {
          *piVar28 = *piVar23;
          piVar23 = piVar23 + 1;
          piVar28 = piVar28 + 1;
        }
        FUN_00420240(param_1);
        if (DAT_0083a402 < param_1) {
          DAT_0083a402 = DAT_0083a402 + 1;
        }
        piVar23 = local_1b0;
        piVar28 = piVar22;
        for (iVar15 = 0x38; iVar15 != 0; iVar15 = iVar15 + -1) {
          *piVar28 = *piVar23;
          piVar23 = piVar23 + 1;
          piVar28 = piVar28 + 1;
        }
        *piVar22 = param_3;
        FUN_00467bd0(param_3,param_1,0xffffffff);
        *(undefined4 *)((int)&DAT_00805df8 + local_1c) = 1;
        *(undefined4 *)((int)&DAT_00805e58 + local_1c) = 0;
        iVar31 = *piVar22;
        iVar24 = *(int *)((int)&DAT_00805df4 + local_1c);
        iVar15 = (iVar31 * 0x50 + iVar24) * 2;
        sVar3 = *(short *)(&DAT_00834a80 + iVar15);
        *(short *)(&DAT_00834a80 + iVar15) = sVar3 + 1;
        if ((short)(sVar3 + 1) == 1) {
          puVar29 = (ushort *)&DAT_0070db80;
          *(undefined2 *)((int)&DAT_00852b20 + iVar15) = (undefined2)param_1;
          puVar19 = (ushort *)(&DAT_00754fb0 + iVar31 * 0x28);
          puVar6 = (ushort *)(&DAT_00716d80 + iVar24 * 0x28);
          do {
            if (*puVar6 != 0) {
              *puVar19 = *puVar29 & *puVar6;
            }
            puVar29 = puVar29 + 1;
            puVar19 = puVar19 + 1;
            puVar6 = puVar6 + 1;
          } while (puVar29 < (ushort *)0x70dbad);
          puVar29 = &DAT_0083a350;
          puVar19 = (ushort *)(&DAT_006683f0 + iVar31 * 0x28);
          puVar6 = (ushort *)(&DAT_008532e0 + iVar24 * 0x28);
          do {
            if (*puVar6 != 0) {
              *puVar19 = *puVar29 & *puVar6;
            }
            puVar29 = puVar29 + 1;
            puVar19 = puVar19 + 1;
            puVar6 = puVar6 + 1;
          } while (puVar29 < (ushort *)0x83a3a7);
        }
        local_54 = *(int *)((int)&DAT_00805e10 + local_1c);
        if (0 < local_54) {
          iVar15 = *(int *)((int)&DAT_00805e08 + local_1c) * 0x80 +
                   *(int *)((int)&DAT_00805e0c + local_1c);
          local_5c = (uint *)(&DAT_0077b770 + iVar15 * 4);
          local_58 = (undefined4 *)(&DAT_00672d80 + iVar15);
          local_b8 = *(uint *)((int)&DAT_00805e14 + local_1c);
          local_6c = local_54;
          do {
            if (0 < (int)local_b8) {
              puVar16 = (undefined4 *)(&DAT_008352f0 + iVar15);
              for (uVar10 = local_b8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar16 = 0x3030303;
                puVar16 = puVar16 + 1;
              }
              for (uVar10 = local_b8 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar16 = 3;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              puVar16 = local_58;
              for (uVar10 = local_b8 >> 1; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar16 = 0xff00ff;
                puVar16 = puVar16 + 1;
              }
              for (uVar10 = (uint)((local_b8 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined2 *)puVar16 = 0xff;
                puVar16 = (undefined4 *)((int)puVar16 + 2);
              }
              puVar16 = (undefined4 *)(&DAT_0066da10 + iVar15);
              for (uVar10 = local_b8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar16 = 0x3030303;
                puVar16 = puVar16 + 1;
              }
              for (uVar10 = local_b8 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar16 = 3;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              puVar16 = (undefined4 *)((int)&DAT_008464f0 + iVar15);
              for (uVar10 = local_b8 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar16 = CONCAT22(CONCAT11((undefined1)param_3,(undefined1)param_3),
                                    CONCAT11((undefined1)param_3,(undefined1)param_3));
                puVar16 = puVar16 + 1;
              }
              for (uVar10 = local_b8 & 3; puVar17 = local_5c, uVar11 = local_b8, uVar10 != 0;
                  uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar16 = (undefined1)param_3;
                puVar16 = (undefined4 *)((int)puVar16 + 1);
              }
              do {
                uVar10 = *puVar17;
                puVar17 = puVar17 + 1;
                uVar11 = uVar11 - 1;
                *(undefined1 *)
                 ((int)&DAT_0078bdd0 + (uVar10 & 0xfff) + (short)(uVar10 >> 0x10) * 0x80) =
                     (undefined1)param_3;
              } while (uVar11 != 0);
            }
            iVar15 = iVar15 + 0x80;
            local_5c = local_5c + 0x80;
            local_58 = local_58 + 0x40;
            local_6c = local_6c + -1;
            local_70 = local_b8;
          } while (local_6c != 0);
        }
        FUN_0041e900(*(undefined4 *)((int)&DAT_00805e08 + local_1c),
                     *(undefined4 *)((int)&DAT_00805e0c + local_1c),local_54,
                     *(undefined4 *)((int)&DAT_00805e14 + local_1c));
      }
      break;
    case 0x11:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) == 0x1000) {
        local_18 = 1;
      }
      else if (((&DAT_0067fe10)[param_1 * 0x368] == DAT_00668ccc) &&
              (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) != 0xfffff000)) {
        DAT_004af678 = 0x1c20;
      }
      break;
    case 0x12:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) == 0x1000) {
        local_18 = 1;
      }
      else if ((DAT_00668ccc == local_8) &&
              (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) != 0xfffff000)) {
        iVar15 = 0x300;
        DAT_004afbb4 = 0xe10;
        DAT_009094b0 = (int)DAT_0066cd60;
        DAT_0066cd60 = 3;
        pbVar7 = DAT_0066cd44;
        do {
          iVar15 = iVar15 + -1;
          *pbVar7 = *pbVar7 >> 2;
          pbVar7 = pbVar7 + 1;
        } while (iVar15 != 0);
        FUN_00494ac0(pbVar8);
        DAT_006df3d4 = 1;
        iVar15 = 0x300;
        pbVar8 = DAT_0066cd44;
        do {
          iVar15 = iVar15 + -1;
          *pbVar8 = *pbVar8 << 2;
          pbVar8 = pbVar8 + 1;
        } while (iVar15 != 0);
      }
      break;
    case 0x13:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        if (-1 < DAT_006e5b38) {
          puVar17 = &DAT_00680498;
          iVar15 = DAT_006e5b38 + 1;
          do {
            if (((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
               ((short)puVar17[-0x19f] != 0)) {
              iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
              iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                *puVar17 = *puVar17 | 0x8000;
                *(undefined2 *)((int)puVar17 + 0x22) = 4000;
                *(undefined2 *)(puVar17 + -0x19d) = 1;
                puVar17[-0x19e] = 0x10000;
              }
            }
            puVar17 = puVar17 + 0x1b4;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x14:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if ((((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
              ((short)puVar17[-0x19f] != 0)) && ((*puVar17 & 0x40000) == 0)) {
            iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
            iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
            if (iVar24 < 0) {
              iVar24 = -iVar24;
            }
            if (iVar31 < 0) {
              iVar31 = -iVar31;
            }
            if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
              *puVar17 = *puVar17 | 0x1000;
              *(undefined2 *)(puVar17 + 7) = 9000;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 0x15:
      local_40 = ((int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10) + -0xa0;
      local_28 = ((int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10) + 0x60;
      local_2c = ((int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10) + 0xa0;
      local_34 = ((int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10) + -0x40;
      iVar15 = 0;
      if (local_40 < local_2c) {
        do {
          iVar31 = local_34;
          if (local_34 < local_28) {
            do {
              if (6 < iVar15) goto switchD_00442204_caseD_1b;
              iVar24 = local_40 >> 5;
              iVar13 = iVar31 >> 5;
              if ((((-1 < iVar24) && (-1 < iVar13)) && (iVar24 < 0x80)) &&
                 (((iVar13 < 0x80 &&
                   (iVar32 = iVar24 * 0x80 + iVar13, (&DAT_008352f0)[iVar32] == '\x01')) &&
                  (*(char *)((int)&DAT_006d3920 + iVar32) == '\0')))) {
                iVar15 = iVar15 + 1;
                DAT_0071667c = 1;
                sVar3 = (short)(local_40 >> 0x15);
                FUN_00424c20(*(uint *)(&DAT_004b6820 + (iVar24 + iVar13 & 7U) * 4) | 0x300,
                             CONCAT22(sVar3,(&DAT_0067fe10)[param_1 * 0x368]),
                             CONCAT22(sVar3,(short)iVar24 << 5),
                             CONCAT22((short)(iVar31 >> 0x15),(short)iVar13 << 5),0);
                DAT_0071667c = 0;
              }
              iVar31 = iVar31 + 0x20;
            } while (iVar31 < local_28);
          }
        } while ((iVar15 < 7) && (local_40 = local_40 + 0x20, local_40 < local_2c));
      }
      break;
    case 0x16:
      local_2c = ((int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10) + 0xa0;
      local_28 = ((int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10) + 0x60;
      local_30 = ((int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10) + -0xa0;
      local_3c = ((int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10) + -0x40;
      iVar15 = 0;
      if (local_3c < local_28) {
        do {
          iVar31 = local_30;
          if (local_30 < local_2c) {
            do {
              if (8 < iVar15) goto switchD_00442204_caseD_1b;
              iVar24 = iVar31 >> 5;
              iVar13 = local_3c >> 5;
              if (((((-1 < iVar24) && (-1 < iVar13)) && (iVar24 < 0x80)) &&
                  ((iVar13 < 0x80 &&
                   (iVar32 = iVar24 * 0x80 + iVar13, (&DAT_008352f0)[iVar32] == '\x01')))) &&
                 (*(char *)((int)&DAT_006d3920 + iVar32) == '\0')) {
                iVar15 = iVar15 + 1;
                DAT_0071667c = 1;
                sVar3 = (short)(iVar31 >> 0x15);
                FUN_00424c20(*(uint *)(&DAT_004b6840 + (iVar13 + -1 + iVar15 + iVar24 & 7U) * 4) |
                             0x400,CONCAT22(sVar3,(&DAT_0067fe10)[param_1 * 0x368]),
                             CONCAT22(sVar3,(short)iVar24 << 5),
                             CONCAT22((short)(local_3c >> 0x15),(short)iVar13 << 5),0);
                DAT_0071667c = 0;
              }
              iVar31 = iVar31 + 0x20;
            } while (iVar31 < local_2c);
          }
        } while ((iVar15 < 9) && (local_3c = local_3c + 0x20, local_3c < local_28));
      }
      break;
    case 0x17:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        DAT_0090a264 = 0xf0;
        DAT_004afbb4 = 5000;
        DAT_009094b0 = (int)DAT_0066cd60;
        DAT_0066cd60 = 4;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x18:
      (&DAT_0067fe20)[param_1 * 0x1b4] =
           (int)*(short *)(&DAT_004c0862 + (short)(&DAT_0067fe12)[param_1 * 0x368] * 0x4c) << 0x12;
      break;
    case 0x19:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) {
        (&DAT_00680498)[param_1 * 0x1b4] = (&DAT_00680498)[param_1 * 0x1b4] | 0x1000;
        (&DAT_006804b4)[param_1 * 0x368] = 9000;
      }
      break;
    case 0x1a:
      iVar15 = param_1 * 0x6d0;
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x1000) == 0) {
        (&DAT_00680498)[param_1 * 0x1b4] = (&DAT_00680498)[param_1 * 0x1b4] | 0x800;
        *(undefined2 *)(&DAT_006804b2 + iVar15) = 3000;
        *(undefined2 *)(&DAT_0067fe72 + iVar15) = 0;
        *(undefined2 *)(&DAT_0067fe74 + iVar15) = 0;
        *(undefined2 *)(&DAT_0067fe88 + iVar15) = 0;
        *(undefined2 *)(&DAT_0067fe92 + iVar15) = 0;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x1d:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if (((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
             ((short)puVar17[-0x19f] != 0)) {
            if ((*puVar17 & 0x1000) == 0) {
              iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
              iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
              if (iVar24 < 0) {
                iVar24 = -iVar24;
              }
              if (iVar31 < 0) {
                iVar31 = -iVar31;
              }
              if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
                *puVar17 = *puVar17 | 0x40000;
                *(undefined2 *)(puVar17 + 10) = 9000;
              }
            }
            else {
              local_18 = 1;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 0x20:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        iVar15 = 0;
        if (0 < DAT_00834f88) {
          iVar31 = (int)DAT_00834f88;
          piVar22 = &DAT_00834a04;
          do {
            iVar24 = *piVar22;
            piVar22 = piVar22 + 1;
            iVar15 = iVar15 + iVar24;
            iVar31 = iVar31 + -1;
          } while (iVar31 != 0);
        }
        iVar31 = (int)DAT_00834f88;
        iVar15 = iVar15 / iVar31;
        if (0 < DAT_00834f88) {
          piVar22 = &DAT_00834a04;
          for (; iVar31 != 0; iVar31 = iVar31 + -1) {
            *piVar22 = iVar15;
            piVar22 = piVar22 + 1;
          }
        }
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x21:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if ((((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
              ((short)puVar17[-0x19f] != 0)) && ((*puVar17 & 0x40000) == 0)) {
            iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
            iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
            if (iVar24 < 0) {
              iVar24 = -iVar24;
            }
            if (iVar31 < 0) {
              iVar31 = -iVar31;
            }
            if ((iVar24 < 0x100) && (iVar31 < 0x100)) {
              *puVar17 = *puVar17 | 0x20000;
              *(undefined2 *)((int)puVar17 + 0x26) = 0;
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 0x22:
    case 0x23:
    case 0x24:
      if (-1 < DAT_006e5b38) {
        puVar17 = &DAT_00680498;
        iVar15 = DAT_006e5b38 + 1;
        do {
          if ((((short)puVar17[-0x1a2] == (&DAT_0067fe10)[param_1 * 0x368]) &&
              ((short)puVar17[-0x19f] != 0)) && ((*puVar17 & 0x40000) == 0)) {
            iVar24 = ((int)puVar17[-0x19c] >> 0x10) - local_c;
            iVar31 = ((int)puVar17[-0x19b] >> 0x10) - local_10;
            if (iVar24 < 0) {
              iVar24 = -iVar24;
            }
            if (iVar31 < 0) {
              iVar31 = -iVar31;
            }
            iVar13 = 0x100;
            if (param_2 == 0x23) {
              iVar13 = 0x120;
            }
            if (param_2 == 0x24) {
              iVar13 = 0x140;
            }
            if ((iVar24 < iVar13) && (iVar31 < iVar13)) {
              *(undefined2 *)((int)puVar17 + -0x36) = 1;
              *puVar17 = *puVar17 | 0x10000;
              *(undefined2 *)(puVar17 + 9) = 5000;
              if (param_2 == 0x23) {
                *(undefined2 *)(puVar17 + 9) = 8000;
              }
              if (param_2 == 0x24) {
                *(undefined2 *)(puVar17 + 9) = 12000;
              }
            }
          }
          puVar17 = puVar17 + 0x1b4;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      break;
    case 0x25:
      if (((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) {
        (&DAT_009094c0)[param_3] = (&DAT_009094c0)[param_3] + 3000;
      }
      break;
    case 0x26:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        local_b0 = (int *)(&DAT_00834a00 + param_3 * 4);
        *local_b0 = *local_b0 +
                    ((int)(*(int *)(&DAT_00834a00 + local_8 * 4) +
                          (*(int *)(&DAT_00834a00 + local_8 * 4) >> 0x1f & 3U)) >> 2);
        iVar15 = *(int *)(&DAT_00834a00 + local_8 * 4);
        *(int *)(&DAT_00834a00 + local_8 * 4) =
             iVar15 - ((int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2);
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x27:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        local_ac = (int *)(&DAT_00834a00 + param_3 * 4);
        piVar22 = (int *)(&DAT_00834a00 + local_8 * 4);
        *local_ac = *local_ac + *piVar22 / 2;
        *piVar22 = *piVar22 - *piVar22 / 2;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x28:
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      (&DAT_00805e44)[param_1 * 0x38] = 0xffc00000;
      break;
    case 0x29:
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      *(undefined4 *)(&DAT_00805ecc + param_1 * 0xe0) = 0x107d0;
      break;
    case 0x2a:
      if (((((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) && (0 < local_8)) &&
         (local_8 <= DAT_00834f88)) {
        (&DAT_0090a240)[param_3] = 0xdac;
        (&DAT_009d62e0)[param_3] = local_8;
      }
      break;
    case 0x2b:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        iVar15 = 5;
        psVar30 = &DAT_0075ba20 + local_8 * 8;
        do {
          bVar33 = DAT_00803c40 == 1;
          sVar3 = (&DAT_004afa58)[DAT_004afad8];
          *psVar30 = sVar3;
          if (bVar33) {
            if (sVar3 == 0xf) {
              *psVar30 = 4;
            }
            if (*psVar30 == 0x11) {
              *psVar30 = 0x20;
            }
            if (*psVar30 == 0x12) {
              *psVar30 = 3;
            }
            if (*psVar30 == 0xf) {
              *psVar30 = 4;
            }
          }
          else {
            if (sVar3 == 0x2a) {
              *psVar30 = 4;
            }
            if (*psVar30 == 0x2d) {
              *psVar30 = 0x20;
            }
          }
          DAT_004afad8 = DAT_004afad8 + 1;
          if (0x3f < DAT_004afad8) {
            DAT_004afad8 = 0;
          }
          psVar30 = psVar30 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x2c:
      psVar30 = &DAT_0075ba20;
      do {
        iVar15 = 5;
        psVar27 = psVar30;
        do {
          bVar33 = DAT_00803c40 == 1;
          sVar3 = (&DAT_004afa58)[DAT_004afad8];
          *psVar27 = sVar3;
          if (bVar33) {
            if (sVar3 == 0xf) {
              *psVar27 = 4;
            }
            if (*psVar27 == 0x11) {
              *psVar27 = 0x20;
            }
            if (*psVar27 == 0x12) {
              *psVar27 = 3;
            }
            if (*psVar27 == 0xf) {
              *psVar27 = 4;
            }
          }
          else {
            if (sVar3 == 0x2a) {
              *psVar27 = 4;
            }
            if (*psVar27 == 0x2d) {
              *psVar27 = 0x20;
            }
          }
          DAT_004afad8 = DAT_004afad8 + 1;
          if (0x3f < DAT_004afad8) {
            DAT_004afad8 = 0;
          }
          psVar27 = psVar27 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        psVar30 = psVar30 + 8;
      } while (psVar30 < &DAT_0075baa0);
      break;
    case 0x2d:
      if (((((&DAT_00680498)[param_1 * 0x1b4] & 0x40000) == 0) && (0 < local_8)) &&
         (local_8 <= DAT_00834f88)) {
        (&DAT_0090a240)[param_3] = 0xdac;
        (&DAT_009d49d0)[param_3] = 1;
        (&DAT_009d62e0)[param_3] = local_8;
      }
      break;
    case 0x2e:
      if ((*(byte *)((int)&DAT_00680498 + param_1 * 0x6d0 + 1) & 0x10) == 0) {
        (&DAT_0092ab00)[(ushort)(&DAT_0067fe10)[param_1 * 0x368] & 7] = 2000;
      }
      else {
        local_18 = 1;
      }
      break;
    case 0x2f:
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      *(undefined4 *)(&DAT_00805ecc + param_1 * 0xe0) = 0x207d0;
      break;
    case 0x30:
      local_8 = (&DAT_00805df0)[param_1 * 0x38];
      *(undefined4 *)(&DAT_00805ecc + param_1 * 0xe0) = 0x307d0;
    }
  }
switchD_00442204_caseD_1b:
  if (local_8 == param_3) {
    _sprintf(&DAT_004dd968,&DAT_00865950,(&PTR_DAT_004baf08)[(&DAT_00835260)[param_3]],
             &DAT_0078b770 + param_3 * 0x80,(&PTR_DAT_004afae0)[param_2]);
  }
  else {
    _sprintf(&DAT_004dd968,&DAT_00865900,(&PTR_DAT_004baf08)[(&DAT_00835260)[param_3]],
             &DAT_0078b770 + param_3 * 0x80,(&PTR_DAT_004afae0)[param_2],
             &DAT_0078b770 + local_8 * 0x80);
  }
  iVar15 = DAT_0092ab58 * 0x100;
  uVar10 = 0xffffffff;
  pcVar20 = &DAT_004dd968;
  do {
    pcVar25 = pcVar20;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar25 = pcVar20 + 1;
    cVar1 = *pcVar20;
    pcVar20 = pcVar25;
  } while (cVar1 != '\0');
  uVar10 = ~uVar10;
  pcVar20 = pcVar25 + -uVar10;
  pcVar25 = &DAT_0090a5c0 + iVar15;
  for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
    *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
    pcVar20 = pcVar20 + 4;
    pcVar25 = pcVar25 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar25 = *pcVar20;
    pcVar20 = pcVar20 + 1;
    pcVar25 = pcVar25 + 1;
  }
  (&DAT_0090a5ed)[iVar15] = 0;
  DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
  if (DAT_0092ab58 == DAT_009d5a44) {
    DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
  }
  DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
  if (((DAT_0083a3f0 != 1) || (iVar15 = _strncmp(&DAT_004dd968,&DAT_00864640,8), iVar15 == 0)) ||
     (iVar15 = _strncmp((char *)&DAT_0066d1a0,&DAT_00864640,8), iVar15 != 0)) {
    uVar10 = 0xffffffff;
    DAT_0083a3f0 = 1;
    DAT_00834f80 = 0;
    pcVar20 = &DAT_004dd968;
    do {
      pcVar25 = pcVar20;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar25 = pcVar20 + 1;
      cVar1 = *pcVar20;
      pcVar20 = pcVar25;
    } while (cVar1 != '\0');
    uVar10 = ~uVar10;
    pcVar20 = pcVar25 + -uVar10;
    pcVar25 = (char *)&DAT_0066d1a0;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
      pcVar20 = pcVar20 + 4;
      pcVar25 = pcVar25 + 4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pcVar25 = *pcVar20;
      pcVar20 = pcVar20 + 1;
      pcVar25 = pcVar25 + 1;
    }
    iVar15 = -1;
    pcVar20 = &DAT_004dd968;
    do {
      if (iVar15 == 0) break;
      iVar15 = iVar15 + -1;
      cVar1 = *pcVar20;
      pcVar20 = pcVar20 + 1;
    } while (cVar1 != '\0');
    DAT_008350e0 = ~(ushort)iVar15 - 1;
    DAT_00859526 = DAT_008350e0 * 2 + 300;
  }
  if ((param_2 != 0x1b) && (param_2 != 0x31)) {
    if ((param_2 == 0x10) ||
       ((((param_2 == 0x28 || (param_2 == 0x29)) || (param_2 == 0x2f)) || (param_2 == 0x30)))) {
      local_c = (int)((&DAT_00805e10)[param_1 * 0x38] << 5) / 2 +
                (&DAT_00805e08)[param_1 * 0x38] * 0x20;
      local_10 = (int)((&DAT_00805e14)[param_1 * 0x38] << 5) / 2 +
                 (&DAT_00805e0c)[param_1 * 0x38] * 0x20;
    }
    else {
      local_c = (int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x10;
      local_10 = (int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x10;
    }
    sVar3 = FUN_00429de0(0x1c,1,local_c,local_10,0xffffffff,0xffffffff);
    iVar15 = (int)sVar3;
    if (iVar15 != -1) {
      (&DAT_0071b65c)[iVar15 * 0x104] = param_2 + 500;
      *(int *)(&DAT_0071b6b0 + iVar15 * 0x410) = local_c;
      *(int *)(&DAT_0071b6b4 + iVar15 * 0x410) = local_10;
    }
    if (local_18 == 1) {
      _sprintf(&DAT_004dd968,&DAT_008659f0,(&PTR_DAT_004baf08)[(&DAT_00835260)[local_8]],
               &DAT_0078b770 + local_8 * 0x80);
      iVar15 = DAT_0092ab58 * 0x100;
      uVar10 = 0xffffffff;
      pcVar20 = &DAT_004dd968;
      do {
        pcVar25 = pcVar20;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar25 = pcVar20 + 1;
        cVar1 = *pcVar20;
        pcVar20 = pcVar25;
      } while (cVar1 != '\0');
      uVar10 = ~uVar10;
      pcVar20 = pcVar25 + -uVar10;
      pcVar25 = &DAT_0090a5c0 + iVar15;
      for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar25 = *(undefined4 *)pcVar20;
        pcVar20 = pcVar20 + 4;
        pcVar25 = pcVar25 + 4;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar25 = *pcVar20;
        pcVar20 = pcVar20 + 1;
        pcVar25 = pcVar25 + 1;
      }
      (&DAT_0090a5ed)[iVar15] = 0;
      DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
      if (DAT_0092ab58 == DAT_009d5a44) {
        DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
      }
      DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
    }
  }
  switch(param_2) {
  case 2:
    uVar12 = DAT_008596bc;
    uVar34 = DAT_0071a0fc;
    break;
  case 3:
  case 0x1c:
    uVar12 = DAT_008596b4;
    uVar34 = DAT_0071a0f4;
    break;
  case 4:
  case 10:
  case 0x32:
  case 0x33:
    uVar12 = DAT_008596b0;
    uVar34 = DAT_0071a0f0;
    break;
  default:
    FUN_0046f6b0(DAT_00859678,DAT_0071a0b8,0x40,0x20);
    uVar35 = 0xa0;
    uVar12 = DAT_0085967c;
    uVar34 = DAT_0071a0bc;
    goto LAB_00444769;
  case 8:
  case 0xe:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1d:
  case 0x2c:
  case 0x2e:
    uVar12 = DAT_008596ac;
    uVar34 = DAT_0071a0ec;
    break;
  case 0x10:
    uVar12 = DAT_008596c0;
    uVar34 = DAT_0071a100;
  }
  uVar35 = 0x20;
LAB_00444769:
  FUN_0046f6b0(uVar12,uVar34,0x40,uVar35);
  if ((param_2 != 0x1b) && (param_2 != 0x31)) {
    _DAT_009d6338 = local_c >> 5;
    _DAT_009d6334 = local_10 >> 5;
    iVar15 = _DAT_009d6338 + -1;
    DAT_00909534 = _DAT_009d6338 + 1;
    iVar31 = _DAT_009d6334 + -1;
    DAT_00994974 = _DAT_009d6334 + 1;
    if (iVar15 < 0) {
      iVar15 = 0;
    }
    if (iVar31 < 0) {
      iVar31 = 0;
    }
    if (0x7f < DAT_00909534) {
      DAT_00909534 = 0x7f;
    }
    if (0x7f < DAT_00994974) {
      DAT_00994974 = 0x7f;
    }
    DAT_0090a9c8 = (undefined4)((longlong)((ulonglong)(uint)(int)(short)iVar15 << 0x20) / 0x1e0000);
    DAT_009d6b5c = (undefined4)((longlong)((ulonglong)(uint)(int)(short)iVar31 << 0x20) / 0x1e0000);
    DAT_0090a9c4 = -(int)((longlong)
                          ((ulonglong)(uint)(DAT_00909534 * -0x10000 + 0x7f0000 >> 0x10) << 0x20) /
                         0x1e0000);
    DAT_00909530 = 0;
    DAT_00994970 = 0;
    DAT_009d6300 = 0x3c;
    iVar24 = _DAT_009d6338 + -5;
    iVar31 = _DAT_009d6334 + -5;
    DAT_009d6b58 = -(int)((longlong)
                          ((ulonglong)(uint)(DAT_00994974 * -0x10000 + 0x7f0000 >> 0x10) << 0x20) /
                         0x1e0000);
    DAT_00909534 = 0x7f0000;
    DAT_00994974 = 0x7f0000;
    local_24 = 0;
    iVar15 = DAT_006cc850 * 0xb;
    if (0 < iVar15) {
      iVar13 = iVar31 + iVar24 * 0x80;
      local_48 = &DAT_00672d80 + iVar13;
      local_44 = (uint *)(&DAT_0077b770 + iVar13 * 4);
      do {
        iVar32 = 0;
        if (0 < iVar15) {
          local_4c = local_44;
          iVar9 = local_24 + iVar24;
          puVar19 = local_48;
          do {
            if (((0 < iVar9) && (iVar18 = iVar31 + iVar32, 0 < iVar18)) &&
               ((iVar9 < 0x80 && (iVar18 < 0x80)))) {
              iVar18 = iVar32 / DAT_006cc850;
              *(undefined1 *)((int)&DAT_0070e620 + iVar13 + iVar32) = 3;
              *(undefined1 *)((int)&DAT_00668cf0 + iVar13 + iVar32) = 2;
              iVar18 = local_24 / DAT_006cc850 + iVar18 * 0xb;
              if ((&DAT_004bb369)[iVar18] != '\0') {
                (&DAT_0066da10)[iVar13 + iVar32] = 3;
                if ((*puVar19 < 0xff) &&
                   (uVar4 = (ushort)((byte)(&DAT_004bb738)[iVar18] >> 3) + *puVar19,
                   *puVar19 = uVar4, 0xfe < uVar4)) {
                  *puVar19 = 0xfe;
                }
                iVar18 = (*local_4c & 0xfff) * 0x80 + (int)(short)(*local_4c >> 0x10);
                (&DAT_0085a760)[iVar18] = (&DAT_006e0e80)[iVar18];
              }
            }
            puVar19 = puVar19 + 1;
            local_4c = local_4c + 1;
            iVar32 = iVar32 + 1;
          } while (iVar32 < iVar15);
        }
        iVar13 = iVar13 + 0x80;
        local_48 = local_48 + 0x80;
        local_44 = local_44 + 0x80;
        local_24 = local_24 + 1;
      } while (local_24 < iVar15);
    }
  }
  return;
LAB_00442cd1:
  piVar22 = piVar22 + 0x38;
  iVar31 = iVar31 + 1;
  if (DAT_0083a402 < iVar31) goto LAB_00442d89;
  goto LAB_00442c9d;
}



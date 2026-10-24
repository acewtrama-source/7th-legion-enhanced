
void FUN_00451b00(void)

{
  ushort *puVar1;
  short *psVar2;
  undefined2 *puVar3;
  char *pcVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  ushort uVar9;
  undefined4 *puVar10;
  int *piVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  undefined4 *puVar16;
  undefined4 *unaff_FS_OFFSET;
  bool bVar17;
  undefined *puVar18;
  int aiStack_2bc [107];
  uint *local_110;
  int local_10c;
  int local_104;
  int local_100;
  uint local_f8;
  int local_f4;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  ushort local_d0;
  int local_cc;
  uint local_c8;
  int local_c4;
  int local_bc;
  int local_b8;
  int local_b4;
  byte *local_b0;
  int local_ac;
  ushort local_a8;
  undefined4 local_a4;
  undefined4 *local_9c;
  int local_8c;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  short *local_6c;
  int local_68;
  ushort *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  ushort local_34;
  ushort local_32;
  short local_30;
  short local_2e;
  ushort local_2c;
  short local_2a;
  short local_28;
  short local_26;
  short local_22;
  short local_20;
  ushort local_1e;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_004aa368;
  puStack_10 = &LAB_0049c890;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xfffffd38;
  _strncpy(&DAT_004e7358 + (short)DAT_00507488 * 0x400,s_UpDateVehicles____004b7edc,0x100);
  DAT_00507488 = DAT_00507488 + 1 & 0x3f;
  local_8 = 0;
  puVar10 = (undefined4 *)&DAT_00804320;
  do {
    *(undefined2 *)puVar10 = 0;
    puVar10 = (undefined4 *)((int)puVar10 + 2);
  } while (puVar10 < &DAT_00804330);
  local_40 = 0;
  if (0 < DAT_00a236a0) {
    piVar11 = aiStack_2bc;
    do {
      *piVar11 = 0;
      piVar11 = piVar11 + 1;
      local_40 = local_40 + 1;
    } while ((int)local_40 < DAT_00a236a0);
  }
  if (DAT_006df0f2 == 0) {
    puVar10 = &DAT_0079dde0;
    for (iVar13 = 0x800; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    DAT_006df0f2 = DAT_006df0f2 + 1;
  }
  if (-1 < DAT_006e5b38) {
    local_20 = 0;
    iVar13 = 0;
    do {
      piVar11 = (int *)((int)&DAT_009094c0 + iVar13);
      *piVar11 = *piVar11 + -1;
      if (*piVar11 < 0) {
        *(undefined4 *)((int)&DAT_009094c0 + iVar13) = 0;
      }
      piVar11 = (int *)((int)&DAT_0092ab00 + iVar13);
      *piVar11 = *piVar11 + -1;
      if (*piVar11 < 0) {
        *(undefined4 *)((int)&DAT_0092ab00 + iVar13) = 0;
      }
      piVar11 = (int *)((int)&DAT_0090a240 + iVar13);
      *piVar11 = *piVar11 + -1;
      if (*piVar11 < 0) {
        *(undefined4 *)((int)&DAT_0090a240 + iVar13) = 0;
      }
      iVar13 = iVar13 + 4;
    } while (iVar13 < 0x20);
    local_40 = 0;
    if (-1 < DAT_006e5b38) {
      puVar15 = &DAT_0067fe10;
      local_8c = 0;
      do {
        if (*(int *)(puVar15 + 4) < 1) {
LAB_00451c98:
          if (*puVar15 != 0) goto LAB_00451ca2;
        }
        else {
          if (*puVar15 == 0) {
            *(int *)(puVar15 + 4) = *(int *)(puVar15 + 4) + -1;
            goto LAB_00451c98;
          }
LAB_00451ca2:
          if (puVar15[6] != 0) {
            local_1e = *puVar15;
            if (0x59 < (short)*puVar15) {
              local_1e = 7;
            }
            local_34 = puVar15[1];
            local_32 = puVar15[0x4a];
            local_c4 = (short)puVar15[1] * 0x4c;
            uVar9 = puVar15[0x337];
            if (0 < (short)uVar9) {
              puVar15[0x337] = puVar15[0x337] - DAT_006df0f8;
              uVar9 = puVar15[0x337];
            }
            if ((short)uVar9 < 0) {
              puVar15[0x337] = 0;
            }
            if ((((puVar15[0x344] & 0x10) != 0) && (*(int *)(puVar15 + 0x16) == 0)) &&
               (*(int *)(puVar15 + 0x18) == 0)) {
              (&DAT_009094c0)[(short)local_1e] = (&DAT_009094c0)[(short)local_1e] + 1;
            }
            if ((puVar15[0x344] & 8) != 0) {
              puVar15[0x32a] = 0;
            }
            if (*(short *)(&DAT_004c0874 + (short)puVar15[1] * 0x4c) == 0) {
              if (puVar15[0x37] == 5) {
                puVar15[0x37] = 4;
              }
              if (puVar15[0x37] == 8) {
                puVar15[0x37] = 7;
              }
            }
            local_44 = 0;
            local_6c = &DAT_0068049c + local_8c;
            local_110 = (uint *)(puVar15 + 0x344);
            do {
              local_f8 = 1 << ((byte)local_44 & 0x1f);
              if ((((*local_110 & local_f8) == 1 << ((byte)local_44 & 0x1f)) && (0 < *local_6c)) &&
                 (sVar12 = *local_6c - DAT_006df0f8, *local_6c = sVar12, sVar12 < 1)) {
                *local_6c = 0;
                *(uint *)(puVar15 + 0x344) = *(uint *)(puVar15 + 0x344) & ~local_f8;
                if ((local_44 == 5) || (local_44 == 0xf)) {
                  puVar15[10] = *(ushort *)(&DAT_004c0862 + (short)puVar15[1] * 0x4c);
                  puVar15[10] = puVar15[10] + puVar15[0x57] * 2;
                  local_f4 = (short)puVar15[10] * 0x10000;
                  if ((local_f4 < *(int *)(puVar15 + 8)) || (local_44 == 0xf)) {
                    *(int *)(puVar15 + 8) = local_f4;
                  }
                }
                if (local_44 == 0x10) {
                  puVar15[0x329] = 0;
                }
              }
              local_6c = local_6c + 1;
              local_44 = local_44 + 1;
            } while (local_44 < 0x20);
            if ((local_1e != DAT_0075ba10) &&
               ((((DAT_008464ec == 0 || (DAT_008464ec == 3)) && (puVar15[0x31] == 3)) &&
                (puVar15[0x23] != 0xffff)))) {
              if ((&DAT_00805df0)[(short)puVar15[0x23] * 0x38] == (int)(short)DAT_0075ba10) {
                DAT_008464ec = 1;
              }
              DAT_007733f8 = 0;
            }
            if (puVar15[0x366] != 0) {
              if ((puVar15[0x31] == 3) || (puVar15[0x31] == 2)) {
                puVar15[0x31] = 0;
              }
              puVar15[0x4a] = 0;
              *(int *)(puVar15 + 8) = *(int *)(puVar15 + 8) + -0x8000;
            }
            if ((puVar15[1] == 0x11) && (0 < *(int *)(puVar15 + 8))) {
              *(int *)(puVar15 + 8) = *(int *)(puVar15 + 8) + 0x2000;
              if ((short)puVar15[10] * 0x10000 < *(int *)(puVar15 + 8)) {
                *(int *)(puVar15 + 8) = (short)puVar15[10] * 0x10000;
              }
            }
            local_e4 = (int)(short)local_1e;
            if (0 < (int)(&DAT_009d5a70)[local_e4]) {
              *(int *)(puVar15 + 8) = *(int *)(puVar15 + 8) + -0x280;
            }
            if (((local_1e == DAT_006df0f0) && (puVar15[0x4a] != 0)) &&
               ((((int)DAT_006df0f2 ^ local_40) & 3) == 0)) {
              local_e8 = (*(int *)(puVar15 + 0xc) >> 0x15) / 2;
              local_54 = (*(int *)(puVar15 + 0xe) >> 0x15) / 2;
              local_50 = ((short)puVar15[0x49] + -0x10 >> 5) / 2;
              iVar13 = *(int *)(&DAT_004c173c + (short)puVar15[0x4a] * 0x20);
              local_48 = iVar13 + 0x18000 >> 0x10;
              local_4c = local_e8 - local_50;
              local_e8 = local_e8 + local_50;
              if ((int)local_4c <= local_e8) {
                local_78 = local_4c * 0x40;
                local_10c = local_54 - local_50;
                do {
                  local_74 = local_10c;
                  local_ec = local_50 + local_54;
                  while (local_74 <= local_50 + local_54) {
                    if (((-1 < local_78) && (-1 < local_74)) &&
                       ((local_78 < 0x1000 && (local_74 < 0x40)))) {
                      psVar2 = (short *)((int)&DAT_0079dde0 + (local_78 + local_74) * 2);
                      local_48._0_2_ = (short)((uint)(iVar13 + 0x18000) >> 0x10);
                      *psVar2 = *psVar2 + (short)local_48;
                    }
                    local_74 = local_74 + 1;
                  }
                  local_78 = local_78 + 0x40;
                  local_4c = local_4c + 1;
                } while ((int)local_4c <= local_e8);
              }
            }
            if ((DAT_006df138 != 0) && (local_1e == DAT_00668ccc)) {
              *(int *)(puVar15 + 8) = (int)(short)puVar15[10] << 0x10;
            }
            if (local_32 != 0) {
              (&DAT_00804320)[local_e4] = (&DAT_00804320)[local_e4] + 1;
            }
            if (0 < (short)puVar15[0x339]) {
              puVar1 = puVar15 + 0x339;
              *puVar1 = *puVar1 - DAT_006df0f8;
              if ((short)*puVar1 < 0) {
                puVar15[0x339] = 0;
              }
            }
            puVar15[0x4d] = puVar15[0x4c];
            if ((((*(byte *)((int)puVar15 + 0x689) & 2) == 0) || ((DAT_006df3b0 & 3) == 0)) &&
               (0 < (short)puVar15[0x4c])) {
              puVar15[0x4c] = puVar15[0x4c] - DAT_006df0f8;
              local_48 = (int)(short)puVar15[0x57] - 2;
              if ((0 < (int)local_48) && ((DAT_006df3b0 & 7) < local_48)) {
                puVar15[0x4c] = puVar15[0x4c] - DAT_006df0f8;
              }
              if ((puVar15[0x344] & 2) != 0) {
                puVar15[0x4c] = puVar15[0x4c] - DAT_006df0f8;
              }
              if ((*(byte *)((int)puVar15 + 0x689) & 4) != 0) {
                puVar15[0x4c] = puVar15[0x4c] - (DAT_006df0f8 + 1);
              }
              if ((0 < (int)(&DAT_009d5a70)[*puVar15 & 7]) && (8 < (short)puVar15[0x4c])) {
                puVar15[0x4c] = 8;
              }
              if ((short)puVar15[0x4c] < 0) {
                puVar15[0x4c] = 0;
              }
            }
            local_e0 = *(int *)(puVar15 + 0xc) >> 0x15;
            local_dc = *(int *)(puVar15 + 0xe) >> 0x15;
            local_60 = ((*(short *)(&DAT_004c085e + (short)puVar15[1] * 0x4c) >> 5) + 1 >> 1) + 2;
            local_3c = local_e0 - local_60;
            local_d4 = local_e0 + local_60;
            if (local_3c <= local_d4) {
              local_58 = local_3c * 0x80;
              local_104 = local_dc - local_60;
              do {
                local_54 = local_104;
                local_d8 = local_dc + local_60;
                while (local_54 <= local_dc + local_60) {
                  if ((((-1 < local_58) && (-1 < local_54)) && (local_58 < 0x4000)) &&
                     (local_54 < 0x80)) {
                    if (*(byte *)((int)&DAT_006d3920 + local_54 + local_58) - local_40 == 1) {
                      *(undefined1 *)((int)&DAT_006d3920 + local_54 + local_58) = 0;
                    }
                    if (*(byte *)((int)&DAT_0083a4d0 + local_54 + local_58) - local_40 == 1) {
                      *(undefined1 *)((int)&DAT_0083a4d0 + local_54 + local_58) = 0;
                    }
                  }
                  local_54 = local_54 + 1;
                }
                local_58 = local_58 + 0x80;
                local_3c = local_3c + 1;
              } while (local_3c <= local_d4);
            }
            if (((local_20 == 0) && (puVar15[0x4a] != 0)) && (puVar15[0x23] != 0xffff)) {
              local_d0 = *puVar15;
              if (DAT_00668ccc != local_d0) {
                local_cc = (int)(short)DAT_00668ccc;
                if (((&DAT_00805df0)[(short)puVar15[0x23] * 0x38] == local_cc) &&
                   (puVar15[0x31] == 3)) {
                  if (DAT_004b97e8 < 1) {
                    if (DAT_009094ac == -1) {
                      DAT_009094ac = 0;
                      DAT_0090a9c0 = 0;
                      if (DAT_00803c40 == 1) {
                        puVar18 = &DAT_0085fa00;
                      }
                      else {
                        local_c8 = local_d0 & 7;
                        _sprintf(&DAT_0090a9d0,&DAT_0085fa50,
                                 (&PTR_DAT_004baf08)[(&DAT_00835260)[local_c8]],
                                 &DAT_0078b770 + local_c8 * 0x80,&DAT_0078b770 + local_cc * 0x80);
                        puVar18 = &DAT_0090a9d0;
                      }
                      FUN_0041fff0(puVar18);
                    }
                    local_20 = 1;
                    FUN_0046f640(DAT_008595b4,DAT_00719ff4,0x40);
                    FUN_0041fcd0(&DAT_0085faa0,200);
                  }
                  DAT_004b97e8 = 3000;
                }
              }
            }
            if ((puVar15[0x46] == 1) && (puVar15[0x3c] != 0xffff)) {
              if (puVar15[0x6b] != 0xffff) {
                (&DAT_006e75c0)[(short)puVar15[0x6b] * 0x177a] = 0xffff;
                puVar15[0x6b] = 0xffff;
              }
              puVar15[0x31] = puVar15[0x3c];
              puVar15[0x20] = puVar15[0x3d];
              puVar15[0x21] = puVar15[0x3e];
              puVar15[0x23] = puVar15[0x3f];
              puVar15[0x24] = puVar15[0x40];
              puVar15[0x3c] = 0xffff;
            }
            if ((puVar15[0x33a] != 0) && ((DAT_006df3b0 & 0x7f) == 0)) {
              puVar15[0x33b] = puVar15[0x33b] + 1;
              if ((short)puVar15[0x33c] < (short)puVar15[0x33b]) {
                puVar15[0x33b] = puVar15[0x33c];
              }
            }
            if ((DAT_0070db34 == 3) && (local_44 = 0, 0 < DAT_00a236a0)) {
              local_68 = 0;
              do {
                if (*(int *)((int)aiStack_2bc + local_68) == 0) {
                  local_3c = *(int *)((int)&DAT_00a236b0 + local_68);
                  local_54 = *(int *)(&DAT_00a23840 + local_68);
                  if (local_3c != -1) {
                    local_3c = local_3c - (*(int *)(puVar15 + 0xc) >> 0x15);
                    local_54 = *(int *)(&DAT_00a23840 + local_68) -
                               (*(int *)(puVar15 + 0xe) >> 0x15);
                    if (local_3c < 0) {
                      local_3c = -local_3c;
                    }
                    if (local_54 < 0) {
                      local_54 = -local_54;
                    }
                    if ((local_3c < 6) && (local_54 < 6)) {
                      *(undefined4 *)((int)aiStack_2bc + local_68) = 1;
                    }
                  }
                }
                local_68 = local_68 + 4;
                local_44 = local_44 + 1;
              } while (local_44 < DAT_00a236a0);
            }
            local_30 = (short)((uint)*(undefined4 *)(puVar15 + 0xc) >> 0x10);
            local_2e = (short)((uint)*(undefined4 *)(puVar15 + 0xe) >> 0x10);
            local_2c = puVar15[0x32b];
            local_2a = (short)((uint)*(undefined4 *)(puVar15 + 0x1a) >> 0x10);
            local_28 = (short)((uint)*(undefined4 *)(puVar15 + 0x28) >> 0x10);
            local_26 = (short)(*(int *)(puVar15 + 0x1c) >> 10);
            if ((((*(byte *)((int)puVar15 + 0x689) & 2) == 0) || ((DAT_006df3b0 & 3) == 0)) &&
               ((*(byte *)((int)puVar15 + 0x689) & 0x80) == 0)) {
              if ((puVar15[0x344] & 1) != 0) {
                (**(code **)(puVar15 + 100))(local_40);
              }
              if ((*puVar15 != 0) && (puVar15[6] != 0)) {
                if ((*(byte *)((int)puVar15 + 0x689) & 4) != 0) {
                  if (*puVar15 == 0) goto LAB_00452c6f;
                  if (puVar15[6] != 0) {
                    (**(code **)(puVar15 + 100))(local_40);
                  }
                }
                if (((*puVar15 != 0) && (puVar15[6] != 0)) && (*puVar15 != 0)) {
                  if (puVar15[6] != 0) {
                    _strncpy(&DAT_004f7358 + (DAT_00507474 & 0x3f) * 0x400,
                             s___Vehicles_i__update__i__004b9d88,0x100);
                    DAT_00507474 = DAT_00507474 + 1 & 0x3f;
                    (**(code **)(puVar15 + 100))(local_40);
                  }
                  goto LAB_0045266d;
                }
              }
            }
            else {
LAB_0045266d:
              if ((*puVar15 != 0) && (puVar15[6] != 0)) {
                puVar15[0x335] = 4;
                if (*(int *)(puVar15 + 0xc) >> 0x10 != (int)local_30) {
                  puVar15[0x335] = 4;
                }
                if (*(int *)(puVar15 + 0xe) >> 0x10 != (int)local_2e) {
                  puVar15[0x335] = 4;
                }
                if (puVar15[0x32b] != local_2c) {
                  puVar15[0x335] = 4;
                }
                if (*(int *)(puVar15 + 0x1a) >> 0x10 != (int)local_2a) {
                  puVar15[0x335] = 4;
                }
                if (*(int *)(puVar15 + 0x28) >> 0x10 != (int)local_28) {
                  puVar15[0x335] = 4;
                }
                if (*(int *)(puVar15 + 0x1c) >> 10 != (int)local_26) {
                  puVar15[0x335] = 4;
                }
                local_4c = 0;
                if (DAT_0075ba10 == *puVar15) {
                  local_4c = 1;
                }
                local_4c = (uint)(DAT_0075ba10 == *puVar15);
                if (puVar15[0x31] == 3) {
                  if (puVar15[0x24] != 0xffff) {
                    local_4c = 1;
                  }
                  if (puVar15[0x23] != 0xffff) {
                    local_4c = 1;
                  }
                }
                if ((puVar15[0x50] != 0xffff) &&
                   ((&DAT_0067fe10)[(short)puVar15[0x50] * 0x368] == DAT_0075ba10)) {
                  local_4c = 1;
                }
                if ((*puVar15 == 0) || (puVar15[6] == 0)) {
                  local_4c = 0;
                }
                if (local_4c != 0) {
                  local_50 = (int)*(short *)(&DAT_004c086a + local_c4);
                  if ((((*(int *)(puVar15 + 0x16) == 0) && (*(int *)(puVar15 + 0x18) == 0)) &&
                      (puVar15[0x31] == 0)) &&
                     (local_50 = *(short *)(&DAT_004c086a + local_c4) + 1, 0x10 < local_50)) {
                    local_50 = 0x10;
                  }
                  local_4c = (*(int *)(puVar15 + 0xc) >> 0x15) + DAT_006cc850 * -5;
                  iVar13 = (*(int *)(puVar15 + 0xe) >> 0x15) + DAT_006cc850 * -5;
                  local_74 = iVar13;
                  local_3c = 0;
                  if (0 < DAT_006cc850 * 0xb) {
                    local_7c = local_4c * 0x80;
                    do {
                      local_54 = 0;
                      if (0 < DAT_006cc850 * 0xb) {
                        local_bc = local_7c + iVar13;
                        local_9c = (undefined4 *)(&DAT_0077b770 + local_bc * 4);
                        local_64 = &DAT_00672d80 + local_bc;
                        local_b8 = local_3c + local_4c;
                        local_100 = local_3c + local_4c;
                        do {
                          iVar7 = local_54;
                          if (((-1 < local_100) && (-1 < iVar13 + local_54)) &&
                             ((local_b8 < 0x80 &&
                              ((iVar13 + local_54 < 0x80 &&
                               (local_b4 = local_50 * 0xb,
                               (&DAT_004baf28)
                               [local_3c / DAT_006cc850 +
                                (local_50 * 0xb + local_54 / DAT_006cc850) * 0xb] != '\0')))))) {
                            local_b0 = &DAT_0066da10 + iVar13 + local_7c + local_54;
                            if (((&DAT_0066da10)[iVar13 + local_7c + local_54] & 1) == 0) {
                              FUN_0041e900((short)local_4c + (short)local_3c + -1,
                                           CONCAT22((short)((uint)(iVar13 + local_54) >> 0x10),
                                                    (short)(iVar13 + local_54) + -1),3,3);
                            }
                            local_80 = iVar7 / DAT_006cc850;
                            local_ac = local_3c / DAT_006cc850;
                            *local_b0 = (&DAT_004baf28)[local_ac + (local_b4 + local_80) * 0xb];
                            local_a8 = *local_64;
                            if ((local_a8 < 0xff) &&
                               (uVar9 = ((byte)(&DAT_004bb738)[local_ac + local_80 * 0xb] >> 3) +
                                        local_a8, *local_64 = uVar9, 0xfe < uVar9)) {
                              *local_64 = 0xfe;
                            }
                            local_a4 = *local_9c;
                            uVar6 = local_a4;
                            local_22 = (short)((uint)local_a4 >> 0x10);
                            iVar14 = (int)local_22 + (short)local_a4 * 0x80;
                            (&DAT_0085a760)[iVar14] = (&DAT_006e0e80)[iVar14];
                            local_a4 = uVar6;
                          }
                          local_9c = local_9c + 1;
                          local_64 = local_64 + 1;
                          local_54 = iVar7 + 1;
                        } while (local_54 < DAT_006cc850 * 0xb);
                      }
                      local_7c = local_7c + 0x80;
                      local_3c = local_3c + 1;
                    } while (local_3c < DAT_006cc850 * 0xb);
                  }
                }
                if (puVar15[0x31] == 0) {
                  *(int *)(puVar15 + 0x324) = *(int *)(puVar15 + 0x324) + (int)DAT_006df0f8;
                  puVar15[0x326] = 0;
                  puVar15[0x327] = 0;
                }
                else {
                  puVar15[0x324] = 0;
                  puVar15[0x325] = 0;
                }
                if ((((*(short *)(&DAT_004c0874 + (short)puVar15[1] * 0x4c) != 0) &&
                     (*(int *)(puVar15 + 8) <= ((short)puVar15[10] / 3) * 0x10000)) &&
                    (0 < *(int *)(puVar15 + 0x1c))) &&
                   ((*(int *)(puVar15 + 8) < 0x30000 &&
                    (iVar13 = *(int *)(puVar15 + 0x1c) + DAT_006df0f8 * -0x1000,
                    *(int *)(puVar15 + 0x1c) = iVar13, iVar13 < 1)))) {
                  puVar15[8] = 0;
                  puVar15[9] = 0;
                }
                if (*(int *)(puVar15 + 8) < 1) {
                  if (*puVar15 == DAT_00668ccc) {
                    FUN_0046f640(DAT_008595f0,DAT_0071a030,0x40);
                    if ((puVar15[1] == 0) || (puVar15[1] == 1)) {
                      FUN_0041fcd0(s_Ore_Carier_Destroyed__004b9d70,0xb4);
                    }
                    else {
                      FUN_0041fa90(&DAT_0085faf0,0xb4);
                    }
                  }
                  FUN_0042d420(local_40);
                }
                else if ((puVar15[0x31] != 0x14) && (puVar15[6] != 0)) {
                  local_3c = *(int *)(puVar15 + 0xc) >> 0x15;
                  local_54 = *(int *)(puVar15 + 0xe) >> 0x15;
                  cVar8 = (char)local_40;
                  if ((-1 < local_3c) &&
                     (((-1 < local_54 && (local_3c < 0x80)) && (local_54 < 0x80)))) {
                    if (*(int *)(puVar15 + 0x1c) == 0) {
                      local_5c = local_3c * 0x80 + local_54;
                      if (*(char *)((int)&DAT_006d3920 + local_5c) == '\0') {
                        *(char *)((int)&DAT_006d3920 + local_5c) = cVar8 + '\x01';
                      }
                      if (*(short *)(&DAT_004c0874 + (short)puVar15[1] * 0x4c) != 0) {
                        if ((&DAT_006d38a0)[local_5c] == '\0') {
                          (&DAT_006d38a0)[local_5c] = cVar8 + '\x01';
                        }
                        if ((&DAT_006d39a0)[local_5c] == '\0') {
                          (&DAT_006d39a0)[local_5c] = cVar8 + '\x01';
                        }
                      }
                    }
                    else {
                      pcVar4 = (char *)((int)&DAT_0083a4d0 + local_54 + local_3c * 0x80);
                      if (*pcVar4 == '\0') {
                        *pcVar4 = cVar8 + '\x01';
                      }
                    }
                  }
                  iVar13 = *(int *)(puVar15 + 0x16);
                  bVar17 = false;
                  if (iVar13 < 0) {
                    local_3c = local_3c + -1;
                    iVar13 = *(int *)(puVar15 + 0x16);
                    bVar17 = iVar13 < 0;
                  }
                  if (iVar13 != 0 && !bVar17) {
                    local_3c = local_3c + 1;
                  }
                  iVar13 = *(int *)(puVar15 + 0x18);
                  bVar17 = false;
                  if (iVar13 < 0) {
                    local_54 = local_54 + -1;
                    iVar13 = *(int *)(puVar15 + 0x18);
                    bVar17 = iVar13 < 0;
                  }
                  if (iVar13 != 0 && !bVar17) {
                    local_54 = local_54 + 1;
                  }
                  if (((-1 < local_3c) && (-1 < local_54)) &&
                     ((local_3c < 0x80 && (local_54 < 0x80)))) {
                    if (*(int *)(puVar15 + 0x1c) == 0) {
                      pcVar4 = (char *)((int)&DAT_006d3920 + local_54 + local_3c * 0x80);
                      cVar5 = *pcVar4;
                    }
                    else {
                      pcVar4 = (char *)((int)&DAT_0083a4d0 + local_54 + local_3c * 0x80);
                      cVar5 = *pcVar4;
                    }
                    if (cVar5 == '\0') {
                      *pcVar4 = cVar8 + '\x01';
                    }
                  }
                }
                if (*puVar15 != 0) {
                  puVar15[0x50] = 0xffff;
                  puVar15[0x51] = 0xffff;
                }
              }
            }
          }
        }
LAB_00452c6f:
        puVar15 = puVar15 + 0x368;
        local_8c = local_8c + 0x368;
        local_40 = local_40 + 1;
      } while ((int)local_40 <= (int)DAT_006e5b38);
    }
    DAT_004b97e8 = DAT_004b97e8 - DAT_006df0f8;
    if (DAT_004b97e8 < 0) {
      DAT_004b97e8 = 0;
    }
    if ((local_20 == 0) && (1000 < DAT_004b97e8)) {
      DAT_004b97e8 = 1000;
    }
    DAT_006df0f2 = DAT_006df0f2 + 1;
    if (DAT_006df0f2 == 5) {
      DAT_006df0f2 = 0;
      puVar10 = &DAT_0079dde0;
      puVar16 = (undefined4 *)(&DAT_0078fde0 + (short)DAT_006df0f0 * 0x2000);
      for (iVar13 = 0x800; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar16 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar16 = puVar16 + 1;
      }
      DAT_006df0f0 = DAT_006df0f0 + 1;
      if (6 < (short)DAT_006df0f0) {
        DAT_006df0f0 = 1;
      }
    }
    if ((DAT_0070db34 == 3) && (local_44 = 0, 0 < DAT_00a236a0)) {
      iVar13 = 0;
      do {
        local_3c = *(int *)((int)&DAT_00a236b0 + iVar13);
        if (local_3c != -1) {
          if (*(int *)((int)aiStack_2bc + iVar13) == 1) {
            local_48 = (uint)(*(ushort *)
                               ((int)&DAT_0084a500 +
                               (local_3c * 0x80 + *(int *)(&DAT_00a23840 + iVar13)) * 2) >> 8);
            *(int *)((int)&DAT_00a23510 + iVar13) =
                 *(int *)((int)&DAT_00a23510 + iVar13) + (int)DAT_006df0f8;
            if (2 < *(int *)((int)&DAT_00a23510 + iVar13)) {
              *(int *)((int)&DAT_00a23510 + iVar13) = *(int *)((int)&DAT_00a23510 + iVar13) + -3;
              if (local_48 == 0) {
                FUN_00416e20(DAT_00859688,6,local_3c,*(undefined4 *)(&DAT_00a23840 + iVar13));
              }
              local_48 = local_48 + 1;
              if (0x1f < (int)local_48) {
                local_48 = 0x1f;
              }
              puVar3 = (undefined2 *)
                       ((int)&DAT_0084a500 +
                       (*(int *)((int)&DAT_00a236b0 + iVar13) * 0x80 +
                       *(int *)(&DAT_00a23840 + iVar13)) * 2);
              *puVar3 = CONCAT11((undefined1)local_48,*(undefined1 *)puVar3);
LAB_00452e81:
              FUN_0041e900(*(undefined4 *)((int)&DAT_00a236b0 + iVar13),
                           *(undefined4 *)(&DAT_00a23840 + iVar13),4,4);
            }
          }
          else {
            local_48 = (uint)(*(ushort *)
                               ((int)&DAT_0084a500 +
                               (local_3c * 0x80 + *(int *)(&DAT_00a23840 + iVar13)) * 2) >> 8);
            *(int *)((int)&DAT_00a23510 + iVar13) =
                 *(int *)((int)&DAT_00a23510 + iVar13) + (int)DAT_006df0f8;
            if (2 < *(int *)((int)&DAT_00a23510 + iVar13)) {
              *(int *)((int)&DAT_00a23510 + iVar13) = *(int *)((int)&DAT_00a23510 + iVar13) + -3;
              if (local_48 == 0x1f) {
                FUN_00416e20(DAT_0085968c,6,local_3c,*(undefined4 *)(&DAT_00a23840 + iVar13));
              }
              local_48 = local_48 - 1;
              if (-1 < (int)local_48) {
                puVar3 = (undefined2 *)
                         ((int)&DAT_0084a500 +
                         (*(int *)((int)&DAT_00a236b0 + iVar13) * 0x80 +
                         *(int *)(&DAT_00a23840 + iVar13)) * 2);
                *puVar3 = CONCAT11((undefined1)local_48,*(undefined1 *)puVar3);
                goto LAB_00452e81;
              }
              local_48 = 0;
            }
          }
        }
        iVar13 = iVar13 + 4;
        local_44 = local_44 + 1;
      } while (local_44 < DAT_00a236a0);
    }
  }
  DAT_00507488 = DAT_00507488 - 1 & 0x3f;
  *unaff_FS_OFFSET = local_14;
  return;
}



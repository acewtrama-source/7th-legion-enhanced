
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl f_42a140(short param_1)

{
  short *psVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  byte bVar6;
  short sVar7;
  undefined4 *puVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  short sVar14;
  int iVar15;
  undefined4 unaff_EBP;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  bool bVar20;
  undefined4 uVar21;
  short local_194 [8];
  int local_184;
  int local_180;
  undefined4 local_17c;
  uint local_178;
  int local_174;
  undefined4 local_170;
  int local_16c;
  uint local_168;
  uint local_164;
  int local_160;
  uint local_15c;
  undefined4 local_158;
  int local_154;
  uint local_150;
  uint local_14c;
  int local_148;
  uint local_144;
  uint local_140;
  uint local_13c;
  int local_138;
  int local_134;
  int local_130;
  uint local_12c;
  int local_128;
  uint local_124;
  undefined4 local_120;
  int local_11c;
  uint local_118;
  uint local_114;
  int local_110;
  uint local_10c;
  undefined4 local_108;
  int local_104;
  uint local_100;
  uint local_fc;
  int local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  uint local_dc;
  int local_d8;
  uint local_d4;
  int local_d0;
  uint local_cc;
  int *local_c8;
  undefined4 local_c4;
  int local_c0;
  uint local_bc;
  uint local_b8;
  int local_b4;
  uint local_b0;
  undefined4 local_ac;
  int local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  int *local_8c;
  short local_88;
  short local_84;
  int local_80;
  int *local_7c;
  int *local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  uint *local_64;
  int local_60;
  ushort *local_5c;
  uint *local_58;
  int local_54;
  short local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  short local_14;
  short local_12;
  short sStack_10;
  short local_e;
  short local_c;
  short sStack_a;
  short sStack_8;
  short local_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
                    /* 0x2a140  1  f_42a140 */
  uStack_4 = (undefined2)unaff_EBP;
  uStack_2 = (undefined2)((uint)unaff_EBP >> 0x10);
  local_194[0] = 0xbbc;
  local_194[1] = 0xbd0;
  local_194[2] = 0xbe4;
  local_194[3] = 0xbf8;
  local_194[4] = 0xbe3;
  local_194[5] = 0xbf7;
  local_194[6] = 0xbf4;
  local_e = -1;
  local_194[7] = 0xbbc;
  local_18 = param_1 * 0x410;
  local_14 = *(short *)(local_18 + 0x71b600);
  switch(*(undefined4 *)(local_18 + 0x71b604)) {
  case 2:
    sStack_8 = 1;
    break;
  default:
    sStack_8 = 0;
    break;
  case 0xf:
    sStack_8 = 2;
    break;
  case 0x12:
    sStack_8 = 0;
    local_e = -1;
    bVar6 = func_0x0049c540();
    if ((bVar6 & 0x1f) == 4) {
      local_e = ((ushort)_DAT_006df3b0 & 1) + 0xd;
    }
    break;
  case 0x14:
    sStack_8 = 3;
    break;
  case 0x1f:
    sStack_8 = 4;
    break;
  case 0x21:
    sStack_8 = 5;
    break;
  case 0x22:
    sStack_8 = 6;
    local_e = -1;
    break;
  case 0x23:
    sStack_8 = 7;
    break;
  case 0x26:
    sStack_8 = 8;
    break;
  case 0x27:
    sStack_8 = 9;
    break;
  case 0x28:
    sStack_8 = 10;
    break;
  case 0x29:
    sStack_8 = 0xb;
    break;
  case 0x2a:
    sStack_8 = 0xc;
    break;
  case 0x2b:
    sStack_8 = 0xd;
  }
  iVar18 = -1;
  local_34 = *(int *)(local_18 + 0x71b694);
  if (local_34 != -1) {
    iVar11 = (short)local_34 * 0xe0;
    iVar18 = *(short *)(*(int *)(&DAT_00805df4 + iVar11) * 0x204 + 0x4bb7da) + -300;
    if (iVar18 < 0) {
      iVar18 = 0;
    }
    iVar18 = iVar18 / 3;
    iVar16 = (int)(short)((short)((*(int *)(iVar11 + 0x805e10) << 5) / 2) +
                         (short)*(undefined4 *)(&DAT_00805e08 + iVar11) * 0x20) -
             (int)(short)((uint)*(undefined4 *)(local_18 + 0x71b610) >> 0x10);
    iVar11 = (int)(short)((short)((*(int *)(iVar11 + 0x805e14) << 5) / 2) +
                         (short)*(undefined4 *)(&DAT_00805e0c + iVar11) * 0x20) -
             (int)(short)((uint)*(undefined4 *)(local_18 + 0x71b614) >> 0x10);
    if (iVar16 < 0) {
      iVar16 = -iVar16;
    }
    if (iVar11 < 0) {
      iVar11 = -iVar11;
    }
    iVar15 = iVar11;
    if (iVar16 < iVar11) {
      iVar15 = iVar16;
      iVar16 = iVar11;
    }
    local_184 = (int)(short)((short)iVar16 + (short)(iVar15 >> 2));
  }
  iVar11 = *(int *)(local_18 + 0x71b690);
  if (iVar11 != -1) {
    iVar16 = iVar11 * 0x6d0;
    iVar18 = *(short *)(iVar16 + 0x67fea2) + -300;
    if (iVar18 < 0) {
      iVar18 = 0;
    }
    iVar18 = (int)(iVar18 + (iVar18 >> 0x1f & 3U)) >> 2;
    iVar15 = (int)(short)((uint)*(undefined4 *)(iVar16 + 0x67fe28) >> 0x10) -
             (int)(short)((uint)*(undefined4 *)(local_18 + 0x71b610) >> 0x10);
    iVar16 = (int)(short)((uint)*(undefined4 *)(iVar16 + 0x67fe2c) >> 0x10) -
             (int)(short)((uint)*(undefined4 *)(local_18 + 0x71b614) >> 0x10);
    if (iVar15 < 0) {
      iVar15 = -iVar15;
    }
    if (iVar16 < 0) {
      iVar16 = -iVar16;
    }
    iVar9 = iVar16;
    if (iVar15 < iVar16) {
      iVar9 = iVar15;
      iVar15 = iVar16;
    }
    local_184 = (int)(short)((short)iVar15 + (short)(iVar9 >> 2));
  }
  local_2c = *(int *)(local_18 + 0x71b604);
  if ((((local_2c == 0x12) || (local_2c == 2)) || (local_2c == 0x2a)) || (_DAT_0070db34 == 3)) {
    iVar18 = -1;
  }
  if ((iVar18 != -1) && (local_184 < iVar18)) {
    return;
  }
  sVar14 = -1;
  local_c = -1;
  sStack_a = -1;
  sStack_10 = -1;
  if (local_34 != -1) {
    sStack_a = *(short *)(local_34 * 0xe0 + 0x805e7c);
  }
  if (iVar11 != -1) {
    iVar15 = iVar11 * 0x6d0;
    sStack_a = *(short *)(iVar15 + 0x67fe58);
    local_c = *(short *)(iVar15 + 0x67fe56);
    local_88 = (short)((uint)*(undefined4 *)(local_18 + 0x71b610) >> 0x10);
    iVar18 = (int)local_88 - (int)(short)((uint)*(undefined4 *)(iVar15 + 0x67fe28) >> 0x10);
    local_84 = (short)((uint)*(undefined4 *)(local_18 + 0x71b614) >> 0x10);
    iVar16 = (int)local_84 - (int)(short)((uint)*(undefined4 *)(iVar15 + 0x67fe2c) >> 0x10);
    if (iVar18 < 0) {
      iVar18 = -iVar18;
    }
    if (iVar16 < 0) {
      iVar16 = -iVar16;
    }
    iVar9 = iVar16;
    if (iVar18 < iVar16) {
      iVar9 = iVar18;
      iVar18 = iVar16;
    }
    sVar14 = *(short *)(iVar15 + 0x67fe50);
    sStack_10 = *(short *)(iVar15 + 0x67fe52);
    if (*(short *)(iVar15 + 0x67fea2) + 0x30 < (int)(short)((short)(iVar9 >> 2) + (short)iVar18)) {
      sStack_a = -1;
      local_c = -1;
      sVar14 = local_88;
      sStack_10 = local_84;
    }
    if (local_2c == 0x2a) {
      sVar14 = 0x1900;
      sStack_a = -1;
      local_c = -1;
      sStack_10 = 0x1900;
    }
  }
  local_12 = sStack_a;
  if (local_c != -1) {
    if (*(int *)(&DAT_00805df8 + local_c * 0xe0) == 0) {
      return;
    }
    if (*(int *)(local_c * 0xe0 + 0x805e44) < 0) {
      return;
    }
  }
  if (sStack_a != -1) {
    if (*(short *)(sStack_a * 0x6d0 + 0x67fe1c) == 0) {
      return;
    }
    if (*(int *)(sStack_a * 0x6d0 + 0x67fe20) < 0) {
      return;
    }
  }
  local_28 = 0x10000;
  local_6 = 0;
  local_50 = (short)iVar11;
  if (iVar11 != -1) {
    local_6 = *(short *)(iVar11 * 0x6d0 + 0x67fe10);
  }
  if (local_34 != -1) {
    local_6 = *(short *)(&DAT_00805df0 + local_34 * 0xe0);
  }
  if ((0 < local_6) && (local_6 < 7)) {
    switch(sStack_8) {
    case 0:
      iVar18 = (int)*(short *)(local_6 * 2 + 0x6dd180);
      break;
    case 1:
    case 9:
      iVar18 = (int)*(short *)(local_6 * 2 + 0x6dd2a0);
      break;
    case 2:
    case 3:
    case 5:
      iVar18 = (int)*(short *)(local_6 * 2 + 0x719f90);
      break;
    default:
      local_180 = 0x10000;
      goto LAB_0042a64a;
    }
    local_180 = (iVar18 + 2) * 0x8000;
LAB_0042a64a:
    local_17c = 0x10000;
    local_178 = (uint)((longlong)local_180 * 0x10000) >> 0x10 |
                (int)((ulonglong)((longlong)local_180 * 0x10000) >> 0x20) << 0x10;
    local_28 = local_178;
  }
  if (iVar11 != -1) {
    local_6 = local_50;
    local_28 = local_28 + *(short *)(local_50 * 0x6d0 + 0x67febe) * 0x3000;
    uVar12 = *(uint *)(local_50 * 0x6d0 + 0x680498);
    if ((uVar12 & 0x80) != 0) {
      local_28 = local_28 * 2;
    }
    if ((uVar12 & 0x400) != 0) {
      local_28 = local_28 * 2;
    }
  }
  iVar18 = *(int *)(local_18 + 0x71b610);
  iVar11 = *(int *)(local_18 + 0x71b614);
  iVar16 = iVar18 >> 0x15;
  iVar15 = iVar11 >> 0x15;
  iVar19 = iVar18 >> 0x10;
  iVar9 = iVar11 >> 0x10;
  if (*(char *)(iVar16 * 0x80 + 0x8352f0 + iVar15) == '\x04') {
LAB_0042b11c:
    iVar18 = func_0x004308f0(iVar19,iVar9,CONCAT22(sStack_a,local_c),CONCAT22(sStack_8,sStack_a));
    if (iVar18 == 0) {
      iVar18 = func_0x004308f0(*(int *)(local_18 + 0x71b610) - *(int *)(local_18 + 0x71b640) / 2 >>
                               0x10,*(int *)(local_18 + 0x71b614) -
                                    *(int *)(local_18 + 0x71b644) / 2 >> 0x10,
                               CONCAT22(sStack_a,local_c),CONCAT22(sStack_8,sStack_a));
    }
    iVar11 = local_18;
    switch(*(undefined4 *)(local_18 + 0x71b604)) {
    case 2:
    case 0xf:
    case 0x12:
    case 0x21:
    case 0x22:
    case 0x23:
      local_30 = *(int *)(local_18 + 0x71b610) >> 0x15;
      iVar16 = *(int *)(local_18 + 0x71b614) >> 0x15;
      if ((*(char *)(local_30 * 0x80 + 0x8352f0 + iVar16) == '\x04') &&
         (iVar15 = 0, -1 < _DAT_0083a402)) {
        piVar17 = (int *)&DAT_00805df8;
        do {
          if (((piVar17[-2] != 0 && *piVar17 != 0) && (piVar17[-1] == 6)) &&
             ((piVar17[4] == local_30 && (piVar17[5] == iVar16)))) {
            local_c = (short)iVar15;
            iVar18 = iVar15 + 1;
            sStack_a = -1;
            break;
          }
          piVar17 = piVar17 + 0x38;
          iVar15 = iVar15 + 1;
        } while (iVar15 <= _DAT_0083a402);
      }
    }
    if (((sStack_a == -1) || (*(short *)(sStack_a * 0x6d0 + 0x680466) < 900)) && (iVar18 != 0)) {
      sVar14 = (short)iVar18 + -1;
      local_6 = (short)((uint)iVar18 >> 0x10) + -1;
      if ((-1 < sVar14) && (sVar14 == local_c)) {
        local_24 = sVar14 * 0xe0;
        uVar12 = ((*(int *)(local_24 + 0x805e10) << 5) / 2 - (*(int *)(local_18 + 0x71b610) >> 0x10)
                 ) + *(int *)(&DAT_00805e08 + local_24) * 0x20;
        if ((int)uVar12 < 0) {
          uVar12 = -uVar12;
        }
        iVar18 = (*(int *)(&DAT_00805e0c + local_24) * 0x20 +
                 (*(int *)(local_24 + 0x805e14) << 5) / 2) - (*(int *)(local_18 + 0x71b614) >> 0x10)
        ;
        if (iVar18 < 0) {
          iVar18 = -iVar18;
        }
        if (((int)uVar12 < 0x20) && (iVar18 < 0x20)) {
          *(uint *)(local_18 + 0x71b68c) = *(int *)(local_18 + 0x71b68c) + (uVar12 & 3) + 4;
        }
        if (sStack_8 == 0) {
          *(undefined4 *)(local_18 + 0x71b68c) = 999;
        }
        if (4 < *(int *)(local_18 + 0x71b68c)) {
          sVar7 = *(short *)(*(int *)(&DAT_00805df4 + local_24) * 0x204 + 0x4bb7d4);
          if (sVar7 == -1) {
            sVar7 = 2;
          }
          local_cc = local_28;
          local_d0 = *(int *)((sStack_8 * 0x14 + (int)sVar7) * 4 + 0x4b5ee8);
          local_c8 = (int *)((uint)((longlong)(int)local_28 * (longlong)local_d0) >> 0x10 |
                            (int)((ulonglong)((longlong)(int)local_28 * (longlong)local_d0) >> 0x20)
                            << 0x10);
          iVar18 = *(int *)(local_18 + 0x71b610);
          iVar11 = *(int *)(local_18 + 0x71b614);
          iVar16 = iVar18 >> 0x10;
          uVar21 = *(undefined4 *)(local_18 + 0x71b690);
          iVar15 = iVar11 >> 0x10;
          *(undefined4 *)(local_24 + 0x805e64) = uVar21;
          uVar5 = *(undefined4 *)(local_18 + 0x71b694);
          *(undefined4 *)(local_24 + 0x805e68) = uVar5;
          *(undefined4 *)(local_24 + 0x805e6c) = uVar21;
          *(undefined4 *)(local_24 + 0x805e70) = uVar5;
          FUN_0042bd90(sVar14,-1,local_c8);
          sVar14 = func_0x00429de0(3,1,iVar16,iVar15,0xffffffff,0xffffffff);
          local_1c = (int)sVar14;
          if (local_1c != -1) {
            puVar8 = (undefined4 *)(local_1c * 0x410 + 0x71b63c);
            *puVar8 = 0;
            if (*(int *)(local_18 + 0x71b604) == 0x22) {
              *puVar8 = 1;
            }
            if (*(int *)(local_18 + 0x71b604) == 0x23) {
              *puVar8 = 2;
            }
            if (*(int *)(local_18 + 0x71b604) == 2) {
              *puVar8 = 3;
            }
          }
          _DAT_004af814 = 0;
          if ((*(int *)(local_18 + 0x71b604) != 0x29) && (_DAT_005474a0 != 1)) {
            sVar14 = ((ushort)*(undefined4 *)(_DAT_009d49c0 * 4 + 0x4afc00) & 1) + 1;
            _DAT_009d49c0 = _DAT_009d49c0 + 1 & 0x3ff;
            if (_DAT_005474a0 == 2) {
              sVar14 = (short)((uint)(int)sVar14 / 2);
            }
            for (; sVar14 != 0; sVar14 = sVar14 + -1) {
              iVar9 = _DAT_009d49c0 * 4;
              uVar12 = _DAT_009d49c0 + 1 & 0x3ff;
              _DAT_009d49c0 = uVar12 + 1 & 0x3ff;
              if (_DAT_004af814 == 0) {
                uVar21 = 0xc;
              }
              else {
                uVar21 = 0x1e;
              }
              func_0x00429de0(uVar21,1,iVar16 + -3 + (*(uint *)(iVar9 + 0x4afc00) & 7),
                              iVar15 + -3 + (*(uint *)(uVar12 * 4 + 0x4afc00) & 7),0xffffffff,
                              0xffffffff);
            }
          }
          if (local_e != -1) {
            iVar16 = local_e * 4;
            func_0x00416e20(*(undefined4 *)(local_e * 4 + 0x859590),
                            *(undefined4 *)(iVar16 + 0x719fd0),iVar18 >> 0x15,iVar11 >> 0x15);
            *(int *)(*(int *)(iVar16 + 0x719fd0) * 4 + 0x9e3bc0) = local_1c;
          }
          if ((*(int *)(local_24 + 0x805ec8) == 0) && (_DAT_0075ba10 == local_14)) {
            local_74 = *(int *)(local_24 + 0x805e10) / 2 + _DAT_006cc850 * -5 +
                       *(int *)(&DAT_00805e08 + local_24);
            local_1c = 0x10;
            local_68 = *(int *)(local_24 + 0x805e14) / 2 + _DAT_006cc850 * -5 +
                       *(int *)(&DAT_00805e0c + local_24);
            if (*(int *)(&DAT_00805df4 + local_24) == 6) {
              local_1c = 8;
            }
            local_3c = 0;
            local_4c = _DAT_006cc850 * 0xb;
            if (0 < local_4c) {
              local_60 = local_74 * 0x80;
              local_5c = (ushort *)((local_60 + local_68) * 2 + 0x672d80);
              local_58 = (uint *)((local_60 + local_68) * 4 + 0x77b770);
              do {
                iVar18 = 0;
                if (0 < local_4c) {
                  local_64 = local_58;
                  local_70 = local_74 + local_3c;
                  puVar13 = local_5c;
                  do {
                    if ((((0 < local_70) && (0 < local_68 + iVar18)) && (local_70 < 0x80)) &&
                       (local_68 + iVar18 < 0x80)) {
                      iVar16 = local_68 + local_60 + iVar18;
                      iVar11 = iVar18 / _DAT_006cc850;
                      *(undefined1 *)(iVar16 + 0x70e620) = 3;
                      *(undefined1 *)(iVar16 + 0x668cf0) = 2;
                      if (*(char *)((local_1c * 0xb + iVar11) * 0xb + 0x4baf28 +
                                   local_3c / _DAT_006cc850) != '\0') {
                        *(undefined1 *)(iVar16 + 0x66da10) = 3;
                        if (*puVar13 < 0xff) {
                          *puVar13 = 0xfe;
                        }
                        iVar11 = (int)(short)(*local_64 >> 0x10) + (*local_64 & 0xfff) * 0x80;
                        *(undefined1 *)(iVar11 + 0x85a760) = *(undefined1 *)(iVar11 + 0x6e0e80);
                      }
                    }
                    puVar13 = puVar13 + 1;
                    local_64 = local_64 + 1;
                    iVar18 = iVar18 + 1;
                  } while (iVar18 < local_4c);
                }
                local_60 = local_60 + 0x80;
                local_5c = local_5c + 0x80;
                local_58 = local_58 + 0x80;
                local_3c = local_3c + 1;
              } while (local_3c < local_4c);
            }
          }
          func_0x0041e900((*(int *)(local_18 + 0x71b610) >> 0x15) + -1,
                          ((*(int *)(local_18 + 0x71b614) >> 0x10) -
                           (*(int *)(local_18 + 0x71b65c) >> 0xd) >> 5) + -1,
                          (*(int *)(local_18 + 0x71b628) + 0x10 >> 5) + 2,
                          (*(int *)(local_18 + 0x71b62c) + 0x10 >> 5) + 2 +
                          (*(int *)(local_18 + 0x71b65c) >> 0x12));
          bVar20 = _DAT_00804310 != param_1;
          *(undefined4 *)(local_18 + 0x71b600) = 0;
          if (bVar20) {
            return;
          }
          _DAT_00804310 = _DAT_00804310 + -1;
          return;
        }
      }
      if (-1 < local_6) {
        local_6c = *(int *)(local_18 + 0x71b690);
        if ((local_6c != local_6) && (local_6 == sStack_a)) {
          local_30 = *(int *)(local_18 + 0x71b610) >> 0x10;
          local_38 = *(int *)(local_18 + 0x71b614) >> 0x10;
          local_20 = local_6 * 0x6d0;
          sVar14 = *(short *)(*(short *)(local_20 + 0x67fe12) * 0x4c + 0x4c0874);
          iVar18 = *(int *)((sStack_8 * 0x14 + (int)sVar14) * 4 + 0x4b5ee8);
          if (sVar14 == 0) {
            local_c4 = 0x2aab;
            iVar16 = (6 - *(short *)((*(ushort *)(local_20 + 0x67fe10) & 7) * 2 + 0x8046d0)) *
                     0x10000;
            local_bc = (uint)((longlong)iVar16 * 0x2aab) >> 0x10 |
                       (int)((ulonglong)((longlong)iVar16 * 0x2aab) >> 0x20) << 0x10;
            local_94 = (uint)((longlong)iVar18 * (longlong)(int)local_bc) >> 0x10 |
                       (int)((ulonglong)((longlong)iVar18 * (longlong)(int)local_bc) >> 0x20) <<
                       0x10;
            local_c0 = iVar16;
            local_b8 = local_bc;
            local_b4 = iVar18;
            local_b0 = local_94;
          }
          else {
            local_ac = 0x2aab;
            iVar16 = (6 - *(short *)((*(ushort *)(local_20 + 0x67fe10) & 7) * 2 + 0x66d8f0)) *
                     0x10000;
            local_a4 = (uint)((longlong)iVar16 * 0x2aab) >> 0x10 |
                       (int)((ulonglong)((longlong)iVar16 * 0x2aab) >> 0x20) << 0x10;
            local_94 = (uint)((longlong)iVar18 * (longlong)(int)local_a4) >> 0x10 |
                       (int)((ulonglong)((longlong)iVar18 * (longlong)(int)local_a4) >> 0x20) <<
                       0x10;
            local_a8 = iVar16;
            local_a0 = local_a4;
            local_9c = iVar18;
            local_98 = local_94;
          }
          local_90 = local_28;
          local_8c = (int *)((uint)((longlong)(int)local_28 * (longlong)(int)local_94) >> 0x10 |
                            (int)((ulonglong)((longlong)(int)local_28 * (longlong)(int)local_94) >>
                                 0x20) << 0x10);
          uVar2 = *(undefined2 *)(local_18 + 0x71b694);
          *(undefined2 *)(local_20 + 0x67feb0) = (undefined2)local_6c;
          *(undefined2 *)(local_20 + 0x67feb2) = uVar2;
          *(undefined2 *)(local_20 + 0x67feb4) = (undefined2)local_6c;
          *(undefined2 *)(local_20 + 0x67feb6) = uVar2;
          piVar17 = local_8c;
          if (((*(byte *)(local_20 + 0x680498) & 0x40) != 0) &&
             ((*(int *)(local_20 + 0x67fe3c) != 0 || (*(int *)(local_20 + 0x67fe40) != 0)))) {
            piVar17 = (int *)0x0;
          }
          FUN_0042bd90(-1,local_6,piVar17);
          sVar7 = func_0x00429de0(3,1,local_30,local_38,0xffffffff,0xffffffff);
          local_1c = (int)sVar7;
          if (local_1c != -1) {
            puVar8 = (undefined4 *)(local_1c * 0x410 + 0x71b63c);
            *puVar8 = 0;
            iVar11 = *(int *)(local_18 + 0x71b604);
            if (iVar11 == 0x22) {
              *puVar8 = 1;
            }
            if (*(int *)(local_18 + 0x71b604) == 0x23) {
              *puVar8 = 2;
            }
            if (*(int *)(local_18 + 0x71b604) == 2) {
              *puVar8 = 3;
            }
          }
          if (sVar14 == 0) {
            local_30 = *(int *)(local_20 + 0x67fe28) >> 0x10;
            local_38 = (*(int *)(local_20 + 0x67fe2c) >> 0x10) + -8;
          }
          _DAT_004af814 = (uint)(sVar14 == 0);
          if (*(int *)(local_18 + 0x71b604) != 0x29) {
            iVar18 = CONCAT22((short)((uint)iVar11 >> 0x10),(undefined2)local_38);
            iVar11 = CONCAT22((short)((uint)iVar16 >> 0x10),(undefined2)local_30);
            if (_DAT_005474a0 != 1) {
              iVar16 = _DAT_009d49c0 * 4;
              _DAT_009d49c0 = _DAT_009d49c0 + 1 & 0x3ff;
              sVar14 = ((ushort)*(undefined4 *)(iVar16 + 0x4afc00) & 1) + 1;
              if (_DAT_005474a0 == 2) {
                sVar14 = (short)((uint)(int)sVar14 / 2);
              }
              for (; sVar14 != 0; sVar14 = sVar14 + -1) {
                iVar16 = _DAT_009d49c0 * 4;
                uVar12 = _DAT_009d49c0 + 1 & 0x3ff;
                _DAT_009d49c0 = uVar12 + 1 & 0x3ff;
                if (_DAT_004af814 == 0) {
                  uVar21 = 0xc;
                }
                else {
                  uVar21 = 0x1e;
                }
                func_0x00429de0(uVar21,1,((*(uint *)(iVar16 + 0x4afc00) & 7) - 3) + iVar11,
                                ((*(uint *)(uVar12 * 4 + 0x4afc00) & 7) - 3) + iVar18,0xffffffff,
                                0xffffffff);
              }
            }
          }
          _DAT_004af814 = 0;
          if (*(short *)(local_20 + 0x67fe12) == 0x14) {
            uVar12 = _DAT_009d49c0 + 1 & 0x3ff;
            local_30 = (*(int *)(local_20 + 0x67fe28) >> 0x10) + -1 +
                       (*(uint *)(_DAT_009d49c0 * 4 + 0x4afc00) & 3);
            _DAT_009d49c0 = uVar12 + 1 & 0x3ff;
            local_38 = (*(int *)(local_20 + 0x67fe2c) >> 0x10) + -10 +
                       (*(uint *)(uVar12 * 4 + 0x4afc00) & 3);
            sVar14 = func_0x00429de0(0xd,1,local_30,local_38,0xffffffff,0xffffffff);
            local_1c = (int)sVar14;
            if (local_1c != -1) {
              *(int *)(local_1c * 0x410 + 0x71b640) = *(int *)(local_18 + 0x71b640) / 2;
              *(int *)(local_1c * 0x410 + 0x71b644) = *(int *)(local_18 + 0x71b644) / 2;
            }
          }
          if (local_e != -1) {
            iVar18 = local_e * 4;
            func_0x00416e20(*(undefined4 *)(iVar18 + 0x859590),*(undefined4 *)(iVar18 + 0x719fd0),
                            local_30 >> 5,local_38 >> 5);
            *(int *)(*(int *)(iVar18 + 0x719fd0) * 4 + 0x9e3bc0) = local_1c;
          }
          func_0x0041e900((*(int *)(local_18 + 0x71b610) >> 0x15) + -1,
                          ((*(int *)(local_18 + 0x71b614) >> 0x10) -
                           (*(int *)(local_18 + 0x71b65c) >> 0xd) >> 5) + -1,
                          (*(int *)(local_18 + 0x71b628) + 0x10 >> 5) + 2,
                          (*(int *)(local_18 + 0x71b62c) + 0x10 >> 5) + 2 +
                          (*(int *)(local_18 + 0x71b65c) >> 0x12));
          bVar20 = _DAT_00804310 == param_1;
          *(undefined4 *)(local_18 + 0x71b600) = 0;
          if (bVar20) {
            _DAT_00804310 = _DAT_00804310 + -1;
          }
        }
      }
    }
  }
  else {
    if ((((local_2c == 0x12) || (local_2c == 2)) || (sVar14 == -1)) || (sStack_10 == -1)) {
      if (local_2c != 0x2a) goto LAB_0042b11c;
    }
    else {
      local_c = -1;
      sStack_a = -1;
    }
    sVar10 = (short)((uint)iVar18 >> 0x10);
    sVar7 = (short)((uint)iVar11 >> 0x10);
    if (local_2c == 0x2a) {
      sStack_a = -1;
      local_c = -1;
      sStack_10 = sVar7;
      sVar14 = sVar10;
    }
    if ((((sStack_a == -1) && (local_c == -1)) && (sVar14 != -1)) && (sStack_10 != -1)) {
      local_40 = local_28;
      iVar18 = iVar19 - sVar14;
      if (iVar18 < 0) {
        iVar18 = -iVar18;
      }
      iVar11 = iVar9 - sStack_10;
      if (iVar11 < 0) {
        iVar11 = -iVar11;
      }
      if ((iVar18 < 8) && (iVar11 < 8)) {
        if ((local_2c != 0x29) && ((local_2c != 0x2a && (_DAT_005474a0 != 1)))) {
          sVar14 = ((ushort)*(undefined4 *)(_DAT_009d49c0 * 4 + 0x4afc00) & 1) + 1;
          _DAT_009d49c0 = _DAT_009d49c0 + 1 & 0x3ff;
          if (_DAT_005474a0 == 2) {
            sVar14 = (short)((uint)(int)sVar14 / 2);
          }
          for (; sVar14 != 0; sVar14 = sVar14 + -1) {
            iVar18 = _DAT_009d49c0 * 4;
            uVar12 = _DAT_009d49c0 + 1 & 0x3ff;
            _DAT_009d49c0 = uVar12 + 1 & 0x3ff;
            if (_DAT_004af814 == 0) {
              uVar21 = 0xc;
            }
            else {
              uVar21 = 0x1e;
            }
            func_0x00429de0(uVar21,1,iVar19 + -3 + (*(uint *)(iVar18 + 0x4afc00) & 7),
                            iVar9 + -3 + (*(uint *)(uVar12 * 4 + 0x4afc00) & 7),0xffffffff,
                            0xffffffff);
          }
        }
        local_80 = 0;
        local_54 = iVar15;
        psVar1 = (short *)((iVar16 * 0x80 + iVar15) * 2 + 0x773450);
        sVar14 = *psVar1;
        if ((sVar14 == 0x3e6) || (sVar14 == 0x3e5)) {
          local_80 = 1;
          *psVar1 = local_194[iVar15 * iVar16 & 7];
          func_0x0041e900(iVar16,iVar15,1,1);
        }
        local_44 = CONCAT22(local_44._2_2_,sVar7);
        local_48 = CONCAT22(local_48._2_2_,sVar10);
        if (local_80 == 0) {
          sVar14 = func_0x00429de0(3,1,local_48,local_44,0xffffffff,0xffffffff);
          iVar18 = (int)sVar14;
          if (iVar18 != -1) {
            puVar8 = (undefined4 *)(iVar18 * 0x410 + 0x71b63c);
            *puVar8 = 0;
            if (*(int *)(local_18 + 0x71b604) == 0x22) {
              *puVar8 = 1;
            }
            if (*(int *)(local_18 + 0x71b604) == 0x23) {
              *puVar8 = 2;
            }
            if (*(int *)(local_18 + 0x71b604) == 2) {
              *puVar8 = 3;
            }
            if (*(int *)(local_18 + 0x71b604) == 0x2a) {
              *puVar8 = 999;
            }
          }
        }
        else {
          sVar14 = func_0x00429de0(4,1,local_48,local_44,0xffffffff,0xffffffff);
          iVar18 = (int)sVar14;
        }
        if (local_e != -1) {
          iVar11 = local_e * 4;
          func_0x00416e20(*(undefined4 *)(local_e * 4 + 0x859590),*(undefined4 *)(iVar11 + 0x719fd0)
                          ,iVar16,local_54);
          *(int *)(*(int *)(iVar11 + 0x719fd0) * 4 + 0x9e3bc0) = iVar18;
        }
        if (local_12 != -1) {
          iVar15 = local_12 * 0x6d0;
          local_174 = (int)*(short *)(*(short *)(iVar15 + 0x67fe12) * 0x4c + 0x4c0860);
          iVar18 = *(short *)(iVar15 + 0x67fe12) * 0x4c;
          iVar11 = (int)(short)((uint)*(undefined4 *)(iVar15 + 0x67fe28) >> 0x10) -
                   (int)(short)local_48;
          iVar16 = (int)(short)((uint)*(undefined4 *)(iVar15 + 0x67fe2c) >> 0x10) -
                   (int)(short)local_44;
          if (iVar11 < 0) {
            iVar11 = -iVar11;
          }
          if (iVar16 < 0) {
            iVar16 = -iVar16;
          }
          iVar9 = iVar16;
          if (iVar11 < iVar16) {
            iVar9 = iVar11;
            iVar11 = iVar16;
          }
          iVar11 = (int)(short)((short)(iVar9 >> 2) + (short)iVar11);
          if (iVar11 < 0x40) {
            iVar11 = iVar11 + ((10 - local_174) - (int)*(short *)(iVar18 + 0x4c085e)) / 2;
            if (iVar11 < 0) {
              iVar11 = 0;
            }
            sVar14 = *(short *)(iVar18 + 0x4c0874);
            iVar18 = *(int *)((sStack_8 * 0x14 + (int)sVar14) * 4 + 0x4b5ee8);
            if (sVar14 == 0) {
              local_170 = 0x2aab;
              local_16c = (6 - *(short *)((*(ushort *)(iVar15 + 0x67fe10) & 7) * 2 + 0x8046d0)) *
                          0x10000;
              local_168 = (uint)((longlong)local_16c * 0x2aab) >> 0x10 |
                          (int)((ulonglong)((longlong)local_16c * 0x2aab) >> 0x20) << 0x10;
              local_140 = (uint)((longlong)iVar18 * (longlong)(int)local_168) >> 0x10 |
                          (int)((ulonglong)((longlong)iVar18 * (longlong)(int)local_168) >> 0x20) <<
                          0x10;
              local_164 = local_168;
              local_160 = iVar18;
              local_15c = local_140;
            }
            else {
              local_158 = 0x2aab;
              local_154 = (6 - *(short *)((*(ushort *)(iVar15 + 0x67fe10) & 7) * 2 + 0x66d8f0)) *
                          0x10000;
              local_150 = (uint)((longlong)local_154 * 0x2aab) >> 0x10 |
                          (int)((ulonglong)((longlong)local_154 * 0x2aab) >> 0x20) << 0x10;
              local_140 = (uint)((longlong)iVar18 * (longlong)(int)local_150) >> 0x10 |
                          (int)((ulonglong)((longlong)iVar18 * (longlong)(int)local_150) >> 0x20) <<
                          0x10;
              local_14c = local_150;
              local_148 = iVar18;
              local_144 = local_140;
            }
            local_13c = local_28;
            uVar12 = (uint)((longlong)(int)local_28 * (longlong)(int)local_140) >> 0x10;
            local_12c = uVar12 | (int)((ulonglong)
                                       ((longlong)(int)local_28 * (longlong)(int)local_140) >> 0x20)
                                 << 0x10;
            local_138 = (iVar11 >> 2) + 1;
            if (3 < local_138) {
              local_138 = 3;
            }
            local_138 = local_138 << 0x10;
            local_130 = (int)((ulonglong)((longlong)local_138 * (longlong)local_138) >> 0x20) <<
                        0x10;
            local_7c = (int *)(CONCAT44((int)local_12c >> 0x10,uVar12 << 0x10) / (longlong)local_130
                              );
            piVar17 = local_7c;
            if ((int)local_7c < 0x4000) {
              piVar17 = (int *)0x4000;
            }
            local_134 = local_138;
            local_128 = local_130;
            local_124 = local_12c;
            if (0x100 < (int)piVar17) {
              uVar2 = *(undefined2 *)(local_18 + 0x71b690);
              uVar3 = *(undefined2 *)(local_18 + 0x71b694);
              *(undefined2 *)(iVar15 + 0x67feb0) = uVar2;
              *(undefined2 *)(iVar15 + 0x67feb2) = uVar3;
              *(undefined2 *)(iVar15 + 0x67feb4) = uVar2;
              *(undefined2 *)(iVar15 + 0x67feb6) = uVar3;
              if (((*(byte *)(iVar15 + 0x680498) & 0x40) != 0) &&
                 ((*(int *)(iVar15 + 0x67fe3c) != 0 || (*(int *)(local_6 * 0x6d0 + 0x67fe40) != 0)))
                 ) {
                piVar17 = (int *)0x0;
              }
              FUN_0042bd90(-1,local_12,piVar17);
              local_40 = (int)local_40 / 2;
            }
          }
        }
        local_6 = 0;
        if (-1 < _DAT_006e5b38) {
          do {
            if ((int)local_40 < 0x100) break;
            if ((local_12 != local_6) && (local_6 != local_50)) {
              iVar18 = local_6 * 0x6d0;
              uVar4 = *(ushort *)(iVar18 + 0x67fe10);
              if (((uVar4 != 0) &&
                  (((*(ushort *)(local_50 * 0x6d0 + 0x67fe10) != uVar4 &&
                    (*(short *)(iVar18 + 0x67fe1c) != 0)) && (-1 < *(int *)(iVar18 + 0x67fe20)))))
                 && (*(short *)(iVar18 + 0x680466) < 900)) {
                iVar16 = (int)(short)((uint)*(undefined4 *)(iVar18 + 0x67fe28) >> 0x10) -
                         (int)(short)local_48;
                iVar11 = (int)(short)((uint)*(undefined4 *)(iVar18 + 0x67fe2c) >> 0x10) -
                         (int)(short)local_44;
                if (iVar16 < 0) {
                  iVar16 = -iVar16;
                }
                if (iVar11 < 0) {
                  iVar11 = -iVar11;
                }
                iVar15 = iVar16;
                if (iVar16 < iVar11) {
                  iVar15 = iVar11;
                  iVar11 = iVar16;
                }
                iVar11 = (int)(short)((short)iVar15 + (short)(iVar11 >> 2));
                if (iVar11 < 0x41) {
                  iVar16 = *(short *)(iVar18 + 0x67fe12) * 0x4c;
                  iVar11 = iVar11 + ((10 - *(short *)(iVar16 + 0x4c085e)) -
                                    (int)*(short *)(iVar16 + 0x4c0860)) / 2;
                  if (iVar11 < 0) {
                    iVar11 = 0;
                  }
                  iVar15 = *(int *)((sStack_8 * 0x14 + (int)*(short *)(iVar16 + 0x4c0874)) * 4 +
                                   0x4b5ee8);
                  if (*(short *)(iVar16 + 0x4c0874) == 0) {
                    local_120 = 0x2aab;
                    local_11c = (6 - *(short *)((uVar4 & 7) * 2 + 0x8046d0)) * 0x10000;
                    local_118 = (uint)((longlong)local_11c * 0x2aab) >> 0x10 |
                                (int)((ulonglong)((longlong)local_11c * 0x2aab) >> 0x20) << 0x10;
                    local_f0 = (uint)((longlong)iVar15 * (longlong)(int)local_118) >> 0x10 |
                               (int)((ulonglong)((longlong)iVar15 * (longlong)(int)local_118) >>
                                    0x20) << 0x10;
                    local_114 = local_118;
                    local_110 = iVar15;
                    local_10c = local_f0;
                  }
                  else {
                    local_108 = 0x2aab;
                    local_104 = (6 - *(short *)((uVar4 & 7) * 2 + 0x66d8f0)) * 0x10000;
                    local_100 = (uint)((longlong)local_104 * 0x2aab) >> 0x10 |
                                (int)((ulonglong)((longlong)local_104 * 0x2aab) >> 0x20) << 0x10;
                    local_f0 = (uint)((longlong)iVar15 * (longlong)(int)local_100) >> 0x10 |
                               (int)((ulonglong)((longlong)iVar15 * (longlong)(int)local_100) >>
                                    0x20) << 0x10;
                    local_fc = local_100;
                    local_f8 = iVar15;
                    local_f4 = local_f0;
                  }
                  local_ec = local_40;
                  uVar12 = (uint)((longlong)(int)local_40 * (longlong)(int)local_f0) >> 0x10;
                  local_dc = uVar12 | (int)((ulonglong)
                                            ((longlong)(int)local_40 * (longlong)(int)local_f0) >>
                                           0x20) << 0x10;
                  local_e8 = (iVar11 >> 2) + 1;
                  if (3 < local_e8) {
                    local_e8 = 3;
                  }
                  local_e8 = local_e8 << 0x10;
                  local_e0 = (int)((ulonglong)((longlong)local_e8 * (longlong)local_e8) >> 0x20) <<
                             0x10;
                  local_78 = (int *)(CONCAT44((int)local_dc >> 0x10,uVar12 << 0x10) /
                                    (longlong)local_e0);
                  piVar17 = local_78;
                  if ((int)local_78 < 0x2000) {
                    piVar17 = (int *)0x2000;
                  }
                  local_e4 = local_e8;
                  local_d8 = local_e0;
                  local_d4 = local_dc;
                  if (0x100 < (int)piVar17) {
                    uVar2 = *(undefined2 *)(local_18 + 0x71b690);
                    uVar3 = *(undefined2 *)(local_18 + 0x71b694);
                    *(undefined2 *)(iVar18 + 0x67feb0) = uVar2;
                    *(undefined2 *)(iVar18 + 0x67feb2) = uVar3;
                    *(undefined2 *)(iVar18 + 0x67feb4) = uVar2;
                    *(undefined2 *)(iVar18 + 0x67feb6) = uVar3;
                    if (((*(byte *)(iVar18 + 0x680498) & 0x40) != 0) &&
                       ((*(int *)(iVar18 + 0x67fe3c) != 0 || (*(int *)(iVar18 + 0x67fe40) != 0)))) {
                      piVar17 = (int *)0x0;
                    }
                    FUN_0042bd90(-1,local_6,piVar17);
                    if ((int)local_40 < 0x100) {
                      func_0x0041e900((*(int *)(local_18 + 0x71b610) >> 0x15) + -1,
                                      ((*(int *)(local_18 + 0x71b614) >> 0x10) -
                                       (*(int *)(local_18 + 0x71b65c) >> 0xd) >> 5) + -1,
                                      (*(int *)(local_18 + 0x71b628) + 0x10 >> 5) + 2,
                                      (*(int *)(local_18 + 0x71b62c) + 0x10 >> 5) + 2 +
                                      (*(int *)(local_18 + 0x71b65c) >> 0x12));
                      bVar20 = _DAT_00804310 != param_1;
                      *(undefined4 *)(local_18 + 0x71b600) = 0;
                      if (bVar20) {
                        return;
                      }
                      _DAT_00804310 = _DAT_00804310 + -1;
                      return;
                    }
                  }
                }
              }
            }
            local_6 = local_6 + 1;
          } while (local_6 <= _DAT_006e5b38);
        }
        func_0x0041e900((*(int *)(local_18 + 0x71b610) >> 0x15) + -1,
                        ((*(int *)(local_18 + 0x71b614) >> 0x10) -
                         (*(int *)(local_18 + 0x71b65c) >> 0xd) >> 5) + -1,
                        (*(int *)(local_18 + 0x71b628) + 0x10 >> 5) + 2,
                        (*(int *)(local_18 + 0x71b62c) + 0x10 >> 5) + 2 +
                        (*(int *)(local_18 + 0x71b65c) >> 0x12));
        bVar20 = _DAT_00804310 == param_1;
        *(undefined4 *)(local_18 + 0x71b600) = 0;
        if (bVar20) {
          _DAT_00804310 = _DAT_00804310 + -1;
          return;
        }
      }
    }
  }
  return;
}



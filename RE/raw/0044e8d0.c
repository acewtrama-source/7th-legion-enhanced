
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl f_44e8d0(int param_1)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  short sVar9;
  short sVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  int extraout_EDX;
  int iVar14;
  ushort *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  short sVar19;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  short local_10;
  short local_c;
  int local_8;
  
                    /* 0x4e8d0  44  f_44e8d0 */
  iVar16 = param_1 * 0x6d0;
  local_c = *(short *)(iVar16 + 0x67fe50);
  local_10 = *(short *)(iVar16 + 0x67fe52);
  if (*(short *)(iVar16 + 0x67fe56) != -1) {
    local_c = -1;
    local_10 = -1;
    iVar12 = (int)*(short *)(iVar16 + 0x67fe56);
    iVar14 = iVar12 * 0xe0;
    if ((*(int *)(&DAT_00805df0 + iVar14) != 0) && (*(int *)(&DAT_00805df8 + iVar14) != 0)) {
      iVar17 = *(int *)(&DAT_00805e10 + iVar14) * 0x20;
      iVar5 = *(int *)(&DAT_00805e10 + iVar14) * -0x20 + 0x10;
      iVar18 = *(int *)(&DAT_00805e14 + iVar14) * 0x20;
      local_c = (short)(iVar17 / 2) +
                (short)*(undefined4 *)(&DAT_00805e08 + iVar14) * 0x20 +
                (short)((iVar12 + param_1 * 4) % ((iVar17 + -0x10) / 2)) +
                (short)((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
      iVar5 = *(int *)(&DAT_00805e14 + iVar14) * -0x20 + 0x10;
      local_10 = (short)(iVar18 / 2) +
                 (short)*(undefined4 *)(&DAT_00805e0c + iVar14) * 0x20 +
                 (short)((*(short *)(&DAT_0067fe12 + iVar16) + iVar12 + param_1 * 4) %
                        ((iVar18 + -0x10) / 2)) + (short)((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2);
    }
  }
  if (*(short *)(&DAT_0067fe58 + iVar16) != -1) {
    local_c = -1;
    local_10 = -1;
    iVar12 = *(short *)(&DAT_0067fe58 + iVar16) * 0x6d0;
    if ((*(short *)(&DAT_0067fe10 + iVar12) != 0) && (*(short *)(&DAT_0067fe1c + iVar12) != 0)) {
      local_c = ((ushort)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar12) >> 0x10) & 0xffe0) + 0x10;
      local_10 = ((ushort)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar12) >> 0x10) & 0xffe0) + 0x10;
    }
  }
  local_1c = (uint)(0xffff < *(int *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c087c) +
                             *(short *)(&DAT_0067febe + iVar16) * 0x2000);
  local_8 = 0;
  do {
    sVar19 = *(short *)(iVar16 + 0x67fee6);
    if (sVar19 != -1) {
      *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
      *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
    }
    *(undefined2 *)(iVar16 + 0x67fe9c) = 0;
    if ((*(short *)(iVar16 + 0x67feea) == *(short *)(iVar16 + 0x67feee)) &&
       (*(short *)(iVar16 + 0x67fef0) == *(short *)(iVar16 + 0x67feec))) {
      *(undefined2 *)(iVar16 + 0x67fe74) = 7;
    }
    if (*(short *)(iVar16 + 0x67fee4) == 0) {
      *(undefined2 *)(iVar16 + 0x67fe74) = 7;
    }
    if (*(short *)(iVar16 + 0x67fe74) == 7) {
      *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
      *(undefined4 *)(iVar16 + 0x67fe40) = 0;
      *(undefined2 *)(&DAT_0067fe72 + iVar16) = 0;
      return;
    }
    iVar12 = (int)*(short *)(iVar16 + 0x67ff08);
    if (*(short *)(iVar16 + 0x6803ba) + -1 < iVar12) {
      *(undefined2 *)(iVar16 + 0x67fee4) = 0;
      sVar19 = *(short *)(iVar16 + 0x67fee6);
      if (sVar19 != -1) {
        *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
        *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
      }
      sVar19 = *(short *)(iVar16 + 0x67fe74);
      *(short *)(&DAT_0067fe72 + iVar16) = sVar19;
      if (sVar19 == 6) {
        *(undefined2 *)(iVar16 + 0x67fe74) = 7;
      }
    }
    else {
      local_2c = (int)*(short *)(iVar16 + 0x67fef2);
      local_28 = (int)*(short *)(iVar16 + 0x67fef4);
      local_18 = (int)*(short *)(iVar16 + 0x67ff06);
      iVar14 = local_28 + local_2c * 0x80;
      uVar13 = (uint)(byte)(&DAT_006d3920)[iVar14];
      if (param_1 - uVar13 == -1) {
        uVar13 = 0;
      }
      if ((*(int *)(&DAT_0067fe28 + iVar16) >> 0x15 == local_2c) &&
         (*(int *)(&DAT_0067fe2c + iVar16) >> 0x15 == local_28)) {
        uVar13 = 0;
      }
      sVar19 = (short)param_1;
      if (uVar13 != 0) {
        if ((((*(short *)(&DAT_0067f740 + uVar13 * 0x6d0) != 0) &&
             (*(short *)(&DAT_0067fe10 + iVar16) != *(short *)(&DAT_0067f740 + uVar13 * 0x6d0))) &&
            (*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0874) != 0)) &&
           (*(short *)(*(short *)(&DAT_0067f742 + uVar13 * 0x6d0) * 0x4c + 0x4c0874) == 0)) {
          uVar13 = 0;
        }
        if ((uVar13 != 0) && (*(short *)(&DAT_0067f740 + uVar13 * 0x6d0) != 0)) {
          iVar12 = uVar13 * 0x6d0;
          if ((*(short *)(&DAT_0067f740 + iVar12) != *(short *)(&DAT_0067fe10 + iVar16)) &&
             (_DAT_0070db34 == 3)) {
            FUN_00423f70(sVar19,3,-1,(short)uVar13 + -1,0xffff,0xffff);
            return;
          }
          if ((*(int *)(&DAT_0067f76c + iVar12) == 0) && (*(int *)(iVar12 + 0x67f770) == 0)) {
            *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
            *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
            *(undefined4 *)(iVar16 + 0x67fe40) = 0;
            *(undefined2 *)(iVar16 + 0x67fee4) = 0;
            sVar19 = *(short *)(iVar16 + 0x67fee6);
            if (sVar19 == -1) {
              return;
            }
            *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
            *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
            return;
          }
          *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
          *(undefined4 *)(iVar16 + 0x67fe40) = 0;
          return;
        }
      }
      if ((((&DAT_008352f0)[iVar14] == 0) || (2 < (byte)(&DAT_008352f0)[iVar14])) || (uVar13 != 0))
      {
        *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
        *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
        *(undefined4 *)(iVar16 + 0x67fe40) = 0;
        sVar19 = *(short *)(iVar16 + 0x67fee6);
        if (sVar19 != -1) {
          *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
          *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
        }
        *(undefined2 *)(iVar16 + 0x67fee4) = 0;
        return;
      }
      iVar17 = param_1 * 0x368;
      iVar5 = (iVar12 + iVar17) * 2;
      iVar14 = iVar17;
      local_24 = iVar12;
      if (((*(short *)(iVar5 + 0x67ff0c) == local_2c) && (*(short *)(iVar5 + 0x680164) == local_28))
         && (*(short *)(iVar16 + 0x6803cc) == 0)) {
        local_24 = iVar12 + 1;
        iVar12 = (iVar17 + local_24) * 2;
        sVar9 = *(short *)(iVar12 + 0x67ff0a);
        local_2c = (int)sVar9;
        sVar4 = *(short *)(iVar12 + 0x680162);
        local_28 = (int)sVar4;
        sVar10 = *(short *)(iVar12 + 0x6803c8);
        local_18 = (int)sVar10;
        *(undefined2 *)(iVar16 + 0x67ff08) = (undefined2)local_24;
        *(short *)(iVar16 + 0x67fef2) = sVar9;
        *(short *)(iVar16 + 0x67fef4) = sVar4;
        *(short *)(iVar16 + 0x67ff06) = sVar10;
        if (local_2c == 9999) {
          *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
          *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
          *(undefined4 *)(iVar16 + 0x67fe40) = 0;
          *(undefined2 *)(iVar16 + 0x67fee4) = 0;
          sVar19 = *(short *)(iVar16 + 0x67fee6);
          if (sVar19 == -1) {
            return;
          }
          *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
          *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
          return;
        }
        sVar9 = sVar9 * 0x20 + 0x10;
        uVar6 = f_429c70(CONCAT22(sVar4 >> 0xf,sVar9),local_18,
                         (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                         (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >> 0x10),sVar9,
                         sVar4 * 0x20 + 0x10);
        sVar9 = (short)uVar6;
        *(short *)(iVar16 + 0x67fe54) = sVar9;
        if (sVar9 != -1) {
          *(short *)(iVar16 + 0x67fe54) = sVar9 << 3;
          if (*(short *)(iVar16 + 0x67fe80) == 0) {
            *(int *)(iVar16 + 0x67fe64) = (int)(short)(sVar9 << 3);
          }
        }
        if (((local_2c < 0) || (local_28 < 0)) ||
           ((0x7f < local_2c || ((0x7f < local_28 || (*(short *)(iVar16 + 0x6803ba) < local_24))))))
        {
          *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
          *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
          *(undefined4 *)(iVar16 + 0x67fe40) = 0;
          *(undefined2 *)(iVar16 + 0x67fee4) = 0;
          sVar19 = *(short *)(iVar16 + 0x67fee6);
          if (sVar19 == -1) {
            return;
          }
          *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
          *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
          return;
        }
        iVar14 = local_28 + local_2c * 0x80;
        uVar13 = (uint)(byte)(&DAT_006d3920)[iVar14];
        if (param_1 - uVar13 == -1) {
          uVar13 = 0;
        }
        if ((((uVar13 != 0) &&
             (*(short *)(&DAT_0067f740 + uVar13 * 0x6d0) != *(short *)(&DAT_0067fe10 + iVar16))) &&
            (*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0874) != 0)) &&
           (*(short *)(*(short *)(&DAT_0067f742 + uVar13 * 0x6d0) * 0x4c + 0x4c0874) == 0)) {
          uVar13 = 0;
        }
        if ((((&DAT_008352f0)[iVar14] == 0) || (2 < (byte)(&DAT_008352f0)[iVar14])) ||
           (iVar12 = 0, uVar13 != 0)) {
          *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
          *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
          *(undefined4 *)(iVar16 + 0x67fe40) = 0;
          *(undefined2 *)(iVar16 + 0x67fee4) = 0;
          sVar9 = *(short *)(iVar16 + 0x67fee6);
          if (sVar9 != -1) {
            *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
            *(undefined2 *)(&DAT_006e75c0 + sVar9 * 0x2ef4) = 0xffff;
          }
          if ((&DAT_008352f0)[local_28 + local_2c * 0x80] != '\x04') {
            return;
          }
          iVar12 = -1;
          iVar14 = 0;
          if (-1 < _DAT_0083a402) {
            piVar8 = (int *)&DAT_00805df0;
            do {
              if (((*piVar8 != 0) && (piVar8[2] != 0)) &&
                 (((int)*(short *)(&DAT_0067fe10 + iVar16) != *piVar8 &&
                  (((piVar8[1] == 6 && (piVar8[6] == local_2c)) && (piVar8[7] == local_28)))))) {
                iVar12 = iVar14;
              }
              piVar8 = piVar8 + 0x38;
              iVar14 = iVar14 + 1;
            } while (iVar14 <= _DAT_0083a402);
          }
          if (iVar12 == -1) {
            return;
          }
          if (*(short *)(&DAT_0067fe10 + iVar16) <= _DAT_00803c40) {
            return;
          }
          FUN_00423f70(sVar19,2,(short)iVar12,-1,0xffff,0xffff);
          return;
        }
      }
      if (*(short *)(iVar16 + 0x67fee8) == 0) {
        iVar14 = *(int *)(&DAT_0067fe28 + iVar16);
        iVar5 = iVar14 >> 0x10;
        iVar12 = iVar5 + local_2c * -0x20 + -0x10;
        if (iVar12 < 0) {
          iVar12 = -iVar12;
        }
        if (iVar12 == 0) {
          iVar12 = (*(int *)(&DAT_0067fe2c + iVar16) >> 0x10) + local_28 * -0x20 + -0x10;
        }
        if (0x20 < iVar12) {
          iVar14 = iVar14 >> 0x15;
          iVar12 = *(int *)(&DAT_0067fe2c + iVar16);
          iVar18 = iVar12 >> 0x15;
          if ((iVar5 + iVar14 * -0x20 == 0x10) &&
             (iVar12 = (iVar12 >> 0x10) + iVar18 * -0x20, iVar12 == 0x10)) {
            iVar14 = iVar14 * 0x80 + iVar18;
            uVar13 = (uint)(byte)(&DAT_006d3920)[iVar14];
            if (param_1 - uVar13 == -1) {
              uVar13 = 0;
            }
            if (((uVar13 != 0) &&
                (*(short *)(&DAT_0067f740 + uVar13 * 0x6d0) != *(short *)(&DAT_0067fe10 + iVar16)))
               && ((*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0874) != 0 &&
                   (*(short *)(*(short *)(&DAT_0067f742 + uVar13 * 0x6d0) * 0x4c + 0x4c0874) == 0)))
               ) {
              uVar13 = 0;
            }
            if ((((&DAT_008352f0)[iVar14] == 0) || (2 < (byte)(&DAT_008352f0)[iVar14])) ||
               (uVar13 != 0)) {
              *(undefined2 *)(iVar16 + 0x67fee0) = 0;
              *(undefined2 *)(iVar16 + 0x67fee4) = 0;
              *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
              *(undefined4 *)(iVar16 + 0x67fe40) = 0;
              sVar19 = *(short *)(iVar16 + 0x67fee6);
              if (sVar19 != -1) {
                *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
                *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
              }
              *(undefined2 *)(&DAT_0067fe72 + iVar16) = 5;
              return;
            }
            iVar12 = 0;
            if (*(short *)(iVar16 + 0x67fe80) == 0) {
              *(uint *)(iVar16 + 0x67fe64) = (int)*(short *)(iVar16 + 0x67fe54) + 0x20U & 0x3f;
            }
          }
        }
      }
      local_20 = 0;
      sVar9 = (short)local_28;
      sVar4 = (short)local_2c;
      if (*(short *)(iVar16 + 0x67fe54) == -1) {
        uVar6 = f_429c70(iVar12,iVar14,
                         (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                         (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >> 0x10),
                         sVar4 * 0x20 + 0x10,sVar9 * 0x20 + 0x10);
        iVar14 = extraout_EDX;
        if ((short)uVar6 != -1) {
          *(short *)(iVar16 + 0x67fe54) = (short)uVar6 << 3;
        }
      }
      if ((*(int *)(iVar16 + 0x67fe44) >> 0x10 != (int)*(short *)(iVar16 + 0x67fe54)) &&
         (_DAT_006dd174 = 0, 0 < _DAT_006df0f8)) {
        local_20 = 1;
        _DAT_006dd174 = _DAT_006df0f8;
        sVar10 = _DAT_006df0f8;
        do {
          iVar14 = *(int *)(iVar16 + 0x67fe44);
          uVar13 = ((iVar14 >> 0x10) - (int)*(short *)(iVar16 + 0x67fe54)) + 0x20U & 0x3f;
          iVar12 = uVar13 * 4 + -0x80;
          sVar1 = *(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880);
          if (sVar1 == -1) {
            *(int *)(iVar16 + 0x67fe44) = (int)*(short *)(iVar16 + 0x67fe54) << 0x10;
          }
          else if (local_1c == 0) {
            if (iVar12 < 0) {
              *(int *)(iVar16 + 0x67fe44) = sVar1 * 0x1000 + iVar14;
            }
            if (uVar13 != 0x20 && -1 < iVar12) {
              iVar12 = (int)*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880) << 0xc;
LAB_0044f0e9:
              *(int *)(iVar16 + 0x67fe44) = *(int *)(iVar16 + 0x67fe44) - iVar12;
            }
          }
          else {
            if (iVar12 < 0) {
              *(int *)(iVar16 + 0x67fe44) = sVar1 * 0x800 + iVar14;
            }
            if (uVar13 != 0x20 && -1 < iVar12) {
              iVar12 = (int)*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880) << 0xb;
              goto LAB_0044f0e9;
            }
          }
          sVar10 = sVar10 + -1;
          *(uint *)(iVar16 + 0x67fe44) = *(uint *)(iVar16 + 0x67fe44) & 0x3ff000;
        } while (sVar10 != 0);
      }
      iVar12 = *(int *)(iVar16 + 0x67fe64);
      if (((*(int *)(iVar16 + 0x67fe60) >> 0x10 != iVar12) && (local_20 != 2)) &&
         (_DAT_006dd174 = 0, 0 < _DAT_006df0f8)) {
        iVar12 = CONCAT22((short)((uint)iVar12 >> 0x10),_DAT_006df0f8);
        _DAT_006dd174 = _DAT_006df0f8;
        do {
          iVar14 = *(int *)(iVar16 + 0x67fe60);
          uVar13 = ((iVar14 >> 0x10) - *(int *)(iVar16 + 0x67fe64)) + 0x20U & 0x3f;
          iVar5 = uVar13 * 4 + -0x80;
          sVar10 = *(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880);
          if (sVar10 == -1) {
            if (local_1c == 0) {
              if (iVar5 < 0) {
                iVar14 = iVar14 + 0x8000;
                *(int *)(iVar16 + 0x67fe60) = iVar14;
              }
              if (uVar13 != 0x20 && -1 < iVar5) {
                iVar5 = *(int *)(iVar16 + 0x67fe60) + -0x8000;
LAB_0044f1d4:
                *(int *)(iVar16 + 0x67fe60) = iVar5;
              }
            }
            else {
              if (iVar5 < 0) {
                iVar14 = iVar14 + 0x4000;
                *(int *)(iVar16 + 0x67fe60) = iVar14;
              }
              if (uVar13 != 0x20 && -1 < iVar5) {
                iVar5 = *(int *)(iVar16 + 0x67fe60) + -0x4000;
                goto LAB_0044f1d4;
              }
            }
            if (*(short *)(&DAT_0067fe12 + iVar16) == 0x13) {
              *(int *)(iVar16 + 0x67fe60) = *(int *)(iVar16 + 0x67fe64) << 0x10;
            }
          }
          else if (local_1c == 0) {
            if (iVar5 < 0) {
              *(int *)(iVar16 + 0x67fe60) = sVar10 * 0x800 + iVar14;
            }
            if (uVar13 != 0x20 && -1 < iVar5) {
              iVar5 = (int)*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880) << 0xb;
LAB_0044f25b:
              *(int *)(iVar16 + 0x67fe60) = *(int *)(iVar16 + 0x67fe60) - iVar5;
            }
          }
          else {
            if (iVar5 < 0) {
              *(int *)(iVar16 + 0x67fe60) = sVar10 * 0x400 + iVar14;
            }
            if (uVar13 != 0x20 && -1 < iVar5) {
              iVar5 = (int)*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0880) << 10;
              goto LAB_0044f25b;
            }
          }
          sVar10 = (short)iVar12 + -1;
          iVar12 = CONCAT22((short)((uint)iVar12 >> 0x10),sVar10);
          *(uint *)(iVar16 + 0x67fe60) = *(uint *)(iVar16 + 0x67fe60) & 0x3ff000;
        } while (sVar10 != 0);
      }
      if ((*(int *)(iVar16 + 0x67fe3c) != 0) || (*(int *)(iVar16 + 0x67fe40) != 0)) {
        local_20 = 0;
      }
      if (local_20 == 0) {
        uVar13 = *(int *)(iVar16 + 0x67fe44) >> 0x10;
        uVar6 = f_429c70(iVar12,iVar14,
                         (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                         (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >> 0x10),
                         sVar4 * 0x20 + 0x10,sVar9 * 0x20 + 0x10);
        if ((short)uVar6 != -1) {
          uVar13 = (short)uVar6 * 8;
        }
        iVar12 = (int)(uVar13 & 0xfffffff9) >> 1;
        uVar7 = FUN_004463a0(*(int *)(iVar12 + 0x4af638),
                             *(int *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c087c) +
                             *(short *)(&DAT_0067febe + iVar16) * 0x2000);
        *(uint *)(iVar16 + 0x67fe3c) = uVar7;
        uVar7 = FUN_004463a0(*(int *)(iVar12 + 0x4af658),
                             *(int *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c087c) +
                             *(short *)(&DAT_0067febe + iVar16) * 0x2000);
        *(uint *)(iVar16 + 0x67fe40) = uVar7;
        if ((int)*(short *)(iVar16 + 0x67fe54) != uVar13) {
          *(short *)(iVar16 + 0x67fe54) = (short)uVar13;
        }
        if (local_1c != 0) {
          *(int *)(iVar16 + 0x67fe3c) = *(int *)(iVar16 + 0x67fe3c) >> 1;
          *(int *)(iVar16 + 0x67fe40) = *(int *)(iVar16 + 0x67fe40) >> 1;
        }
      }
      else {
        *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
        *(undefined4 *)(iVar16 + 0x67fe40) = 0;
      }
      _DAT_006dd174 = 0;
      if (0 < _DAT_006df0f8) {
        do {
          iVar12 = (*(int *)(&DAT_0067fe28 + iVar16) >> 0x10) + local_2c * -0x20 + -0x10;
          iVar14 = (*(int *)(&DAT_0067fe2c + iVar16) >> 0x10) + local_28 * -0x20 + -0x10;
          if (iVar12 < 0) {
            iVar12 = -iVar12;
          }
          if (iVar14 < 0) {
            iVar14 = -iVar14;
          }
          iVar5 = *(int *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c087c) +
                  *(short *)(&DAT_0067febe + iVar16) * 0x2000;
          iVar18 = iVar5 >> 0x10;
          if (local_1c != 0) {
            iVar18 = iVar5 >> 0x11;
          }
          if ((iVar12 <= iVar18) && (iVar14 <= iVar18)) {
            *(undefined2 *)(iVar16 + 0x6803cc) = 0;
            *(undefined2 *)(iVar16 + 0x67fe9c) = 1;
            *(short *)(iVar16 + 0x67fef2) = sVar4;
            *(short *)(iVar16 + 0x67fef4) = sVar9;
            if (*(short *)(iVar16 + 0x67fee8) == 0) {
              if (local_18 < 0) {
                iVar12 = (iVar17 + local_24) * 2;
                local_18 = local_18 + *(short *)(iVar12 + 0x6803bc);
                local_2c = local_2c + *(short *)((iVar17 + local_24) * 2 + 0x6803c0);
                local_28 = local_28 + *(short *)(iVar12 + 0x6803c4);
              }
              else {
                iVar12 = (iVar17 + local_24) * 2;
                local_18 = local_18 + *(short *)(iVar12 + 0x6803be);
                local_2c = local_2c + *(short *)((iVar17 + local_24) * 2 + 0x6803c2);
                local_28 = local_28 + *(short *)(iVar12 + 0x6803c6);
              }
            }
            else {
              iVar12 = (iVar17 + local_24) * 2;
              local_2c = (int)*(short *)(iVar12 + 0x67ff0c);
              iVar12 = (int)*(short *)(iVar12 + 0x680164);
              local_24 = local_24 + 1;
              local_28 = iVar12;
            }
            if ((*(short *)(iVar16 + 0x67fef2) == local_2c) && (sVar9 == local_28)) {
              *(undefined2 *)(&DAT_0067fe72 + iVar16) = *(undefined2 *)(iVar16 + 0x67fe74);
              *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
              *(undefined4 *)(iVar16 + 0x67fe40) = 0;
              return;
            }
            *(undefined2 *)(iVar16 + 0x67ff08) = (undefined2)local_24;
            *(short *)(iVar16 + 0x67fef2) = (short)local_2c;
            uVar11 = (short)local_2c * 0x20 + 0x10;
            *(short *)(iVar16 + 0x67fef4) = (short)local_28;
            *(undefined2 *)(iVar16 + 0x67ff06) = (undefined2)local_18;
            uVar6 = f_429c70((uint)uVar11,
                             CONCAT22((short)((uint)iVar12 >> 0x10),(undefined2)local_18),
                             (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                             (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >> 0x10),uVar11,
                             (short)local_28 * 0x20 + 0x10);
            sVar9 = (short)uVar6;
            *(short *)(iVar16 + 0x67fe54) = sVar9;
            if (sVar9 != -1) {
              *(short *)(iVar16 + 0x67fe54) = sVar9 << 3;
            }
            if (*(short *)(iVar16 + 0x67fe80) == 0) {
              *(int *)(iVar16 + 0x67fe64) = (int)*(short *)(iVar16 + 0x67fe54);
            }
            sVar9 = *(short *)(iVar16 + 0x67fe74);
            if (sVar9 == 7) {
              *(undefined2 *)(&DAT_0067fe72 + iVar16) = 0;
              *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
              *(undefined4 *)(iVar16 + 0x67fe40) = 0;
              return;
            }
            if (sVar9 == 1) {
              if (local_2c != 0) {
                return;
              }
              if (*(int *)(&DAT_0067fe2c + iVar16) >> 0x15 != (int)*(short *)(iVar16 + 0x67fef0)) {
                return;
              }
              if (*(short *)(iVar16 + 0x67fee0) != 0) {
                *(undefined2 *)(iVar16 + 0x67fee0) = 0;
                *(undefined2 *)(iVar16 + 0x67fee4) = 0;
                *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
                *(undefined4 *)(iVar16 + 0x67fe40) = 0;
                sVar19 = *(short *)(iVar16 + 0x67fee6);
                if (sVar19 != -1) {
                  *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
                  *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
                }
                *(undefined2 *)(&DAT_0067fe72 + iVar16) = 5;
                return;
              }
              if (_DAT_004aee00 != 1) {
                return;
              }
              f_423710(sVar19,0x29a,-1,-1,
                       (ushort)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                       (ushort)((uint)*(int *)(&DAT_0067fe2c + iVar16) >> 0x10));
              return;
            }
            if (sVar9 != 2) {
              return;
            }
            if (*(short *)(iVar16 + 0x67fee0) == 0) {
              iVar12 = f_429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >> 0x10),
                                local_c,local_10);
              iVar12 = (int)(short)iVar12;
              if (*(short *)(iVar16 + 0x67fe56) != -1) {
                iVar14 = *(short *)(iVar16 + 0x67fe56) * 0xe0;
                iVar12 = iVar12 - (*(int *)(&DAT_00805e14 + iVar14) +
                                  *(int *)(&DAT_00805e10 + iVar14)) / 4;
              }
              if (*(short *)(&DAT_0067fea2 + iVar16) < iVar12) {
                return;
              }
              *(undefined2 *)(&DAT_0067fe72 + iVar16) = 3;
              return;
            }
            if (*(int *)(&DAT_0067fe28 + iVar16) >> 0x15 != (int)*(short *)(iVar16 + 0x67feee)) {
              return;
            }
            if (*(int *)(&DAT_0067fe2c + iVar16) >> 0x15 != (int)*(short *)(iVar16 + 0x67fef0)) {
              return;
            }
            *(undefined2 *)(iVar16 + 0x67fee0) = 0;
            *(undefined2 *)(iVar16 + 0x67fee4) = 0;
            *(undefined4 *)(iVar16 + 0x67fe3c) = 0;
            *(undefined4 *)(iVar16 + 0x67fe40) = 0;
            *(undefined2 *)(&DAT_0067fe72 + iVar16) = 5;
            sVar19 = *(short *)(iVar16 + 0x67fee6);
            if (sVar19 == -1) {
              return;
            }
            *(undefined2 *)(iVar16 + 0x67fee6) = 0xffff;
            *(undefined2 *)(&DAT_006e75c0 + sVar19 * 0x2ef4) = 0xffff;
            return;
          }
          *(int *)(&DAT_0067fe28 + iVar16) =
               *(int *)(iVar16 + 0x67fe3c) + *(int *)(&DAT_0067fe28 + iVar16);
          *(int *)(&DAT_0067fe2c + iVar16) =
               *(int *)(&DAT_0067fe2c + iVar16) + *(int *)(iVar16 + 0x67fe40);
          if (*(short *)(&DAT_0067fe72 + iVar16) != 3) {
            *(undefined2 *)(iVar16 + 0x67fe80) = 0;
            if (((*(short *)(iVar16 + 0x67fe7e) == 5) || (*(short *)(iVar16 + 0x67fe7e) == 8)) ||
               (_DAT_00803c40 < *(short *)(&DAT_0067fe10 + iVar16))) {
              iVar12 = 0;
              if (-1 < _DAT_006e5b38) {
                puVar15 = (ushort *)&DAT_0067fe10;
                do {
                  if (*(short *)(*(short *)(&DAT_0067fe12 + iVar16) * 0x4c + 0x4c0874) == 0) break;
                  uVar11 = *puVar15;
                  if ((uVar11 != 0) && (uVar11 != 99)) {
                    uVar2 = *(ushort *)(&DAT_0067fe10 + iVar16);
                    if (((((short)uVar2 <= _DAT_00803c40) || ((short)uVar11 < 0x5a)) &&
                        (((puVar15[6] != 0 && (uVar11 != uVar2)) && (iVar12 != param_1)))) &&
                       ((((short)puVar15[0x32a] < 0x78 ||
                         (*(int *)((uVar2 & 7) * 4 + 0x9094c0) != 0)) &&
                        (iVar14 = f_429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar16) >>
                                                  0x10),
                                           (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar16) >>
                                                  0x10),
                                           (short)((uint)*(undefined4 *)(puVar15 + 0xc) >> 0x10),
                                           (short)((uint)*(undefined4 *)(puVar15 + 0xe) >> 0x10)),
                        (short)iVar14 < *(short *)(&DAT_0067fea2 + iVar16))))) {
                      *(undefined2 *)(iVar16 + 0x67fe80) = 1;
                      uVar3 = *(undefined2 *)(&DAT_0067fe58 + iVar16);
                      *(short *)(&DAT_0067fe58 + iVar16) = (short)iVar12;
                      f_43efb0(param_1,(*(uint *)(&DAT_0067fe28 + iVar12 * 0x6d0) >> 0x10 & 0xffe0)
                                       + 0x10,
                               (*(uint *)(&DAT_0067fe2c + iVar12 * 0x6d0) >> 0x10 & 0xffe0) + 0x10);
                      *(undefined2 *)(&DAT_0067fe58 + iVar16) = uVar3;
                      break;
                    }
                  }
                  puVar15 = puVar15 + 0x368;
                  iVar12 = iVar12 + 1;
                } while (iVar12 <= _DAT_006e5b38);
              }
              *(undefined2 *)(iVar16 + 0x67fe80) = 0;
            }
          }
          _DAT_006dd174 = _DAT_006dd174 + 1;
        } while (_DAT_006dd174 < _DAT_006df0f8);
      }
    }
    local_8 = local_8 + 1;
    if ((int)local_1c < local_8) {
      return;
    }
  } while( true );
}



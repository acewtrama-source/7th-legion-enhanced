
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042bd90(short param_1,short param_2,int param_3)

{
  int *piVar1;
  ushort *puVar2;
  short *psVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  short sVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  char *pcVar19;
  short sVar20;
  char *pcVar21;
  int local_48;
  int local_30;
  int local_20;
  int local_18;
  short local_12;
  short sStack_10;
  short local_e;
  ushort local_c;
  short local_a;
  ushort local_6;
  
  iVar13 = param_3;
  local_6 = 0xffff;
  if (param_1 != -1) {
    iVar12 = (int)param_1;
    if ((int)(&DAT_00805e44)[iVar12 * 0x38] < 1) {
      return;
    }
    if ((&DAT_00805df0)[iVar12 * 0x38] == 0) {
      return;
    }
    if ((&DAT_00805df8)[iVar12 * 0x38] == 0) {
      return;
    }
    if ((DAT_0083e4d0 == 1) && ((&DAT_00805df4)[iVar12 * 0x38] == 0)) {
      return;
    }
    local_6 = (ushort)(&DAT_00805df0)[iVar12 * 0x38];
    local_48 = (&DAT_00805e44)[iVar12 * 0x38] - param_3;
  }
  if (param_2 != -1) {
    iVar12 = (int)param_2;
    if ((int)(&DAT_0067fe20)[iVar12 * 0x1b4] < 1) {
      return;
    }
    local_6 = (&DAT_0067fe10)[iVar12 * 0x368];
    if (local_6 == 0) {
      return;
    }
    if ((&DAT_0067fe1c)[iVar12 * 0x368] == 0) {
      return;
    }
    local_48 = (&DAT_0067fe20)[iVar12 * 0x1b4] - param_3;
    if ((short)(&DAT_0067fe24)[iVar12 * 0x368] * 0x10000 < local_48) {
      local_48 = (short)(&DAT_0067fe24)[iVar12 * 0x368] * 0x10000;
    }
  }
  if (local_6 == 0xffff) {
    return;
  }
  if (DAT_0071667c == 1) {
    if ((DAT_00803c40 < (short)local_6) && (DAT_004aee00 == 1)) {
      puVar18 = &DAT_00773410;
      for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar18 = 0;
        puVar18 = puVar18 + 1;
      }
      *(undefined2 *)puVar18 = 0;
      _DAT_00773414 = param_3;
      DAT_00773410._0_2_ = param_1;
      DAT_00773410._2_2_ = param_2;
      puVar18 = &DAT_00773410;
      _DAT_009e2d80 = 0x26;
      if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) == (int)DAT_00834f94) {
        _DAT_00773418 = local_48;
        _DAT_009e2d80 = 0x26;
        return;
      }
      iVar12 = 0;
      iVar13 = (short)DAT_0066ccf0 * 0x2a;
      _DAT_00773418 = local_48;
      (&DAT_00671a20)[iVar13] = 0xe;
      do {
        uVar4 = *(undefined1 *)puVar18;
        puVar18 = (undefined4 *)((int)puVar18 + 1);
        (&DAT_00671a22)[iVar12 + iVar13] = uVar4;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 0x26);
      DAT_0066ccf0 = DAT_0066ccf0 + 1;
      DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
      DAT_004af798 = DAT_004af798 + 1;
      DAT_004af79c = DAT_004af79c + 1;
      _DAT_00668910 = 0xe;
      return;
    }
    if (local_6 != DAT_00668ccc) {
      return;
    }
    puVar18 = &DAT_00773410;
    for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
    *(undefined2 *)puVar18 = 0;
    _DAT_00773414 = param_3;
    DAT_00773410._0_2_ = param_1;
    DAT_00773410._2_2_ = param_2;
    puVar18 = &DAT_00773410;
    _DAT_009e2d80 = 0x26;
    if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) == (int)DAT_00834f94) {
      _DAT_00773418 = local_48;
      _DAT_009e2d80 = 0x26;
      return;
    }
    iVar12 = 0;
    iVar13 = (short)DAT_0066ccf0 * 0x2a;
    _DAT_00773418 = local_48;
    (&DAT_00671a20)[iVar13] = 0xe;
    do {
      uVar4 = *(undefined1 *)puVar18;
      puVar18 = (undefined4 *)((int)puVar18 + 1);
      (&DAT_00671a22)[iVar12 + iVar13] = uVar4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0x26);
    DAT_0066ccf0 = DAT_0066ccf0 + 1;
    DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
    DAT_004af798 = DAT_004af798 + 1;
    DAT_004af79c = DAT_004af79c + 1;
    _DAT_00668910 = 0xe;
    return;
  }
  local_e = -1;
  local_a = -1;
  bVar8 = false;
  local_c = 0;
  if (param_1 != -1) {
    iVar14 = (int)param_1;
    iVar15 = iVar14 * 0xe0;
    iVar12 = (&DAT_00805e44)[iVar14 * 0x38];
    piVar1 = &DAT_00805e44 + iVar14 * 0x38;
    iVar10 = iVar12 - param_3;
    *piVar1 = iVar10;
    if ((&DAT_00805e48)[iVar14 * 0x38] * 0x10000 < iVar10) {
      *piVar1 = (&DAT_00805e48)[iVar14 * 0x38] * 0x10000;
    }
    local_e = *(short *)(&DAT_00805e70 + iVar15);
    local_a = *(short *)(&DAT_00805e6c + iVar15);
    if ((*piVar1 < 1) && (0 < iVar12)) {
      bVar8 = true;
    }
    sStack_10 = (short)((int)((&DAT_00805e10)[iVar14 * 0x38] << 5) >> 1) +
                (short)(&DAT_00805e08)[iVar14 * 0x38] * 0x20;
    local_12 = (short)((int)((&DAT_00805e14)[iVar14 * 0x38] << 5) >> 1) +
               (short)(&DAT_00805e0c)[iVar14 * 0x38] * 0x20;
    local_c = *(ushort *)(&DAT_00805df0 + iVar14 * 0x38);
    local_20 = (&DAT_00805e48)[iVar14 * 0x38] * 0x10000;
    if (local_20 < *piVar1) {
      *piVar1 = local_20;
    }
    if ((((bVar8) && (*(short *)(&DAT_00805e18 + iVar15) == 0)) && (local_c != local_6)) &&
       ((local_6 != 0 && (local_a != -1)))) {
      uVar5 = (&DAT_0067fe10)[local_a * 0x368];
      puVar2 = &DAT_0067fe10 + local_a * 0x368;
      if (((short)uVar5 < 7) && (0 < (short)uVar5)) {
        _sprintf(&DAT_0090a9d0,s__s_s__s__ss__s_004b8208,
                 (&PTR_DAT_004baf08)[(&DAT_00835260)[uVar5 & 7]],&DAT_0078b770 + (uVar5 & 7) * 0x80,
                 DAT_00909500,&DAT_0078b770 + (short)local_c * 0x80,
                 (&PTR_DAT_004bb7cc)[(&DAT_00805df4)[iVar14 * 0x38] * 0x81]);
        iVar12 = DAT_0092ab58 * 0x100;
        uVar16 = 0xffffffff;
        pcVar19 = &DAT_0090a9d0;
        do {
          pcVar21 = pcVar19;
          if (uVar16 == 0) break;
          uVar16 = uVar16 - 1;
          pcVar21 = pcVar19 + 1;
          cVar11 = *pcVar19;
          pcVar19 = pcVar21;
        } while (cVar11 != '\0');
        uVar16 = ~uVar16;
        pcVar19 = pcVar21 + -uVar16;
        pcVar21 = &DAT_0090a5c0 + iVar12;
        for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
          pcVar19 = pcVar19 + 4;
          pcVar21 = pcVar21 + 4;
        }
        for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *pcVar21 = *pcVar19;
          pcVar19 = pcVar19 + 1;
          pcVar21 = pcVar21 + 1;
        }
        (&DAT_0090a5ed)[iVar12] = 0;
        DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
        if (DAT_0092ab58 == DAT_009d5a44) {
          DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
        }
        DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
        iVar12 = (&DAT_00805df4)[iVar14 * 0x38];
        if (iVar12 != 6) {
          *(int *)(&DAT_007f7e00 + (*puVar2 & 7) * 4) =
               *(int *)(&DAT_007f7e00 + (*puVar2 & 7) * 4) + 2;
        }
        if (iVar12 == 0) {
          *(int *)(&DAT_007f7e00 + (*puVar2 & 7) * 4) =
               *(int *)(&DAT_007f7e00 + (*puVar2 & 7) * 4) + 2;
        }
        uVar16 = *puVar2 & 7;
        if (*(int *)(&DAT_004af830 + (&DAT_00835260)[uVar16] * 4) <=
            *(int *)(&DAT_007f7e00 + uVar16 * 4)) {
          iVar12 = (&DAT_00835260)[uVar16] + 1;
          (&DAT_00835260)[uVar16] = iVar12;
          if (iVar12 < 6) {
            _sprintf(&DAT_0090a9d0,&DAT_00864820,&DAT_0078b770 + uVar16 * 0x80,
                     (&PTR_DAT_004baee8)[iVar12]);
            iVar12 = DAT_0092ab58 * 0x100;
            uVar16 = 0xffffffff;
            pcVar19 = &DAT_0090a9d0;
            do {
              pcVar21 = pcVar19;
              if (uVar16 == 0) break;
              uVar16 = uVar16 - 1;
              pcVar21 = pcVar19 + 1;
              cVar11 = *pcVar19;
              pcVar19 = pcVar21;
            } while (cVar11 != '\0');
            uVar16 = ~uVar16;
            pcVar19 = pcVar21 + -uVar16;
            pcVar21 = &DAT_0090a5c0 + iVar12;
            for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
              *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
              pcVar19 = pcVar19 + 4;
              pcVar21 = pcVar21 + 4;
            }
            for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
              *pcVar21 = *pcVar19;
              pcVar19 = pcVar19 + 1;
              pcVar21 = pcVar21 + 1;
            }
            (&DAT_0090a5ed)[iVar12] = 0;
            DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
            if (DAT_0092ab58 == DAT_009d5a44) {
              DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
            }
            DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
            if ((*puVar2 == DAT_00668ccc) &&
               (((_sprintf(&DAT_0090a9d0,&DAT_00864870,
                           (&PTR_DAT_004baee8)[(&DAT_00835260)[(short)*puVar2]]), DAT_0083a3f0 != 1
                 || (iVar12 = _strncmp(&DAT_0090a9d0,&DAT_00864640,8), iVar12 == 0)) ||
                (iVar12 = _strncmp((char *)&DAT_0066d1a0,&DAT_00864640,8), iVar12 != 0)))) {
              uVar16 = 0xffffffff;
              DAT_0083a3f0 = 1;
              DAT_00834f80 = 0;
              pcVar19 = &DAT_0090a9d0;
              do {
                pcVar21 = pcVar19;
                if (uVar16 == 0) break;
                uVar16 = uVar16 - 1;
                pcVar21 = pcVar19 + 1;
                cVar11 = *pcVar19;
                pcVar19 = pcVar21;
              } while (cVar11 != '\0');
              uVar16 = ~uVar16;
              pcVar19 = pcVar21 + -uVar16;
              pcVar21 = (char *)&DAT_0066d1a0;
              for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
                pcVar19 = pcVar19 + 4;
                pcVar21 = pcVar21 + 4;
              }
              for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
                *pcVar21 = *pcVar19;
                pcVar19 = pcVar19 + 1;
                pcVar21 = pcVar21 + 1;
              }
              iVar12 = -1;
              pcVar19 = &DAT_0090a9d0;
              do {
                if (iVar12 == 0) break;
                iVar12 = iVar12 + -1;
                cVar11 = *pcVar19;
                pcVar19 = pcVar19 + 1;
              } while (cVar11 != '\0');
              DAT_008350e0 = ~(ushort)iVar12 - 1;
              DAT_00859526 = DAT_008350e0 * 2 + 300;
            }
          }
          else {
            (&DAT_00835260)[uVar16] = 5;
          }
        }
      }
    }
  }
  if (param_2 != -1) {
    iVar12 = (int)param_2;
    iVar10 = iVar12 * 0x6d0;
    if (((*(byte *)((int)&DAT_00680498 + iVar10 + 1) & 4) != 0) && (0 < param_3)) {
      param_3 = param_3 >> 1;
    }
    iVar14 = (&DAT_0067fe20)[iVar12 * 0x1b4];
    piVar1 = &DAT_0067fe20 + iVar12 * 0x1b4;
    param_3 = iVar14 - param_3;
    psVar3 = &DAT_0067fe24 + iVar12 * 0x368;
    *piVar1 = param_3;
    if (*psVar3 * 0x10000 < param_3) {
      *piVar1 = *psVar3 * 0x10000;
    }
    if ((*(short *)(&DAT_004c0874 + (short)(&DAT_0067fe12)[iVar12 * 0x368] * 0x4c) != 0) &&
       ((&DAT_006804dc)[iVar12 * 0x368] == 0)) {
      cVar11 = *piVar1 <= ((int)*psVar3 << 0x10) / 6;
      if (*piVar1 < 0x601) {
        cVar11 = '\x02';
      }
      if ((cVar11 != '\0') && ((((byte)DAT_006df3b0 & 0xf) == 5 || (cVar11 == '\x02')))) {
        (&DAT_006804dc)[iVar12 * 0x368] = 1;
        if (cVar11 == '\x02') {
          *piVar1 = 0x600;
        }
        iVar15 = (&DAT_0067fe28)[iVar12 * 0x1b4];
        iVar6 = (&DAT_0067fe2c)[iVar12 * 0x1b4];
        local_30 = 3;
        do {
          uVar16 = _rand();
          uVar16 = (uVar16 & 3) + 5;
          if (7 < uVar16) {
            uVar16 = 5;
          }
          FUN_00429de0(uVar16,1,iVar15 >> 0x10,iVar6 >> 0x10,0xffffffff,0xffffffff);
          local_30 = local_30 + -1;
        } while (local_30 != 0);
        if ((&DAT_0067feb4)[iVar12 * 0x368] != 0xffff) {
          bVar8 = true;
          local_6 = (&DAT_0067feb4)[iVar12 * 0x368];
        }
      }
    }
    local_e = (&DAT_0067feb6)[iVar12 * 0x368];
    local_a = (&DAT_0067feb4)[iVar12 * 0x368];
    if ((*piVar1 < 1) && (0 < iVar14)) {
      bVar8 = true;
    }
    if ((500 < *(short *)(&DAT_00680466 + iVar10)) && (*(short *)(&DAT_00680466 + iVar10) != 0x393))
    {
      bVar8 = false;
    }
    sStack_10 = (short)((uint)(&DAT_0067fe28)[iVar12 * 0x1b4] >> 0x10);
    local_12 = (short)((uint)(&DAT_0067fe2c)[iVar12 * 0x1b4] >> 0x10);
    local_c = (&DAT_0067fe10)[iVar12 * 0x368];
    local_20 = *psVar3 * 0x10000;
    if (local_20 < *piVar1) {
      *piVar1 = local_20;
    }
    if ((bVar8) && (local_a != -1)) {
      uVar5 = (&DAT_0067fe10)[local_a * 0x368];
      if (((short)uVar5 < 9) &&
         (((*(short *)(&DAT_0067fe38 + iVar10) == 0 && (local_c != local_6)) && (local_6 != 0)))) {
        iVar14 = (int)(short)uVar5;
        iVar12 = *(int *)(&DAT_007f7e00 + iVar14 * 4);
        iVar10 = (&DAT_00835260)[iVar14];
        *(int *)(&DAT_007f7e00 + iVar14 * 4) = iVar12 + 1;
        if (*(int *)(&DAT_004af830 + iVar10 * 4) <= iVar12 + 1) {
          iVar10 = iVar10 + 1;
          (&DAT_00835260)[iVar14] = iVar10;
          if (iVar10 < 6) {
            _sprintf(&DAT_0090a9d0,&DAT_008648c0,&DAT_0078b770 + iVar14 * 0x80,
                     (&PTR_DAT_004baee8)[iVar10]);
            iVar12 = DAT_0092ab58 * 0x100;
            uVar16 = 0xffffffff;
            pcVar19 = &DAT_0090a9d0;
            do {
              pcVar21 = pcVar19;
              if (uVar16 == 0) break;
              uVar16 = uVar16 - 1;
              pcVar21 = pcVar19 + 1;
              cVar11 = *pcVar19;
              pcVar19 = pcVar21;
            } while (cVar11 != '\0');
            uVar16 = ~uVar16;
            pcVar19 = pcVar21 + -uVar16;
            pcVar21 = &DAT_0090a5c0 + iVar12;
            for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
              *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
              pcVar19 = pcVar19 + 4;
              pcVar21 = pcVar21 + 4;
            }
            for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
              *pcVar21 = *pcVar19;
              pcVar19 = pcVar19 + 1;
              pcVar21 = pcVar21 + 1;
            }
            (&DAT_0090a5ed)[iVar12] = 0;
            DAT_0092ab58 = DAT_0092ab58 + 1 & 3;
            if (DAT_0092ab58 == DAT_009d5a44) {
              DAT_009d5a44 = DAT_009d5a44 + 1 & 3;
            }
            DAT_00909500 = (&PTR_DAT_004afbf0)[DAT_006df3b0 & 3];
            uVar5 = (&DAT_0067fe10)[local_a * 0x368];
            if ((uVar5 == DAT_00668ccc) &&
               (((_sprintf(&DAT_0090a9d0,&DAT_00864910,
                           (&PTR_DAT_004baee8)[(&DAT_00835260)[(short)uVar5]]), DAT_0083a3f0 != 1 ||
                 (iVar12 = _strncmp(&DAT_0090a9d0,&DAT_00864640,8), iVar12 == 0)) ||
                (iVar12 = _strncmp((char *)&DAT_0066d1a0,&DAT_00864640,8), iVar12 != 0)))) {
              uVar16 = 0xffffffff;
              DAT_0083a3f0 = 1;
              DAT_00834f80 = 0;
              pcVar19 = &DAT_0090a9d0;
              do {
                pcVar21 = pcVar19;
                if (uVar16 == 0) break;
                uVar16 = uVar16 - 1;
                pcVar21 = pcVar19 + 1;
                cVar11 = *pcVar19;
                pcVar19 = pcVar21;
              } while (cVar11 != '\0');
              uVar16 = ~uVar16;
              pcVar19 = pcVar21 + -uVar16;
              pcVar21 = (char *)&DAT_0066d1a0;
              for (uVar17 = uVar16 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                *(undefined4 *)pcVar21 = *(undefined4 *)pcVar19;
                pcVar19 = pcVar19 + 4;
                pcVar21 = pcVar21 + 4;
              }
              for (uVar16 = uVar16 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
                *pcVar21 = *pcVar19;
                pcVar19 = pcVar19 + 1;
                pcVar21 = pcVar21 + 1;
              }
              iVar12 = -1;
              pcVar19 = &DAT_0090a9d0;
              do {
                if (iVar12 == 0) break;
                iVar12 = iVar12 + -1;
                cVar11 = *pcVar19;
                pcVar19 = pcVar19 + 1;
              } while (cVar11 != '\0');
              DAT_008350e0 = ~(ushort)iVar12 - 1;
              DAT_00859526 = DAT_008350e0 * 2 + 300;
            }
          }
          else {
            (&DAT_00835260)[iVar14] = 5;
          }
        }
      }
    }
  }
  if (!bVar8) {
    return;
  }
  if ((param_2 != -1) && (*(short *)(&DAT_0067fe38 + param_2 * 0x6d0) != 0)) {
    bVar8 = false;
  }
  if ((param_1 != -1) && (*(short *)(&DAT_00805e18 + param_1 * 0xe0) != 0)) {
    bVar8 = false;
  }
  if (!bVar8) {
    return;
  }
  if (param_2 != -1) {
    *(undefined2 *)(&DAT_0067fe38 + param_2 * 0x6d0) = 1;
  }
  if (param_1 != -1) {
    *(undefined2 *)(&DAT_00805e18 + param_1 * 0xe0) = 1;
  }
  if ((local_a == -1) && (local_e == -1)) {
    return;
  }
  if (iVar13 == 0) {
    iVar13 = 0x1f40000;
  }
  iVar13 = (int)(CONCAT44(local_20 >> 0x10,local_20 << 0x10) / (longlong)iVar13);
  local_18 = (int)((iVar13 >> 0x10) + (iVar13 >> 0x1f & 3U)) >> 2;
  if (local_18 < 0) {
    local_18 = 0;
  }
  if (0xc < local_18) {
    local_18 = 0xc;
  }
  if ((param_2 == -1) && (param_1 != -1)) {
    local_18 = local_18 / 2;
  }
  local_6 = 0;
  if (local_e != -1) {
    local_6 = *(ushort *)(&DAT_00805df0 + local_e * 0x38);
  }
  if (local_a != -1) {
    local_6 = (&DAT_0067fe10)[local_a * 0x368];
  }
  if (bVar8) {
    if (local_a == -1) goto LAB_0042cc02;
    iVar13 = (short)local_6 * 4;
    iVar12 = (&DAT_009d6340)[(short)local_6];
    if (iVar12 != 0) {
      if (iVar12 == 1) {
        if (((*(int *)(&DAT_0090aad0 + iVar13) == (int)(short)local_c) && (param_1 != -1)) &&
           ((&DAT_00805df4)[param_1 * 0x38] == *(int *)(&DAT_009e2d90 + iVar13))) {
          *(undefined4 *)(&DAT_009dbbd0 + iVar13) = 0;
        }
      }
      else if ((iVar12 == 2) &&
              (((*(int *)(&DAT_0090aad0 + iVar13) == (int)(short)local_c && (param_2 != -1)) ||
               ((0x59 < (short)local_c && (((short)local_c < 99 && (param_2 != -1)))))))) {
        *(int *)(&DAT_009dbbd0 + iVar13) = *(int *)(&DAT_009dbbd0 + iVar13) + -1;
      }
    }
  }
  if (local_a != -1) {
    if (local_c == local_6) {
      return;
    }
    if (bVar8) {
      sVar20 = 0;
      if (-1 < DAT_006e5b38) {
        do {
          iVar13 = (int)sVar20;
          if (((((&DAT_0067fe10)[iVar13 * 0x368] != 0) && ((&DAT_0067fe1c)[iVar13 * 0x368] != 0)) &&
              ((&DAT_0067fe10)[local_a * 0x368] == (&DAT_0067fe10)[iVar13 * 0x368])) &&
             (*(short *)(&DAT_0067fe72 + iVar13 * 0x6d0) == 3)) {
            bVar7 = false;
            if ((param_2 != -1) && (*(short *)(&DAT_0067fe58 + iVar13 * 0x6d0) == param_2)) {
              bVar7 = true;
              (&DAT_0067fec0)[iVar13 * 0x368] =
                   (&DAT_0067fec0)[iVar13 * 0x368] + (short)(local_18 / 3) + 1;
            }
            if ((param_1 != -1) && ((&DAT_0067fe56)[iVar13 * 0x368] == param_1)) {
              bVar7 = true;
              (&DAT_0067fec0)[iVar13 * 0x368] =
                   (&DAT_0067fec0)[iVar13 * 0x368] + (short)(local_18 / 3) + 1;
            }
            if (((bVar7) &&
                (sVar9 = (&DAT_0067febe)[iVar13 * 0x368],
                *(short *)(&DAT_004af820 + sVar9 * 2) <= (short)(&DAT_0067fec0)[iVar13 * 0x368])) &&
               (sVar9 < 4)) {
              (&DAT_0067febe)[iVar13 * 0x368] = sVar9 + 1;
              sVar9 = (short)((uint)(&DAT_0067fe2c)[iVar13 * 0x1b4] >> 0x10);
              sVar9 = FUN_00429de0(0x1c,1,(int)(&DAT_0067fe28)[iVar13 * 0x1b4] >> 0x10,
                                   CONCAT22(sVar9 >> 0xf,sVar9 + 8),0xffffffff,0xffffffff);
              if (sVar9 != -1) {
                (&DAT_0071b65c)[sVar9 * 0x104] = 999;
              }
              sVar9 = (&DAT_0067fe24)[iVar13 * 0x368];
              (&DAT_0067fe24)[iVar13 * 0x368] = sVar9 + 2;
              iVar12 = ((short)(sVar9 + 2) * 0x10000) / 2 + (&DAT_0067fe20)[iVar13 * 0x1b4];
              (&DAT_0067fe20)[iVar13 * 0x1b4] = iVar12;
              if ((short)(&DAT_0067fe24)[iVar13 * 0x368] * 0x10000 < iVar12) {
                (&DAT_0067fe20)[iVar13 * 0x1b4] = (short)(&DAT_0067fe24)[iVar13 * 0x368] * 0x10000;
              }
              sVar9 = (&DAT_0067fe10)[iVar13 * 0x368];
              if (sVar9 < 9) {
                if ((int)(&DAT_009d5ff0)[sVar9] < (int)(short)(&DAT_0067febe)[iVar13 * 0x368]) {
                  (&DAT_009d5ff0)[sVar9] = (int)(short)(&DAT_0067febe)[iVar13 * 0x368];
                }
              }
            }
          }
          sVar20 = sVar20 + 1;
        } while (sVar20 <= DAT_006e5b38);
      }
      iVar13 = DAT_0083e4d0;
      if ((local_a != -1) && (sVar20 = (&DAT_0067fe10)[local_a * 0x368], sVar20 < 9)) {
        (&DAT_009d5a00)[sVar20] = (&DAT_009d5a00)[sVar20] + 1;
        (&DAT_00994980)[sVar20] = (&DAT_00994980)[sVar20] + 1;
        if (iVar13 == 2) {
          (&DAT_009d6b70)[sVar20] = (&DAT_009d6b70)[sVar20] + 1;
        }
      }
    }
  }
LAB_0042cc02:
  if (((local_c != local_6) && (local_6 != 0)) && (bVar8)) {
    sVar20 = FUN_00429de0(0x1c,1,CONCAT22(local_e,sStack_10),CONCAT22(sStack_10,local_12),0xffffffff
                          ,0xffffffff);
    if (sVar20 != -1) {
      iVar13 = *(int *)(&DAT_00834a00 + (short)local_6 * 4);
      (&DAT_0071b65c)[sVar20 * 0x104] = local_18;
      *(int *)(&DAT_00834a00 + (short)local_6 * 4) = iVar13 + *(int *)(local_18 * 4 + 0x4af7e0);
    }
    if (param_2 != -1) {
      *(undefined2 *)(&DAT_0067fe38 + param_2 * 0x6d0) = 1;
    }
    if (param_1 != -1) {
      *(undefined2 *)(&DAT_00805e18 + param_1 * 0xe0) = 1;
    }
  }
  return;
}



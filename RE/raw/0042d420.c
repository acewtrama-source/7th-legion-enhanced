
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042d420(uint param_1)

{
  undefined1 uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar10;
  uint uVar7;
  int iVar8;
  int iVar9;
  char cVar11;
  uint uVar12;
  ushort *puVar13;
  undefined4 *puVar14;
  int iVar15;
  ushort *puVar16;
  int iVar17;
  bool bVar18;
  undefined4 uVar19;
  short local_34 [8];
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_34[0] = 0xbbc;
  local_34[1] = 0xbd0;
  local_34[2] = 0xbe4;
  local_34[3] = 0xbf8;
  local_34[4] = 0xbe3;
  local_34[5] = 0xbf7;
  local_34[6] = 0xbf4;
  local_34[7] = 0xbbc;
  iVar4 = (int)(short)param_1;
  local_8 = iVar4 * 0x6d0;
  uVar3 = (&DAT_0067fe10)[iVar4 * 0x368];
  if (uVar3 == 0) {
    return;
  }
  if (DAT_0071667c == 1) {
    if ((short)uVar3 <= DAT_00803c40) {
      if (uVar3 != DAT_00668ccc) {
        (&DAT_0067fe1c)[iVar4 * 0x368] = 0;
        return;
      }
      if ((&DAT_0067fe1c)[iVar4 * 0x368] != 1) {
        return;
      }
      (&DAT_0067fe1c)[iVar4 * 0x368] = 0;
      puVar14 = &DAT_00773410;
      for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      *(undefined2 *)puVar14 = 0;
      DAT_00773410._0_2_ = 0xffff;
      puVar14 = &DAT_00773410;
      _DAT_009e2d80 = 0x26;
      DAT_00773410._2_2_ = (short)param_1;
      if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) == (int)DAT_00834f94) {
        DAT_00773410._0_2_ = 0xffff;
        _DAT_009e2d80 = 0x26;
        return;
      }
      iVar5 = 0;
      iVar4 = (short)DAT_0066ccf0 * 0x2a;
      (&DAT_00671a20)[iVar4] = 0xb;
      do {
        uVar1 = *(undefined1 *)puVar14;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
        (&DAT_00671a22)[iVar5 + iVar4] = uVar1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0x26);
      DAT_0066ccf0 = DAT_0066ccf0 + 1;
      DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
      DAT_004af798 = DAT_004af798 + 1;
      DAT_004af79c = DAT_004af79c + 1;
      _DAT_00668910 = 0xb;
      return;
    }
    if (DAT_004aee00 != 1) {
      (&DAT_0067fe1c)[iVar4 * 0x368] = 0;
      return;
    }
    if ((&DAT_0067fe1c)[iVar4 * 0x368] != 1) {
      return;
    }
    (&DAT_0067fe1c)[iVar4 * 0x368] = 0;
    puVar14 = &DAT_00773410;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    *(undefined2 *)puVar14 = 0;
    DAT_00773410._0_2_ = 0xffff;
    puVar14 = &DAT_00773410;
    _DAT_009e2d80 = 0x26;
    DAT_00773410._2_2_ = (short)param_1;
    if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) == (int)DAT_00834f94) {
      DAT_00773410._0_2_ = 0xffff;
      _DAT_009e2d80 = 0x26;
      return;
    }
    iVar5 = 0;
    iVar4 = (short)DAT_0066ccf0 * 0x2a;
    (&DAT_00671a20)[iVar4] = 0xb;
    do {
      uVar1 = *(undefined1 *)puVar14;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
      (&DAT_00671a22)[iVar5 + iVar4] = uVar1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x26);
    DAT_0066ccf0 = DAT_0066ccf0 + 1;
    DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
    DAT_004af798 = DAT_004af798 + 1;
    DAT_004af79c = DAT_004af79c + 1;
    _DAT_00668910 = 0xb;
    return;
  }
  iVar5 = (&DAT_0067fe28)[iVar4 * 0x1b4];
  local_14 = iVar5 >> 0x10;
  iVar8 = (&DAT_0067fe2c)[iVar4 * 0x1b4];
  local_18 = iVar8 >> 0x10;
  if (*(short *)(&DAT_004c0874 + (short)(&DAT_0067fe12)[iVar4 * 0x368] * 0x4c) == 0)
  goto LAB_0042dbf2;
  local_10 = iVar8 >> 0x15;
  local_24 = CONCAT22(local_24._2_2_,(short)(iVar8 >> 0x15));
  iVar4 = iVar5 >> 0x15;
  local_20 = CONCAT22(local_20._2_2_,(short)(iVar5 >> 0x15));
  FUN_00416e20(DAT_0085959c,DAT_00719fdc,local_20,local_24);
  sVar2 = FUN_00429de0(4,1,local_14,local_18,0xffffffff,0xffffffff);
  bVar18 = DAT_005474a0 != 1;
  *(int *)(&DAT_009e3bc0 + DAT_00719fdc * 4) = (int)sVar2;
  if (bVar18) {
    iVar5 = DAT_009d49c0 * 4;
    DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
    uVar3 = ((ushort)*(undefined4 *)(&DAT_004afc00 + iVar5) & 1) + 1;
    uVar6 = (uint)uVar3;
    if (DAT_005474a0 == 2) {
      uVar6 = (uint)(int)(short)uVar3 / 2;
    }
    for (sVar2 = (short)uVar6; sVar2 != 0; sVar2 = sVar2 + -1) {
      uVar10 = (undefined2)(uVar6 >> 0x10);
      iVar5 = DAT_009d49c0 * 4;
      uVar6 = DAT_009d49c0 + 1 & 0x3ff;
      DAT_009d49c0 = uVar6 + 1 & 0x3ff;
      if (DAT_004af814 == 0) {
        uVar19 = 0xc;
      }
      else {
        uVar19 = 0x1e;
      }
      uVar6 = FUN_00429de0(uVar19,1,((*(uint *)(&DAT_004afc00 + iVar5) & 7) - 3) +
                                    CONCAT22(uVar10,(short)local_14),
                           CONCAT22(uVar10,(short)local_18) + -3 +
                           (*(uint *)(&DAT_004afc00 + uVar6 * 4) & 7),0xffffffff,0xffffffff);
    }
  }
  local_1c = param_1 & 1;
  local_c = local_1c + 3 + (*(uint *)(&DAT_004afc00 + DAT_009d49c0 * 4) & 1);
  DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
  if (*(short *)(&DAT_004c0874 + *(short *)((int)&DAT_0067fe12 + local_8) * 0x4c) == 3) {
    local_c = local_c + 1;
  }
  if (DAT_005474a0 == 3) {
    local_c = local_c * 2;
  }
  uVar6 = 0;
  if (local_c != 0) {
    do {
      iVar5 = (*(uint *)(&DAT_004afc00 + DAT_009d49c0 * 4) & 0xf) - 7;
      uVar7 = (uVar6 & 3) + 5;
      uVar12 = DAT_009d49c0 + 1 & 0x3ff;
      DAT_009d49c0 = uVar12 + 1 & 0x3ff;
      if (7 < uVar7) {
        uVar7 = 5;
      }
      uVar6 = uVar6 + 1;
      FUN_00429de0(uVar7,1,CONCAT22((short)((uint)iVar5 >> 0x10),(short)iVar5 + (short)local_14),
                   (short)local_18 +
                   (((ushort)*(undefined4 *)(&DAT_004afc00 + uVar12 * 4) & 0xf) - 7),0xffffffff,
                   0xffffffff);
    } while ((int)uVar6 < local_c);
  }
  uVar6 = local_1c;
  if ((0x20 < *(short *)((int)&DAT_0067fe12 + local_8)) &&
     (*(short *)((int)&DAT_0067fe12 + local_8) < 0x27)) {
    uVar6 = 1;
  }
  if (uVar6 == 0) {
    iVar5 = iVar4 + 1;
    local_14 = local_10 + 1;
    iVar8 = iVar4 + -1;
    local_c = local_10 + -1;
    if (0x7f < iVar5) {
      iVar5 = 0x7f;
    }
    if (0x7f < (int)local_14) {
      local_14 = 0x7f;
    }
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    if (local_c < 0) {
      local_c = 0;
    }
    iVar4 = iVar4 * 0x80;
    if ((((((&DAT_008352f0)[iVar4 + local_10] != '\x01') ||
          ((*(byte *)((int)&DAT_008464f0 + iVar4 + local_10) & 0xf) != 0)) ||
         (iVar5 = iVar5 * 0x80 + local_10, (&DAT_008352f0)[iVar5] != '\x01')) ||
        ((local_18 = iVar8 * 0x80 + local_10, (&DAT_008352f0)[local_18] != '\x01' ||
         ((&DAT_008352f0)[local_14 + iVar4] != '\x01')))) ||
       (((&DAT_008352f0)[local_c + iVar4] != '\x01' ||
        (0x824 < (ushort)(&DAT_00773450)[local_10 + iVar4])))) goto LAB_0042dbf2;
    iVar8 = 0;
    uVar6 = _rand();
    uVar6 = uVar6 & 7;
    local_1c = (uint)(ushort)(&DAT_00773450)[iVar5];
    do {
      uVar7 = (uint)local_34[uVar6];
      if ((((ushort)(&DAT_00773450)[iVar5] != uVar7) && ((ushort)(&DAT_00773450)[local_18] != uVar7)
          ) && (((ushort)(&DAT_00773450)[local_14 + iVar4] != uVar7 &&
                ((ushort)(&DAT_00773450)[local_c + iVar4] != uVar7)))) break;
      iVar8 = iVar8 + 1;
      uVar6 = uVar6 + 1 & 7;
    } while (iVar8 != 8);
    if (iVar8 == 8) goto LAB_0042dbf2;
    (&DAT_00773450)[local_10 + iVar4] = local_34[uVar6];
    uVar6 = local_20;
    uVar7 = local_24;
  }
  else {
    local_14 = _rand();
    local_14 = local_14 & 7;
    if (((0x20 < *(short *)((int)&DAT_0067fe12 + local_8)) &&
        (*(short *)((int)&DAT_0067fe12 + local_8) < 0x27)) && (local_14 == 0)) {
      local_14 = 1;
    }
    uVar6 = _rand();
    sVar2 = *(short *)((int)&DAT_0067fe10 + local_8);
    local_c = (uVar6 & 1) * 0x14 + local_14;
    local_18 = CONCAT22(local_18._2_2_,sVar2);
    if ((*(short *)((int)&DAT_006df140 + sVar2 * 2) == 1) ||
       (*(short *)((int)&DAT_0067fe14 + local_8) == 1)) {
      local_c = local_c + 0x28;
    }
    bVar18 = false;
    iVar5 = -1;
    local_10 = iVar4 * 0x80 + local_10;
    local_1c = local_10 * 2;
    puVar16 = &DAT_0077334e + local_10;
    do {
      iVar4 = -1;
      puVar13 = puVar16;
      do {
        uVar3 = *puVar13;
        if ((0x102e < uVar3) && (uVar3 < 0x1072)) {
          bVar18 = true;
        }
        if ((0xe45 < uVar3) && (uVar3 < 0x102f)) {
          bVar18 = true;
        }
        if ((2999 < uVar3) && (uVar3 < 0xbf9)) {
          bVar18 = true;
        }
        if ((0xd57 < uVar3) && (uVar3 < 0xe46)) {
          bVar18 = true;
        }
        if (bVar18) goto LAB_0042daec;
        puVar13 = puVar13 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
      puVar16 = puVar16 + 0x80;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
LAB_0042daec:
    if (bVar18) goto LAB_0042dbf2;
    (&DAT_00773450)[local_10] = (short)local_c + 0x102f;
    *(byte *)((int)&DAT_008464f0 + local_10) = ((byte)sVar2 & 7) << 4;
    FUN_0041e900(local_20,local_24,1,1);
    if (2 < (int)local_14) goto LAB_0042dbf2;
    uVar6 = _rand();
    iVar4 = local_c + 4;
    iVar5 = local_10 + (uVar6 & 1);
    if ((&DAT_00835370)[iVar5] == '\x01') {
      (&DAT_00773550)[iVar5] = (short)iVar4 + 0x102f;
      uVar7 = CONCAT31((int3)(CONCAT22((short)((uint)iVar4 >> 0x10),
                                       *(undefined2 *)((int)&DAT_0067fe10 + local_8)) >> 8),
                       (char)*(undefined2 *)((int)&DAT_0067fe10 + local_8)) & 0xffffff07;
      cVar11 = (char)uVar7 << 4;
      iVar4 = CONCAT31((int3)(uVar7 >> 8),cVar11);
      (&DAT_00846570)[iVar5] = cVar11;
    }
    FUN_0041e900((short)local_20 + 1,
                 CONCAT22((short)((uint)iVar4 >> 0x10),(short)local_24 + (short)(uVar6 & 1)),1,1);
    uVar6 = _rand();
    iVar4 = local_10 + -(uVar6 & 1);
    if ((&DAT_00835270)[iVar4] == '\x01') {
      (&DAT_00773350)[iVar4] = (short)local_c + 0x1032;
      (&DAT_00846470)[iVar4] = ((byte)*(undefined2 *)((int)&DAT_0067fe10 + local_8) & 7) << 4;
    }
    uVar7 = (uint)(ushort)((short)local_24 + (short)-(uVar6 & 1));
    uVar6 = (uint)(ushort)((short)local_20 - 1);
  }
  FUN_0041e900(uVar6,uVar7,1,1);
LAB_0042dbf2:
  if ((*(byte *)((int)&DAT_00680498 + local_8) & 8) != 0) {
    sVar2 = FUN_00429de0(0x1d,1,*(int *)((int)&DAT_0067fe28 + local_8) >> 0x10,
                         *(int *)((int)&DAT_0067fe2c + local_8) >> 0x10,0xffffffff,0xffffffff);
    *(uint *)((int)&DAT_00680498 + local_8) = *(uint *)((int)&DAT_00680498 + local_8) & 0xfffffff7;
    if (sVar2 != -1) {
      *(undefined4 *)(&DAT_0071b688 + sVar2 * 0x410) = 1;
    }
  }
  uVar3 = *(ushort *)((int)&DAT_0067fe10 + local_8);
  if (uVar3 == DAT_00668ccc) {
    DAT_00773400 = DAT_00773400 + 0x30;
  }
  else {
    (&DAT_00719fb0)[uVar3 & 7] = (&DAT_00719fb0)[uVar3 & 7] + 0x30;
  }
  iVar4 = (int)(short)uVar3;
  local_8 = (int)*(short *)((int)&DAT_0067fe12 + local_8);
  FUN_004210c0(param_1);
  if (((DAT_0083e4d0 == 2) && (iVar4 < 7)) && (DAT_004aee00 == 1)) {
    iVar5 = (&DAT_009d6b70)[iVar4];
    (&DAT_009d6b70)[iVar4] = iVar5 - 1U;
    iVar5 = (iVar5 - 1U & 3) + 1 + (DAT_004b6528 & 1);
    DAT_004b6528 = 1 - (DAT_004b6528 & 1);
    iVar8 = (&DAT_006dd250)[iVar5];
    do {
      iVar15 = 0;
      iVar17 = (&DAT_006dd210)[iVar5];
      do {
        iVar9 = iVar17 * 0x80 + iVar8;
        if (((&DAT_008352f0)[iVar9] == '\x01') && (*(char *)((int)&DAT_006d3920 + iVar9) == '\0')) {
          FUN_00424c20(local_8,iVar4,CONCAT22((short)((uint)iVar17 >> 0x10),(short)iVar17 << 5),
                       CONCAT22((short)((uint)iVar8 >> 0x10),(short)iVar8 << 5),0);
          return;
        }
        iVar17 = iVar17 + 2;
        iVar15 = iVar15 + 1;
      } while ((iVar15 < 6) && (iVar17 < 0x80));
      iVar8 = iVar8 + 1;
    } while( true );
  }
  return;
}



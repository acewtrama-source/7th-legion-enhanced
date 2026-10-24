
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042ccc0(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  uint local_14;
  int local_8;
  
  if ((DAT_0083e4d0 == 1) && (iVar9 = (int)(short)param_1, (&DAT_00805df4)[iVar9 * 0x38] == 0)) {
    (&DAT_00805e44)[iVar9 * 0x38] = (&DAT_00805e48)[iVar9 * 0x38] << 0x10;
    return;
  }
  if (DAT_0071667c == 1) {
    iVar9 = (int)(short)param_1;
    if ((int)DAT_00803c40 < (int)(&DAT_00805df0)[iVar9 * 0x38]) {
      if ((DAT_004aee00 == 1) && ((&DAT_00805df8)[iVar9 * 0x38] == 1)) {
        puVar12 = &DAT_00773410;
        for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
        }
        *(undefined2 *)puVar12 = 0;
        DAT_00773410._2_2_ = 0xffff;
        puVar12 = &DAT_00773410;
        _DAT_009e2d80 = 0x26;
        DAT_00773410._0_2_ = (short)param_1;
        if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) != (int)DAT_00834f94) {
          iVar6 = 0;
          iVar9 = (short)DAT_0066ccf0 * 0x2a;
          (&DAT_00671a20)[iVar9] = 0xb;
          do {
            uVar1 = *(undefined1 *)puVar12;
            puVar12 = (undefined4 *)((int)puVar12 + 1);
            (&DAT_00671a22)[iVar6 + iVar9] = uVar1;
            iVar6 = iVar6 + 1;
          } while (iVar6 < 0x26);
          DAT_0066ccf0 = DAT_0066ccf0 + 1;
          DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
          DAT_004af798 = DAT_004af798 + 1;
          DAT_004af79c = DAT_004af79c + 1;
          _DAT_00668910 = 0xb;
          return;
        }
      }
    }
    else if (((int)DAT_00668ccc == (&DAT_00805df0)[iVar9 * 0x38]) &&
            ((&DAT_00805df8)[iVar9 * 0x38] == 1)) {
      puVar12 = &DAT_00773410;
      for (iVar9 = 9; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      *(undefined2 *)puVar12 = 0;
      DAT_00773410._2_2_ = 0xffff;
      puVar12 = &DAT_00773410;
      _DAT_009e2d80 = 0x26;
      DAT_00773410._0_2_ = (short)param_1;
      if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) != (int)DAT_00834f94) {
        iVar6 = 0;
        iVar9 = (short)DAT_0066ccf0 * 0x2a;
        (&DAT_00671a20)[iVar9] = 0xb;
        do {
          uVar1 = *(undefined1 *)puVar12;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          (&DAT_00671a22)[iVar6 + iVar9] = uVar1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0x26);
        DAT_0066ccf0 = DAT_0066ccf0 + 1;
        DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
        DAT_004af798 = DAT_004af798 + 1;
        DAT_004af79c = DAT_004af79c + 1;
        _DAT_00668910 = 0xb;
        return;
      }
    }
  }
  else {
    FUN_004207a0(param_1);
    iVar7 = (int)(short)param_1;
    iVar9 = (&DAT_00805e08)[iVar7 * 0x38];
    iVar6 = (&DAT_00805df4)[iVar7 * 0x38];
    iVar13 = (&DAT_00805e0c)[iVar7 * 0x38];
    iVar14 = (&DAT_00805e10)[iVar7 * 0x38];
    iVar2 = (&DAT_00805e14)[iVar7 * 0x38];
    FUN_00420240(param_1);
    iVar9 = iVar9 * 0x20 + ((iVar14 << 5) >> 1);
    iVar13 = iVar13 * 0x20 + ((iVar2 << 5) >> 1);
    iVar14 = -1;
    sVar3 = (short)iVar9;
    uVar8 = (undefined2)((uint)iVar9 >> 0x10);
    if (iVar6 != 6) {
      sVar4 = FUN_00429de0(0xb,1,CONCAT22(uVar8,sVar3 + -0x10),iVar13,0xffffffff,0xffffffff);
      iVar14 = (int)sVar4;
      if (iVar14 != -1) {
        *(uint *)(&DAT_0071b638 + iVar14 * 0x410) = iVar13 + iVar14 & 3;
        (&DAT_0071b630)[iVar14 * 0x104] = iVar9 + iVar14 & 3;
      }
    }
    if ((&DAT_00805df4)[iVar7 * 0x38] != 6) {
      sVar4 = FUN_00429de0(0x20,1,CONCAT22(uVar8,sVar3 + -8),iVar13,0xffffffff,0xffffffff);
      iVar14 = (int)sVar4;
      if (iVar14 != -1) {
        *(undefined4 *)(&DAT_0071b640 + iVar14 * 0x410) = 0x96;
        *(uint *)(&DAT_0071b638 + iVar14 * 0x410) = iVar9 + iVar14 & 3;
        (&DAT_0071b630)[iVar14 * 0x104] = iVar13 + iVar14 & 3;
      }
    }
    uVar10 = iVar13 >> 5;
    iVar9 = iVar9 >> 5;
    if ((&DAT_00805df4)[iVar7 * 0x38] == 0) {
      FUN_00416e20(DAT_00859684,DAT_0071a0c4,iVar9,uVar10);
      uVar15 = DAT_00859684;
      iVar6 = DAT_0071a0c4;
      *(int *)(&DAT_009e3bc0 + DAT_0071a0c4 * 4) = iVar14;
      local_14 = uVar10;
    }
    else {
      local_14 = uVar10 & 0xffff;
      FUN_00416e20(DAT_008595a0,DAT_00719fe0,iVar9,local_14);
      uVar15 = DAT_008595a0;
      iVar6 = DAT_00719fe0;
      *(int *)(&DAT_009e3bc0 + DAT_00719fe0 * 4) = iVar14;
    }
    FUN_00416e20(uVar15,iVar6,iVar9,local_14);
    iVar6 = (&DAT_00805df4)[iVar7 * 0x38];
    if (iVar6 != 6) {
      if ((int)DAT_00668ccc == (&DAT_00805df0)[iVar7 * 0x38]) {
        DAT_00773400 = DAT_00773400 + 0x5f;
      }
      else {
        (&DAT_00719fb0)[(&DAT_00805df0)[iVar7 * 0x38]] =
             (&DAT_00719fb0)[(&DAT_00805df0)[iVar7 * 0x38]] + 0x5f;
      }
    }
    if ((((DAT_007168ce + -1 <= iVar9) && (DAT_0071693e + -1 <= (int)uVar10)) &&
        (iVar9 <= (int)DAT_0080315c + (int)DAT_007168ce + 1)) &&
       ((int)uVar10 <= (int)DAT_007166a4 + (int)DAT_0071693e + 1)) {
      if (iVar6 == 6) {
        local_8 = (int)DAT_005474a0;
        if (DAT_005474a0 == 3) {
          local_8 = 6;
        }
        if (0 < local_8) {
          sVar4 = DAT_007168ce >> 0xf;
          do {
            if (DAT_005474a0 != 1) {
              iVar9 = DAT_009d49c0 * 4;
              DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
              sVar5 = ((ushort)*(undefined4 *)(&DAT_004afc00 + iVar9) & 1) + 1;
              if (DAT_005474a0 == 2) {
                sVar5 = (short)((uint)(int)sVar5 / 2);
              }
              for (; sVar5 != 0; sVar5 = sVar5 + -1) {
                iVar9 = DAT_009d49c0 * 4;
                uVar10 = DAT_009d49c0 + 1 & 0x3ff;
                DAT_009d49c0 = uVar10 + 1 & 0x3ff;
                if (DAT_004af814 == 0) {
                  uVar15 = 0xc;
                }
                else {
                  uVar15 = 0x1e;
                }
                FUN_00429de0(uVar15,1,((*(uint *)(&DAT_004afc00 + iVar9) & 7) - 3) +
                                      CONCAT22(sVar4,sVar3),
                             ((*(uint *)(&DAT_004afc00 + uVar10 * 4) & 7) - 3) + iVar13,0xffffffff,
                             0xffffffff);
              }
            }
            local_8 = local_8 + -1;
          } while (local_8 != 0);
          return;
        }
      }
      else {
        iVar9 = DAT_009d49c0 * 4;
        DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
        iVar9 = DAT_005474a0 + 1 + (*(uint *)(&DAT_004afc00 + iVar9) & 1);
        if (DAT_005474a0 == 3) {
          iVar9 = iVar9 * 2;
        }
        if (0 < iVar9) {
          do {
            uVar10 = DAT_009d49c0 + 1 & 0x3ff;
            iVar14 = (*(uint *)(&DAT_004afc00 + DAT_009d49c0 * 4) & 0x3f) - 0x20;
            uVar11 = uVar10 + 1 & 0x3ff;
            iVar6 = (*(uint *)(&DAT_004afc00 + uVar10 * 4) & 0x3f) - 0x20;
            DAT_009d49c0 = uVar11 + 1 & 0x3ff;
            uVar10 = (*(uint *)(&DAT_004afc00 + uVar11 * 4) & 3) + 5;
            if (7 < uVar10) {
              uVar10 = 5;
            }
            FUN_00429de0(uVar10,1,CONCAT22((short)((uint)iVar14 >> 0x10),(short)iVar14 + sVar3),
                         CONCAT22((short)((uint)iVar6 >> 0x10),(short)iVar6 + (short)iVar13),
                         0xffffffff,0xffffffff);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar9 = DAT_009d49c0 * 4;
        DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
        iVar9 = DAT_005474a0 + 1 + (*(uint *)(&DAT_004afc00 + iVar9) & 1);
        if (DAT_005474a0 == 3) {
          iVar9 = iVar9 * 2;
        }
        iVar6 = iVar9;
        if (0 < iVar9) {
          do {
            uVar10 = DAT_009d49c0 + 1 & 0x3ff;
            iVar14 = (*(uint *)(&DAT_004afc00 + DAT_009d49c0 * 4) & 0x3f) - 0x20;
            uVar11 = uVar10 + 1 & 0x3ff;
            iVar6 = (*(uint *)(&DAT_004afc00 + uVar10 * 4) & 0x3f) - 0x20;
            DAT_009d49c0 = uVar11 + 1 & 0x3ff;
            uVar10 = (*(uint *)(&DAT_004afc00 + uVar11 * 4) & 3) + 8;
            if (10 < uVar10) {
              uVar10 = 8;
            }
            FUN_00429de0(uVar10,1,CONCAT22((short)((uint)iVar14 >> 0x10),(short)iVar14 + sVar3),
                         CONCAT22((short)((uint)iVar6 >> 0x10),(short)iVar6 + (short)iVar13),
                         0xffffffff,0xffffffff);
            iVar9 = iVar9 + -1;
            iVar6 = 0;
          } while (iVar9 != 0);
        }
        local_8 = (int)DAT_005474a0;
        if (0 < local_8) {
          do {
            if (DAT_005474a0 != 1) {
              iVar9 = DAT_009d49c0 * 4;
              DAT_009d49c0 = DAT_009d49c0 + 1 & 0x3ff;
              sVar4 = ((ushort)*(undefined4 *)(&DAT_004afc00 + iVar9) & 1) + 1;
              if (DAT_005474a0 == 2) {
                sVar4 = (short)((uint)(int)sVar4 / 2);
              }
              for (; sVar4 != 0; sVar4 = sVar4 + -1) {
                iVar9 = DAT_009d49c0 * 4;
                uVar10 = DAT_009d49c0 + 1 & 0x3ff;
                DAT_009d49c0 = uVar10 + 1 & 0x3ff;
                if (DAT_004af814 == 0) {
                  uVar15 = 0xc;
                }
                else {
                  uVar15 = 0x1e;
                }
                FUN_00429de0(uVar15,1,CONCAT22((short)((uint)iVar6 >> 0x10),sVar3) + -3 +
                                      (*(uint *)(&DAT_004afc00 + iVar9) & 7),
                             iVar13 + -3 + (*(uint *)(&DAT_004afc00 + uVar10 * 4) & 7),0xffffffff,
                             0xffffffff);
              }
            }
            local_8 = local_8 + -1;
          } while (local_8 != 0);
        }
      }
    }
  }
  return;
}



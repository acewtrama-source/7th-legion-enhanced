
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424300(int param_1,int param_2)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  bool bVar7;
  
  sVar2 = (&DAT_0067fe10)[param_1 * 0x368];
  if (((((sVar2 != 0) && (sVar2 != 99)) && ((&DAT_0067fe1c)[param_1 * 0x368] != 0)) &&
      (*(short *)(&DAT_0067fe7e + param_1 * 0x6d0) != param_2)) &&
     (((param_2 != 5 && (param_2 != 8)) ||
      (*(short *)(&DAT_004c0874 + (short)(&DAT_0067fe12)[param_1 * 0x368] * 0x4c) != 0)))) {
    uVar6 = (undefined2)param_2;
    if (DAT_0071667c == 1) {
      bVar7 = sVar2 == DAT_00668ccc;
      if ((DAT_00803c40 < sVar2) && (DAT_004aee00 == 1)) {
        bVar7 = true;
      }
      if (bVar7) {
        puVar5 = &DAT_00773410;
        for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        *(undefined2 *)puVar5 = 0;
        _DAT_009e2d80 = 0x26;
        DAT_00773410._2_2_ = (undefined2)param_1;
        puVar5 = &DAT_00773410;
        DAT_00773410._0_2_ = uVar6;
        if (((int)(short)DAT_0066ccf0 + 2U & 0x3f) != (int)DAT_00834f94) {
          iVar3 = 0;
          iVar4 = (short)DAT_0066ccf0 * 0x2a;
          (&DAT_00671a20)[iVar4] = 0xd;
          do {
            uVar1 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            (&DAT_00671a22)[iVar3 + iVar4] = uVar1;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x26);
          DAT_0066ccf0 = DAT_0066ccf0 + 1;
          DAT_0066ccf0 = DAT_0066ccf0 & 0x3f;
          _DAT_00668910 = 0xd;
          DAT_004af798 = DAT_004af798 + 1;
          DAT_004af79c = DAT_004af79c + 1;
          return;
        }
      }
    }
    else {
      *(undefined2 *)(&DAT_0067fe7e + param_1 * 0x6d0) = uVar6;
    }
  }
  return;
}



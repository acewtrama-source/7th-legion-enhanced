// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x46bec0) | verbatim, do not edit
void FUN_0046bec0(short param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  undefined2 extraout_var;
  int iVar8;
  int *piVar9;

  iVar8 = (int)param_1;
  if ((&DAT_008750d0)[iVar8] != 0) {
    (&DAT_008750d0)[iVar8] = (&DAT_008750d0)[iVar8] + -1;
  }
  if ((&DAT_00666610)[iVar8] != 0) {
    (&DAT_00666610)[iVar8] = (&DAT_00666610)[iVar8] + -1;
  }
  if (0 < (int)(&DAT_005bb500)[iVar8]) {
    (&DAT_005bb500)[iVar8] = (&DAT_005bb500)[iVar8] + -1;
  }
  (&DAT_00665660)[iVar8] = (&DAT_00665660)[iVar8] + 1;
  for (iVar3 = (&DAT_005bbd50)[DAT_005bcd74 * 8]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    if ((*(char *)(iVar3 + 0x38) == '\x01') || (*(char *)(iVar3 + 0x38) == '\0')) {
      uVar5 = *(uint *)(iVar3 + 0x18);
      if (uVar5 != 0) {
        if (*(int *)(iVar3 + 0x24) != 0) {
          uVar5 = (uint)(CONCAT44((int)uVar5 >> 0x10,uVar5 << 0x10) /
                        (longlong)*(int *)(iVar3 + 0x24));
        }
        FUN_0046b820(*(int *)(*(int *)(iVar3 + 0xc) + 0x18) >> 0x10,
                     *(int *)(*(int *)(iVar3 + 0xc) + 0x1c) >> 0x10,
                     (int)((uVar5 & 0xffffff00) * 0x28) >> 0x10);
        if ((*(char *)(iVar3 + 0x38) != '\x06') &&
           (DAT_00803c40 < (short)(&DAT_0067fe10)[*(short *)(iVar3 + 0x10) * 0x368])) {
          *(undefined1 *)(iVar3 + 0x38) = 2;
          *(undefined4 *)(iVar3 + 0x3c) = 0;
          *(undefined4 *)(iVar3 + 0x5c) = 0;
          FUN_00423710(CONCAT22(extraout_var,*(short *)(iVar3 + 0x10)),7,0xffffffff,0xffffffff,
                       0xffffffff,0xffffffff);
        }
      }
    }
  }
  for (iVar3 = (&DAT_005bbd50)[DAT_005bcd74 * 8]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
    cVar1 = *(char *)(iVar3 + 0x38);
    if ((((cVar1 != '\x02') && (cVar1 != '\x05')) &&
        (*(short *)(&DAT_0067fe72 + *(short *)(iVar3 + 0x10) * 0x6d0) == 0)) &&
       (bVar7 = *(char *)(iVar3 + 0x37) + 1, *(byte *)(iVar3 + 0x37) = bVar7, 1 < bVar7)) {
      *(undefined1 *)(iVar3 + 0x37) = 0;
      if (cVar1 == '\x03') {
        if (*(byte *)(iVar3 + 0x4c) != 0xffffffff) {
          FUN_0046c300(iVar3,(uint)*(byte *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x50),
                       (int)*(short *)(iVar3 + 0x5a),(int)*(short *)(iVar3 + 0x58),
                       (int)*(short *)(iVar3 + 0x54),(int)*(short *)(iVar3 + 0x56));
          *(undefined1 *)(iVar3 + 0x4c) = 0xff;
        }
      }
      else {
        FUN_0046c300(iVar3,2,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
      }
    }
  }
  switch((&DAT_00665660)[iVar8] & 7) {
  case 0:
    piVar9 = &DAT_004c2350;
    FUN_004697b0(3,0);
    iVar3 = DAT_004c2350;
    while (iVar3 != 0) {
      iVar3 = *piVar9;
      piVar9 = piVar9 + 1;
      FUN_00469020(iVar3,0);
      iVar3 = *piVar9;
    }
    break;
  case 1:
    iVar6 = (int)DAT_00507484;
    iVar4 = *(int *)(&DAT_004b8b28 + DAT_005bcd74 * 4);
    iVar3 = DAT_005bcd74 * 4;
    *(int *)(&DAT_004b8b28 + iVar3) = iVar4 + 1;
    if (((0xf - iVar6) * 2) / 0x14 <= iVar4 + 1) {
      *(int *)(&DAT_004b8b28 + iVar3) = 0;
      FUN_00469e80();
      FUN_0046a5b0();
    }
    FUN_0046bd80();
    break;
  case 2:
    FUN_004698f0();
    break;
  case 3:
    FUN_0046af10();
    break;
  case 4:
    FUN_0046b260();
    break;
  case 5:
    if ((int)(&DAT_005bb500)[iVar8] < 1) {
      FUN_0046ad10(0);
    }
    break;
  case 6:
    FUN_0046b640();
    FUN_0046bd80();
    break;
  case 7:
    FUN_0046b6e0();
    for (iVar3 = (&DAT_005bbd50)[DAT_005bcd74 * 8]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      sVar2 = *(short *)(iVar3 + 0x10);
      if ((&DAT_0067feb0)[sVar2 * 0x368] != -1) {
        FUN_00423f70(sVar2,2,0xffffffff,
                     CONCAT22((short)((uint)(sVar2 * 0x6d0) >> 0x10),(&DAT_0067feb0)[sVar2 * 0x368])
                     ,0xffffffff,0xffffffff);
        FUN_00469020(iVar3,0);
      }
    }
    for (iVar3 = (&DAT_005bbd4c)[DAT_005bcd74 * 8]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
      iVar4 = *(int *)(iVar3 + 0xc);
      iVar6 = *(int *)(iVar4 + 0x58) * 0x10000;
      if (*(int *)(iVar4 + 0x54) < iVar6) {
        if ((*(int *)(iVar4 + 0x54) < iVar6 - ((int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2)) &&
           (*(int *)(iVar4 + 0x5c) == 0)) {
          DAT_00773410._0_2_ = *(undefined2 *)(iVar3 + 0x10);
          DAT_00773410._2_2_ = 1;
LAB_0046c27e:
          FUN_00444c00(8,&DAT_00773410);
        }
      }
      else if (*(int *)(iVar4 + 0x5c) == 1) {
        DAT_00773410._0_2_ = *(undefined2 *)(iVar3 + 0x10);
        DAT_00773410._2_2_ = 0;
        goto LAB_0046c27e;
      }
    }
  }
  sVar2 = (&DAT_00875160)[iVar8];
  (&DAT_00875160)[iVar8] = sVar2 + 1;
  if ((short)(&DAT_008753d0)[iVar8] <= (short)(sVar2 + 1)) {
    FUN_0044da70();
  }
  return;
}

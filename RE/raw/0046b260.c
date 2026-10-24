// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA analyze_function(0x46b5a2) -> FUN_0046b260 | verbatim, do not edit
void FUN_0046b260(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  short local_1c;
  short local_1a;
  int *local_18;
  short local_10;

  sVar8 = 0;
  do {
    iVar3 = (int)sVar8;
    sVar8 = sVar8 + 1;
    (&DAT_00666630)[iVar3 * 8] = 0;
    (&DAT_00666634)[iVar3 * 8] = 0;
  } while (sVar8 < 0x32);
  local_1a = 1;
  if (0 < DAT_00834f88) {
    do {
      for (iVar3 = (&DAT_005bbd50)[local_1a * 8]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        sVar8 = 0;
        do {
          iVar6 = (int)sVar8;
          if ((((&DAT_00666628)[iVar6 * 8] != 0) &&
              (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x18) >> 0x15) -
                       ((int)(&DAT_00666620)[iVar6 * 8] >> 5), uVar9 = (int)uVar4 >> 0x1f,
              (int)((uVar4 ^ uVar9) - uVar9) < 5)) &&
             (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x1c) >> 0x15) -
                      ((int)(&DAT_00666624)[iVar6 * 8] >> 5), uVar9 = (int)uVar4 >> 0x1f,
             (int)((uVar4 ^ uVar9) - uVar9) < 5)) goto LAB_0046b310;
          sVar8 = sVar8 + 1;
        } while (sVar8 < 0x32);
        sVar8 = -1;
LAB_0046b310:
        if (((sVar8 != -1) && (iVar6 = (int)sVar8, (&DAT_00666630)[iVar6 * 8] == 0)) &&
           ((&DAT_00666634)[iVar6 * 8] == 0)) {
          (&DAT_00666630)[iVar6 * 8] = *(undefined4 *)(iVar3 + 0x1c);
          (&DAT_00666634)[iVar6 * 8] = *(undefined4 *)(iVar3 + 0x28);
        }
      }
      local_1a = local_1a + 1;
    } while (local_1a <= DAT_00834f88);
  }
  sVar8 = 0;
  do {
    iVar3 = (int)sVar8;
    if ((&DAT_00666634)[iVar3 * 8] == 0) {
      uVar5 = (&DAT_00666630)[iVar3 * 8];
    }
    else {
      uVar5 = (undefined4)
              (CONCAT44((int)(&DAT_00666630)[iVar3 * 8] >> 0x10,(&DAT_00666630)[iVar3 * 8] << 0x10)
              / (longlong)(int)(&DAT_00666634)[iVar3 * 8]);
    }
    sVar8 = sVar8 + 1;
    (&DAT_00666638)[iVar3 * 8] = uVar5;
  } while (sVar8 < 0x32);
  local_10 = 0x32;
  do {
    sVar8 = 0;
    iVar3 = 0;
    local_1c = -1;
    do {
      if (((&DAT_00666628)[sVar8 * 8] != 0) && (iVar3 < (int)(&DAT_00666638)[sVar8 * 8])) {
        iVar3 = (&DAT_00666638)[sVar8 * 8];
        local_1c = sVar8;
      }
      sVar8 = sVar8 + 1;
    } while (sVar8 < 0x32);
    if ((local_1c != -1) && (iVar3 = (int)local_1c, 0x10000 < (int)(&DAT_00666638)[iVar3 * 8])) {
      FUN_004687e0(0,(int)(&DAT_00666620)[iVar3 * 8] >> 5,(int)(&DAT_00666624)[iVar3 * 8] >> 5);
      local_18 = &DAT_004c2350;
      iVar6 = DAT_004c2350;
      while ((iVar6 != 0 && ((int)(&DAT_00666634)[iVar3 * 8] < (int)(&DAT_00666630)[iVar3 * 8]))) {
        sVar8 = 0;
        iVar6 = *local_18;
        do {
          iVar7 = (int)sVar8;
          if ((((&DAT_00666628)[iVar7 * 8] != 0) &&
              (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x18) >> 0x15) -
                       ((int)(&DAT_00666620)[iVar7 * 8] >> 5), uVar9 = (int)uVar4 >> 0x1f,
              (int)((uVar4 ^ uVar9) - uVar9) < 5)) &&
             (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x1c) >> 0x15) -
                      ((int)(&DAT_00666624)[iVar7 * 8] >> 5), uVar9 = (int)uVar4 >> 0x1f,
             (int)((uVar4 ^ uVar9) - uVar9) < 5)) {
            if (local_1c == sVar8) goto LAB_0046b4cd;
            goto LAB_0046b4ea;
          }
          sVar8 = sVar8 + 1;
        } while (sVar8 < 0x32);
        if (local_1c == -1) {
LAB_0046b4cd:
          (&DAT_00666630)[iVar3 * 8] = *(int *)(iVar6 + 0x2c) + (&DAT_00666630)[iVar3 * 8];
        }
        else {
LAB_0046b4ea:
          cVar1 = *(char *)(iVar6 + 0x38);
          if ((cVar1 == '\0') || (cVar1 == '\x02')) {
            iVar7 = (&DAT_00666624)[iVar3 * 8];
            iVar2 = (&DAT_00666620)[iVar3 * 8];
            if ((cVar1 != '\x06') &&
               (DAT_00803c40 < (short)(&DAT_0067fe10)[*(short *)(iVar6 + 0x10) * 0x368])) {
              *(undefined1 *)(iVar6 + 0x38) = 2;
              *(undefined4 *)(iVar6 + 0x3c) = 0;
              *(undefined4 *)(iVar6 + 0x5c) = 0;
              if ((iVar2 == -1) && (iVar7 == -1)) {
                uVar5 = 7;
              }
              else {
                uVar5 = 1;
              }
              FUN_00423710(CONCAT22((short)((uint)iVar2 >> 0x10),*(undefined2 *)(iVar6 + 0x10)),
                           uVar5,0xffffffff,0xffffffff,iVar2,iVar7);
            }
            if (DAT_004b8b20 == 1) {
              FUN_0041fff0(s_AI_Sending_unit_to_guard_point_004c44fc);
            }
            (&DAT_00666630)[iVar3 * 8] = (&DAT_00666630)[iVar3 * 8] + *(int *)(iVar6 + 0x2c);
          }
        }
        local_18 = local_18 + 1;
        iVar6 = *local_18;
      }
      (&DAT_00666638)[iVar3 * 8] = 0;
    }
    local_10 = local_10 + -1;
    if (local_10 == 0) {
      return;
    }
  } while( true );
}

// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x46b6e0) | verbatim, do not edit
void FUN_0046b6e0(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  short sVar9;
  short local_a;
  
  sVar9 = 0;
  do {
    iVar3 = (int)sVar9;
    if ((&DAT_00666628)[iVar3 * 8] != 0) {
      local_a = 1;
      bVar1 = false;
      if (0 < DAT_00834f88) {
        do {
          bVar2 = false;
          for (iVar5 = (&DAT_005bbd50)[local_a * 8]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
            bVar1 = true;
            if (bVar2) goto LAB_0046b7c6;
            sVar8 = 0;
            do {
              iVar6 = (int)sVar8;
              if ((((&DAT_00666628)[iVar6 * 8] != 0) &&
                  (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar5 + 0xc) + 0x18) >> 0x15)
                           - ((int)(&DAT_00666620)[iVar6 * 8] >> 5), uVar7 = (int)uVar4 >> 0x1f,
                  (int)((uVar4 ^ uVar7) - uVar7) < 5)) &&
                 (uVar4 = (int)(short)((int)*(undefined4 *)(*(int *)(iVar5 + 0xc) + 0x1c) >> 0x15) -
                          ((int)(&DAT_00666624)[iVar6 * 8] >> 5), uVar7 = (int)uVar4 >> 0x1f,
                 (int)((uVar4 ^ uVar7) - uVar7) < 5)) goto LAB_0046b79a;
              sVar8 = sVar8 + 1;
            } while (sVar8 < 0x32);
            sVar8 = -1;
LAB_0046b79a:
            if (sVar8 == sVar9) {
              bVar2 = true;
            }
          }
          if (bVar2) goto LAB_0046b7f5;
          local_a = local_a + 1;
          bVar1 = false;
        } while (local_a <= DAT_00834f88);
      }
LAB_0046b7c6:
      if (bVar1) {
LAB_0046b7f5:
        (&DAT_00666628)[iVar3 * 8] = (&DAT_0066663c)[iVar3 * 8];
      }
      else {
        iVar5 = (&DAT_00666628)[iVar3 * 8] + -1;
        (&DAT_00666628)[iVar3 * 8] = iVar5;
        if ((iVar5 == 0) && (DAT_004b8b20 == 1)) {
          FUN_0041fff0(s_AI_Removed_guard_point_004c455c);
        }
      }
    }
    sVar9 = sVar9 + 1;
    if (0x31 < sVar9) {
      return;
    }
  } while( true );
}

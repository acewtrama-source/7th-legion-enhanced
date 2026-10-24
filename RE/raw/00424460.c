// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x424460) | verbatim, do not edit
uint FUN_00424460(short param_1,short param_2,short param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  bool bVar5;
  int local_c;
  int local_8;
  
  param_2 = param_2 >> 5;
  param_3 = param_3 >> 5;
  uVar1 = (int)param_3 << 0x10 | (int)param_2;
  sVar4 = (short)((int)(&DAT_0067fe28)[param_1 * 0x1b4] >> 0x15) - param_2;
  sVar2 = (short)((int)(&DAT_0067fe2c)[param_1 * 0x1b4] >> 0x15) - param_3;
  bVar5 = sVar4 < 0;
  if (bVar5) {
    sVar4 = -1;
  }
  if (sVar4 != 0 && !bVar5) {
    sVar4 = 1;
  }
  bVar5 = sVar2 < 0;
  if (bVar5) {
    sVar2 = -1;
  }
  if (sVar2 != 0 && !bVar5) {
    sVar2 = 1;
  }
  sVar2 = sVar4 + 1 + (sVar2 + 1) * 3;
  if ((sVar2 < 0) || (8 < sVar2)) {
    sVar2 = -1;
  }
  else {
    sVar2 = *(short *)(&DAT_004b5ed0 + sVar2 * 2);
  }
  if (sVar2 != -1) {
    local_c = *(int *)(&DAT_004b9e48 + sVar2 * 4);
    local_8 = *(int *)(&DAT_004b9e68 + sVar2 * 4);
    if (local_c < 0) {
      local_c = -1;
    }
    if (0 < local_c) {
      local_c = 1;
    }
    bVar5 = local_8 < 0;
    if (bVar5) {
      local_8 = -1;
    }
    if (local_8 != 0 && !bVar5) {
      local_8._0_2_ = 1;
    }
    sVar2 = 0;
    while ((iVar3 = param_2 * 0x80 + (int)param_3, (&DAT_008352f0)[iVar3] != '\x01' ||
           (*(char *)((int)&DAT_006d3920 + iVar3) != '\0'))) {
      param_2 = param_2 + (short)local_c;
      sVar2 = sVar2 + 1;
      param_3 = param_3 + (short)local_8;
      if (sVar2 == 0x1e) break;
      if (param_2 < 0) {
        return uVar1;
      }
      if (param_3 < 0) {
        return uVar1;
      }
      if (0x7f < param_2) {
        return uVar1;
      }
      if (0x7f < param_3) {
        return uVar1;
      }
    }
    uVar1 = (int)param_3 << 0x10 | (int)param_2;
  }
  return uVar1;
}

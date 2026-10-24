// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x46b820) | verbatim, do not edit
void FUN_0046b820(short param_1,short param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  bool bVar6;
  
  sVar1 = 0;
  while( true ) {
    iVar4 = (int)sVar1;
    sVar5 = sVar1;
    if ((&DAT_00666628)[iVar4 * 8] == 0) break;
    uVar3 = (int)param_1 - (&DAT_00666620)[iVar4 * 8] >> 0x1f;
    if (((int)(((int)param_1 - (&DAT_00666620)[iVar4 * 8] ^ uVar3) - uVar3) < 0xa0) &&
       (uVar3 = (int)param_2 - (&DAT_00666624)[iVar4 * 8] >> 0x1f,
       (int)(((int)param_2 - (&DAT_00666624)[iVar4 * 8] ^ uVar3) - uVar3) < 0xa0)) {
      bVar6 = DAT_004b8b20 != 1;
      (&DAT_00666628)[sVar1 * 8] = param_3;
      (&DAT_0066663c)[sVar1 * 8] = param_3;
      if (bVar6) {
        return;
      }
      FUN_0041fff0(s_AI_Merging_new_guard_point__004c4590);
      return;
    }
    if (((&DAT_00666628)[iVar4 * 8] == 0) || (sVar1 = sVar1 + 1, sVar5 = -1, 0x31 < sVar1)) break;
  }
  if (-1 < sVar5) {
    iVar2 = (int)sVar5;
    (&DAT_00666620)[iVar2 * 8] = (int)param_1;
    iVar4 = DAT_004b8b20;
    (&DAT_00666624)[iVar2 * 8] = (int)param_2;
    (&DAT_00666628)[iVar2 * 8] = param_3;
    if (iVar4 == 1) {
      FUN_0041fff0(s_AI_Setting_new_guard_point__004c4574);
    }
  }
  return;
}

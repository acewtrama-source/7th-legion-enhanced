// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x46b640) | verbatim, do not edit
void FUN_0046b640(void)

{
  int iVar1;
  char local_50 [80];
  
  iVar1 = (&DAT_005bbd50)[DAT_005bcd74 * 8];
  if (iVar1 != 0) {
    while (((*(char *)(iVar1 + 0x38) != '\x02' ||
            (*(int *)(iVar1 + 0x28) <= *(int *)(iVar1 + 0x1c) * 2 >> 1)) ||
           (*(int *)(iVar1 + 0x1c) == 0))) {
      iVar1 = *(int *)(iVar1 + 4);
      if (iVar1 == 0) {
        return;
      }
    }
    FUN_00469020(iVar1,2);
    _sprintf(local_50,s_AI_Guard_Point_Attacking__d__d___004c4538,(int)*(short *)(iVar1 + 0x10),
             *(int *)(*(int *)(iVar1 + 0xc) + 0x18) >> 0x15,
             *(int *)(*(int *)(iVar1 + 0xc) + 0x1c) >> 0x15);
    if (DAT_004b8b20 == 1) {
      FUN_0041fff0(local_50);
    }
  }
  return;
}

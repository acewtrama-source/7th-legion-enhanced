// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x420180) | verbatim, do not edit
int FUN_00420180(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_c;
  int local_8;
  
  local_c = (int)(800 / (longlong)(int)DAT_00834f88);
  local_8 = (param_1 + -1) * local_c;
  if (DAT_00803c40 == 1) {
    local_8 = 0;
    local_c = 0x31e;
  }
  iVar1 = local_8;
  if (local_8 < local_c + local_8 + -1) {
    piVar2 = &DAT_00805df0 + local_8 * 0x38;
    do {
      if ((*piVar2 == 0) && (piVar2[3] == 0)) {
        DAT_0083a402 = 0x31e;
        *(int *)(&DAT_00805dfc + iVar1 * 0xe0) = DAT_00803c48 + 10;
        return iVar1;
      }
      piVar2 = piVar2 + 0x38;
      iVar1 = iVar1 + 1;
    } while (iVar1 < local_c + local_8 + -1);
  }
  return CONCAT22((short)((uint)iVar1 >> 0x10),0xffff);
}

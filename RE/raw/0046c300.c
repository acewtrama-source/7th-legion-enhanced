// legion.exe sha256 efbb2e8c...a9a5b8 | Ghidra 12.1.4 via REA procedure_pseudo_code(0x46c300) | verbatim, do not edit
void FUN_0046c300(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  if (*(char *)(param_1 + 0x38) == '\x06') {
    return;
  }
  if ((short)(&DAT_0067fe10)[*(short *)(param_1 + 0x10) * 0x368] <= DAT_00803c40) {
    return;
  }
  *(char *)(param_1 + 0x38) = (char)param_2;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  switch(param_2) {
  case 0:
    param_2 = 7;
    break;
  case 1:
  case 4:
    param_2 = 2;
    break;
  case 2:
    if ((param_6 == -1) && (param_7 == -1)) {
      param_2 = 7;
      break;
    }
  case 3:
  case 5:
    param_2 = 1;
  }
  FUN_00423710(*(short *)(param_1 + 0x10),param_2,param_4,param_5,param_6,param_7);
  return;
}

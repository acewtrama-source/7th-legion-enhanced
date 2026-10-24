
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl f_454d20(uint param_1)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  undefined2 uVar9;
  int iVar7;
  undefined4 uVar8;
  int iVar10;
  undefined2 extraout_var;
  uint uVar11;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  short sVar12;
  int iVar13;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  short sVar14;
  short sVar15;
  uint uVar16;
  int *piVar17;
  int iVar18;
  bool bVar19;
  char cVar20;
  int local_18;
  int local_10;
  uint uStack_c;
  int iStack_8;
  short *psStack_4;
  
                    /* 0x54d20  35  f_454d20 */
  FUN_00454690(param_1);
  iVar18 = param_1 * 0x6d0;
  uVar16 = (uint)*(ushort *)(iVar18 + 0x67fe50);
  uVar11 = (uint)*(ushort *)(iVar18 + 0x67fe52);
  if (*(short *)(iVar18 + 0x67fe56) != -1) {
    uVar16 = 0xffff;
    uVar11 = 0xffff;
    iVar10 = *(short *)(iVar18 + 0x67fe56) * 0xe0;
    if ((*(int *)(&DAT_00805df0 + iVar10) == 0) || (*(int *)(&DAT_00805df8 + iVar10) == 0)) {
      local_18 = 0x80;
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      *(undefined2 *)(iVar18 + 0x67fe56) = 0xffff;
      psVar4 = (short *)&DAT_009014a0;
      do {
        iVar10 = 0x80;
        do {
          if ((int)*psVar4 == param_1) {
            *psVar4 = -1;
          }
          psVar4 = psVar4 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    else {
      uVar1 = (short)*(undefined4 *)(&DAT_00805e08 + iVar10) * 0x20;
      iVar13 = (param_1 & 0xffff0003) * 2;
      uVar16 = (uint)(ushort)((short)((*(int *)(iVar10 + 0x805e10) << 5) / 2) + uVar1) + iVar13;
      uVar11 = ((ushort)((short)((*(int *)(iVar10 + 0x805e14) << 5) / 2) +
                        *(short *)(&DAT_00805e0c + iVar10) * 0x20) - 6) + iVar13;
      if (*(short *)(&DAT_0067fe12 + iVar18) == 1) {
        uVar16 = (uint)uVar1;
        uVar11 = (uint)(ushort)((*(short *)(&DAT_00805e0c + iVar10) + 2) * 0x20);
      }
    }
  }
  if (*(short *)(iVar18 + 0x67fe58) != -1) {
    uVar16 = 0xffff;
    uVar11 = 0xffff;
    iVar10 = *(short *)(iVar18 + 0x67fe58) * 0x6d0;
    if ((*(short *)(&DAT_0067fe10 + iVar10) == 0) || (*(short *)(&DAT_0067fe1c + iVar10) == 0)) {
      local_18 = 0x80;
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      *(undefined2 *)(iVar18 + 0x67fe58) = 0xffff;
      psVar4 = (short *)&DAT_009014a0;
      do {
        iVar10 = 0x80;
        do {
          if ((int)*psVar4 == param_1) {
            *psVar4 = -1;
          }
          psVar4 = psVar4 + 1;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    else {
      uVar16 = (uint)(ushort)(((ushort)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar10) >> 0x10) &
                              0xffe0) + 0x10);
      uVar11 = (uint)(ushort)(((ushort)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar10) >> 0x10) &
                              0xffe0) + 0x10);
    }
  }
  if ((*(short *)(&DAT_0067fe12 + iVar18) != 1) && (*(ushort *)(iVar18 + 0x67fe50) != 0xffff)) {
    uVar16 = (uint)*(ushort *)(iVar18 + 0x67fe50);
    uVar11 = (uint)*(ushort *)(iVar18 + 0x67fe52);
  }
  if (((((short)uVar16 < 0) || ((short)uVar11 < 0)) || (0x1000 < (short)uVar16)) ||
     (0x1000 < (short)uVar11)) {
    uVar16 = 0xffffffff;
    uVar11 = 0xffff;
  }
  if (((int)*(short *)(iVar18 + 0x67fe58) == param_1) && (*(short *)(iVar18 + 0x67fe56) == -1)) {
    uVar16 = 0xffff;
    uVar11 = 0xffff;
  }
  iVar10 = (int)(short)uVar16 - (*(int *)(&DAT_0067fe28 + iVar18) >> 0x10);
  if (iVar10 < 0) {
    iVar10 = -iVar10;
  }
  iVar13 = *(int *)(&DAT_0067fe2c + iVar18) >> 0x10;
  iVar5 = (short)uVar11 - iVar13;
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  if ((iVar10 < 8) && (iVar5 < 8)) {
    uVar16 = 0xffffffff;
    uVar11 = 0xffff;
  }
  sVar2 = (short)uVar16;
  sVar3 = (short)uVar11;
  if (((sVar2 == -1) || (sVar3 == -1)) && (*(short *)(iVar18 + 0x67fe72) != 0)) {
    *(undefined2 *)(iVar18 + 0x67fe74) = 7;
  }
  *(undefined2 *)(iVar18 + 0x67fe78) = 0;
  if ((short)*(ushort *)(&DAT_0067fe10 + iVar18) <= _DAT_00803c40) {
    uVar6 = *(ushort *)(&DAT_0067fe10 + iVar18) & 7;
    iVar10 = uVar6 * 2;
    iVar5 = FUN_00429cd0(*(short *)(iVar10 + 0x773440),*(short *)(iVar10 + 0x77b470),
                         *(short *)(iVar10 + 0x77b460),*(short *)(uVar6 * 2 + 0x77b480));
    iVar10 = (*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 2;
    iVar10 = FUN_00429cd0((short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15),
                          (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15),
                          *(short *)(iVar10 + 0x716640),*(short *)(iVar10 + 0x716660));
    iVar10 = (int)(short)iVar10;
    iVar13 = extraout_EDX;
    if (iVar10 <= (short)iVar5 * 2) {
      *(undefined2 *)(iVar18 + 0x67fe78) = 1;
    }
  }
  uVar9 = (undefined2)((uint)iVar10 >> 0x10);
  uVar1 = *(ushort *)(iVar18 + 0x67fe72);
  if (8 < uVar1) {
switchD_00455042_caseD_4:
    *(undefined2 *)(iVar18 + 0x67fee4) = 0;
    sVar3 = *(short *)(iVar18 + 0x67fee6);
    if (sVar3 != -1) {
      *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
      uVar9 = (undefined2)((uint)(sVar3 * 0x964) >> 0x10);
      *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
    }
    if (_DAT_004aee00 != 1) {
      return;
    }
    func_0x00423710(param_1,0x29a,CONCAT22(uVar9,*(undefined2 *)(&DAT_0067fe12 + iVar18)),0,
                    *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,
                    *(int *)(&DAT_0067fe2c + iVar18) >> 0x10);
    return;
  }
  sVar15 = sVar2 >> 5;
  sVar14 = sVar3 >> 5;
  switch(uVar1) {
  case 0:
    sVar3 = *(short *)(iVar18 + 0x67fe7e);
    if ((sVar3 == 8) || (sVar3 == 5)) {
      if (_DAT_00803c40 < *(short *)(&DAT_0067fe10 + iVar18)) goto LAB_00455103;
    }
    else if ((sVar3 == 3) || (sVar3 == 1)) goto LAB_00455103;
    func_0x00424300(param_1,1);
    uVar9 = extraout_var;
LAB_00455103:
    *(undefined2 *)(iVar18 + 0x67fe80) = 0;
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    *(undefined2 *)(iVar18 + 0x67fe9c) = 1;
    if (*(short *)(iVar18 + 0x67fe74) != 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 0;
      if ((_DAT_004aee00 == 1) && (*(short *)(iVar18 + 0x67fe92) == -1)) {
        func_0x00423710(param_1,0x29a,*(undefined2 *)(&DAT_0067fe12 + iVar18),
                        CONCAT22(uVar9,*(undefined2 *)(iVar18 + 0x67fe72)),
                        *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,
                        *(int *)(&DAT_0067fe2c + iVar18) >> 0x10);
      }
      psVar4 = (short *)&DAT_009014a0;
      iVar10 = 0x80;
      do {
        iVar13 = 0x80;
        do {
          if ((int)*psVar4 == param_1) {
            *psVar4 = -1;
          }
          psVar4 = psVar4 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if ((*(short *)(iVar18 + 0x67fe7e) == 3) && ((int)_DAT_006df160 == param_1)) {
      func_0x00424300(param_1,1);
      iStack_8 = 0;
      local_10 = 0;
      sVar3 = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
      sVar2 = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
      if (_DAT_006dd208 < 1) {
        return;
      }
      psStack_4 = (short *)&DAT_006df160;
      do {
        sVar14 = *psStack_4;
        uVar16 = (uint)sVar14;
        if ((((uVar16 != param_1) && (sVar14 != -1)) &&
            (*(short *)(&DAT_0067fe10 + uVar16 * 0x6d0) != 0)) &&
           (*(short *)(&DAT_0067fe1c + uVar16 * 0x6d0) != 0)) {
          if (iStack_8 < 0x28) {
            iVar18 = iStack_8 * 2;
            iVar10 = iStack_8;
            do {
              iVar13 = ((int)*(short *)(iVar18 + 0x4b0c00) + (int)sVar3) * 0x80 +
                       (int)*(short *)(iVar18 + 0x4b0c50) + (int)sVar2;
              uVar11 = (uint)*(byte *)(iVar13 + 0x6d3920);
              if (uVar16 - uVar11 == -1) {
                uVar11 = 0;
              }
              if ((*(char *)(iVar13 + 0x8352f0) == '\x01') && (uVar11 == 0)) {
                uVar9 = (undefined2)((uint)iVar13 >> 0x10);
                iStack_8 = iVar10 + 1;
                func_0x00423710(sVar14,1,0xffffffff,0xffffffff,
                                CONCAT22(uVar9,(*(short *)(iVar10 * 2 + 0x4b0c00) + sVar3) * 0x20 +
                                               0x10),
                                CONCAT22(uVar9,(*(short *)(iVar10 * 2 + 0x4b0c50) + sVar2) * 0x20 +
                                               0x10));
                break;
              }
              iVar18 = iVar18 + 2;
              iVar10 = iVar10 + 1;
            } while (iVar18 < 0x50);
          }
          func_0x00424300((int)*psStack_4,4);
        }
        psStack_4 = psStack_4 + 1;
        local_10 = local_10 + 1;
        if (_DAT_006dd208 <= local_10) {
          return;
        }
      } while( true );
    }
    *(undefined2 *)(iVar18 + 0x67fee4) = 0;
    sVar3 = *(short *)(iVar18 + 0x67fee6);
    if (sVar3 != -1) {
      *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
      *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
    }
    if (*(short *)(iVar18 + 0x67fe92) != -1) {
      *(short *)(iVar18 + 0x67fe72) = *(short *)(iVar18 + 0x67fe92);
      *(undefined2 *)(iVar18 + 0x67fe58) = *(undefined2 *)(iVar18 + 0x67fe9a);
      *(undefined2 *)(iVar18 + 0x67fe56) = *(undefined2 *)(iVar18 + 0x67fe98);
      *(undefined2 *)(iVar18 + 0x67fe50) = *(undefined2 *)(iVar18 + 0x67fe94);
      *(undefined2 *)(iVar18 + 0x67fe52) = *(undefined2 *)(iVar18 + 0x67fe96);
      *(undefined2 *)(iVar18 + 0x67fe92) = 0xffff;
      return;
    }
    if (*(int *)(iVar18 + 0x67fe60) >> 0x10 == *(int *)(iVar18 + 0x67fe64)) {
      *(short *)(iVar18 + 0x67feba) = *(short *)(iVar18 + 0x67feba) + _DAT_006df0f8;
      if (*(short *)(&DAT_0067fe12 + iVar18) == 0x13) {
        *(undefined2 *)(iVar18 + 0x67feba) = 0;
      }
      if ((int)((param_1 & 0xf) * 4 + 0x82) <= (int)*(short *)(iVar18 + 0x67feba)) {
        *(undefined2 *)(iVar18 + 0x67feba) = 0;
        iVar10 = *(int *)(iVar18 + 0x67fe44) >> 0x10;
        if (*(short *)(iVar18 + 0x67feb8) == 0) {
          *(uint *)(iVar18 + 0x67fe64) = iVar10 + 8U & 0x3f;
          *(undefined2 *)(iVar18 + 0x67feb8) = 1;
        }
        else {
          *(uint *)(iVar18 + 0x67fe64) = iVar10 - 8U & 0x3f;
          *(undefined2 *)(iVar18 + 0x67feb8) = 0;
        }
      }
    }
    else {
      _DAT_006dd174 = 0;
      if (0 < _DAT_006df0f8) {
        _DAT_006dd174 = _DAT_006df0f8;
        sVar3 = _DAT_006df0f8;
        do {
          uVar16 = ((*(int *)(iVar18 + 0x67fe60) >> 0x10) - *(int *)(iVar18 + 0x67fe64)) + 0x20U &
                   0x3f;
          iVar10 = uVar16 * 4 + -0x80;
          if (iVar10 < 0) {
            *(int *)(iVar18 + 0x67fe60) = *(int *)(iVar18 + 0x67fe60) + 0x8000;
          }
          if (uVar16 != 0x20 && -1 < iVar10) {
            *(int *)(iVar18 + 0x67fe60) = *(int *)(iVar18 + 0x67fe60) + -0x8000;
          }
          if (uVar16 == 0x20) {
            *(int *)(iVar18 + 0x67fe60) = *(int *)(iVar18 + 0x67fe64) << 0x10;
          }
          sVar3 = sVar3 + -1;
          *(uint *)(iVar18 + 0x67fe60) = *(uint *)(iVar18 + 0x67fe60) & 0x3ff000;
        } while (sVar3 != 0);
      }
    }
    sVar3 = *(short *)(&DAT_0067fe12 + iVar18);
    if (*(short *)(sVar3 * 0x4c + 0x4c086e) == 0) {
      return;
    }
    if (sVar3 == 0) {
      return;
    }
    if (sVar3 == 1) {
      return;
    }
    if (sVar3 == 0x2a) {
      return;
    }
    if ((_DAT_00803c40 == 1) ||
       ((bVar19 = _DAT_00668ccc == *(short *)(&DAT_0067fe10 + iVar18),
        _DAT_00803c40 < *(short *)(&DAT_0067fe10 + iVar18) && (_DAT_004aee00 == 1)))) {
      bVar19 = true;
    }
    if ((bVar19) &&
       (((_DAT_00803c40 + 1 <= (int)*(short *)(&DAT_0067fe10 + iVar18) ||
         (*(short *)(iVar18 + 0x67fe72) == 0)) &&
        (sVar3 = *(short *)(iVar18 + 0x67feb0), sVar3 != -1)))) {
      iVar10 = sVar3 * 0x6d0;
      if (((*(short *)(&DAT_0067fe10 + iVar10) != 0) &&
          (*(short *)(&DAT_0067fe10 + iVar10) != *(short *)(&DAT_0067fe10 + iVar18))) &&
         (iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar10) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar10) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10)),
         (short)iVar10 < 0x191)) {
        func_0x00424300(param_1,1);
        bVar19 = false;
        func_0x00423710(param_1,2,0xffffffff,(int)sVar3,0xffffffff,0xffffffff);
      }
    }
    if (((byte)_DAT_006df3b0 & 7) != ((byte)param_1 & 7)) {
      return;
    }
    if (!bVar19) {
      return;
    }
    local_10 = 29999;
    uStack_c = 0xffff;
    if (_DAT_006e5b38 < 0) {
      return;
    }
    uVar16 = 0;
    psVar4 = (short *)&DAT_0067fe10;
    do {
      if (((uVar16 != param_1) && (*psVar4 != 0)) &&
         ((psVar4[6] != 0 &&
          ((((((*(uint *)(psVar4 + 0x344) & 0x800) == 0x800 ||
              (*(short *)(&DAT_0067fe10 + iVar18) != *psVar4)) && (*psVar4 != 99)) &&
            (psVar4[0x366] == 0)) &&
           ((*psVar4 < 0x5a || ((int)*psVar4 - (int)*(short *)(&DAT_0067fe10 + iVar18) != 0x5a))))))
         )) {
        uVar1 = *(ushort *)(&DAT_0067fe10 + iVar18);
        if ((((((short)uVar1 < 0x5a) || ((int)(short)uVar1 - (int)*psVar4 != 0x5a)) &&
             (psVar4[1] != 0)) &&
            (((_DAT_00803c40 < (short)uVar1 || ((*(uint *)(psVar4 + 0x344) & 0x800) == 0x800)) ||
             (*(char *)((*(int *)(psVar4 + 0xc) >> 0x15) * 0x80 + 0x66da10 +
                       (*(int *)(psVar4 + 0xe) >> 0x15)) != '\0')))) &&
           (((psVar4[0x32a] < 0x79 && ((*(byte *)(psVar4 + 0x344) & 4) == 0)) ||
            (*(int *)((uVar1 & 7) * 4 + 0x9094c0) != 0)))) {
          iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(psVar4 + 0xc) >> 0x10),
                                (short)((uint)*(undefined4 *)(psVar4 + 0xe) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10));
          iVar10 = (int)(short)iVar10;
          if (((*(uint *)(&DAT_00680498 + iVar18) & 0x800) != 0x800) ||
             (*(short *)(iVar18 + 0x6804b2) < 9)) {
            if (((iVar10 < 0x280) && (iVar10 <= local_10)) &&
               ((*(short *)(iVar18 + 0x67fe7e) == 2 ||
                ((iVar10 <= *(short *)(iVar18 + 0x67fea2) && (iVar10 <= local_10)))))) {
              uStack_c = uVar16 & 0xffff;
              local_10 = iVar10;
            }
            if (_DAT_00803c40 < *(short *)(&DAT_0067fe10 + iVar18)) {
              if (*(short *)(&DAT_0067fe10 + iVar18) < 0x5a) {
                if (iVar10 < *(short *)(iVar18 + 0x67fea2) + 0x40) goto LAB_00455828;
              }
              else if ((iVar10 < 0x1e0) && (iVar10 <= local_10)) {
LAB_00455828:
                uStack_c = uVar16 & 0xffff;
                local_10 = iVar10;
              }
            }
          }
          if (((*(uint *)(&DAT_00680498 + iVar18) & 0x800) == 0x800) &&
             (8 < *(short *)(iVar18 + 0x6804b2))) {
            if (iVar10 < local_10) {
              uStack_c = uVar16 & 0xffff;
              local_10 = iVar10;
            }
          }
          else if ((short)uStack_c != -1) goto LAB_0045587f;
        }
      }
      psVar4 = psVar4 + 0x368;
      uVar16 = uVar16 + 1;
    } while ((int)uVar16 <= (int)_DAT_006e5b38);
    if ((short)uStack_c == -1) {
      return;
    }
LAB_0045587f:
    if ((_DAT_00803c40 == 1) ||
       ((bVar19 = _DAT_00668ccc == *(short *)(&DAT_0067fe10 + iVar18),
        _DAT_00803c40 < *(short *)(&DAT_0067fe10 + iVar18) && (_DAT_004aee00 == 1)))) {
      bVar19 = true;
    }
    if (!bVar19) {
      return;
    }
    if ((*(uint *)(&DAT_00680498 + iVar18) & 0x800) != 0) {
      func_0x00423710(param_1,2,0xffffffff,uStack_c,0xffffffff,0xffffffff);
      func_0x00424300(param_1,8);
      return;
    }
    if ((*(uint *)(&DAT_00680498 + iVar18) & 8) != 0) {
      return;
    }
    if (_DAT_0070db34 != 3) {
      func_0x00424300(param_1,1);
      func_0x00423710(param_1,2,0xffffffff,uStack_c,0xffffffff,0xffffffff);
      return;
    }
    if (*(short *)(&DAT_0067fe10 + iVar18) != _DAT_00668ccc) {
      iVar10 = *(int *)(&DAT_0067fe28 + iVar18);
      iVar18 = *(int *)(&DAT_0067fe2c + iVar18);
      iVar13 = *(int *)(&DAT_0067fe28 + (short)uStack_c * 0x6d0);
      iVar5 = *(int *)(&DAT_0067fe2c + (short)uStack_c * 0x6d0);
      iVar7 = FUN_00454c20(iVar10 + 0x200000,iVar18,iVar13,iVar5);
      cVar20 = iVar7 != 0;
      iVar7 = FUN_00454c20(iVar10 + -0x200000,iVar18,iVar13,iVar5);
      if (iVar7 != 0) {
        cVar20 = cVar20 + '\x01';
      }
      iVar7 = FUN_00454c20(iVar10,iVar18 + 0x200000,iVar13,iVar5);
      if (iVar7 != 0) {
        cVar20 = cVar20 + '\x01';
      }
      iVar18 = FUN_00454c20(iVar10,iVar18 + -0x200000,iVar13,iVar5);
      if (iVar18 != 0) {
        cVar20 = cVar20 + '\x01';
      }
      if (cVar20 != '\x04') {
        return;
      }
    }
    func_0x00424300(param_1,1);
    func_0x00423710(param_1,2,0xffffffff,uStack_c,0xffffffff,0xffffffff);
    return;
  case 1:
    *(undefined2 *)(iVar18 + 0x67fe80) = 0;
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    uVar16 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                          (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),sVar2,sVar3
                         );
    if ((uVar16 & 0xffe0) == 0) {
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      return;
    }
    if (*(short *)(iVar18 + 0x67fe74) != 7) {
      *(undefined2 *)(iVar18 + 0x680450) = 0;
      *(short *)(iVar18 + 0x6803f8) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x6803fa) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
      *(undefined2 *)(iVar18 + 0x68044e) = 0;
      *(undefined2 *)(iVar18 + 0x680452) = 0;
      uVar8 = FUN_00429c70(0,extraout_EDX_00,
                           (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                           (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),
                           *(short *)(iVar18 + 0x6803f8) * 0x20 + 0x10,
                           *(short *)(iVar18 + 0x6803fa) * 0x20 + 0x10);
      sVar3 = (short)uVar8;
      *(short *)(iVar18 + 0x67fe54) = sVar3;
      if (sVar3 != -1) {
        *(short *)(iVar18 + 0x67fe54) = sVar3 << 3;
      }
      sVar3 = 0;
      do {
        iVar10 = (int)sVar3;
        sVar3 = sVar3 + 1;
        *(undefined2 *)((iVar10 + param_1 * 0x368) * 2 + 0x6803fe) = 0xffff;
      } while (sVar3 < 0x14);
      *(short *)(iVar18 + 0x67fef2) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x67fef4) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x67feee) = sVar15;
      *(short *)(iVar18 + 0x67fef0) = sVar14;
      *(short *)(iVar18 + 0x67fe7a) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x67fe7c) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
      *(undefined4 *)(iVar18 + 0x67fe84) = *(undefined4 *)(iVar18 + 0x67fe20);
      *(undefined2 *)(iVar18 + 0x67fee0) = 0;
      *(undefined2 *)(iVar18 + 0x67fee4) = 0;
      *(undefined2 *)(iVar18 + 0x67fea0) = 1;
      sVar3 = *(short *)(iVar18 + 0x67fee6);
      if (sVar3 != -1) {
        *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
        *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
      }
      *(undefined2 *)(iVar18 + 0x67fe74) = *(undefined2 *)(iVar18 + 0x67fe72);
      *(undefined2 *)(iVar18 + 0x67fe72) = 5;
      return;
    }
    if (_DAT_004aee00 == 1) {
      func_0x00423710(param_1,0x29a,
                      CONCAT22(extraout_var_00,*(undefined2 *)(&DAT_0067fe12 + iVar18)),0,
                      *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,
                      *(int *)(&DAT_0067fe2c + iVar18) >> 0x10);
    }
    *(undefined2 *)(iVar18 + 0x67fe72) = 0;
    return;
  case 2:
    if (((&DAT_00680498)[iVar18] & 8) != 0) {
      *(undefined2 *)(iVar18 + 0x67fea2) = 100;
    }
    if ((*(byte *)(iVar18 + 0x680499) & 1) != 0) {
      if (*(short *)(iVar18 + 0x67fe58) == -1) goto LAB_00455ce5;
      func_0x0042bd90(0xffffffff,
                      CONCAT22((short)((short)uVar1 >> 0xf),*(short *)(iVar18 + 0x67fe58)),0x1f40000
                     );
      *(uint *)(&DAT_00680498 + iVar18) = *(uint *)(&DAT_00680498 + iVar18) & 0xfffffeff;
      iVar13 = extraout_EDX_01;
    }
    sVar12 = *(short *)(iVar18 + 0x67fe58);
    if (((sVar12 != -1) && (iVar13 = sVar12 * 9, 0x78 < *(short *)(&DAT_00680464 + sVar12 * 0x6d0)))
       && (*(int *)((*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4 + 0x9094c0) == 0)) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
LAB_00455ce5:
    if (*(short *)(iVar18 + 0x67fe74) == 7) {
      if (_DAT_004aee00 == 1) {
        func_0x00423710(param_1,0x29a,*(undefined2 *)(&DAT_0067fe12 + iVar18),0,
                        *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,
                        *(int *)(&DAT_0067fe2c + iVar18) >> 0x10);
      }
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      return;
    }
    *(undefined2 *)(iVar18 + 0x680450) = 0;
    *(short *)(iVar18 + 0x6803f8) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
    *(short *)(iVar18 + 0x6803fa) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
    *(undefined2 *)(iVar18 + 0x68044e) = 0;
    *(undefined2 *)(iVar18 + 0x680452) = 0;
    uVar8 = FUN_00429c70(0,iVar13,(short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                         (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),
                         *(short *)(iVar18 + 0x6803f8) * 0x20 + 0x10,
                         *(short *)(iVar18 + 0x6803fa) * 0x20 + 0x10);
    sVar12 = (short)uVar8;
    *(short *)(iVar18 + 0x67fe54) = sVar12;
    if (sVar12 != -1) {
      *(short *)(iVar18 + 0x67fe54) = sVar12 << 3;
    }
    sVar12 = 0;
    do {
      iVar10 = (int)sVar12;
      sVar12 = sVar12 + 1;
      *(undefined2 *)((iVar10 + param_1 * 0x368) * 2 + 0x6803fe) = 0xffff;
    } while (sVar12 < 0x14);
    *(short *)(iVar18 + 0x67fef2) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
    *(short *)(iVar18 + 0x67fef4) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
    *(short *)(iVar18 + 0x67feee) = sVar15;
    *(short *)(iVar18 + 0x67fef0) = sVar14;
    *(short *)(iVar18 + 0x67fe7a) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
    *(short *)(iVar18 + 0x67fe7c) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
    *(undefined4 *)(iVar18 + 0x67fe84) = *(undefined4 *)(iVar18 + 0x67fe20);
    *(undefined2 *)(iVar18 + 0x67fe80) = 0;
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                          (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),sVar2,sVar3
                         );
    sVar3 = (short)iVar10;
    if (*(short *)(iVar18 + 0x67fe56) != -1) {
      iVar10 = *(short *)(iVar18 + 0x67fe56) * 0xe0;
      sVar3 = sVar3 - (short)((*(int *)(iVar10 + 0x805e14) + *(int *)(iVar10 + 0x805e10)) / 4);
    }
    if (*(short *)(iVar18 + 0x67fea2) < sVar3) {
      *(undefined2 *)(iVar18 + 0x67fee0) = 0;
      *(undefined2 *)(iVar18 + 0x67fee4) = 0;
      *(undefined2 *)(iVar18 + 0x67fea0) = 1;
      sVar3 = *(short *)(iVar18 + 0x67fee6);
      if (sVar3 != -1) {
        *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
        *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
      }
      *(undefined2 *)(iVar18 + 0x67fe74) = *(undefined2 *)(iVar18 + 0x67fe72);
      *(undefined2 *)(iVar18 + 0x67fe72) = 5;
      return;
    }
    if (*(short *)(iVar18 + 0x67fea8) == 0) {
      *(ushort *)(iVar18 + 0x67fea8) =
           (ushort)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10) & 0xf;
    }
    *(undefined2 *)(iVar18 + 0x67fe72) = 3;
    return;
  case 3:
    break;
  default:
    goto switchD_00455042_caseD_4;
  case 5:
    *(undefined2 *)(iVar18 + 0x67fe80) = 0;
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    *(undefined2 *)(iVar18 + 0x67fe9c) = 1;
    if (*(short *)(iVar18 + 0x67fe74) == 7) {
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      return;
    }
    if (*(short *)(iVar18 + 0x67fea0) == 1) {
      *(undefined2 *)(iVar18 + 0x67fea0) = 0;
    }
    if (0 < *(short *)(iVar18 + 0x67fee4)) {
      if (*(short *)(iVar18 + 0x67fe74) == 1) {
        if (((short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15) ==
             *(short *)(iVar18 + 0x67feee)) &&
           ((short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15) ==
            *(short *)(iVar18 + 0x67fef0))) {
          if (*(short *)(iVar18 + 0x67fee0) == 0) {
            *(undefined2 *)(iVar18 + 0x67fe72) = 0;
            return;
          }
          *(undefined2 *)(iVar18 + 0x67fee0) = 0;
          *(undefined2 *)(iVar18 + 0x67fee4) = 0;
          sVar3 = *(short *)(iVar18 + 0x67fee6);
joined_r0x004567e9:
          if (sVar3 != -1) {
            *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
            iVar13 = sVar3 * 0x4b;
            *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
          }
          *(undefined2 *)(iVar18 + 0x67fe72) = 5;
        }
      }
      else if (*(short *)(iVar18 + 0x67fe74) == 2) {
        if (*(short *)(iVar18 + 0x67fee0) == 0) {
          iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                                (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),sVar2
                                ,sVar3);
          sVar3 = (short)iVar10;
          iVar13 = extraout_EDX_02;
          if (*(short *)(iVar18 + 0x67fe56) != -1) {
            iVar10 = *(short *)(iVar18 + 0x67fe56) * 0xe0;
            iVar10 = (*(int *)(iVar10 + 0x805e14) + *(int *)(iVar10 + 0x805e10)) / 2;
            iVar13 = iVar10 >> 0x1f;
            sVar3 = sVar3 - (short)(iVar10 / 2);
          }
          if (sVar3 <= *(short *)(iVar18 + 0x67fea2)) {
            *(undefined2 *)(iVar18 + 0x67fe72) = 3;
            return;
          }
        }
        else if (((short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15) ==
                  *(short *)(iVar18 + 0x67feee)) &&
                ((short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15) ==
                 *(short *)(iVar18 + 0x67fef0))) {
          *(undefined2 *)(iVar18 + 0x67fee0) = 0;
          *(undefined2 *)(iVar18 + 0x67fee4) = 0;
          sVar3 = *(short *)(iVar18 + 0x67fee6);
          goto joined_r0x004567e9;
        }
      }
    }
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    sVar3 = *(short *)(iVar18 + 0x67fee4);
    if (sVar3 < 0x29e) {
      if (sVar3 < 0x29a) {
        if (sVar3 == 0) {
          *(undefined2 *)(iVar18 + 0x6803f6) = 0;
          *(undefined2 *)(iVar18 + 0x67fee8) = 1;
          *(undefined2 *)(iVar18 + 0x67fee4) = 1;
          *(short *)(iVar18 + 0x67feea) =
               (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
          *(short *)(iVar18 + 0x67feec) =
               (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
          *(short *)(iVar18 + 0x67feee) = sVar15;
          *(short *)(iVar18 + 0x67fef0) = sVar14;
          *(undefined2 *)(iVar18 + 0x6803cc) = 0;
          *(undefined2 *)(iVar18 + 0x67fee0) = 0;
          func_0x00438fb0(iVar18 + 0x67fee4,param_1);
          return;
        }
        if (sVar3 != 2) {
          if (sVar3 == 3) {
            *(undefined2 *)(iVar18 + 0x67fef2) = *(undefined2 *)(iVar18 + 0x67ff0a);
            *(undefined2 *)(iVar18 + 0x67fef4) = *(undefined2 *)(iVar18 + 0x680162);
            uVar9 = (undefined2)((uint)iVar13 >> 0x10);
            uVar8 = CONCAT22(uVar9,*(undefined2 *)(iVar18 + 0x6803c8));
            *(undefined2 *)(iVar18 + 0x67ff06) = *(undefined2 *)(iVar18 + 0x6803c8);
            *(undefined2 *)(iVar18 + 0x67ff08) = 0;
            *(undefined2 *)(iVar18 + 0x6803cc) = 0;
            iVar10 = (int)*(short *)(iVar18 + 0x67fef2);
            if (*(int *)(&DAT_0067fe28 + iVar18) >> 0x15 == iVar10) {
              iVar10 = (int)*(short *)(iVar18 + 0x67fef4);
              if (*(int *)(&DAT_0067fe2c + iVar18) >> 0x15 == iVar10) {
                *(undefined2 *)(iVar18 + 0x67fef2) = *(undefined2 *)(iVar18 + 0x67ff0c);
                iVar10 = CONCAT22(*(short *)(iVar18 + 0x67fef4) >> 0xf,
                                  *(undefined2 *)(iVar18 + 0x680164));
                *(undefined2 *)(iVar18 + 0x67fef4) = *(undefined2 *)(iVar18 + 0x680164);
                uVar8 = CONCAT22(uVar9,*(undefined2 *)(iVar18 + 0x6803ca));
                *(undefined2 *)(iVar18 + 0x67ff06) = *(undefined2 *)(iVar18 + 0x6803ca);
                *(undefined2 *)(iVar18 + 0x67ff08) = 1;
                if (*(short *)(iVar18 + 0x6803ba) < 1) {
                  *(undefined2 *)(iVar18 + 0x67fe72) = 0;
                  return;
                }
              }
            }
            uVar8 = FUN_00429c70(iVar10,uVar8,
                                 (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                                 (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),
                                 *(short *)(iVar18 + 0x67fef2) * 0x20 + 0x10,
                                 *(short *)(iVar18 + 0x67fef4) * 0x20 + 0x10);
            sVar3 = (short)uVar8;
            *(short *)(iVar18 + 0x67fe54) = sVar3;
            if (sVar3 != -1) {
              *(short *)(iVar18 + 0x67fe54) = sVar3 << 3;
              *(int *)(iVar18 + 0x67fe64) = (int)(short)(sVar3 << 3);
            }
            *(undefined2 *)(iVar18 + 0x67fe72) = 6;
            return;
          }
          goto LAB_00456932;
        }
      }
      if ((sVar3 == 2) || (((byte)_DAT_006df3b0 & 1) == ((byte)param_1 & 1))) {
        func_0x00438fb0(iVar18 + 0x67fee4,param_1);
      }
      if (*(int *)(iVar18 + 0x680458) < 0x4b1) {
        return;
      }
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      *(undefined2 *)(iVar18 + 0x67fee4) = 0;
      sVar3 = *(short *)(iVar18 + 0x67fee6);
      *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
      *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
      return;
    }
LAB_00456932:
    sVar3 = *(short *)(iVar18 + 0x67fee6);
    if (sVar3 != -1) {
      *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
      *(undefined2 *)(sVar3 * 0x2ef4 + 0x6e75c0) = 0xffff;
    }
    *(undefined2 *)(iVar18 + 0x67fee4) = 1;
    *(short *)(iVar18 + 0x67feea) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
    *(short *)(iVar18 + 0x67feec) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
    sVar3 = *(short *)(iVar18 + 0x67fee0) + 1;
    *(short *)(iVar18 + 0x67fee0) = sVar3;
    if (0x4af < *(int *)(iVar18 + 0x680458)) {
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      return;
    }
    if (sVar3 < 5) {
      *(short *)(iVar18 + 0x67feea) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x67feec) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
      *(short *)(iVar18 + 0x67feee) = sVar15;
      *(short *)(iVar18 + 0x67fef0) = sVar14;
      uVar8 = func_0x00424460(param_1,uVar16,uVar11);
      *(short *)(iVar18 + 0x67feee) = (short)uVar8;
      *(short *)(iVar18 + 0x67fef0) = (short)((uint)uVar8 >> 0x10);
    }
    *(undefined2 *)(iVar18 + 0x67fe72) = 5;
    if ((*(short *)(iVar18 + 0x67fe74) != 7) && (*(short *)(iVar18 + 0x67fee0) < 5)) {
      func_0x00438fb0(iVar18 + 0x67fee4,param_1);
      return;
    }
    *(undefined2 *)(iVar18 + 0x67fe9e) = 1;
    *(undefined2 *)(iVar18 + 0x67fe72) = 0;
    return;
  case 6:
    func_0x0044e8d0(param_1);
    return;
  case 8:
    if (*(short *)(&DAT_0067fe12 + iVar18) == 0x11) {
      sVar3 = *(short *)(iVar18 + 0x67fe58);
      if (((sVar3 != -1) && ((int)sVar3 != param_1)) &&
         ((iVar10 = sVar3 * 0x6d0, *(short *)(&DAT_0067fe10 + iVar10) != 0 &&
          (*(short *)(&DAT_0067fe1c + iVar10) != 0)))) {
        if ((*(short *)(&DAT_0067fe10 + iVar18) == _DAT_00668ccc) || (_DAT_004aee00 == 1)) {
          func_0x0042bd90(0xffffffff,sVar3,0xffb00000);
        }
        *(undefined2 *)(iVar18 + 0x67fe58) = 0xffff;
        func_0x0042bd90(0xffffffff,param_1,0xa0000);
      }
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      return;
    }
    *(undefined2 *)(iVar18 + 0x67fe72) = 0;
    return;
  }
  if (*(short *)(iVar18 + 0x67fe58) != -1) {
    iVar10 = (int)*(short *)(iVar18 + 0x67fe58);
    if ((0x78 < *(short *)(&DAT_00680464 + iVar10 * 0x6d0)) &&
       (iVar10 = *(int *)((*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4 + 0x9094c0), iVar10 == 0)) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    if ((*(short *)(iVar18 + 0x6804b2) < 8) && ((*(byte *)(iVar18 + 0x680499) & 8) != 0)) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
  }
  if (((&DAT_00680498)[iVar18] & 8) != 0) {
    FUN_00429de0(0x1d,*(short *)(&DAT_0067fe10 + iVar18),
                 (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                 (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),-1,-1);
    *(uint *)(&DAT_00680498 + iVar18) = *(uint *)(&DAT_00680498 + iVar18) & 0xfffffff7;
    *(undefined2 *)(iVar18 + 0x67fea2) =
         *(undefined2 *)(*(short *)(&DAT_0067fe12 + iVar18) * 0x4c + 0x4c086c);
    *(undefined2 *)(iVar18 + 0x67fe72) = 0;
    func_0x0049c430(0x90a9d0,0x85fb40,
                    *(undefined4 *)
                     (*(int *)((*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4 + 0x835260) * 4 +
                     0x4baf08),(*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 0x80 + 0x78b770);
    func_0x0041fff0(0x90a9d0);
    iVar10 = (*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4;
    if (*(int *)((*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4 + 0x9d6340) != 3) {
      return;
    }
    iVar13 = (int)*(short *)(iVar10 + 0x90aad0);
    sVar3 = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
    sVar2 = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
    if ((((*(short *)(iVar13 * 2 + 0x773440) + -6 <= (int)sVar3) &&
         ((int)sVar3 <= *(short *)(iVar13 * 2 + 0x77b460) + 6)) &&
        (*(short *)(iVar13 * 2 + 0x77b470) + -6 <= (int)sVar2)) &&
       ((int)sVar2 <= *(short *)(iVar13 * 2 + 0x77b480) + 6)) {
      *(undefined4 *)(iVar10 + 0x9dbbd0) = 0;
    }
    iVar10 = 0;
    if (_DAT_0083a402 < 0) {
      return;
    }
    piVar17 = (int *)&DAT_00805df0;
    while (((*piVar17 == 0 || (piVar17[2] == 0)) ||
           ((*piVar17 != iVar13 ||
            (iVar5 = FUN_00429cd0(sVar3,sVar2,(short)piVar17[6],(short)piVar17[7]), 6 < (short)iVar5
            ))))) {
      piVar17 = piVar17 + 0x38;
      iVar10 = iVar10 + 1;
      if (_DAT_0083a402 < iVar10) {
        return;
      }
    }
    *(undefined4 *)((*(ushort *)(&DAT_0067fe10 + iVar18) & 7) * 4 + 0x9dbbd0) = 0;
    return;
  }
  *(short *)(iVar18 + 0x67fef2) = (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
  *(short *)(iVar18 + 0x67fef4) = (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
  *(short *)(iVar18 + 0x67feee) = sVar15;
  *(short *)(iVar18 + 0x67fef0) = sVar14;
  *(undefined2 *)(iVar18 + 0x67fea0) = 1;
  *(undefined2 *)(iVar18 + 0x67fe80) = 0;
  *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
  *(undefined4 *)(iVar18 + 0x67fe40) = 0;
  *(undefined2 *)(iVar18 + 0x67fe9c) = 1;
  *(undefined2 *)(iVar18 + 0x67fee4) = 0;
  if (*(short *)(iVar18 + 0x67fee6) != -1) {
    iVar10 = (int)*(short *)(iVar18 + 0x67fee6);
    *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
    *(undefined2 *)(iVar10 * 0x2ef4 + 0x6e75c0) = 0xffff;
  }
  if (*(short *)(iVar18 + 0x67fe58) != -1) {
    if (*(short *)(&DAT_0067fe10 + *(short *)(iVar18 + 0x67fe58) * 0x6d0) == 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    if (*(short *)(&DAT_0067fe1c + *(short *)(iVar18 + 0x67fe58) * 0x6d0) == 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    iVar10 = *(int *)(*(short *)(iVar18 + 0x67fe58) * 0x6d0 + 0x67fe20);
    if (iVar10 < 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    if (*(short *)(iVar18 + 0x67fe74) == 7) {
      sVar3 = -1;
      sVar2 = -1;
    }
  }
  if (*(short *)(iVar18 + 0x67fe56) == -1) {
LAB_0045632a:
    uVar9 = (undefined2)((uint)iVar10 >> 0x10);
    if (*(short *)(iVar18 + 0x67fe74) == 7) goto LAB_004566bf;
  }
  else {
    if (*(int *)(&DAT_00805df0 + *(short *)(iVar18 + 0x67fe56) * 0xe0) == 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    iVar10 = *(int *)(&DAT_00805df8 + *(short *)(iVar18 + 0x67fe56) * 0xe0);
    if (iVar10 == 0) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
    }
    if (*(short *)(iVar18 + 0x67fe74) == 7) {
      sVar3 = -1;
      sVar2 = -1;
      goto LAB_0045632a;
    }
  }
  uVar9 = (undefined2)((uint)iVar10 >> 0x10);
  if ((sVar2 != -1) && (sVar3 != -1)) {
    func_0x0043efb0(param_1,(int)sVar2,(int)sVar3);
    if ((sVar2 == -1) && (sVar3 == -1)) {
      *(undefined2 *)(iVar18 + 0x67fe72) = 0;
      if (_DAT_004aee00 != 1) {
        return;
      }
      func_0x00423710(param_1,0x29a,
                      CONCAT22(extraout_var_01,*(undefined2 *)(&DAT_0067fe12 + iVar18)),0,
                      *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,
                      *(int *)(&DAT_0067fe2c + iVar18) >> 0x10);
      return;
    }
    if ((*(short *)(iVar18 + 0x67fe7e) == 9) &&
       (*(int *)(iVar18 + 0x67fe20) <= *(int *)(iVar18 + 0x67fe84) / 2)) {
      iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                            (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),sVar2,
                            sVar3);
      sVar3 = (short)iVar10;
      if (*(short *)(iVar18 + 0x67fe56) != -1) {
        iVar10 = *(short *)(iVar18 + 0x67fe56) * 0xe0;
        sVar3 = sVar3 - (short)((*(int *)(iVar10 + 0x805e14) + *(int *)(iVar10 + 0x805e10)) / 4);
      }
      sVar2 = *(short *)(iVar18 + 0x67fea2);
      iVar10 = (int)(sVar2 >> 1) + (int)sVar2;
      if (sVar3 <= iVar10) {
        *(undefined2 *)(iVar18 + 0x67fe80) = 1;
        uVar9 = *(undefined2 *)(iVar18 + 0x67fe74);
        *(undefined2 *)(iVar18 + 0x67fe72) = 1;
        *(undefined2 *)(iVar18 + 0x680450) = 0;
        *(short *)(iVar18 + 0x6803f8) =
             (short)((int)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x15);
        *(short *)(iVar18 + 0x6803fa) =
             (short)((int)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x15);
        *(undefined2 *)(iVar18 + 0x67fea0) = 0;
        uVar8 = FUN_00429c70((int)sVar3,iVar10,
                             (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                             (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),
                             *(short *)(iVar18 + 0x6803f8) * 0x20 + 0x10,
                             *(short *)(iVar18 + 0x6803fa) * 0x20 + 0x10);
        sVar3 = (short)uVar8;
        *(short *)(iVar18 + 0x67fe54) = sVar3;
        if (sVar3 != -1) {
          *(short *)(iVar18 + 0x67fe54) = sVar3 << 3;
        }
        func_0x0043c0c0(param_1,CONCAT22(extraout_var_02,*(undefined2 *)(iVar18 + 0x67fe7a)),
                        *(undefined2 *)(iVar18 + 0x67fe7c));
        *(undefined2 *)(iVar18 + 0x67fe80) = 0;
        *(undefined2 *)(iVar18 + 0x67fe50) = 0xffff;
        *(undefined2 *)(iVar18 + 0x67fe52) = 0xffff;
        *(undefined2 *)(iVar18 + 0x67fe74) = uVar9;
        *(undefined2 *)(iVar18 + 0x67fe72) = 3;
        return;
      }
      func_0x00423710(param_1,1,0xffffffff,0xffffffff,
                      CONCAT22(sVar3 >> 0xf,*(undefined2 *)(iVar18 + 0x67fe7a)),
                      CONCAT22(sVar2 >> 0xf,*(undefined2 *)(iVar18 + 0x67fe7c)));
      func_0x00424300(param_1,6);
      return;
    }
    iVar10 = FUN_00429cd0((short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar18) >> 0x10),
                          (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar18) >> 0x10),sVar2,sVar3
                         );
    sVar3 = (short)iVar10;
    if (*(short *)(iVar18 + 0x67fe56) != -1) {
      iVar10 = *(short *)(iVar18 + 0x67fe56) * 0xe0;
      sVar3 = sVar3 - (short)((*(int *)(iVar10 + 0x805e14) + *(int *)(iVar10 + 0x805e10)) / 4);
    }
    iVar13 = CONCAT22(extraout_var_03,sVar3);
    sVar2 = *(short *)(iVar18 + 0x67fea2);
    iVar10 = (int)(sVar2 >> 1) + (int)sVar2;
    if (sVar3 < iVar10) {
      return;
    }
    sVar2 = sVar2 >> 0xf;
    if (*(short *)(iVar18 + 0x67fe7e) == 1) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
      return;
    }
    iVar10 = iVar10 * 2;
    if ((iVar10 < sVar3) && (*(short *)(iVar18 + 0x67fe7e) != 8)) {
      *(undefined2 *)(iVar18 + 0x67fe74) = 7;
      return;
    }
    *(undefined2 *)(iVar18 + 0x67fe80) = 0;
    *(undefined4 *)(iVar18 + 0x67fe3c) = 0;
    *(undefined4 *)(iVar18 + 0x67fe40) = 0;
    *(undefined2 *)(iVar18 + 0x67fee0) = 0;
    *(undefined2 *)(iVar18 + 0x67fee4) = 0;
    if (*(short *)(iVar18 + 0x67fee6) != -1) {
      iVar13 = (int)*(short *)(iVar18 + 0x67fee6);
      *(undefined2 *)(iVar18 + 0x67fee6) = 0xffff;
      iVar10 = iVar13 * 0x4b;
      sVar2 = (short)((uint)(iVar13 * 0x964) >> 0x10);
      *(undefined2 *)(iVar13 * 0x2ef4 + 0x6e75c0) = 0xffff;
    }
    if (_DAT_004aee00 != 1) {
      return;
    }
    func_0x00423710(param_1,2,CONCAT22(sVar2,*(undefined2 *)(iVar18 + 0x67fe56)),
                    CONCAT22((short)((uint)iVar10 >> 0x10),*(undefined2 *)(iVar18 + 0x67fe58)),
                    CONCAT22((short)((uint)iVar13 >> 0x10),*(undefined2 *)(iVar18 + 0x67fe50)),
                    CONCAT22(sVar2,*(undefined2 *)(iVar18 + 0x67fe52)));
    return;
  }
LAB_004566bf:
  *(undefined2 *)(iVar18 + 0x67fe72) = 0;
  if (_DAT_004aee00 != 1) {
    return;
  }
  func_0x00423710(param_1,0x29a,CONCAT22(uVar9,*(undefined2 *)(&DAT_0067fe12 + iVar18)),0,
                  *(int *)(&DAT_0067fe28 + iVar18) >> 0x10,*(int *)(&DAT_0067fe2c + iVar18) >> 0x10)
  ;
  return;
}



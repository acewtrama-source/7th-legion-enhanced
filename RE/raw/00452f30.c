
/* WARNING: Removing unreachable block (ram,0x00453276) */
/* WARNING: Removing unreachable block (ram,0x0045327f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl f_452f30(uint param_1)

{
  undefined2 uVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  undefined4 uVar11;
  undefined2 uVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  short local_e;
  short sStack_c;
  short sStack_a;
  short sStack_8;
  undefined2 uStack_6;
  
                    /* 0x52f30  34  f_452f30 */
  iVar14 = param_1 * 0x6d0;
  sVar3 = *(short *)(&DAT_0067fe12 + iVar14);
  *(undefined2 *)(iVar14 + 0x67fe9c) = 1;
  *(undefined4 *)(iVar14 + 0x68045c) = 0;
  *(undefined4 *)(iVar14 + 0x680458) = 0;
  uVar12 = *(undefined2 *)(iVar14 + 0x67fe72);
  switch(uVar12) {
  case 0:
    *(undefined2 *)(iVar14 + 0x67fe56) = 0xffff;
    *(undefined2 *)(iVar14 + 0x67fe58) = 0xffff;
    *(undefined2 *)(iVar14 + 0x67fe76) = 0;
    if (*(short *)(iVar14 + 0x67fed4) == 0) {
      if (_DAT_004aee00 == 1) {
        func_0x00423710(param_1,10,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
      }
      *(undefined2 *)(iVar14 + 0x67fe76) = 0;
      return;
    }
    uVar11 = CONCAT22((short)(param_1 * 0x1b >> 0x10),0xffff);
    if (((((int)_DAT_008351d0 ^ param_1) & 7) == 0) && (sVar3 = 0, -1 < _DAT_0083a402)) {
      do {
        iVar9 = sVar3 * 0xe0;
        if (((((*(int *)(&DAT_00805df0 + iVar9) == (int)*(short *)(&DAT_0067fe10 + iVar14)) &&
              (*(int *)(&DAT_00805df8 + iVar9) != 0)) && (*(int *)(iVar9 + 0x805df4) == 4)) &&
            ((*(int *)(iVar9 + 0x805e58) != 1 && (*(int *)(iVar9 + 0x805e5c) == 0)))) &&
           (*(int *)(iVar9 + 0x805e90) + (int)_DAT_004bbde2 <= (int)_DAT_004bbfe6)) {
          uVar12 = (undefined2)((uint)uVar11 >> 0x10);
          uVar11 = CONCAT22(uVar12,sVar3);
          sVar6 = 0;
          if (-1 < _DAT_006e5b38) {
            do {
              if ((int)sVar6 != param_1) {
                iVar9 = sVar6 * 0x6d0;
                if (((*(short *)(&DAT_0067fe12 + iVar9) == 0) ||
                    (*(short *)(&DAT_0067fe12 + iVar9) == 1)) &&
                   ((*(short *)(iVar9 + 0x67fe56) == sVar3 &&
                    (*(short *)(&DAT_0067fe10 + iVar9) == *(short *)(&DAT_0067fe10 + iVar14))))) {
                  uVar11 = CONCAT22(uVar12,0xffff);
                  break;
                }
              }
              sVar6 = sVar6 + 1;
            } while (sVar6 <= _DAT_006e5b38);
          }
          if ((short)uVar11 != -1) break;
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 <= _DAT_0083a402);
    }
    if (-1 < (short)uVar11) {
      iVar13 = (short)uVar11 * 0xe0;
      iVar7 = CONCAT22((short)((uint)*(undefined4 *)(&DAT_00805e08 + iVar13) >> 0x10),
                       (short)*(undefined4 *)(&DAT_00805e08 + iVar13) << 5);
      iVar9 = iVar7 + 0x38;
      if (*(int *)(iVar13 + 0x805e00) == 1) {
        iVar9 = iVar7 + 0x58;
      }
      if (_DAT_004aee00 == 1) {
        func_0x00423710(param_1,0xd,uVar11,0xffffffff,iVar9,
                        CONCAT22((short)((uint)*(undefined4 *)(iVar13 + 0x805e14) >> 0x10),
                                 ((short)*(undefined4 *)(iVar13 + 0x805e14) +
                                 *(short *)(&DAT_00805e0c + iVar13)) * 0x20 + 0xf));
      }
      *(undefined2 *)(iVar14 + 0x67fe76) = 0;
      return;
    }
    break;
  case 2:
  case 3:
  case 7:
    *(undefined2 *)(iVar14 + 0x67fe72) = 1;
    *(undefined2 *)(iVar14 + 0x67fe74) = 0;
  case 1:
  case 5:
  case 6:
    f_454d20(param_1);
    break;
  case 10:
    if (sVar3 != 1) {
      if (*(short *)(iVar14 + 0x67fe74) == 0) {
        *(undefined2 *)(iVar14 + 0x67fe56) = 0xffff;
        sStack_a = 0x1060;
        sStack_c = (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10);
        sVar3 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10);
        if (sVar3 < (short)(0x1000 - sVar3)) {
          sStack_a = -0x60;
        }
        local_e = -1;
        sVar6 = 0;
        if (-1 < _DAT_0083a402) {
LAB_00453201:
          iVar9 = sVar6 * 0xe0;
          if (((*(int *)(&DAT_00805df8 + iVar9) == 0) ||
              (*(int *)(&DAT_00805df0 + iVar9) != (int)*(short *)(&DAT_0067fe10 + iVar14))) ||
             (*(int *)(iVar9 + 0x805df4) != 0x14)) goto LAB_00453293;
          sVar10 = 0;
          if (-1 < _DAT_006e5b38) {
            do {
              sVar10 = sVar10 + 1;
            } while (sVar10 <= _DAT_006e5b38);
          }
          sStack_a = ((short)*(undefined4 *)(&DAT_00805e08 + sVar6 * 0xe0) + 1) * 0x20;
          sVar10 = (short)*(undefined4 *)(&DAT_00805e0c + sVar6 * 0xe0) + 1;
          FUN_00429c50(sStack_a - sVar3,(sStack_c + sVar10 * -0x20) * 2);
          local_e = sVar6;
          sStack_c = sVar10 * 0x20;
        }
LAB_004532f9:
        if (_DAT_004aee00 == 1) {
          func_0x00423710(param_1,10,CONCAT22(sStack_c,local_e),0xffffffff,CONCAT22(sVar3,sStack_a),
                          CONCAT22(sStack_a,sStack_c));
        }
      }
      else {
        if ((*(short *)(iVar14 + 0x67fe56) != -1) &&
           ((iVar9 = *(short *)(iVar14 + 0x67fe56) * 0xe0, *(int *)(&DAT_00805df0 + iVar9) == 0 ||
            (*(int *)(&DAT_00805df8 + iVar9) == 0)))) {
          *(undefined2 *)(iVar14 + 0x67fe72) = 0;
          return;
        }
        _DAT_006dd174 = 0;
        if (0 < _DAT_006df0f8) {
          do {
            uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) -
                                 (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10),
                                 ((short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                                 *(short *)(iVar14 + 0x67fe52)) * 2);
            sVar3 = (short)(uVar5 >> 8) >> 2;
            *(short *)(iVar14 + 0x67fe54) = sVar3;
            sVar6 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10) -
                    *(short *)(iVar14 + 0x67fe50);
            sVar10 = (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                     *(short *)(iVar14 + 0x67fe52);
            if (sVar6 < 0) {
              sVar6 = -sVar6;
            }
            if (sVar10 < 0) {
              sVar10 = -sVar10;
            }
            if ((sVar6 < 4) && (sVar10 < 4)) {
              uVar8 = *(uint *)(iVar14 + 0x67fe44);
              if ((uVar8 & 0xffff0000) == 0x200000) {
                if (0x4000 < *(int *)(iVar14 + 0x67fe48)) {
                  *(int *)(iVar14 + 0x67fe48) = *(int *)(iVar14 + 0x67fe48) + -0x1000;
                }
                if ((int)*(short *)(iVar14 + 0x67fe50) < *(int *)(&DAT_0067fe28 + iVar14) >> 0x10) {
                  *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) + -0x10000;
                }
                if (*(int *)(&DAT_0067fe28 + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe50)) {
                  *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) + 0x10000;
                }
                if ((int)*(short *)(iVar14 + 0x67fe52) < *(int *)(&DAT_0067fe2c + iVar14) >> 0x10) {
                  *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) + -0x10000;
                }
                if (*(int *)(&DAT_0067fe2c + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe52)) {
                  *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) + 0x10000;
                }
                *(undefined4 *)(iVar14 + 0x67fe3c) = 0;
                *(undefined4 *)(iVar14 + 0x67fe40) = 0;
              }
              else {
                sVar3 = ((ushort)(uVar8 >> 0x10) & 0x3f) * 4 + -0x80;
                if (sVar3 < 0) {
                  *(uint *)(iVar14 + 0x67fe44) = uVar8 + 0x8000;
                }
                if (0 < sVar3) {
                  *(int *)(iVar14 + 0x67fe44) = *(int *)(iVar14 + 0x67fe44) + -0x8000;
                }
                *(uint *)(iVar14 + 0x67fe44) = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
              }
            }
            else {
              uVar8 = *(uint *)(iVar14 + 0x67fe48);
              if ((int)(uVar8 & 0xffff0000) < 0x60000) {
                *(uint *)(iVar14 + 0x67fe48) =
                     (0xa00 - ((int)(uVar8 & 0xffff00ff) >> 8)) * (int)_DAT_006df0f8 + uVar8;
                *(undefined4 *)(iVar14 + 0x67fe3c) = 0;
                *(undefined4 *)(iVar14 + 0x67fe40) = 0;
              }
              else {
                iVar9 = *(int *)(iVar14 + 0x67fe44);
                sVar6 = (short)((uint)iVar9 >> 0x10);
                if ((int)sVar3 == iVar9 >> 0x10) {
LAB_00453622:
                  *(undefined4 *)(iVar14 + 0x67fe3c) = *(undefined4 *)(sVar6 * 0x10 + 0x4b9e88);
                  iVar9 = *(int *)(sVar6 * 0x10 + 0x4ba288);
                }
                else {
                  sVar3 = ((sVar6 - sVar3) + 0x20U & 0x3f) * 4 + -0x80;
                  if (sVar3 < 0) {
                    *(int *)(iVar14 + 0x67fe44) = iVar9 + 0x8000;
                  }
                  if (0 < sVar3) {
                    *(int *)(iVar14 + 0x67fe44) = *(int *)(iVar14 + 0x67fe44) + -0x8000;
                  }
                  uVar8 = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
                  *(uint *)(iVar14 + 0x67fe44) = uVar8;
                  sVar6 = (short)(uVar8 >> 0x10);
                  if ((sVar3 < 9) && (-9 < sVar3)) goto LAB_00453622;
                  iVar9 = *(int *)(sVar6 * 0x10 + 0x4b9e88);
                  *(int *)(iVar14 + 0x67fe3c) = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
                  iVar9 = *(int *)(sVar6 * 0x10 + 0x4ba288);
                  iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
                }
                *(int *)(iVar14 + 0x67fe40) = -iVar9;
              }
              *(int *)(&DAT_0067fe28 + iVar14) =
                   *(int *)(&DAT_0067fe28 + iVar14) + *(int *)(iVar14 + 0x67fe3c);
              *(int *)(&DAT_0067fe2c + iVar14) =
                   *(int *)(&DAT_0067fe2c + iVar14) + *(int *)(iVar14 + 0x67fe40);
            }
            _DAT_006dd174 = _DAT_006dd174 + 1;
          } while (_DAT_006dd174 < _DAT_006df0f8);
        }
      }
    }
    sStack_8 = -1;
    if ((((byte)_DAT_006df3b0 & 7) == ((byte)param_1 & 7)) && (sVar3 = 0, -1 < _DAT_0083a402)) {
      do {
        iVar9 = sVar3 * 0xe0;
        if ((((*(int *)(&DAT_00805df0 + iVar9) == (int)*(short *)(&DAT_0067fe10 + iVar14)) &&
             (*(int *)(&DAT_00805df8 + iVar9) != 0)) && (*(int *)(iVar9 + 0x805df4) == 3)) &&
           ((int)_DAT_004bbde2 <= *(int *)(iVar9 + 0x805e90))) {
          sVar6 = 0;
          sStack_8 = sVar3;
          if (-1 < _DAT_006e5b38) {
            do {
              iVar9 = sVar6 * 0x6d0;
              if (((((*(short *)(&DAT_0067fe10 + iVar9) != 0) &&
                    (*(short *)(&DAT_0067fe1c + iVar9) != 0)) &&
                   (((int)sVar6 != param_1 &&
                    ((*(short *)(&DAT_0067fe12 + iVar9) == 0 ||
                     (*(short *)(&DAT_0067fe12 + iVar9) == 1)))))) &&
                  (*(short *)(iVar9 + 0x67fe56) == sVar3)) &&
                 (*(short *)(&DAT_0067fe10 + iVar9) == *(short *)(&DAT_0067fe10 + iVar14))) {
                sStack_8 = -1;
                break;
              }
              sVar6 = sVar6 + 1;
            } while (sVar6 <= _DAT_006e5b38);
          }
          if (sStack_8 != -1) break;
        }
        sVar3 = sVar3 + 1;
      } while (sVar3 <= _DAT_0083a402);
    }
    if (-1 < sStack_8) {
      iVar13 = sStack_8 * 0xe0;
      uVar11 = *(undefined4 *)(iVar13 + 0x805e14);
      iVar7 = CONCAT22((short)((uint)*(undefined4 *)(&DAT_00805e08 + iVar13) >> 0x10),
                       (short)*(undefined4 *)(&DAT_00805e08 + iVar13) << 5);
      sVar3 = *(short *)(&DAT_00805e0c + iVar13);
      iVar9 = iVar7 + 0x16;
      if (*(int *)(iVar13 + 0x805e00) == 1) {
        iVar9 = iVar7 + 0x36;
      }
      *(undefined2 *)(iVar14 + 0x67fe76) = 0;
      if (_DAT_004aee00 == 1) {
        func_0x00423710(param_1,0xb,CONCAT22(uStack_6,sStack_8),0xffffffff,iVar9,
                        CONCAT22((short)((uint)uVar11 >> 0x10),((short)uVar11 + sVar3) * 0x20 + 0xf)
                       );
        return;
      }
    }
    break;
  case 0xb:
    sVar3 = *(short *)(iVar14 + 0x67fe56);
    if (sVar3 == -1) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    if ((*(int *)(&DAT_00805df0 + sVar3 * 0xe0) == 0) ||
       (*(int *)(&DAT_00805df8 + sVar3 * 0xe0) == 0)) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    if (*(short *)(&DAT_0067fe12 + iVar14) == 1) {
      sVar4 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10);
      sVar6 = sVar4 - *(short *)(iVar14 + 0x67fe50);
      sVar10 = (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
               *(short *)(iVar14 + 0x67fe52);
      if (sVar6 < 0) {
        sVar6 = -sVar6;
      }
      sVar15 = sVar10;
      if (sVar10 < 0) {
        sVar15 = -sVar10;
      }
      if ((sVar6 < 0x40) && (sVar15 < 0x40)) {
        uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) - sVar4,sVar10 * 2);
        sVar3 = (short)(uVar5 >> 8) >> 2;
        *(short *)(iVar14 + 0x67fe54) = sVar3;
        *(ushort *)(iVar14 + 0x67fe54) = sVar3 + 0x20U & 0x3f;
        *(undefined2 *)(iVar14 + 0x67fe72) = 0xc;
        *(undefined2 *)(iVar14 + 0x67fe76) = 0;
        *(undefined2 *)(iVar14 + 0x67feb8) = 0;
        return;
      }
      uVar1 = *(undefined2 *)(iVar14 + 0x67fe74);
      if (*(short *)(iVar14 + 0x67fe76) == 0) {
        *(undefined2 *)(iVar14 + 0x67fe76) = 1;
      }
      *(undefined2 *)(iVar14 + 0x67fe72) = *(undefined2 *)(iVar14 + 0x67fe76);
      *(undefined2 *)(iVar14 + 0x67fe74) = 0;
      *(undefined2 *)(iVar14 + 0x67fe56) = 0xffff;
      *(undefined2 *)(iVar14 + 0x67fea0) = 0;
      f_454d20(param_1);
      *(undefined2 *)(iVar14 + 0x67fe76) = *(undefined2 *)(iVar14 + 0x67fe72);
      *(undefined2 *)(iVar14 + 0x67fe72) = uVar12;
      *(undefined2 *)(iVar14 + 0x67fe74) = uVar1;
      *(short *)(iVar14 + 0x67fe56) = sVar3;
      return;
    }
    uVar8 = *(uint *)(iVar14 + 0x67fe48);
    if ((int)(uVar8 & 0xffff0000) < 0x60000) {
      *(uint *)(iVar14 + 0x67fe48) =
           (0xa00 - ((int)(uVar8 & 0xffff00ff) >> 8)) * (int)_DAT_006df0f8 + uVar8;
      return;
    }
    _DAT_006dd174 = 0;
    if (0 < _DAT_006df0f8) {
      do {
        uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) -
                             (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10),
                             ((short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                             *(short *)(iVar14 + 0x67fe52)) * 2);
        sVar10 = _DAT_006df0f8;
        sVar4 = (short)(uVar5 >> 8) >> 2;
        *(short *)(iVar14 + 0x67fe54) = sVar4;
        sVar6 = _DAT_006dd174;
        iVar9 = *(int *)(iVar14 + 0x67fe44);
        sVar3 = (short)((uint)iVar9 >> 0x10);
        if ((int)sVar4 == iVar9 >> 0x10) {
LAB_00453ab0:
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4ba288);
          *(undefined4 *)(iVar14 + 0x67fe3c) = *(undefined4 *)(sVar3 * 0x10 + 0x4b9e88);
        }
        else {
          sVar4 = ((sVar3 - sVar4) + 0x20U & 0x3f) * 4 + -0x80;
          if (sVar4 < 0) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + 0x8000;
          }
          if (0 < sVar4) {
            *(int *)(iVar14 + 0x67fe44) = *(int *)(iVar14 + 0x67fe44) + -0x8000;
          }
          uVar8 = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
          *(uint *)(iVar14 + 0x67fe44) = uVar8;
          sVar3 = (short)(uVar8 >> 0x10);
          if ((sVar4 < 9) && (-9 < sVar4)) goto LAB_00453ab0;
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4b9e88);
          *(int *)(iVar14 + 0x67fe3c) = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4ba288);
          iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
        }
        *(int *)(iVar14 + 0x67fe40) = -iVar9;
        *(int *)(&DAT_0067fe28 + iVar14) =
             *(int *)(&DAT_0067fe28 + iVar14) + *(int *)(iVar14 + 0x67fe3c);
        iVar9 = *(int *)(&DAT_0067fe2c + iVar14) + *(int *)(iVar14 + 0x67fe40);
        *(int *)(&DAT_0067fe2c + iVar14) = iVar9;
        sVar3 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10) -
                *(short *)(iVar14 + 0x67fe50);
        sVar4 = (short)((uint)iVar9 >> 0x10) - *(short *)(iVar14 + 0x67fe52);
        if (sVar3 < 0) {
          sVar3 = -sVar3;
        }
        if (sVar4 < 0) {
          sVar4 = -sVar4;
        }
        if ((sVar3 < 4) && (sVar4 < 4)) {
          *(undefined2 *)(iVar14 + 0x67fe54) = 0x28;
          *(undefined2 *)(iVar14 + 0x67fe72) = 0xc;
          *(undefined2 *)(iVar14 + 0x67feb8) = 0;
          return;
        }
        _DAT_006dd174 = sVar6 + 1;
        if (sVar10 <= _DAT_006dd174) {
          return;
        }
      } while( true );
    }
    break;
  case 0xc:
    bVar2 = false;
    if (*(short *)(iVar14 + 0x67fe56) == -1) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    iVar9 = *(short *)(iVar14 + 0x67fe56) * 0xe0;
    if ((*(int *)(&DAT_00805df0 + iVar9) == 0) || (*(int *)(&DAT_00805df8 + iVar9) == 0)) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    _DAT_006dd174 = 0;
    sVar3 = _DAT_006df0f8;
    if (0 < _DAT_006df0f8) {
      do {
        bVar2 = false;
        iVar9 = *(int *)(iVar14 + 0x67fe44);
        if ((int)*(short *)(iVar14 + 0x67fe54) != iVar9 >> 0x10) {
          sVar6 = (((short)((uint)iVar9 >> 0x10) - *(short *)(iVar14 + 0x67fe54)) + 0x20U & 0x3f) *
                  4 + -0x80;
          if (sVar6 < 0) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + 0x8000;
            sVar6 = *(short *)(iVar14 + 0x67fe54);
            if (-1 < (short)((((short)((uint)(iVar9 + 0x8000) >> 0x10) - sVar6) + 0x20U & 0x3f) * 4
                            + -0x80)) {
LAB_00453c66:
              *(int *)(iVar14 + 0x67fe44) = (int)sVar6 << 0x10;
            }
          }
          else if (0 < sVar6) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + -0x8000;
            sVar6 = *(short *)(iVar14 + 0x67fe54);
            if ((short)((((short)((uint)(iVar9 + -0x8000) >> 0x10) - sVar6) + 0x20U & 0x3f) * 4 +
                       -0x80) < 1) goto LAB_00453c66;
          }
          bVar2 = true;
          *(uint *)(iVar14 + 0x67fe44) = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
        }
        if (!bVar2) {
          uVar8 = *(uint *)(iVar14 + 0x67fe48);
          if (0x4000 < (int)uVar8) {
            bVar2 = true;
            *(uint *)(iVar14 + 0x67fe48) = (uVar8 - ((int)(uVar8 & 0xffff00ff) >> 8)) + -0x400;
          }
          iVar9 = 0x10000;
          if (*(short *)(&DAT_0067fe12 + iVar14) == 1) {
            iVar9 = 0xc000;
            uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) -
                                 (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10),
                                 ((short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                                 *(short *)(iVar14 + 0x67fe52)) * 2);
            sVar3 = _DAT_006df0f8;
            sVar6 = (short)(uVar5 >> 8) >> 2;
            *(short *)(iVar14 + 0x67fe54) = sVar6;
            *(ushort *)(iVar14 + 0x67fe54) = sVar6 + 0x20U & 0x3f;
          }
          if ((int)*(short *)(iVar14 + 0x67fe50) < *(int *)(&DAT_0067fe28 + iVar14) >> 0x10) {
            bVar2 = true;
            *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) - iVar9;
          }
          if (*(int *)(&DAT_0067fe28 + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe50)) {
            bVar2 = true;
            *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) + iVar9;
          }
          if ((int)*(short *)(iVar14 + 0x67fe52) < *(int *)(&DAT_0067fe2c + iVar14) >> 0x10) {
            bVar2 = true;
            *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) - iVar9;
          }
          if (*(int *)(&DAT_0067fe2c + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe52)) {
            bVar2 = true;
            *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) + iVar9;
          }
          if (!bVar2) goto LAB_00453dcd;
        }
        _DAT_006dd174 = _DAT_006dd174 + 1;
      } while (_DAT_006dd174 < sVar3);
    }
    if (!bVar2) {
LAB_00453dcd:
      if (*(short *)(iVar14 + 0x67feb8) < 0x14) {
        *(short *)(iVar14 + 0x67feb8) = *(short *)(iVar14 + 0x67feb8) + sVar3;
        return;
      }
      iVar9 = *(int *)(*(short *)(iVar14 + 0x67fe56) * 0xe0 + 0x805e90);
      if ((iVar9 != 0) && (*(short *)(iVar14 + 0x67fed4) == 0)) {
        *(short *)(iVar14 + 0x67fed4) = (short)iVar9;
      }
      iVar9 = *(short *)(iVar14 + 0x67fe56) * 0xe0;
      *(undefined4 *)(iVar9 + 0x805e90) = 0;
      func_0x0041e900(*(undefined4 *)(&DAT_00805e08 + iVar9),*(undefined4 *)(&DAT_00805e0c + iVar9),
                      *(undefined4 *)(iVar9 + 0x805e10),*(undefined4 *)(iVar9 + 0x805e14));
      sStack_8 = -1;
      if (((((int)_DAT_008351d0 ^ param_1) & 7) == 0) && (sVar3 = 0, -1 < _DAT_0083a402)) {
        do {
          iVar9 = sVar3 * 0xe0;
          if (((((*(int *)(&DAT_00805df0 + iVar9) == (int)*(short *)(&DAT_0067fe10 + iVar14)) &&
                (*(int *)(&DAT_00805df8 + iVar9) != 0)) && (*(int *)(iVar9 + 0x805df4) == 4)) &&
              ((*(int *)(iVar9 + 0x805e58) != 1 && (*(int *)(iVar9 + 0x805e5c) == 0)))) &&
             (*(int *)(iVar9 + 0x805e90) + (int)_DAT_004bbde2 <= (int)_DAT_004bbfe6)) {
            sVar6 = 0;
            sStack_8 = sVar3;
            if (-1 < _DAT_006e5b38) {
              do {
                if ((int)sVar6 != param_1) {
                  iVar9 = sVar6 * 0x6d0;
                  if (((*(short *)(&DAT_0067fe12 + iVar9) == 0) ||
                      (*(short *)(&DAT_0067fe12 + iVar9) == 1)) &&
                     ((*(short *)(iVar9 + 0x67fe56) == sVar3 &&
                      (*(short *)(&DAT_0067fe10 + iVar9) == *(short *)(&DAT_0067fe10 + iVar14))))) {
                    sStack_8 = -1;
                    break;
                  }
                }
                sVar6 = sVar6 + 1;
              } while (sVar6 <= _DAT_006e5b38);
            }
            if (sStack_8 != -1) break;
          }
          sVar3 = sVar3 + 1;
        } while (sVar3 <= _DAT_0083a402);
      }
      if (-1 < sStack_8) {
        iVar13 = sStack_8 * 0xe0;
        iVar7 = CONCAT22((short)((uint)*(undefined4 *)(&DAT_00805e08 + iVar13) >> 0x10),
                         (short)*(undefined4 *)(&DAT_00805e08 + iVar13) << 5);
        iVar9 = iVar7 + 0x30;
        if (*(int *)(iVar13 + 0x805e00) == 1) {
          iVar9 = iVar7 + 0x58;
        }
        if (_DAT_004aee00 == 1) {
          func_0x00423710(param_1,0xd,CONCAT22(uStack_6,sStack_8),0xffffffff,iVar9,
                          CONCAT22((short)((uint)*(undefined4 *)(iVar13 + 0x805e14) >> 0x10),
                                   ((short)*(undefined4 *)(iVar13 + 0x805e14) +
                                   *(short *)(&DAT_00805e0c + iVar13)) * 0x20 + 0xf));
        }
        *(undefined2 *)(iVar14 + 0x67fe76) = 0;
        return;
      }
    }
    break;
  case 0xd:
    sVar6 = *(short *)(iVar14 + 0x67fe56);
    if (sVar6 == -1) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    if ((*(int *)(&DAT_00805df0 + sVar6 * 0xe0) == 0) ||
       (*(int *)(&DAT_00805df8 + sVar6 * 0xe0) == 0)) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    if (sVar3 == 1) {
      sVar4 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10);
      sVar3 = sVar4 - *(short *)(iVar14 + 0x67fe50);
      sVar10 = (short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
               *(short *)(iVar14 + 0x67fe52);
      if (sVar3 < 0) {
        sVar3 = -sVar3;
      }
      sVar15 = sVar10;
      if (sVar10 < 0) {
        sVar15 = -sVar10;
      }
      if ((sVar3 < 0x40) && (sVar15 < 0x40)) {
        uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) - sVar4,sVar10 * 2);
        sVar3 = (short)(uVar5 >> 8) >> 2;
        *(short *)(iVar14 + 0x67fe54) = sVar3;
        *(ushort *)(iVar14 + 0x67fe54) = sVar3 + 0x20U & 0x3f;
        *(undefined2 *)(iVar14 + 0x67fe72) = 0xe;
        *(undefined2 *)(iVar14 + 0x67feb8) = 0;
        return;
      }
      uVar1 = *(undefined2 *)(iVar14 + 0x67fe74);
      if (*(short *)(iVar14 + 0x67fe76) == 0) {
        *(undefined2 *)(iVar14 + 0x67fe76) = 1;
      }
      *(undefined2 *)(iVar14 + 0x67fe72) = *(undefined2 *)(iVar14 + 0x67fe76);
      *(undefined2 *)(iVar14 + 0x67fe74) = 0;
      *(undefined2 *)(iVar14 + 0x67fe56) = 0xffff;
      *(undefined2 *)(iVar14 + 0x67fea0) = 0;
      f_454d20(param_1);
      *(undefined2 *)(iVar14 + 0x67fe76) = *(undefined2 *)(iVar14 + 0x67fe72);
      *(undefined2 *)(iVar14 + 0x67fe72) = uVar12;
      *(undefined2 *)(iVar14 + 0x67fe74) = uVar1;
      *(short *)(iVar14 + 0x67fe56) = sVar6;
      return;
    }
    uVar8 = *(uint *)(iVar14 + 0x67fe48);
    if ((int)(uVar8 & 0xffff0000) < 0x60000) {
      *(uint *)(iVar14 + 0x67fe48) =
           (0xa00 - ((int)(uVar8 & 0xffff00ff) >> 8)) * (int)_DAT_006df0f8 + uVar8;
      *(undefined4 *)(iVar14 + 0x67fe3c) = 0;
      *(undefined4 *)(iVar14 + 0x67fe40) = 0;
      return;
    }
    _DAT_006dd174 = 0;
    if (0 < _DAT_006df0f8) {
      do {
        uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) -
                             (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10),
                             ((short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                             *(short *)(iVar14 + 0x67fe52)) * 2);
        sVar10 = _DAT_006df0f8;
        sVar4 = (short)(uVar5 >> 8) >> 2;
        *(short *)(iVar14 + 0x67fe54) = sVar4;
        sVar6 = _DAT_006dd174;
        iVar9 = *(int *)(iVar14 + 0x67fe44);
        sVar3 = (short)((uint)iVar9 >> 0x10);
        if ((int)sVar4 == iVar9 >> 0x10) {
LAB_004542b6:
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4ba288);
          *(undefined4 *)(iVar14 + 0x67fe3c) = *(undefined4 *)(sVar3 * 0x10 + 0x4b9e88);
        }
        else {
          sVar4 = ((sVar3 - sVar4) + 0x20U & 0x3f) * 4 + -0x80;
          if (sVar4 < 0) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + 0x8000;
          }
          if (0 < sVar4) {
            *(int *)(iVar14 + 0x67fe44) = *(int *)(iVar14 + 0x67fe44) + -0x8000;
          }
          uVar8 = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
          *(uint *)(iVar14 + 0x67fe44) = uVar8;
          sVar3 = (short)(uVar8 >> 0x10);
          if ((sVar4 < 9) && (-9 < sVar4)) goto LAB_004542b6;
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4b9e88);
          *(int *)(iVar14 + 0x67fe3c) = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
          iVar9 = *(int *)(sVar3 * 0x10 + 0x4ba288);
          iVar9 = (int)(iVar9 + (iVar9 >> 0x1f & 3U)) >> 2;
        }
        *(int *)(iVar14 + 0x67fe40) = -iVar9;
        *(int *)(&DAT_0067fe28 + iVar14) =
             *(int *)(&DAT_0067fe28 + iVar14) + *(int *)(iVar14 + 0x67fe3c);
        iVar9 = *(int *)(&DAT_0067fe2c + iVar14) + *(int *)(iVar14 + 0x67fe40);
        *(int *)(&DAT_0067fe2c + iVar14) = iVar9;
        if (*(short *)(iVar14 + 0x67fe56) == -1) {
          *(undefined2 *)(iVar14 + 0x67fe72) = 0;
          return;
        }
        sVar4 = (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10) -
                *(short *)(iVar14 + 0x67fe50);
        sVar3 = (short)((uint)iVar9 >> 0x10) - *(short *)(iVar14 + 0x67fe52);
        if (sVar4 < 0) {
          sVar4 = -sVar4;
        }
        if (sVar3 < 0) {
          sVar3 = -sVar3;
        }
        if ((sVar4 < 4) && (sVar3 < 4)) {
          *(undefined2 *)(iVar14 + 0x67fe54) = 0x1e;
          *(undefined2 *)(iVar14 + 0x67fe72) = 0xe;
          return;
        }
        _DAT_006dd174 = sVar6 + 1;
        if (sVar10 <= _DAT_006dd174) {
          return;
        }
      } while( true );
    }
    break;
  case 0xe:
    if (*(short *)(iVar14 + 0x67fe56) == -1) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    iVar9 = *(short *)(iVar14 + 0x67fe56) * 0xe0;
    if ((*(int *)(&DAT_00805df0 + iVar9) == 0) || (*(int *)(&DAT_00805df8 + iVar9) == 0)) {
      *(undefined2 *)(iVar14 + 0x67fe72) = 0;
      return;
    }
    _DAT_006dd174 = 0;
    sVar3 = _DAT_006df0f8;
    if (0 < _DAT_006df0f8) {
      do {
        bVar2 = false;
        iVar9 = *(int *)(iVar14 + 0x67fe44);
        if ((int)*(short *)(iVar14 + 0x67fe54) != iVar9 >> 0x10) {
          sVar6 = (((short)((uint)iVar9 >> 0x10) - *(short *)(iVar14 + 0x67fe54)) + 0x20U & 0x3f) *
                  4 + -0x80;
          if (sVar6 < 0) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + 0x8000;
            sVar6 = *(short *)(iVar14 + 0x67fe54);
            if (-1 < (short)((((short)((uint)(iVar9 + 0x8000) >> 0x10) - sVar6) + 0x20U & 0x3f) * 4
                            + -0x80)) {
LAB_0045447f:
              *(int *)(iVar14 + 0x67fe44) = (int)sVar6 << 0x10;
            }
          }
          else if (0 < sVar6) {
            *(int *)(iVar14 + 0x67fe44) = iVar9 + -0x8000;
            sVar6 = *(short *)(iVar14 + 0x67fe54);
            if ((short)((((short)((uint)(iVar9 + -0x8000) >> 0x10) - sVar6) + 0x20U & 0x3f) * 4 +
                       -0x80) < 1) goto LAB_0045447f;
          }
          bVar2 = true;
          *(uint *)(iVar14 + 0x67fe44) = *(uint *)(iVar14 + 0x67fe44) & 0x3ff000;
        }
        if (!bVar2) {
          uVar8 = *(uint *)(iVar14 + 0x67fe48);
          if (0x4000 < (int)uVar8) {
            bVar2 = true;
            *(uint *)(iVar14 + 0x67fe48) = (uVar8 - ((int)(uVar8 & 0xffff00ff) >> 8)) + -0x400;
          }
          iVar9 = 0x10000;
          if (*(short *)(&DAT_0067fe12 + iVar14) == 1) {
            iVar9 = 0xc000;
            uVar5 = FUN_00429c50(*(short *)(iVar14 + 0x67fe50) -
                                 (short)((uint)*(undefined4 *)(&DAT_0067fe28 + iVar14) >> 0x10),
                                 ((short)((uint)*(undefined4 *)(&DAT_0067fe2c + iVar14) >> 0x10) -
                                 *(short *)(iVar14 + 0x67fe52)) * 2);
            sVar3 = _DAT_006df0f8;
            sVar6 = (short)(uVar5 >> 8) >> 2;
            *(short *)(iVar14 + 0x67fe54) = sVar6;
            *(ushort *)(iVar14 + 0x67fe54) = sVar6 + 0x20U & 0x3f;
          }
          if ((int)*(short *)(iVar14 + 0x67fe50) < *(int *)(&DAT_0067fe28 + iVar14) >> 0x10) {
            bVar2 = true;
            *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) - iVar9;
          }
          if (*(int *)(&DAT_0067fe28 + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe50)) {
            bVar2 = true;
            *(int *)(&DAT_0067fe28 + iVar14) = *(int *)(&DAT_0067fe28 + iVar14) + iVar9;
          }
          if ((int)*(short *)(iVar14 + 0x67fe52) < *(int *)(&DAT_0067fe2c + iVar14) >> 0x10) {
            bVar2 = true;
            *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) - iVar9;
          }
          if (*(int *)(&DAT_0067fe2c + iVar14) >> 0x10 < (int)*(short *)(iVar14 + 0x67fe52)) {
            bVar2 = true;
            *(int *)(&DAT_0067fe2c + iVar14) = *(int *)(&DAT_0067fe2c + iVar14) + iVar9;
          }
          if (!bVar2) {
            sVar3 = *(short *)(iVar14 + 0x67fed4);
            *(undefined2 *)(iVar14 + 0x67fed4) = 0;
            *(undefined2 *)(iVar14 + 0x67fe72) = 0;
            *(undefined2 *)(iVar14 + 0x67fe76) = 0;
            iVar9 = *(short *)(iVar14 + 0x67fe56) * 0xe0;
            *(undefined2 *)(iVar14 + 0x67fe56) = 0xffff;
            *(int *)(iVar9 + 0x805e90) = *(int *)(iVar9 + 0x805e90) + (int)sVar3;
            *(undefined4 *)(iVar9 + 0x805e5c) = 0x78;
            return;
          }
        }
        _DAT_006dd174 = _DAT_006dd174 + 1;
        if (sVar3 <= _DAT_006dd174) {
          return;
        }
      } while( true );
    }
  }
  return;
LAB_00453293:
  sVar6 = sVar6 + 1;
  if (_DAT_0083a402 < sVar6) goto LAB_004532f9;
  goto LAB_00453201;
}



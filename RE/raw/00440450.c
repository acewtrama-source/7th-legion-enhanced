
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00440450(void)

{
  char cVar1;
  short sVar2;
  undefined2 extraout_AX;
  int iVar3;
  char *pcVar4;
  undefined2 uVar5;
  undefined2 extraout_var;
  uint uVar6;
  uint extraout_EDX;
  int iVar7;
  undefined4 unaff_EBP;
  uint uVar8;
  undefined2 uVar9;
  short sVar10;
  ushort uVar11;
  short sVar12;
  char *pcVar13;
  undefined4 *puVar14;
  time_t tVar15;
  longlong lVar16;
  undefined4 uVar17;
  char local_11c [25];
  undefined1 local_103;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  short local_a;
  short local_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uStack_4 = (undefined2)unaff_EBP;
  uStack_2 = (undefined2)((uint)unaff_EBP >> 0x10);
  if (DAT_00719fa4 == 1) {
    DAT_004aedfc = 0;
  }
  FUN_00435580();
  tVar15 = _time((time_t *)0x0);
  FUN_0049c530((int)tVar15);
  FUN_004752b0();
  DAT_009094b4 = 0;
  _DAT_009d6b68 = 0;
  FUN_00475740();
  FUN_00475700();
  FUN_00475730(5,0xf,0x140,0x73);
  FUN_00475730(0x1a9,0xf,0xb4,0x91);
  FUN_00475730(5,0x16d,0x19a,0x3f);
  FUN_00404f30();
  local_14 = 1;
  if (DAT_004aee00 == 1) {
    FUN_0040bec0();
  }
  else {
    DAT_004aee08 = 0xffffffff;
  }
  FUN_0040ba20(1);
  _strncpy(&DAT_004f7358 + (DAT_00507474 & 0x3f) * 0x400,s_GetPlayerList___004b8740,0x100);
  DAT_00507474 = DAT_00507474 + 1 & 0x3f;
  FUN_0040ba80();
  _strncpy(&DAT_004f7358 + (DAT_00507474 & 0x3f) * 0x400,s_After_GetPlayerList___004b8728,0x100);
  DAT_00507474 = DAT_00507474 + 1 & 0x3f;
  sVar10 = 0x94;
  uVar8 = 0;
  FUN_004758b0(0x3c6,4,0x1e,0x7e,200,0x10,&DAT_00865220);
  uVar11 = DAT_009e7600;
  if (0 < (short)DAT_009e7600) {
    do {
      sVar2 = (short)uVar8;
      local_10 = &DAT_009e6e80 + sVar2 * 0x20;
      iVar3 = sVar2 * 0x28;
      _strncpy(&DAT_004ddd68 + iVar3,local_10,0xb);
      (&DAT_004ddd71)[iVar3] = 0;
      FUN_004758b0(uVar8,0,0x1e,sVar10,200,0x10,&DAT_004ddd68 + iVar3);
      FUN_00475be0(uVar8,0);
      FUN_004758b0(uVar8 + 0x32,7,0xf0,sVar10,0x5e,0x10,&DAT_00865270);
      iVar3 = __strcmpi(local_10,&DAT_0090a290);
      if (iVar3 != 0) {
        FUN_00475be0(uVar8 + 0x32,0);
      }
      sVar10 = sVar10 + 0x16;
      uVar8 = (uint)(ushort)(sVar2 + 1U);
      uVar11 = DAT_009e7600;
    } while ((short)(sVar2 + 1U) < (short)DAT_009e7600);
  }
  for (; uVar8 = (uint)uVar11, (short)uVar11 < 6; uVar11 = uVar11 + 1) {
    FUN_004758b0(uVar8,7,0x1e,sVar10,200,0x10,&DAT_008652c0);
    if (DAT_00719fa4 == 0) {
      FUN_00475be0(uVar8,0);
    }
    if ((uVar11 == DAT_009e7600) && (DAT_00719fa4 == 1)) {
      FUN_00475cd0(uVar8,1);
      FUN_00475be0(uVar8,0);
    }
    FUN_004758b0(uVar8 + 0x32,7,0xf0,sVar10,0x5e,0x10,&DAT_00865310);
    FUN_00475be0(uVar8 + 0x32,0);
    sVar10 = sVar10 + 0x16;
  }
  uVar8 = 0;
  FUN_004758b0(199,4,0x140,0x7e,0x50,0x10,&DAT_00865360);
  FUN_004758b0(100,7,0x140,0x94,0xaa,0x15,&DAT_008653b0);
  FUN_004758b0(0x65,7,0x140,0xaa,0xaa,0x15,&DAT_00865400);
  FUN_004758b0(0x66,7,0x140,0xc0,0xaa,0x15,&DAT_00865450);
  FUN_004758b0(0x67,7,0x140,0xd6,0xaa,0x15,&DAT_008654a0);
  FUN_004758b0(0x68,7,0x140,0xf2,0xaa,0x15,&DAT_008654f0);
  if (DAT_004aee00 != 1) {
    FUN_00475be0(100,0);
    FUN_00475be0(0x65,0);
    FUN_00475be0(0x66,0);
    FUN_00475be0(0x67,0);
    FUN_00475be0(0x68,0);
  }
  DAT_009d5a90 = 0;
  DAT_009d5aec = 0;
  DAT_009d6330 = 0;
  DAT_009d5ae4 = 0;
  DAT_009d6b64 = 0;
  DAT_0092ab5c = 0;
  if (DAT_00719fa4 == 1) {
    FUN_00475be0(0x68,0);
  }
  FUN_00475cd0(100,1);
  FUN_004758b0(0x96,0,0x14,0x12d,200,0x15,&DAT_00a13600);
  if ((DAT_004aee00 == 1) || (FUN_00475be0(0x96,0), DAT_004aee00 == 1)) {
    FUN_004758b0(500,0,0xbc,0x196,0x50,0x10,&DAT_00865540);
  }
  pcVar13 = (char *)0x0;
  FUN_004758b0(600,0,0x174,0x196,0x50,0x10,&DAT_00865590);
  FUN_004758b0(999,5,10,0x153,0x1e4,0x10,&DAT_00865630);
  FUN_004758b0(0x3e5,5,10,0x16a,0x1e4,0x10,&DAT_004ae47c);
  FUN_00475be0(0x3e5,0);
  if (DAT_004aee00 != 1) {
    uVar8 = 0;
    do {
      local_18 = FUN_0040bf90();
      if (0 < local_18) {
        iVar3 = _strncmp(&DAT_009e77b0,s__Leave__004b8720,7);
        if (iVar3 == 0) {
          FUN_004757c0();
          return 1;
        }
        iVar3 = _strncmp(&DAT_009e77b0,&DAT_004b8718,4);
        if (iVar3 == 0) {
          _sscanf((char *)&DAT_009e77b4,s__d__d_004b8710,&local_8,&uStack_6);
          if (CONCAT11(uStack_6._1_1_,(undefined1)uStack_6) == 0x96) {
            local_14 = (int)local_8;
            FUN_00475dc0(0x96,&DAT_00a13500 + local_14 * 0x100);
          }
          else {
            FUN_00475cd0(CONCAT22(uStack_4,CONCAT11(uStack_6._1_1_,(undefined1)uStack_6)),
                         CONCAT13(uStack_6._1_1_,CONCAT12((undefined1)uStack_6,local_8)));
          }
        }
      }
      uVar11 = (short)pcVar13 + 1;
      pcVar13 = (char *)(uint)uVar11;
    } while ((short)uVar11 < 0x50);
  }
  do {
    do {
      local_1c = 0;
      local_a = 0;
      uVar8 = uVar8 & 0xffff0000;
      FUN_0040ba80();
      local_10 = (char *)0x0;
      if (0 < (short)DAT_009e7600) {
        do {
          sVar10 = (short)uVar8;
          pcVar13 = &DAT_009e6e80 + sVar10 * 0x20;
          iVar3 = sVar10 * 0x28;
          _strncpy(&DAT_004ddd68 + iVar3,pcVar13,0xb);
          (&DAT_004ddd71)[iVar3] = 0;
          FUN_00475dc0(uVar8,&DAT_004ddd68 + iVar3);
          FUN_00475be0(uVar8,0);
          iVar3 = __strcmpi(pcVar13,&DAT_0090a290);
          if (iVar3 != 0) {
            FUN_00475be0(sVar10 + 0x32,0);
          }
          iVar3 = __strcmpi(pcVar13,&DAT_0090a290);
          if (iVar3 == 0) {
            FUN_00475be0(sVar10 + 0x32,1);
          }
          uVar8 = CONCAT22((short)(uVar8 >> 0x10),sVar10 + 1);
          local_10 = (char *)((int)local_10 + 1);
        } while ((short)(sVar10 + 1) < (short)DAT_009e7600);
      }
      pcVar13 = (char *)CONCAT22((short)((uint)pcVar13 >> 0x10),DAT_009e7600);
      if ((short)DAT_009e7600 < 6) {
        uVar8 = 0;
        do {
          FUN_00475dc0(pcVar13,&DAT_00865680);
          uVar11 = (ushort)pcVar13;
          if (DAT_004aee00 == 1) {
            pcVar4 = pcVar13 + 0x32;
            FUN_00475be0(pcVar13,0);
            FUN_00475be0(pcVar4,0);
            if ((DAT_00719fa4 == 1) && (uVar11 == DAT_009e7600)) {
              FUN_00475be0(pcVar13,0);
LAB_00440b5b:
              FUN_00475be0(pcVar4,0);
            }
          }
          else if ((DAT_00719fa4 == 0) && (FUN_00475be0(pcVar13,0), DAT_00719fa4 == 0)) {
            pcVar4 = (char *)(uint)(ushort)(uVar11 + 0x32);
            goto LAB_00440b5b;
          }
          pcVar13 = (char *)CONCAT22((short)((uint)pcVar13 >> 0x10),uVar11 + 1);
        } while ((short)(uVar11 + 1) < 6);
      }
      if (local_10 == (char *)0x0) {
        FUN_00475be0(500,0);
      }
      if ((((int)local_10 < 2) || (DAT_004aee00 != 1)) || (DAT_00719fa4 == 1)) {
        uVar17 = 0;
      }
      else {
        uVar17 = 1;
      }
      FUN_00475be0(500,uVar17);
      if (DAT_00719fa4 == 1) {
        FUN_00475be0(500,1);
      }
      FUN_00476160(0xffffffff);
      local_10 = (char *)CONCAT22(0xffff,(undefined2)local_10);
      do {
        _rand();
        FUN_00494900();
        sVar10 = FUN_00476aa0();
        uVar8 = CONCAT22((short)(uVar8 >> 0x10),sVar10);
        if (sVar10 != 0) {
          if ((sVar10 == 2) && (DAT_00719fa4 == 0)) {
            puVar14 = &DAT_009e6400;
            for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar14 = 0;
              puVar14 = puVar14 + 1;
            }
            sVar2 = FUN_00476010(DAT_0059f890,(int)DAT_0059f890,0);
            _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar2);
            uVar6 = 0xffffffff;
            pcVar4 = (char *)&DAT_009e6400;
            do {
              pcVar13 = pcVar4;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar13 = pcVar4 + 1;
              cVar1 = *pcVar4;
              pcVar4 = pcVar13;
            } while (cVar1 != '\0');
            FUN_0040c170(~uVar6 + 4,0);
            local_10 = (char *)CONCAT22(0xffff,(undefined2)local_10);
          }
          if (sVar10 == 1) {
            if ((DAT_0059f890 == 999) && (DAT_00719fa4 == 0)) {
              puVar14 = &DAT_009e6400;
              for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar14 = 0;
                puVar14 = puVar14 + 1;
              }
              uVar17 = FUN_00475fc0(999,0);
              _sprintf((char *)&DAT_009e6400,s__msg__s_c_004b86f8,uVar17);
              pcVar4 = (char *)FUN_00475fc0(999,0);
              uVar6 = 0xffffffff;
              do {
                pcVar13 = pcVar4;
                if (uVar6 == 0) break;
                uVar6 = uVar6 - 1;
                pcVar13 = pcVar4 + 1;
                cVar1 = *pcVar4;
                pcVar4 = pcVar13;
              } while (cVar1 != '\0');
              FUN_0040c170(~uVar6 + 6);
              local_10 = (char *)CONCAT22(0xffff,(undefined2)local_10);
            }
            if (DAT_0059f890 == 0x96) {
              local_14 = local_14 + 1;
              if ((&DAT_00a13500)[local_14 * 0x100] == '@') {
                local_14 = 1;
              }
              FUN_00475dc0(0x96,&DAT_00a13500 + local_14 * 0x100);
              pcVar13 = (char *)&DAT_009e6400;
              for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
                pcVar13[0] = '\0';
                pcVar13[1] = '\0';
                pcVar13[2] = '\0';
                pcVar13[3] = '\0';
                pcVar13 = pcVar13 + 4;
              }
              _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,local_14,0x96,0);
              if (DAT_00719fa4 == 0) {
                uVar6 = 0xffffffff;
                pcVar4 = (char *)&DAT_009e6400;
                do {
                  pcVar13 = pcVar4;
                  if (uVar6 == 0) break;
                  uVar6 = uVar6 - 1;
                  pcVar13 = pcVar4 + 1;
                  cVar1 = *pcVar4;
                  pcVar4 = pcVar13;
                } while (cVar1 != '\0');
                FUN_0040c170(~uVar6 + 4,0);
              }
              local_10 = (char *)CONCAT22(0xffff,(undefined2)local_10);
            }
          }
          if (sVar10 == 1) {
            if (DAT_0059f890 == 600) {
              iVar3 = 5;
              uVar8 = 0;
              do {
                if ((DAT_004aee00 == 1) && (DAT_00719fa4 == 0)) {
                  pcVar13 = s__Leave__004b8720;
                }
                else {
                  pcVar13 = s__leave__004b86f0;
                }
                _sprintf((char *)&DAT_009e6400,pcVar13);
                FUN_0040c170(9,0);
                FUN_0040c170(9,0);
                FUN_0040c170(9,0);
                iVar3 = iVar3 + -1;
                pcVar13 = (char *)0x0;
              } while (iVar3 != 0);
            }
            if ((DAT_0059f890 == 500) || (DAT_0059f890 == 600)) {
              local_10 = (char *)CONCAT22(DAT_0059f890,(undefined2)local_10);
            }
          }
        }
        if (DAT_00719fa4 != 1) {
          uVar8 = 0;
          pcVar13 = (char *)0xffffffff;
          do {
            _strncpy(&DAT_004f7358 + (DAT_00507474 & 0x3f) * 0x400,s_GetAMessage___004b86e0,0x100);
            DAT_00507474 = DAT_00507474 + 1 & 0x3f;
            local_18 = FUN_0040bf90();
            _strncpy(&DAT_004f7358 + (DAT_00507474 & 0x3f) * 0x400,s_After_GetAMessage___004b86cc,
                     0x100);
            DAT_00507474 = DAT_00507474 + 1 & 0x3f;
            if (local_18 < 1) {
LAB_00440ff5:
              if (local_10._2_2_ != -1) break;
            }
            else {
              iVar3 = _strncmp(&DAT_009e77b0,s__leave__004b86f0,7);
              if (iVar3 == 0) {
                Sleep(10);
                local_10 = (char *)CONCAT22(700,(undefined2)local_10);
              }
              iVar3 = _strncmp(&DAT_009e77b0,s__Leave__004b8720,7);
              if (iVar3 == 0) {
                local_10 = (char *)CONCAT22(600,(undefined2)local_10);
                break;
              }
              iVar3 = _strncmp(&DAT_009e77b0,&DAT_004b8718,4);
              if (iVar3 == 0) {
                _sscanf((char *)&DAT_009e77b4,s__d__d_004b8710,&local_8,&uStack_6);
                if (CONCAT11(uStack_6._1_1_,(undefined1)uStack_6) == 0x96) {
                  local_14 = (int)local_8;
                  FUN_00475dc0(0x96,&DAT_00a13500 + local_14 * 0x100);
                }
                else {
                  FUN_00475cd0(CONCAT22(uStack_4,CONCAT11(uStack_6._1_1_,(undefined1)uStack_6)),
                               CONCAT13(uStack_6._1_1_,CONCAT12((undefined1)uStack_6,local_8)));
                }
              }
              else {
                iVar3 = _strncmp(&DAT_009e77b0,s__msg__004b86c4,5);
                if (iVar3 != 0) {
                  iVar3 = _strncmp(&DAT_009e77b0,s_begin_004b86b4,5);
                  if (iVar3 != 0) goto LAB_00440ff5;
                  local_10 = (char *)CONCAT22(500,(undefined2)local_10);
                  break;
                }
                sVar10 = 0;
                local_8 = -1;
                do {
                  sVar2 = sVar10;
                  if (sVar10 == local_18) break;
                  sVar10 = sVar10 + 1;
                  sVar2 = local_8;
                } while (sVar10 < 8);
                local_8 = sVar2;
                if (local_8 != -1) {
                  _sprintf(local_11c,s__s___s_004b86bc,&DAT_009e6e60 + local_8 * 0x20,0x9e77b5);
                  local_103 = 0;
                  FUN_00475dc0(0x3e5,local_11c);
                }
              }
            }
            uVar8 = uVar8 + 1;
          } while ((int)uVar8 < 0x14);
        }
        if (((local_10._2_2_ == 700) || (local_10._2_2_ == 600)) || (local_10._2_2_ == 500)) break;
        local_a = local_a + 1;
        if (local_a < 0) {
          local_a = 0;
        }
        if (((0xf < local_a) && (local_a = 0, DAT_004aee00 == 1)) && (DAT_00719fa4 == 0)) {
          uVar8 = uVar8 & 0xffff0000;
          if (0 < (short)DAT_009e7600) {
            do {
              puVar14 = &DAT_009e6400;
              for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar14 = 0;
                puVar14 = puVar14 + 1;
              }
              sVar2 = (short)uVar8;
              sVar10 = FUN_00476010(CONCAT22((short)((uint)(sVar2 + 0x32) >> 0x10),sVar2 + 0x32),
                                    sVar2 + 0x32,0);
              _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar10);
              uVar6 = 0xffffffff;
              pcVar13 = (char *)&DAT_009e6400;
              do {
                if (uVar6 == 0) break;
                uVar6 = uVar6 - 1;
                cVar1 = *pcVar13;
                pcVar13 = pcVar13 + 1;
              } while (cVar1 != '\0');
              uVar8 = CONCAT22((short)(uVar8 >> 0x10),sVar2 + 1);
              FUN_0040c170(~uVar6 + 4,0);
            } while ((short)(sVar2 + 1) < (short)DAT_009e7600);
          }
          uVar17 = CONCAT22((short)(uVar8 >> 0x10),DAT_009e7600);
          uVar11 = DAT_009e7600;
          while (uVar5 = (undefined2)((uint)uVar17 >> 0x10), (short)uVar11 < 6) {
            puVar14 = &DAT_009e6400;
            for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar14 = 0;
              puVar14 = puVar14 + 1;
            }
            sVar2 = (short)uVar17;
            sVar10 = FUN_00476010(uVar17,(int)sVar2,0);
            _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar10);
            uVar8 = 0xffffffff;
            pcVar13 = (char *)&DAT_009e6400;
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar13 + 1;
            } while (cVar1 != '\0');
            FUN_0040c170(~uVar8 + 4,0);
            puVar14 = &DAT_009e6400;
            for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar14 = 0;
              puVar14 = puVar14 + 1;
            }
            sVar10 = FUN_00476010(sVar2 + 0x32,sVar2 + 0x32,0);
            _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar10);
            uVar8 = 0xffffffff;
            pcVar13 = (char *)&DAT_009e6400;
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar13 + 1;
            } while (cVar1 != '\0');
            uVar11 = sVar2 + 1;
            uVar17 = CONCAT22(uVar5,uVar11);
            FUN_0040c170(~uVar8 + 4,0);
          }
          uVar8 = CONCAT22(uVar5,100);
          do {
            puVar14 = &DAT_009e6400;
            for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar14 = 0;
              puVar14 = puVar14 + 1;
            }
            sVar10 = FUN_00476010(uVar8,(int)(short)uVar8,0);
            _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar10);
            uVar6 = 0xffffffff;
            pcVar13 = (char *)&DAT_009e6400;
            do {
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar13 + 1;
            } while (cVar1 != '\0');
            sVar10 = (short)uVar8 + 1;
            uVar8 = CONCAT22((short)(uVar8 >> 0x10),sVar10);
            FUN_0040c170(~uVar6 + 4,0);
          } while (sVar10 < 0x69);
          puVar14 = &DAT_009e6400;
          for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar14 = 0;
            puVar14 = puVar14 + 1;
          }
          _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,local_14,0x96,0);
          uVar6 = 0xffffffff;
          pcVar4 = (char *)&DAT_009e6400;
          do {
            pcVar13 = pcVar4;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar13 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar13;
          } while (cVar1 != '\0');
          FUN_0040c170(~uVar6 + 4,0);
        }
        local_1c = local_1c + 1;
        if (0x31 < local_1c) {
          local_1c = 0;
          local_10 = (char *)CONCAT22(10000,(undefined2)local_10);
        }
      } while (local_10._2_2_ == -1);
    } while ((local_10._2_2_ == 10000) || (local_10._2_2_ == 700));
    if (local_10._2_2_ == 600) {
      sVar10 = 10;
      do {
        FUN_00494900();
        if ((DAT_004aee00 == 1) && (DAT_00719fa4 == 0)) {
          pcVar13 = s__Leave__004b8720;
        }
        else {
          pcVar13 = s__leave__004b86f0;
        }
        _sprintf((char *)&DAT_009e6400,pcVar13);
        FUN_0040c170(9,0);
        sVar10 = sVar10 + -1;
      } while (sVar10 != 0);
      FUN_00475700();
      FUN_0040b8d0();
      FUN_004757c0();
      return 1;
    }
  } while (local_10._2_2_ != 500);
  FUN_00475700();
  lVar16 = (ulonglong)extraout_EDX << 0x20;
  if (DAT_004b95f4 != 0) {
    lVar16 = FUN_0046f720(DAT_004b95f4,0,0x40,22000,0);
  }
  iVar3 = (int)lVar16;
  uVar6 = (uint)((ulonglong)lVar16 >> 0x20) & 0xffff0000;
  DAT_009d6b60 = 0;
  uVar8 = CONCAT22((short)(uVar8 >> 0x10),DAT_009e7600);
  _DAT_0090a268 = 6;
  do {
    sVar10 = (short)uVar6;
    if (sVar10 < (short)DAT_009e7600) {
      iVar3 = (int)sVar10;
      DAT_009d6b60 = DAT_009d6b60 + 1;
      if ((&DAT_009e7610)[iVar3] == DAT_004aedfc) {
        iVar3 = uVar6 + 1;
        DAT_009094b4 = (short)iVar3;
      }
    }
    uVar6 = CONCAT22((short)(uVar6 >> 0x10),sVar10 + 1);
  } while ((short)(sVar10 + 1) < 6);
  sVar10 = 0;
  uStack_6._0_1_ = 0;
  uStack_6._1_1_ = 0;
  if ((DAT_004aee00 == 1) && (iVar3 = DAT_00719fa4, DAT_00719fa4 == 0)) {
    if (0 < (short)DAT_009e7600) {
      do {
        puVar14 = &DAT_009e6400;
        for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar14 = 0;
          puVar14 = puVar14 + 1;
        }
        sVar2 = FUN_00476010(CONCAT22((short)((uint)(sVar10 + 0x32) >> 0x10),sVar10 + 0x32),
                             sVar10 + 0x32,0);
        _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar2);
        uVar6 = 0xffffffff;
        pcVar13 = (char *)&DAT_009e6400;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
        } while (cVar1 != '\0');
        sVar10 = sVar10 + 1;
        FUN_0040c170(~uVar6 + 4,0);
        uVar8 = CONCAT22((short)(uVar8 >> 0x10),DAT_009e7600);
      } while (sVar10 < (short)DAT_009e7600);
    }
    sVar10 = (short)uVar8;
    while (uVar5 = (undefined2)(uVar8 >> 0x10), sVar10 < 6) {
      puVar14 = &DAT_009e6400;
      for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      sVar10 = (short)uVar8;
      sVar2 = FUN_00476010(uVar8,(int)sVar10,0);
      _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar2);
      uVar8 = 0xffffffff;
      pcVar13 = (char *)&DAT_009e6400;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != '\0');
      FUN_0040c170(~uVar8 + 4,0);
      puVar14 = &DAT_009e6400;
      for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      sVar2 = FUN_00476010(sVar10 + 0x32,sVar10 + 0x32,0);
      _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar2);
      uVar6 = 0xffffffff;
      pcVar13 = (char *)&DAT_009e6400;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != '\0');
      sVar10 = sVar10 + 1;
      uVar8 = CONCAT22(uVar5,sVar10);
      FUN_0040c170(~uVar6 + 4,0);
    }
    uVar8 = CONCAT22(uVar5,100);
    do {
      puVar14 = &DAT_009e6400;
      for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      sVar10 = FUN_00476010(uVar8,(int)(short)uVar8,0);
      _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,(int)sVar10);
      uVar6 = 0xffffffff;
      pcVar13 = (char *)&DAT_009e6400;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != '\0');
      sVar10 = (short)uVar8 + 1;
      uVar8 = CONCAT22((short)(uVar8 >> 0x10),sVar10);
      FUN_0040c170(~uVar6 + 4,0);
    } while (sVar10 < 0x69);
    puVar14 = &DAT_009e6400;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    _sprintf((char *)&DAT_009e6400,s__gv__d__d_c_004b8704,local_14,0x96,0);
    uVar6 = 0xffffffff;
    pcVar13 = (char *)&DAT_009e6400;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    iVar3 = FUN_0040c170(~uVar6 + 4,0);
  }
  uVar5 = (undefined2)((uint)iVar3 >> 0x10);
  uVar8 = uVar8 & 0xffff0000;
  DAT_008574f8 = (undefined2)local_14;
  do {
    sVar10 = (short)uVar8;
    FUN_00476010(CONCAT22(uVar5,sVar10 + 0x32));
    uVar9 = (undefined2)(uVar8 >> 0x10);
    uVar8 = CONCAT22(uVar9,sVar10 + 1);
    *(undefined2 *)((int)&DAT_006df140 + sVar10 * 2 + 2) = extraout_AX;
    uVar5 = extraout_var;
  } while ((short)(sVar10 + 1) < 6);
  local_10 = (char *)0x0;
  uVar17 = CONCAT22(uVar9,DAT_009e7600);
  DAT_005474b4 = *(undefined2 *)((int)&DAT_006df140 + DAT_009094b4 * 2);
  uVar11 = DAT_009e7600;
  while ((short)uVar11 < 6) {
    sVar10 = FUN_00476010(uVar17);
    if (sVar10 == 1) {
      local_10 = (char *)((int)local_10 + 1);
    }
    uVar11 = (short)uVar17 + 1;
    uVar17 = CONCAT22((short)((uint)uVar17 >> 0x10),uVar11);
  }
  sVar10 = FUN_00476010(100);
  DAT_009d6b64 = (int)sVar10;
  sVar10 = FUN_00476010(0x65);
  DAT_009d5aec = (int)sVar10;
  sVar10 = FUN_00476010(0x66);
  DAT_009d6330 = (int)sVar10;
  sVar10 = FUN_00476010(0x67);
  DAT_009d5ae4 = (int)sVar10;
  sVar10 = FUN_00476010(0x68);
  DAT_0092ab5c = (int)sVar10;
  if (DAT_004aee00 == 0) {
    sVar2 = -1;
    sVar10 = 0;
    uStack_6 = 0;
    do {
      if (0x1c20 < (short)uStack_6) {
        FUN_004757c0();
        return 1;
      }
      sVar10 = sVar10 + 1;
      FUN_00494900();
      uStack_6 = uStack_6 + 1;
      if (5 < sVar10) {
        sVar10 = 0;
        DAT_009e6400._0_1_ = s_waiting_004b86ac[0];
        DAT_009e6400._1_1_ = s_waiting_004b86ac[1];
        DAT_009e6400._2_1_ = s_waiting_004b86ac[2];
        DAT_009e6400._3_1_ = s_waiting_004b86ac[3];
        DAT_009e6404._0_1_ = s_waiting_004b86ac[4];
        DAT_009e6404._1_1_ = s_waiting_004b86ac[5];
        DAT_009e6404._2_1_ = s_waiting_004b86ac[6];
        DAT_009e6404._3_1_ = s_waiting_004b86ac[7];
        FUN_0040c170(8,0);
      }
      local_18 = FUN_0040bf90();
      if (0 < local_18) {
        iVar3 = _strncmp(&DAT_009e77b0,s_start__004b86a4,6);
        if (iVar3 == 0) {
          sVar2 = 1;
        }
      }
    } while (sVar2 == -1);
    FUN_00477b50(s_Got_Start__004b8698,0x1b8);
  }
  else if (DAT_00719fa4 == 0) {
    sVar2 = 0;
    sVar10 = 0;
    do {
      iVar3 = (int)sVar10;
      sVar10 = sVar10 + 1;
      (&DAT_009e8630)[iVar3 * 6] = 0;
    } while (sVar10 < 6);
    uStack_6 = 0;
    if (DAT_00719fa4 == 1) {
      sVar2 = 7;
    }
    if ((int)sVar2 < DAT_009d6b60 + -1) {
      do {
        if (0x1c20 < (short)uStack_6) {
          FUN_004757c0();
          return 1;
        }
        FUN_00494900();
        uStack_6 = uStack_6 + 1;
        if ((uStack_6 & 3) == 0) {
          DAT_009e6400._0_1_ = s_begin_004b86b4[0];
          DAT_009e6400._1_1_ = s_begin_004b86b4[1];
          DAT_009e6400._2_1_ = s_begin_004b86b4[2];
          DAT_009e6400._3_1_ = s_begin_004b86b4[3];
          DAT_009e6404 = CONCAT22(DAT_009e6404._2_2_,s_begin_004b86b4._4_2_);
          FUN_0040c170(6,0);
        }
        local_18 = FUN_0040bf90();
        if (0 < local_18) {
          iVar3 = _strncmp(&DAT_009e77b0,s_waiting_004b86ac,6);
          if (iVar3 == 0) {
            sVar10 = 0;
            FUN_00494910(0,0x3f,0,0x3f);
            sVar12 = 200;
            FUN_00477b50(s_got_waiting____004b8688,0x1b8);
            do {
              iVar3 = (int)sVar10;
              if ((local_18 == iVar3) && ((&DAT_009e8630)[iVar3 * 6] == '\0')) {
                sVar2 = sVar2 + 1;
                (&DAT_009e8630)[iVar3 * 6] = 1;
                FUN_00477b50(s_new_player___004b8678,sVar12);
              }
              sVar12 = sVar12 + 0x12;
              sVar10 = sVar10 + 1;
            } while (sVar10 < 6);
          }
        }
      } while ((int)sVar2 < DAT_009d6b60 + -1);
    }
    uStack_6 = 0;
    do {
      FUN_00494900();
      uStack_6 = uStack_6 + 1;
      DAT_009e6400._0_1_ = s_start__004b86a4[0];
      DAT_009e6400._1_1_ = s_start__004b86a4[1];
      DAT_009e6400._2_1_ = s_start__004b86a4[2];
      DAT_009e6400._3_1_ = s_start__004b86a4[3];
      DAT_009e6404._0_3_ = CONCAT12(s_start__004b86a4[6],s_start__004b86a4._4_2_);
      FUN_0040c170(8,0);
      FUN_00494900();
      uStack_6 = uStack_6 + 1;
      DAT_009e6400._0_1_ = s_start__004b86a4[0];
      DAT_009e6400._1_1_ = s_start__004b86a4[1];
      DAT_009e6400._2_1_ = s_start__004b86a4[2];
      DAT_009e6400._3_1_ = s_start__004b86a4[3];
      DAT_009e6404._0_3_ = CONCAT12(s_start__004b86a4[6],s_start__004b86a4._4_2_);
      FUN_0040c170(8,0);
      FUN_00494900();
      uStack_6 = uStack_6 + 1;
      DAT_009e6400._0_1_ = s_start__004b86a4[0];
      DAT_009e6400._1_1_ = s_start__004b86a4[1];
      DAT_009e6400._2_1_ = s_start__004b86a4[2];
      DAT_009e6400._3_1_ = s_start__004b86a4[3];
      DAT_009e6404._0_3_ = CONCAT12(s_start__004b86a4[6],s_start__004b86a4._4_2_);
      FUN_0040c170(8,0);
      FUN_00494900();
      uStack_6 = uStack_6 + 1;
      DAT_009e6400._0_1_ = s_start__004b86a4[0];
      DAT_009e6400._1_1_ = s_start__004b86a4[1];
      DAT_009e6400._2_1_ = s_start__004b86a4[2];
      DAT_009e6400._3_1_ = s_start__004b86a4[3];
      DAT_009e6404._0_3_ = CONCAT12(s_start__004b86a4[6],s_start__004b86a4._4_2_);
      FUN_0040c170(8,0);
      uStack_6 = uStack_6 + 1;
    } while ((short)uStack_6 < 10);
  }
  sVar10 = DAT_009094b4;
  DAT_004e7350 = DAT_009d6b60;
  DAT_00803c40 = DAT_009d6b60;
  if (0 < (int)local_10) {
    DAT_009d5a90 = 1;
  }
  if ((DAT_009d5a90 == 1) && (DAT_009d6b60 < 6)) {
    DAT_009d5a90 = 1;
    _DAT_0090a268 = (short)local_10 + DAT_009d6b60;
  }
  else {
    DAT_009d5a90 = 0;
    _DAT_0090a268 = DAT_009d6b60;
  }
  sVar2 = 1;
  _DAT_009e8064 = DAT_004aedfc;
  DAT_00668ccc = DAT_009094b4;
  DAT_00507358 = _DAT_0090a268;
  DAT_00834f88 = _DAT_0090a268;
  do {
    iVar7 = (int)sVar2;
    sVar2 = sVar2 + 1;
    iVar3 = iVar7 * 6;
    uVar17 = *(undefined4 *)(&DAT_009e760c + iVar7 * 4);
    (&DAT_009e8630)[iVar3] = (char)uVar17;
    *(char *)(iVar3 + 0x9e8631) = (char)((uint)uVar17 >> 8);
    *(char *)(iVar3 + 0x9e8632) = (char)((uint)uVar17 >> 0x10);
    *(char *)(iVar3 + 0x9e8633) = (char)((uint)uVar17 >> 0x18);
  } while (sVar2 < 7);
  _sprintf(local_11c,s_humns__d__plyrs__d__pnum__d__004b8658,(int)DAT_009d6b60,(int)_DAT_0090a268,
           (int)sVar10);
  FUN_00477b50(local_11c,0x1cb);
  FUN_004757c0();
  FUN_0040ba20(0);
  return 0;
}



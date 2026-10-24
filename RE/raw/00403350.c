
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403350(short param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  UINT UVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  UINT UVar10;
  undefined4 uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  byte bVar16;
  byte *pbVar17;
  undefined2 extraout_var;
  undefined4 uVar18;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  short sVar19;
  ushort *puVar20;
  undefined2 uVar21;
  int iVar22;
  short sVar23;
  short sVar24;
  char *pcVar25;
  undefined4 *puVar26;
  bool bVar27;
  char acStackY_81e8 [188];
  char acStackY_812c [40];
  char acStackY_8104 [32472];
  short local_202;
  short local_200;
  short sStack_1fe;
  ushort local_1fc;
  ushort uStack_1fa;
  undefined4 local_1f8;
  uint local_1f4;
  int local_1f0;
  int local_1ec;
  char local_1e8 [36];
  UINT UStack_1c4;
  int local_1c0 [8];
  char local_1a0 [80];
  byte *local_150 [8];
  int local_130;
  char local_12c [40];
  undefined4 local_104 [65];
  
  DAT_0071667c = 0;
  local_1ec = FUN_0040ca00(3);
  local_1ec = local_1ec + 3;
  local_130 = FUN_0040ca00(3);
  local_130 = local_130 + 1;
  DAT_0083e4d0 = DAT_0092ab5c;
  GetCurrentDirectoryA(0x3c,s_1234567890123456789jjjjj56789012_004ae884);
  if ((s_1234567890123456789jjjjj56789012_004ae884[2] == '\\') &&
     (s_1234567890123456789jjjjj56789012_004ae884[3] == '\0')) {
    s_1234567890123456789jjjjj56789012_004ae884[2] = '\0';
  }
  _sprintf(s_123456789012345678901234567lllll_004ae804,s__s_data_Missions_ini_004ae574,
           s_1234567890123456789jjjjj56789012_004ae884);
  if (DAT_004b9608 == 1) {
    _sprintf(s_123456789012345678901234567lllll_004ae804,s__s_data_jivmis_ini_004ae560,
             s_1234567890123456789jjjjj56789012_004ae884);
  }
  if (DAT_004b9608 == 2) {
    _sprintf(s_123456789012345678901234567lllll_004ae804,s__s_data_fremis_ini_004ae54c,
             s_1234567890123456789jjjjj56789012_004ae884);
  }
  if (DAT_004b9608 == 3) {
    _sprintf(s_123456789012345678901234567lllll_004ae804,s__s_data_spmmis_ini_004ae538,
             s_1234567890123456789jjjjj56789012_004ae884);
  }
  bVar16 = 0x42;
  if (DAT_005474b4 == 0) {
    bVar16 = 0x47;
  }
  if ((1 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    bVar16 = 0x4d;
  }
  sVar23 = 0;
  _sprintf(local_1a0,s__cMission__d_004ae528,(uint)bVar16,(int)param_1);
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,&DAT_004ae524,0,s_123456789012345678901234567lllll_004ae804);
  DAT_0050747c = (short)UVar4;
  _DAT_006cdf10 = (short)UVar4;
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_Difficulty_004ae518,9,s_123456789012345678901234567lllll_004ae804);
  DAT_00507484 = (short)UVar4;
  _DAT_008046ec = (short)UVar4;
  do {
    iVar5 = (int)sVar23;
    sVar23 = sVar23 + 1;
    (&DAT_0083a350)[iVar5] = 0;
    *(undefined2 *)(&DAT_0070db80 + iVar5 * 2) = 0;
  } while (sVar23 < 0x50);
  sVar23 = 0;
  GetPrivateProfileStringA
            (local_1a0,s_BAvail_004ae7e8,s_0000000000000000_004ae7f0,(LPSTR)local_104,0x100,
             s_123456789012345678901234567lllll_004ae804);
  cVar1 = (char)local_104[0];
  while (cVar1 != '\0') {
    if (*(char *)((int)local_104 + (int)sVar23) != '0') {
      *(undefined2 *)(&DAT_0070db80 + sVar23 * 2) = 1;
    }
    sVar23 = sVar23 + 1;
    cVar1 = *(char *)((int)local_104 + (int)sVar23);
  }
  sVar23 = 0;
  GetPrivateProfileStringA
            (local_1a0,s_VAvail_004ae7e0,s_0000000000000000_004ae7f0,(LPSTR)local_104,0x100,
             s_123456789012345678901234567lllll_004ae804);
  cVar1 = (char)local_104[0];
  while (cVar1 != '\0') {
    if (*(char *)((int)local_104 + (int)sVar23) != '0') {
      (&DAT_0083a350)[sVar23] = 1;
    }
    sVar23 = sVar23 + 1;
    cVar1 = *(char *)((int)local_104 + (int)sVar23);
  }
  DAT_00a23500 = GetPrivateProfileIntA
                           (local_1a0,s_TechLevel_004ae7d4,999,
                            s_123456789012345678901234567lllll_004ae804);
  if ((1 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    if (DAT_009d6330 == 0) {
      DAT_00a23500 = 9;
    }
    if (DAT_009d6330 == 1) {
      DAT_00a23500 = 6;
    }
    if (DAT_009d6330 == 2) {
      DAT_00a23500 = 4;
    }
  }
  if (DAT_0092ab5c == 2) {
    DAT_00a23500 = 0;
  }
  if (DAT_00a23500 != 999) {
    pbVar17 = &DAT_004addc0 + DAT_00a23500;
    puVar6 = (ushort *)&DAT_0070db80;
    do {
      bVar16 = *pbVar17;
      pbVar17 = pbVar17 + 10;
      puVar20 = puVar6 + 1;
      *puVar6 = (ushort)bVar16;
      puVar6 = puVar20;
    } while (puVar20 < (ushort *)0x70dbad);
    pbVar17 = &DAT_004ae0e0 + DAT_00a23500;
    puVar6 = &DAT_0083a350;
    do {
      bVar16 = *pbVar17;
      pbVar17 = pbVar17 + 10;
      puVar20 = puVar6 + 1;
      *puVar6 = (ushort)bVar16;
      puVar6 = puVar20;
    } while (puVar20 < (ushort *)0x83a3a7);
  }
  DAT_00835250 = GetPrivateProfileIntA
                           (local_1a0,s_HowToWin_004ae7c8,3,
                            s_123456789012345678901234567lllll_004ae804);
  DAT_0071a168 = GetPrivateProfileIntA
                           (local_1a0,s_HowToWinData1_004ae7b8,0,
                            s_123456789012345678901234567lllll_004ae804);
  _DAT_0071b328 =
       GetPrivateProfileIntA
                 (local_1a0,s_HowToWinData2_004ae7a8,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0071b324 =
       GetPrivateProfileIntA
                 (local_1a0,s_HowToWinData3_004ae798,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0071b32c =
       GetPrivateProfileIntA
                 (local_1a0,s_HowToWinData4_004ae788,0,s_123456789012345678901234567lllll_004ae804);
  DAT_0070d880 = GetPrivateProfileIntA
                           (local_1a0,s_TriggerType1_004ae778,0,
                            s_123456789012345678901234567lllll_004ae804);
  DAT_0070d884 = GetPrivateProfileIntA
                           (local_1a0,s_TriggerType2_004ae768,0,
                            s_123456789012345678901234567lllll_004ae804);
  _DAT_0070d888 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerType3_004ae758,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_008040c0 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerVal1_004ae74c,0,s_123456789012345678901234567lllll_004ae804);
  DAT_008040c4 = GetPrivateProfileIntA
                           (local_1a0,s_TriggerVal2_004ae740,0,
                            s_123456789012345678901234567lllll_004ae804);
  _DAT_008040c8 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerVal3_004ae734,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0070d830 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerEffect1_004ae724,0,s_123456789012345678901234567lllll_004ae804)
  ;
  DAT_0070d834 = GetPrivateProfileIntA
                           (local_1a0,s_TriggerEffect2_004ae714,0,
                            s_123456789012345678901234567lllll_004ae804);
  _DAT_0070d838 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerEffect3_004ae704,0,s_123456789012345678901234567lllll_004ae804)
  ;
  _DAT_0067fdb0 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerData1_004ae6f4,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0067fdb4 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerData2_004ae6e4,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0067fdb8 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerData3_004ae6d4,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0066cd20 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerTime1_004ae6c4,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0066cd24 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerTime2_004ae6b4,0,s_123456789012345678901234567lllll_004ae804);
  _DAT_0066cd28 =
       GetPrivateProfileIntA
                 (local_1a0,s_TriggerTime3_004ae6a4,0,s_123456789012345678901234567lllll_004ae804);
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_StartCash_004ae698,25000,
                     s_123456789012345678901234567lllll_004ae804);
  if ((1 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    if (DAT_009d5ae4 == 0) {
      UVar4 = 15000;
    }
    if (DAT_009d5ae4 == 1) {
      UVar4 = 30000;
    }
    if (DAT_009d5ae4 == 2) {
      UVar4 = 50000;
    }
    if (DAT_009d5ae4 == 3) {
      UVar4 = 75000;
    }
  }
  if (DAT_00a23500 == 0) {
    UVar4 = 0;
  }
  sVar23 = 0;
  do {
    iVar5 = (int)sVar23;
    sVar23 = sVar23 + 1;
    DAT_006ccad8 = UVar4;
    *(UINT *)(&DAT_00834a00 + iVar5 * 4) = UVar4;
  } while (sVar23 < 8);
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_AIXtraCash_004ae68c,0,s_123456789012345678901234567lllll_004ae804);
  local_1f8._0_2_ = (ushort)UVar4;
  local_1f8._2_2_ = (short)(UVar4 >> 0x10);
  sVar23 = DAT_00803c40;
  if (1 < DAT_00803c40) {
    local_1f8._0_2_ = 0;
    local_1f8._2_2_ = 0;
  }
  while (sVar23 = sVar23 + 1, sVar23 < 8) {
    *(int *)(&DAT_00834a00 + sVar23 * 4) =
         *(int *)(&DAT_00834a00 + sVar23 * 4) + CONCAT22(local_1f8._2_2_,(ushort)local_1f8);
  }
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_AICheatCount_004ae67c,0,s_123456789012345678901234567lllll_004ae804
                    );
  sVar24 = DAT_00803c40;
  local_1f8._0_2_ = (ushort)UVar4;
  local_1f8._2_2_ = (short)(UVar4 >> 0x10);
  sVar23 = DAT_00803c40 + 1;
  if (sVar23 < 8) {
    do {
      (&DAT_007533e0)[sVar23] = UVar4 * 0x3c;
      if (1 < sVar24) {
        (&DAT_007533e0)[sVar23] = 0;
      }
      sVar23 = sVar23 + 1;
    } while (sVar23 < 8);
  }
  if ((sVar24 == 1) && (DAT_00719fa4 == 0)) {
    uVar7 = _rand();
    local_1f8 = (uVar7 & 3) + 1;
    _sprintf((char *)local_104,s_StartX_d_004ae670,local_1f8);
    UVar8 = GetPrivateProfileIntA
                      (local_1a0,(LPCSTR)local_104,0x20,s_123456789012345678901234567lllll_004ae804)
    ;
    _sprintf((char *)local_104,s_StartY_d_004ae664,local_1f8);
    UVar9 = GetPrivateProfileIntA
                      (local_1a0,(LPCSTR)local_104,0x20,s_123456789012345678901234567lllll_004ae804)
    ;
    UVar4 = 1;
    do {
      local_1f8 = UVar4;
      _sprintf((char *)local_104,s_StartX_d_004ae670,UVar4);
      UVar4 = GetPrivateProfileIntA
                        (local_1a0,(LPCSTR)local_104,0x20,
                         s_123456789012345678901234567lllll_004ae804);
      (&DAT_006dd210)[local_1f8] = UVar4;
      _sprintf((char *)local_104,s_StartY_d_004ae664,local_1f8);
      UVar10 = GetPrivateProfileIntA
                         (local_1a0,(LPCSTR)local_104,0x20,
                          s_123456789012345678901234567lllll_004ae804);
      UVar4 = local_1f8 + 1;
      local_1f8._0_2_ = (ushort)UVar4;
      local_1f8._2_2_ = (short)(UVar4 >> 0x10);
      *(UINT *)(UVar4 * 4 + 0x6dd24c) = UVar10;
      local_1fc = (ushort)UVar8;
      uStack_1fa = (ushort)UVar9;
    } while ((int)UVar4 < 5);
  }
  else {
    local_1f8 = 1;
    do {
      _sprintf((char *)local_104,s_MStartX_d_004ae658,local_1f8);
      pbVar17 = (byte *)GetPrivateProfileIntA
                                  (local_1a0,(LPCSTR)local_104,0x20,
                                   s_123456789012345678901234567lllll_004ae804);
      local_150[local_1f8] = pbVar17;
      _sprintf((char *)local_104,s_MStartY_d_004ae64c,local_1f8);
      UVar4 = GetPrivateProfileIntA
                        (local_1a0,(LPCSTR)local_104,0x20,
                         s_123456789012345678901234567lllll_004ae804);
      local_1f8 = local_1f8 + 1;
      (&UStack_1c4)[local_1f8] = UVar4;
    } while ((int)local_1f8 < 7);
    iVar5 = 1;
    do {
      sVar23 = 1;
      local_1f8 = iVar5;
      do {
        iVar5 = FUN_0040ca00(1);
        if (iVar5 == 0) {
          sVar24 = *(short *)(local_150 + local_1f8);
          iVar5 = local_1c0[local_1f8];
          local_150[local_1f8] = local_150[sVar23];
          local_1c0[local_1f8] = local_1c0[sVar23];
          local_150[sVar23] = (byte *)(int)sVar24;
          local_1c0[sVar23] = (int)(short)iVar5;
        }
        sVar23 = sVar23 + 1;
      } while (sVar23 < 7);
      iVar5 = local_1f8 + 1;
      local_1f8._0_2_ = (ushort)iVar5;
      local_1f8._2_2_ = (short)((uint)iVar5 >> 0x10);
    } while (iVar5 < 7);
    local_1fc = *(ushort *)(local_150 + DAT_00668ccc);
    local_1f8._0_2_ = DAT_00668ccc;
    local_1f8._2_2_ = DAT_00668ccc >> 0xf;
    UVar4 = (UINT)DAT_00668ccc;
    uStack_1fa = *(ushort *)(local_1c0 + DAT_00668ccc);
    sVar23 = 0;
    do {
      sVar24 = sVar23 + 1;
      (&DAT_006dd210)[sVar23] = local_150[sVar23];
      (&DAT_006dd250)[sVar23] = local_1c0[sVar23];
      sVar23 = sVar24;
    } while (sVar24 < 6);
  }
  DAT_007168ce = local_1fc - 10;
  DAT_0071693e = uStack_1fa - 7;
  if (DAT_007168ce < 0) {
    DAT_007168ce = 0;
  }
  if (DAT_0071693e < 0) {
    DAT_0071693e = 0;
  }
  if (0x80 - DAT_0080315c <= (int)DAT_007168ce) {
    DAT_007168ce = 0x7f - DAT_0080315c;
  }
  uVar7 = (uint)DAT_0071693e;
  if (0x80 - DAT_007166a4 <= (int)uVar7) {
    DAT_0071693e = 0x7f - DAT_007166a4;
  }
  DAT_00859528 = DAT_007168ce;
  DAT_0085952a = DAT_0071693e;
  if ((DAT_00803c40 == 1) && (DAT_00719fa4 == 0)) {
    local_1f8 = UVar4;
    UVar4 = GetPrivateProfileIntA
                      (local_1a0,s_NumAIs_004ae644,1,s_123456789012345678901234567lllll_004ae804);
    local_1f8._0_2_ = (ushort)UVar4;
    local_1f8._2_2_ = (short)(UVar4 >> 0x10);
    DAT_00834f88 = DAT_00803c40 + (ushort)local_1f8;
  }
  if (6 < DAT_00834f88) {
    DAT_00834f88 = 6;
  }
  bVar27 = false;
  if (DAT_00803c40 == 1) {
    if (DAT_00719fa4 == 0) {
      sVar23 = 0;
      local_1f8 = UVar4;
      GetPrivateProfileStringA
                (local_1a0,s_PVStart_004ae628,s_0100000000000000_004ae630,(LPSTR)local_104,0x100,
                 s_123456789012345678901234567lllll_004ae804);
      sStack_1fe = 0;
      uVar7 = (short)local_1fc * 0x20 - 0xb0;
      iVar5 = (short)uStack_1fa * 0x20 + -0x50;
      local_1f4 = uVar7;
      UVar4 = local_1f8;
      if ((char)local_104[0] != '\0') {
        uVar18 = CONCAT22(extraout_var,DAT_00668ccc);
        do {
          iVar22 = (int)sStack_1fe;
          if (*(byte *)((int)local_104 + iVar22) != 0x30 &&
              -1 < (int)(*(byte *)((int)local_104 + iVar22) - 0x30)) {
            local_202 = 0;
            local_1f8 = UVar4;
            do {
              DAT_006ccad8 = 200000;
              *(undefined4 *)(&DAT_00834a00 + (short)uVar18 * 4) = 200000;
              while ((iVar15 = (iVar5 >> 5) + (uVar7 & 0xffffffe0) * 4,
                     (&DAT_008352f0)[iVar15] != '\x01' ||
                     (*(char *)((int)&DAT_006d3920 + iVar15) != '\0'))) {
                sVar23 = sVar23 + 1;
                uVar7 = uVar7 + 0x40;
                if (5 < sVar23) {
                  sVar23 = 0;
                  iVar5 = iVar5 + 0x40;
                  uVar7 = local_1f4;
                }
              }
              if (DAT_005474b4 == 1) {
                uVar11 = *(undefined4 *)(&DAT_004adb38 + iVar22 * 4);
              }
              else {
                uVar11 = CONCAT22(local_1fc,sStack_1fe);
              }
              sVar23 = sVar23 + 1;
              FUN_00424c20(uVar11,uVar18,uVar7,iVar5,0);
              uVar18 = CONCAT22(extraout_var_00,DAT_00668ccc);
              uVar7 = uVar7 + 0x40;
              if (5 < sVar23) {
                sVar23 = 0;
                iVar5 = iVar5 + 0x40;
                uVar7 = local_1f4;
              }
              local_202 = local_202 + 1;
              UVar4 = local_1f8;
            } while ((int)local_202 < (int)(*(byte *)((int)local_104 + iVar22) - 0x30));
          }
          sStack_1fe = sStack_1fe + 1;
        } while (*(char *)((int)local_104 + (int)sStack_1fe) != '\0');
      }
    }
    bVar27 = DAT_00803c40 == 1;
  }
  if ((!bVar27 && 0 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    if ((DAT_00803c40 < DAT_00834f88) &&
       ((DAT_0092ab5c != 2 && ((short)(DAT_00803c40 + 1) <= DAT_00834f88)))) {
      uVar7 = 0;
      sVar23 = DAT_00803c40 + 1;
      local_1f8 = UVar4;
      do {
        iVar5 = (int)sVar23;
        DAT_004adb30 = 1;
        *(undefined4 *)(&DAT_00834a00 + iVar5 * 4) = 200000;
        local_1fc = (short)local_150[iVar5] - 2;
        uVar2 = (short)local_1c0[iVar5] - 1;
        sVar24 = sVar23 + 1;
        FUN_00421d40(0,sVar23,CONCAT22(uStack_1fa,local_1fc),CONCAT22((ushort)local_1f8,uVar2));
        DAT_004adb30 = 0;
        uStack_1fa = uVar2;
        sVar23 = sVar24;
        UVar4 = local_1f8;
      } while (sVar24 <= DAT_00834f88);
    }
    local_200 = 1;
    if (DAT_00803c40 < 1) goto LAB_00404100;
    do {
      local_1f0 = (int)local_200;
      local_1fc = *(ushort *)(local_150 + local_1f0);
      uStack_1fa = *(ushort *)(local_1c0 + local_1f0);
      local_1f8 = UVar4;
      GetPrivateProfileStringA
                (local_1a0,s_PVStart_004ae628,s_0100000000000000_004ae630,(LPSTR)local_104,0x100,
                 s_123456789012345678901234567lllll_004ae804);
      if (DAT_0092ab5c == 2) {
        pcVar25 = s_00000000000000100000000000000000_004ae5fc;
        puVar26 = local_104;
        for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar26 = *(undefined4 *)pcVar25;
          pcVar25 = pcVar25 + 4;
          puVar26 = puVar26 + 1;
        }
      }
      sStack_1fe = 0;
      sVar23 = 0;
      uVar12 = (short)local_1fc * 0x20 - 0xb0;
      iVar5 = (short)uStack_1fa * 0x20 + -0x30;
      local_1f4 = uVar12;
      UVar4 = local_1f8;
      cVar1 = (char)local_104[0];
      while (cVar1 != '\0') {
        uVar7 = (uint)sStack_1fe;
        local_1f8 = UVar4;
        if (*(byte *)((int)local_104 + uVar7) != 0x30 &&
            -1 < (int)(*(byte *)((int)local_104 + uVar7) - 0x30)) {
          local_202 = 0;
          do {
            DAT_006ccad8 = 200000;
            *(undefined4 *)(&DAT_00834a00 + local_1f0 * 4) = 200000;
            if (*(short *)((int)&DAT_006df140 + local_1f0 * 2) == 1) {
              uVar18 = *(undefined4 *)(&DAT_004adb38 + uVar7 * 4);
            }
            else {
              uVar18 = CONCAT22(local_1fc,sStack_1fe);
            }
            sVar23 = sVar23 + 1;
            FUN_00424c20(uVar18,CONCAT22(sStack_1fe,local_200),uVar12,iVar5,0);
            uVar12 = uVar12 + 0x40;
            if (5 < sVar23) {
              sVar23 = 0;
              iVar5 = iVar5 + 0x40;
              uVar12 = local_1f4;
            }
            local_202 = local_202 + 1;
          } while ((int)local_202 < (int)(*(byte *)((int)local_104 + uVar7) - 0x30));
        }
        sStack_1fe = sStack_1fe + 1;
        UVar4 = local_1f8;
        cVar1 = *(char *)((int)local_104 + (int)sStack_1fe);
      }
      local_200 = local_200 + 1;
    } while (local_200 <= DAT_00803c40);
  }
LAB_00404100:
  local_1f8 = UVar4;
  if ((DAT_00803c40 == 1) && (DAT_00719fa4 == 0)) {
    DAT_008349f0 = 0;
    bVar16 = 0x42;
    local_1c0[0] = 0;
    if (DAT_005474b4 == 0) {
      bVar16 = 0x47;
    }
    _sprintf((char *)local_104,s_DATA__cmaps_d_ai_004ae5e8,(uint)bVar16,(int)_DAT_006cdf10);
    local_150[0] = (byte *)FUN_0049c410(local_104,&DAT_004ae5e4);
    if (local_150[0] == (byte *)0x0) {
      FUN_00405060(s_Can_t_open_nMISSx_AI_004ae5cc);
    }
    do {
      iVar5 = FUN_0049c4e0(local_150[0],&DAT_004ae424,local_104);
      if (iVar5 == -1) break;
      if (iVar5 != 0) {
        sVar23 = 0;
        cVar1 = (char)local_104[0];
        while (cVar1 != '=') {
          iVar22 = (int)sVar23;
          sVar23 = sVar23 + 1;
          uVar7 = (uint)sVar23;
          local_1e8[iVar22] = *(char *)((int)local_104 + iVar22);
          cVar1 = *(char *)((int)local_104 + uVar7);
        }
        sVar24 = sVar23 + 1;
        local_1e8[sVar23] = '\0';
        uVar2 = 0;
        cVar1 = *(char *)((int)local_104 + (int)sVar24);
        uVar12 = 0;
        while (cVar1 != '\0') {
          iVar22 = (int)sVar24;
          sVar24 = sVar24 + 1;
          uVar2 = (short)uVar12 + 1;
          local_12c[(short)uVar12] = *(char *)((int)local_104 + iVar22);
          cVar1 = *(char *)((int)local_104 + (int)sVar24);
          uVar7 = CONCAT31((int3)(char)(uVar12 >> 8),cVar1);
          uVar12 = (uint)uVar2;
        }
        local_12c[(short)uVar2] = '\0';
        iVar22 = _strncmp(&DAT_004ae5c8,local_1e8,3);
        if (iVar22 == 0) {
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_bt_base_004ba688 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x17);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          uVar2 = (ushort)(local_1f8 >> 8);
          local_1fc = uVar2 & 0xff;
          uVar18 = CONCAT22(extraout_var_01,DAT_00803c40);
          DAT_004adb30 = 1;
          iVar22 = 0;
          (&DAT_00834a04)[DAT_00803c40] = 200000;
          uStack_1fa = (ushort)local_1f8 & 0xff;
          if (-1 < DAT_0083a402) {
            piVar13 = &DAT_00805df0;
            do {
              if ((((*piVar13 != 0) && (piVar13[1] == (int)(short)uVar7)) &&
                  (piVar13[6] == (int)(short)local_1fc)) && (piVar13[7] == (int)(short)uStack_1fa))
              {
                uVar7 = CONCAT22((short)(uVar7 >> 0x10),0xffff);
                uVar18 = _DAT_00803c40;
                goto LAB_00404340;
              }
              piVar13 = piVar13 + 0x38;
              iVar22 = iVar22 + 1;
            } while (iVar22 <= DAT_0083a402);
            uVar18 = CONCAT22(extraout_var_01,DAT_00803c40);
          }
LAB_00404340:
          if ((short)uVar7 != -1) {
            FUN_00421d40(uVar7,CONCAT22((short)((uint)uVar18 >> 0x10),(short)uVar18 + 1),
                         CONCAT22((ushort)local_1f8,uVar2) & 0xff00ff,
                         CONCAT22((ushort)local_1f8,(ushort)local_1f8) & 0xffff00ff);
            local_1c0[0] = local_1c0[0] + 1;
          }
          DAT_004adb30 = 0;
        }
        iVar22 = _strncmp(&DAT_004ae5c0,local_1e8,3);
        if (iVar22 == 0) {
          local_1e8[0] = 'b';
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_bt_base_004ba688 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x17);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          uVar2 = (ushort)(local_1f8 >> 8);
          local_1fc = uVar2 & 0xff;
          uVar18 = CONCAT22(extraout_var_02,DAT_00803c40);
          DAT_004adb30 = 1;
          *(undefined4 *)(&DAT_00834a00 + DAT_00803c40 * 4) = 200000;
          uVar3 = (ushort)local_1f8 & 0xff;
          FUN_00421d40(uVar7,uVar18,CONCAT22(uStack_1fa,uVar2) & 0xffff00ff,
                       CONCAT22((ushort)local_1f8,(ushort)local_1f8) & 0xffff00ff);
          DAT_004adb30 = 0;
          uStack_1fa = uVar3;
        }
        iVar22 = _strncmp(&DAT_004ae5bc,local_1e8,3);
        if (iVar22 == 0) {
          local_1e8[0] = 'b';
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_bt_base_004ba688 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x17);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          uVar2 = (ushort)(local_1f8 >> 8);
          local_1fc = uVar2 & 0xff;
          uVar18 = CONCAT22(extraout_var_03,DAT_00803c40);
          DAT_004adb30 = 1;
          *(undefined4 *)(&DAT_00834a00 + DAT_00803c40 * 4) = 20000;
          uVar3 = (ushort)local_1f8 & 0xff;
          FUN_00421d40(uVar7,uVar18,CONCAT22(uStack_1fa,uVar2) & 0xffff00ff,
                       CONCAT22((ushort)local_1f8,(ushort)local_1f8) & 0xffff00ff);
          DAT_004adb30 = 0;
          uStack_1fa = uVar3;
        }
        iVar22 = _strncmp(&DAT_004ae5b8,local_1e8,3);
        if (iVar22 == 0) {
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_vt_carrier_004baa70 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x2c);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          local_1fc = (ushort)(local_1f8 >> 8) & 0xff;
          sVar23 = DAT_00803c40;
          uStack_1fa = (ushort)local_1f8 & 0xff;
          (&DAT_00834a04)[DAT_00803c40] = 200000;
          sVar24 = sVar23 >> 0xf;
          uVar7 = CONCAT22((short)(uVar7 >> 0x10),(short)uVar7 + local_1f8._2_2_ * 0x100);
          FUN_00424c20(uVar7,sVar23 + 1,CONCAT22(sVar24,local_1fc * 0x20 + 0x10),
                       CONCAT22(sVar24,uStack_1fa * 0x20 + 0x10),0);
        }
        iVar22 = _strncmp(&DAT_004ae5b4,local_1e8,3);
        if (iVar22 == 0) {
          local_1e8[0] = 'v';
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_vt_carrier_004baa70 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x2c);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          sVar23 = DAT_00668ccc;
          local_1fc = (ushort)(local_1f8 >> 8) & 0xff;
          uVar18 = CONCAT22(extraout_var_04,DAT_00668ccc);
          uStack_1fa = (ushort)local_1f8 & 0xff;
          *(undefined4 *)(&DAT_00834a00 + DAT_00668ccc * 4) = 200000;
          uVar7 = CONCAT22((short)(uVar7 >> 0x10),(short)uVar7 + local_1f8._2_2_ * 0x100);
          FUN_00424c20(uVar7,uVar18,CONCAT22(sVar23 >> 0xf,local_1fc * 0x20 + 0x10),
                       CONCAT22(sVar23 >> 0xf,uStack_1fa * 0x20 + 0x10),0);
        }
        iVar22 = _strncmp(&DAT_004ae5b0,local_1e8,3);
        if (iVar22 == 0) {
          local_1e8[0] = 'v';
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_vt_carrier_004baa70 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x2c);
          if ((short)uVar7 == -1) goto LAB_004048f9;
          _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
          local_1fc = (ushort)(local_1f8 >> 8) & 0xff;
          sVar23 = DAT_00803c40;
          uStack_1fa = (ushort)local_1f8 & 0xff;
          (&DAT_00834a04)[DAT_00803c40] = 200000;
          sVar24 = sVar23 >> 0xf;
          uVar7 = CONCAT22((short)(uVar7 >> 0x10),(short)uVar7 + local_1f8._2_2_ * 0x100);
          FUN_00424c20(uVar7,sVar23 + 0x5b,CONCAT22(sVar24,local_1fc * 0x20 + 0x10),
                       CONCAT22(sVar24,uStack_1fa * 0x20 + 0x10),0);
        }
        iVar22 = _strncmp(&DAT_004ae5ac,local_1e8,3);
        if (iVar22 == 0) {
          local_1e8[0] = 'v';
          uVar21 = (undefined2)(uVar7 >> 0x10);
          uVar7 = CONCAT22(uVar21,0xffff);
          sVar23 = 0;
          do {
            uVar12 = 0xffffffff;
            pcVar25 = local_1e8;
            do {
              if (uVar12 == 0) break;
              uVar12 = uVar12 - 1;
              cVar1 = *pcVar25;
              pcVar25 = pcVar25 + 1;
            } while (cVar1 != '\0');
            iVar22 = _strncmp(local_1e8,s_vt_carrier_004baa70 + sVar23 * 0x14,~uVar12 - 1);
            if (iVar22 == 0) {
              uVar7 = CONCAT22(uVar21,sVar23);
              break;
            }
            sVar23 = sVar23 + 1;
          } while (sVar23 < 0x2c);
          if ((short)uVar7 != -1) {
            _sscanf(local_12c,&DAT_004ae5c4,&local_1f8);
            local_1fc = (ushort)(local_1f8 >> 8) & 0xff;
            uStack_1fa = (ushort)local_1f8 & 0xff;
            sVar23 = DAT_00803c40;
            (&DAT_00834a04)[DAT_00803c40] = 200000;
            uVar7 = CONCAT22((short)(uVar7 >> 0x10),(short)uVar7 + local_1f8._2_2_ * 0x100);
            FUN_00424c20(uVar7,99,CONCAT22(sVar23 >> 0xf,local_1fc * 0x20 + 0x10),
                         CONCAT22(sVar23 >> 0xf,uStack_1fa * 0x20 + 0x10),0);
          }
        }
      }
LAB_004048f9:
    } while (iVar5 != -1);
    FUN_0049c330(local_150[0]);
  }
  local_1f4 = CONCAT22(local_1f4._2_2_,1);
  if (0 < (int)DAT_00834f88 - (int)DAT_00803c40) {
    do {
      if ((DAT_0092ab5c == 2) || (DAT_00803c40 < 2)) {
        sStack_1fe = 0;
        GetPrivateProfileStringA
                  (local_1a0,s_PAStart_004ae58c,s_00000000000000000000000_004ae594,(LPSTR)local_104,
                   0x100,s_123456789012345678901234567lllll_004ae804);
        if (DAT_0092ab5c == 2) {
          pcVar25 = s_00000000000000100000000000000000_004ae5fc;
          puVar26 = local_104;
          for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar26 = *(undefined4 *)pcVar25;
            pcVar25 = pcVar25 + 4;
            puVar26 = puVar26 + 1;
          }
        }
        iVar5 = (int)(short)local_1f4;
        uVar7 = (int)(short)local_1fc + (local_1ec + iVar5) * 4 + 0xfU & 0x3f;
        uVar12 = (local_130 + iVar5) * 7 + (int)(short)uStack_1fa + 0xdU & 0x3f;
        cVar1 = (char)local_104[0];
        while (cVar1 != '\0') {
          local_150[0] = (byte *)((int)local_104 + (int)sStack_1fe);
          uVar14 = (uint)*(byte *)((int)local_104 + (int)sStack_1fe);
          if (uVar14 != 0x30 && -1 < (int)(uVar14 - 0x30)) {
            sVar23 = 0;
            do {
              uVar7 = uVar7 + sVar23 + local_1ec;
              uVar12 = uVar12 + iVar5 + local_1ec;
              while( true ) {
                uVar12 = uVar12 & 0x3f;
                uVar7 = uVar7 & 0x3f;
                iVar22 = uVar7 * 0x80 + uVar12;
                if ((((&DAT_00835a7e)[iVar22] == '\x01') && ((&DAT_006d40ae)[iVar22] == '\0')) &&
                   (((&DAT_00835afe)[iVar22] == '\x01' &&
                    ((((&DAT_00835a7f)[iVar22] == '\x01' && ((&DAT_008359fe)[iVar22] == '\x01')) &&
                     ((&DAT_00835a7d)[iVar22] == '\x01')))))) break;
                uVar7 = uVar7 + 2;
                uVar12 = uVar12 + 1;
              }
              *(undefined4 *)(&DAT_00834a00 + (DAT_00803c40 + iVar5) * 4) = 200000;
              sVar23 = sVar23 + 1;
              FUN_00424c20(CONCAT22(local_1fc,sStack_1fe),DAT_00803c40 + (short)local_1f4,
                           (short)uVar7 * 0x20 + 0x1f0,(short)uVar12 * 0x20 + 0x1d0,0);
            } while ((int)sVar23 < (int)(*local_150[0] - 0x30));
          }
          sStack_1fe = sStack_1fe + 1;
          cVar1 = *(char *)((int)local_104 + (int)sStack_1fe);
        }
      }
      sVar23 = (short)local_1f4 + 1;
      local_1f4 = CONCAT22(local_1f4._2_2_,sVar23);
    } while ((int)sVar23 <= (int)DAT_00834f88 - (int)DAT_00803c40);
  }
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_StartCash_004ae698,25000,
                     s_123456789012345678901234567lllll_004ae804);
  if ((1 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    if (DAT_009d5ae4 == 0) {
      UVar4 = 15000;
    }
    if (DAT_009d5ae4 == 1) {
      UVar4 = 30000;
    }
    if (DAT_009d5ae4 == 2) {
      UVar4 = 50000;
    }
    if (DAT_009d5ae4 == 3) {
      UVar4 = 75000;
    }
    local_1c0[0] = 0;
  }
  if (DAT_0092ab5c == 2) {
    UVar4 = 0;
  }
  *(UINT *)(&DAT_00834a00 + DAT_00668ccc * 4) = UVar4;
  sVar23 = 0;
  do {
    iVar5 = (int)sVar23;
    sVar23 = sVar23 + 1;
    DAT_006ccad8 = UVar4;
    *(UINT *)(&DAT_00834a00 + iVar5 * 4) = UVar4;
  } while (sVar23 < 8);
  UVar4 = GetPrivateProfileIntA
                    (local_1a0,s_AIXtraCash_004ae68c,0,s_123456789012345678901234567lllll_004ae804);
  iVar5 = DAT_00719fa4;
  sVar23 = DAT_00803c40;
  local_1f8._0_2_ = (ushort)UVar4;
  local_1f8._2_2_ = (short)(UVar4 >> 0x10);
  if ((1 < DAT_00803c40) || (DAT_00719fa4 == 1)) {
    local_1f8._0_2_ = 0;
    local_1f8._2_2_ = 0;
  }
  sVar24 = DAT_00803c40 + 1;
  for (sVar19 = sVar24; sVar19 < 8; sVar19 = sVar19 + 1) {
    piVar13 = (int *)(&DAT_00834a00 + sVar19 * 4);
    iVar22 = *(int *)(&DAT_00834a00 + sVar19 * 4) + CONCAT22(local_1f8._2_2_,(ushort)local_1f8);
    *piVar13 = iVar22;
    iVar22 = iVar22 + local_1c0[0] * -2000;
    *piVar13 = iVar22;
    if (iVar22 < 9000) {
      *piVar13 = 9000;
    }
  }
  if ((1 < sVar23) || (iVar5 == 1)) {
    if (DAT_009d6b64 == 0) {
      _DAT_008046ec = 10;
      DAT_00507484 = 10;
      local_1c0[0] = DAT_00834a1c;
    }
    else if (DAT_009d6b64 == 1) {
      DAT_00507484 = 6;
      _DAT_008046ec = 6;
      local_1c0[0] = DAT_00834a1c / 2;
    }
    else if (DAT_009d6b64 == 2) {
      DAT_00507484 = 3;
      _DAT_008046ec = 3;
      local_1c0[0] = (int)(DAT_00834a1c + (DAT_00834a1c >> 0x1f & 3U)) >> 2;
    }
    if (sVar24 < 8) {
      iVar5 = 2 - DAT_009d6b64;
      do {
        iVar22 = (int)sVar24;
        iVar15 = iVar22 * 4;
        *(int *)(&DAT_00834a00 + iVar15) = local_1c0[0];
        if (local_1c0[0] < 8000) {
          *(undefined4 *)(&DAT_00834a00 + iVar15) = 8000;
        }
        sVar24 = sVar24 + 1;
        (&DAT_00835260)[iVar22] = iVar5;
      } while (sVar24 < 8);
    }
  }
  DAT_0083e4d0 = DAT_0092ab5c;
  DAT_008046e8 = 0;
  DAT_008046f0 = 5000;
  _DAT_0085e76c = 15000;
  return;
}



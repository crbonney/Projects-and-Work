  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (physical_dynamics_transfer_mo_P)
    ;%
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POInitial
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POFinal
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POWatchdog
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% physical_dynamics_transfer_mo_P.Constant1_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% physical_dynamics_transfer_mo_P.TransferFcn_A
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% physical_dynamics_transfer_mo_P.TransferFcn_C
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% physical_dynamics_transfer_mo_P.TransferFcn1_A
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 18;
	
	  ;% physical_dynamics_transfer_mo_P.TransferFcn1_C
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 19;
	
	  ;% physical_dynamics_transfer_mo_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 20;
	
	  ;% physical_dynamics_transfer_mo_P.Gain1_Gain
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 21;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_Amp
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 22;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_Bias
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 23;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_Freq
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 24;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_Hsin
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 25;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_HCos
	  section.data(27).logicalSrcIdx = 30;
	  section.data(27).dtTransOffset = 26;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_PSin
	  section.data(28).logicalSrcIdx = 31;
	  section.data(28).dtTransOffset = 27;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave1_PCos
	  section.data(29).logicalSrcIdx = 32;
	  section.data(29).dtTransOffset = 28;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_Amp
	  section.data(30).logicalSrcIdx = 33;
	  section.data(30).dtTransOffset = 29;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_Bias
	  section.data(31).logicalSrcIdx = 34;
	  section.data(31).dtTransOffset = 30;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_Freq
	  section.data(32).logicalSrcIdx = 35;
	  section.data(32).dtTransOffset = 31;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_Hsin
	  section.data(33).logicalSrcIdx = 36;
	  section.data(33).dtTransOffset = 32;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_HCos
	  section.data(34).logicalSrcIdx = 37;
	  section.data(34).dtTransOffset = 33;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_PSin
	  section.data(35).logicalSrcIdx = 38;
	  section.data(35).dtTransOffset = 34;
	
	  ;% physical_dynamics_transfer_mo_P.SineWave2_PCos
	  section.data(36).logicalSrcIdx = 39;
	  section.data(36).dtTransOffset = 35;
	
	  ;% physical_dynamics_transfer_mo_P.Saturation_UpperSat
	  section.data(37).logicalSrcIdx = 40;
	  section.data(37).dtTransOffset = 36;
	
	  ;% physical_dynamics_transfer_mo_P.Saturation_LowerSat
	  section.data(38).logicalSrcIdx = 41;
	  section.data(38).dtTransOffset = 37;
	
	  ;% physical_dynamics_transfer_mo_P.Gain2_Gain
	  section.data(39).logicalSrcIdx = 42;
	  section.data(39).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 4;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 6;
	
	  ;% physical_dynamics_transfer_mo_P.HILReadEncoder_Channels
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 7;
	
	  ;% physical_dynamics_transfer_mo_P.HILReadEncoder1_Channels
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 8;
	
	  ;% physical_dynamics_transfer_mo_P.HILWriteAnalog_Channels
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 3;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 4;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 5;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 6;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 7;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 8;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 9;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 10;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 65;
	  section.data(12).dtTransOffset = 11;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 66;
	  section.data(13).dtTransOffset = 12;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 67;
	  section.data(14).dtTransOffset = 13;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 68;
	  section.data(15).dtTransOffset = 14;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 69;
	  section.data(16).dtTransOffset = 15;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 70;
	  section.data(17).dtTransOffset = 16;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 71;
	  section.data(18).dtTransOffset = 17;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 72;
	  section.data(19).dtTransOffset = 18;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 73;
	  section.data(20).dtTransOffset = 19;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 74;
	  section.data(21).dtTransOffset = 20;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 75;
	  section.data(22).dtTransOffset = 21;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 76;
	  section.data(23).dtTransOffset = 22;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 77;
	  section.data(24).dtTransOffset = 23;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 78;
	  section.data(25).dtTransOffset = 24;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 79;
	  section.data(26).dtTransOffset = 25;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 80;
	  section.data(27).dtTransOffset = 26;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 81;
	  section.data(28).dtTransOffset = 27;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 82;
	  section.data(29).dtTransOffset = 28;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 83;
	  section.data(30).dtTransOffset = 29;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 84;
	  section.data(31).dtTransOffset = 30;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 85;
	  section.data(32).dtTransOffset = 31;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 86;
	  section.data(33).dtTransOffset = 32;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 87;
	  section.data(34).dtTransOffset = 33;
	
	  ;% physical_dynamics_transfer_mo_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 88;
	  section.data(35).dtTransOffset = 34;
	
	  ;% physical_dynamics_transfer_mo_P.HILReadEncoder_Active
	  section.data(36).logicalSrcIdx = 89;
	  section.data(36).dtTransOffset = 35;
	
	  ;% physical_dynamics_transfer_mo_P.HILReadEncoder1_Active
	  section.data(37).logicalSrcIdx = 90;
	  section.data(37).dtTransOffset = 36;
	
	  ;% physical_dynamics_transfer_mo_P.HILWriteAnalog_Active
	  section.data(38).logicalSrcIdx = 91;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (physical_dynamics_transfer_mo_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfer_mo_B.dq1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfer_mo_B.dq2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfer_mo_B.q1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfer_mo_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% physical_dynamics_transfer_mo_B.q2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% physical_dynamics_transfer_mo_B.Gain2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (physical_dynamics_transfe_DWork)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfe_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% physical_dynamics_transfe_DWork.lastSin
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% physical_dynamics_transfe_DWork.lastCos
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% physical_dynamics_transfe_DWork.lastSin_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% physical_dynamics_transfe_DWork.lastCos_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfe_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampA
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfe_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfe_DWork.HILReadEncoder1_PWORK
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfe_DWork.HILWriteAnalog_PWORK
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% physical_dynamics_transfe_DWork.PhysicalData_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% physical_dynamics_transfe_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% physical_dynamics_transfe_DWork.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 3;
	
	  ;% physical_dynamics_transfe_DWork.HILReadEncoder_Buffer
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 5;
	
	  ;% physical_dynamics_transfe_DWork.HILReadEncoder1_Buffer
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 6;
	
	  ;% physical_dynamics_transfe_DWork.systemEnable
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 7;
	
	  ;% physical_dynamics_transfe_DWork.systemEnable_d
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 321867131;
  targMap.checksum1 = 3931537316;
  targMap.checksum2 = 2171480614;
  targMap.checksum3 = 2099522798;


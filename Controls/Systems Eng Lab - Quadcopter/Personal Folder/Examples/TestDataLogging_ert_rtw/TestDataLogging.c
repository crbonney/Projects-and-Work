/*
 * TestDataLogging.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TestDataLogging".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Jul  9 16:01:33 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestDataLogging.h"
#include "TestDataLogging_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block states (default storage) */
DW_TestDataLogging_T TestDataLogging_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TestDataLogging_T TestDataLogging_Y;

/* Real-time model */
RT_MODEL_TestDataLogging_T TestDataLogging_M_;
RT_MODEL_TestDataLogging_T *const TestDataLogging_M = &TestDataLogging_M_;

/* Model step function */
void TestDataLogging_step(void)
{
  /* local block i/o variables */
  real32_T rtb_TmpSignalConversionAtToWork[3];
  real_T rtb_VectorConcatenate1_idx_0;
  real_T rtb_VectorConcatenate1_idx_1;
  real_T rtb_VectorConcatenate1_idx_2;
  real_T rtb_VectorConcatenate1_idx_3;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  rtb_VectorConcatenate1_idx_0 = (TestDataLogging_DW.clockTickCounter <
    TestDataLogging_P.PulseGenerator1_Duty) &&
    (TestDataLogging_DW.clockTickCounter >= 0) ?
    TestDataLogging_P.PulseGenerator1_Amp : 0.0;
  if (TestDataLogging_DW.clockTickCounter >=
      TestDataLogging_P.PulseGenerator1_Period - 1.0) {
    TestDataLogging_DW.clockTickCounter = 0;
  } else {
    TestDataLogging_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  rtb_VectorConcatenate1_idx_1 = (TestDataLogging_DW.clockTickCounter_h <
    TestDataLogging_P.PulseGenerator3_Duty) &&
    (TestDataLogging_DW.clockTickCounter_h >= 0) ?
    TestDataLogging_P.PulseGenerator3_Amp : 0.0;
  if (TestDataLogging_DW.clockTickCounter_h >=
      TestDataLogging_P.PulseGenerator3_Period - 1.0) {
    TestDataLogging_DW.clockTickCounter_h = 0;
  } else {
    TestDataLogging_DW.clockTickCounter_h++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator3' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator4' */
  rtb_VectorConcatenate1_idx_2 = (TestDataLogging_DW.clockTickCounter_a <
    TestDataLogging_P.PulseGenerator4_Duty) &&
    (TestDataLogging_DW.clockTickCounter_a >= 0) ?
    TestDataLogging_P.PulseGenerator4_Amp : 0.0;
  if (TestDataLogging_DW.clockTickCounter_a >=
      TestDataLogging_P.PulseGenerator4_Period - 1.0) {
    TestDataLogging_DW.clockTickCounter_a = 0;
  } else {
    TestDataLogging_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator4' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  rtb_VectorConcatenate1_idx_3 = (TestDataLogging_DW.clockTickCounter_n <
    TestDataLogging_P.PulseGenerator2_Duty) &&
    (TestDataLogging_DW.clockTickCounter_n >= 0) ?
    TestDataLogging_P.PulseGenerator2_Amp : 0.0;
  if (TestDataLogging_DW.clockTickCounter_n >=
      TestDataLogging_P.PulseGenerator2_Period - 1.0) {
    TestDataLogging_DW.clockTickCounter_n = 0;
  } else {
    TestDataLogging_DW.clockTickCounter_n++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator2' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_VectorConcatenate1_idx_0 > TestDataLogging_P.Saturation1_UpperSat) {
    motors_outport[0] = TestDataLogging_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate1_idx_0 <
             TestDataLogging_P.Saturation1_LowerSat) {
    motors_outport[0] = TestDataLogging_P.Saturation1_LowerSat;
  } else {
    motors_outport[0] = (real32_T)rtb_VectorConcatenate1_idx_0;
  }

  /* Outport: '<Root>/Motors' */
  TestDataLogging_Y.Motors[0] = motors_outport[0];

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_VectorConcatenate1_idx_1 > TestDataLogging_P.Saturation1_UpperSat) {
    motors_outport[1] = TestDataLogging_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate1_idx_1 <
             TestDataLogging_P.Saturation1_LowerSat) {
    motors_outport[1] = TestDataLogging_P.Saturation1_LowerSat;
  } else {
    motors_outport[1] = (real32_T)rtb_VectorConcatenate1_idx_1;
  }

  /* Outport: '<Root>/Motors' */
  TestDataLogging_Y.Motors[1] = motors_outport[1];

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_VectorConcatenate1_idx_2 > TestDataLogging_P.Saturation1_UpperSat) {
    motors_outport[2] = TestDataLogging_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate1_idx_2 <
             TestDataLogging_P.Saturation1_LowerSat) {
    motors_outport[2] = TestDataLogging_P.Saturation1_LowerSat;
  } else {
    motors_outport[2] = (real32_T)rtb_VectorConcatenate1_idx_2;
  }

  /* Outport: '<Root>/Motors' */
  TestDataLogging_Y.Motors[2] = motors_outport[2];

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_VectorConcatenate1_idx_3 > TestDataLogging_P.Saturation1_UpperSat) {
    motors_outport[3] = TestDataLogging_P.Saturation1_UpperSat;
  } else if (rtb_VectorConcatenate1_idx_3 <
             TestDataLogging_P.Saturation1_LowerSat) {
    motors_outport[3] = TestDataLogging_P.Saturation1_LowerSat;
  } else {
    motors_outport[3] = (real32_T)rtb_VectorConcatenate1_idx_3;
  }

  /* Outport: '<Root>/Motors' */
  TestDataLogging_Y.Motors[3] = motors_outport[3];

  /* ManualSwitch: '<S1>/Manual Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (TestDataLogging_P.ManualSwitch_CurrentSetting == 1) {
    flag_outport = TestDataLogging_P.Constant2_Value;
  } else {
    flag_outport = TestDataLogging_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch' */

  /* Outport: '<Root>/Flag' */
  TestDataLogging_Y.Flag = flag_outport;

  /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
   *  Inport: '<Root>/Sensors'
   *  SignalConversion generated from: '<S2>/Bus Selector4'
   * */
  rtb_TmpSignalConversionAtToWork[0] = sensor_inport.HALSensors.HAL_gyro_SI.x;
  rtb_TmpSignalConversionAtToWork[1] = sensor_inport.HALSensors.HAL_gyro_SI.y;
  rtb_TmpSignalConversionAtToWork[2] = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = TestDataLogging_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          TestDataLogging_DW.ToWorkspace_PWORK.LoggedData,
                          &locTime, &rtb_TmpSignalConversionAtToWork[0]);
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(TestDataLogging_M->rtwLogInfo,
                      (&TestDataLogging_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(TestDataLogging_M)!=-1) &&
        !((rtmGetTFinal(TestDataLogging_M)-TestDataLogging_M->Timing.taskTime0) >
          TestDataLogging_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TestDataLogging_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TestDataLogging_M->Timing.clockTick0)) {
    ++TestDataLogging_M->Timing.clockTickH0;
  }

  TestDataLogging_M->Timing.taskTime0 = TestDataLogging_M->Timing.clockTick0 *
    TestDataLogging_M->Timing.stepSize0 + TestDataLogging_M->Timing.clockTickH0 *
    TestDataLogging_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void TestDataLogging_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TestDataLogging_M, 0,
                sizeof(RT_MODEL_TestDataLogging_T));
  rtmSetTFinal(TestDataLogging_M, 100.0);
  TestDataLogging_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    TestDataLogging_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogT(TestDataLogging_M->rtwLogInfo, "tout");
    rtliSetLogX(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogXFinal(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(TestDataLogging_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(TestDataLogging_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(TestDataLogging_M->rtwLogInfo, 0);
    rtliSetLogDecimation(TestDataLogging_M->rtwLogInfo, 1);
    rtliSetLogY(TestDataLogging_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(TestDataLogging_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(TestDataLogging_M->rtwLogInfo, (NULL));
  }

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (dwork) */
  (void) memset((void *)&TestDataLogging_DW, 0,
                sizeof(DW_TestDataLogging_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&TestDataLogging_Y, 0,
                sizeof(ExtY_TestDataLogging_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(TestDataLogging_M->rtwLogInfo, 0.0,
    rtmGetTFinal(TestDataLogging_M), TestDataLogging_M->Timing.stepSize0,
    (&rtmGetErrorStatus(TestDataLogging_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 3 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 3 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_SINGLE };

    static int_T rt_ToWksComplexSignals[] = { 0 };

    static int_T rt_ToWksFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs[] = {
      (NULL)
    };

    static const char_T *rt_ToWksLabels[] = { "" };

    static RTWLogSignalInfo rt_ToWksSignalInfo = {
      1,
      rt_ToWksWidths,
      rt_ToWksNumDimensions,
      rt_ToWksDimensions,
      rt_ToWksIsVarDims,
      rt_ToWksCurrSigDims,
      rt_ToWksCurrSigDimsSize,
      rt_ToWksDataTypeIds,
      rt_ToWksComplexSignals,
      rt_ToWksFrameData,
      rt_ToWksLoggingPreprocessingFcnPtrs,

      { rt_ToWksLabels },
      (NULL),
      (NULL),
      (NULL),

      { (NULL) },

      { (NULL) },
      (NULL),
      (NULL)
    };

    static const char_T rt_ToWksBlockName[] =
      "TestDataLogging/Flight Control System/To Workspace";
    TestDataLogging_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      TestDataLogging_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(TestDataLogging_M),
      TestDataLogging_M->Timing.stepSize0,
      (&rtmGetErrorStatus(TestDataLogging_M)),
      "simout",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (TestDataLogging_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  TestDataLogging_DW.clockTickCounter = 0;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator3' */
  TestDataLogging_DW.clockTickCounter_h = -400;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator4' */
  TestDataLogging_DW.clockTickCounter_a = -800;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator2' */
  TestDataLogging_DW.clockTickCounter_n = -1200;
}

/* Model terminate function */
void TestDataLogging_terminate(void)
{
  /* (no terminate code required) */
}

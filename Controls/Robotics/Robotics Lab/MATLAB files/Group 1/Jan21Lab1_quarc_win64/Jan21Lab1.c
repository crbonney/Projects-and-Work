/*
 * Jan21Lab1.c
 *
 * Code generation for model "Jan21Lab1".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Jan 21 11:31:42 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Jan21Lab1.h"
#include "Jan21Lab1_private.h"
#include "Jan21Lab1_dt.h"

/* Block signals (auto storage) */
BlockIO_Jan21Lab1 Jan21Lab1_B;

/* Block states (auto storage) */
D_Work_Jan21Lab1 Jan21Lab1_DWork;

/* Real-time model */
RT_MODEL_Jan21Lab1 Jan21Lab1_M_;
RT_MODEL_Jan21Lab1 *const Jan21Lab1_M = &Jan21Lab1_M_;

/* Model step function */
void Jan21Lab1_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_Switch;
  boolean_T tmp;

  /* Memory: '<Root>/Memory' */
  rtb_Saturation = Jan21Lab1_DWork.Memory_PreviousInput;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Jan21Lab1_B.Compare = (rtb_Saturation > Jan21Lab1_P.Constant_Value_d);

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Jan21Lab1/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Jan21Lab1_DWork.HILInitialize_Card,
      &Jan21Lab1_P.HILReadEncoder_Channels, 1,
      &Jan21Lab1_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
    } else {
      rtb_Saturation = Jan21Lab1_DWork.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  Jan21Lab1_B.Gain = Jan21Lab1_P.Gain_Gain * rtb_Saturation;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S4>/Constant'
   *  Logic: '<Root>/AND1'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   *  RelationalOperator: '<S4>/Compare'
   */
  if ((Jan21Lab1_B.Gain <= Jan21Lab1_P.Constant_Value_j) && (Jan21Lab1_B.Gain >=
       Jan21Lab1_P.Constant_Value_f)) {
    tmp = Jan21Lab1_B.Compare;
  } else {
    tmp = (Jan21Lab1_B.Gain <= Jan21Lab1_P.Constant_Value);
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (tmp) {
    rtb_Switch = Jan21Lab1_P.Constant_Value_a;
  } else {
    rtb_Switch = Jan21Lab1_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch >= Jan21Lab1_P.Saturation_UpperSat) {
    rtb_Saturation = Jan21Lab1_P.Saturation_UpperSat;
  } else if (rtb_Switch <= Jan21Lab1_P.Saturation_LowerSat) {
    rtb_Saturation = Jan21Lab1_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Jan21Lab1/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Jan21Lab1_DWork.HILInitialize_Card,
      &Jan21Lab1_P.HILWriteAnalog_Channels, 1, &rtb_Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
    }
  }

  /* Update for Memory: '<Root>/Memory' */
  Jan21Lab1_DWork.Memory_PreviousInput = rtb_Switch;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Jan21Lab1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Jan21Lab1_M)!=-1) &&
        !((rtmGetTFinal(Jan21Lab1_M)-Jan21Lab1_M->Timing.taskTime0) >
          Jan21Lab1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Jan21Lab1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Jan21Lab1_M)) {
      rtmSetErrorStatus(Jan21Lab1_M, "Simulation finished");
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
  if (!(++Jan21Lab1_M->Timing.clockTick0)) {
    ++Jan21Lab1_M->Timing.clockTickH0;
  }

  Jan21Lab1_M->Timing.taskTime0 = Jan21Lab1_M->Timing.clockTick0 *
    Jan21Lab1_M->Timing.stepSize0 + Jan21Lab1_M->Timing.clockTickH0 *
    Jan21Lab1_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Jan21Lab1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Jan21Lab1_M, 0,
                sizeof(RT_MODEL_Jan21Lab1));
  rtmSetTFinal(Jan21Lab1_M, -1);
  Jan21Lab1_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Jan21Lab1_M->Sizes.checksums[0] = (3287402149U);
  Jan21Lab1_M->Sizes.checksums[1] = (2742453000U);
  Jan21Lab1_M->Sizes.checksums[2] = (1948676461U);
  Jan21Lab1_M->Sizes.checksums[3] = (2447825193U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Jan21Lab1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Jan21Lab1_M->extModeInfo,
      &Jan21Lab1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Jan21Lab1_M->extModeInfo, Jan21Lab1_M->Sizes.checksums);
    rteiSetTPtr(Jan21Lab1_M->extModeInfo, rtmGetTPtr(Jan21Lab1_M));
  }

  /* block I/O */
  (void) memset(((void *) &Jan21Lab1_B), 0,
                sizeof(BlockIO_Jan21Lab1));

  /* states (dwork) */
  (void) memset((void *)&Jan21Lab1_DWork, 0,
                sizeof(D_Work_Jan21Lab1));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Jan21Lab1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan21Lab1/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &Jan21Lab1_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Jan21Lab1_DWork.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Jan21Lab1_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
      return;
    }

    if ((Jan21Lab1_P.HILInitialize_AIPStart && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_AIPEnter && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_AIMinimums[0] =
        Jan21Lab1_P.HILInitialize_AILow;
      Jan21Lab1_DWork.HILInitialize_AIMinimums[1] =
        Jan21Lab1_P.HILInitialize_AILow;
      Jan21Lab1_DWork.HILInitialize_AIMaximums[0] =
        Jan21Lab1_P.HILInitialize_AIHigh;
      Jan21Lab1_DWork.HILInitialize_AIMaximums[1] =
        Jan21Lab1_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(Jan21Lab1_DWork.HILInitialize_Card,
        Jan21Lab1_P.HILInitialize_AIChannels, 2U,
        &Jan21Lab1_DWork.HILInitialize_AIMinimums[0],
        &Jan21Lab1_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Jan21Lab1_P.HILInitialize_AOPStart && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_AOPEnter && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_AOMinimums[0] =
        Jan21Lab1_P.HILInitialize_AOLow;
      Jan21Lab1_DWork.HILInitialize_AOMinimums[1] =
        Jan21Lab1_P.HILInitialize_AOLow;
      Jan21Lab1_DWork.HILInitialize_AOMaximums[0] =
        Jan21Lab1_P.HILInitialize_AOHigh;
      Jan21Lab1_DWork.HILInitialize_AOMaximums[1] =
        Jan21Lab1_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(Jan21Lab1_DWork.HILInitialize_Card,
        Jan21Lab1_P.HILInitialize_AOChannels, 2U,
        &Jan21Lab1_DWork.HILInitialize_AOMinimums[0],
        &Jan21Lab1_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Jan21Lab1_P.HILInitialize_AOStart && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_AOEnter && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_AOVoltages[0] =
        Jan21Lab1_P.HILInitialize_AOInitial;
      Jan21Lab1_DWork.HILInitialize_AOVoltages[1] =
        Jan21Lab1_P.HILInitialize_AOInitial;
      result = hil_write_analog(Jan21Lab1_DWork.HILInitialize_Card,
        Jan21Lab1_P.HILInitialize_AOChannels, 2U,
        &Jan21Lab1_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }

    if (Jan21Lab1_P.HILInitialize_AOReset) {
      Jan21Lab1_DWork.HILInitialize_AOVoltages[0] =
        Jan21Lab1_P.HILInitialize_AOWatchdog;
      Jan21Lab1_DWork.HILInitialize_AOVoltages[1] =
        Jan21Lab1_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Jan21Lab1_DWork.HILInitialize_Card,
         Jan21Lab1_P.HILInitialize_AOChannels, 2U,
         &Jan21Lab1_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Jan21Lab1_P.HILInitialize_EIPStart && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_EIPEnter && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_QuadratureModes[0] =
        Jan21Lab1_P.HILInitialize_EIQuadrature;
      Jan21Lab1_DWork.HILInitialize_QuadratureModes[1] =
        Jan21Lab1_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Jan21Lab1_DWork.HILInitialize_Card,
         Jan21Lab1_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
         &Jan21Lab1_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }

    if ((Jan21Lab1_P.HILInitialize_EIStart && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_EIEnter && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_InitialEICounts[0] =
        Jan21Lab1_P.HILInitialize_EIInitial;
      Jan21Lab1_DWork.HILInitialize_InitialEICounts[1] =
        Jan21Lab1_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Jan21Lab1_DWork.HILInitialize_Card,
        Jan21Lab1_P.HILInitialize_EIChannels, 2U,
        &Jan21Lab1_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  Jan21Lab1_DWork.Memory_PreviousInput = Jan21Lab1_P.Memory_X0;
}

/* Model terminate function */
void Jan21Lab1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan21Lab1/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Jan21Lab1_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Jan21Lab1_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Jan21Lab1_P.HILInitialize_AOTerminate && !is_switching) ||
        (Jan21Lab1_P.HILInitialize_AOExit && is_switching)) {
      Jan21Lab1_DWork.HILInitialize_AOVoltages[0] =
        Jan21Lab1_P.HILInitialize_AOFinal;
      Jan21Lab1_DWork.HILInitialize_AOVoltages[1] =
        Jan21Lab1_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Jan21Lab1_DWork.HILInitialize_Card,
        Jan21Lab1_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Jan21Lab1_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan21Lab1_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Jan21Lab1_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Jan21Lab1_DWork.HILInitialize_Card);
    hil_close(Jan21Lab1_DWork.HILInitialize_Card);
    Jan21Lab1_DWork.HILInitialize_Card = NULL;
  }
}

/*
 * Feb4SimulinkModel.c
 *
 * Code generation for model "Feb4SimulinkModel".
 *
 * Model version              : 1.25
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Feb 11 11:20:49 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Feb4SimulinkModel.h"
#include "Feb4SimulinkModel_private.h"
#include "Feb4SimulinkModel_dt.h"

/* Block signals (auto storage) */
BlockIO_Feb4SimulinkModel Feb4SimulinkModel_B;

/* Block states (auto storage) */
D_Work_Feb4SimulinkModel Feb4SimulinkModel_DWork;

/* Real-time model */
RT_MODEL_Feb4SimulinkModel Feb4SimulinkModel_M_;
RT_MODEL_Feb4SimulinkModel *const Feb4SimulinkModel_M = &Feb4SimulinkModel_M_;

/* Model step function */
void Feb4SimulinkModel_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder1;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Feb4SimulinkModel_P.Constant_Value >=
      Feb4SimulinkModel_P.Saturation_UpperSat) {
    rtb_HILReadEncoder1 = Feb4SimulinkModel_P.Saturation_UpperSat;
  } else if (Feb4SimulinkModel_P.Constant_Value <=
             Feb4SimulinkModel_P.Saturation_LowerSat) {
    rtb_HILReadEncoder1 = Feb4SimulinkModel_P.Saturation_LowerSat;
  } else {
    rtb_HILReadEncoder1 = Feb4SimulinkModel_P.Constant_Value;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Feb4SimulinkModel/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Feb4SimulinkModel_DWork.HILInitialize_Card,
      &Feb4SimulinkModel_P.HILWriteAnalog_Channels, 1, &rtb_HILReadEncoder1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Feb4SimulinkModel/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Feb4SimulinkModel_DWork.HILInitialize_Card,
      &Feb4SimulinkModel_P.HILReadEncoder_Channels, 1,
      &Feb4SimulinkModel_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = Feb4SimulinkModel_DWork.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  Feb4SimulinkModel_B.Gain = Feb4SimulinkModel_P.Gain_Gain * rtb_HILReadEncoder1;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: Feb4SimulinkModel/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Feb4SimulinkModel_DWork.HILInitialize_Card,
      &Feb4SimulinkModel_P.HILReadEncoder1_Channels, 1,
      &Feb4SimulinkModel_DWork.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = Feb4SimulinkModel_DWork.HILReadEncoder1_Buffer;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain1'
   */
  Feb4SimulinkModel_B.Sum = Feb4SimulinkModel_P.Gain1_Gain * rtb_HILReadEncoder1
    + Feb4SimulinkModel_P.Constant1_Value;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Feb4SimulinkModel_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Feb4SimulinkModel_M)!=-1) &&
        !((rtmGetTFinal(Feb4SimulinkModel_M)-
           Feb4SimulinkModel_M->Timing.taskTime0) >
          Feb4SimulinkModel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Feb4SimulinkModel_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Feb4SimulinkModel_M)) {
      rtmSetErrorStatus(Feb4SimulinkModel_M, "Simulation finished");
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
  if (!(++Feb4SimulinkModel_M->Timing.clockTick0)) {
    ++Feb4SimulinkModel_M->Timing.clockTickH0;
  }

  Feb4SimulinkModel_M->Timing.taskTime0 = Feb4SimulinkModel_M->Timing.clockTick0
    * Feb4SimulinkModel_M->Timing.stepSize0 +
    Feb4SimulinkModel_M->Timing.clockTickH0 *
    Feb4SimulinkModel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Feb4SimulinkModel_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Feb4SimulinkModel_M, 0,
                sizeof(RT_MODEL_Feb4SimulinkModel));
  rtmSetTFinal(Feb4SimulinkModel_M, -1);
  Feb4SimulinkModel_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Feb4SimulinkModel_M->Sizes.checksums[0] = (1245903295U);
  Feb4SimulinkModel_M->Sizes.checksums[1] = (630493744U);
  Feb4SimulinkModel_M->Sizes.checksums[2] = (2806973917U);
  Feb4SimulinkModel_M->Sizes.checksums[3] = (4278490302U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Feb4SimulinkModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Feb4SimulinkModel_M->extModeInfo,
      &Feb4SimulinkModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Feb4SimulinkModel_M->extModeInfo,
                        Feb4SimulinkModel_M->Sizes.checksums);
    rteiSetTPtr(Feb4SimulinkModel_M->extModeInfo, rtmGetTPtr(Feb4SimulinkModel_M));
  }

  /* block I/O */
  (void) memset(((void *) &Feb4SimulinkModel_B), 0,
                sizeof(BlockIO_Feb4SimulinkModel));

  /* states (dwork) */
  (void) memset((void *)&Feb4SimulinkModel_DWork, 0,
                sizeof(D_Work_Feb4SimulinkModel));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Feb4SimulinkModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Feb4SimulinkModel/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &Feb4SimulinkModel_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Feb4SimulinkModel_DWork.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Feb4SimulinkModel_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
      return;
    }

    if ((Feb4SimulinkModel_P.HILInitialize_AIPStart && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_AIPEnter && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_AIMinimums[0] =
        Feb4SimulinkModel_P.HILInitialize_AILow;
      Feb4SimulinkModel_DWork.HILInitialize_AIMinimums[1] =
        Feb4SimulinkModel_P.HILInitialize_AILow;
      Feb4SimulinkModel_DWork.HILInitialize_AIMaximums[0] =
        Feb4SimulinkModel_P.HILInitialize_AIHigh;
      Feb4SimulinkModel_DWork.HILInitialize_AIMaximums[1] =
        Feb4SimulinkModel_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Feb4SimulinkModel_DWork.HILInitialize_Card,
         Feb4SimulinkModel_P.HILInitialize_AIChannels, 2U,
         &Feb4SimulinkModel_DWork.HILInitialize_AIMinimums[0],
         &Feb4SimulinkModel_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }

    if ((Feb4SimulinkModel_P.HILInitialize_AOPStart && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_AOPEnter && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_AOMinimums[0] =
        Feb4SimulinkModel_P.HILInitialize_AOLow;
      Feb4SimulinkModel_DWork.HILInitialize_AOMinimums[1] =
        Feb4SimulinkModel_P.HILInitialize_AOLow;
      Feb4SimulinkModel_DWork.HILInitialize_AOMaximums[0] =
        Feb4SimulinkModel_P.HILInitialize_AOHigh;
      Feb4SimulinkModel_DWork.HILInitialize_AOMaximums[1] =
        Feb4SimulinkModel_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Feb4SimulinkModel_DWork.HILInitialize_Card,
         Feb4SimulinkModel_P.HILInitialize_AOChannels, 2U,
         &Feb4SimulinkModel_DWork.HILInitialize_AOMinimums[0],
         &Feb4SimulinkModel_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }

    if ((Feb4SimulinkModel_P.HILInitialize_AOStart && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_AOEnter && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0] =
        Feb4SimulinkModel_P.HILInitialize_AOInitial;
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[1] =
        Feb4SimulinkModel_P.HILInitialize_AOInitial;
      result = hil_write_analog(Feb4SimulinkModel_DWork.HILInitialize_Card,
        Feb4SimulinkModel_P.HILInitialize_AOChannels, 2U,
        &Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }

    if (Feb4SimulinkModel_P.HILInitialize_AOReset) {
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0] =
        Feb4SimulinkModel_P.HILInitialize_AOWatchdog;
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[1] =
        Feb4SimulinkModel_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Feb4SimulinkModel_DWork.HILInitialize_Card,
         Feb4SimulinkModel_P.HILInitialize_AOChannels, 2U,
         &Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }

    if ((Feb4SimulinkModel_P.HILInitialize_EIPStart && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_EIPEnter && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_QuadratureModes[0] =
        Feb4SimulinkModel_P.HILInitialize_EIQuadrature;
      Feb4SimulinkModel_DWork.HILInitialize_QuadratureModes[1] =
        Feb4SimulinkModel_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Feb4SimulinkModel_DWork.HILInitialize_Card,
         Feb4SimulinkModel_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Feb4SimulinkModel_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }

    if ((Feb4SimulinkModel_P.HILInitialize_EIStart && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_EIEnter && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_InitialEICounts[0] =
        Feb4SimulinkModel_P.HILInitialize_EIInitial;
      Feb4SimulinkModel_DWork.HILInitialize_InitialEICounts[1] =
        Feb4SimulinkModel_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Feb4SimulinkModel_DWork.HILInitialize_Card,
        Feb4SimulinkModel_P.HILInitialize_EIChannels, 2U,
        &Feb4SimulinkModel_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Feb4SimulinkModel_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Feb4SimulinkModel/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Feb4SimulinkModel_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Feb4SimulinkModel_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Feb4SimulinkModel_P.HILInitialize_AOTerminate && !is_switching) ||
        (Feb4SimulinkModel_P.HILInitialize_AOExit && is_switching)) {
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0] =
        Feb4SimulinkModel_P.HILInitialize_AOFinal;
      Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[1] =
        Feb4SimulinkModel_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Feb4SimulinkModel_DWork.HILInitialize_Card,
        Feb4SimulinkModel_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Feb4SimulinkModel_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Feb4SimulinkModel_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Feb4SimulinkModel_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Feb4SimulinkModel_DWork.HILInitialize_Card);
    hil_close(Feb4SimulinkModel_DWork.HILInitialize_Card);
    Feb4SimulinkModel_DWork.HILInitialize_Card = NULL;
  }
}

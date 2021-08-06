/*
 * Joint_data_collector.c
 *
 * Code generation for model "Joint_data_collector".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Feb 25 11:54:19 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Joint_data_collector.h"
#include "Joint_data_collector_private.h"
#include "Joint_data_collector_dt.h"

/* Block signals (auto storage) */
BlockIO_Joint_data_collector Joint_data_collector_B;

/* Block states (auto storage) */
D_Work_Joint_data_collector Joint_data_collector_DWork;

/* Real-time model */
RT_MODEL_Joint_data_collector Joint_data_collector_M_;
RT_MODEL_Joint_data_collector *const Joint_data_collector_M =
  &Joint_data_collector_M_;

/* Model step function */
void Joint_data_collector_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder1;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Joint_data_collector/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (Joint_data_collector_DWork.HILInitialize_Card,
       &Joint_data_collector_P.HILReadEncoder_Channels, 1,
       &Joint_data_collector_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = Joint_data_collector_DWork.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  Joint_data_collector_B.Gain = Joint_data_collector_P.Gain_Gain *
    rtb_HILReadEncoder1;

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder1' */

  /* S-Function Block: Joint_data_collector/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (Joint_data_collector_DWork.HILInitialize_Card,
       &Joint_data_collector_P.HILReadEncoder1_Channels, 1,
       &Joint_data_collector_DWork.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder1 = Joint_data_collector_DWork.HILReadEncoder1_Buffer;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain1'
   */
  Joint_data_collector_B.Sum = Joint_data_collector_P.Gain1_Gain *
    rtb_HILReadEncoder1 + Joint_data_collector_P.Constant1_Value;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Joint_data_collector_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Joint_data_collector_M)!=-1) &&
        !((rtmGetTFinal(Joint_data_collector_M)-
           Joint_data_collector_M->Timing.taskTime0) >
          Joint_data_collector_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Joint_data_collector_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Joint_data_collector_M)) {
      rtmSetErrorStatus(Joint_data_collector_M, "Simulation finished");
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
  if (!(++Joint_data_collector_M->Timing.clockTick0)) {
    ++Joint_data_collector_M->Timing.clockTickH0;
  }

  Joint_data_collector_M->Timing.taskTime0 =
    Joint_data_collector_M->Timing.clockTick0 *
    Joint_data_collector_M->Timing.stepSize0 +
    Joint_data_collector_M->Timing.clockTickH0 *
    Joint_data_collector_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Joint_data_collector_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Joint_data_collector_M, 0,
                sizeof(RT_MODEL_Joint_data_collector));
  rtmSetTFinal(Joint_data_collector_M, -1);
  Joint_data_collector_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Joint_data_collector_M->Sizes.checksums[0] = (1117916495U);
  Joint_data_collector_M->Sizes.checksums[1] = (4220791337U);
  Joint_data_collector_M->Sizes.checksums[2] = (3065448256U);
  Joint_data_collector_M->Sizes.checksums[3] = (3753094550U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Joint_data_collector_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Joint_data_collector_M->extModeInfo,
      &Joint_data_collector_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Joint_data_collector_M->extModeInfo,
                        Joint_data_collector_M->Sizes.checksums);
    rteiSetTPtr(Joint_data_collector_M->extModeInfo, rtmGetTPtr
                (Joint_data_collector_M));
  }

  /* block I/O */
  (void) memset(((void *) &Joint_data_collector_B), 0,
                sizeof(BlockIO_Joint_data_collector));

  /* states (dwork) */
  (void) memset((void *)&Joint_data_collector_DWork, 0,
                sizeof(D_Work_Joint_data_collector));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Joint_data_collector_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Joint_data_collector/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &Joint_data_collector_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Joint_data_collector_DWork.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Joint_data_collector_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
      return;
    }

    if ((Joint_data_collector_P.HILInitialize_AIPStart && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_AIPEnter && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_AIMinimums[0] =
        Joint_data_collector_P.HILInitialize_AILow;
      Joint_data_collector_DWork.HILInitialize_AIMinimums[1] =
        Joint_data_collector_P.HILInitialize_AILow;
      Joint_data_collector_DWork.HILInitialize_AIMaximums[0] =
        Joint_data_collector_P.HILInitialize_AIHigh;
      Joint_data_collector_DWork.HILInitialize_AIMaximums[1] =
        Joint_data_collector_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Joint_data_collector_DWork.HILInitialize_Card,
         Joint_data_collector_P.HILInitialize_AIChannels, 2U,
         &Joint_data_collector_DWork.HILInitialize_AIMinimums[0],
         &Joint_data_collector_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_data_collector_P.HILInitialize_AOPStart && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_AOPEnter && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_AOMinimums[0] =
        Joint_data_collector_P.HILInitialize_AOLow;
      Joint_data_collector_DWork.HILInitialize_AOMinimums[1] =
        Joint_data_collector_P.HILInitialize_AOLow;
      Joint_data_collector_DWork.HILInitialize_AOMaximums[0] =
        Joint_data_collector_P.HILInitialize_AOHigh;
      Joint_data_collector_DWork.HILInitialize_AOMaximums[1] =
        Joint_data_collector_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Joint_data_collector_DWork.HILInitialize_Card,
         Joint_data_collector_P.HILInitialize_AOChannels, 2U,
         &Joint_data_collector_DWork.HILInitialize_AOMinimums[0],
         &Joint_data_collector_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_data_collector_P.HILInitialize_AOStart && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_AOEnter && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_AOVoltages[0] =
        Joint_data_collector_P.HILInitialize_AOInitial;
      Joint_data_collector_DWork.HILInitialize_AOVoltages[1] =
        Joint_data_collector_P.HILInitialize_AOInitial;
      result = hil_write_analog(Joint_data_collector_DWork.HILInitialize_Card,
        Joint_data_collector_P.HILInitialize_AOChannels, 2U,
        &Joint_data_collector_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }

    if (Joint_data_collector_P.HILInitialize_AOReset) {
      Joint_data_collector_DWork.HILInitialize_AOVoltages[0] =
        Joint_data_collector_P.HILInitialize_AOWatchdog;
      Joint_data_collector_DWork.HILInitialize_AOVoltages[1] =
        Joint_data_collector_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Joint_data_collector_DWork.HILInitialize_Card,
         Joint_data_collector_P.HILInitialize_AOChannels, 2U,
         &Joint_data_collector_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_data_collector_P.HILInitialize_EIPStart && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_EIPEnter && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_QuadratureModes[0] =
        Joint_data_collector_P.HILInitialize_EIQuadrature;
      Joint_data_collector_DWork.HILInitialize_QuadratureModes[1] =
        Joint_data_collector_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Joint_data_collector_DWork.HILInitialize_Card,
         Joint_data_collector_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Joint_data_collector_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_data_collector_P.HILInitialize_EIStart && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_EIEnter && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_InitialEICounts[0] =
        Joint_data_collector_P.HILInitialize_EIInitial;
      Joint_data_collector_DWork.HILInitialize_InitialEICounts[1] =
        Joint_data_collector_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (Joint_data_collector_DWork.HILInitialize_Card,
         Joint_data_collector_P.HILInitialize_EIChannels, 2U,
         &Joint_data_collector_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Joint_data_collector_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Joint_data_collector/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Joint_data_collector_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Joint_data_collector_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Joint_data_collector_P.HILInitialize_AOTerminate && !is_switching) ||
        (Joint_data_collector_P.HILInitialize_AOExit && is_switching)) {
      Joint_data_collector_DWork.HILInitialize_AOVoltages[0] =
        Joint_data_collector_P.HILInitialize_AOFinal;
      Joint_data_collector_DWork.HILInitialize_AOVoltages[1] =
        Joint_data_collector_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Joint_data_collector_DWork.HILInitialize_Card,
        Joint_data_collector_P.HILInitialize_AOChannels,
        num_final_analog_outputs,
        &Joint_data_collector_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_data_collector_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Joint_data_collector_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Joint_data_collector_DWork.HILInitialize_Card);
    hil_close(Joint_data_collector_DWork.HILInitialize_Card);
    Joint_data_collector_DWork.HILInitialize_Card = NULL;
  }
}

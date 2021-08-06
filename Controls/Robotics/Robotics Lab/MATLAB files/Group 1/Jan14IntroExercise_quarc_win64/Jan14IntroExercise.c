/*
 * Jan14IntroExercise.c
 *
 * Code generation for model "Jan14IntroExercise".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Feb 25 11:47:32 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Jan14IntroExercise.h"
#include "Jan14IntroExercise_private.h"
#include "Jan14IntroExercise_dt.h"

/* Block signals (auto storage) */
BlockIO_Jan14IntroExercise Jan14IntroExercise_B;

/* Block states (auto storage) */
D_Work_Jan14IntroExercise Jan14IntroExercise_DWork;

/* Real-time model */
RT_MODEL_Jan14IntroExercise Jan14IntroExercise_M_;
RT_MODEL_Jan14IntroExercise *const Jan14IntroExercise_M = &Jan14IntroExercise_M_;

/* Model step function */
void Jan14IntroExercise_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder;
  real_T DiscreteTransferFcn_tmp;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Jan14IntroExercise/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Jan14IntroExercise_DWork.HILInitialize_Card,
      &Jan14IntroExercise_P.HILWriteAnalog_Channels, 1,
      &Jan14IntroExercise_P.Constant_Value);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Jan14IntroExercise/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (Jan14IntroExercise_DWork.HILInitialize_Card,
       &Jan14IntroExercise_P.HILReadEncoder_Channels, 1,
       &Jan14IntroExercise_DWork.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder = Jan14IntroExercise_DWork.HILReadEncoder_Buffer;
    }
  }

  /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  DiscreteTransferFcn_tmp = (rtb_HILReadEncoder -
    Jan14IntroExercise_P.DiscreteTransferFcn_DenCoef[1] *
    Jan14IntroExercise_DWork.DiscreteTransferFcn_states) /
    Jan14IntroExercise_P.DiscreteTransferFcn_DenCoef[0];

  /* Gain: '<Root>/Gain' incorporates:
   *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
   */
  Jan14IntroExercise_B.Gain = (Jan14IntroExercise_P.DiscreteTransferFcn_NumCoef
    [0] * DiscreteTransferFcn_tmp +
    Jan14IntroExercise_P.DiscreteTransferFcn_NumCoef[1] *
    Jan14IntroExercise_DWork.DiscreteTransferFcn_states) *
    Jan14IntroExercise_P.Gain_Gain;

  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  Jan14IntroExercise_DWork.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, Jan14IntroExercise_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(Jan14IntroExercise_M)!=-1) &&
        !((rtmGetTFinal(Jan14IntroExercise_M)-
           Jan14IntroExercise_M->Timing.taskTime0) >
          Jan14IntroExercise_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Jan14IntroExercise_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Jan14IntroExercise_M)) {
      rtmSetErrorStatus(Jan14IntroExercise_M, "Simulation finished");
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
  if (!(++Jan14IntroExercise_M->Timing.clockTick0)) {
    ++Jan14IntroExercise_M->Timing.clockTickH0;
  }

  Jan14IntroExercise_M->Timing.taskTime0 =
    Jan14IntroExercise_M->Timing.clockTick0 *
    Jan14IntroExercise_M->Timing.stepSize0 +
    Jan14IntroExercise_M->Timing.clockTickH0 *
    Jan14IntroExercise_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Jan14IntroExercise_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Jan14IntroExercise_M, 0,
                sizeof(RT_MODEL_Jan14IntroExercise));
  rtmSetTFinal(Jan14IntroExercise_M, -1);
  Jan14IntroExercise_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Jan14IntroExercise_M->Sizes.checksums[0] = (3955353712U);
  Jan14IntroExercise_M->Sizes.checksums[1] = (3936682191U);
  Jan14IntroExercise_M->Sizes.checksums[2] = (2034607194U);
  Jan14IntroExercise_M->Sizes.checksums[3] = (3265299490U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Jan14IntroExercise_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Jan14IntroExercise_M->extModeInfo,
      &Jan14IntroExercise_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Jan14IntroExercise_M->extModeInfo,
                        Jan14IntroExercise_M->Sizes.checksums);
    rteiSetTPtr(Jan14IntroExercise_M->extModeInfo, rtmGetTPtr
                (Jan14IntroExercise_M));
  }

  /* block I/O */
  (void) memset(((void *) &Jan14IntroExercise_B), 0,
                sizeof(BlockIO_Jan14IntroExercise));

  /* states (dwork) */
  (void) memset((void *)&Jan14IntroExercise_DWork, 0,
                sizeof(D_Work_Jan14IntroExercise));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Jan14IntroExercise_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan14IntroExercise/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &Jan14IntroExercise_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Jan14IntroExercise_DWork.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Jan14IntroExercise_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
      return;
    }

    if ((Jan14IntroExercise_P.HILInitialize_AIPStart && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_AIPEnter && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_AIMinimums[0] =
        Jan14IntroExercise_P.HILInitialize_AILow;
      Jan14IntroExercise_DWork.HILInitialize_AIMinimums[1] =
        Jan14IntroExercise_P.HILInitialize_AILow;
      Jan14IntroExercise_DWork.HILInitialize_AIMaximums[0] =
        Jan14IntroExercise_P.HILInitialize_AIHigh;
      Jan14IntroExercise_DWork.HILInitialize_AIMaximums[1] =
        Jan14IntroExercise_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Jan14IntroExercise_DWork.HILInitialize_Card,
         Jan14IntroExercise_P.HILInitialize_AIChannels, 2U,
         &Jan14IntroExercise_DWork.HILInitialize_AIMinimums[0],
         &Jan14IntroExercise_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }

    if ((Jan14IntroExercise_P.HILInitialize_AOPStart && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_AOPEnter && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_AOMinimums[0] =
        Jan14IntroExercise_P.HILInitialize_AOLow;
      Jan14IntroExercise_DWork.HILInitialize_AOMinimums[1] =
        Jan14IntroExercise_P.HILInitialize_AOLow;
      Jan14IntroExercise_DWork.HILInitialize_AOMaximums[0] =
        Jan14IntroExercise_P.HILInitialize_AOHigh;
      Jan14IntroExercise_DWork.HILInitialize_AOMaximums[1] =
        Jan14IntroExercise_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Jan14IntroExercise_DWork.HILInitialize_Card,
         Jan14IntroExercise_P.HILInitialize_AOChannels, 2U,
         &Jan14IntroExercise_DWork.HILInitialize_AOMinimums[0],
         &Jan14IntroExercise_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }

    if ((Jan14IntroExercise_P.HILInitialize_AOStart && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_AOEnter && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0] =
        Jan14IntroExercise_P.HILInitialize_AOInitial;
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[1] =
        Jan14IntroExercise_P.HILInitialize_AOInitial;
      result = hil_write_analog(Jan14IntroExercise_DWork.HILInitialize_Card,
        Jan14IntroExercise_P.HILInitialize_AOChannels, 2U,
        &Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }

    if (Jan14IntroExercise_P.HILInitialize_AOReset) {
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0] =
        Jan14IntroExercise_P.HILInitialize_AOWatchdog;
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[1] =
        Jan14IntroExercise_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Jan14IntroExercise_DWork.HILInitialize_Card,
         Jan14IntroExercise_P.HILInitialize_AOChannels, 2U,
         &Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }

    if ((Jan14IntroExercise_P.HILInitialize_EIPStart && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_EIPEnter && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_QuadratureModes[0] =
        Jan14IntroExercise_P.HILInitialize_EIQuadrature;
      Jan14IntroExercise_DWork.HILInitialize_QuadratureModes[1] =
        Jan14IntroExercise_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Jan14IntroExercise_DWork.HILInitialize_Card,
         Jan14IntroExercise_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Jan14IntroExercise_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }

    if ((Jan14IntroExercise_P.HILInitialize_EIStart && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_EIEnter && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_InitialEICounts[0] =
        Jan14IntroExercise_P.HILInitialize_EIInitial;
      Jan14IntroExercise_DWork.HILInitialize_InitialEICounts[1] =
        Jan14IntroExercise_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (Jan14IntroExercise_DWork.HILInitialize_Card,
         Jan14IntroExercise_P.HILInitialize_EIChannels, 2U,
         &Jan14IntroExercise_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  Jan14IntroExercise_DWork.DiscreteTransferFcn_states =
    Jan14IntroExercise_P.DiscreteTransferFcn_InitialStat;
}

/* Model terminate function */
void Jan14IntroExercise_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan14IntroExercise/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Jan14IntroExercise_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Jan14IntroExercise_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Jan14IntroExercise_P.HILInitialize_AOTerminate && !is_switching) ||
        (Jan14IntroExercise_P.HILInitialize_AOExit && is_switching)) {
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0] =
        Jan14IntroExercise_P.HILInitialize_AOFinal;
      Jan14IntroExercise_DWork.HILInitialize_AOVoltages[1] =
        Jan14IntroExercise_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Jan14IntroExercise_DWork.HILInitialize_Card,
        Jan14IntroExercise_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Jan14IntroExercise_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan14IntroExercise_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Jan14IntroExercise_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Jan14IntroExercise_DWork.HILInitialize_Card);
    hil_close(Jan14IntroExercise_DWork.HILInitialize_Card);
    Jan14IntroExercise_DWork.HILInitialize_Card = NULL;
  }
}

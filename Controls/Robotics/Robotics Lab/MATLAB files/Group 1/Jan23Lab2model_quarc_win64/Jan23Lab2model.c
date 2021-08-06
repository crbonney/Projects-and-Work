/*
 * Jan23Lab2model.c
 *
 * Code generation for model "Jan23Lab2model".
 *
 * Model version              : 1.19
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Jan 28 11:58:27 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Jan23Lab2model.h"
#include "Jan23Lab2model_private.h"
#include "Jan23Lab2model_dt.h"

/* Block signals (auto storage) */
BlockIO_Jan23Lab2model Jan23Lab2model_B;

/* Continuous states */
ContinuousStates_Jan23Lab2model Jan23Lab2model_X;

/* Block states (auto storage) */
D_Work_Jan23Lab2model Jan23Lab2model_DWork;

/* Real-time model */
RT_MODEL_Jan23Lab2model Jan23Lab2model_M_;
RT_MODEL_Jan23Lab2model *const Jan23Lab2model_M = &Jan23Lab2model_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Jan23Lab2model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Jan23Lab2model_step(void)
{
  /* local block i/o variables */
  real_T rtb_ghostofchristmasfuture;
  real_T rtb_Derivative;
  real_T rtb_HILReadEncoder;
  real_T temp;
  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
    /* set solver stop time */
    if (!(Jan23Lab2model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Jan23Lab2model_M->solverInfo,
                            ((Jan23Lab2model_M->Timing.clockTickH0 + 1) *
        Jan23Lab2model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Jan23Lab2model_M->solverInfo,
                            ((Jan23Lab2model_M->Timing.clockTick0 + 1) *
        Jan23Lab2model_M->Timing.stepSize0 +
        Jan23Lab2model_M->Timing.clockTickH0 *
        Jan23Lab2model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Jan23Lab2model_M)) {
    Jan23Lab2model_M->Timing.t[0] = rtsiGetT(&Jan23Lab2model_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Jan23Lab2model_B.TransferFcn = Jan23Lab2model_P.TransferFcn_C*
    Jan23Lab2model_X.TransferFcn_CSTATE;

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = Jan23Lab2model_P.SignalGenerator_Frequency * Jan23Lab2model_M->
    Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    Jan23Lab2model_B.u = Jan23Lab2model_P.SignalGenerator_Amplitude;
  } else {
    Jan23Lab2model_B.u = -Jan23Lab2model_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Sum: '<Root>/Sum1' */
  Jan23Lab2model_B.e = Jan23Lab2model_B.u - Jan23Lab2model_B.TransferFcn;

  /* Gain: '<Root>/ghost of christmas future' */
  rtb_ghostofchristmasfuture = Jan23Lab2model_P.ghostofchristmasfuture_Gain *
    Jan23Lab2model_B.e;

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = Jan23Lab2model_M->Timing.t[0];
    real_T timeStampA = Jan23Lab2model_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = Jan23Lab2model_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Derivative = (rtb_ghostofchristmasfuture - *lastU++) / deltaT;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/ghost of christmas present'
   *  Integrator: '<Root>/Integrator'
   */
  Jan23Lab2model_B.Sum = (rtb_Derivative + Jan23Lab2model_X.Integrator_CSTATE) +
    Jan23Lab2model_P.ghostofchristmaspresent_Gain * Jan23Lab2model_B.e;

  /* Saturate: '<Root>/Saturation' */
  if (Jan23Lab2model_B.Sum >= Jan23Lab2model_P.Saturation_UpperSat) {
    Jan23Lab2model_B.inputtomotor = Jan23Lab2model_P.Saturation_UpperSat;
  } else if (Jan23Lab2model_B.Sum <= Jan23Lab2model_P.Saturation_LowerSat) {
    Jan23Lab2model_B.inputtomotor = Jan23Lab2model_P.Saturation_LowerSat;
  } else {
    Jan23Lab2model_B.inputtomotor = Jan23Lab2model_B.Sum;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Jan23Lab2model/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Jan23Lab2model_DWork.HILInitialize_Card,
        &Jan23Lab2model_P.HILWriteAnalog_Channels, 1,
        &Jan23Lab2model_B.inputtomotor);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Jan23Lab2model/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Jan23Lab2model_DWork.HILInitialize_Card,
        &Jan23Lab2model_P.HILReadEncoder_Channels, 1,
        &Jan23Lab2model_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = Jan23Lab2model_DWork.HILReadEncoder_Buffer;
      }
    }
  }

  /* Gain: '<Root>/ghost of christmas past' */
  Jan23Lab2model_B.ghostofchristmaspast =
    Jan23Lab2model_P.ghostofchristmaspast_Gain * Jan23Lab2model_B.e;
  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
    /* Gain: '<Root>/to_rads' */
    Jan23Lab2model_B.theta = Jan23Lab2model_P.to_rads_Gain * rtb_HILReadEncoder;
  }

  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA = Jan23Lab2model_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = Jan23Lab2model_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &Jan23Lab2model_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &Jan23Lab2model_DWork.Derivative_RWORK.TimeStampB;
          lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &Jan23Lab2model_DWork.Derivative_RWORK.TimeStampB;
          lastU = &Jan23Lab2model_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = Jan23Lab2model_M->Timing.t[0];
      *lastU++ = rtb_ghostofchristmasfuture;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, Jan23Lab2model_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((Jan23Lab2model_M->Timing.clockTick1+
                            Jan23Lab2model_M->Timing.clockTickH1* 4294967296.0))
                          * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Jan23Lab2model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Jan23Lab2model_M)!=-1) &&
          !((rtmGetTFinal(Jan23Lab2model_M)-
             (((Jan23Lab2model_M->Timing.clockTick1+
                Jan23Lab2model_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((Jan23Lab2model_M->Timing.clockTick1+
               Jan23Lab2model_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(Jan23Lab2model_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Jan23Lab2model_M)) {
        rtmSetErrorStatus(Jan23Lab2model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Jan23Lab2model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Jan23Lab2model_M->Timing.clockTick0)) {
      ++Jan23Lab2model_M->Timing.clockTickH0;
    }

    Jan23Lab2model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Jan23Lab2model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Jan23Lab2model_M->Timing.clockTick1++;
      if (!Jan23Lab2model_M->Timing.clockTick1) {
        Jan23Lab2model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Jan23Lab2model_derivatives(void)
{
  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_Jan23Lab2model *) Jan23Lab2model_M->ModelData.derivs)
      ->TransferFcn_CSTATE = Jan23Lab2model_B.theta;
    ((StateDerivatives_Jan23Lab2model *) Jan23Lab2model_M->ModelData.derivs)
      ->TransferFcn_CSTATE += (Jan23Lab2model_P.TransferFcn_A)*
      Jan23Lab2model_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_Jan23Lab2model *) Jan23Lab2model_M->ModelData.derivs)
    ->Integrator_CSTATE = Jan23Lab2model_B.ghostofchristmaspast;
}

/* Model initialize function */
void Jan23Lab2model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Jan23Lab2model_M, 0,
                sizeof(RT_MODEL_Jan23Lab2model));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Jan23Lab2model_M->solverInfo,
                          &Jan23Lab2model_M->Timing.simTimeStep);
    rtsiSetTPtr(&Jan23Lab2model_M->solverInfo, &rtmGetTPtr(Jan23Lab2model_M));
    rtsiSetStepSizePtr(&Jan23Lab2model_M->solverInfo,
                       &Jan23Lab2model_M->Timing.stepSize0);
    rtsiSetdXPtr(&Jan23Lab2model_M->solverInfo,
                 &Jan23Lab2model_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Jan23Lab2model_M->solverInfo,
                         &Jan23Lab2model_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Jan23Lab2model_M->solverInfo,
      &Jan23Lab2model_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Jan23Lab2model_M->solverInfo, (&rtmGetErrorStatus
      (Jan23Lab2model_M)));
    rtsiSetRTModelPtr(&Jan23Lab2model_M->solverInfo, Jan23Lab2model_M);
  }

  rtsiSetSimTimeStep(&Jan23Lab2model_M->solverInfo, MAJOR_TIME_STEP);
  Jan23Lab2model_M->ModelData.intgData.f[0] = Jan23Lab2model_M->ModelData.odeF[0];
  Jan23Lab2model_M->ModelData.contStates = ((real_T *) &Jan23Lab2model_X);
  rtsiSetSolverData(&Jan23Lab2model_M->solverInfo, (void *)
                    &Jan23Lab2model_M->ModelData.intgData);
  rtsiSetSolverName(&Jan23Lab2model_M->solverInfo,"ode1");
  rtmSetTPtr(Jan23Lab2model_M, &Jan23Lab2model_M->Timing.tArray[0]);
  rtmSetTFinal(Jan23Lab2model_M, -1);
  Jan23Lab2model_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Jan23Lab2model_M->Sizes.checksums[0] = (4010694045U);
  Jan23Lab2model_M->Sizes.checksums[1] = (871875812U);
  Jan23Lab2model_M->Sizes.checksums[2] = (1165629514U);
  Jan23Lab2model_M->Sizes.checksums[3] = (514905443U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Jan23Lab2model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Jan23Lab2model_M->extModeInfo,
      &Jan23Lab2model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Jan23Lab2model_M->extModeInfo,
                        Jan23Lab2model_M->Sizes.checksums);
    rteiSetTPtr(Jan23Lab2model_M->extModeInfo, rtmGetTPtr(Jan23Lab2model_M));
  }

  /* block I/O */
  (void) memset(((void *) &Jan23Lab2model_B), 0,
                sizeof(BlockIO_Jan23Lab2model));

  /* states (continuous) */
  {
    (void) memset((void *)&Jan23Lab2model_X, 0,
                  sizeof(ContinuousStates_Jan23Lab2model));
  }

  /* states (dwork) */
  (void) memset((void *)&Jan23Lab2model_DWork, 0,
                sizeof(D_Work_Jan23Lab2model));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Jan23Lab2model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan23Lab2model/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &Jan23Lab2model_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Jan23Lab2model_DWork.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Jan23Lab2model_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      return;
    }

    if ((Jan23Lab2model_P.HILInitialize_AIPStart && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_AIPEnter && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_AIMinimums[0] =
        Jan23Lab2model_P.HILInitialize_AILow;
      Jan23Lab2model_DWork.HILInitialize_AIMinimums[1] =
        Jan23Lab2model_P.HILInitialize_AILow;
      Jan23Lab2model_DWork.HILInitialize_AIMaximums[0] =
        Jan23Lab2model_P.HILInitialize_AIHigh;
      Jan23Lab2model_DWork.HILInitialize_AIMaximums[1] =
        Jan23Lab2model_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Jan23Lab2model_DWork.HILInitialize_Card,
         Jan23Lab2model_P.HILInitialize_AIChannels, 2U,
         &Jan23Lab2model_DWork.HILInitialize_AIMinimums[0],
         &Jan23Lab2model_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }

    if ((Jan23Lab2model_P.HILInitialize_AOPStart && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_AOPEnter && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_AOMinimums[0] =
        Jan23Lab2model_P.HILInitialize_AOLow;
      Jan23Lab2model_DWork.HILInitialize_AOMinimums[1] =
        Jan23Lab2model_P.HILInitialize_AOLow;
      Jan23Lab2model_DWork.HILInitialize_AOMaximums[0] =
        Jan23Lab2model_P.HILInitialize_AOHigh;
      Jan23Lab2model_DWork.HILInitialize_AOMaximums[1] =
        Jan23Lab2model_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Jan23Lab2model_DWork.HILInitialize_Card,
         Jan23Lab2model_P.HILInitialize_AOChannels, 2U,
         &Jan23Lab2model_DWork.HILInitialize_AOMinimums[0],
         &Jan23Lab2model_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }

    if ((Jan23Lab2model_P.HILInitialize_AOStart && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_AOEnter && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[0] =
        Jan23Lab2model_P.HILInitialize_AOInitial;
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[1] =
        Jan23Lab2model_P.HILInitialize_AOInitial;
      result = hil_write_analog(Jan23Lab2model_DWork.HILInitialize_Card,
        Jan23Lab2model_P.HILInitialize_AOChannels, 2U,
        &Jan23Lab2model_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }

    if (Jan23Lab2model_P.HILInitialize_AOReset) {
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[0] =
        Jan23Lab2model_P.HILInitialize_AOWatchdog;
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[1] =
        Jan23Lab2model_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Jan23Lab2model_DWork.HILInitialize_Card,
         Jan23Lab2model_P.HILInitialize_AOChannels, 2U,
         &Jan23Lab2model_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }

    if ((Jan23Lab2model_P.HILInitialize_EIPStart && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_EIPEnter && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_QuadratureModes[0] =
        Jan23Lab2model_P.HILInitialize_EIQuadrature;
      Jan23Lab2model_DWork.HILInitialize_QuadratureModes[1] =
        Jan23Lab2model_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Jan23Lab2model_DWork.HILInitialize_Card,
         Jan23Lab2model_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Jan23Lab2model_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }

    if ((Jan23Lab2model_P.HILInitialize_EIStart && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_EIEnter && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_InitialEICounts[0] =
        Jan23Lab2model_P.HILInitialize_EIInitial;
      Jan23Lab2model_DWork.HILInitialize_InitialEICounts[1] =
        Jan23Lab2model_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Jan23Lab2model_DWork.HILInitialize_Card,
        Jan23Lab2model_P.HILInitialize_EIChannels, 2U,
        &Jan23Lab2model_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Jan23Lab2model_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Jan23Lab2model_DWork.Derivative_RWORK.TimeStampA = rtInf;
  Jan23Lab2model_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Jan23Lab2model_X.Integrator_CSTATE = Jan23Lab2model_P.Integrator_IC;
}

/* Model terminate function */
void Jan23Lab2model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Jan23Lab2model/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Jan23Lab2model_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Jan23Lab2model_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Jan23Lab2model_P.HILInitialize_AOTerminate && !is_switching) ||
        (Jan23Lab2model_P.HILInitialize_AOExit && is_switching)) {
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[0] =
        Jan23Lab2model_P.HILInitialize_AOFinal;
      Jan23Lab2model_DWork.HILInitialize_AOVoltages[1] =
        Jan23Lab2model_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Jan23Lab2model_DWork.HILInitialize_Card,
        Jan23Lab2model_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Jan23Lab2model_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Jan23Lab2model_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Jan23Lab2model_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Jan23Lab2model_DWork.HILInitialize_Card);
    hil_close(Jan23Lab2model_DWork.HILInitialize_Card);
    Jan23Lab2model_DWork.HILInitialize_Card = NULL;
  }
}

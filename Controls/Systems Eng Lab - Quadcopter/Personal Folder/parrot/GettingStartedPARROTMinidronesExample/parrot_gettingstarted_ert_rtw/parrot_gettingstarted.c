/*
 * parrot_gettingstarted.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "parrot_gettingstarted".
 *
 * Model version              : 1.101
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sun Feb 23 16:59:33 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "parrot_gettingstarted.h"
#include "parrot_gettingstarted_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* External outputs (root outports fed by signals with default storage) */
ExtY_parrot_gettingstarted_T parrot_gettingstarted_Y;

/* Real-time model */
RT_MODEL_parrot_gettingstarte_T parrot_gettingstarted_M_;
RT_MODEL_parrot_gettingstarte_T *const parrot_gettingstarted_M =
  &parrot_gettingstarted_M_;

/* Model step function */
void parrot_gettingstarted_step(void)
{
  int32_T i;
  real_T tmp;
  for (i = 0; i < 4; i++) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     *  Constant: '<S1>/Constant6'
     *  Gain: '<S1>/Gain'
     */
    tmp = (((parrot_gettingstarted_P.MotorMix[i + 4] *
             parrot_gettingstarted_P.Constant3_Value +
             parrot_gettingstarted_P.MotorMix[i] *
             parrot_gettingstarted_P.Constant6_Value) +
            parrot_gettingstarted_P.MotorMix[i + 8] *
            parrot_gettingstarted_P.Constant4_Value) +
           parrot_gettingstarted_P.MotorMix[i + 12] *
           parrot_gettingstarted_P.Constant5_Value) +
      parrot_gettingstarted_P.Constant_Value;

    /* Saturate: '<S1>/Saturation1' */
    if (tmp > parrot_gettingstarted_P.Saturation1_UpperSat) {
      motors_outport[i] = parrot_gettingstarted_P.Saturation1_UpperSat;
    } else if (tmp < parrot_gettingstarted_P.Saturation1_LowerSat) {
      motors_outport[i] = parrot_gettingstarted_P.Saturation1_LowerSat;
    } else {
      motors_outport[i] = (real32_T)tmp;
    }

    /* End of Saturate: '<S1>/Saturation1' */

    /* Outport: '<Root>/Motors' */
    parrot_gettingstarted_Y.Motors[i] = motors_outport[i];
  }

  /* ManualSwitch: '<S1>/Manual Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (parrot_gettingstarted_P.ManualSwitch_CurrentSetting == 1) {
    flag_outport = parrot_gettingstarted_P.Constant2_Value;
  } else {
    flag_outport = parrot_gettingstarted_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch' */

  /* Outport: '<Root>/Flag' */
  parrot_gettingstarted_Y.Flag = flag_outport;

  /* Matfile logging */
  rt_UpdateTXYLogVars(parrot_gettingstarted_M->rtwLogInfo,
                      (&parrot_gettingstarted_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(parrot_gettingstarted_M)!=-1) &&
        !((rtmGetTFinal(parrot_gettingstarted_M)-
           parrot_gettingstarted_M->Timing.taskTime0) >
          parrot_gettingstarted_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(parrot_gettingstarted_M, "Simulation finished");
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
  if (!(++parrot_gettingstarted_M->Timing.clockTick0)) {
    ++parrot_gettingstarted_M->Timing.clockTickH0;
  }

  parrot_gettingstarted_M->Timing.taskTime0 =
    parrot_gettingstarted_M->Timing.clockTick0 *
    parrot_gettingstarted_M->Timing.stepSize0 +
    parrot_gettingstarted_M->Timing.clockTickH0 *
    parrot_gettingstarted_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void parrot_gettingstarted_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)parrot_gettingstarted_M, 0,
                sizeof(RT_MODEL_parrot_gettingstarte_T));
  rtmSetTFinal(parrot_gettingstarted_M, 100.0);
  parrot_gettingstarted_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    parrot_gettingstarted_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(parrot_gettingstarted_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(parrot_gettingstarted_M->rtwLogInfo, (NULL));
    rtliSetLogT(parrot_gettingstarted_M->rtwLogInfo, "tout");
    rtliSetLogX(parrot_gettingstarted_M->rtwLogInfo, "");
    rtliSetLogXFinal(parrot_gettingstarted_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(parrot_gettingstarted_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(parrot_gettingstarted_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(parrot_gettingstarted_M->rtwLogInfo, 0);
    rtliSetLogDecimation(parrot_gettingstarted_M->rtwLogInfo, 1);
    rtliSetLogY(parrot_gettingstarted_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(parrot_gettingstarted_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(parrot_gettingstarted_M->rtwLogInfo, (NULL));
  }

  /* block I/O */

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&parrot_gettingstarted_Y, 0,
                sizeof(ExtY_parrot_gettingstarted_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(parrot_gettingstarted_M->rtwLogInfo, 0.0,
    rtmGetTFinal(parrot_gettingstarted_M),
    parrot_gettingstarted_M->Timing.stepSize0, (&rtmGetErrorStatus
    (parrot_gettingstarted_M)));
}

/* Model terminate function */
void parrot_gettingstarted_terminate(void)
{
  /* (no terminate code required) */
}

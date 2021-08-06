/*
 * physical_dynamics_transfer_model.c
 *
 * Code generation for model "physical_dynamics_transfer_model".
 *
 * Model version              : 1.52
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu Mar 05 12:17:37 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "physical_dynamics_transfer_model.h"
#include "physical_dynamics_transfer_model_private.h"
#include "physical_dynamics_transfer_model_dt.h"

/* Block signals (auto storage) */
BlockIO_physical_dynamics_trans physical_dynamics_transfer_mo_B;

/* Continuous states */
ContinuousStates_physical_dynam physical_dynamics_transfer_mo_X;

/* Block states (auto storage) */
D_Work_physical_dynamics_transf physical_dynamics_transfe_DWork;

/* Real-time model */
RT_MODEL_physical_dynamics_tran physical_dynamics_transfer_m_M_;
RT_MODEL_physical_dynamics_tran *const physical_dynamics_transfer_m_M =
  &physical_dynamics_transfer_m_M_;

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
  physical_dynamics_transfer_model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void physical_dynamics_transfer_model_step(void)
{
  /* local block i/o variables */
  real_T rtb_TransferFcn;
  real_T rtb_TransferFcn1;
  real_T rtb_Saturation;
  real_T HoldSine;
  if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
    /* set solver stop time */
    if (!(physical_dynamics_transfer_m_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&physical_dynamics_transfer_m_M->solverInfo,
                            ((physical_dynamics_transfer_m_M->Timing.clockTickH0
        + 1) * physical_dynamics_transfer_m_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&physical_dynamics_transfer_m_M->solverInfo,
                            ((physical_dynamics_transfer_m_M->Timing.clockTick0
        + 1) * physical_dynamics_transfer_m_M->Timing.stepSize0 +
        physical_dynamics_transfer_m_M->Timing.clockTickH0 *
        physical_dynamics_transfer_m_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(physical_dynamics_transfer_m_M)) {
    physical_dynamics_transfer_m_M->Timing.t[0] = rtsiGetT
      (&physical_dynamics_transfer_m_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
  }

  /* TransferFcn: '<S3>/Transfer Fcn' */
  rtb_TransferFcn = physical_dynamics_transfer_mo_P.TransferFcn_C*
    physical_dynamics_transfer_mo_X.TransferFcn_CSTATE;

  /* Derivative: '<S3>/Derivative' */
  {
    real_T t = physical_dynamics_transfer_m_M->Timing.t[0];
    real_T timeStampA =
      physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB =
      physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastU =
      &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      physical_dynamics_transfer_mo_B.dq1 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      physical_dynamics_transfer_mo_B.dq1 = (rtb_TransferFcn - *lastU++) /
        deltaT;
    }
  }

  /* TransferFcn: '<S3>/Transfer Fcn1' */
  rtb_TransferFcn1 = physical_dynamics_transfer_mo_P.TransferFcn1_C*
    physical_dynamics_transfer_mo_X.TransferFcn1_CSTATE;

  /* Derivative: '<S3>/Derivative1' */
  {
    real_T t = physical_dynamics_transfer_m_M->Timing.t[0];
    real_T timeStampA =
      physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB =
      physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampB;
    real_T *lastU =
      &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      physical_dynamics_transfer_mo_B.dq2 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU =
            &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      physical_dynamics_transfer_mo_B.dq2 = (rtb_TransferFcn1 - *lastU++) /
        deltaT;
    }
  }

  if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
    /* S-Function (hil_read_encoder_block): '<S3>/HIL Read Encoder' */

    /* S-Function Block: physical_dynamics_transfer_model/Physical System/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         &physical_dynamics_transfer_mo_P.HILReadEncoder_Channels, 1,
         &physical_dynamics_transfe_DWork.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      } else {
        rtb_Saturation = physical_dynamics_transfe_DWork.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<S3>/Gain' */
    physical_dynamics_transfer_mo_B.q1 =
      physical_dynamics_transfer_mo_P.Gain_Gain * rtb_Saturation;

    /* S-Function (hil_read_encoder_block): '<S3>/HIL Read Encoder1' */

    /* S-Function Block: physical_dynamics_transfer_model/Physical System/HIL Read Encoder1 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         &physical_dynamics_transfer_mo_P.HILReadEncoder1_Channels, 1,
         &physical_dynamics_transfe_DWork.HILReadEncoder1_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      } else {
        rtb_Saturation = physical_dynamics_transfe_DWork.HILReadEncoder1_Buffer;
      }
    }

    /* Gain: '<S3>/Gain1' */
    physical_dynamics_transfer_mo_B.Gain1 =
      physical_dynamics_transfer_mo_P.Gain1_Gain * rtb_Saturation;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    physical_dynamics_transfer_mo_B.q2 = physical_dynamics_transfer_mo_B.Gain1 +
      physical_dynamics_transfer_mo_P.Constant1_Value;

    /* Sin: '<Root>/Sine Wave1' */
    if (physical_dynamics_transfe_DWork.systemEnable != 0) {
      physical_dynamics_transfe_DWork.lastSin = sin
        (physical_dynamics_transfer_mo_P.SineWave1_Freq *
         (((physical_dynamics_transfer_m_M->Timing.clockTick1+
            physical_dynamics_transfer_m_M->Timing.clockTickH1* 4294967296.0)) *
          0.002));
      physical_dynamics_transfe_DWork.lastCos = cos
        (physical_dynamics_transfer_mo_P.SineWave1_Freq *
         (((physical_dynamics_transfer_m_M->Timing.clockTick1+
            physical_dynamics_transfer_m_M->Timing.clockTickH1* 4294967296.0)) *
          0.002));
      physical_dynamics_transfe_DWork.systemEnable = 0;
    }

    rtb_Saturation = ((physical_dynamics_transfe_DWork.lastSin *
                       physical_dynamics_transfer_mo_P.SineWave1_PCos +
                       physical_dynamics_transfe_DWork.lastCos *
                       physical_dynamics_transfer_mo_P.SineWave1_PSin) *
                      physical_dynamics_transfer_mo_P.SineWave1_HCos +
                      (physical_dynamics_transfe_DWork.lastCos *
                       physical_dynamics_transfer_mo_P.SineWave1_PCos -
                       physical_dynamics_transfe_DWork.lastSin *
                       physical_dynamics_transfer_mo_P.SineWave1_PSin) *
                      physical_dynamics_transfer_mo_P.SineWave1_Hsin) *
      physical_dynamics_transfer_mo_P.SineWave1_Amp +
      physical_dynamics_transfer_mo_P.SineWave1_Bias;

    /* End of Sin: '<Root>/Sine Wave1' */

    /* Sin: '<Root>/Sine Wave2' */
    if (physical_dynamics_transfe_DWork.systemEnable_d != 0) {
      physical_dynamics_transfe_DWork.lastSin_j = sin
        (physical_dynamics_transfer_mo_P.SineWave2_Freq *
         (((physical_dynamics_transfer_m_M->Timing.clockTick1+
            physical_dynamics_transfer_m_M->Timing.clockTickH1* 4294967296.0)) *
          0.002));
      physical_dynamics_transfe_DWork.lastCos_p = cos
        (physical_dynamics_transfer_mo_P.SineWave2_Freq *
         (((physical_dynamics_transfer_m_M->Timing.clockTick1+
            physical_dynamics_transfer_m_M->Timing.clockTickH1* 4294967296.0)) *
          0.002));
      physical_dynamics_transfe_DWork.systemEnable_d = 0;
    }

    /* Sum: '<Root>/Sum' incorporates:
     *  Sin: '<Root>/Sine Wave2'
     */
    rtb_Saturation += ((physical_dynamics_transfe_DWork.lastSin_j *
                        physical_dynamics_transfer_mo_P.SineWave2_PCos +
                        physical_dynamics_transfe_DWork.lastCos_p *
                        physical_dynamics_transfer_mo_P.SineWave2_PSin) *
                       physical_dynamics_transfer_mo_P.SineWave2_HCos +
                       (physical_dynamics_transfe_DWork.lastCos_p *
                        physical_dynamics_transfer_mo_P.SineWave2_PCos -
                        physical_dynamics_transfe_DWork.lastSin_j *
                        physical_dynamics_transfer_mo_P.SineWave2_PSin) *
                       physical_dynamics_transfer_mo_P.SineWave2_Hsin) *
      physical_dynamics_transfer_mo_P.SineWave2_Amp +
      physical_dynamics_transfer_mo_P.SineWave2_Bias;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_Saturation >= physical_dynamics_transfer_mo_P.Saturation_UpperSat) {
      rtb_Saturation = physical_dynamics_transfer_mo_P.Saturation_UpperSat;
    } else {
      if (rtb_Saturation <= physical_dynamics_transfer_mo_P.Saturation_LowerSat)
      {
        rtb_Saturation = physical_dynamics_transfer_mo_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: physical_dynamics_transfer_model/Physical System/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         &physical_dynamics_transfer_mo_P.HILWriteAnalog_Channels, 1,
         &rtb_Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      }
    }

    /* Gain: '<S3>/Gain2' */
    physical_dynamics_transfer_mo_B.Gain2 =
      physical_dynamics_transfer_mo_P.Gain2_Gain * rtb_Saturation;
  }

  if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
    /* Update for Derivative: '<S3>/Derivative' */
    {
      real_T timeStampA =
        physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB =
        physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampB;
      real_T* lastTime =
        &physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampA;
      real_T* lastU =
        &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime =
            &physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampB;
          lastU = &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime =
            &physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampB;
          lastU = &physical_dynamics_transfe_DWork.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = physical_dynamics_transfer_m_M->Timing.t[0];
      *lastU++ = rtb_TransferFcn;
    }

    /* Update for Derivative: '<S3>/Derivative1' */
    {
      real_T timeStampA =
        physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampA;
      real_T timeStampB =
        physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampB;
      real_T* lastTime =
        &physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampA;
      real_T* lastU =
        &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime =
            &physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampB;
          lastU =
            &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime =
            &physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampB;
          lastU =
            &physical_dynamics_transfe_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = physical_dynamics_transfer_m_M->Timing.t[0];
      *lastU++ = rtb_TransferFcn1;
    }

    if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
      /* Update for Sin: '<Root>/Sine Wave1' */
      HoldSine = physical_dynamics_transfe_DWork.lastSin;
      physical_dynamics_transfe_DWork.lastSin =
        physical_dynamics_transfe_DWork.lastSin *
        physical_dynamics_transfer_mo_P.SineWave1_HCos +
        physical_dynamics_transfe_DWork.lastCos *
        physical_dynamics_transfer_mo_P.SineWave1_Hsin;
      physical_dynamics_transfe_DWork.lastCos =
        physical_dynamics_transfe_DWork.lastCos *
        physical_dynamics_transfer_mo_P.SineWave1_HCos - HoldSine *
        physical_dynamics_transfer_mo_P.SineWave1_Hsin;

      /* Update for Sin: '<Root>/Sine Wave2' */
      HoldSine = physical_dynamics_transfe_DWork.lastSin_j;
      physical_dynamics_transfe_DWork.lastSin_j =
        physical_dynamics_transfe_DWork.lastSin_j *
        physical_dynamics_transfer_mo_P.SineWave2_HCos +
        physical_dynamics_transfe_DWork.lastCos_p *
        physical_dynamics_transfer_mo_P.SineWave2_Hsin;
      physical_dynamics_transfe_DWork.lastCos_p =
        physical_dynamics_transfe_DWork.lastCos_p *
        physical_dynamics_transfer_mo_P.SineWave2_HCos - HoldSine *
        physical_dynamics_transfer_mo_P.SineWave2_Hsin;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, physical_dynamics_transfer_m_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((physical_dynamics_transfer_m_M->Timing.clockTick1+
                            physical_dynamics_transfer_m_M->Timing.clockTickH1*
                            4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(physical_dynamics_transfer_m_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(physical_dynamics_transfer_m_M)!=-1) &&
          !((rtmGetTFinal(physical_dynamics_transfer_m_M)-
             (((physical_dynamics_transfer_m_M->Timing.clockTick1+
                physical_dynamics_transfer_m_M->Timing.clockTickH1* 4294967296.0))
              * 0.002)) > (((physical_dynamics_transfer_m_M->Timing.clockTick1+
                             physical_dynamics_transfer_m_M->Timing.clockTickH1*
              4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, "Simulation finished");
      }

      if (rtmGetStopRequested(physical_dynamics_transfer_m_M)) {
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&physical_dynamics_transfer_m_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++physical_dynamics_transfer_m_M->Timing.clockTick0)) {
      ++physical_dynamics_transfer_m_M->Timing.clockTickH0;
    }

    physical_dynamics_transfer_m_M->Timing.t[0] = rtsiGetSolverStopTime
      (&physical_dynamics_transfer_m_M->solverInfo);

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
      physical_dynamics_transfer_m_M->Timing.clockTick1++;
      if (!physical_dynamics_transfer_m_M->Timing.clockTick1) {
        physical_dynamics_transfer_m_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void physical_dynamics_transfer_model_derivatives(void)
{
  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  {
    ((StateDerivatives_physical_dynam *)
      physical_dynamics_transfer_m_M->ModelData.derivs)->TransferFcn_CSTATE =
      physical_dynamics_transfer_mo_B.q1;
    ((StateDerivatives_physical_dynam *)
      physical_dynamics_transfer_m_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (physical_dynamics_transfer_mo_P.TransferFcn_A)*
      physical_dynamics_transfer_mo_X.TransferFcn_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' */
  {
    ((StateDerivatives_physical_dynam *)
      physical_dynamics_transfer_m_M->ModelData.derivs)->TransferFcn1_CSTATE =
      physical_dynamics_transfer_mo_B.Gain1;
    ((StateDerivatives_physical_dynam *)
      physical_dynamics_transfer_m_M->ModelData.derivs)->TransferFcn1_CSTATE +=
      (physical_dynamics_transfer_mo_P.TransferFcn1_A)*
      physical_dynamics_transfer_mo_X.TransferFcn1_CSTATE;
  }
}

/* Model initialize function */
void physical_dynamics_transfer_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)physical_dynamics_transfer_m_M, 0,
                sizeof(RT_MODEL_physical_dynamics_tran));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&physical_dynamics_transfer_m_M->solverInfo,
                          &physical_dynamics_transfer_m_M->Timing.simTimeStep);
    rtsiSetTPtr(&physical_dynamics_transfer_m_M->solverInfo, &rtmGetTPtr
                (physical_dynamics_transfer_m_M));
    rtsiSetStepSizePtr(&physical_dynamics_transfer_m_M->solverInfo,
                       &physical_dynamics_transfer_m_M->Timing.stepSize0);
    rtsiSetdXPtr(&physical_dynamics_transfer_m_M->solverInfo,
                 &physical_dynamics_transfer_m_M->ModelData.derivs);
    rtsiSetContStatesPtr(&physical_dynamics_transfer_m_M->solverInfo,
                         &physical_dynamics_transfer_m_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&physical_dynamics_transfer_m_M->solverInfo,
      &physical_dynamics_transfer_m_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&physical_dynamics_transfer_m_M->solverInfo,
                          (&rtmGetErrorStatus(physical_dynamics_transfer_m_M)));
    rtsiSetRTModelPtr(&physical_dynamics_transfer_m_M->solverInfo,
                      physical_dynamics_transfer_m_M);
  }

  rtsiSetSimTimeStep(&physical_dynamics_transfer_m_M->solverInfo,
                     MAJOR_TIME_STEP);
  physical_dynamics_transfer_m_M->ModelData.intgData.f[0] =
    physical_dynamics_transfer_m_M->ModelData.odeF[0];
  physical_dynamics_transfer_m_M->ModelData.contStates = ((real_T *)
    &physical_dynamics_transfer_mo_X);
  rtsiSetSolverData(&physical_dynamics_transfer_m_M->solverInfo, (void *)
                    &physical_dynamics_transfer_m_M->ModelData.intgData);
  rtsiSetSolverName(&physical_dynamics_transfer_m_M->solverInfo,"ode1");
  rtmSetTPtr(physical_dynamics_transfer_m_M,
             &physical_dynamics_transfer_m_M->Timing.tArray[0]);
  rtmSetTFinal(physical_dynamics_transfer_m_M, 10.0);
  physical_dynamics_transfer_m_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  physical_dynamics_transfer_m_M->Sizes.checksums[0] = (321867131U);
  physical_dynamics_transfer_m_M->Sizes.checksums[1] = (3931537316U);
  physical_dynamics_transfer_m_M->Sizes.checksums[2] = (2171480614U);
  physical_dynamics_transfer_m_M->Sizes.checksums[3] = (2099522798U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    physical_dynamics_transfer_m_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(physical_dynamics_transfer_m_M->extModeInfo,
      &physical_dynamics_transfer_m_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(physical_dynamics_transfer_m_M->extModeInfo,
                        physical_dynamics_transfer_m_M->Sizes.checksums);
    rteiSetTPtr(physical_dynamics_transfer_m_M->extModeInfo, rtmGetTPtr
                (physical_dynamics_transfer_m_M));
  }

  /* block I/O */
  (void) memset(((void *) &physical_dynamics_transfer_mo_B), 0,
                sizeof(BlockIO_physical_dynamics_trans));

  /* states (continuous) */
  {
    (void) memset((void *)&physical_dynamics_transfer_mo_X, 0,
                  sizeof(ContinuousStates_physical_dynam));
  }

  /* states (dwork) */
  (void) memset((void *)&physical_dynamics_transfe_DWork, 0,
                sizeof(D_Work_physical_dynamics_transf));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    physical_dynamics_transfer_m_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: physical_dynamics_transfer_model/Physical System/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &physical_dynamics_transfe_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (physical_dynamics_transfe_DWork.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (physical_dynamics_transfe_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      return;
    }

    if ((physical_dynamics_transfer_mo_P.HILInitialize_AIPStart && !is_switching)
        || (physical_dynamics_transfer_mo_P.HILInitialize_AIPEnter &&
            is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_AIMinimums[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AILow;
      physical_dynamics_transfe_DWork.HILInitialize_AIMinimums[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AILow;
      physical_dynamics_transfe_DWork.HILInitialize_AIMaximums[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AIHigh;
      physical_dynamics_transfe_DWork.HILInitialize_AIMaximums[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_AIChannels, 2U,
         &physical_dynamics_transfe_DWork.HILInitialize_AIMinimums[0],
         &physical_dynamics_transfe_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }

    if ((physical_dynamics_transfer_mo_P.HILInitialize_AOPStart && !is_switching)
        || (physical_dynamics_transfer_mo_P.HILInitialize_AOPEnter &&
            is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_AOMinimums[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOLow;
      physical_dynamics_transfe_DWork.HILInitialize_AOMinimums[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOLow;
      physical_dynamics_transfe_DWork.HILInitialize_AOMaximums[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOHigh;
      physical_dynamics_transfe_DWork.HILInitialize_AOMaximums[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_AOChannels, 2U,
         &physical_dynamics_transfe_DWork.HILInitialize_AOMinimums[0],
         &physical_dynamics_transfe_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }

    if ((physical_dynamics_transfer_mo_P.HILInitialize_AOStart && !is_switching)
        || (physical_dynamics_transfer_mo_P.HILInitialize_AOEnter &&
            is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOInitial;
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOInitial;
      result = hil_write_analog
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_AOChannels, 2U,
         &physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }

    if (physical_dynamics_transfer_mo_P.HILInitialize_AOReset) {
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOWatchdog;
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_AOChannels, 2U,
         &physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }

    if ((physical_dynamics_transfer_mo_P.HILInitialize_EIPStart && !is_switching)
        || (physical_dynamics_transfer_mo_P.HILInitialize_EIPEnter &&
            is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_QuadratureModes[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_EIQuadrature;
      physical_dynamics_transfe_DWork.HILInitialize_QuadratureModes[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &physical_dynamics_transfe_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }

    if ((physical_dynamics_transfer_mo_P.HILInitialize_EIStart && !is_switching)
        || (physical_dynamics_transfer_mo_P.HILInitialize_EIEnter &&
            is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_InitialEICounts[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_EIInitial;
      physical_dynamics_transfe_DWork.HILInitialize_InitialEICounts[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_EIChannels, 2U,
         &physical_dynamics_transfe_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  physical_dynamics_transfer_mo_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampA = rtInf;
  physical_dynamics_transfe_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
  physical_dynamics_transfer_mo_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<S3>/Derivative1' */
  physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampA = rtInf;
  physical_dynamics_transfe_DWork.Derivative1_RWORK.TimeStampB = rtInf;

  /* Enable for Sin: '<Root>/Sine Wave1' */
  physical_dynamics_transfe_DWork.systemEnable = 1;

  /* Enable for Sin: '<Root>/Sine Wave2' */
  physical_dynamics_transfe_DWork.systemEnable_d = 1;
}

/* Model terminate function */
void physical_dynamics_transfer_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: physical_dynamics_transfer_model/Physical System/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(physical_dynamics_transfe_DWork.HILInitialize_Card);
    hil_monitor_stop_all(physical_dynamics_transfe_DWork.HILInitialize_Card);
    is_switching = false;
    if ((physical_dynamics_transfer_mo_P.HILInitialize_AOTerminate &&
         !is_switching) || (physical_dynamics_transfer_mo_P.HILInitialize_AOExit
         && is_switching)) {
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOFinal;
      physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[1] =
        physical_dynamics_transfer_mo_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog
        (physical_dynamics_transfe_DWork.HILInitialize_Card,
         physical_dynamics_transfer_mo_P.HILInitialize_AOChannels,
         num_final_analog_outputs,
         &physical_dynamics_transfe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(physical_dynamics_transfer_m_M, _rt_error_message);
      }
    }

    hil_task_delete_all(physical_dynamics_transfe_DWork.HILInitialize_Card);
    hil_monitor_delete_all(physical_dynamics_transfe_DWork.HILInitialize_Card);
    hil_close(physical_dynamics_transfe_DWork.HILInitialize_Card);
    physical_dynamics_transfe_DWork.HILInitialize_Card = NULL;
  }
}

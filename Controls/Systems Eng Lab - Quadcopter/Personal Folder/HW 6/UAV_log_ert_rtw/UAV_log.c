/*
 * UAV_log.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UAV_log".
 *
 * Model version              : 1.145
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Mar  5 17:19:07 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UAV_log.h"
#include "UAV_log_private.h"

/* Exported block signals */
CommandBus cmd_inport;                 /* '<Root>/AC cmd' */
SensorsBus sensor_inport;              /* '<Root>/Sensors' */
real32_T motors_outport[4];            /* '<S1>/Saturation1' */
uint8_T flag_outport;                  /* '<S1>/Manual Switch' */

/* Block signals (default storage) */
B_UAV_log_T UAV_log_B;

/* Continuous states */
X_UAV_log_T UAV_log_X;

/* Block states (default storage) */
DW_UAV_log_T UAV_log_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_UAV_log_T UAV_log_Y;

/* Real-time model */
RT_MODEL_UAV_log_T UAV_log_M_;
RT_MODEL_UAV_log_T *const UAV_log_M = &UAV_log_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  UAV_log_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  UAV_log_step();
  UAV_log_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  UAV_log_step();
  UAV_log_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void UAV_log_step(void)
{
  real_T rtb_ue;
  real_T rtb_ve;
  real_T rtb_phie;
  real_T rtb_thetae;
  real_T rtb_az;
  int32_T i;
  real_T rtb_zwe_idx_1;
  real_T rtb_zwe_idx_0;
  if (rtmIsMajorTimeStep(UAV_log_M)) {
    /* set solver stop time */
    if (!(UAV_log_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&UAV_log_M->solverInfo,
                            ((UAV_log_M->Timing.clockTickH0 + 1) *
        UAV_log_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&UAV_log_M->solverInfo,
                            ((UAV_log_M->Timing.clockTick0 + 1) *
        UAV_log_M->Timing.stepSize0 + UAV_log_M->Timing.clockTickH0 *
        UAV_log_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(UAV_log_M)) {
    UAV_log_M->Timing.t[0] = rtsiGetT(&UAV_log_M->solverInfo);
  }

  /* TransferFcn: '<S3>/Transfer Fcn15' */
  UAV_log_B.p = 0.0;
  UAV_log_B.p += UAV_log_P.TransferFcn15_C * UAV_log_X.TransferFcn15_CSTATE;

  /* TransferFcn: '<S3>/Transfer Fcn16' */
  UAV_log_B.q = 0.0;
  UAV_log_B.q += UAV_log_P.TransferFcn16_C * UAV_log_X.TransferFcn16_CSTATE;

  /* TransferFcn: '<S3>/Transfer Fcn17' */
  UAV_log_B.r = 0.0;
  UAV_log_B.r += UAV_log_P.TransferFcn17_C * UAV_log_X.TransferFcn17_CSTATE;
  if (rtmIsMajorTimeStep(UAV_log_M)) {
    for (i = 0; i < 4; i++) {
      /* Gain: '<S1>/MotorMix' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S1>/Constant3'
       *  Constant: '<S1>/Constant4'
       *  Constant: '<S1>/Constant5'
       */
      rtb_ue = UAV_log_P.MotorMix_Gain[i + 12] * UAV_log_P.Constant_Value +
        (UAV_log_P.MotorMix_Gain[i + 8] * UAV_log_P.Constant3_Value +
         (UAV_log_P.MotorMix_Gain[i + 4] * UAV_log_P.Constant4_Value +
          UAV_log_P.MotorMix_Gain[i] * UAV_log_P.Constant5_Value));

      /* Saturate: '<S1>/Saturation1' */
      if (rtb_ue > UAV_log_P.Saturation1_UpperSat) {
        motors_outport[i] = UAV_log_P.Saturation1_UpperSat;
      } else if (rtb_ue < UAV_log_P.Saturation1_LowerSat) {
        motors_outport[i] = UAV_log_P.Saturation1_LowerSat;
      } else {
        motors_outport[i] = (real32_T)rtb_ue;
      }

      /* End of Saturate: '<S1>/Saturation1' */

      /* Outport: '<Root>/Motors' */
      UAV_log_Y.Motors[i] = motors_outport[i];
    }

    /* ManualSwitch: '<S1>/Manual Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     */
    if (UAV_log_P.ManualSwitch_CurrentSetting == 1) {
      flag_outport = UAV_log_P.Constant2_Value;
    } else {
      flag_outport = UAV_log_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S1>/Manual Switch' */

    /* Outport: '<Root>/Flag' */
    UAV_log_Y.Flag = flag_outport;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
    rtb_ue = UAV_log_DW.DiscreteTimeIntegrator1_DSTATE;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
    rtb_ve = UAV_log_DW.DiscreteTimeIntegrator2_DSTATE;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator5' */
    rtb_zwe_idx_0 = UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[0];
    rtb_zwe_idx_1 = UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[1];

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator4' */
    rtb_phie = UAV_log_DW.DiscreteTimeIntegrator4_DSTATE;

    /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
    rtb_thetae = UAV_log_DW.DiscreteTimeIntegrator3_DSTATE;

    /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator3'
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator4'
     */
    UAV_log_B.TmpSignalConversionAtToWork[0] = rtb_ue;
    UAV_log_B.TmpSignalConversionAtToWork[1] = rtb_ve;
    UAV_log_B.TmpSignalConversionAtToWork[2] = rtb_zwe_idx_1;
    UAV_log_B.TmpSignalConversionAtToWork[3] = rtb_zwe_idx_0;
    UAV_log_B.TmpSignalConversionAtToWork[4] = UAV_log_B.p;
    UAV_log_B.TmpSignalConversionAtToWork[5] = UAV_log_B.q;
    UAV_log_B.TmpSignalConversionAtToWork[6] = UAV_log_B.r;
    UAV_log_B.TmpSignalConversionAtToWork[7] =
      UAV_log_DW.DiscreteTimeIntegrator4_DSTATE;
    UAV_log_B.TmpSignalConversionAtToWork[8] =
      UAV_log_DW.DiscreteTimeIntegrator3_DSTATE;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((UAV_log_M->Timing.clockTick1+
                          UAV_log_M->Timing.clockTickH1* 4294967296.0)) * 0.005);
      ;
      if (rtmIsMajorTimeStep(UAV_log_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              UAV_log_DW.ToWorkspace_PWORK.LoggedData, &locTime,
                              &UAV_log_B.TmpSignalConversionAtToWork[0]);
      }
    }

    /* Gain: '<S2>/Ax' */
    UAV_log_B.Aue = UAV_log_P.A_single * rtb_ue;

    /* Gain: '<S2>/Ax1' */
    UAV_log_B.Aue_k = UAV_log_P.A_single * rtb_ve;

    /* Gain: '<S2>/Ax2' */
    UAV_log_B.Athetae = UAV_log_P.A_single * rtb_thetae;

    /* Gain: '<S2>/Ax3' */
    UAV_log_B.Aphie = UAV_log_P.A_single * rtb_phie;

    /* Gain: '<S2>/Ax4' */
    UAV_log_B.Azwe[0] = 0.0;
    UAV_log_B.Azwe[0] += UAV_log_P.A_double[0] * rtb_zwe_idx_0;
    UAV_log_B.Azwe[0] += UAV_log_P.A_double[2] * rtb_zwe_idx_1;
    UAV_log_B.Azwe[1] = 0.0;
    UAV_log_B.Azwe[1] += UAV_log_P.A_double[1] * rtb_zwe_idx_0;
    UAV_log_B.Azwe[1] += UAV_log_P.A_double[3] * rtb_zwe_idx_1;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.r_g = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* DataTypeConversion: '<S1>/Data Type Conversion11' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.V = sensor_inport.HALSensors.HAL_vbat_SI.vbat_V;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.p_l = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.q_d = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.h = sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.v = sensor_inport.VisionSensors.opticalFlow_data[1];

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.u = sensor_inport.VisionSensors.opticalFlow_data[0];

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.ax = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.ay = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion9' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.az = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* TransferFcn: '<S3>/Transfer Fcn13' */
  UAV_log_B.ay_m = UAV_log_P.TransferFcn13_C * UAV_log_X.TransferFcn13_CSTATE;

  /* TransferFcn: '<S3>/Transfer Fcn14' */
  rtb_az = UAV_log_P.TransferFcn14_C * UAV_log_X.TransferFcn14_CSTATE;
  if (rtmIsMajorTimeStep(UAV_log_M)) {
    /* Gain: '<S2>/Cx' */
    UAV_log_B.Cue = UAV_log_P.C_single * rtb_ue;

    /* Gain: '<S2>/Cx1' */
    UAV_log_B.Cue_i = UAV_log_P.C_single * rtb_ve;

    /* Gain: '<S2>/Cx2' */
    UAV_log_B.Cthetae = UAV_log_P.C_single * rtb_thetae;

    /* Gain: '<S2>/Cx3' */
    UAV_log_B.Cthetae_j = UAV_log_P.C_single * rtb_phie;

    /* Gain: '<S2>/Cx4' */
    UAV_log_B.Czwe = UAV_log_P.C_double[0] * rtb_zwe_idx_0 + UAV_log_P.C_double
      [1] * rtb_zwe_idx_1;
  }

  /* TransferFcn: '<S3>/Transfer Fcn12' */
  rtb_phie = UAV_log_P.TransferFcn12_C * UAV_log_X.TransferFcn12_CSTATE;

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  DotProduct: '<S2>/Dot Product'
   *  SignalConversion generated from: '<S2>/Vector Concatenate'
   * */
  rtb_thetae = sqrt(UAV_log_B.ay_m * UAV_log_B.ay_m + rtb_az * rtb_az);

  /* Sum: '<S2>/Sum8' incorporates:
   *  Gain: '<S2>/Dax4'
   *  Gain: '<S2>/Gain1'
   *  TransferFcn: '<S3>/Transfer Fcn18'
   */
  rtb_ue = (UAV_log_P.TransferFcn18_C * UAV_log_X.TransferFcn18_CSTATE *
            UAV_log_P.Gain1_Gain - UAV_log_P.D_double * rtb_az) - UAV_log_B.Czwe;

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Dax'
   *  Gain: '<S2>/L(y-Cx-Du)'
   *  Gain: '<S2>/gain'
   *  Sum: '<S2>/Sum10'
   *  TransferFcn: '<S3>/Transfer Fcn10'
   */
  UAV_log_B.Sum = ((UAV_log_P.TransferFcn10_C * UAV_log_X.TransferFcn10_CSTATE -
                    UAV_log_P.D_single * rtb_phie) - UAV_log_B.Cue) *
    UAV_log_P.L_single + (UAV_log_P.B_single * rtb_phie + UAV_log_B.Aue);

  /* Sum: '<S2>/Sum1' incorporates:
   *  Gain: '<S2>/Dax1'
   *  Gain: '<S2>/L(y-Cx-Du)1'
   *  Gain: '<S2>/gain1'
   *  Sum: '<S2>/Sum2'
   *  TransferFcn: '<S3>/Transfer Fcn11'
   */
  UAV_log_B.Sum1 = ((UAV_log_P.TransferFcn11_C * UAV_log_X.TransferFcn11_CSTATE
                     - UAV_log_P.D_single * UAV_log_B.ay_m) - UAV_log_B.Cue_i) *
    UAV_log_P.L_single + (UAV_log_P.B_single * UAV_log_B.ay_m + UAV_log_B.Aue_k);

  /* Saturate: '<S2>/Saturation' */
  if (rtb_thetae > UAV_log_P.Saturation_UpperSat) {
    rtb_thetae = UAV_log_P.Saturation_UpperSat;
  } else {
    if (rtb_thetae < UAV_log_P.Saturation_LowerSat) {
      rtb_thetae = UAV_log_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Sum: '<S2>/Sum3' incorporates:
   *  Gain: '<S2>/Dax2'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/L(y-Cx-Du)2'
   *  Gain: '<S2>/gain2'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Sum4'
   */
  UAV_log_B.Sum3 = ((rtb_phie / rtb_thetae * UAV_log_P.Gain_Gain -
                     UAV_log_P.D_single * UAV_log_B.q) - UAV_log_B.Cthetae) *
    UAV_log_P.L_single + (UAV_log_P.B_single * UAV_log_B.q + UAV_log_B.Athetae);

  /* Sum: '<S2>/Sum5' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Dax3'
   *  Gain: '<S2>/L(y-Cx-Du)3'
   *  Gain: '<S2>/gain3'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Sum6'
   *  Sum: '<S2>/Sum9'
   */
  UAV_log_B.Sum5 = ((UAV_log_B.ay_m / (rtb_az + UAV_log_P.Constant_Value_n) -
                     UAV_log_P.D_single * UAV_log_B.p) - UAV_log_B.Cthetae_j) *
    UAV_log_P.L_single + (UAV_log_P.B_single * UAV_log_B.p + UAV_log_B.Aphie);

  /* Sum: '<S2>/Sum7' incorporates:
   *  Gain: '<S2>/L(y-Cx-Du)4'
   *  Gain: '<S2>/gain4'
   */
  UAV_log_B.Sum7[0] = (UAV_log_P.B_double[0] * rtb_az + UAV_log_B.Azwe[0]) +
    UAV_log_P.L_double[0] * rtb_ue;
  UAV_log_B.Sum7[1] = (UAV_log_P.B_double[1] * rtb_az + UAV_log_B.Azwe[1]) +
    UAV_log_P.L_double[1] * rtb_ue;
  if (rtmIsMajorTimeStep(UAV_log_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(UAV_log_M->rtwLogInfo, (UAV_log_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(UAV_log_M)) {
    if (rtmIsMajorTimeStep(UAV_log_M)) {
      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
      UAV_log_DW.DiscreteTimeIntegrator1_DSTATE +=
        UAV_log_P.DiscreteTimeIntegrator1_gainval * UAV_log_B.Sum;

      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
      UAV_log_DW.DiscreteTimeIntegrator2_DSTATE +=
        UAV_log_P.DiscreteTimeIntegrator2_gainval * UAV_log_B.Sum1;

      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator5' */
      UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
        UAV_log_P.DiscreteTimeIntegrator5_gainval * UAV_log_B.Sum7[0];
      UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
        UAV_log_P.DiscreteTimeIntegrator5_gainval * UAV_log_B.Sum7[1];

      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator4' */
      UAV_log_DW.DiscreteTimeIntegrator4_DSTATE +=
        UAV_log_P.DiscreteTimeIntegrator4_gainval * UAV_log_B.Sum5;

      /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
      UAV_log_DW.DiscreteTimeIntegrator3_DSTATE +=
        UAV_log_P.DiscreteTimeIntegrator3_gainval * UAV_log_B.Sum3;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(UAV_log_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(UAV_log_M)!=-1) &&
          !((rtmGetTFinal(UAV_log_M)-(((UAV_log_M->Timing.clockTick1+
               UAV_log_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((UAV_log_M->Timing.clockTick1+UAV_log_M->Timing.clockTickH1*
               4294967296.0)) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(UAV_log_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&UAV_log_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++UAV_log_M->Timing.clockTick0)) {
      ++UAV_log_M->Timing.clockTickH0;
    }

    UAV_log_M->Timing.t[0] = rtsiGetSolverStopTime(&UAV_log_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      UAV_log_M->Timing.clockTick1++;
      if (!UAV_log_M->Timing.clockTick1) {
        UAV_log_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void UAV_log_derivatives(void)
{
  XDot_UAV_log_T *_rtXdot;
  _rtXdot = ((XDot_UAV_log_T *) UAV_log_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn15' */
  _rtXdot->TransferFcn15_CSTATE = 0.0;
  _rtXdot->TransferFcn15_CSTATE += UAV_log_P.TransferFcn15_A *
    UAV_log_X.TransferFcn15_CSTATE;
  _rtXdot->TransferFcn15_CSTATE += UAV_log_B.p_l;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn16' */
  _rtXdot->TransferFcn16_CSTATE = 0.0;
  _rtXdot->TransferFcn16_CSTATE += UAV_log_P.TransferFcn16_A *
    UAV_log_X.TransferFcn16_CSTATE;
  _rtXdot->TransferFcn16_CSTATE += UAV_log_B.q_d;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn17' */
  _rtXdot->TransferFcn17_CSTATE = 0.0;
  _rtXdot->TransferFcn17_CSTATE += UAV_log_P.TransferFcn17_A *
    UAV_log_X.TransferFcn17_CSTATE;
  _rtXdot->TransferFcn17_CSTATE += UAV_log_B.r_g;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn13' */
  _rtXdot->TransferFcn13_CSTATE = 0.0;
  _rtXdot->TransferFcn13_CSTATE += UAV_log_P.TransferFcn13_A *
    UAV_log_X.TransferFcn13_CSTATE;
  _rtXdot->TransferFcn13_CSTATE += UAV_log_B.ay;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn14' */
  _rtXdot->TransferFcn14_CSTATE = 0.0;
  _rtXdot->TransferFcn14_CSTATE += UAV_log_P.TransferFcn14_A *
    UAV_log_X.TransferFcn14_CSTATE;
  _rtXdot->TransferFcn14_CSTATE += UAV_log_B.az;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn12' */
  _rtXdot->TransferFcn12_CSTATE = 0.0;
  _rtXdot->TransferFcn12_CSTATE += UAV_log_P.TransferFcn12_A *
    UAV_log_X.TransferFcn12_CSTATE;
  _rtXdot->TransferFcn12_CSTATE += UAV_log_B.ax;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn18' */
  _rtXdot->TransferFcn18_CSTATE = 0.0;
  _rtXdot->TransferFcn18_CSTATE += UAV_log_P.TransferFcn18_A *
    UAV_log_X.TransferFcn18_CSTATE;
  _rtXdot->TransferFcn18_CSTATE += UAV_log_B.h;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn10' */
  _rtXdot->TransferFcn10_CSTATE = 0.0;
  _rtXdot->TransferFcn10_CSTATE += UAV_log_P.TransferFcn10_A *
    UAV_log_X.TransferFcn10_CSTATE;
  _rtXdot->TransferFcn10_CSTATE += UAV_log_B.u;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn11' */
  _rtXdot->TransferFcn11_CSTATE = 0.0;
  _rtXdot->TransferFcn11_CSTATE += UAV_log_P.TransferFcn11_A *
    UAV_log_X.TransferFcn11_CSTATE;
  _rtXdot->TransferFcn11_CSTATE += UAV_log_B.v;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn19' */
  _rtXdot->TransferFcn19_CSTATE = 0.0;
  _rtXdot->TransferFcn19_CSTATE += UAV_log_P.TransferFcn19_A *
    UAV_log_X.TransferFcn19_CSTATE;
  _rtXdot->TransferFcn19_CSTATE += UAV_log_B.V;
}

/* Model initialize function */
void UAV_log_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  UAV_log_P.Saturation_UpperSat = rtInf;

  /* initialize real-time model */
  (void) memset((void *)UAV_log_M, 0,
                sizeof(RT_MODEL_UAV_log_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&UAV_log_M->solverInfo, &UAV_log_M->Timing.simTimeStep);
    rtsiSetTPtr(&UAV_log_M->solverInfo, &rtmGetTPtr(UAV_log_M));
    rtsiSetStepSizePtr(&UAV_log_M->solverInfo, &UAV_log_M->Timing.stepSize0);
    rtsiSetdXPtr(&UAV_log_M->solverInfo, &UAV_log_M->derivs);
    rtsiSetContStatesPtr(&UAV_log_M->solverInfo, (real_T **)
                         &UAV_log_M->contStates);
    rtsiSetNumContStatesPtr(&UAV_log_M->solverInfo,
      &UAV_log_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&UAV_log_M->solverInfo,
      &UAV_log_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&UAV_log_M->solverInfo,
      &UAV_log_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&UAV_log_M->solverInfo,
      &UAV_log_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&UAV_log_M->solverInfo, (&rtmGetErrorStatus(UAV_log_M)));
    rtsiSetRTModelPtr(&UAV_log_M->solverInfo, UAV_log_M);
  }

  rtsiSetSimTimeStep(&UAV_log_M->solverInfo, MAJOR_TIME_STEP);
  UAV_log_M->intgData.y = UAV_log_M->odeY;
  UAV_log_M->intgData.f[0] = UAV_log_M->odeF[0];
  UAV_log_M->intgData.f[1] = UAV_log_M->odeF[1];
  UAV_log_M->intgData.f[2] = UAV_log_M->odeF[2];
  UAV_log_M->contStates = ((X_UAV_log_T *) &UAV_log_X);
  rtsiSetSolverData(&UAV_log_M->solverInfo, (void *)&UAV_log_M->intgData);
  rtsiSetSolverName(&UAV_log_M->solverInfo,"ode3");
  rtmSetTPtr(UAV_log_M, &UAV_log_M->Timing.tArray[0]);
  rtmSetTFinal(UAV_log_M, 100.0);
  UAV_log_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    UAV_log_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(UAV_log_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(UAV_log_M->rtwLogInfo, (NULL));
    rtliSetLogT(UAV_log_M->rtwLogInfo, "tout");
    rtliSetLogX(UAV_log_M->rtwLogInfo, "");
    rtliSetLogXFinal(UAV_log_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(UAV_log_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(UAV_log_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(UAV_log_M->rtwLogInfo, 0);
    rtliSetLogDecimation(UAV_log_M->rtwLogInfo, 1);
    rtliSetLogY(UAV_log_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(UAV_log_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(UAV_log_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &UAV_log_B), 0,
                sizeof(B_UAV_log_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&UAV_log_X, 0,
                  sizeof(X_UAV_log_T));
  }

  /* states (dwork) */
  (void) memset((void *)&UAV_log_DW, 0,
                sizeof(DW_UAV_log_T));

  /* external inputs */
  (void)memset(&cmd_inport, 0, sizeof(CommandBus));
  (void)memset(&sensor_inport, 0, sizeof(SensorsBus));

  /* external outputs */
  (void) memset((void *)&UAV_log_Y, 0,
                sizeof(ExtY_UAV_log_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(UAV_log_M->rtwLogInfo, 0.0, rtmGetTFinal
    (UAV_log_M), UAV_log_M->Timing.stepSize0, (&rtmGetErrorStatus(UAV_log_M)));

  /* SetupRuntimeResources for ToWorkspace: '<S1>/To Workspace' */
  {
    static int_T rt_ToWksWidths[] = { 9 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 9 };

    static boolean_T rt_ToWksIsVarDims[] = { 0 };

    static void *rt_ToWksCurrSigDims[] = { (NULL) };

    static int_T rt_ToWksCurrSigDimsSize[] = { 4 };

    static BuiltInDTypeId rt_ToWksDataTypeIds[] = { SS_DOUBLE };

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
      "UAV_log/Flight Control System/To Workspace";
    UAV_log_DW.ToWorkspace_PWORK.LoggedData = rt_CreateStructLogVar(
      UAV_log_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(UAV_log_M),
      UAV_log_M->Timing.stepSize0,
      (&rtmGetErrorStatus(UAV_log_M)),
      "simout",
      1,
      0,
      1,
      0.005,
      &rt_ToWksSignalInfo,
      rt_ToWksBlockName);
    if (UAV_log_DW.ToWorkspace_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' */
  UAV_log_DW.DiscreteTimeIntegrator1_DSTATE =
    UAV_log_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
  UAV_log_DW.DiscreteTimeIntegrator2_DSTATE =
    UAV_log_P.DiscreteTimeIntegrator2_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator5' */
  UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[0] =
    UAV_log_P.DiscreteTimeIntegrator5_IC;
  UAV_log_DW.DiscreteTimeIntegrator5_DSTATE[1] =
    UAV_log_P.DiscreteTimeIntegrator5_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn15' */
  UAV_log_X.TransferFcn15_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn16' */
  UAV_log_X.TransferFcn16_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn17' */
  UAV_log_X.TransferFcn17_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator4' */
  UAV_log_DW.DiscreteTimeIntegrator4_DSTATE =
    UAV_log_P.DiscreteTimeIntegrator4_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
  UAV_log_DW.DiscreteTimeIntegrator3_DSTATE =
    UAV_log_P.DiscreteTimeIntegrator3_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn13' */
  UAV_log_X.TransferFcn13_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn14' */
  UAV_log_X.TransferFcn14_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn12' */
  UAV_log_X.TransferFcn12_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn18' */
  UAV_log_X.TransferFcn18_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn10' */
  UAV_log_X.TransferFcn10_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn11' */
  UAV_log_X.TransferFcn11_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn19' */
  UAV_log_X.TransferFcn19_CSTATE = 0.0;
}

/* Model terminate function */
void UAV_log_terminate(void)
{
  /* (no terminate code required) */
}

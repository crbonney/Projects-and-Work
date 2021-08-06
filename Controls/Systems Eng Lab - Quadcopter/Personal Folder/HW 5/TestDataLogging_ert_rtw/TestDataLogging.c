/*
 * TestDataLogging.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TestDataLogging".
 *
 * Model version              : 1.55
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Feb 27 16:25:54 2020
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

/* Block signals (default storage) */
B_TestDataLogging_T TestDataLogging_B;

/* Continuous states */
X_TestDataLogging_T TestDataLogging_X;

/* Block states (default storage) */
DW_TestDataLogging_T TestDataLogging_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TestDataLogging_T TestDataLogging_Y;

/* Real-time model */
RT_MODEL_TestDataLogging_T TestDataLogging_M_;
RT_MODEL_TestDataLogging_T *const TestDataLogging_M = &TestDataLogging_M_;

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
  int_T nXc = 22;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TestDataLogging_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TestDataLogging_step();
  TestDataLogging_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TestDataLogging_step();
  TestDataLogging_derivatives();

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
void TestDataLogging_step(void)
{
  int32_T i;
  real_T tmp;
  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* set solver stop time */
    if (!(TestDataLogging_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TestDataLogging_M->solverInfo,
                            ((TestDataLogging_M->Timing.clockTickH0 + 1) *
        TestDataLogging_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TestDataLogging_M->solverInfo,
                            ((TestDataLogging_M->Timing.clockTick0 + 1) *
        TestDataLogging_M->Timing.stepSize0 +
        TestDataLogging_M->Timing.clockTickH0 *
        TestDataLogging_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TestDataLogging_M)) {
    TestDataLogging_M->Timing.t[0] = rtsiGetT(&TestDataLogging_M->solverInfo);
  }

  /* TransferFcn: '<S1>/Transfer Fcn' */
  TestDataLogging_B.u = 0.0;
  TestDataLogging_B.u += TestDataLogging_P.TransferFcn_C *
    TestDataLogging_X.TransferFcn_CSTATE;

  /* Integrator: '<S1>/Integrator' */
  TestDataLogging_B.X = TestDataLogging_X.Integrator_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn1' */
  TestDataLogging_B.v = 0.0;
  TestDataLogging_B.v += TestDataLogging_P.TransferFcn1_C *
    TestDataLogging_X.TransferFcn1_CSTATE;

  /* Integrator: '<S1>/Integrator1' */
  TestDataLogging_B.Y = TestDataLogging_X.Integrator1_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn2' */
  TestDataLogging_B.ax = 0.0;
  TestDataLogging_B.ax += TestDataLogging_P.TransferFcn2_C *
    TestDataLogging_X.TransferFcn2_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn3' */
  TestDataLogging_B.ay = 0.0;
  TestDataLogging_B.ay += TestDataLogging_P.TransferFcn3_C *
    TestDataLogging_X.TransferFcn3_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn4' */
  TestDataLogging_B.az = 0.0;
  TestDataLogging_B.az += TestDataLogging_P.TransferFcn4_C *
    TestDataLogging_X.TransferFcn4_CSTATE;

  /* Integrator: '<S1>/Integrator5' */
  TestDataLogging_B.w = TestDataLogging_X.Integrator5_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn5' */
  TestDataLogging_B.p = 0.0;
  TestDataLogging_B.p += TestDataLogging_P.TransferFcn5_C *
    TestDataLogging_X.TransferFcn5_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  TestDataLogging_B.phi = TestDataLogging_X.Integrator2_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn6' */
  TestDataLogging_B.q = 0.0;
  TestDataLogging_B.q += TestDataLogging_P.TransferFcn6_C *
    TestDataLogging_X.TransferFcn6_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  TestDataLogging_B.theta = TestDataLogging_X.Integrator3_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn7' */
  TestDataLogging_B.r = 0.0;
  TestDataLogging_B.r += TestDataLogging_P.TransferFcn7_C *
    TestDataLogging_X.TransferFcn7_CSTATE;

  /* Integrator: '<S1>/Integrator4' */
  TestDataLogging_B.psi = TestDataLogging_X.Integrator4_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn8' */
  TestDataLogging_B.h = 0.0;
  TestDataLogging_B.h += TestDataLogging_P.TransferFcn8_C *
    TestDataLogging_X.TransferFcn8_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn9' */
  TestDataLogging_B.Vbat = 0.0;
  TestDataLogging_B.Vbat += TestDataLogging_P.TransferFcn9_C *
    TestDataLogging_X.TransferFcn9_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.u_i = sensor_inport.VisionSensors.opticalFlow_data[0];

  /* Integrator: '<S1>/Integrator6' */
  TestDataLogging_B.X_m = TestDataLogging_X.Integrator6_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.v_j = sensor_inport.VisionSensors.opticalFlow_data[1];

  /* Integrator: '<S1>/Integrator7' */
  TestDataLogging_B.Y_m = TestDataLogging_X.Integrator7_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion7' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.ax_m = sensor_inport.HALSensors.HAL_acc_SI.x;

  /* DataTypeConversion: '<S1>/Data Type Conversion8' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.ay_h = sensor_inport.HALSensors.HAL_acc_SI.y;

  /* DataTypeConversion: '<S1>/Data Type Conversion9' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.az_a = sensor_inport.HALSensors.HAL_acc_SI.z;

  /* Integrator: '<S1>/Integrator11' */
  TestDataLogging_B.w_g = TestDataLogging_X.Integrator11_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.p_l = sensor_inport.HALSensors.HAL_gyro_SI.x;

  /* Integrator: '<S1>/Integrator8' */
  TestDataLogging_B.phi_h = TestDataLogging_X.Integrator8_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.q_d = sensor_inport.HALSensors.HAL_gyro_SI.y;

  /* Integrator: '<S1>/Integrator9' */
  TestDataLogging_B.theta_f = TestDataLogging_X.Integrator9_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.r_g = sensor_inport.HALSensors.HAL_gyro_SI.z;

  /* Integrator: '<S1>/Integrator10' */
  TestDataLogging_B.psi_f = TestDataLogging_X.Integrator10_CSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.h_o = sensor_inport.HALSensors.HAL_ultrasound_SI.altitude;

  /* DataTypeConversion: '<S1>/Data Type Conversion11' incorporates:
   *  Inport: '<Root>/Sensors'
   */
  TestDataLogging_B.V = sensor_inport.HALSensors.HAL_vbat_SI.vbat_V;
  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    for (i = 0; i < 4; i++) {
      /* Gain: '<S1>/MotorMix' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S1>/Constant3'
       *  Constant: '<S1>/Constant4'
       *  Constant: '<S1>/Constant5'
       */
      tmp = TestDataLogging_P.MotorMix_Gain[i + 12] *
        TestDataLogging_P.Constant_Value + (TestDataLogging_P.MotorMix_Gain[i +
        8] * TestDataLogging_P.Constant3_Value +
        (TestDataLogging_P.MotorMix_Gain[i + 4] *
         TestDataLogging_P.Constant4_Value + TestDataLogging_P.MotorMix_Gain[i] *
         TestDataLogging_P.Constant5_Value));

      /* Saturate: '<S1>/Saturation1' */
      if (tmp > TestDataLogging_P.Saturation1_UpperSat) {
        motors_outport[i] = TestDataLogging_P.Saturation1_UpperSat;
      } else if (tmp < TestDataLogging_P.Saturation1_LowerSat) {
        motors_outport[i] = TestDataLogging_P.Saturation1_LowerSat;
      } else {
        motors_outport[i] = (real32_T)tmp;
      }

      /* End of Saturate: '<S1>/Saturation1' */

      /* Outport: '<Root>/Motors' */
      TestDataLogging_Y.Motors[i] = motors_outport[i];
    }

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

    /* SignalConversion generated from: '<S1>/To Workspace' */
    TestDataLogging_B.TmpSignalConversionAtToWork[0] = TestDataLogging_B.u;
    TestDataLogging_B.TmpSignalConversionAtToWork[1] = TestDataLogging_B.X;
    TestDataLogging_B.TmpSignalConversionAtToWork[2] = TestDataLogging_B.v;
    TestDataLogging_B.TmpSignalConversionAtToWork[3] = TestDataLogging_B.Y;
    TestDataLogging_B.TmpSignalConversionAtToWork[4] = TestDataLogging_B.ax;
    TestDataLogging_B.TmpSignalConversionAtToWork[5] = TestDataLogging_B.ay;
    TestDataLogging_B.TmpSignalConversionAtToWork[6] = TestDataLogging_B.az;
    TestDataLogging_B.TmpSignalConversionAtToWork[7] = TestDataLogging_B.w;
    TestDataLogging_B.TmpSignalConversionAtToWork[8] = TestDataLogging_B.p;
    TestDataLogging_B.TmpSignalConversionAtToWork[9] = TestDataLogging_B.phi;
    TestDataLogging_B.TmpSignalConversionAtToWork[10] = TestDataLogging_B.q;
    TestDataLogging_B.TmpSignalConversionAtToWork[11] = TestDataLogging_B.theta;
    TestDataLogging_B.TmpSignalConversionAtToWork[12] = TestDataLogging_B.r;
    TestDataLogging_B.TmpSignalConversionAtToWork[13] = TestDataLogging_B.psi;
    TestDataLogging_B.TmpSignalConversionAtToWork[14] = TestDataLogging_B.h;
    TestDataLogging_B.TmpSignalConversionAtToWork[15] = TestDataLogging_B.Vbat;
    TestDataLogging_B.TmpSignalConversionAtToWork[16] = TestDataLogging_B.u_i;
    TestDataLogging_B.TmpSignalConversionAtToWork[17] = TestDataLogging_B.X_m;
    TestDataLogging_B.TmpSignalConversionAtToWork[18] = TestDataLogging_B.v_j;
    TestDataLogging_B.TmpSignalConversionAtToWork[19] = TestDataLogging_B.Y_m;
    TestDataLogging_B.TmpSignalConversionAtToWork[20] = TestDataLogging_B.ax_m;
    TestDataLogging_B.TmpSignalConversionAtToWork[21] = TestDataLogging_B.ay_h;
    TestDataLogging_B.TmpSignalConversionAtToWork[22] = TestDataLogging_B.az_a;
    TestDataLogging_B.TmpSignalConversionAtToWork[23] = TestDataLogging_B.w_g;
    TestDataLogging_B.TmpSignalConversionAtToWork[24] = TestDataLogging_B.p_l;
    TestDataLogging_B.TmpSignalConversionAtToWork[25] = TestDataLogging_B.phi_h;
    TestDataLogging_B.TmpSignalConversionAtToWork[26] = TestDataLogging_B.q_d;
    TestDataLogging_B.TmpSignalConversionAtToWork[27] =
      TestDataLogging_B.theta_f;
    TestDataLogging_B.TmpSignalConversionAtToWork[28] = TestDataLogging_B.r_g;
    TestDataLogging_B.TmpSignalConversionAtToWork[29] = TestDataLogging_B.psi_f;
    TestDataLogging_B.TmpSignalConversionAtToWork[30] = TestDataLogging_B.h_o;
    TestDataLogging_B.TmpSignalConversionAtToWork[31] = TestDataLogging_B.V;

    /* ToWorkspace: '<S1>/To Workspace' */
    {
      double locTime = (((TestDataLogging_M->Timing.clockTick1+
                          TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) *
                        0.005);
      ;
      if (rtmIsMajorTimeStep(TestDataLogging_M)) {
        rt_UpdateStructLogVar((StructLogVar *)
                              TestDataLogging_DW.ToWorkspace_PWORK.LoggedData,
                              &locTime,
                              &TestDataLogging_B.TmpSignalConversionAtToWork[0]);
      }
    }
  }

  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(TestDataLogging_M->rtwLogInfo,
                        (TestDataLogging_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TestDataLogging_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(TestDataLogging_M)!=-1) &&
          !((rtmGetTFinal(TestDataLogging_M)-
             (((TestDataLogging_M->Timing.clockTick1+
                TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005)) >
            (((TestDataLogging_M->Timing.clockTick1+
               TestDataLogging_M->Timing.clockTickH1* 4294967296.0)) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(TestDataLogging_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&TestDataLogging_M->solverInfo);

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

    TestDataLogging_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TestDataLogging_M->solverInfo);

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
      TestDataLogging_M->Timing.clockTick1++;
      if (!TestDataLogging_M->Timing.clockTick1) {
        TestDataLogging_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TestDataLogging_derivatives(void)
{
  XDot_TestDataLogging_T *_rtXdot;
  _rtXdot = ((XDot_TestDataLogging_T *) TestDataLogging_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += TestDataLogging_P.TransferFcn_A *
    TestDataLogging_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += TestDataLogging_B.u_i;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = TestDataLogging_B.u;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += TestDataLogging_P.TransferFcn1_A *
    TestDataLogging_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += TestDataLogging_B.v_j;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = TestDataLogging_B.v;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += TestDataLogging_P.TransferFcn2_A *
    TestDataLogging_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += TestDataLogging_B.ax_m;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += TestDataLogging_P.TransferFcn3_A *
    TestDataLogging_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += TestDataLogging_B.ay_h;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE = 0.0;
  _rtXdot->TransferFcn4_CSTATE += TestDataLogging_P.TransferFcn4_A *
    TestDataLogging_X.TransferFcn4_CSTATE;
  _rtXdot->TransferFcn4_CSTATE += TestDataLogging_B.az_a;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = TestDataLogging_B.az;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn5' */
  _rtXdot->TransferFcn5_CSTATE = 0.0;
  _rtXdot->TransferFcn5_CSTATE += TestDataLogging_P.TransferFcn5_A *
    TestDataLogging_X.TransferFcn5_CSTATE;
  _rtXdot->TransferFcn5_CSTATE += TestDataLogging_B.p_l;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = TestDataLogging_B.p;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn6' */
  _rtXdot->TransferFcn6_CSTATE = 0.0;
  _rtXdot->TransferFcn6_CSTATE += TestDataLogging_P.TransferFcn6_A *
    TestDataLogging_X.TransferFcn6_CSTATE;
  _rtXdot->TransferFcn6_CSTATE += TestDataLogging_B.q_d;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = TestDataLogging_B.q;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn7' */
  _rtXdot->TransferFcn7_CSTATE = 0.0;
  _rtXdot->TransferFcn7_CSTATE += TestDataLogging_P.TransferFcn7_A *
    TestDataLogging_X.TransferFcn7_CSTATE;
  _rtXdot->TransferFcn7_CSTATE += TestDataLogging_B.r_g;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = TestDataLogging_B.r;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn8' */
  _rtXdot->TransferFcn8_CSTATE = 0.0;
  _rtXdot->TransferFcn8_CSTATE += TestDataLogging_P.TransferFcn8_A *
    TestDataLogging_X.TransferFcn8_CSTATE;
  _rtXdot->TransferFcn8_CSTATE += TestDataLogging_B.h_o;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn9' */
  _rtXdot->TransferFcn9_CSTATE = 0.0;
  _rtXdot->TransferFcn9_CSTATE += TestDataLogging_P.TransferFcn9_A *
    TestDataLogging_X.TransferFcn9_CSTATE;
  _rtXdot->TransferFcn9_CSTATE += TestDataLogging_B.V;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = TestDataLogging_B.u_i;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = TestDataLogging_B.v_j;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = TestDataLogging_B.az_a;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = TestDataLogging_B.p_l;

  /* Derivatives for Integrator: '<S1>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = TestDataLogging_B.q_d;

  /* Derivatives for Integrator: '<S1>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = TestDataLogging_B.r_g;
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

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TestDataLogging_M->solverInfo,
                          &TestDataLogging_M->Timing.simTimeStep);
    rtsiSetTPtr(&TestDataLogging_M->solverInfo, &rtmGetTPtr(TestDataLogging_M));
    rtsiSetStepSizePtr(&TestDataLogging_M->solverInfo,
                       &TestDataLogging_M->Timing.stepSize0);
    rtsiSetdXPtr(&TestDataLogging_M->solverInfo, &TestDataLogging_M->derivs);
    rtsiSetContStatesPtr(&TestDataLogging_M->solverInfo, (real_T **)
                         &TestDataLogging_M->contStates);
    rtsiSetNumContStatesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TestDataLogging_M->solverInfo,
      &TestDataLogging_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&TestDataLogging_M->solverInfo, (&rtmGetErrorStatus
      (TestDataLogging_M)));
    rtsiSetRTModelPtr(&TestDataLogging_M->solverInfo, TestDataLogging_M);
  }

  rtsiSetSimTimeStep(&TestDataLogging_M->solverInfo, MAJOR_TIME_STEP);
  TestDataLogging_M->intgData.y = TestDataLogging_M->odeY;
  TestDataLogging_M->intgData.f[0] = TestDataLogging_M->odeF[0];
  TestDataLogging_M->intgData.f[1] = TestDataLogging_M->odeF[1];
  TestDataLogging_M->intgData.f[2] = TestDataLogging_M->odeF[2];
  TestDataLogging_M->contStates = ((X_TestDataLogging_T *) &TestDataLogging_X);
  rtsiSetSolverData(&TestDataLogging_M->solverInfo, (void *)
                    &TestDataLogging_M->intgData);
  rtsiSetSolverName(&TestDataLogging_M->solverInfo,"ode3");
  rtmSetTPtr(TestDataLogging_M, &TestDataLogging_M->Timing.tArray[0]);
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
  (void) memset(((void *) &TestDataLogging_B), 0,
                sizeof(B_TestDataLogging_T));

  /* exported global signals */
  motors_outport[0] = 0.0F;
  motors_outport[1] = 0.0F;
  motors_outport[2] = 0.0F;
  motors_outport[3] = 0.0F;
  flag_outport = 0U;

  /* states (continuous) */
  {
    (void) memset((void *)&TestDataLogging_X, 0,
                  sizeof(X_TestDataLogging_T));
  }

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
    static int_T rt_ToWksWidths[] = { 32 };

    static int_T rt_ToWksNumDimensions[] = { 1 };

    static int_T rt_ToWksDimensions[] = { 32 };

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

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  TestDataLogging_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  TestDataLogging_X.Integrator_CSTATE = TestDataLogging_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
  TestDataLogging_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  TestDataLogging_X.Integrator1_CSTATE = TestDataLogging_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn2' */
  TestDataLogging_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn3' */
  TestDataLogging_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn4' */
  TestDataLogging_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  TestDataLogging_X.Integrator5_CSTATE = TestDataLogging_P.Integrator5_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn5' */
  TestDataLogging_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  TestDataLogging_X.Integrator2_CSTATE = TestDataLogging_P.Integrator2_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn6' */
  TestDataLogging_X.TransferFcn6_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  TestDataLogging_X.Integrator3_CSTATE = TestDataLogging_P.Integrator3_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn7' */
  TestDataLogging_X.TransferFcn7_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  TestDataLogging_X.Integrator4_CSTATE = TestDataLogging_P.Integrator4_IC;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn8' */
  TestDataLogging_X.TransferFcn8_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn9' */
  TestDataLogging_X.TransferFcn9_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  TestDataLogging_X.Integrator6_CSTATE = TestDataLogging_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  TestDataLogging_X.Integrator7_CSTATE = TestDataLogging_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  TestDataLogging_X.Integrator11_CSTATE = TestDataLogging_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  TestDataLogging_X.Integrator8_CSTATE = TestDataLogging_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator9' */
  TestDataLogging_X.Integrator9_CSTATE = TestDataLogging_P.Integrator9_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator10' */
  TestDataLogging_X.Integrator10_CSTATE = TestDataLogging_P.Integrator10_IC;
}

/* Model terminate function */
void TestDataLogging_terminate(void)
{
  /* (no terminate code required) */
}

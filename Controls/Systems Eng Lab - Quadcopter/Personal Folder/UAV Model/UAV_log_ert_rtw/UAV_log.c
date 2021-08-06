/*
 * UAV_log.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UAV_log".
 *
 * Model version              : 1.170
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Mar 13 17:53:49 2020
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

/* Block states (default storage) */
DW_UAV_log_T UAV_log_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_UAV_log_T UAV_log_Y;

/* Real-time model */
RT_MODEL_UAV_log_T UAV_log_M_;
RT_MODEL_UAV_log_T *const UAV_log_M = &UAV_log_M_;

/*
 * System initialize for enable system:
 *    '<S30>/MeasurementUpdate'
 *    '<S82>/MeasurementUpdate'
 *    '<S134>/MeasurementUpdate'
 *    '<S238>/MeasurementUpdate'
 */
void UAV_log_MeasurementUpdate_Init(B_MeasurementUpdate_UAV_log_T *localB,
  P_MeasurementUpdate_UAV_log_T *localP)
{
  /* SystemInitialize for Outport: '<S59>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
}

/*
 * Disable for enable system:
 *    '<S30>/MeasurementUpdate'
 *    '<S82>/MeasurementUpdate'
 *    '<S134>/MeasurementUpdate'
 *    '<S238>/MeasurementUpdate'
 */
void UAV_l_MeasurementUpdate_Disable(B_MeasurementUpdate_UAV_log_T *localB,
  DW_MeasurementUpdate_UAV_log_T *localDW, P_MeasurementUpdate_UAV_log_T *localP)
{
  /* Disable for Outport: '<S59>/L*(y[k]-yhat[k|k-1])' */
  localB->Product3 = localP->Lykyhatkk1_Y0;
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Start for enable system:
 *    '<S30>/MeasurementUpdate'
 *    '<S82>/MeasurementUpdate'
 *    '<S134>/MeasurementUpdate'
 *    '<S238>/MeasurementUpdate'
 */
void UAV_log_MeasurementUpdate_Start(DW_MeasurementUpdate_UAV_log_T *localDW)
{
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S30>/MeasurementUpdate'
 *    '<S82>/MeasurementUpdate'
 *    '<S134>/MeasurementUpdate'
 *    '<S238>/MeasurementUpdate'
 */
void UAV_log_MeasurementUpdate(boolean_T rtu_Enable, real_T rtu_Lk, real_T
  rtu_yk, real_T rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_UAV_log_T *localB, DW_MeasurementUpdate_UAV_log_T *localDW,
  P_MeasurementUpdate_UAV_log_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S30>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Product: '<S59>/Product3' incorporates:
     *  Product: '<S59>/C[k]*xhat[k|k-1]'
     *  Product: '<S59>/D[k]*u[k]'
     *  Sum: '<S59>/Add1'
     *  Sum: '<S59>/Sum'
     */
    localB->Product3 = (rtu_yk - (rtu_Ck * rtu_xhatkk1 + rtu_Dk * rtu_uk)) *
      rtu_Lk;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      UAV_l_MeasurementUpdate_Disable(localB, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S30>/MeasurementUpdate' */
}

/*
 * System initialize for enable system:
 *    '<S37>/Enabled Subsystem'
 *    '<S89>/Enabled Subsystem'
 *    '<S141>/Enabled Subsystem'
 *    '<S245>/Enabled Subsystem'
 */
void UAV_log_EnabledSubsystem_Init(B_EnabledSubsystem_UAV_log_T *localB,
  P_EnabledSubsystem_UAV_log_T *localP)
{
  /* SystemInitialize for Outport: '<S61>/deltax' */
  localB->Product2 = localP->deltax_Y0;
}

/*
 * Disable for enable system:
 *    '<S37>/Enabled Subsystem'
 *    '<S89>/Enabled Subsystem'
 *    '<S141>/Enabled Subsystem'
 *    '<S245>/Enabled Subsystem'
 */
void UAV_lo_EnabledSubsystem_Disable(B_EnabledSubsystem_UAV_log_T *localB,
  DW_EnabledSubsystem_UAV_log_T *localDW, P_EnabledSubsystem_UAV_log_T *localP)
{
  /* Disable for Outport: '<S61>/deltax' */
  localB->Product2 = localP->deltax_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S37>/Enabled Subsystem'
 *    '<S89>/Enabled Subsystem'
 *    '<S141>/Enabled Subsystem'
 *    '<S245>/Enabled Subsystem'
 */
void UAV_log_EnabledSubsystem_Start(DW_EnabledSubsystem_UAV_log_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S37>/Enabled Subsystem'
 *    '<S89>/Enabled Subsystem'
 *    '<S141>/Enabled Subsystem'
 *    '<S245>/Enabled Subsystem'
 */
void UAV_log_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_Mk, real_T rtu_Ck,
  real_T rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_UAV_log_T *localB,
  DW_EnabledSubsystem_UAV_log_T *localDW, P_EnabledSubsystem_UAV_log_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Product: '<S61>/Product2' incorporates:
     *  Product: '<S61>/Product'
     *  Sum: '<S61>/Add1'
     */
    localB->Product2 = (rtu_yk - rtu_Ck * rtu_xhatkk1) * rtu_Mk;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      UAV_lo_EnabledSubsystem_Disable(localB, localDW, localP);
    }
  }

  /* End of Outputs for SubSystem: '<S37>/Enabled Subsystem' */
}

/* Model step function */
void UAV_log_step(void)
{
  real_T DiscreteTransferFcn9_tmp;
  real_T DiscreteTransferFcn3_tmp;
  real_T DiscreteTransferFcn2_tmp;
  real_T DiscreteTransferFcn1_tmp;
  real_T DiscreteTransferFcn5_tmp;
  real_T DiscreteTransferFcn4_tmp;
  real_T DiscreteTransferFcn6_tmp;
  int32_T i;
  for (i = 0; i < 4; i++) {
    /* Gain: '<S1>/MotorMix' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     */
    UAV_log_B.u = UAV_log_P.MotorMix_Gain[i + 12] * UAV_log_P.Constant_Value +
      (UAV_log_P.MotorMix_Gain[i + 8] * UAV_log_P.Constant3_Value +
       (UAV_log_P.MotorMix_Gain[i + 4] * UAV_log_P.Constant4_Value +
        UAV_log_P.MotorMix_Gain[i] * UAV_log_P.Constant5_Value));

    /* Saturate: '<S1>/Saturation1' */
    if (UAV_log_B.u > UAV_log_P.Saturation1_UpperSat) {
      motors_outport[i] = UAV_log_P.Saturation1_UpperSat;
    } else if (UAV_log_B.u < UAV_log_P.Saturation1_LowerSat) {
      motors_outport[i] = UAV_log_P.Saturation1_LowerSat;
    } else {
      motors_outport[i] = (real32_T)UAV_log_B.u;
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

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn8' */
  UAV_log_B.DiscreteTransferFcn8_tmp = (0.0 -
    UAV_log_P.DiscreteTransferFcn8_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn8_states) /
    UAV_log_P.DiscreteTransferFcn8_DenCoef[0];
  UAV_log_B.u = UAV_log_P.DiscreteTransferFcn8_NumCoef[0] *
    UAV_log_B.DiscreteTransferFcn8_tmp + UAV_log_P.DiscreteTransferFcn8_NumCoef
    [1] * UAV_log_DW.DiscreteTransferFcn8_states;

  /* Delay: '<S5>/MemoryX' incorporates:
   *  Constant: '<S5>/X0'
   */
  if (UAV_log_DW.icLoad != 0) {
    UAV_log_DW.MemoryX_DSTATE = UAV_log_P.X0_Value;
  }

  /* Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' */
  /* Constant: '<S5>/Enable' incorporates:
   *  Constant: '<S10>/KalmanGainM'
   *  Constant: '<S5>/C'
   *  Delay: '<S5>/MemoryX'
   */
  UAV_log_EnabledSubsystem(UAV_log_P.Enable_Value, UAV_log_P.KalmanGainM_Value,
    UAV_log_P.C_Value, UAV_log_B.u, UAV_log_DW.MemoryX_DSTATE,
    &UAV_log_B.EnabledSubsystem, &UAV_log_DW.EnabledSubsystem,
    &UAV_log_P.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S37>/Enabled Subsystem' */

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn7' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  Inport: '<Root>/Sensors'
   */
  UAV_log_B.DiscreteTransferFcn7_tmp =
    (sensor_inport.VisionSensors.opticalFlow_data[1] -
     UAV_log_P.DiscreteTransferFcn7_DenCoef[1] *
     UAV_log_DW.DiscreteTransferFcn7_states) /
    UAV_log_P.DiscreteTransferFcn7_DenCoef[0];
  UAV_log_B.v_p = UAV_log_P.DiscreteTransferFcn7_NumCoef[0] *
    UAV_log_B.DiscreteTransferFcn7_tmp + UAV_log_P.DiscreteTransferFcn7_NumCoef
    [1] * UAV_log_DW.DiscreteTransferFcn7_states;

  /* Delay: '<S9>/MemoryX' incorporates:
   *  Constant: '<S9>/X0'
   */
  if (UAV_log_DW.icLoad_i != 0) {
    UAV_log_DW.MemoryX_DSTATE_m = UAV_log_P.X0_Value_g;
  }

  /* Outputs for Enabled SubSystem: '<S245>/Enabled Subsystem' */
  /* Constant: '<S9>/Enable' incorporates:
   *  Constant: '<S218>/KalmanGainM'
   *  Constant: '<S9>/C'
   *  Delay: '<S9>/MemoryX'
   */
  UAV_log_EnabledSubsystem(UAV_log_P.Enable_Value_g,
    UAV_log_P.KalmanGainM_Value_m, UAV_log_P.C_Value_h, UAV_log_B.v_p,
    UAV_log_DW.MemoryX_DSTATE_m, &UAV_log_B.EnabledSubsystem_p,
    &UAV_log_DW.EnabledSubsystem_p, &UAV_log_P.EnabledSubsystem_p);

  /* End of Outputs for SubSystem: '<S245>/Enabled Subsystem' */

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn9' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn9_tmp =
    (sensor_inport.HALSensors.HAL_ultrasound_SI.altitude -
     UAV_log_P.DiscreteTransferFcn9_DenCoef[1] *
     UAV_log_DW.DiscreteTransferFcn9_states) /
    UAV_log_P.DiscreteTransferFcn9_DenCoef[0];

  /* Gain: '<S2>/Gain3' incorporates:
   *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn9'
   */
  UAV_log_B.z = (UAV_log_P.DiscreteTransferFcn9_NumCoef[0] *
                 DiscreteTransferFcn9_tmp +
                 UAV_log_P.DiscreteTransferFcn9_NumCoef[1] *
                 UAV_log_DW.DiscreteTransferFcn9_states) * UAV_log_P.Gain3_Gain;

  /* Delay: '<S8>/MemoryX' incorporates:
   *  Constant: '<S8>/X0'
   */
  if (UAV_log_DW.icLoad_a != 0) {
    UAV_log_DW.MemoryX_DSTATE_i[0] = UAV_log_P.X0_Value_h[0];
    UAV_log_DW.MemoryX_DSTATE_i[1] = UAV_log_P.X0_Value_h[1];
  }

  /* Outputs for Enabled SubSystem: '<S193>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S217>/Enable'
   */
  /* Constant: '<S8>/Enable' */
  if (UAV_log_P.Enable_Value_o) {
    UAV_log_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S217>/Add1' incorporates:
     *  Constant: '<S8>/C'
     *  Delay: '<S8>/MemoryX'
     *  Product: '<S217>/Product'
     */
    UAV_log_B.Akxhatkk1_d = UAV_log_B.z - (UAV_log_P.C_Value_k[0] *
      UAV_log_DW.MemoryX_DSTATE_i[0] + UAV_log_P.C_Value_k[1] *
      UAV_log_DW.MemoryX_DSTATE_i[1]);

    /* Product: '<S217>/Product2' incorporates:
     *  Constant: '<S166>/KalmanGainM'
     */
    UAV_log_B.Product2[0] = UAV_log_P.KalmanGainM_Value_j[0] *
      UAV_log_B.Akxhatkk1_d;
    UAV_log_B.Product2[1] = UAV_log_P.KalmanGainM_Value_j[1] *
      UAV_log_B.Akxhatkk1_d;
  } else {
    if (UAV_log_DW.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S217>/deltax' */
      UAV_log_B.Product2[0] = UAV_log_P.deltax_Y0;
      UAV_log_B.Product2[1] = UAV_log_P.deltax_Y0;
      UAV_log_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S193>/Enabled Subsystem' */

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn3' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn3_tmp = (sensor_inport.HALSensors.HAL_gyro_SI.x -
    UAV_log_P.DiscreteTransferFcn3_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn3_states) /
    UAV_log_P.DiscreteTransferFcn3_DenCoef[0];

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn2_tmp = (sensor_inport.HALSensors.HAL_gyro_SI.y -
    UAV_log_P.DiscreteTransferFcn2_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn2_states) /
    UAV_log_P.DiscreteTransferFcn2_DenCoef[0];
  UAV_log_B.q_h = UAV_log_P.DiscreteTransferFcn2_NumCoef[0] *
    DiscreteTransferFcn2_tmp + UAV_log_P.DiscreteTransferFcn2_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn2_states;

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn1_tmp = (sensor_inport.HALSensors.HAL_gyro_SI.z -
    UAV_log_P.DiscreteTransferFcn1_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn1_states) /
    UAV_log_P.DiscreteTransferFcn1_DenCoef[0];

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn5' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion8'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn5_tmp = (sensor_inport.HALSensors.HAL_acc_SI.y -
    UAV_log_P.DiscreteTransferFcn5_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn5_states) /
    UAV_log_P.DiscreteTransferFcn5_DenCoef[0];
  UAV_log_B.ay_b = UAV_log_P.DiscreteTransferFcn5_NumCoef[0] *
    DiscreteTransferFcn5_tmp + UAV_log_P.DiscreteTransferFcn5_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn5_states;

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn4' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn4_tmp = (sensor_inport.HALSensors.HAL_acc_SI.z -
    UAV_log_P.DiscreteTransferFcn4_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn4_states) /
    UAV_log_P.DiscreteTransferFcn4_DenCoef[0];
  UAV_log_B.Bkuk_i = UAV_log_P.DiscreteTransferFcn4_NumCoef[0] *
    DiscreteTransferFcn4_tmp + UAV_log_P.DiscreteTransferFcn4_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn4_states;

  /* Product: '<S2>/Product3' */
  UAV_log_B.Akxhatkk1_d = UAV_log_B.ay_b / UAV_log_B.Bkuk_i;

  /* Delay: '<S7>/MemoryX' incorporates:
   *  Constant: '<S7>/X0'
   */
  if (UAV_log_DW.icLoad_e != 0) {
    UAV_log_DW.MemoryX_DSTATE_n = UAV_log_P.X0_Value_i;
  }

  /* Outputs for Enabled SubSystem: '<S141>/Enabled Subsystem' */
  /* Constant: '<S7>/Enable' incorporates:
   *  Constant: '<S114>/KalmanGainM'
   *  Constant: '<S7>/C'
   *  Delay: '<S7>/MemoryX'
   */
  UAV_log_EnabledSubsystem(UAV_log_P.Enable_Value_i,
    UAV_log_P.KalmanGainM_Value_h, UAV_log_P.C_Value_m, UAV_log_B.Akxhatkk1_d,
    UAV_log_DW.MemoryX_DSTATE_n, &UAV_log_B.EnabledSubsystem_c,
    &UAV_log_DW.EnabledSubsystem_c, &UAV_log_P.EnabledSubsystem_c);

  /* End of Outputs for SubSystem: '<S141>/Enabled Subsystem' */

  /* DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn6' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Sensors'
   */
  DiscreteTransferFcn6_tmp = (sensor_inport.HALSensors.HAL_acc_SI.x -
    UAV_log_P.DiscreteTransferFcn6_DenCoef[1] *
    UAV_log_DW.DiscreteTransferFcn6_states) /
    UAV_log_P.DiscreteTransferFcn6_DenCoef[0];
  UAV_log_B.ax_b = UAV_log_P.DiscreteTransferFcn6_NumCoef[0] *
    DiscreteTransferFcn6_tmp + UAV_log_P.DiscreteTransferFcn6_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn6_states;

  /* Gain: '<S2>/Gain2' incorporates:
   *  DotProduct: '<S2>/Dot Product1'
   *  Product: '<S2>/Product2'
   *  SignalConversion generated from: '<S2>/Vector Concatenate1'
   *  Sqrt: '<S2>/Sqrt1'
   * */
  UAV_log_B.theta = UAV_log_B.ax_b / sqrt(UAV_log_B.ay_b * UAV_log_B.ay_b +
    UAV_log_B.Bkuk_i * UAV_log_B.Bkuk_i) * UAV_log_P.Gain2_Gain;

  /* Delay: '<S6>/MemoryX' incorporates:
   *  Constant: '<S6>/X0'
   */
  if (UAV_log_DW.icLoad_j != 0) {
    UAV_log_DW.MemoryX_DSTATE_p = UAV_log_P.X0_Value_o;
  }

  /* Outputs for Enabled SubSystem: '<S89>/Enabled Subsystem' */
  /* Constant: '<S6>/Enable' incorporates:
   *  Constant: '<S62>/KalmanGainM'
   *  Constant: '<S6>/C'
   *  Delay: '<S6>/MemoryX'
   */
  UAV_log_EnabledSubsystem(UAV_log_P.Enable_Value_gt,
    UAV_log_P.KalmanGainM_Value_h0, UAV_log_P.C_Value_ko, UAV_log_B.theta,
    UAV_log_DW.MemoryX_DSTATE_p, &UAV_log_B.EnabledSubsystem_a,
    &UAV_log_DW.EnabledSubsystem_a, &UAV_log_P.EnabledSubsystem_a);

  /* End of Outputs for SubSystem: '<S89>/Enabled Subsystem' */

  /* SignalConversion generated from: '<S1>/To Workspace' incorporates:
   *  Delay: '<S5>/MemoryX'
   *  Delay: '<S6>/MemoryX'
   *  Delay: '<S7>/MemoryX'
   *  Delay: '<S8>/MemoryX'
   *  Delay: '<S9>/MemoryX'
   *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
   *  DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn3'
   *  Sum: '<S141>/Add'
   *  Sum: '<S193>/Add'
   *  Sum: '<S245>/Add'
   *  Sum: '<S37>/Add'
   *  Sum: '<S89>/Add'
   */
  UAV_log_B.TmpSignalConversionAtToWork[0] = UAV_log_B.EnabledSubsystem.Product2
    + UAV_log_DW.MemoryX_DSTATE;
  UAV_log_B.TmpSignalConversionAtToWork[1] =
    UAV_log_B.EnabledSubsystem_p.Product2 + UAV_log_DW.MemoryX_DSTATE_m;
  UAV_log_B.TmpSignalConversionAtToWork[2] = UAV_log_B.Product2[1] +
    UAV_log_DW.MemoryX_DSTATE_i[1];
  UAV_log_B.TmpSignalConversionAtToWork[3] = UAV_log_B.Product2[0] +
    UAV_log_DW.MemoryX_DSTATE_i[0];
  UAV_log_B.TmpSignalConversionAtToWork[4] =
    UAV_log_P.DiscreteTransferFcn3_NumCoef[0] * DiscreteTransferFcn3_tmp +
    UAV_log_P.DiscreteTransferFcn3_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn3_states;
  UAV_log_B.TmpSignalConversionAtToWork[5] = UAV_log_B.q_h;
  UAV_log_B.TmpSignalConversionAtToWork[6] =
    UAV_log_P.DiscreteTransferFcn1_NumCoef[0] * DiscreteTransferFcn1_tmp +
    UAV_log_P.DiscreteTransferFcn1_NumCoef[1] *
    UAV_log_DW.DiscreteTransferFcn1_states;
  UAV_log_B.TmpSignalConversionAtToWork[7] =
    UAV_log_B.EnabledSubsystem_c.Product2 + UAV_log_DW.MemoryX_DSTATE_n;
  UAV_log_B.TmpSignalConversionAtToWork[8] =
    UAV_log_B.EnabledSubsystem_a.Product2 + UAV_log_DW.MemoryX_DSTATE_p;

  /* ToWorkspace: '<S1>/To Workspace' */
  {
    double locTime = UAV_log_M->Timing.taskTime0;
    ;
    rt_UpdateStructLogVar((StructLogVar *)
                          UAV_log_DW.ToWorkspace_PWORK.LoggedData, &locTime,
                          &UAV_log_B.TmpSignalConversionAtToWork[0]);
  }

  /* Outputs for Enabled SubSystem: '<S30>/MeasurementUpdate' */
  /* Constant: '<S5>/Enable' incorporates:
   *  Constant: '<S10>/KalmanGainL'
   *  Constant: '<S5>/C'
   *  Constant: '<S5>/D'
   *  Delay: '<S5>/MemoryX'
   */
  UAV_log_MeasurementUpdate(UAV_log_P.Enable_Value, UAV_log_P.KalmanGainL_Value,
    UAV_log_B.u, UAV_log_P.C_Value, UAV_log_DW.MemoryX_DSTATE, UAV_log_P.D_Value,
    UAV_log_B.ax_b, &UAV_log_B.MeasurementUpdate, &UAV_log_DW.MeasurementUpdate,
    &UAV_log_P.MeasurementUpdate);

  /* End of Outputs for SubSystem: '<S30>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S82>/MeasurementUpdate' */
  /* Constant: '<S6>/Enable' incorporates:
   *  Constant: '<S62>/KalmanGainL'
   *  Constant: '<S6>/C'
   *  Constant: '<S6>/D'
   *  Delay: '<S6>/MemoryX'
   */
  UAV_log_MeasurementUpdate(UAV_log_P.Enable_Value_gt,
    UAV_log_P.KalmanGainL_Value_n, UAV_log_B.theta, UAV_log_P.C_Value_ko,
    UAV_log_DW.MemoryX_DSTATE_p, UAV_log_P.D_Value_h, UAV_log_B.q_h,
    &UAV_log_B.MeasurementUpdate_f, &UAV_log_DW.MeasurementUpdate_f,
    &UAV_log_P.MeasurementUpdate_f);

  /* End of Outputs for SubSystem: '<S82>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S134>/MeasurementUpdate' */
  /* Constant: '<S7>/Enable' incorporates:
   *  Constant: '<S114>/KalmanGainL'
   *  Constant: '<S7>/C'
   *  Constant: '<S7>/D'
   *  Delay: '<S7>/MemoryX'
   */
  UAV_log_MeasurementUpdate(UAV_log_P.Enable_Value_i,
    UAV_log_P.KalmanGainL_Value_a, UAV_log_B.Akxhatkk1_d, UAV_log_P.C_Value_m,
    UAV_log_DW.MemoryX_DSTATE_n, UAV_log_P.D_Value_d, UAV_log_B.q_h,
    &UAV_log_B.MeasurementUpdate_p, &UAV_log_DW.MeasurementUpdate_p,
    &UAV_log_P.MeasurementUpdate_p);

  /* End of Outputs for SubSystem: '<S134>/MeasurementUpdate' */

  /* Sum: '<S2>/Sum9' incorporates:
   *  Constant: '<S2>/Constant'
   */
  UAV_log_B.u = UAV_log_B.Bkuk_i - UAV_log_P.Constant_Value_j;

  /* Outputs for Enabled SubSystem: '<S186>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S215>/Enable'
   */
  /* Constant: '<S8>/Enable' */
  if (UAV_log_P.Enable_Value_o) {
    UAV_log_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S215>/Sum' incorporates:
     *  Constant: '<S8>/C'
     *  Constant: '<S8>/D'
     *  Delay: '<S8>/MemoryX'
     *  Product: '<S215>/C[k]*xhat[k|k-1]'
     *  Product: '<S215>/D[k]*u[k]'
     *  Sum: '<S215>/Add1'
     */
    UAV_log_B.Akxhatkk1_d = UAV_log_B.z - ((UAV_log_P.C_Value_k[0] *
      UAV_log_DW.MemoryX_DSTATE_i[0] + UAV_log_P.C_Value_k[1] *
      UAV_log_DW.MemoryX_DSTATE_i[1]) + UAV_log_P.D_Value_o * UAV_log_B.u);

    /* Product: '<S215>/Product3' incorporates:
     *  Constant: '<S166>/KalmanGainL'
     */
    UAV_log_B.Product3[0] = UAV_log_P.KalmanGainL_Value_m[0] *
      UAV_log_B.Akxhatkk1_d;
    UAV_log_B.Product3[1] = UAV_log_P.KalmanGainL_Value_m[1] *
      UAV_log_B.Akxhatkk1_d;
  } else {
    if (UAV_log_DW.MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S215>/L*(y[k]-yhat[k|k-1])' */
      UAV_log_B.Product3[0] = UAV_log_P.Lykyhatkk1_Y0;
      UAV_log_B.Product3[1] = UAV_log_P.Lykyhatkk1_Y0;
      UAV_log_DW.MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S186>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S238>/MeasurementUpdate' */
  /* Constant: '<S9>/Enable' incorporates:
   *  Constant: '<S218>/KalmanGainL'
   *  Constant: '<S9>/C'
   *  Constant: '<S9>/D'
   *  Delay: '<S9>/MemoryX'
   */
  UAV_log_MeasurementUpdate(UAV_log_P.Enable_Value_g,
    UAV_log_P.KalmanGainL_Value_o, UAV_log_B.v_p, UAV_log_P.C_Value_h,
    UAV_log_DW.MemoryX_DSTATE_m, UAV_log_P.D_Value_b, UAV_log_B.ay_b,
    &UAV_log_B.MeasurementUpdate_h, &UAV_log_DW.MeasurementUpdate_h,
    &UAV_log_P.MeasurementUpdate_h);

  /* End of Outputs for SubSystem: '<S238>/MeasurementUpdate' */

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn8' */
  UAV_log_DW.DiscreteTransferFcn8_states = UAV_log_B.DiscreteTransferFcn8_tmp;

  /* Update for Delay: '<S5>/MemoryX' incorporates:
   *  Constant: '<S5>/A'
   *  Constant: '<S5>/B'
   *  Product: '<S30>/A[k]*xhat[k|k-1]'
   *  Product: '<S30>/B[k]*u[k]'
   *  Sum: '<S30>/Add'
   */
  UAV_log_DW.icLoad = 0U;
  UAV_log_DW.MemoryX_DSTATE = (UAV_log_P.B_Value * UAV_log_B.ax_b +
    UAV_log_P.A_Value * UAV_log_DW.MemoryX_DSTATE) +
    UAV_log_B.MeasurementUpdate.Product3;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn7' */
  UAV_log_DW.DiscreteTransferFcn7_states = UAV_log_B.DiscreteTransferFcn7_tmp;

  /* Update for Delay: '<S9>/MemoryX' incorporates:
   *  Constant: '<S9>/A'
   *  Constant: '<S9>/B'
   *  Product: '<S238>/A[k]*xhat[k|k-1]'
   *  Product: '<S238>/B[k]*u[k]'
   *  Sum: '<S238>/Add'
   */
  UAV_log_DW.icLoad_i = 0U;
  UAV_log_DW.MemoryX_DSTATE_m = (UAV_log_P.B_Value_f * UAV_log_B.ay_b +
    UAV_log_P.A_Value_m * UAV_log_DW.MemoryX_DSTATE_m) +
    UAV_log_B.MeasurementUpdate_h.Product3;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn9' */
  UAV_log_DW.DiscreteTransferFcn9_states = DiscreteTransferFcn9_tmp;

  /* Update for Delay: '<S8>/MemoryX' */
  UAV_log_DW.icLoad_a = 0U;

  /* Product: '<S186>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S8>/A'
   *  Delay: '<S8>/MemoryX'
   */
  UAV_log_B.DiscreteTransferFcn8_tmp = UAV_log_P.A_Value_d[1] *
    UAV_log_DW.MemoryX_DSTATE_i[0] + UAV_log_P.A_Value_d[3] *
    UAV_log_DW.MemoryX_DSTATE_i[1];

  /* Update for Delay: '<S8>/MemoryX' incorporates:
   *  Constant: '<S8>/A'
   *  Constant: '<S8>/B'
   *  Product: '<S186>/A[k]*xhat[k|k-1]'
   *  Product: '<S186>/B[k]*u[k]'
   *  Sum: '<S186>/Add'
   */
  UAV_log_DW.MemoryX_DSTATE_i[0] = ((UAV_log_P.A_Value_d[0] *
    UAV_log_DW.MemoryX_DSTATE_i[0] + UAV_log_P.A_Value_d[2] *
    UAV_log_DW.MemoryX_DSTATE_i[1]) + UAV_log_P.B_Value_o[0] * UAV_log_B.u) +
    UAV_log_B.Product3[0];
  UAV_log_DW.MemoryX_DSTATE_i[1] = (UAV_log_P.B_Value_o[1] * UAV_log_B.u +
    UAV_log_B.DiscreteTransferFcn8_tmp) + UAV_log_B.Product3[1];

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn3' */
  UAV_log_DW.DiscreteTransferFcn3_states = DiscreteTransferFcn3_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
  UAV_log_DW.DiscreteTransferFcn2_states = DiscreteTransferFcn2_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1' */
  UAV_log_DW.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn5' */
  UAV_log_DW.DiscreteTransferFcn5_states = DiscreteTransferFcn5_tmp;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn4' */
  UAV_log_DW.DiscreteTransferFcn4_states = DiscreteTransferFcn4_tmp;

  /* Update for Delay: '<S7>/MemoryX' incorporates:
   *  Constant: '<S7>/A'
   *  Constant: '<S7>/B'
   *  Product: '<S134>/A[k]*xhat[k|k-1]'
   *  Product: '<S134>/B[k]*u[k]'
   *  Sum: '<S134>/Add'
   */
  UAV_log_DW.icLoad_e = 0U;
  UAV_log_DW.MemoryX_DSTATE_n = (UAV_log_P.B_Value_a * UAV_log_B.q_h +
    UAV_log_P.A_Value_a * UAV_log_DW.MemoryX_DSTATE_n) +
    UAV_log_B.MeasurementUpdate_p.Product3;

  /* Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn6' */
  UAV_log_DW.DiscreteTransferFcn6_states = DiscreteTransferFcn6_tmp;

  /* Update for Delay: '<S6>/MemoryX' incorporates:
   *  Constant: '<S6>/A'
   *  Constant: '<S6>/B'
   *  Product: '<S82>/A[k]*xhat[k|k-1]'
   *  Product: '<S82>/B[k]*u[k]'
   *  Sum: '<S82>/Add'
   */
  UAV_log_DW.icLoad_j = 0U;
  UAV_log_DW.MemoryX_DSTATE_p = (UAV_log_P.B_Value_k * UAV_log_B.q_h +
    UAV_log_P.A_Value_e * UAV_log_DW.MemoryX_DSTATE_p) +
    UAV_log_B.MeasurementUpdate_f.Product3;

  /* Matfile logging */
  rt_UpdateTXYLogVars(UAV_log_M->rtwLogInfo, (&UAV_log_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(UAV_log_M)!=-1) &&
        !((rtmGetTFinal(UAV_log_M)-UAV_log_M->Timing.taskTime0) >
          UAV_log_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(UAV_log_M, "Simulation finished");
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
  if (!(++UAV_log_M->Timing.clockTick0)) {
    ++UAV_log_M->Timing.clockTickH0;
  }

  UAV_log_M->Timing.taskTime0 = UAV_log_M->Timing.clockTick0 *
    UAV_log_M->Timing.stepSize0 + UAV_log_M->Timing.clockTickH0 *
    UAV_log_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void UAV_log_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)UAV_log_M, 0,
                sizeof(RT_MODEL_UAV_log_T));
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

  /* Start for Enabled SubSystem: '<S37>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Start(&UAV_log_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S37>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S245>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Start(&UAV_log_DW.EnabledSubsystem_p);

  /* End of Start for SubSystem: '<S245>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S193>/Enabled Subsystem' */
  UAV_log_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S193>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S141>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Start(&UAV_log_DW.EnabledSubsystem_c);

  /* End of Start for SubSystem: '<S141>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S89>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Start(&UAV_log_DW.EnabledSubsystem_a);

  /* End of Start for SubSystem: '<S89>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S30>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Start(&UAV_log_DW.MeasurementUpdate);

  /* End of Start for SubSystem: '<S30>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S82>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Start(&UAV_log_DW.MeasurementUpdate_f);

  /* End of Start for SubSystem: '<S82>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S134>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Start(&UAV_log_DW.MeasurementUpdate_p);

  /* End of Start for SubSystem: '<S134>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S186>/MeasurementUpdate' */
  UAV_log_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S186>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S238>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Start(&UAV_log_DW.MeasurementUpdate_h);

  /* End of Start for SubSystem: '<S238>/MeasurementUpdate' */

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn8' */
  UAV_log_DW.DiscreteTransferFcn8_states =
    UAV_log_P.DiscreteTransferFcn8_InitialSta;

  /* InitializeConditions for Delay: '<S5>/MemoryX' */
  UAV_log_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn7' */
  UAV_log_DW.DiscreteTransferFcn7_states =
    UAV_log_P.DiscreteTransferFcn7_InitialSta;

  /* InitializeConditions for Delay: '<S9>/MemoryX' */
  UAV_log_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn9' */
  UAV_log_DW.DiscreteTransferFcn9_states =
    UAV_log_P.DiscreteTransferFcn9_InitialSta;

  /* InitializeConditions for Delay: '<S8>/MemoryX' */
  UAV_log_DW.icLoad_a = 1U;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn3' */
  UAV_log_DW.DiscreteTransferFcn3_states =
    UAV_log_P.DiscreteTransferFcn3_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn2' */
  UAV_log_DW.DiscreteTransferFcn2_states =
    UAV_log_P.DiscreteTransferFcn2_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1' */
  UAV_log_DW.DiscreteTransferFcn1_states =
    UAV_log_P.DiscreteTransferFcn1_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn5' */
  UAV_log_DW.DiscreteTransferFcn5_states =
    UAV_log_P.DiscreteTransferFcn5_InitialSta;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn4' */
  UAV_log_DW.DiscreteTransferFcn4_states =
    UAV_log_P.DiscreteTransferFcn4_InitialSta;

  /* InitializeConditions for Delay: '<S7>/MemoryX' */
  UAV_log_DW.icLoad_e = 1U;

  /* InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn6' */
  UAV_log_DW.DiscreteTransferFcn6_states =
    UAV_log_P.DiscreteTransferFcn6_InitialSta;

  /* InitializeConditions for Delay: '<S6>/MemoryX' */
  UAV_log_DW.icLoad_j = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S37>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Init(&UAV_log_B.EnabledSubsystem,
    &UAV_log_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S37>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S245>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Init(&UAV_log_B.EnabledSubsystem_p,
    &UAV_log_P.EnabledSubsystem_p);

  /* End of SystemInitialize for SubSystem: '<S245>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S193>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S217>/deltax' */
  UAV_log_B.Product2[0] = UAV_log_P.deltax_Y0;
  UAV_log_B.Product2[1] = UAV_log_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S193>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S141>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Init(&UAV_log_B.EnabledSubsystem_c,
    &UAV_log_P.EnabledSubsystem_c);

  /* End of SystemInitialize for SubSystem: '<S141>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S89>/Enabled Subsystem' */
  UAV_log_EnabledSubsystem_Init(&UAV_log_B.EnabledSubsystem_a,
    &UAV_log_P.EnabledSubsystem_a);

  /* End of SystemInitialize for SubSystem: '<S89>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S30>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Init(&UAV_log_B.MeasurementUpdate,
    &UAV_log_P.MeasurementUpdate);

  /* End of SystemInitialize for SubSystem: '<S30>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S82>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Init(&UAV_log_B.MeasurementUpdate_f,
    &UAV_log_P.MeasurementUpdate_f);

  /* End of SystemInitialize for SubSystem: '<S82>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S134>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Init(&UAV_log_B.MeasurementUpdate_p,
    &UAV_log_P.MeasurementUpdate_p);

  /* End of SystemInitialize for SubSystem: '<S134>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S186>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S215>/L*(y[k]-yhat[k|k-1])' */
  UAV_log_B.Product3[0] = UAV_log_P.Lykyhatkk1_Y0;
  UAV_log_B.Product3[1] = UAV_log_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S186>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S238>/MeasurementUpdate' */
  UAV_log_MeasurementUpdate_Init(&UAV_log_B.MeasurementUpdate_h,
    &UAV_log_P.MeasurementUpdate_h);

  /* End of SystemInitialize for SubSystem: '<S238>/MeasurementUpdate' */
}

/* Model terminate function */
void UAV_log_terminate(void)
{
  /* (no terminate code required) */
}

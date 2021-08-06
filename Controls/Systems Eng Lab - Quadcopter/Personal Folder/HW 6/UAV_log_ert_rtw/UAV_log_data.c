/*
 * UAV_log_data.c
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

/* Block parameters (default storage) */
P_UAV_log_T UAV_log_P = {
  /* Variable: A_double
   * Referenced by: '<S2>/Ax4'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /* Variable: A_single
   * Referenced by:
   *   '<S2>/Ax'
   *   '<S2>/Ax1'
   *   '<S2>/Ax2'
   *   '<S2>/Ax3'
   */
  0.0,

  /* Variable: B_double
   * Referenced by: '<S2>/gain4'
   */
  { 0.0, 1.0 },

  /* Variable: B_single
   * Referenced by:
   *   '<S2>/gain'
   *   '<S2>/gain1'
   *   '<S2>/gain2'
   *   '<S2>/gain3'
   */
  1.0,

  /* Variable: C_double
   * Referenced by: '<S2>/Cx4'
   */
  { 1.0, 0.0 },

  /* Variable: C_single
   * Referenced by:
   *   '<S2>/Cx'
   *   '<S2>/Cx1'
   *   '<S2>/Cx2'
   *   '<S2>/Cx3'
   */
  1.0,

  /* Variable: D_double
   * Referenced by: '<S2>/Dax4'
   */
  0.0,

  /* Variable: D_single
   * Referenced by:
   *   '<S2>/Dax'
   *   '<S2>/Dax1'
   *   '<S2>/Dax2'
   *   '<S2>/Dax3'
   */
  0.0,

  /* Variable: L_double
   * Referenced by: '<S2>/L(y-Cx-Du)4'
   */
  { 1.3093687481168341, 0.857223259272522 },

  /* Variable: L_single
   * Referenced by:
   *   '<S2>/L(y-Cx-Du)'
   *   '<S2>/L(y-Cx-Du)1'
   *   '<S2>/L(y-Cx-Du)2'
   *   '<S2>/L(y-Cx-Du)3'
   */
  0.85722325927252263,

  /* Expression: 200
   * Referenced by: '<S1>/Constant5'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: [1 1 1 -1; 1 1 -1 1; 1 -1 -1 -1; 1 -1 1 1]
   * Referenced by: '<S1>/MotorMix'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0,
    -1.0, 1.0 },

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator1'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator2'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator2'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator5_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator5'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator5'
   */
  0.0,

  /* Computed Parameter: TransferFcn15_A
   * Referenced by: '<S3>/Transfer Fcn15'
   */
  -100.0,

  /* Computed Parameter: TransferFcn15_C
   * Referenced by: '<S3>/Transfer Fcn15'
   */
  100.0,

  /* Computed Parameter: TransferFcn16_A
   * Referenced by: '<S3>/Transfer Fcn16'
   */
  -100.0,

  /* Computed Parameter: TransferFcn16_C
   * Referenced by: '<S3>/Transfer Fcn16'
   */
  100.0,

  /* Computed Parameter: TransferFcn17_A
   * Referenced by: '<S3>/Transfer Fcn17'
   */
  -100.0,

  /* Computed Parameter: TransferFcn17_C
   * Referenced by: '<S3>/Transfer Fcn17'
   */
  100.0,

  /* Computed Parameter: DiscreteTimeIntegrator4_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator4'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator3_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator3'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator3'
   */
  0.0,

  /* Computed Parameter: TransferFcn13_A
   * Referenced by: '<S3>/Transfer Fcn13'
   */
  -100.0,

  /* Computed Parameter: TransferFcn13_C
   * Referenced by: '<S3>/Transfer Fcn13'
   */
  100.0,

  /* Computed Parameter: TransferFcn14_A
   * Referenced by: '<S3>/Transfer Fcn14'
   */
  -100.0,

  /* Computed Parameter: TransferFcn14_C
   * Referenced by: '<S3>/Transfer Fcn14'
   */
  100.0,

  /* Expression: 0.00001
   * Referenced by: '<S2>/Constant'
   */
  1.0E-5,

  /* Computed Parameter: TransferFcn12_A
   * Referenced by: '<S3>/Transfer Fcn12'
   */
  -100.0,

  /* Computed Parameter: TransferFcn12_C
   * Referenced by: '<S3>/Transfer Fcn12'
   */
  100.0,

  /* Expression: inf
   * Referenced by: '<S2>/Saturation'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<S2>/Saturation'
   */
  0.001,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Computed Parameter: TransferFcn18_A
   * Referenced by: '<S3>/Transfer Fcn18'
   */
  -100.0,

  /* Computed Parameter: TransferFcn18_C
   * Referenced by: '<S3>/Transfer Fcn18'
   */
  100.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain1'
   */
  -1.0,

  /* Computed Parameter: TransferFcn10_A
   * Referenced by: '<S3>/Transfer Fcn10'
   */
  -100.0,

  /* Computed Parameter: TransferFcn10_C
   * Referenced by: '<S3>/Transfer Fcn10'
   */
  100.0,

  /* Computed Parameter: TransferFcn11_A
   * Referenced by: '<S3>/Transfer Fcn11'
   */
  -100.0,

  /* Computed Parameter: TransferFcn11_C
   * Referenced by: '<S3>/Transfer Fcn11'
   */
  100.0,

  /* Computed Parameter: TransferFcn19_A
   * Referenced by: '<S3>/Transfer Fcn19'
   */
  -100.0,

  /* Computed Parameter: TransferFcn19_C
   * Referenced by: '<S3>/Transfer Fcn19'
   */
  100.0,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S1>/Saturation1'
   */
  500.0F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S1>/Saturation1'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S1>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S1>/Constant2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  1U
};

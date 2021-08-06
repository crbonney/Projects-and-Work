/*
 * TestDataLogging_data.c
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

/* Block parameters (default storage) */
P_TestDataLogging_T TestDataLogging_P = {
  /* Expression: 68
   * Referenced by: '<S1>/Constant5'
   */
  68.0,

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

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S1>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S1>/Transfer Fcn'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  -100.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S1>/Transfer Fcn2'
   */
  -100.0,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S1>/Transfer Fcn2'
   */
  100.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<S1>/Transfer Fcn3'
   */
  -100.0,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<S1>/Transfer Fcn3'
   */
  100.0,

  /* Computed Parameter: TransferFcn4_A
   * Referenced by: '<S1>/Transfer Fcn4'
   */
  -100.0,

  /* Computed Parameter: TransferFcn4_C
   * Referenced by: '<S1>/Transfer Fcn4'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator5'
   */
  0.0,

  /* Computed Parameter: TransferFcn5_A
   * Referenced by: '<S1>/Transfer Fcn5'
   */
  -100.0,

  /* Computed Parameter: TransferFcn5_C
   * Referenced by: '<S1>/Transfer Fcn5'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator2'
   */
  0.0,

  /* Computed Parameter: TransferFcn6_A
   * Referenced by: '<S1>/Transfer Fcn6'
   */
  -100.0,

  /* Computed Parameter: TransferFcn6_C
   * Referenced by: '<S1>/Transfer Fcn6'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator3'
   */
  0.0,

  /* Computed Parameter: TransferFcn7_A
   * Referenced by: '<S1>/Transfer Fcn7'
   */
  -100.0,

  /* Computed Parameter: TransferFcn7_C
   * Referenced by: '<S1>/Transfer Fcn7'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator4'
   */
  0.0,

  /* Computed Parameter: TransferFcn8_A
   * Referenced by: '<S1>/Transfer Fcn8'
   */
  -100.0,

  /* Computed Parameter: TransferFcn8_C
   * Referenced by: '<S1>/Transfer Fcn8'
   */
  100.0,

  /* Computed Parameter: TransferFcn9_A
   * Referenced by: '<S1>/Transfer Fcn9'
   */
  -100.0,

  /* Computed Parameter: TransferFcn9_C
   * Referenced by: '<S1>/Transfer Fcn9'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator10'
   */
  0.0,

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

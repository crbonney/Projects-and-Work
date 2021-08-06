/*
 * UAV_log_data.c
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

/* Block parameters (default storage) */
P_UAV_log_T UAV_log_P = {
  /* Expression: 0
   * Referenced by: '<S215>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S217>/deltax'
   */
  0.0,

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

  /* Expression: pInitialization.M
   * Referenced by: '<S10>/KalmanGainM'
   */
  0.0085355697459064718,

  /* Expression: pInitialization.C
   * Referenced by: '<S5>/C'
   */
  1.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn8'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn8'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn8'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S5>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S218>/KalmanGainM'
   */
  0.0085355697459064718,

  /* Expression: pInitialization.C
   * Referenced by: '<S9>/C'
   */
  1.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn7'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn7'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn7'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S9>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S166>/KalmanGainM'
   */
  { 0.0092159224010828454, 0.0085326406473199817 },

  /* Expression: pInitialization.C
   * Referenced by: '<S8>/C'
   */
  { 1.0, 0.0 },

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn9'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn9'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn9'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain3'
   */
  -1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S8>/X0'
   */
  { 0.0, 0.0 },

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn3'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn3'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn3'
   */
  0.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn2'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn2'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn2'
   */
  0.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn1'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn1'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn1'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S114>/KalmanGainM'
   */
  0.0085355697459064718,

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  1.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn5'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn5'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn5'
   */
  0.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn4'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn4'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn4'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  0.0,

  /* Expression: pInitialization.M
   * Referenced by: '<S62>/KalmanGainM'
   */
  0.0085355697459064718,

  /* Expression: pInitialization.C
   * Referenced by: '<S6>/C'
   */
  1.0,

  /* Expression: [omega_c omega_c]
   * Referenced by: '<S3>/Discrete Transfer Fcn6'
   */
  { 125.66370614359172, 125.66370614359172 },

  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
   * Referenced by: '<S3>/Discrete Transfer Fcn6'
   */
  { 525.66370614359175, -274.33629385640825 },

  /* Expression: 0
   * Referenced by: '<S3>/Discrete Transfer Fcn6'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain2'
   */
  -1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S6>/X0'
   */
  0.0,

  /* Expression: 9.81
   * Referenced by: '<S2>/Constant'
   */
  9.81,

  /* Expression: pInitialization.A
   * Referenced by: '<S5>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S5>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S10>/KalmanGainL'
   */
  0.00853556974590647,

  /* Expression: pInitialization.D
   * Referenced by: '<S5>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S6>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S6>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S62>/KalmanGainL'
   */
  0.00853556974590647,

  /* Expression: pInitialization.D
   * Referenced by: '<S6>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S7>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S7>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S114>/KalmanGainL'
   */
  0.00853556974590647,

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S8>/A'
   */
  { 1.0, 0.0, 0.005, 1.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S8>/B'
   */
  { 1.25E-5, 0.005 },

  /* Expression: pInitialization.L
   * Referenced by: '<S166>/KalmanGainL'
   */
  { 0.0092585856043194414, 0.00853264064731997 },

  /* Expression: pInitialization.D
   * Referenced by: '<S8>/D'
   */
  0.0,

  /* Expression: pInitialization.A
   * Referenced by: '<S9>/A'
   */
  1.0,

  /* Expression: pInitialization.B
   * Referenced by: '<S9>/B'
   */
  0.005,

  /* Expression: pInitialization.L
   * Referenced by: '<S218>/KalmanGainL'
   */
  0.00853556974590647,

  /* Expression: pInitialization.D
   * Referenced by: '<S9>/D'
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

  /* Expression: true()
   * Referenced by: '<S5>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S9>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S8>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S6>/Enable'
   */
  1,

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
  1U,

  /* Start of '<S245>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S269>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S245>/Enabled Subsystem' */

  /* Start of '<S238>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S267>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S238>/MeasurementUpdate' */

  /* Start of '<S141>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S165>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S141>/Enabled Subsystem' */

  /* Start of '<S134>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S163>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S134>/MeasurementUpdate' */

  /* Start of '<S89>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S113>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S89>/Enabled Subsystem' */

  /* Start of '<S82>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S111>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  ,

  /* End of '<S82>/MeasurementUpdate' */

  /* Start of '<S37>/Enabled Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S61>/deltax'
     */
    0.0
  }
  ,

  /* End of '<S37>/Enabled Subsystem' */

  /* Start of '<S30>/MeasurementUpdate' */
  {
    /* Expression: 0
     * Referenced by: '<S59>/L*(y[k]-yhat[k|k-1])'
     */
    0.0
  }
  /* End of '<S30>/MeasurementUpdate' */
};

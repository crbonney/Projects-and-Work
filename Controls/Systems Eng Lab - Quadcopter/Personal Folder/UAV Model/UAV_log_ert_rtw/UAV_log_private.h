/*
 * UAV_log_private.h
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

#ifndef RTW_HEADER_UAV_log_private_h_
#define RTW_HEADER_UAV_log_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "UAV_log.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

extern void UAV_log_MeasurementUpdate_Init(B_MeasurementUpdate_UAV_log_T *localB,
  P_MeasurementUpdate_UAV_log_T *localP);
extern void UAV_log_MeasurementUpdate_Start(DW_MeasurementUpdate_UAV_log_T
  *localDW);
extern void UAV_l_MeasurementUpdate_Disable(B_MeasurementUpdate_UAV_log_T
  *localB, DW_MeasurementUpdate_UAV_log_T *localDW,
  P_MeasurementUpdate_UAV_log_T *localP);
extern void UAV_log_MeasurementUpdate(boolean_T rtu_Enable, real_T rtu_Lk,
  real_T rtu_yk, real_T rtu_Ck, real_T rtu_xhatkk1, real_T rtu_Dk, real_T rtu_uk,
  B_MeasurementUpdate_UAV_log_T *localB, DW_MeasurementUpdate_UAV_log_T *localDW,
  P_MeasurementUpdate_UAV_log_T *localP);
extern void UAV_log_EnabledSubsystem_Init(B_EnabledSubsystem_UAV_log_T *localB,
  P_EnabledSubsystem_UAV_log_T *localP);
extern void UAV_log_EnabledSubsystem_Start(DW_EnabledSubsystem_UAV_log_T
  *localDW);
extern void UAV_lo_EnabledSubsystem_Disable(B_EnabledSubsystem_UAV_log_T *localB,
  DW_EnabledSubsystem_UAV_log_T *localDW, P_EnabledSubsystem_UAV_log_T *localP);
extern void UAV_log_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_Mk, real_T
  rtu_Ck, real_T rtu_yk, real_T rtu_xhatkk1, B_EnabledSubsystem_UAV_log_T
  *localB, DW_EnabledSubsystem_UAV_log_T *localDW, P_EnabledSubsystem_UAV_log_T *
  localP);

#endif                                 /* RTW_HEADER_UAV_log_private_h_ */

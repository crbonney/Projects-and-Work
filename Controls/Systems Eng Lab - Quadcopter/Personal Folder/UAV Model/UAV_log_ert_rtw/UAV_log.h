/*
 * UAV_log.h
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

#ifndef RTW_HEADER_UAV_log_h_
#define RTW_HEADER_UAV_log_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <float.h>
#ifndef UAV_log_COMMON_INCLUDES_
# define UAV_log_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* UAV_log_COMMON_INCLUDES_ */

#include "UAV_log_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S30>/MeasurementUpdate' */
typedef struct {
  real_T Product3;                     /* '<S59>/Product3' */
} B_MeasurementUpdate_UAV_log_T;

/* Block states (default storage) for system '<S30>/MeasurementUpdate' */
typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S30>/MeasurementUpdate' */
} DW_MeasurementUpdate_UAV_log_T;

/* Block signals for system '<S37>/Enabled Subsystem' */
typedef struct {
  real_T Product2;                     /* '<S61>/Product2' */
} B_EnabledSubsystem_UAV_log_T;

/* Block states (default storage) for system '<S37>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S37>/Enabled Subsystem' */
} DW_EnabledSubsystem_UAV_log_T;

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[9];/* '<S1>/Kalman Filter' */
  real_T Product2[2];                  /* '<S217>/Product2' */
  real_T Product3[2];                  /* '<S215>/Product3' */
  real_T ay_b;                         /* '<S3>/Discrete Transfer Fcn5' */
  real_T Bkuk_i;                       /* '<S238>/B[k]*u[k]' */
  real_T ax_b;                         /* '<S3>/Discrete Transfer Fcn6' */
  real_T Akxhatkk1_d;                  /* '<S238>/A[k]*xhat[k|k-1]' */
  real_T z;                            /* '<S2>/Gain3' */
  real_T theta;                        /* '<S2>/Gain2' */
  real_T u;                            /* '<S3>/Discrete Transfer Fcn8' */
  real_T v_p;                          /* '<S3>/Discrete Transfer Fcn7' */
  real_T q_h;                          /* '<S3>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn8_tmp;
  real_T DiscreteTransferFcn7_tmp;
  B_EnabledSubsystem_UAV_log_T EnabledSubsystem_p;/* '<S245>/Enabled Subsystem' */
  B_MeasurementUpdate_UAV_log_T MeasurementUpdate_h;/* '<S238>/MeasurementUpdate' */
  B_EnabledSubsystem_UAV_log_T EnabledSubsystem_c;/* '<S141>/Enabled Subsystem' */
  B_MeasurementUpdate_UAV_log_T MeasurementUpdate_p;/* '<S134>/MeasurementUpdate' */
  B_EnabledSubsystem_UAV_log_T EnabledSubsystem_a;/* '<S89>/Enabled Subsystem' */
  B_MeasurementUpdate_UAV_log_T MeasurementUpdate_f;/* '<S82>/MeasurementUpdate' */
  B_EnabledSubsystem_UAV_log_T EnabledSubsystem;/* '<S37>/Enabled Subsystem' */
  B_MeasurementUpdate_UAV_log_T MeasurementUpdate;/* '<S30>/MeasurementUpdate' */
} B_UAV_log_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn8_states;  /* '<S3>/Discrete Transfer Fcn8' */
  real_T MemoryX_DSTATE;               /* '<S5>/MemoryX' */
  real_T DiscreteTransferFcn7_states;  /* '<S3>/Discrete Transfer Fcn7' */
  real_T MemoryX_DSTATE_m;             /* '<S9>/MemoryX' */
  real_T DiscreteTransferFcn9_states;  /* '<S3>/Discrete Transfer Fcn9' */
  real_T MemoryX_DSTATE_i[2];          /* '<S8>/MemoryX' */
  real_T DiscreteTransferFcn3_states;  /* '<S3>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn2_states;  /* '<S3>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn1_states;  /* '<S3>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn5_states;  /* '<S3>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn4_states;  /* '<S3>/Discrete Transfer Fcn4' */
  real_T MemoryX_DSTATE_n;             /* '<S7>/MemoryX' */
  real_T DiscreteTransferFcn6_states;  /* '<S3>/Discrete Transfer Fcn6' */
  real_T MemoryX_DSTATE_p;             /* '<S6>/MemoryX' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  uint8_T icLoad;                      /* '<S5>/MemoryX' */
  uint8_T icLoad_i;                    /* '<S9>/MemoryX' */
  uint8_T icLoad_a;                    /* '<S8>/MemoryX' */
  uint8_T icLoad_e;                    /* '<S7>/MemoryX' */
  uint8_T icLoad_j;                    /* '<S6>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S193>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S186>/MeasurementUpdate' */
  DW_EnabledSubsystem_UAV_log_T EnabledSubsystem_p;/* '<S245>/Enabled Subsystem' */
  DW_MeasurementUpdate_UAV_log_T MeasurementUpdate_h;/* '<S238>/MeasurementUpdate' */
  DW_EnabledSubsystem_UAV_log_T EnabledSubsystem_c;/* '<S141>/Enabled Subsystem' */
  DW_MeasurementUpdate_UAV_log_T MeasurementUpdate_p;/* '<S134>/MeasurementUpdate' */
  DW_EnabledSubsystem_UAV_log_T EnabledSubsystem_a;/* '<S89>/Enabled Subsystem' */
  DW_MeasurementUpdate_UAV_log_T MeasurementUpdate_f;/* '<S82>/MeasurementUpdate' */
  DW_EnabledSubsystem_UAV_log_T EnabledSubsystem;/* '<S37>/Enabled Subsystem' */
  DW_MeasurementUpdate_UAV_log_T MeasurementUpdate;/* '<S30>/MeasurementUpdate' */
} DW_UAV_log_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Motors[4];                  /* '<Root>/Motors' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_UAV_log_T;

/* Parameters for system: '<S30>/MeasurementUpdate' */
struct P_MeasurementUpdate_UAV_log_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S59>/L*(y[k]-yhat[k|k-1])'
                                        */
};

/* Parameters for system: '<S37>/Enabled Subsystem' */
struct P_EnabledSubsystem_UAV_log_T_ {
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S61>/deltax'
                                        */
};

/* Parameters (default storage) */
struct P_UAV_log_T_ {
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S215>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S217>/deltax'
                                        */
  real_T Constant5_Value;              /* Expression: 200
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T MotorMix_Gain[16];
                       /* Expression: [1 1 1 -1; 1 1 -1 1; 1 -1 -1 -1; 1 -1 1 1]
                        * Referenced by: '<S1>/MotorMix'
                        */
  real_T KalmanGainM_Value;            /* Expression: pInitialization.M
                                        * Referenced by: '<S10>/KalmanGainM'
                                        */
  real_T C_Value;                      /* Expression: pInitialization.C
                                        * Referenced by: '<S5>/C'
                                        */
  real_T DiscreteTransferFcn8_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn8'
                                          */
  real_T DiscreteTransferFcn8_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn8'
                                   */
  real_T DiscreteTransferFcn8_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn8'
                                          */
  real_T X0_Value;                     /* Expression: pInitialization.X0
                                        * Referenced by: '<S5>/X0'
                                        */
  real_T KalmanGainM_Value_m;          /* Expression: pInitialization.M
                                        * Referenced by: '<S218>/KalmanGainM'
                                        */
  real_T C_Value_h;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T DiscreteTransferFcn7_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn7'
                                          */
  real_T DiscreteTransferFcn7_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn7'
                                   */
  real_T DiscreteTransferFcn7_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn7'
                                          */
  real_T X0_Value_g;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S9>/X0'
                                        */
  real_T KalmanGainM_Value_j[2];       /* Expression: pInitialization.M
                                        * Referenced by: '<S166>/KalmanGainM'
                                        */
  real_T C_Value_k[2];                 /* Expression: pInitialization.C
                                        * Referenced by: '<S8>/C'
                                        */
  real_T DiscreteTransferFcn9_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn9'
                                          */
  real_T DiscreteTransferFcn9_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn9'
                                   */
  real_T DiscreteTransferFcn9_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn9'
                                          */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T X0_Value_h[2];                /* Expression: pInitialization.X0
                                        * Referenced by: '<S8>/X0'
                                        */
  real_T DiscreteTransferFcn3_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn3'
                                          */
  real_T DiscreteTransferFcn3_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn3'
                                   */
  real_T DiscreteTransferFcn3_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn3'
                                          */
  real_T DiscreteTransferFcn2_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn2_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                   */
  real_T DiscreteTransferFcn2_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn2'
                                          */
  real_T DiscreteTransferFcn1_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn1'
                                   */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn1'
                                          */
  real_T KalmanGainM_Value_h;          /* Expression: pInitialization.M
                                        * Referenced by: '<S114>/KalmanGainM'
                                        */
  real_T C_Value_m;                    /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T DiscreteTransferFcn5_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn5'
                                          */
  real_T DiscreteTransferFcn5_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn5'
                                   */
  real_T DiscreteTransferFcn5_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn5'
                                          */
  real_T DiscreteTransferFcn4_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn4'
                                          */
  real_T DiscreteTransferFcn4_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn4'
                                   */
  real_T DiscreteTransferFcn4_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn4'
                                          */
  real_T X0_Value_i;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T KalmanGainM_Value_h0;         /* Expression: pInitialization.M
                                        * Referenced by: '<S62>/KalmanGainM'
                                        */
  real_T C_Value_ko;                   /* Expression: pInitialization.C
                                        * Referenced by: '<S6>/C'
                                        */
  real_T DiscreteTransferFcn6_NumCoef[2];/* Expression: [omega_c omega_c]
                                          * Referenced by: '<S3>/Discrete Transfer Fcn6'
                                          */
  real_T DiscreteTransferFcn6_DenCoef[2];
                                  /* Expression: [(omega_c+2/Ts) (omega_c-2/Ts)]
                                   * Referenced by: '<S3>/Discrete Transfer Fcn6'
                                   */
  real_T DiscreteTransferFcn6_InitialSta;/* Expression: 0
                                          * Referenced by: '<S3>/Discrete Transfer Fcn6'
                                          */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T X0_Value_o;                   /* Expression: pInitialization.X0
                                        * Referenced by: '<S6>/X0'
                                        */
  real_T Constant_Value_j;             /* Expression: 9.81
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T A_Value;                      /* Expression: pInitialization.A
                                        * Referenced by: '<S5>/A'
                                        */
  real_T B_Value;                      /* Expression: pInitialization.B
                                        * Referenced by: '<S5>/B'
                                        */
  real_T KalmanGainL_Value;            /* Expression: pInitialization.L
                                        * Referenced by: '<S10>/KalmanGainL'
                                        */
  real_T D_Value;                      /* Expression: pInitialization.D
                                        * Referenced by: '<S5>/D'
                                        */
  real_T A_Value_e;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S6>/A'
                                        */
  real_T B_Value_k;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S6>/B'
                                        */
  real_T KalmanGainL_Value_n;          /* Expression: pInitialization.L
                                        * Referenced by: '<S62>/KalmanGainL'
                                        */
  real_T D_Value_h;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S6>/D'
                                        */
  real_T A_Value_a;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value_a;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T KalmanGainL_Value_a;          /* Expression: pInitialization.L
                                        * Referenced by: '<S114>/KalmanGainL'
                                        */
  real_T D_Value_d;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T A_Value_d[4];                 /* Expression: pInitialization.A
                                        * Referenced by: '<S8>/A'
                                        */
  real_T B_Value_o[2];                 /* Expression: pInitialization.B
                                        * Referenced by: '<S8>/B'
                                        */
  real_T KalmanGainL_Value_m[2];       /* Expression: pInitialization.L
                                        * Referenced by: '<S166>/KalmanGainL'
                                        */
  real_T D_Value_o;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T A_Value_m;                    /* Expression: pInitialization.A
                                        * Referenced by: '<S9>/A'
                                        */
  real_T B_Value_f;                    /* Expression: pInitialization.B
                                        * Referenced by: '<S9>/B'
                                        */
  real_T KalmanGainL_Value_o;          /* Expression: pInitialization.L
                                        * Referenced by: '<S218>/KalmanGainL'
                                        */
  real_T D_Value_b;                    /* Expression: pInitialization.D
                                        * Referenced by: '<S9>/D'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S5>/Enable'
                                        */
  boolean_T Enable_Value_g;            /* Expression: true()
                                        * Referenced by: '<S9>/Enable'
                                        */
  boolean_T Enable_Value_o;            /* Expression: true()
                                        * Referenced by: '<S8>/Enable'
                                        */
  boolean_T Enable_Value_i;            /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  boolean_T Enable_Value_gt;           /* Expression: true()
                                        * Referenced by: '<S6>/Enable'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S1>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S1>/Constant2'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  P_EnabledSubsystem_UAV_log_T EnabledSubsystem_p;/* '<S245>/Enabled Subsystem' */
  P_MeasurementUpdate_UAV_log_T MeasurementUpdate_h;/* '<S238>/MeasurementUpdate' */
  P_EnabledSubsystem_UAV_log_T EnabledSubsystem_c;/* '<S141>/Enabled Subsystem' */
  P_MeasurementUpdate_UAV_log_T MeasurementUpdate_p;/* '<S134>/MeasurementUpdate' */
  P_EnabledSubsystem_UAV_log_T EnabledSubsystem_a;/* '<S89>/Enabled Subsystem' */
  P_MeasurementUpdate_UAV_log_T MeasurementUpdate_f;/* '<S82>/MeasurementUpdate' */
  P_EnabledSubsystem_UAV_log_T EnabledSubsystem;/* '<S37>/Enabled Subsystem' */
  P_MeasurementUpdate_UAV_log_T MeasurementUpdate;/* '<S30>/MeasurementUpdate' */
};

/* Real-time Model Data Structure */
struct tag_RTM_UAV_log_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_UAV_log_T UAV_log_P;

/* Block signals (default storage) */
extern B_UAV_log_T UAV_log_B;

/* Block states (default storage) */
extern DW_UAV_log_T UAV_log_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_UAV_log_T UAV_log_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S1>/Saturation1' */
extern uint8_T flag_outport;           /* '<S1>/Manual Switch' */

/* Model entry point functions */
extern void UAV_log_initialize(void);
extern void UAV_log_step(void);
extern void UAV_log_terminate(void);

/* Real-time Model object */
extern RT_MODEL_UAV_log_T *const UAV_log_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion10' : Unused code path elimination
 * Block '<S1>/Data Type Conversion11' : Unused code path elimination
 * Block '<S1>/Data Type Conversion6' : Unused code path elimination
 * Block '<S10>/CovarianceZ' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Conversion' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Conversion' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/G' : Unused code path elimination
 * Block '<S5>/H' : Unused code path elimination
 * Block '<S5>/N' : Unused code path elimination
 * Block '<S5>/P0' : Unused code path elimination
 * Block '<S5>/Q' : Unused code path elimination
 * Block '<S5>/R' : Unused code path elimination
 * Block '<S51>/CheckSignalProperties' : Unused code path elimination
 * Block '<S52>/CheckSignalProperties' : Unused code path elimination
 * Block '<S62>/CovarianceZ' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Conversion' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Conversion' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Conversion' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/G' : Unused code path elimination
 * Block '<S6>/H' : Unused code path elimination
 * Block '<S6>/N' : Unused code path elimination
 * Block '<S6>/P0' : Unused code path elimination
 * Block '<S6>/Q' : Unused code path elimination
 * Block '<S6>/R' : Unused code path elimination
 * Block '<S103>/CheckSignalProperties' : Unused code path elimination
 * Block '<S104>/CheckSignalProperties' : Unused code path elimination
 * Block '<S114>/CovarianceZ' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Conversion' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Conversion' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S117>/Data Type Duplicate' : Unused code path elimination
 * Block '<S118>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Conversion' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S126>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S128>/Data Type Duplicate' : Unused code path elimination
 * Block '<S130>/Data Type Duplicate' : Unused code path elimination
 * Block '<S131>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S155>/CheckSignalProperties' : Unused code path elimination
 * Block '<S156>/CheckSignalProperties' : Unused code path elimination
 * Block '<S166>/CovarianceZ' : Unused code path elimination
 * Block '<S209>/Data Type Duplicate' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Conversion' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/Conversion' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Conversion' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/G' : Unused code path elimination
 * Block '<S8>/H' : Unused code path elimination
 * Block '<S8>/N' : Unused code path elimination
 * Block '<S8>/P0' : Unused code path elimination
 * Block '<S8>/Q' : Unused code path elimination
 * Block '<S8>/R' : Unused code path elimination
 * Block '<S207>/CheckSignalProperties' : Unused code path elimination
 * Block '<S208>/CheckSignalProperties' : Unused code path elimination
 * Block '<S218>/CovarianceZ' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S263>/Conversion' : Unused code path elimination
 * Block '<S263>/Data Type Duplicate' : Unused code path elimination
 * Block '<S264>/Conversion' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S222>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Conversion' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S230>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S232>/Data Type Duplicate' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S235>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/G' : Unused code path elimination
 * Block '<S9>/H' : Unused code path elimination
 * Block '<S9>/N' : Unused code path elimination
 * Block '<S9>/P0' : Unused code path elimination
 * Block '<S9>/Q' : Unused code path elimination
 * Block '<S9>/R' : Unused code path elimination
 * Block '<S259>/CheckSignalProperties' : Unused code path elimination
 * Block '<S260>/CheckSignalProperties' : Unused code path elimination
 * Block '<S3>/Discrete Transfer Fcn' : Unused code path elimination
 * Block '<S3>/Discrete Transfer Fcn10' : Unused code path elimination
 * Block '<S53>/Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Reshape' : Reshape block reduction
 * Block '<S5>/ReshapeX0' : Reshape block reduction
 * Block '<S5>/Reshapeu' : Reshape block reduction
 * Block '<S5>/Reshapexhat' : Reshape block reduction
 * Block '<S5>/Reshapey' : Reshape block reduction
 * Block '<S105>/Conversion' : Eliminate redundant data type conversion
 * Block '<S106>/Conversion' : Eliminate redundant data type conversion
 * Block '<S78>/Conversion' : Eliminate redundant data type conversion
 * Block '<S82>/Reshape' : Reshape block reduction
 * Block '<S6>/ReshapeX0' : Reshape block reduction
 * Block '<S6>/Reshapeu' : Reshape block reduction
 * Block '<S6>/Reshapexhat' : Reshape block reduction
 * Block '<S6>/Reshapey' : Reshape block reduction
 * Block '<S157>/Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/Conversion' : Eliminate redundant data type conversion
 * Block '<S130>/Conversion' : Eliminate redundant data type conversion
 * Block '<S134>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapeu' : Reshape block reduction
 * Block '<S7>/Reshapexhat' : Reshape block reduction
 * Block '<S7>/Reshapey' : Reshape block reduction
 * Block '<S209>/Conversion' : Eliminate redundant data type conversion
 * Block '<S210>/Conversion' : Eliminate redundant data type conversion
 * Block '<S182>/Conversion' : Eliminate redundant data type conversion
 * Block '<S186>/Reshape' : Reshape block reduction
 * Block '<S8>/ReshapeX0' : Reshape block reduction
 * Block '<S8>/Reshapeu' : Reshape block reduction
 * Block '<S8>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Reshapey' : Reshape block reduction
 * Block '<S261>/Conversion' : Eliminate redundant data type conversion
 * Block '<S262>/Conversion' : Eliminate redundant data type conversion
 * Block '<S234>/Conversion' : Eliminate redundant data type conversion
 * Block '<S238>/Reshape' : Reshape block reduction
 * Block '<S9>/ReshapeX0' : Reshape block reduction
 * Block '<S9>/Reshapeu' : Reshape block reduction
 * Block '<S9>/Reshapexhat' : Reshape block reduction
 * Block '<S9>/Reshapey' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'UAV_log'
 * '<S1>'   : 'UAV_log/Flight Control System'
 * '<S2>'   : 'UAV_log/Flight Control System/Kalman Filter'
 * '<S3>'   : 'UAV_log/Flight Control System/Sensor Processing '
 * '<S4>'   : 'UAV_log/Flight Control System/Subsystem'
 * '<S5>'   : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1'
 * '<S6>'   : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2'
 * '<S7>'   : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3'
 * '<S8>'   : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4'
 * '<S9>'   : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6'
 * '<S10>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL'
 * '<S11>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculateYhat'
 * '<S12>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CovarianceOutputConfigurator'
 * '<S13>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionA'
 * '<S14>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionB'
 * '<S15>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionC'
 * '<S16>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionD'
 * '<S17>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionEnable'
 * '<S18>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionG'
 * '<S19>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionH'
 * '<S20>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionN'
 * '<S21>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionP'
 * '<S22>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionP0'
 * '<S23>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionQ'
 * '<S24>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionR'
 * '<S25>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionReset'
 * '<S26>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionX'
 * '<S27>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionX0'
 * '<S28>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/DataTypeConversionu'
 * '<S29>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/MemoryP'
 * '<S30>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/Observer'
 * '<S31>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/ReducedQRN'
 * '<S32>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/Reset'
 * '<S33>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/Reshapeyhat'
 * '<S34>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/ScalarExpansionP0'
 * '<S35>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/ScalarExpansionQ'
 * '<S36>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/ScalarExpansionR'
 * '<S37>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/UseCurrentEstimator'
 * '<S38>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkA'
 * '<S39>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkB'
 * '<S40>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkC'
 * '<S41>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkD'
 * '<S42>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkEnable'
 * '<S43>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkG'
 * '<S44>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkH'
 * '<S45>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkN'
 * '<S46>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkP0'
 * '<S47>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkQ'
 * '<S48>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkR'
 * '<S49>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkReset'
 * '<S50>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checkX0'
 * '<S51>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checku'
 * '<S52>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/checky'
 * '<S53>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL/DataTypeConversionL'
 * '<S54>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL/DataTypeConversionM'
 * '<S55>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL/DataTypeConversionP'
 * '<S56>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL/DataTypeConversionZ'
 * '<S57>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculatePL/Ground'
 * '<S58>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/CalculateYhat/Ground'
 * '<S59>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/Observer/MeasurementUpdate'
 * '<S60>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/ReducedQRN/Ground'
 * '<S61>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter1/UseCurrentEstimator/Enabled Subsystem'
 * '<S62>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL'
 * '<S63>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculateYhat'
 * '<S64>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CovarianceOutputConfigurator'
 * '<S65>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionA'
 * '<S66>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionB'
 * '<S67>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionC'
 * '<S68>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionD'
 * '<S69>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionEnable'
 * '<S70>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionG'
 * '<S71>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionH'
 * '<S72>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionN'
 * '<S73>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionP'
 * '<S74>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionP0'
 * '<S75>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionQ'
 * '<S76>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionR'
 * '<S77>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionReset'
 * '<S78>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionX'
 * '<S79>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionX0'
 * '<S80>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/DataTypeConversionu'
 * '<S81>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/MemoryP'
 * '<S82>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/Observer'
 * '<S83>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/ReducedQRN'
 * '<S84>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/Reset'
 * '<S85>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/Reshapeyhat'
 * '<S86>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/ScalarExpansionP0'
 * '<S87>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/ScalarExpansionQ'
 * '<S88>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/ScalarExpansionR'
 * '<S89>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/UseCurrentEstimator'
 * '<S90>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkA'
 * '<S91>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkB'
 * '<S92>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkC'
 * '<S93>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkD'
 * '<S94>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkEnable'
 * '<S95>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkG'
 * '<S96>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkH'
 * '<S97>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkN'
 * '<S98>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkP0'
 * '<S99>'  : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkQ'
 * '<S100>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkR'
 * '<S101>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkReset'
 * '<S102>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checkX0'
 * '<S103>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checku'
 * '<S104>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/checky'
 * '<S105>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL/DataTypeConversionL'
 * '<S106>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL/DataTypeConversionM'
 * '<S107>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL/DataTypeConversionP'
 * '<S108>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL/DataTypeConversionZ'
 * '<S109>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculatePL/Ground'
 * '<S110>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/CalculateYhat/Ground'
 * '<S111>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/Observer/MeasurementUpdate'
 * '<S112>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/ReducedQRN/Ground'
 * '<S113>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter2/UseCurrentEstimator/Enabled Subsystem'
 * '<S114>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL'
 * '<S115>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculateYhat'
 * '<S116>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CovarianceOutputConfigurator'
 * '<S117>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionA'
 * '<S118>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionB'
 * '<S119>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionC'
 * '<S120>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionD'
 * '<S121>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionEnable'
 * '<S122>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionG'
 * '<S123>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionH'
 * '<S124>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionN'
 * '<S125>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionP'
 * '<S126>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionP0'
 * '<S127>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionQ'
 * '<S128>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionR'
 * '<S129>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionReset'
 * '<S130>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionX'
 * '<S131>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionX0'
 * '<S132>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/DataTypeConversionu'
 * '<S133>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/MemoryP'
 * '<S134>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/Observer'
 * '<S135>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/ReducedQRN'
 * '<S136>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/Reset'
 * '<S137>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/Reshapeyhat'
 * '<S138>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/ScalarExpansionP0'
 * '<S139>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/ScalarExpansionQ'
 * '<S140>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/ScalarExpansionR'
 * '<S141>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/UseCurrentEstimator'
 * '<S142>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkA'
 * '<S143>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkB'
 * '<S144>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkC'
 * '<S145>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkD'
 * '<S146>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkEnable'
 * '<S147>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkG'
 * '<S148>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkH'
 * '<S149>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkN'
 * '<S150>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkP0'
 * '<S151>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkQ'
 * '<S152>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkR'
 * '<S153>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkReset'
 * '<S154>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checkX0'
 * '<S155>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checku'
 * '<S156>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/checky'
 * '<S157>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL/DataTypeConversionL'
 * '<S158>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL/DataTypeConversionM'
 * '<S159>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL/DataTypeConversionP'
 * '<S160>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL/DataTypeConversionZ'
 * '<S161>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculatePL/Ground'
 * '<S162>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/CalculateYhat/Ground'
 * '<S163>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/Observer/MeasurementUpdate'
 * '<S164>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/ReducedQRN/Ground'
 * '<S165>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter3/UseCurrentEstimator/Enabled Subsystem'
 * '<S166>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL'
 * '<S167>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculateYhat'
 * '<S168>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CovarianceOutputConfigurator'
 * '<S169>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionA'
 * '<S170>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionB'
 * '<S171>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionC'
 * '<S172>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionD'
 * '<S173>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionEnable'
 * '<S174>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionG'
 * '<S175>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionH'
 * '<S176>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionN'
 * '<S177>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionP'
 * '<S178>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionP0'
 * '<S179>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionQ'
 * '<S180>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionR'
 * '<S181>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionReset'
 * '<S182>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionX'
 * '<S183>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionX0'
 * '<S184>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/DataTypeConversionu'
 * '<S185>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/MemoryP'
 * '<S186>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/Observer'
 * '<S187>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/ReducedQRN'
 * '<S188>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/Reset'
 * '<S189>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/Reshapeyhat'
 * '<S190>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/ScalarExpansionP0'
 * '<S191>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/ScalarExpansionQ'
 * '<S192>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/ScalarExpansionR'
 * '<S193>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/UseCurrentEstimator'
 * '<S194>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkA'
 * '<S195>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkB'
 * '<S196>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkC'
 * '<S197>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkD'
 * '<S198>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkEnable'
 * '<S199>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkG'
 * '<S200>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkH'
 * '<S201>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkN'
 * '<S202>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkP0'
 * '<S203>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkQ'
 * '<S204>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkR'
 * '<S205>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkReset'
 * '<S206>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checkX0'
 * '<S207>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checku'
 * '<S208>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/checky'
 * '<S209>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL/DataTypeConversionL'
 * '<S210>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL/DataTypeConversionM'
 * '<S211>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL/DataTypeConversionP'
 * '<S212>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL/DataTypeConversionZ'
 * '<S213>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculatePL/Ground'
 * '<S214>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/CalculateYhat/Ground'
 * '<S215>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/Observer/MeasurementUpdate'
 * '<S216>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/ReducedQRN/Ground'
 * '<S217>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter4/UseCurrentEstimator/Enabled Subsystem'
 * '<S218>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL'
 * '<S219>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculateYhat'
 * '<S220>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CovarianceOutputConfigurator'
 * '<S221>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionA'
 * '<S222>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionB'
 * '<S223>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionC'
 * '<S224>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionD'
 * '<S225>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionEnable'
 * '<S226>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionG'
 * '<S227>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionH'
 * '<S228>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionN'
 * '<S229>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionP'
 * '<S230>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionP0'
 * '<S231>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionQ'
 * '<S232>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionR'
 * '<S233>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionReset'
 * '<S234>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionX'
 * '<S235>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionX0'
 * '<S236>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/DataTypeConversionu'
 * '<S237>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/MemoryP'
 * '<S238>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/Observer'
 * '<S239>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/ReducedQRN'
 * '<S240>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/Reset'
 * '<S241>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/Reshapeyhat'
 * '<S242>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/ScalarExpansionP0'
 * '<S243>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/ScalarExpansionQ'
 * '<S244>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/ScalarExpansionR'
 * '<S245>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/UseCurrentEstimator'
 * '<S246>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkA'
 * '<S247>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkB'
 * '<S248>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkC'
 * '<S249>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkD'
 * '<S250>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkEnable'
 * '<S251>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkG'
 * '<S252>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkH'
 * '<S253>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkN'
 * '<S254>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkP0'
 * '<S255>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkQ'
 * '<S256>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkR'
 * '<S257>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkReset'
 * '<S258>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checkX0'
 * '<S259>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checku'
 * '<S260>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/checky'
 * '<S261>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL/DataTypeConversionL'
 * '<S262>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL/DataTypeConversionM'
 * '<S263>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL/DataTypeConversionP'
 * '<S264>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL/DataTypeConversionZ'
 * '<S265>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculatePL/Ground'
 * '<S266>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/CalculateYhat/Ground'
 * '<S267>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/Observer/MeasurementUpdate'
 * '<S268>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/ReducedQRN/Ground'
 * '<S269>' : 'UAV_log/Flight Control System/Kalman Filter/Kalman Filter6/UseCurrentEstimator/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_UAV_log_h_ */

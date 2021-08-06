/*
 * UAV_log.h
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
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpSignalConversionAtToWork[9];/* '<S1>/Kalman Filter' */
  real_T p;                            /* '<S3>/Transfer Fcn15' */
  real_T q;                            /* '<S3>/Transfer Fcn16' */
  real_T r;                            /* '<S3>/Transfer Fcn17' */
  real_T r_g;                          /* '<S1>/Data Type Conversion1' */
  real_T V;                            /* '<S1>/Data Type Conversion11' */
  real_T p_l;                          /* '<S1>/Data Type Conversion2' */
  real_T q_d;                          /* '<S1>/Data Type Conversion3' */
  real_T h;                            /* '<S1>/Data Type Conversion4' */
  real_T v;                            /* '<S1>/Data Type Conversion5' */
  real_T u;                            /* '<S1>/Data Type Conversion6' */
  real_T ax;                           /* '<S1>/Data Type Conversion7' */
  real_T ay;                           /* '<S1>/Data Type Conversion8' */
  real_T az;                           /* '<S1>/Data Type Conversion9' */
  real_T Aue;                          /* '<S2>/Ax' */
  real_T Aue_k;                        /* '<S2>/Ax1' */
  real_T Athetae;                      /* '<S2>/Ax2' */
  real_T Aphie;                        /* '<S2>/Ax3' */
  real_T Azwe[2];                      /* '<S2>/Ax4' */
  real_T Cue;                          /* '<S2>/Cx' */
  real_T Cue_i;                        /* '<S2>/Cx1' */
  real_T Cthetae;                      /* '<S2>/Cx2' */
  real_T Cthetae_j;                    /* '<S2>/Cx3' */
  real_T Czwe;                         /* '<S2>/Cx4' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T Sum1;                         /* '<S2>/Sum1' */
  real_T Sum3;                         /* '<S2>/Sum3' */
  real_T Sum5;                         /* '<S2>/Sum5' */
  real_T Sum7[2];                      /* '<S2>/Sum7' */
  real_T ay_m;                         /* '<S3>/Transfer Fcn13' */
} B_UAV_log_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S2>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator5_DSTATE[2];/* '<S2>/Discrete-Time Integrator5' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<S2>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S2>/Discrete-Time Integrator3' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */
} DW_UAV_log_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn15_CSTATE;         /* '<S3>/Transfer Fcn15' */
  real_T TransferFcn16_CSTATE;         /* '<S3>/Transfer Fcn16' */
  real_T TransferFcn17_CSTATE;         /* '<S3>/Transfer Fcn17' */
  real_T TransferFcn13_CSTATE;         /* '<S3>/Transfer Fcn13' */
  real_T TransferFcn14_CSTATE;         /* '<S3>/Transfer Fcn14' */
  real_T TransferFcn12_CSTATE;         /* '<S3>/Transfer Fcn12' */
  real_T TransferFcn18_CSTATE;         /* '<S3>/Transfer Fcn18' */
  real_T TransferFcn10_CSTATE;         /* '<S3>/Transfer Fcn10' */
  real_T TransferFcn11_CSTATE;         /* '<S3>/Transfer Fcn11' */
  real_T TransferFcn19_CSTATE;         /* '<S3>/Transfer Fcn19' */
} X_UAV_log_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn15_CSTATE;         /* '<S3>/Transfer Fcn15' */
  real_T TransferFcn16_CSTATE;         /* '<S3>/Transfer Fcn16' */
  real_T TransferFcn17_CSTATE;         /* '<S3>/Transfer Fcn17' */
  real_T TransferFcn13_CSTATE;         /* '<S3>/Transfer Fcn13' */
  real_T TransferFcn14_CSTATE;         /* '<S3>/Transfer Fcn14' */
  real_T TransferFcn12_CSTATE;         /* '<S3>/Transfer Fcn12' */
  real_T TransferFcn18_CSTATE;         /* '<S3>/Transfer Fcn18' */
  real_T TransferFcn10_CSTATE;         /* '<S3>/Transfer Fcn10' */
  real_T TransferFcn11_CSTATE;         /* '<S3>/Transfer Fcn11' */
  real_T TransferFcn19_CSTATE;         /* '<S3>/Transfer Fcn19' */
} XDot_UAV_log_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn15_CSTATE;      /* '<S3>/Transfer Fcn15' */
  boolean_T TransferFcn16_CSTATE;      /* '<S3>/Transfer Fcn16' */
  boolean_T TransferFcn17_CSTATE;      /* '<S3>/Transfer Fcn17' */
  boolean_T TransferFcn13_CSTATE;      /* '<S3>/Transfer Fcn13' */
  boolean_T TransferFcn14_CSTATE;      /* '<S3>/Transfer Fcn14' */
  boolean_T TransferFcn12_CSTATE;      /* '<S3>/Transfer Fcn12' */
  boolean_T TransferFcn18_CSTATE;      /* '<S3>/Transfer Fcn18' */
  boolean_T TransferFcn10_CSTATE;      /* '<S3>/Transfer Fcn10' */
  boolean_T TransferFcn11_CSTATE;      /* '<S3>/Transfer Fcn11' */
  boolean_T TransferFcn19_CSTATE;      /* '<S3>/Transfer Fcn19' */
} XDis_UAV_log_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Motors[4];                  /* '<Root>/Motors' */
  uint8_T Flag;                        /* '<Root>/Flag' */
} ExtY_UAV_log_T;

/* Parameters (default storage) */
struct P_UAV_log_T_ {
  real_T A_double[4];                  /* Variable: A_double
                                        * Referenced by: '<S2>/Ax4'
                                        */
  real_T A_single;                     /* Variable: A_single
                                        * Referenced by:
                                        *   '<S2>/Ax'
                                        *   '<S2>/Ax1'
                                        *   '<S2>/Ax2'
                                        *   '<S2>/Ax3'
                                        */
  real_T B_double[2];                  /* Variable: B_double
                                        * Referenced by: '<S2>/gain4'
                                        */
  real_T B_single;                     /* Variable: B_single
                                        * Referenced by:
                                        *   '<S2>/gain'
                                        *   '<S2>/gain1'
                                        *   '<S2>/gain2'
                                        *   '<S2>/gain3'
                                        */
  real_T C_double[2];                  /* Variable: C_double
                                        * Referenced by: '<S2>/Cx4'
                                        */
  real_T C_single;                     /* Variable: C_single
                                        * Referenced by:
                                        *   '<S2>/Cx'
                                        *   '<S2>/Cx1'
                                        *   '<S2>/Cx2'
                                        *   '<S2>/Cx3'
                                        */
  real_T D_double;                     /* Variable: D_double
                                        * Referenced by: '<S2>/Dax4'
                                        */
  real_T D_single;                     /* Variable: D_single
                                        * Referenced by:
                                        *   '<S2>/Dax'
                                        *   '<S2>/Dax1'
                                        *   '<S2>/Dax2'
                                        *   '<S2>/Dax3'
                                        */
  real_T L_double[2];                  /* Variable: L_double
                                        * Referenced by: '<S2>/L(y-Cx-Du)4'
                                        */
  real_T L_single;                     /* Variable: L_single
                                        * Referenced by:
                                        *   '<S2>/L(y-Cx-Du)'
                                        *   '<S2>/L(y-Cx-Du)1'
                                        *   '<S2>/L(y-Cx-Du)2'
                                        *   '<S2>/L(y-Cx-Du)3'
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
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator2'
                           */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator5_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator5_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator5'
                           */
  real_T DiscreteTimeIntegrator5_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator5'
                                        */
  real_T TransferFcn15_A;              /* Computed Parameter: TransferFcn15_A
                                        * Referenced by: '<S3>/Transfer Fcn15'
                                        */
  real_T TransferFcn15_C;              /* Computed Parameter: TransferFcn15_C
                                        * Referenced by: '<S3>/Transfer Fcn15'
                                        */
  real_T TransferFcn16_A;              /* Computed Parameter: TransferFcn16_A
                                        * Referenced by: '<S3>/Transfer Fcn16'
                                        */
  real_T TransferFcn16_C;              /* Computed Parameter: TransferFcn16_C
                                        * Referenced by: '<S3>/Transfer Fcn16'
                                        */
  real_T TransferFcn17_A;              /* Computed Parameter: TransferFcn17_A
                                        * Referenced by: '<S3>/Transfer Fcn17'
                                        */
  real_T TransferFcn17_C;              /* Computed Parameter: TransferFcn17_C
                                        * Referenced by: '<S3>/Transfer Fcn17'
                                        */
  real_T DiscreteTimeIntegrator4_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator4_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator4'
                           */
  real_T DiscreteTimeIntegrator4_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator4'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<S2>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  real_T TransferFcn13_A;              /* Computed Parameter: TransferFcn13_A
                                        * Referenced by: '<S3>/Transfer Fcn13'
                                        */
  real_T TransferFcn13_C;              /* Computed Parameter: TransferFcn13_C
                                        * Referenced by: '<S3>/Transfer Fcn13'
                                        */
  real_T TransferFcn14_A;              /* Computed Parameter: TransferFcn14_A
                                        * Referenced by: '<S3>/Transfer Fcn14'
                                        */
  real_T TransferFcn14_C;              /* Computed Parameter: TransferFcn14_C
                                        * Referenced by: '<S3>/Transfer Fcn14'
                                        */
  real_T Constant_Value_n;             /* Expression: 0.00001
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T TransferFcn12_A;              /* Computed Parameter: TransferFcn12_A
                                        * Referenced by: '<S3>/Transfer Fcn12'
                                        */
  real_T TransferFcn12_C;              /* Computed Parameter: TransferFcn12_C
                                        * Referenced by: '<S3>/Transfer Fcn12'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.001
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T TransferFcn18_A;              /* Computed Parameter: TransferFcn18_A
                                        * Referenced by: '<S3>/Transfer Fcn18'
                                        */
  real_T TransferFcn18_C;              /* Computed Parameter: TransferFcn18_C
                                        * Referenced by: '<S3>/Transfer Fcn18'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T TransferFcn10_A;              /* Computed Parameter: TransferFcn10_A
                                        * Referenced by: '<S3>/Transfer Fcn10'
                                        */
  real_T TransferFcn10_C;              /* Computed Parameter: TransferFcn10_C
                                        * Referenced by: '<S3>/Transfer Fcn10'
                                        */
  real_T TransferFcn11_A;              /* Computed Parameter: TransferFcn11_A
                                        * Referenced by: '<S3>/Transfer Fcn11'
                                        */
  real_T TransferFcn11_C;              /* Computed Parameter: TransferFcn11_C
                                        * Referenced by: '<S3>/Transfer Fcn11'
                                        */
  real_T TransferFcn19_A;              /* Computed Parameter: TransferFcn19_A
                                        * Referenced by: '<S3>/Transfer Fcn19'
                                        */
  real_T TransferFcn19_C;              /* Computed Parameter: TransferFcn19_C
                                        * Referenced by: '<S3>/Transfer Fcn19'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S1>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S1>/Saturation1'
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
};

/* Real-time Model Data Structure */
struct tag_RTM_UAV_log_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_UAV_log_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[10];
  real_T odeF[3][10];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_UAV_log_T UAV_log_P;

/* Block signals (default storage) */
extern B_UAV_log_T UAV_log_B;

/* Continuous states (default storage) */
extern X_UAV_log_T UAV_log_X;

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
 */
#endif                                 /* RTW_HEADER_UAV_log_h_ */

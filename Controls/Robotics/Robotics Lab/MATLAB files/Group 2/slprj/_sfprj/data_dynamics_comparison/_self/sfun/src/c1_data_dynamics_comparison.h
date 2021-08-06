#ifndef __c1_data_dynamics_comparison_h__
#define __c1_data_dynamics_comparison_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c1_ResolvedFunctionInfo
#define typedef_c1_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c1_ResolvedFunctionInfo;

#endif                                 /*typedef_c1_ResolvedFunctionInfo*/

#ifndef typedef_SFc1_data_dynamics_comparisonInstanceStruct
#define typedef_SFc1_data_dynamics_comparisonInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc1_data_dynamics_comparisonInstanceStruct;

#endif                                 /*typedef_SFc1_data_dynamics_comparisonInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_data_dynamics_comparison_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_data_dynamics_comparison_get_check_sum(mxArray *plhs[]);
extern void c1_data_dynamics_comparison_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif

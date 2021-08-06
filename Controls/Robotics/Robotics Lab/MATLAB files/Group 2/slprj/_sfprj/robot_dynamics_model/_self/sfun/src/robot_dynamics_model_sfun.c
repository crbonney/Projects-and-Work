/* Include files */

#include "robot_dynamics_model_sfun.h"
#include "c1_robot_dynamics_model.h"
#include "c2_robot_dynamics_model.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _robot_dynamics_modelMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void robot_dynamics_model_initializer(void)
{
}

void robot_dynamics_model_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_robot_dynamics_model_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_robot_dynamics_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_robot_dynamics_model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_robot_dynamics_model_process_testpoint_info_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "robot_dynamics_model")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_robot_dynamics_model_get_testpoint_info(void);
        plhs[0] = sf_c1_robot_dynamics_model_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_robot_dynamics_model_get_testpoint_info(void);
        plhs[0] = sf_c2_robot_dynamics_model_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_robot_dynamics_model_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3319212047U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2372593236U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3188472482U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1621816837U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1244681319U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2213711989U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1699267020U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1298653969U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_robot_dynamics_model_get_check_sum(mxArray *plhs[]);
          sf_c1_robot_dynamics_model_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_robot_dynamics_model_get_check_sum(mxArray *plhs[]);
          sf_c2_robot_dynamics_model_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(784597580U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(508478511U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1608615269U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1082679159U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1935733278U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(404337134U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2731124298U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1253442411U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_robot_dynamics_model_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "33lZRLkVsu4YvjHaLgpf8E") == 0) {
          extern mxArray *sf_c1_robot_dynamics_model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_robot_dynamics_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "u4aECYgFsIh5714bPukpfF") == 0) {
          extern mxArray *sf_c2_robot_dynamics_model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_robot_dynamics_model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_robot_dynamics_model_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_robot_dynamics_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_robot_dynamics_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_robot_dynamics_model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_robot_dynamics_model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void robot_dynamics_model_debug_initialize(void)
{
  _robot_dynamics_modelMachineNumber_ = sf_debug_initialize_machine(
    "robot_dynamics_model","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(_robot_dynamics_modelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_robot_dynamics_modelMachineNumber_,0);
}

void robot_dynamics_model_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_robot_dynamics_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "robot_dynamics_model", "robot_dynamics_model");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_robot_dynamics_model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}

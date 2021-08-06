/* Include files */

#include "hamiltonian_data_collector_sfun.h"
#include "c1_hamiltonian_data_collector.h"
#include "c2_hamiltonian_data_collector.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _hamiltonian_data_collectorMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void hamiltonian_data_collector_initializer(void)
{
}

void hamiltonian_data_collector_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_hamiltonian_data_collector_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_hamiltonian_data_collector_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_hamiltonian_data_collector_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_hamiltonian_data_collector_process_testpoint_info_call( int nlhs,
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
  if (!strcmp(machineName, "hamiltonian_data_collector")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_hamiltonian_data_collector_get_testpoint_info(void);
        plhs[0] = sf_c1_hamiltonian_data_collector_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_hamiltonian_data_collector_get_testpoint_info(void);
        plhs[0] = sf_c2_hamiltonian_data_collector_get_testpoint_info();
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

unsigned int sf_hamiltonian_data_collector_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1214227498U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1667679046U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2929723072U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3184097525U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1572546448U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2291031625U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1797400238U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2891141775U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_hamiltonian_data_collector_get_check_sum(mxArray
            *plhs[]);
          sf_c1_hamiltonian_data_collector_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_hamiltonian_data_collector_get_check_sum(mxArray
            *plhs[]);
          sf_c2_hamiltonian_data_collector_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4229754976U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1061950418U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1739420796U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2063438836U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_hamiltonian_data_collector_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "DjyGoijFEQua0YZKmyCmNG") == 0) {
          extern mxArray
            *sf_c1_hamiltonian_data_collector_get_autoinheritance_info(void);
          plhs[0] = sf_c1_hamiltonian_data_collector_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "WKGVZgwQlZZ7lKxFUzXUiE") == 0) {
          extern mxArray
            *sf_c2_hamiltonian_data_collector_get_autoinheritance_info(void);
          plhs[0] = sf_c2_hamiltonian_data_collector_get_autoinheritance_info();
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

unsigned int sf_hamiltonian_data_collector_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_hamiltonian_data_collector_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_hamiltonian_data_collector_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_hamiltonian_data_collector_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_hamiltonian_data_collector_get_eml_resolved_functions_info();
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

void hamiltonian_data_collector_debug_initialize(void)
{
  _hamiltonian_data_collectorMachineNumber_ = sf_debug_initialize_machine(
    "hamiltonian_data_collector","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_hamiltonian_data_collectorMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_hamiltonian_data_collectorMachineNumber_,
    0);
}

void hamiltonian_data_collector_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_hamiltonian_data_collector_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "hamiltonian_data_collector", "hamiltonian_data_collector");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_hamiltonian_data_collector_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
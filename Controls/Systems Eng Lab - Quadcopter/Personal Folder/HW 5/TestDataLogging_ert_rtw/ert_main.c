#include "TestDataLogging.h"
#include "rtwtypes.h"
#include "rt_logging.h"
#ifndef SAVEFILE
# define MATFILE2(file)                #file ".mat"
# define MATFILE1(file)                MATFILE2(file)
# define MATFILE                       MATFILE1(MODEL)
#else
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              /* need to expand name */
# define MATFILE                       QUOTE(SAVEFILE)
#endif

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  TestDataLogging_step();

  /* Get model outputs here */
  OverrunFlag--;
}

#define UNUSED(x)                      x = x

volatile boolean_T stopRequested = false;
volatile boolean_T runModel = false;
int main(void)
{
  float modelBaseRate = 0.005;
  float systemClock = 416;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  UNUSED(modelBaseRate);
  UNUSED(systemClock);
  rtmSetErrorStatus(TestDataLogging_M, 0);
  TestDataLogging_initialize();
  runModel =
    (rtmGetErrorStatus(TestDataLogging_M) == (NULL)) && !rtmGetStopRequested
    (TestDataLogging_M);
  ;
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      (rtmGetErrorStatus(TestDataLogging_M) == (NULL)) &&
                      !rtmGetStopRequested(TestDataLogging_M));
    runModel = !(stopRequested);
  }

  rt_StopDataLogging(MATFILE, TestDataLogging_M->rtwLogInfo);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  TestDataLogging_terminate();
  ;
  return 0;
}

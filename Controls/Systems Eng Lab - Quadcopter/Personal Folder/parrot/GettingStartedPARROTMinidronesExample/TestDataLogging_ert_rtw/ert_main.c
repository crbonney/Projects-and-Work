#include "TestDataLogging.h"
#include "rtwtypes.h"
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>
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
  rtExtModeCheckEndTrigger();
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

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  TestDataLogging_initialize();
  ;

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(TestDataLogging_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(TestDataLogging_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(TestDataLogging_M, true);
    }
  }

  rtERTExtModeStartMsg();
  ;
  runModel =
    (rtmGetErrorStatus(TestDataLogging_M) == (NULL)) && !rtmGetStopRequested
    (TestDataLogging_M);
  ;
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(TestDataLogging_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(TestDataLogging_M, true);
      }
    }

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
  rtExtModeShutdown(1);
  ;
  return 0;
}

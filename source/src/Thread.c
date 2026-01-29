//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Thread.c
// Summary  : To create & join threads
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 29/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "Thread.h"
#include "TempRead.h"
#include "TempCheck.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************
THREAD_HANDLER ThreadHandler[] = {{0, TempReadThread},
                                  {0, TempCheckThread}
                                 };

//******************************* Local Functions ******************************

//********************************.CreateThreads.*******************************
//Purpose : To create and join all the threads in the implementation
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool CreateThreads()
{
    bool blRet = false;
    uint8_t ucMaxThreadCount = 0;
    ucMaxThreadCount = sizeof(ThreadHandler)/sizeof(ThreadHandler[0]);

    for (uint8_t ucindex = 0; ucindex < ucMaxThreadCount; ucindex++)
    {
        if(pthread_create(&ThreadHandler[ucindex].lThreadId, NULL, 
                            ThreadHandler[ucindex].func, NULL) == 0)
        {
            blRet = true;
        }
    }

    for (uint8_t ucindex = 0; ucindex < ucMaxThreadCount; ucindex++) 
    {
        if(pthread_join(ThreadHandler[ucindex].lThreadId, NULL) == 0)
        {
            blRet = true;
        }
    }

    return blRet;
}
//EOF
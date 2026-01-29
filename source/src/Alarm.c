//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Alarm.c
// Summary  : To receive alarm trigger and process it
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
#include "Alarm.h"
#include "Semaphore.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//****************************.AlarmThread.*************************************
//Purpose : This thread work for alarm
//Inputs  : Directory in the PC from which we need to read files as CLA
//Outputs : None
//Return  : None
//Notes   : None
//*
void* AlarmThread(void *arg)
{
    (void)arg;
    InitializeAlarmSemaphore();

    while(1)
    {
        AlarmSemaphoreWait(&lAlarmSemFlag);
        printf("Alarm Triggered\n");
    }

    return NULL;
}

//**************************.InitializeAlarmSemaphore.**************************
//Purpose : To initialize alarm semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool InitializeAlarmSemaphore()
{
    bool blRet = false;

    if(SemaphoreInit() != false)
    {
        blRet = true;
    }

    return blRet;
}

//******************************.AlarmSemaphoreWait.****************************
//Purpose : main function.
//Inputs  : lAlarmSemFlag - semaphore flag
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool AlarmSemaphoreWait(sem_t *lAlarmSemFlag)
{
    bool blRet = false;

    if(SemaphoreWait(lAlarmSemFlag) == 0)
    {
        blRet = true;
    }

    return blRet;
}

//******************************.AlarmSemaphorePost.****************************
//Purpose : main function.
//Inputs  : lAlarmSemFlag - semaphore flag
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool AlarmSemaphorePost(sem_t *lAlarmSemFlag)
{
    bool blRet = false;

    if(SemaphorePost(lAlarmSemFlag) == 0)
    {
        blRet = true;
    }

    return blRet;
}
//EOF


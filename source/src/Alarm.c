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
void* AlarmThread(void *pArg)
{
    (void)pArg;
    AlarmSemaphoreInilialize();

    while(1)
    {
        AlarmSemaphoreWait();
        printf("Alarm Triggered\n");
    }

    return NULL;
}

//**************************.AlarmSemaphoreInilialize.**************************
//Purpose : To initialize alarm semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool AlarmSemaphoreInilialize()
{
    bool blRet = false;

    if(SemaphoreInit() != false)
    {
        blRet = true;
    }

    return blRet;
}

//******************************.AlarmSemaphoreWait.****************************
//Purpose : wrapper function for SemaphoreWait()
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool AlarmSemaphoreWait()
{
    bool blRet = false;

    if(SemaphoreWait() == 0)
    {
        blRet = true;
    }

    return blRet;
}

//******************************.AlarmSemaphorePost.****************************
//Purpose : Wrapper function for SemaphorePost()
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool AlarmSemaphorePost()
{
    bool blRet = false;

    if(SemaphorePost() == 0)
    {
        blRet = true;
    }

    return blRet;
}
//EOF


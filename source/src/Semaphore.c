//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Semaphore.c
// Summary  : Semaphore wrapper functions
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************
sem_t lAlarmSemFlag;

//******************************* Local Functions ******************************

//********************************.SemaphoreInit.*******************************
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SemaphoreInit()
{
    bool blRet = false;

    if(sem_init(&lAlarmSemFlag, 0, 0) == 0)
    {
        blRet = true;
    }

    return blRet;
}

//********************************.SemaphoreWait.*******************************
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SemaphoreWait()
{
    bool blRet = false;

    if(sem_wait(&lAlarmSemFlag) == 0)
    {
        blRet = true;
    }

    return blRet;
}

//********************************.SemaphorePost.*******************************
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SemaphorePost()
{
    bool blRet = false;

    if(sem_post(&lAlarmSemFlag) == 0)
    {
        blRet = true;
    }

    return blRet;
}
//EOF
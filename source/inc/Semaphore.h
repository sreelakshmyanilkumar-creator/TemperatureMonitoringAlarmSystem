//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Semaphore.h
// Summary  : Wrapper functions for semaphore
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 29/01/2026
//
//******************************************************************************
#ifndef _SEMAPHORE_H_ 
#define _SEMAPHORE_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
extern sem_t lAlarmSemFlag;

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool SemaphoreInit();
bool SemaphorePost(sem_t *lAlarmSemFlag);
bool SemaphoreWait(sem_t *lAlarmSemFlag);
#endif //_SEMAPHORE_H_
//EOF
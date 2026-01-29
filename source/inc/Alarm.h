//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Alarm.h
// Summary  : To receive alarm trigger and process it
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 29/01/2026
//
//******************************************************************************
#ifndef _ALARM_H_ 
#define _ALARM_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
extern sem_t AlarmFlag;

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void* AlarmThread(void *arg);
bool InitializeAlarmSemaphore();
bool AlarmSemaphoreWait(sem_t *lAlarmSemFlag);
bool AlarmSemaphorePost(sem_t *lAlarmSemFlag);
#endif //_ALARM_H_
//EOF
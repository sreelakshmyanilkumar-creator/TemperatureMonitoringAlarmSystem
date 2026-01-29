//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Thread.h
// Summary  : To create & join threads
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 29/01/2026
//
//******************************************************************************
#ifndef _THREAD_H_ 
#define _THREAD_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************
typedef struct _THREAD_HANDLER_
{
    pthread_t lThreadId;
    void* (*func) (void*);
}THREAD_HANDLER;

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool CreateThreads();
#endif //_THREAD_H_
//EOF
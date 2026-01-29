//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : TempRead.h
// Summary  : To read process and send tempearature data
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************
#ifndef _TEMP_READ_H_ 
#define _TEMP_READ_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

//***************************** Global Constants *******************************

//******************************* Global Types *********************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void* TempReadThread(void* arg);
bool ReadTemp(int8_t *pscTempValue);
#endif //_TEMP_READ_H_
//EOF
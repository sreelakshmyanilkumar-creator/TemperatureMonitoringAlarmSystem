//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : TempCheck.h
// Summary  : To check and trigger alarm comparing with threshold limits
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************
#ifndef _TEMP_CHECK_H_ 
#define _TEMP_CHECK_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "TempCheck.h"
#include "MessageQueue.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define MAX_BREACH_COUNT    (5)
//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void* TempCheckThread(void* arg);
bool TempCheckMessageQueueCreate();
bool TempCheckMessageQueueSend(uint8_t *pucMsgQTempData, size_t lMsgQSize);
bool TempCheckMessageQueueReceive(uint8_t *pucMsgQTempData, size_t lMsgQSize);
bool TempCheckForThresholds(uint8_t *pucMsgQTempData, 
                            uint8_t *psucThresholdBreachCount);
#endif //_TEMP_CHECK_H_
//EOF
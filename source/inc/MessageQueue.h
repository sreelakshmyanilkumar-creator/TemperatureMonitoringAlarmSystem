//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : MessageQueue.h
// Summary  : To create, send, receive message queue
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************
#ifndef _MESSAGE_QUEUE_H_ 
#define _MESSAGE_QUEUE_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define MSG_QUEUE_FAIL          (-1)
#define MSG_QUEUE_TYPE          (1)
#define MSG_QUEUE_FLAG          (0)
#define MSG_QUEUE_PROJECT_ID    (66)
#define PERMISSION_MASK         (0666)
#define MSG_QUEUE_MAX_MESSAGES  (10)
#define MSG_QUEUE_MAX_MSG_SIZE  (sizeof(int8_t))
#define QUEUE_NAME              "/tempqueue"

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool MessageQueueCreate();
bool MessageQueueSend(int8_t *pscMessageQueueData, size_t lMsgQSize);
bool MessageQueueReceive(int8_t *pscMessageQueueData, size_t lMsgQSize);
#endif //_MESSAGE_QUEUE_H_
//EOF
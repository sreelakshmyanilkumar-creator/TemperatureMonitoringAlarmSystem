//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : TempCheck.c
// Summary  : To check and trigger alarm comparing with threshold limits
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
#include "MessageQueue.h"
#include "TempCheck.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.TempCheckThread.*****************************
//Purpose : Thread function to check the temperature value against the minimum
//          and maximum thresholds and trigger the alarm if breach happens
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void* TempCheckThread(void *arg)
{
    int8_t scTempValue = 0;
    (void)arg;

    TempCheckMessageQueueCreate();

    while(1)
    {
        if(TempCheckMessageQueueReceive(&scTempValue, 
                                        MSG_QUEUE_MAX_MSG_SIZE) != false)
        {
            printf("Message Received successfully, Data = %d\n",scTempValue);
        }
    }

    return NULL;
}

//*************************.TempCheckMessageQueueCreate.************************
//Purpose : Thread function to check the temperature value against the minimum
//          and maximum thresholds and trigger the alarm if breach happens
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckMessageQueueCreate()
{
    bool blRet = false;

    if(MessageQueueCreate() != false)
    {
        blRet = true;
    }

    return blRet;
}

//***************************.TempCheckMessageQueueSend.************************
//Purpose : Thread function to check the temperature value against the minimum
//          and maximum thresholds and trigger the alarm if breach happens
//Inputs  : pstMsgQTempData - Data to be send in message queue
//          lMsgQSize - message queue size
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckMessageQueueSend(int8_t *pscMsgQTempData, size_t lMsgQSize)
{
    bool blRet = false;

    if(pscMsgQTempData != NULL)
    {
        if(MessageQueueSend(pscMsgQTempData, lMsgQSize) != false)
        {
            blRet = true;
        }
    }

    return blRet;
}

//************************.TempCheckMessageQueueReceive.************************
//Purpose : Thread function to check the temperature value against the minimum
//          and maximum thresholds and trigger the alarm if breach happens
//Inputs  : lMsgQSize - message queue size
//Outputs : pscMsgQTempData - to receieve data from message queue
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckMessageQueueReceive(int8_t *pscMsgQTempData, size_t lMsgQSize)
{
    bool blRet = false;

    if(MessageQueueReceive(pscMsgQTempData , lMsgQSize) != false)
    {
        blRet = true;
    }

    return blRet;
}
//EOF
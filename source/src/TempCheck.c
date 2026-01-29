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
#include "Sensor.h"
#include "Alarm.h"
#include "Semaphore.h"

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
    int8_t cTempValue = 0;
    static uint8_t sucThresholdBreachCount = 0;
    (void)arg;

    TempCheckMessageQueueCreate();

    while(1)
    {
        if(TempCheckMessageQueueReceive(&cTempValue, 
                                        MSG_QUEUE_MAX_MSG_SIZE) != false)
        {
            printf("Message Received successfully, Data = %d\n",cTempValue);

            if(TempCheckForThresholds(&cTempValue, &sucThresholdBreachCount) 
                                        != false)
            {
                AlarmSemaphorePost(&lAlarmSemFlag);
            }
        }
    }

    return NULL;
}

//*************************.TempCheckMessageQueueCreate.************************
//Purpose : To create message queue
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
//Purpose : To send data via message queue
//Inputs  : pstMsgQTempData - Data to be send in message queue
//          lMsgQSize - message queue size
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckMessageQueueSend(int8_t *pcMsgQTempData, size_t lMsgQSize)
{
    bool blRet = false;

    if(pcMsgQTempData != NULL)
    {
        if(MessageQueueSend(pcMsgQTempData, lMsgQSize) != false)
        {
            blRet = true;
        }
    }

    return blRet;
}

//************************.TempCheckMessageQueueReceive.************************
//Purpose : To receive data via message queue
//Inputs  : lMsgQSize - message queue size
//Outputs : pscMsgQTempData - to receieve data from message queue
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckMessageQueueReceive(int8_t *pcMsgQTempData, size_t lMsgQSize)
{
    bool blRet = false;

    if(MessageQueueReceive(pcMsgQTempData , lMsgQSize) != false)
    {
        blRet = true;
    }

    return blRet;
}

//************************.TempCheckForThresholds.************************
//Purpose : To compare the read value with thresholds and find out 5 consecutive
//          breaches
//Inputs  : pcMsgQTempData - Read temperature value
//Outputs : psucThresholdBreachCount - breach count is incremented for every 
//          breach
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool TempCheckForThresholds(int8_t *pcMsgQTempData, 
                            uint8_t *psucThresholdBreachCount)
{
    bool blRet = false;

    if(*pcMsgQTempData < TEMP_THRESHOLD_MIN || 
        *pcMsgQTempData > TEMP_THRESHOLD_MAX)
    {
        (*psucThresholdBreachCount)++;
    }
    else
    {
        *psucThresholdBreachCount = 0;
    }

    if(*psucThresholdBreachCount > MAX_BREACH_COUNT)
    {
        blRet = true;
    }

    return blRet;
}
//EOF
//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : TempRead.c
// Summary  : Reading temperature value from sensor every 20 ms and sent for 
//            checking threasholds
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "TempRead.h"
#include "TempCheck.h"
#include "Sensor.h"
#include "MessageQueue.h"
#include "Sleep.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.TempReadThread.******************************
//Purpose : To read temperature data from sensor and 
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void* TempReadThread(void *arg)
{
    int8_t cTempValue = 0;
    (void)arg;

    while(1)
    {
        if(ReadTemp(&cTempValue) != false)
        {
            if(TempCheckMessageQueueSend(&cTempValue, MSG_QUEUE_MAX_MSG_SIZE) 
                                        != false)
            {
                printf("Message send successfully, Data = %d\n", cTempValue);
            }
        }

        msleep(20);
    }

    return NULL;
}

//********************************.ReadTemp.************************************
//Purpose : To read temperature data from sensor
//Inputs  : None
//Outputs : pscTempValue - Update temperature sensor value
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool ReadTemp(int8_t *pcTempValue)
{
    bool blRet = false;

    if(pcTempValue != NULL)
    {
        blRet = SensorRead(pcTempValue);
    }

    return blRet;
}
//EOF
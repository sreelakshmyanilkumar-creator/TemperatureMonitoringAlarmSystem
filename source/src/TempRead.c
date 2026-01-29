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
void* TempReadThread(void *pArg)
{
    uint8_t ucTempValue = 0;
    (void)pArg;

    while(1)
    {
        if(ReadTemp(&ucTempValue) != false)
        {
            if(TempCheckMessageQueueSend(&ucTempValue, MSG_QUEUE_MAX_MSG_SIZE) 
                                        != false)
            {
                printf("Message send successfully, Data = %d\n", 
                        (int8_t)ucTempValue);
            }
        }

        msleep(20);
    }

    return NULL;
}

//********************************.ReadTemp.************************************
//Purpose : To read temperature data from sensor
//Inputs  : None
//Outputs : pucTempValue - Update temperature sensor value
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool ReadTemp(uint8_t *pucTempValue)
{
    bool blRet = false;

    if(pucTempValue != NULL)
    {
        blRet = SensorRead(pucTempValue);
    }

    return blRet;
}
//EOF
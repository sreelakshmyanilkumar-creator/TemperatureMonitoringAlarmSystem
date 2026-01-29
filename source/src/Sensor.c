//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Sensor.c
// Summary  : Read temperature sensor
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
#include "Sensor.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.SensorRead.**********************************
//Purpose : To read the temperature value from sensor
//Inputs  : None
//Outputs : pcTempValue - Read temperature value
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SensorRead(int8_t *pcTempValue)
{
    bool blRet = false;
    
    *pcTempValue = (rand() % (TEMP_THRESHOLD_MAX - (TEMP_THRESHOLD_MIN) + 
                    RANGE_ADJUST)) + (TEMP_THRESHOLD_MIN);

    //Comparing with assumed sensor max and min values
    if(*pcTempValue > TEMP_SENSOR_MIN || *pcTempValue < TEMP_SENSOR_MAX)
    {
        blRet = true;
    }

    return blRet;
}
//EOF
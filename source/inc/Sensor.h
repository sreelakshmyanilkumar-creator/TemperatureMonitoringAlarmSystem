//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Sendor.h
// Summary  : To read from tempearature sensor
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************
#ifndef _SENSOR_H_ 
#define _SENSOR_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define TEMP_THRESHOLD_MAX  (50)
#define TEMP_THRESHOLD_MIN  (-10)
#define RANGE_ADJUST        (1)

//Assume sensor reads in this range
#define TEMP_SENSOR_MAX     (125) 
#define TEMP_SENSOR_MIN     (-40)

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool SensorRead(uint8_t *pucTempValue);
#endif //_SENSOR_H_
//EOF
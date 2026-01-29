//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Sleep.c
// Summary  : To create different sleep functions for development
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 29/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "Sleep.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.msleep.**************************************
//Purpose : To generate a sleep function in milliseconds.
//Inputs  : ucTimeInMilliSeconds - time in milliseconds
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool msleep(uint32_t ucTimeInMilliSeconds) 
{ 
    bool blRet = false;
    if(usleep(ucTimeInMilliSeconds * 1000) == 0)
    {
        blRet = true;
    }

    return blRet;
}
//EOF
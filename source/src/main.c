//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : main.c
// Summary  : implements continuous temperature monitoring and triggers an alarm
//            whenever readings exceed defined limits
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
#include <pthread.h>
#include "TempCheck.h"
#include "Thread.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************
#define FAILURE             (1)
#define SUCCESS             (0)

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.main.****************************************
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Interger value - Upon success return will be 0 else 1
//Notes   : None
//*
int main(void)
{
    int lRet = FAILURE;
    
    if(CreateThreads())
    {
        lRet = SUCCESS;
    }
    
    return lRet;
}
//EOF

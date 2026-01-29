//************************* Temperature Alarm System ***************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : MessageQueue.c
// Summary  : Definition of Message queue wrapper functions
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 28/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdbool.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "MessageQueue.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.MessageQueueCreate.**************************
//Purpose : MessageQueueCreate function.
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueueCreate()
{
    bool blRet = false;

    struct mq_attr stMsgQueueAttr; 
    stMsgQueueAttr.mq_flags = 0;
    stMsgQueueAttr.mq_maxmsg = MSG_QUEUE_MAX_MESSAGES;
    stMsgQueueAttr.mq_msgsize = MSG_QUEUE_MAX_MSG_SIZE;
    stMsgQueueAttr.mq_curmsgs = 0;

    mqd_t lTempMsgQueue = mq_open(QUEUE_NAME, O_CREAT | 
                                O_RDWR, PERMISSION_MASK, 
                                &stMsgQueueAttr);
    
    if (lTempMsgQueue != (mqd_t)-1)
    {
        blRet = true;
    }
    else
    {
        printf("mq_open failed"); 
    }

    return blRet;
}

//*****************************.MessageQueueSend.*******************************
//Purpose : MessageQueueCreate function.
//Inputs  : pscMessageQueueData - Data to be send in message queue
//          lMsgQSize - message queue size
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueueSend(int8_t *pscMessageQueueData, size_t lMsgQSize)
{
    bool blRet = false;

    if(pscMessageQueueData != NULL)
    {
        mqd_t lTempMsgQueue = mq_open(QUEUE_NAME, O_WRONLY);
        
        if (lTempMsgQueue == (mqd_t)-1)
        {
            printf("mq_open failed");
        }
        else
        {
            if (mq_send(lTempMsgQueue, (char*)pscMessageQueueData, 
                        lMsgQSize, 0) == -1) 
            { 
                printf("mq_send failed"); 
            }
            else
            {
                blRet = true;
            }
        }

        mq_close(lTempMsgQueue);
    }

    return blRet;
}

//****************************.MessageQueueReceive.*****************************
//Purpose : To receive data in message queue 
//Inputs  : lMsgQSize - message queue size
//Outputs : pscMessageQueueData - Data to be received in message queue
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueueReceive(int8_t *pscMessageQueueData, size_t lMsgQSize)
{
    bool blRet = false;

    mqd_t lTempMsgQueue = mq_open(QUEUE_NAME, O_RDONLY);
    
    if (lTempMsgQueue == (mqd_t)-1)
    {
        printf("Producer mq_open failed");
    }

    if (mq_receive(lTempMsgQueue, (char*)pscMessageQueueData, lMsgQSize, 
        NULL) == -1)
    {
        printf("mq_receive failed");
    } 
    else 
    { 
        blRet = true;
    }

    mq_close(lTempMsgQueue);

    return blRet;
}
//EOF
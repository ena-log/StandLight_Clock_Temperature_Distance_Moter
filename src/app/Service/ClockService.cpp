#include "ClockService.h"

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view;
    clockState = CLOCK;
    counterTime = 0;
}

ClockService::~ClockService()
{

}

void ClockService::updateEvent()
{
    if (clockState == CLOCK)
    {
        curTime = time(NULL);
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }
    else if (clockState == COUTNER_START)
    {
        curTime = time(NULL) - counterTime;
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }
    else if (clockState == COUNTER_STOP)
    {
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }
}

void ClockService::updateState(std::string strState)
{
    switch (clockState)
    {
        case CLOCK:
            if (strState == "clockButton") 
            {
                counterTime = time(NULL)+(60*60*9+1);
                clockState = COUTNER_START;
            }
        break;

        case COUTNER_START:
            if (strState == "clockButton") {
                counterTime = curTime;
                clockState = COUNTER_STOP;
            }
        break;

        case COUNTER_STOP:
            if (strState == "clockButton") 
            {
                clockState = CLOCK;
            }
        break;
    }

}
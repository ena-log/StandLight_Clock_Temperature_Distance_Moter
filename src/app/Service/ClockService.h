#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"
#include "clockState.h"

#pragma once

class ClockService
{
private:
    time_t curTime;
    ClockView *clockView;
    int clockState;
    time_t counterTime;

public:
    ClockService(ClockView *clockView);
    virtual ~ClockService();
    void updateEvent();
    void updateState(std::string strState);

};

#endif
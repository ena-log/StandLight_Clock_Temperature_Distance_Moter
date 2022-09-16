#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"

#pragma once

class ClockService
{
private:
    time_t curTime;
    ClockView *clockView;

public:
    ClockService(ClockView *clockView);
    virtual ~ClockService();
    void updateEvent();

};

#endif
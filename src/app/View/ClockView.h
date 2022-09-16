#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include <time.h>
#include "LCD.h"

#pragma once

class ClockView
{
private:
    struct tm timeDate;
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    virtual ~ClockView();
    void updateTime(struct tm *timeDate);

};

#endif
#ifndef MOTORVIEW_H
#define MOTORVIEW_H

#include "Motor.h"
#include "motorState.h"
#include <string>

#pragma once

class MotorView
{
private:
    int motorState;
    Motor *motor;

public:
    MotorView(Motor *motor);
    ~MotorView();
    void setState(int state);
    void motorView();
    void motorOn();
    void motorOff();
};

#endif
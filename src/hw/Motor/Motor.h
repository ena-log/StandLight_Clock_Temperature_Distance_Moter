#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>
#include <softPwm.h>

#pragma once

class Motor
{
private:
    const int ON = 99;
    const int OFF = 0;
    int pinNumber;
    int fanState;

    void writePin(int fanState);

public:
    Motor(int pin);
    ~Motor();
    void On();
    void Off();

};

#endif
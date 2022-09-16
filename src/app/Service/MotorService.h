#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#include "MotorView.h"
#include "motorState.h"

#pragma once

class MotorService
{
private:
    int motorState;
    MotorView *motorView;

public:
    MotorService(MotorView *motorView);
    ~MotorService();
    void updateState(std::string strState);
};

#endif
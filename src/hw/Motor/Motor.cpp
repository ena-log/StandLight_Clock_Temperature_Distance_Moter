#include "Motor.h"

Motor::Motor(int pin)
    : pinNumber(pin), fanState(OFF)
{
    wiringPiSetup();
    softPwmCreate(pinNumber, 0, 100);
}

Motor::~Motor()
{

}

void Motor::writePin(int fanState)
{
    softPwmWrite(pinNumber, fanState);
}


void Motor::On()
{
    fanState = ON;
    writePin(fanState);
}

void Motor::Off()
{
    fanState = OFF;
    writePin(fanState);
}
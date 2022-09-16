#include "MotorView.h"

MotorView::MotorView(Motor *motor)
{
    this->motor = motor;
    motorState = MOTOR_OFF;
}

MotorView::~MotorView()
{

}

void MotorView::setState(int state)
{
    motorState = state;
}

void MotorView::motorView()
{
    switch (motorState)
    {
        case MOTOR_OFF:
            motorOff();
        break;

        case MOTOR_ON:
            motorOn();
        break;
    }
}

void MotorView::motorOff()
{
    motor->Off();
}

void MotorView::motorOn()
{
    motor->On();
}
#include "MotorService.h"

MotorService::MotorService(MotorView *motorView)
{
    this->motorView = motorView;
    motorState = MOTOR_OFF;
}

MotorService::~MotorService()
{

}

void MotorService::updateState(std::string strState)
{
    switch (motorState)
    {
        case MOTOR_OFF:
            if (strState == "motorButton") {
                motorState = MOTOR_ON;
                motorView->setState(motorState);
            }
        break;

        case MOTOR_ON:
            if (strState == "motorButton") 
            {
                motorState = MOTOR_OFF;
                motorView->setState(motorState);
            }
        break;
    }

}
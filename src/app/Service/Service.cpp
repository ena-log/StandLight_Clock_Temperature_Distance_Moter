#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
    offCount = 0;
    motorState = MOTOR_OFF;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton" || strState == "TempHighError") {
                motorState = MOTOR_ON;
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){     //거리 범위 안
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton" || strState == "TempHighError") {
                motorState = MOTOR_ON;
                lightState = LIGHT_OFF;
            }
            if(bDistanceLight){     //거리 범위 안
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton" || strState == "TempHighError") {
                lightState = LIGHT_OFF;
                motorState = MOTOR_ON;
            }
            if(bDistanceLight){     //거리 범위 안
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton" || strState == "TempHighError") {
                lightState = LIGHT_OFF;
                motorState = MOTOR_ON;
            }
            if(bDistanceLight){     //거리 범위 안
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton" || strState == "TempHighError") {
                lightState = LIGHT_OFF;
                motorState = MOTOR_ON;
            }
            if(bDistanceLight){     //거리 범위 안
                view->setState(lightState);
            }
            else{
                view->setState(LIGHT_OFF);
            }
        break;
    }
    
}

void Service::updateDistance(int distance)
{
    if(distance < 0)    //light off
    {   
        offCount ++;
        if (offCount >= 10)
        {
            bDistanceLight = false;
            view->setState(LIGHT_OFF);
        }
    }
    else                //light on
    {
        offCount = 0;
        bDistanceLight = true;
        view->setState(lightState);
    }

    // printf("distance : %d, offCount : %d\n", distance, offCount);
}
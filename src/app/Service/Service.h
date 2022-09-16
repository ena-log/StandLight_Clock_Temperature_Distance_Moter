#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "View.h"
#include "LightState.h"
#include "motorState.h"
#include "MotorView.h"

class Service
{
private:
    int lightState;
    View *view;
    bool bDistanceLight;
    int offCount;

    int motorState;
    MotorView *motorView;

public:
    Service(View *viewer, MotorView *motorView);
    ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);

};

#endif
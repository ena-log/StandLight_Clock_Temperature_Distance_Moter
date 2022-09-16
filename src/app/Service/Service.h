#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "View.h"
#include "LightState.h"
#include "motorState.h"

class Service
{
private:
    int lightState;
    View *view;
    bool bDistanceLight;
    int offCount;

    int motorState;

public:
    Service(View *viewer);
    ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);

};

#endif
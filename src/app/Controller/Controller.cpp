#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService, MotorService *motorService)
{
    service = serv;
    clockService = clockServ;
    this->tempHumidService = tempHumidService;
    this->motorService = motorService;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    
    if (strBtn == "modeButton") {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton") {
        service->updateState("powerButton");
    }

    if (strBtn == "motorButton") {
        motorService->updateState("motorButton");
    }

    if (strBtn == "clockUpdate") {
        clockService->updateEvent();
    }

    if (strBtn == "TempHighError") {
        service->updateState("TempHighError");
        motorService->updateState("TempHighError");
    }
   
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}
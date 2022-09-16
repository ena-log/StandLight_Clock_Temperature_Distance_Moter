#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#include "DHT_Data.h"
#include "TempHumidView.h"

#pragma once

class TempHumidService
{
private:
    TempHumidView *tempHumiView;
    
public:
    TempHumidService(TempHumidView *tempHumiView);
    ~TempHumidService();
    void updateEvent(DHT_Data dhtData);

};

#endif
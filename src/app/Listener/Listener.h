#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "Controller.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    Button *motorButton;
    Controller *controller;
    ClockCheck *clockcheck;
    DHT11 *dht11;
    UltraSonic *ultraSonic;

public:
    Listener(Button *modeButton, Button *powerButton, Button *motorButton, Controller *control, ClockCheck *clockcheck, DHT11 *dht11, UltraSonic *ultraSonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */

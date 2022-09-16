#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "UltraSonic.h"
#include "Motor.h"
#include "MotorService.h"
#include "MotorView.h"

// #include <time.h>


// func. main
// 1. 프로그램의 시작점을 알려줌
// 2. 초기화 및 로딩
// using namespace std;
int main()
{
    std::cout << "Hello World!" << std::endl;
    //<time test>
    // time_t timeSec;
    // struct tm *timeData;
    
    Button modeButton(27);
    Button powerButton(28);
    Button motorButton(29);  
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    UltraSonic ultraSonic(5, 4);    //trig, echo
    Motor motor(26);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    MotorView motorView(&motor);
    Service service(&view, &motorView);
    ClockService clockService(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    MotorService motorService(&motorView);
    Controller control(&service, &clockService, &tempHumidService, &motorService);
    Listener listener(&modeButton, &powerButton, &motorButton, &control, &clockCheck, &dht, &ultraSonic);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        motorView.motorView();

        // <time test>
        // timeSec = time(NULL);
        // timeData = localtime(&timeSec);

        // std::cout << "timeSec : " << timeSec << std::endl;
        // std::cout << timeData->tm_hour << ":" 
        //            << timeData->tm_min << ":"
        //            << timeData->tm_sec << std::endl;
        // delay(100);

        // <dht11 test>
        // DHT_Data dhtData;
        // dhtData = dht.readData();
        // if(dhtData.error == 0)
        // {
        //     std::cout << "humidity : " << dhtData.RH << "." << dhtData.RHDec << "% "
        //               << "Temperaure : " << dhtData.Temp << "." << dhtData.TempDec << "'C "
        //               <<std::endl;
        // }
        //delay(2000);
        
        delay(50);
    }

    return 0;
}
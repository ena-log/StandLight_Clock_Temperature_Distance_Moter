#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd)
{
    this->lcd = lcd;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumiData(float temp, float humid)
{
    char buff1[30];
    sprintf(buff1, " %.1fC", temp);
    lcd->WriteStringXY(0, 9, buff1);

    char buff2[30];
    // if(temp > 27)
    // {
    //     sprintf(buff2, "warning");
    // }
    // else
    // {
    //     sprintf(buff2, " %.1f%% ", humid);
    // }
    sprintf(buff2, " %.1f%% ", humid);
    lcd->WriteStringXY(1, 9, buff2);

    printf("%s, %s\n", buff1, buff2);
}
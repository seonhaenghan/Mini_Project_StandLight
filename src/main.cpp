#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include <time.h>
#include "LCD.h"
#include "I2C.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "ClockView.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "UltraSonic.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Button modebutton(27);
    Button powerbutton(28);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    UltraSonic ultrasonic(5,4);
    DHT11 dht11(7);
    LCD lcd(new I2C("/dev/i2c-1",0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockService(&clockView);
    TempHumidService temphumidService(&tempHumidView);
    Controller control(&service, &clockService, &temphumidService);
    Listener listener(&modebutton,&powerbutton, &control, &clockCheck, &dht11, &ultrasonic);
    DHT_Data dhtData;

    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(50);
    }

    return 0;
}
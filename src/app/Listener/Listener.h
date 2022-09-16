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
    Controller *controller;
    ClockCheck *clockcheck;
    DHT11 *dht11;
    UltraSonic *Ultrasonic;

public:
    Listener(Button *modebutton,Button *powerbutton, Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *Ultrasonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */

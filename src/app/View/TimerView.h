#ifndef TIMERVIEW_H
#define TIMERVIEW_H

#include "LCD.h"

class TimerView
{
private:
    LCD *lcd;

public:
    TimerView(LCD *lcd);
    virtual ~TimerView();
    
};

#endif
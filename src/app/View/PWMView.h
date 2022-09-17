#ifndef PWMVIEW_H
#define PWMVIEW_H
#include "PWM.h"
#include <string>
#include "LightState.h"
class PWMView
{
private:
    PWM *pwm;
    int onoffmode;
    int powermode;
    int tempsign;
public:
    PWMView(PWM *pwm);
    ~PWMView();
    void tempState(int tempOver);
    void modeState(int motor_mode);
    void powerState(int motor_power);
    
};

#endif
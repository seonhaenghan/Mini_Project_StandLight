#include "PWMView.h"

PWMView::PWMView(PWM *pwm)
{
    this->pwm = pwm;
    onoffmode = 0;
    powermode = 0;
    tempsign = 0;
}

PWMView::~PWMView()
{

}

void PWMView::tempState(int tempOver)
{
    if(tempOver)
    {
         switch (powermode)
        {
        case 0:
        pwm->startmotor(60);
            break;

        case 1:
        pwm->startmotor(70);
            break;

        case 2:
        pwm->startmotor(99);
            break;

        case 3:
        pwm->Stopmotor();
            break;
        }
    }
    else
    {
        pwm->Stopmotor();
    }
   
}

void PWMView::modeState(int motor_mode)
{
    onoffmode = motor_mode;
}

void PWMView::powerState(int motor_power)
{
    powermode = motor_power;
   
}


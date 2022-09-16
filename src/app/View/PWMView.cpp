#include "PWMView.h"

PWMView::PWMView(PWM *pwm)
{
    this->pwm = pwm;
    mode = 0;
    tempsign = 0;
}

PWMView::~PWMView()
{

}

void PWMView::tempState(int tempOver)
{
    tempsign = tempOver;
}

void PWMView::modeState(int motor_mode)
{
    mode = motor_mode;
}

void PWMView::powerState(int motor_power)
{
    if(mode)// manual mode 
    {
        switch(motor_power)
        {
            case 0 :
            pwm->Stopmotor();
            break;

            case 1 :
            pwm->startmotor(50);
            break;

            case 2 :
            pwm->startmotor(70);
            break;

            case 3 :
            pwm->startmotor(99);
            break;
        }
    }
    else    // auto mode
    {
        if(tempsign)   // 26도 이상
        {
            pwm->Stopmotor();
        }
        else{
            pwm->startmotor(80);
        }
    }
}


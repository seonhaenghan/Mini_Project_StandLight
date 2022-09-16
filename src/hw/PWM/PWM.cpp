#include "PWM.h"

PWM::PWM(int pin, int min, int max)
    : pinNumber(pin), low(min), high(max)
{
    wiringPiSetup();
    softPwmCreate(pinNumber, low, high);
}

PWM::~PWM()
{

}


void PWM::Stopmotor()
{
   softPwmStop(pinNumber);
}

void PWM::startmotor(int speed)
{
    softPwmWrite(pinNumber, speed);
}


#include "PWMService.h"

PWMService::PWMService(PWMView *pwmView)
{
    this->pwmView = pwmView;
}

PWMService::~PWMService()
{

}

void PWMService::updateEvent(std::string strState1)
{
    static int motor_mode = 0;
    // auto로 사용할지 manual로 사용할지 
    if(strState1 == "windButton")
    {
        motor_mode++;
        motor_mode %=2;
    
    }
    pwmView->modeState(motor_mode);
}

void PWMService::updateState(std::string strState2)
{
    static int motor_power = 0;
    // 바람의 세기
    if(strState2 == "windpowerButton")
    {
        motor_power++;
        motor_power %= 4;
    }
    pwmView->powerState(motor_power);
}
// temp data 전송 
void PWMService::upDatetemp(DHT_Data dhtData)
{
    float temp;
    static int tempOver = 0;
    temp = dhtData.Temp + (float)(dhtData.TempDec/10.0);
    if(temp >= 26)
    {
        tempOver++;
         tempOver %= 2;
    }
    pwmView->tempState(tempOver);
}
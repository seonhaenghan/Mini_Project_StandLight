#ifndef PWMSERVICE_H
#define PWMSERVICE_H
#include "PWMView.h"
#include <string>
#include "DHT_Data.h"
#include "LightState.h"
// 문자열 사용 시 필요 

class PWMService
{
private:
    PWMView *pwmView;

public:
    PWMService(PWMView *pwmView);
    virtual ~PWMService();
    void updateEvent(std::string strState1);
    void updateState(std::string strState2);
    void upDatetemp(DHT_Data dhtData);
};

#endif
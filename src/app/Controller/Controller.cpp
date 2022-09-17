#include "Controller.h"
#include "LightState.h"
Controller::Controller(Service *serv, ClockService *clockServ, 
    TempHumidService *temphumidService, PWMService *pwmService, TimerService *timerService)
{
    service = serv; // Service에 대한 주소를 갖는다. 
    clockService = clockServ; 
    lightState = LIGHT_OFF;
    this->temphumidService = temphumidService; 
    this->pwmService = pwmService;
    this->timerService = timerService;
    timercount = 0;
}
Controller::~Controller()
{

}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton") 
    {
        service->updateState("modeButton");
    }   

    if (strBtn == "powerButton") 
    {
        service->updateState("powerButton");
    }  

    if (strBtn == "clockUpdate") 
    {
        clockService->updateEvent();
    }  

    if (strBtn == "windButton") 
    {
        pwmService->updateEvent("windButton");
        
    }  
    
    if (strBtn == "windpowerButton") 
    {
        pwmService->updateState("windpowerButton");
       
    } 
        // 타이머에 str 전송 
    if (strBtn == "timerButton") 
    {
        timerService->updateEvent("timerButton");
       clockService->updatestate("timerButton");
    }  
}

void Controller::updateTimer(int timer)
{
    timercount = timer / 1000;

    timerService->timercounter(timercount);
}


void Controller::updateTempHumid(DHT_Data dhtData)
{
    temphumidService->upDateEvent(dhtData);
    service->upDateEvent(dhtData);
    pwmService->upDatetemp(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
    
}


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
        timerService->timercounter(0);
    }  

    if (strBtn == "clockUpdate") 
    {
        clockService->updateEvent();
        // Event만 발생 시켜준다. 
    }  

    if (strBtn == "windButton") 
    {
        pwmService->updateEvent("windButton");
        
    }  
    
    if (strBtn == "windpowerButton") 
    {
        pwmService->updateState("windpowerButton");
        // state change 
    } 
        // 타이머에 str 전송 
    if (strBtn == "timerButton") 
    {
        timerService->updateEvent("timerButton");
       
    }  
}

void Controller::updateTimer(int timer)
{
    int timercount = timer / 1000;

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


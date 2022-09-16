#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *temphumidService)
{
    service = serv; // Service에 대한 주소를 갖는다. 
    clockService = clockServ; 
    lightState = LIGHT_OFF;
    this->temphumidService = temphumidService; 
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
        // Event만 발생 시켜준다. 
    }   
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    temphumidService->upDateEvent(dhtData);
    service->upDateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}
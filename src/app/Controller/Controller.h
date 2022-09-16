#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT_Data.h"
#include "TempHumidService.h"

class Controller
{
private:
    int lightState;
    Service *service; // Service에 대한 정보를 생성자에 만들어줌 
    ClockService *clockService;
    TempHumidService *temphumidService;
    
public:
    Controller(Service *serv, ClockService *clockServ, TempHumidService *temphumidService);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);
};

#endif /* __CONTROLLER_H__ */
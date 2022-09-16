#include "TimerService.h"

TimerService::TimerService(TimerView *timerView)
{
    this->timerView = timerView;
}

TimerService::~TimerService()
{
}

void TimerService::updateEvent(std::string strbtn)
{
    if(strbtn == "timerButton")
    {
        ;
    }
}

void TimerService::timercounter(int timercount)
{
    int sec = timercount%60;
}
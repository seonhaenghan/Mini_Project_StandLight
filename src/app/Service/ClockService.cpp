#include "ClockService.h"

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view; 
}

ClockService::~ClockService()
{

}

void ClockService::updateEvent()
{
    curTime = time(NULL); 
    // time(NULL); >> return 값으로 70년 대 부터 1sec씩 Count
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}
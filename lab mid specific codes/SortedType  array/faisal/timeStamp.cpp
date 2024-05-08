#include <iostream>
#include <string>
#include "timeStamp.h"
using namespace std;

TimeStamp::TimeStamp()
{
    hour = minute = second = 0;
}

TimeStamp::TimeStamp(int s,int m,int h)
{
    hour = h;
    minute = m ;
    second = s;
}

void TimeStamp::setHour(int h)
{
    hour = h;
}

void TimeStamp::setMinute(int m)
{
    minute = m;
}

void TimeStamp::setSecond(int s)
{
    second = s;
}

int TimeStamp::getHour()
{
    return hour;
}

int TimeStamp::getMinute()
{
    return minute;
}

int TimeStamp::getSecond()
{
    return second;
}

void TimeStamp::Print()
{
    cout << hour << ":" << minute << ":" << second <<endl;
}

bool operator< (TimeStamp ts1,TimeStamp ts2)
{
    int temp1 = ts1.getHour() * 3600 + ts1.getMinute() * 60 + ts1.getSecond();
    int temp2 = ts2.getHour() * 3600 + ts2.getMinute() * 60 + ts2.getSecond();

    return (temp1 < temp2);
}


bool operator!= (TimeStamp ts1,TimeStamp ts2)
{
    int temp1 = ts1.getHour() * 3600 + ts1.getMinute() * 60 + ts1.getSecond();
    int temp2 = ts2.getHour() * 3600 + ts2.getMinute() * 60 + ts2.getSecond();

    return (temp1 != temp2);
}

//my alternate
/*
bool operator!= (TimeStamp ts1,TimeStamp ts2)
{
    int temp1 = ts1.getHour() * 3600 + ts1.getMinute() * 60 + ts1.getSecond();
    int temp2 = ts2.getHour() * 3600 + ts2.getMinute() * 60 + ts2.getSecond();

    if (temp1 != temp2)
    {
        return true;
    }
    else { return false;}
}

*/

bool operator> (TimeStamp ts1,TimeStamp ts2)
{
    int temp1 = ts1.getHour() * 3600 + ts1.getMinute() * 60 + ts1.getSecond();
    int temp2 = ts2.getHour() * 3600 + ts2.getMinute() * 60 + ts2.getSecond();

    return (temp1 > temp2);
}



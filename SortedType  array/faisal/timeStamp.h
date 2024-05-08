#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class TimeStamp
{
    private :
        int second, minute , hour;
    public:
        TimeStamp();
        TimeStamp(int,int,int);
        void setHour(int);
        void setMinute(int);
        void setSecond(int);
        int getHour();
        int getMinute();
        int getSecond();
        void Print();
        friend bool operator< (TimeStamp ,TimeStamp);
        friend bool operator!= (TimeStamp ,TimeStamp);
        friend bool operator> (TimeStamp ,TimeStamp);
};


#endif // TIMESTAMP_H_INCLUDED



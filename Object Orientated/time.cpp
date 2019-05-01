/*
 Name: Gregory Moncayo
 Course: COP 3330
 Section: 3
 Assignment: Assignment # 3
 Due Date: 02/16/2018
 About this Project: To gain experience with operator overloading.
 */

#include <iostream>
#include "time.h"

using namespace std;

// To add two objects together to tell the time.

Time operator+(const Time & t1, const Time & t2)
{
    return Time(t1.day+t2.day, t1.hour+t2.hour, t1.minute+t2.minute, t1.second+ t2.second);
}

// To subtract two time objects to get the new time.

Time operator-(const Time & t1, const Time & t2)
{
    return Time(t1.day-t2.day, t1.hour-t2.hour, t1.minute-t2.minute, t1.second-t2.second);
}

// To multiply the two objects.

Time operator*(const Time & t1, const Time & t2)
{
    return Time(t1.day*t2.day, t1.hour*t2.hour, t1.minute*t2.minute, t1.second*t2.second);
}

// To output the summary.

ostream & operator << (ostream & s, Time T)
{
    s << T.day << "~" << T.hour << ":" << T.minute << ":" << T.second;
    
    return s;
}

// To input new data for the objects.

istream & operator >> (istream & s, Time & T)
{
    char slash;
    
    s >> T.day >> slash >> T.hour >> slash >> T.minute >> slash >> T.second;
    
    return s;
}

// To compare two objects and determine which one is less than.

bool operator <(Time T1, Time T2)
{
    if (T1.day < T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour < T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute < T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second < T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// To compare two objects and determine which one is greater than.

bool operator >(Time T1, Time T2)
{
    if (T1.day > T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour > T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute > T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second > T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// To compare two objects and determine which one is greater than or equal to.

bool operator >=(Time T1, Time T2)
{
    if (T1.day >= T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour >= T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute >= T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second >= T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// To compare two objects and determine which one is less than or equal to.

bool operator <=(Time T1, Time T2)
{
    
    if (T1.day <= T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour <= T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute <= T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second <= T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
    
}

// To compare two objects and determine if they're equal to.

bool operator ==(Time T1, Time T2)
{
    if (T1.day == T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second == T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// To compare two objects and determine if they're not equal to.

bool operator !=(Time T1, Time T2)
{
    if (T1.day != T2.day)
    {
        return true;
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour != T2.hour)
        {
            return true;
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute != T2.minute)
            {
                return true;
            }
        }
    }
    
    if (T1.day == T2.day)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute == T2.minute)
            {
                if (T1.second != T2.second)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// Default constructor which defaults the private data to zero.

Time:: Time()
{
    day = 0;
    hour = 0;
    minute = 0;
    second = 0;
}

// Constructor with single parameter that represents seconds and sets second to zero if negative or greater than 59.

Time:: Time(int sec)
{
    
    if (sec < 0 || sec > 59)
    {
        second = 0;
    }
    
    minute = sec / 60;
    second = sec % 60;
    
    hour = minute / 60;
    minute = minute % 60;
    
    day = hour / 24;
    hour = hour % 24;
    
}

// Constructor with 4 parameters to determine the days, hours, minutes, and seconds.

Time:: Time(int d, int h, int m, int s)
{
    if (d < 0)
    {
        day = 0;
    }
    
    if (h < 0 || h > 23)
    {
        hour = 0;
    }
    
    if (m < 0 || m > 59)
    {
        minute = 0;
    }
    
    if (s < 0 || s > 59)
    {
        second = 0;
    }
    
    if (s > 59)
    {
        
        m += s / 60;
        s = s % 60;
    }
    
    if (m > 59)
    {
        h += m / 60;
        m = m % 60;
        
    }
    
     if (h > 23)
    {
        d += h / 24;
        h = h % 24;
        
    }
    
    day = d;
    hour = h;
    minute = m;
    second = s;
}

// Returns the day.

int Time:: GetDay()
{
    return day;
}

// Returns the hour.

int Time:: GetHour()
{
    return hour;
}

// Returns the minute.

int Time:: GetMinute()
{
    return minute;
}

// Returns the second.

int Time:: GetSecond()
{
    return second;
}

// Pre-increment.

Time & Time:: operator++()
{
    second = second + 1;
    return * this;
}

// Post-increment.

Time Time:: operator++(int)
{
    Time temp = *this;
    second = second + 1;
    return temp;
}

// Pre-decrement.

Time & Time:: operator--()
{
    second--;
    return * this;
}

// Post-decrement.

Time Time:: operator--(int)
{
    Time temp = *this;
    second = second -1;
    return temp;
}

//
//  timer.cpp
//  COP3330 timer example
//
//  Created by Gregory Moncayo on 2/12/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

//-------------- timer.cpp --------------

#include <iostream>       // for cout, cin
#include "timer.h"        // for Display and Timer declarations

using namespace std;

//-------------- Definition of member functions for class Display

Display::Display(int lim) : LIMIT(lim)
// Initialize a new Display object.
{
    value = 0;
}

void Display::increment()
// Add 1 to value.  If incrementing makes value
// equal to limit, reset value to zero.
{
    value++;
    if (value == LIMIT)
        value = 0;
}

bool Display::setValue(int val)
// Set the value on the timer to "val", as long as it's valid
// returns true for success, and false for failure.
//  On failure, current display value is unchanged
{
    if (val < 0 || val >= LIMIT)
        return false;
    
    value = val;
    return true;			// success
}

int Display::getValue() const
// Return the current value.
{
    return value;
}

int Display::getLimit() const
// Return the limit for this display
{
    return LIMIT;
}

void Display::show() const
// Show the value of a Display.
{
    if (value < 10)          // Pad with a leading zero, if needed,
        cout << '0';
    
    cout << value;           // and in any case, display the value.
}

//-------------- Definition of member functions for class Timer

Timer::Timer() : hours(24), minutes(60)
// Initialize a new Timer object,
// setting hours limit to 24 and minutes limit to 60.
{
    // All the work is done by the two constructor calls in the header.
}

Timer::Timer(int h, int m) : hours(24), minutes(60)
// initializes Timer value to h hours and m minutes, if h,m valid.
// if invalid data, defaults to 00:00
{
    if (set(h,m) == false)
        set(0,0);
}

void Timer::increment()
// Add 1 minute to timer.
{
    minutes.increment();
    
    if (minutes.getValue() == 0) // We've turned the minute counter over,
        hours.increment();        // so we have to increment the hours counter.
}

bool Timer::set(int h, int m)
// Set hours to h and minutes to m, if they are valid.
// If h and m represent an invalid timer setting, no change
// returns true for success, false for failure
{
    if (h < 0 || h >= hours.getLimit())
        return false;
    if (m < 0 || m >= minutes.getLimit())
        return false;
    
    hours.setValue(h);
    minutes.setValue(m);
    return true;
}

void Timer::show() const
// Show the current timer's settings.
{
    hours.show();
    cout << ':';
    minutes.show();
}

Timer Timer::add(const Timer& t) const
{
    int h = hours.getValue() + t.hours.getValue();	// add hours
    int m = minutes.getValue() + t.minutes.getValue();	// add minutes
    
    if (m >= minutes.getLimit())		// check to see if minutes
    {					//  is past the limit
        m = m - minutes.getLimit();
        h = h + 1;
    }
    
    if (h >= hours.getLimit())		// adjust h if past the hours limit
        h = h - hours.getLimit();
    
    return Timer(h,m);		// build and return result object
    
    
}


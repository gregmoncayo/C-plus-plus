//
//  timer.h
//  COP3330 timer example
//
//  Created by Gregory Moncayo on 2/12/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

//-------------- timer.h --------------

// Declarations of classes Display and Timer

class Display
// A Display object stores and displays a single integer.
// That integer is always in the range 0 .. limit-1, where limit
// is also stored in the class.
{
public:
    Display(int lim);		// Initialize a new Display object.
    
    void increment();		// Add 1 to value.
    bool setValue(int val);	// Set the value.
    
    int getValue() const;	// Return the current value.
    int getLimit() const;	// Return the limit
    
    void show() const;		// Show the current value.
    
private:
    const int LIMIT;		// largest possible value
    int value;			// current value (0 .. limit - 1)
};

class Timer
// A Timer object consists of two Displays,one for hours and one for minutes.
// When the timer is incremented and minutes becomes 60, minutes is reset
// to 0
//and hours is incremented.
{
public:
    Timer();			// Initialize a new Timer object 00:00
    Timer(int h, int m);		// Initialize a new Timer object
				//   to h hours and m minutes
    void increment();		// Add 1 minute to timer.
    bool set(int h, int m);	// Set Timer to h hours and m minutes
    
    void show() const;		// Show hours and minutes.
    
    Timer add(const Timer& t) const;  // add two Timer objects together
    
private:
    Display hours,		// two displays, one for hours,
    minutes;		// and one for minutes
};

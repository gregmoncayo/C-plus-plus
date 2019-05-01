/*
 Name: Gregory Moncayo
 Course: COP 3330
 Section: 3
 Assignment: Assignment # 3
 Due Date: 02/16/2018
 About this Project: To gain experience with operator overloading.
 */

#include <iostream>
using namespace std;

class Time
{
    friend Time operator+(const Time &, const Time &);          // Additon function to add two objects together.
    friend Time operator-(const Time &, const Time &);         // Subtraaction function to subtract two objects together.
    friend Time operator*(const Time &, const Time &);        // Multiplication function to multiply two objects together.
    
    friend ostream & operator << (ostream & s, Time T);      // Insertation operator to output Time objects.
    friend istream & operator >> (istream & s, Time & T);   // Extraction operator to read Time objects.
    
    friend bool operator <(Time T1, Time T2);              // Less than operator to compare two objects.
    friend bool operator >(Time T1, Time T2);             // Greater than operator to compare two objects.
    friend bool operator >=(Time T1, Time T2);
    friend bool operator <=(Time T1, Time T2);           // Less than or equal to operator to compare two objects.
    friend bool operator ==(Time T1, Time T2);          // Equal to operator to compare two objects.
    friend bool operator !=(Time T1, Time T2);         // Not equal to operator to compare two objects.
    
    public:
        Time();                                     // Default Constructor
        Time(int sec);                         // Constructor with single parameter
        Time(int d, int h, int m, int s); // Constructor with 4 parameters to represent day,hour, min, sec.
    
    // Accessors
    int GetDay();
    int GetHour();
    int GetMinute();
    int GetSecond();
    
    // Increments and Decrements
    
    Time & operator++(); // Pre increment
    Time operator++(int); // Post increment
    Time & operator--(); // Pre decrement
    Time operator--(int); // Post decrement
    
    private:
        int day;                            // Variable to store the day.
        int hour;                          // Variable to store the hour.
        int minute;                       // Variable to store the minute.
        int second;                      // Variable to store the second.
};

/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: 2
 Section: 3
 Due Date: 02/5/2018
 About this Project: To help us gain a better understanding on objects and implementing classes.
 */

#include "temperature.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

// Constructor with parameters to help us gain the temperature and temeperature letter.

Temperature:: Temperature(double temp, char letter)
{
    degrees = temp;
    Scale = letter;
    format = 'L';
    
    // To determine f the scale is fahrenheit, Celsius, or Kelvin.
    
    if (Scale == 'F' || Scale == 'f')
    {
        if (degrees < -459.67)
        {
            degrees = 0;
            Scale = 'C';
        }
    }
    
    else if (Scale == 'C'|| Scale == 'c')
    {
        if (degrees < -273.15)
        {
            degrees = 0;
            Scale = 'C';
        }
    }
    
    else if (Scale == 'K' || Scale == 'k')
    {
        if (degrees < 0)
        {
            degrees = 0;
            Scale = 'C';
        }
    }
    
    else
    {
        degrees = 0;
        Scale = 'C';
    }
}

// For user input and information.

void Temperature:: Input()
{
    cout << " Please enter a temperature";
    
    do
    {
        cin >> degrees >> Scale;
        
        if (Scale == 'F' || Scale == 'f')
        {
            // If temperature is over the limit, it will ask the user to try again.
            
            if (degrees < -459.67)
            {
                cout << " Invalid temperature. Try again ";
            }
            
            else
                break;
        }
        
        
        if (Scale == 'C' || Scale == 'c')
        {
            // If temperature is over the limit, it will ask the user to try again.
            
            if (degrees < -273.15)
            {
                cout << " Invalid temperature. Try again ";
            }
            
            else
                break;
        }
        
        if (Scale == 'K' || Scale == 'k')
        {
            // If temperature is under the limit, it will ask the user to try again.
            
            if (degrees < 0)
            {
                cout << " Invalid temperature. Try again ";
            }
            
            else
                break;
        }
        
    }
    while (true);
    
}

// Displays summary in different format.

const void Temperature:: Show()
{
    
    // Displays in default format.
    
    if (format == 'D' || format == 'd')
    {
        cout << degrees << " " << Scale << endl;
    }
    
    // Displays in long format.
    
    else if (format == 'L' || format == 'l')
    {
        if (Scale == 'F' || Scale == 'f')
        {
            cout << degrees << " Fahrenheit " << endl;
        }
        
        if (Scale == 'C' || Scale == 'c')
        {
            cout << degrees << " Celsius " << endl;
        }
        
        if (Scale == 'K' || Scale == 'k')
        {
            cout << degrees << " Kelvin " << endl;
        }

    }
    
    // Displays in Precise-1 format
    
    else if (format == 'P' || format == 'p')
    {
        cout << fixed;
        cout << showpoint;
        cout << setprecision(1) << degrees << Scale << endl;
    }
    
    
}

// Sets the temperature and scale

bool Temperature:: set(double deg, char s)
{
    degrees = deg;
    Scale = s;
    
    if (s == 'C' || s == 'c')
    {
        // Sets limit for how the temperature can be.
        // It is physically impossible for it to be -273.15 degrees in Celsius.
        
        if (deg < -273.15)
        {
            return true;
        }
    }
    
    if (s == 'K' || s == 'k')
    {
        // Sets limit for how the temperature can be.
        // It is physically impossible for it to be 0 degrees in Kelvin.
        
        if (deg > 0)
        {
            return true;
        }
    }
    
    // Sets limit for how the temperature can be.
    // It is physically impossible for it to be -459.67 degrees in fahrenheit.
    
    if (s == 'F' || s == 'f')
    {
        if (deg < -459.67)
        {
            return true;
        }
    }
    
    // If temperature is set out of bounds, returns false.
    
    return false;
}

// Returns the degrees to the program since it is private data.

double Temperature:: GetDegrees()
{
    return degrees;
}

// Returns the scale to the program since it is private data.

char Temperature:: GetScale()
{
    return Scale;
}

// Sets the format for the temperature.

bool Temperature:: SetFormat(char f)
{
    format = f;
    
    // Default format
    
    if (f == 'D' || f == 'd')
    {
        return true;
    }
    
    // Precise-1 format
    
    if (f == 'P' || f == 'p')
    {
        return true;
    }
    
    // Long format
    
    if (f == 'L' || f == 'l')
    {
        return true;
    }
    
    // Returns false if any other letter is not entered.
    
    return false;
}

// Converts the temperature to the degrees dependent on the scale.

bool Temperature:: convert(char sc)
{
    // Converts from Celsius to Kelvin or fahrenheit
    
    if (Scale == 'C' || Scale == 'c')
    {
        if (sc == 'F' || sc == 'f')
        {
            degrees = (degrees * 1.8) + 32;
            Scale = sc;
            return true;
        }
        
        if (sc == 'C' || sc == 'c')
        {
            Scale = sc;
            return true;
        }
        
        if (sc == 'K' || sc == 'k')
        {
            degrees = degrees + 273.15;
            Scale = sc;
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    // Converts from fahrenheit to Kelvin or Celsius
    
    if (Scale == 'F' || Scale == 'f')
    {
        if (sc == 'F' || sc == 'f')
        {
            Scale = sc;
            return true;
        }
        
        if (sc == 'C' || sc == 'c')
        {
            degrees = (degrees-32) * (5.0/9.0);
            Scale = sc;
             return true;
        }
        
        if (sc == 'K' || sc == 'k')
        {
            degrees = (degrees + 459.67) * (5.0/9.0);
            Scale = sc;
             return true;
        }
        
        else
        {
            return false;
        }
    }
    
    // Converts from Kelvin to fahrenheit or celsius
    
    if (Scale == 'K' || Scale == 'k')
    {
        if (sc == 'F' || sc == 'f')
        {
            degrees = degrees * 1.8 - 459.67;
            Scale = sc;
             return true;
        }
        
        if (sc == 'C' || sc == 'c')
        {
            degrees = degrees - 273.15;
            Scale = sc;
             return true;
        }
        
        if (sc == 'K' || sc == 'k')
        {
            Scale = sc;
             return true;
        }
        
        else
        {
            return false;
        }
    }
    
    return false;
}

// Compares the temperatures of other objects.

int Temperature:: compare(const Temperature & d)
{
    // If the calling object is less than the private object, returns 1
    
    if (d.degrees < degrees)
    {
        return 1;
    }
    
    // If the calling object is equal to the private object, returns 0
    
    if (d.degrees == degrees)
    {
        return 0;
    }
    
    return -1;
}

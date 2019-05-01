/* Name: Gregory Moncayo
 Date: 10/2/17
 Section: 0009
 Assignment: Assignment #2
 Due Date: 10/4/17
 About this project: This assignment will provide further practice with implementing classes.
 Assumptions: To assume that the user will enter integers and will not enter characters beside /
 
 All work below was performed by Gregory Moncayo */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "date.h"

using namespace std;

// Object that defaults the date to January 1, 2000 if the user prompts an illegal month, day, or year.

Date:: Date()
{
    // Error checking if year is negative.
    
    if (year < 0)
    {
        month = 1;
        day = 1;
        year = 2000;
    }
    
    // The number of days within January, March, May, July, August, October, December.
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
        {
            month = 1;
            day = 1;
            year = 2000;
        }
    }
    
    // The number of days within April, June, September, & November.
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            month = 1;
            day = 1;
            year = 2000;
        }
    }
    
    // Number of days within February.
    
    if (month == 2)
    {
        if (day < 1 || day > 28)
        {
            month = 1;
            day = 1;
            year = 2000;
        }
    }
    
    // Ranges between the months within the year.
    
    if (month < 1 || month > 12)
    {
        month = 1;
        day = 1;
        year = 2000;
    }
    
    
}

// Object that illustrates the month, day, and year to what is passed in through the parameters.

Date:: Date(int mth, int dy, int yr)
{
    Date();
    
    month = mth;
    day = dy;
    year = yr;
}

// Function that defines the month, day, and year & defines whether it is a valid day, month, or year.

bool Date:: Set(int m, int d, int y)
{
    m = month;
    d = day;
    y = year;
    
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d  > 0 || d < 31)
        {
            if (y >= 0)
            {
                return true;
            }
        }
    }
    
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d  > 0 || d < 30)
        {
            if (y >= 0)
            {
                return true;
            }
        }
    }
    
    if (m == 2)
    {
        if (d > 0 || d < 28)
        {
            if (y >= 0)
            {
                return true;
            }
        }
    }
        return false;
}

// Adjusts the different types of format and returns false if user tries to input the wrong format.

bool Date:: SetFormat(char f)
{
    format = f;
    
    if (f == 'D' || f == 'd')
    {
        return true;
    }
    
    if (f == 'T' || f == 't')
    {
        return true;
    }
    
    if (f == 'L' || f == 'l')
    {
        return true;
    }
    
    else
        return false;
}

// Returns the day to the user.

int Date:: GetDay()
{
    return day;
}

// Returns the month to the user.

int Date:: GetMonth()
{
    return month;
}

// Returns the year to the user.

int Date:: GetYear()
{
    return year;
}

// Compares two dates and defines whether one comes first before the other or are the same exact date.

int Date:: compare(const Date & d)
{
    if (year < d.year)
    {
        return -1;
    }
    
    if (month == d.month)
    {
        if (day == d.day)
        {
            if (year == d.year)
            {
                return 0;
            }
        }
    }
    
    if (month == d.month)
    {
        if (year < d.year)
        {
            return -1;
        }
    }
    
        return 1;
}

// Adds one day to the original date.

void Date:: Increment(int numDays)
{
    for (int i = 0; i < numDays; i++)
    {
            day++;
        
        if (day > 31)
        {
            day = 1;
            month++;
        }
    }
    
}

// Asks for the user input and tells them to enter a date MM/DD/YY format.

void Date:: Input()
{
    char temp;
    
    cout << '\n';
    cout << " Enter a date: ";
    cin >> month >> temp >> day >> temp >> year;
    
    // Error message if the user enters an invalid date.
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
        {
            cout << " Invalid date. Please try again. " << endl;
            cout << " Enter a date: ";
            cin >> month >> temp >> day >> temp >> year;
        }
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            cout << " Invalid date. Please try again. " << endl;
            cout << " Enter a date: ";
            cin >> month >> temp >> day >> temp >> year;
        }
    }
    
    if (month == 2)
    {
        if (day < 1 || day > 28)
        {
            cout << " Invalid date. Please try again. " << endl;
            cout << " Enter a date: ";
            cin >> month >> temp >> day >> temp >> year;
        }
    }
    
    if (month < 1 || month > 12)
    {
        cout << " Invalid date. Please try again. " << endl;
        cout << " Enter a date: ";
        cin >> month >> temp >> day >> temp >> year;

    }
    
    if (year < 0)
    {
        cout << " Invalid date. Please try again. " << endl;
        cout << " Enter a date: ";
        cin >> month >> temp >> day >> temp >> year;
    }
}

// Displays the date in several formats.

void Date:: Show()
{
    
    // Displays the date in long format. Ex: Jan 1, 2017.
    
    if (format == 'l' || format == 'L')
    {
        
        switch (month)
        {
            case 1:
                cout << "Jan " << day << ", " << year << endl;
                break;
            case 2:
                cout << "Feb " << day << ", " << year << endl;
                break;
            case 3:
                cout << "Mar " << day << ", " << year << endl;
                break;
            case 4:
                cout << "Apr " << day << ", " << year << endl;
                break;
            case 5:
                cout << "May " << day << ", " << year << endl;
                break;
            case 6:
                cout << "June " << day << ", " << year << endl;
                break;
            case 7:
                cout << "July " << day << ", " << year << endl;
                break;
            case 8:
                cout << "Aug " << day << ", " << year << endl;
                break;
            case 9:
                cout << "Sept " << day << ", " << year << endl;
                break;
            case 10:
                cout << "Oct " << day << ", " << year << endl;
                break;
            case 11:
                cout << "Nov " << day << ", " << year << endl;
                break;
            case 12:
                cout << "Dec " << day << ", " << year << endl;
                break;
            
            default:
                break;
        }
    }
    
    // Displays the date in two digit format. Ex: Feb 14, 00.
    
    if (format == 't' ||format == 'T')
    {
        switch (month)
        {
            case 1:
                cout << "01/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 2:
                cout << "02/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 3:
                cout << "03/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 4:
                cout << "04/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 5:
                cout << "05/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 6:
                cout << "06/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 7:
                cout << "07/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 8:
                cout << "08/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 9:
                cout << "09/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 10:
                cout << "10/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 11:
                cout << "11/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                break;
            case 12:
                cout << "12/" << day << "/" << year % 100;
                if (year % 100 < 10)
                {
                    cout << 0;
                }
                cout << '\n';
                
            default:
                break;
        }
        
        if (year < 10)
            cout << 0;
    }
    
    // Displays the date in default format. Ex: 10/15/1999.
    
    if (format == 'd' || format == 'D')
    {
        switch (month)
        {
            case 1:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 2:
                cout << month << "/" <<  day << "/" << year << endl;
                break;
            case 3:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 4:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 5:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 6:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 7:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 8:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 9:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 10:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 11:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 12:
                cout << month << "/" << day << "/" << year << endl;
                break;
                
            default:
                break;
        }
    }
    
    // Displays the default format if the user does not enter a parameter within the function.
    
    else if (format != 'D' && format != 'd' && format != 'T' && format != 't' && format != 'L' && format != 'l')
    {
        switch (month)
        {
            case 1:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 2:
                cout << month << "/" <<  day << "/" << year << endl;
                break;
            case 3:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 4:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 5:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 6:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 7:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 8:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 9:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 10:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 11:
                cout << month << "/" << day << "/" << year << endl;
                break;
            case 12:
                cout << month << "/" << day << "/" << year << endl;
                break;
                
            default:
                break;
        }
    }
}

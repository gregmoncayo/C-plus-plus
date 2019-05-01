/*
 Name: Gregory Moncayo
 Course: CGS 3406
 Assignment: Assignment # 7
 Due Date: 4/26/2018
 About this Project: To help us gain a better understanding on building classes.
 */

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

// Employee class with four parameters

Employee:: Employee(string FirstName, string Lastname, double money, double work)
{
    first = FirstName;
    last = Lastname;
    
    if (money < 0 || work < 0)
    {
        pay = 25.00;
        hours = 40.0;
    }
    
    else
    {
        pay = money;
        hours = work;
    }
}

// Employee class with three parameters

Employee:: Employee(string FirstName, string Lastname, double yearly)
{
    first = FirstName;
    last = Lastname;
    hours = 40.0;
    pay = (yearly/52)/hours;
}

// Set function that changes the firstname, lastname, hourly pay, and hours of work.

bool Employee:: Set(string FirstName, string Lastname, double money, double work)
{
    if (money > 0.00)
    {
        if (work > 0.0 && work <= 80.0)
        {
            first = FirstName;
            last = Lastname;
            pay = money;
            hours = work;
            return true;
        }
    }
    
    return false;
}

// Changes the pay rate by the percentage.

bool Employee:: ChangePay(double P)
{
    if (P > 0.00)
    {
        pay = (pay * P) + pay;
        return true;
    }
    
    return false;
}

// sets the hour

bool Employee:: SetHours(double H)
{
    if (H > 0.0 && H <= 80.0)
    {
        hours = H;
        return true;
    }
    
    return false;
}

// sets the time

bool Employee:: SetTime(char T)
{
    switch (T)
    {
        case 'F':
        case 'f':
            hours = 40;
            break;
        case 'P':
        case 'p':
            hours = 20;
            break;
        case 'T':
        case 't':
            hours = 30;
            break;
            
        default:
            break;
    }
    
    return false;
}

// Display the results

void Employee:: Show()
{
    cout << first << ' ' << last << endl;
    cout << "Makes $" << pay << "/hour and works " << hours << " hours each week" << endl;
    cout << "This makes $" << GetYearlyPay() << " per year." << endl;
}

// accessors

// returns the hourly rate
double Employee:: GetHourlyPay()
{
    return pay;
}

// returns the weekly pay

double Employee:: GetWeeklyPay()
{
    return pay*hours*7;
}

// returns the yearly pay

double Employee:: GetYearlyPay()
{
    return pay*hours*52;
}

// returns the first & last name

string Employee:: GetName()
{
    return first+ ' '+last;
}

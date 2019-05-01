/*
 Name: Gregory Moncayo
 Course: CGS 3406
 Assignment: Assignment # 7
 Due Date: 4/26/2018
 About this Project: To help us gain a better understanding on building classes.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

class Employee
{
    public:
    Employee(string FirstName, string Lastname, double money, double work); // Constructor with 4 parameters.
    Employee(string FirstName, string Lastname, double yearly = 50000);     // Constructor with 3 parameters.
    bool Set(string FirstName, string Lastname, double money, double work); // Returns true if hours/work is valid.
    bool ChangePay(double P);       // Returns true if parameter is greater than 0.
    bool SetHours(double H);        // Returns true if parameter is greater than 0.
    bool SetTime(char T);           // Returns true if T is valid.
    void Show();                    // Displays results.
    
    // accessors
    double GetHourlyPay();          // Returns hourly pay.
    double GetWeeklyPay();          // Returns weekly pay.
    double GetYearlyPay();          // Returns yearly pay.
    string GetName();               // Returns First & Last name.
    
    private:
    string first;                   // Stores firstname.
    string last;                    // Stores lastname.
    double pay;                     // Stores hourly pay.
    double hours;                   // Stores # of hours worker has worked.
};

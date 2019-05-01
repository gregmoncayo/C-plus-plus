#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

int main()
{
    Employee e1("Bill", "Johnson");
    Employee e2("John", "Smith", 62400);
    Employee e3("Jane", "Doe", 30.51, 60);
    Employee e4("Susan", "Jones", 25.25, -10);
    
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    
    cout << "\n*** Displaying each employee\n";
    cout << "Employee 1:\n";
    e1.Show();
    cout << "Employee 2:\n";
    e2.Show();
    cout << "Employee 3:\n";
    e3.Show();
    cout << "Employee 4:\n";
    e4.Show();
    
    cout << endl << endl;
    
    cout << "***Making changes\n";
    cout << "Setting and Printing Employee 1:\n";
    e1.Set("Bob", "Johnson", 12.5, 32.5);
    e1.Show();
    
    cout << "Setting and Printing Employee 2:\n";
    e2.Set("John", "Smith", -5.0, 40.0);
    e2.Show();
    
    cout << "Setting and Printing Employee 3:\n";
    e3.Set("Jane", "Johnson", 50.18, 100.5);
    e3.Show();
    
    cout << "Setting and Printing Employee 4:\n";
    e4.Set("Different", "Name", 22.21, -10.1);
    e4.Show();
    
    
    cout << endl << endl;
    
    cout << "***Setting hours and printing:\n";
    cout << "Employee 2:\n";
    e2.SetHours(60);
    e2.Show();
    cout << "Employee 3:\n";
    e3.SetHours(20);
    e3.Show();
    cout << "Employee 4:\n";
    e4.SetHours(85);
    e4.Show();
    
    cout << endl << endl;
    
    cout << "***Changing Employee 1's time several times:\n";
    
    e1.SetTime('f');
    e1.Show();
    e1.SetTime('P');
    e1.Show();
    e1.SetTime('K');
    e1.Show();
    
    cout << endl << endl;
    
    cout << "***Changing Employees' pay by percentages\n";
    cout << "Changing Employee 1's pay:\n";
    if (e1.ChangePay(0.25))
        e1.Show();
    else
        cout << "Unsuccessful change.\n";
    cout << "Changing Employee 2's pay:\n";
    if (e2.ChangePay(-0.05))
        e2.Show();
    else
        cout << "Unsuccessful change.\n";
    cout << "Changing Employee 3's pay:\n";
    if (e3.ChangePay(-1.20))
        e3.Show();
    else
        cout << "Unsuccessful\n";
    cout << "Changing Employee 4's pay:\n";
    if (e2.ChangePay(1.0))
        e4.Show();
    else
        cout << "Unsuccessful\n";
    
    cout << endl << endl;
    
    cout << "***Testing accessors\n";
    cout << "Employee 2 Name: " << e2.GetName() << endl;
    cout << "Employee 2 Hourly Pay: $" << e2.GetHourlyPay() << endl;
    cout << "Employee 2 Weekly Pay: $" << e2.GetWeeklyPay() << endl;
    cout << "Employee 2 Yearly Pay: $" << e2.GetYearlyPay() << endl << endl;
    
    cout << "Employee 1 Name: " << e1.GetName() << endl;
    cout << "Employee 1 Hourly Pay: $" << e1.GetHourlyPay() << endl;
    cout << "Employee 1 Weekly Pay: $" << e1.GetWeeklyPay() << endl;
    cout << "Employee 1 Yearly Pay: $" << e1.GetYearlyPay() << endl << endl;
    
    return 0;
}

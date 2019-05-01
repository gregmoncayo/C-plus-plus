//
//  gas.cpp
//  GasPump
//
//  Created by Gregory Moncayo on 2/12/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include "gas.h"
using namespace std;

Gas :: Gas()
{
    standard = 2.85;
    diseal = 3.00;
    preminum = 3.85;
}

const void Gas:: Summary()
{
    switch (choice)
    {
        case 'S':
        case 's':
        cout << "For " << gallons << " gallons of standard gasoline, it will cost you " << gallons * standard << endl;
            break;
        case 'D':
        case 'd':
        cout << "For " << gallons << " gallons of diseal gasoline, it will cost you " << gallons * diseal << endl;
            break;
        case 'P':
        case 'p':
        cout << "For " << gallons << " gallons of preminum gasoline, it will cost you " << gallons * preminum << endl;
            break;
        default:
            break;
    }
}

void Gas:: Input()
{
    cout << "Welcome to Gas calculator. " << endl;
    cout << "Please enter your choice: " << endl;
    cout << "Standard - S " << endl;
    cout << "Diseal - D " << endl;
    cout << "Preminum - P " << endl;
    cout << ">";
    
    do
    {
         cin >> choice;
        
        if (choice != 'p' && choice != 'd' && choice != 's' && choice != 'P' && choice != 'D' && choice != 'S')
        {
            cout << "Wrong choice. Please try again. " << endl;
            cout << ">";
        }
        
    } while (choice != 'p' && choice != 'd' && choice != 's' && choice != 'P' && choice != 'D' && choice != 'S');
    
    cout << "How many gallons? ";
    cout << ">";
    
    do {
        cin >> gallons;
        
        if (gallons < 0)
        {
            cout << "Invalid number. Please try again. " << endl;
            cout << ">";
        }
    } while (gallons < 0);
    
}

int Gas:: GetGallons()
{
    return gallons;
}

int Gas:: GetChoice()
{
    return choice;
}

double Gas:: ReturnStandard()
{
    return standard;
}
double Gas:: ReturnPrem()
{
    return preminum;
}

double Gas:: ReturnDiseal()
{
    return diseal;
}

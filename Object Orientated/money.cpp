#include "money.h"
#include <iostream>

using namespace std;
Money:: Money()
{
    dollars = 0;
    cents = 0;
}
void Money:: Input()
{
    cout << " Please input the amount for dollars: ";
    cin >> dollars;
    
    cout << "Please input the amount for cents: ";
    cin >> cents;
}

void Money:: Summary() const
{
    cout << "You have a total of " << dollars << "." << cents << endl;
    cout <<"\n";
}

int Money:: ReturnDollar() const
{
    return dollars;
}

int Money:: ReturnCents() const
{
    return cents;
}

// main.cpp -- Bob Myers
//
// Driver program to demonstrate the behavior of the MyInt class
//
// You can add more tests of your own, or write other drivers to test your
// class

#include <iostream>
#include "myint.h"

using namespace std;

MyInt Fibonnaci(MyInt num);

int main()
{
    
    // demonstrate behavior of the two constructors and the << overload
    
    MyInt x(12345), y("9876543210123456789"), r1(-1000), r2 = "14H67", r3;
    char answer;
    cout << "Initial values: \nx = " << x << "\ny = " << y
    << "\nr1 = " << r1 << "\nr2 = " << r2 << "\nr3 = " << r3 << "\n\n";
    
    cout << "Enter a new value: ";
    cin >> r3;
    
    cout << "r3 is now: " << r3 << endl;

}

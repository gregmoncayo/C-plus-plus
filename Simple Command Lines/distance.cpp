/*
 Name: Gregory Moncayo
 Course: CGS 3406
 Assignment: Assignment # 4
 Due Date: 02/27/2018
 About this Project: To help us gain a better understanding of functions
 */


#include <iostream>

using namespace std;

int inches(int miles, int feet, int inches);    // Function to convert miles & feet to inches.

int main()
{
    int m, f, i, mi, foot, inch;        // variables to store miles, feet, and inches from user input.
    
    // Display menu for user input.
    
    cout << "Input first point distance from the origin... " << endl;
    cout << "Miles: ";
    cin >> m;
    cout << "Feet: ";
    cin >> f;
    cout << "Inches: ";
    cin >> i;
    
    // Second display menu for user input.
    
    cout << "\n";
    cout << "Input second point distance from the origin... " << endl;
    cout << "Miles: ";
    cin >> mi;
    cout << "Feet: ";
    cin >> foot;
    cout << "Inches: ";
    cin >> inch;
    
    // Calculates the conversion from miles & feet to inches and adds them together.
    
    int sum = inches(m, f, i);
    int total = inches(mi, foot, inch);
    
    // Displays the summary.
    
    cout << "The first point is " << sum << " inches from the origin." << endl;
    cout << "The second point is " << total << " inches from the origin. " << endl;
    
    // Displays the difference between two points.
    
    if (sum > total)
    {
        cout << "\n";
        cout << "The two are " << sum - total << " inches apart." << endl;
    }
    
    else
    {
        cout << "\n";
        cout << "The two are " << total - sum << " inches apart." << endl;
    }
    
    return 0;
}

// Helps calucate the conversion of miles & feet to inches and adds them together.

int inches(int miles, int feet, int inches)
{
    miles = miles * 63360;
    
    feet = feet * 12;
    
    int sum = miles + feet + inches;
    
    return sum;
}

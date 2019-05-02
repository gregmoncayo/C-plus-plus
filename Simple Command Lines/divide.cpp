/* Name: Gregory Moncayo
 Date: 02/2/17
 Section: 17
 Assignment: Assignment #2
 Due Date: 02/3/17
 About this project: To help do simple math with fractions & to help us learn about if/else statements.
 Assumptions: Assuming that the user will enter a valid integer.
 
 All work below was performed by Gregory Moncayo */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    double num, den, numerator, denominator; // Variables used to ask the user for the numerator & denominator.
    
    // Display menu for user interface.
    
    cout << " Enter the numerator of the first fraction: ";
    cin >> num;
    
    cout << " Enter the denominator of the first fraction: ";
    cin >> den;
    
    // Warning statement used if the User types in a zero as a denominator.
    
    if (den == 0)
    {
        cout << " You can not divide by 0! Aborting program ";
    }
    
    // Display menu for user interface.
    
    else
    
    cout << " Enter the numerator of the second fraction: ";
    cin >> numerator;
    
    cout << " Enter the denominator of the second fraction: ";
    cin >> denominator;
    
    // Warning statement used if the User types in a zero as a denominator.
    
    if (denominator == 0)
    {
        cout << " You can not divide by 0! Aborting program ";
    }
    
    // Displays the result for the user.
    
    else

        cout << num << "/" << den << " divided by " << numerator << "/" << denominator << " = " << num * denominator << "/" << numerator * den;
        
    return 0;
    
}

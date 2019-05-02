/* Name: Gregory Moncayo
 Date: 9/25/16
 Section: Section 2
 Assignment: Assignment 2
 Due Date: 9/28/16
 About this project: Calculates how much a person would earn over a period of time if his/her salary is just one penny
 and doubles each day.
 Assumptions: (Assums that the user will enter a positive number of days starting from 1 and up.
 
 All work below was performed by Gregory Moncayo */


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int counter = 1;                            // counts the number of days
    int days;                                   // For user entry when asked how many days have they worked.
   
    double pennies = 0.01;                      // The value of the penny that is being doubled everyday.
    
    double total = 0.0;                         // To calculate the total earnings at the end.
    
    
    // User display
    
    cout << "Please enter the amount of days worked: ";
    cin >> days;
    
    // When the user enters an invalid answer, ask the user repetively to try again and to enter a valid answer.
    
    while (days < 1)
    {
       
    
        if (days < 1)
            {
                cout << "Invalid number of days. Please try again. " << endl;
                cout << "Please enter the amount of days worked: ";
                cin >> days;
            }
        
    }
    
    cout << "\n\n";
    
    cout << "Day\t\t\t\t\t\t Amount earned" << endl;
    
    // Displays the amount of pennies that's doubled within each day of working.
    
    for (int x = 1; x <= days; x++)
    {
        cout << "---------------------------------------" << endl;
        cout << counter++ << "\t\t\t\t\t\t\t\t" << "$" << pennies << endl;
        pennies = pennies * 2;
        total = pennies;
    }
    
    // Displays the total earnings within the amount time period one worked.
    
    cout << "\n";
    cout << "Total earnings: " << " $ " << total -0.01;
    
    return 0;
}

/* Name: Gregory Moncayo
 Date: 02/2/17
 Section: 17
 Assignment: Assignment #2
 Due Date: 02/3/17
 About this project: To help calculate one's grade & to help us learn about switch statements, if/else statements, & repetitions.
 Assumptions: Assuming that the user will enter valid homework & test scores.
 
 All work below was performed by Gregory Moncayo */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int hw1, hw2, hw3, hw4, test1, test2, Final, ExtraCredit; // Variables to input student's grade for their assignments.
    char choice;                                           // Variable used to ask the user whether they received EC or not.
    
    // Display menu for User interface.
    
    cout << "**************************" << endl;
    cout << "Welcome to the COP3014" << endl;
    cout << "Grade Calculation System" << endl;
    cout << "**************************" << endl;
    cout << "\n";
    
    cout << "Please enter the following data: " << endl;
    cout << "Homework 1 grade --> ";
    cin >> hw1;
    cout << "Homework 2 grade --> ";
    cin >> hw2;
    cout << "Homework 3 grade --> ";
    cin >> hw3;
    cout << "Homework 4 grade --> ";
    cin >> hw4;
    
    cout << "\n";
    
    cout << "Test 1 grade --> ";
    cin >> test1;
    cout << "Test 2 grade --> ";
    cin >> test2;
    cout << "Final exam grade --> ";
    cin >> Final;
    
    cout << "Did you receive any extra credit on homework? (y or n) --> ";
    cin >> choice;
    
    // Aborts program if user does not enter Yes or No.
    
    if (choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y')
    {
        cout << " Invalid entry, aborting program... ";
    }
    
    // Ask the user whether they received Extra Credit or not if the user pressed Yes.
    
    if (choice == 'Y' || choice == 'y')
    {
        cout << "How many points should be added to homework total? -->";
        cin >> ExtraCredit;
    }
    
    // Variable used to calculate the Homework average.
    
    double HwAverage = ((hw1 + hw2 + hw3 + hw4 + ExtraCredit) / 400.0) * 100;
    
    // Variable used to calculate the test average and the final grade for the student.
    
    double Total = ((test1 * 17.5) + (test2 * 17.5) + (Final * 25) + (HwAverage * 40)) / 100.0;
    
    // Display Final Score after user enters the amount of Extra Credit they received.
    
    if (choice == 'Y' || choice == 'y')
    {
        cout << fixed;
        cout << showpoint;
        cout << " Your final average is: " << setprecision(2) << Total << "%";
    
    // To display what grade the user received from the class.
        
    if (Total > 89)
    {
        cout << "\n";
        cout << " Your letter grade is: A! ";
    }
    if (Total < 90 && Total > 79)
    {
        cout << "\n";
        cout << " Your letter grade is: B! ";
    }
    if (Total < 80 && Total > 69)
    {
        cout << "\n";
        cout << " Your letter grade is: C! ";
    }
    if (Total < 70 && Total > 59)
    {
        cout << "\n";
        cout << " Your letter grade is: D! ";
    }
    if (Total < 60)
    {
        cout << "\n";
        cout << " Your letter grade is: F! ";
    }
    }
    
    // To display the grade that the user will received if they press No.
    
    if (choice == 'N' || choice == 'n')
    {
        cout << fixed;
        cout << showpoint;
        cout << " Your final average is: " << setprecision(2) << Total << "%";
        
        if (Total > 89)
        {
            cout << "\n";
            cout << " Your letter grade is: A! ";
        }
        if (Total < 90 && Total > 79)
        {
            cout << "\n";
            cout << " Your letter grade is: B! ";
        }
        if (Total < 80 && Total > 69)
        {
            cout << "\n";
            cout << " Your letter grade is: C! ";
        }
        if (Total < 70 && Total > 59)
        {
            cout << "\n";
            cout << " Your letter grade is: D! ";
        }
        if (Total < 60)
        {
            cout << "\n";
            cout << " Your letter grade is: F! ";
        }

    }
        
    return 0;
}

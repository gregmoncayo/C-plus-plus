/*
 Name: Gregory Moncayo
 Course: CGS 3406
 Assignment: Assignment #4
 Due Date: 02/27/2018
 About this Project: To help us gain a better understanding of function
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int RollDice(); // Function that lets the computer roll a pair of dice.

int main()
{
    // Variables to help count the number of times the dice hits a number & to roll  it a certain amount of times.
    int roll, count = 0, counter = 0;
    
    // Display menu for user entry.
    cout << "How many times would you like to roll the dice? ";
    cin >> roll;
    
    // counts the number of times the dice equals 7 or 12.
    
    for (int i = 0; i < roll; i++)
    {
        int total = RollDice();
        
    if (total == 7)
        {
            count++;
        }
        
        else if (total == 12)
        {
            counter++;
        }
    }
    
    // Displays summary.
    
    cout << '\n';
    cout << "A roll of 7 has appeared" << endl;
    cout << "\t\t" << count << " times" << endl;
    cout << "\t\t" << fixed << showpoint << setprecision(2) << (1.0 * count/roll) * 100 << "% of the time" << endl;
    
    cout << '\n';
    cout << "A roll of 12 has appeared" << endl;
    cout << "\t\t" << counter << " times" << endl;
    cout << fixed;
    cout << showpoint;
    cout << "\t\t" << setprecision(2) << (1.0 * counter/roll) * 100 << "% of the time" << endl;
    
    return 0;
}

// Function that randomize dice numbers and adds them up.

int RollDice()
{
    int dice = 1 + rand() % 6;
    int pair = 1 + rand() % 6;
    
    int sum = dice + pair;
    
    return sum;
}

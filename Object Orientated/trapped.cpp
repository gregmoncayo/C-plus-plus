/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 4
 section: 03
 Due Date: 03/02/2018
 About this Project: Upon completion of this program, you should gain experience with the use of managing arrays inside of a class.
 */

#include <iostream>
using namespace std;
void MainMenu();        // To display Main menu

#include "grid.h"

int main()
{
    int row, column;    // To store the number of row & columns the user inputs.
    
    // Display menu for user input.
    
    MainMenu();
    cout << "row: ";
    cin >> row;
    cout << "column: ";
    cin >> column;
    
    // Displays grid
    
    cout << '\n';
    Grid g(row,column);
    g.Display();
    
    // moves cursor
    
    do
    {
        // if front & right is clear, moves by 1
        
        if (g.RightIsClear() && g.FrontIsClear() == 1)
        {
            cout << "You may go forward or turn right. " << endl;
            g.Move(1);
        }
        
        // if front is clear, moves up by one
    
        else if (g.FrontIsClear() == 1)
        {
            cout << "You may go forward." << endl;
            g.Move(1);
        }
        
        // if right is clear, turns to the right & moves up one.
    
        else if (g.RightIsClear() == 1)
        {
            cout << "You may turn right " << endl;
            
            if (g.GetDirection() == 0)
            {
                g.TurnLeft();
                g.TurnLeft();
                g.TurnLeft();
                g.Move(1);
            }
            
            else if (g.GetDirection() == 1)
            {
                g.TurnLeft();
                g.TurnLeft();
                g.TurnLeft();
                g.Move(1);
            }
            
            else if (g.GetDirection() == 2)
            {
                g.TurnLeft();
                g.TurnLeft();
                g.TurnLeft();
                g.Move(1);
            }
            
            else if (g.GetDirection() == 3)
            {
                g.TurnLeft();
                g.TurnLeft();
                g.TurnLeft();
                g.Move(1);
            }
        }
    
        // if cannot move forward or right, turns left & checks again
        else
        {
            cout << "You cannot move forward or right. Now turning left...." << endl;
            g.TurnLeft();
        }
        
    }
    while (g.ReturnWinner() == 1);
   
    // If user wins, displays congrats message
    
    cout << " Congratulations! You escaped and saved the world!! " << endl;
    return 0;
}

// Menu for user input.

void MainMenu()
{
    cout << "\t\t\tWelcome to trapped! \n" << endl;
    cout << "\tGiant Mole People have risen from their underground lairs " << endl;
    cout << "\t& They are taking over the world. Only You could save the world!" << endl;
    cout << "\tFind the exit & join society. Only you could help humanity! " << endl;
    cout << "\tPlease input the number of rows & columns. " << endl;
}

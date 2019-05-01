//
//  main.cpp
//  Template
//
//  Created by Gregory Moncayo on 7/30/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include "Template.h"
#include "template.cpp"

using namespace std;

void Menu();

int main()
{
    char choice = '\0'; // variable for user input
    Pizza<int> P; // Variable for class Pizza
    
    Menu(); // Displays menu

    while (choice != 'X' && choice != 'x')
    {
        cout << ">";
        cin >> choice;
        
        switch (choice)
        {
            case 'A':
            case 'a':
                P.insert(10);
                P.Enter("Hawaiian");
                break;
            case 'B':
            case 'b':
                P.insert(12);
                 P.Enter("Buffalo Chicken");
                break;
            case 'C':
            case 'c':
                P.insert(11);
                 P.Enter("Pepporoni");
                break;
            case 'D':
            case 'd':
                P.insert(8);
                 P.Enter("Cheese");
                break;
            case 'E':
            case 'e':
                P.insert(7);
                 P.Enter("Veggie");
                break;
                
            default:
                break;
        }
    }
    
    P.Display();
    
    
    return 0;
}

void Menu()
{
    cout << "Thank you for choosing Schwapper's Pizza! " << endl;
    cout << "Please choise your pizza. " << endl;
    cout << "A. Hawaiian " << endl;
    cout << "B. Buffalo Chicken " << endl;
    cout << "C. Pepporoni" << endl;
    cout << "D. Cheese " << endl;
    cout << "E. Veggie" << endl;
    cout << "X. Exit " << endl;
}

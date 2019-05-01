//
//  main.cpp
//  proj5
//
//  Created by Gregory Moncayo on 4/15/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include "passserver.h"

using namespace cop4530;
using namespace std;

void Menu();

int main()
{
    char option = '\n';
    int choice = 0;
    int counter = 0;
    string username, password;
    pair<string, string> newUser;
    

    cout << "Enter preferred hash table capacity: ";
    cin >> choice;
    
    PassServer server(choice);
    do
    {
        Menu();
        cin >> option;
        option = toupper(option);
        
        switch (option)
        {
            case 'A':
            cout << "Enter a username: ";
            cin >> username;
            
            cout << endl;
            cout << "Enter a password: ";
            cin >> password;
            
            newUser = make_pair(username, password);
            
            if (!server.addUser(newUser))
            {
                cout << "Couldn't insert information. Please try again. " << endl;
            }
            
            else
                cout << "User " << username << " added!" << endl;
            
                break;
            case 'C':
                break;
            case 'D':
                break;
            case 'F':
                break;
            case 'L':
                break;
            case 'R':
                break;
            case 'S':
                break;
            case 'W':
                break;
            case 'X':
                break;
                
            default:
                break;
        }
        counter++;
    } while (option != 'X');
    
    
    return 0;
}

void Menu()
{
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
}

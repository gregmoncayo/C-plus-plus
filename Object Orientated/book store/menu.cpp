//
//  main.cpp
//  book store
//
//  Created by Gregory Moncayo on 6/23/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "store.h"
#include "book.h"
using namespace std;
void Menu();            // Main Menu

int main()
{
    enum Genre select;                    // to store the user's choice for the Genre Selection
    Store s1;                             // Store object to help call functions
    Book b;
    double money = 0.0, dinero = 0.0;    // to store the amount of money for the cashier and book price
    char title[30], author[30];         // To store the title & author of the book
    char choice, type;                // To store the user's choice
   
    cout << "Please input the starting money into the cash register: ";
    cin >> dinero;
    cout << '\n';
    
    // error message if user types in a negative amount
    
    while (dinero <= 0)
    {
        cout << " Can not enter a negative amount. Please try again. " << endl;
        cout << "Please input the starting money into the cash register: ";
        cin >> dinero;
        cout << '\n';
    }
    
    // Runs the loop until user hits X for exit.
    
    do {
        Menu();
        cin >> choice;
        
        switch (choice)
        {
                
            // Adds a book to the Library
                
            case 'A':
            case 'a':
                cout << "Enter title: ";
                cin.ignore();
                cin.getline(title, 30);
                cout << '\n';
                
                cout << "Enter author: ";
                cin.getline(author, 30);
                cout << '\n';
                
                cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer:  ";
                cin >> type;
                cout << '\n';
                
                cout << "Enter price: ";
                cin >> money;
                cout << '\n';
                
                while (money < 0)
                {
                    cout << "Can not enter a negative amount. Please enter a valid price: ";
                    cin >> money;
                }
                
                switch (type)
            {
                case 'C':
                case 'c':
                    select = COMPUTER;
                    s1.Insert(title, author, select ,money);
                        break;
                case 'f':
                case 'F':
                    select = FICTION;
                    s1.Insert(title, author, select ,money);
                        break;
                case 'm':
                case 'M':
                    select = MYSTERY;
                    s1.Insert(title, author, select ,money);
                    break;
                case 's':
                case 'S':
                    select = SCIFI;
                    s1.Insert(title, author, select ,money);
                        break;
                        
                    default:
                        break;
            }
                
                break;
                
            // Displays the Library
                
            case 'D':
            case 'd':
               s1.DisplayStore();
                break;
                
            // Searches and finds the book
                
            case 'F':
            case 'f':
                cout << "Enter search string (title or author): ";
                cin.ignore();
                cin.getline(title, 30);
                
                s1.Find(title);
                
                if (s1.Find(title) == -1)
                {
                    cout << title << ": not found. " << endl;
                }
                
                else
                {
                    cout << "Book found: " << endl;
                    cout << b.GetTitle() << " " << b.GetAuthor() << " " << b.GetGenre() << " " << b.GetPrice() << endl;
                    cout << endl;
                }
                
                break;
                
            // Classifies the books by Genre
                
            case 'G':
            case 'g':
                
                cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer:  ";
                cin >> type;
                cout << '\n';
                
                switch (type)
            {
                case 'C':
                case 'c':
                    select = COMPUTER;
                    s1.Genre(select);
                    break;
                case 'f':
                case 'F':
                    select = FICTION;
                    s1.Genre(select);
                    break;
                case 'm':
                case 'M':
                    select = MYSTERY;
                    s1.Genre(select);
                    break;
                case 's':
                case 'S':
                    select = SCIFI;
                    s1.Genre(select);
                    break;
                    
                default:
                    cout << "Invalid genre entry.  Please re-enter: " << endl;
                    cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer:  ";
                    cin >> type;
                    break;
            }
                
                break;
            case 'M':
            case 'm':
                Menu();
                break;
                
            // Sells the book
                
            case 'S':
            case 's':
                cout << "Enter title to sell: ";
                cin.ignore();
                cin.getline(title, 30);
                
                if (s1.Sell(title) == true)
                {
                    s1.Sell(title);
                    cout << "Sale complete!" << endl;
                    cout << endl;
                }
                
                else if (s1.Sell(title) == false)
                {
                    cout << title << " not found in the inventory" << endl;
                    cout << "* no sale made *" << endl;
                    cout << endl;
                }
                
                break;
                
            default:
                
                break;
        }
    } while (choice != 'X' && choice != 'x');
    
    cout << "Goodbye! " << endl;
    
    
    return 0;
}

// Main menu display

void Menu()
{
    cout << "A:   Add a book to inventory " << endl;
    cout << "F:   Find a book from inventory " << endl;
    cout << "S:   Sell a book " << endl;
    cout << "D:   Display the inventory list " << endl;
    cout << "G:   Genre summary " << endl;
    cout << "M:   Show this Menu" << endl;
    cout << "X:   eXit the program " << endl;
    cout << "Please enter a choice " << endl;
    cout << ">";
}

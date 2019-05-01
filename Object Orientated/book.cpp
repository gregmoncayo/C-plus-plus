//
//  book.cpp
//  book store
//
//  Created by Gregory Moncayo on 6/23/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

// Default constructor to set the objects
Book:: Book()
{
    title[0] = '\0';
    author[0] = '\0';
    type = FICTION;
    price = 0.0;
}

// Set constructor to set the objects to the parameters

void Book:: Set(const char* t, const char* a, Genre g, double p)
{
    strcpy(title, t);
    strcpy(author, a);
    type = g;
    price = p;
}

// returns the title of the book

const char* Book:: GetTitle() const
{
    return title;
}

// returns the author of the book

const char* Book:: GetAuthor() const
{
    return author;
}

// returns the price of the book

double Book:: GetPrice() const
{
    return price;
}

// returns the genre of the book

Genre Book:: GetGenre() const
{
    return type;
}

// Displays the results

void Book:: Display() const
{
    cout << endl;
    cout << title << setw(25) << author;
    
    switch (type)
    {
        case FICTION:
            cout << fixed;
            cout << showpoint;
            cout << setw(25) << " Fiction " << setw(25) << setprecision(2) << " $ " << price << endl;
            cout << endl;
            break;
        case MYSTERY:
            cout << setw(25) << " Mystery " << setw(25) << setprecision(2) << " $ " << price << endl;
            cout << endl;
            break;
        case SCIFI:
            cout << setw(25) << " Sci Fi " << setw(25) << setprecision(2) << " $ " << price << endl;
            cout << endl;
            break;
        case COMPUTER:
            cout << setw(25) << " Computer " << setw(25) << setprecision(2) << " $ " << price << endl;
            cout << endl;
            break;
            
        default:
            break;
    }
}

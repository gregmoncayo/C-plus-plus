//
//  store.cpp
//  book store
//
//  Created by Gregory Moncayo on 6/23/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "book.h"
#include "store.h"

// Default Constructor to store everything to 0

Store:: Store()
{
    CurrentSize = 0;
    cash = 0.0;
    size = 0;
    storelist = new Book[size];
}

// Destructor to clean up memory

Store:: ~Store()
{
    delete [] storelist;
}

// To add books in the library

void Store:: Insert(const char * story, const char * auth, enum Genre select, double price)
{
    if (size == CurrentSize)
        Grow();
    
    storelist[CurrentSize++].Set(story, auth, select, price);
}

// To find the book within the library

int Store:: Find(char * name) const
{
    for (int i = 0; i < CurrentSize; i++)
    {
        if (strcmp(storelist[i].GetAuthor(), name) == 0)
        {
            return i;
        }
        
        if (strcmp(storelist[i].GetTitle(), name) == 0)
        {
            return i;
        }
    }
    
    return -1;
}

// To sell the book

bool Store:: Sell(char * name)
{
    if (Find(name) == -1)
    {
        return false;
    }
    
    else
    {
        for (int i = Find(name)+1; i < CurrentSize; i++)
        {
            storelist[i-1] = storelist[i];
        }
    
        CurrentSize--;
    
        return true;
    }
}

// To locate the book by Genre

void Store:: Genre(enum Genre selection)
{
    int count = 0;      // counts the number of books within the genre
    
    switch (selection)
    {
        case FICTION:
            
            // Display results for Fiction genre
            
            for (int i = 0; i < CurrentSize; i++)
            {
                if (storelist[i].GetGenre() == 0)
                {
                    count++;
                    cash += storelist[i].GetPrice();
                    cout << storelist[i].GetTitle() << setw(25) << storelist[i].GetAuthor() << setw(25) << " Fiction" << endl;
                }
            }
            cout << endl;
            cout << "Total books in this genre = " << count << endl;
            cout << fixed;
            cout << showpoint;
            cout << "Total price of books in this genre = $" << setprecision(2) << cash << endl;
            cout << endl;
            break;
        case MYSTERY:
            
            // Display results for Mystery genre
            
            for (int i = 0; i < CurrentSize; i++)
            {
                if (storelist[i].GetGenre() == 1)
                {
                    count++;
                    cash += storelist[i].GetPrice();
                    cout << storelist[i].GetTitle() << setw(25) << storelist[i].GetAuthor() << setw(25) << endl;
                }
            }
            
            cout << "Total books in this genre = " << count << endl;
            cout << fixed;
            cout << showpoint;
            cout << "Total price of books in this genre = $" << setprecision(2) << cash << endl;
            cout << endl;
            break;
        case SCIFI:
            
            // Display results for Sci Fi genre
            
            for (int i = 0; i < CurrentSize; i++)
            {
                if (storelist[i].GetGenre() == 2)
                {
                    count++;
                    cash += storelist[i].GetPrice();
                    cout << storelist[i].GetTitle() << setw(25) << storelist[i].GetAuthor() << setw(25) << endl;
                }
            }
            
            cout << "Total books in this genre = " << count << endl;
            cout << fixed;
            cout << showpoint;
            cout << "Total price of books in this genre = $" << setprecision(2) << cash << endl;
            cout << endl;
            break;
            
        // Display results for Computer genre
            
        case COMPUTER:
            
            for (int i = 0; i < CurrentSize; i++)
            {
                if (storelist[i].GetGenre() == 3)
                {
                    count++;
                    cash += storelist[i].GetPrice();
                    cout << storelist[i].GetTitle() << setw(25) << storelist[i].GetAuthor() << setw(25) << endl;
                }
            }
            
            cout << "Total books in this genre = " << count << endl;
            cout << fixed;
            cout << showpoint;
            cout << "Total price of books in this genre = $" << setprecision(2) << cash << endl;
            cout << endl;
            break;
            
        default:
            break;
    }
}

// To grow the array

void Store:: Grow()
{
    size = CurrentSize + 5;
    Book * newlist = new Book[size];
    
    for (int i = 0; i < CurrentSize; i++)
    {
        newlist[i] = storelist[i];
    }
    
    delete [] storelist;
    
    storelist = newlist;
}

// To display the results

void Store:: DisplayStore() const
{
    cout << "**Title**" << setw(25) << "**Author**" << setw(25) << "**Genre**" << setw(25) << "**Price**" << endl;
    
    for (int i = 0; i < CurrentSize; i++)
    {
        storelist[i].Display();
    }
}

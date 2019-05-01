//
//  store.hpp
//  book store
//
//  Created by Gregory Moncayo on 6/23/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
#include "book.h"

using namespace std;

class Store
{
    public:
    Store();                            // Constructor
    ~Store();                           // Destructor
    void Insert(const char * story, const char * auth, enum Genre select, double price);  // Adds a book
    int Find(char * name) const;        // Finds a book
    bool Sell(char * name);             // removes a book
    void Genre(enum Genre selection);   // Finds book by Genre
    void DisplayStore() const;          // Displays
    void Grow();                        // Grows the array
    
    private:
    int size;                           // The max size of the array
    int CurrentSize;                    // The current size of the array
    double cash;                        // How much money the book is
    Book * storelist;                   // Book pointer to store data 
};

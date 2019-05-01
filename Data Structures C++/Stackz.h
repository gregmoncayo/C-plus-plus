//
//  pro3.h
//  proj3
//
//  Created by Gregory Moncayo on 2/25/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#ifndef pro3_h
#define pro3_h

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

namespace cop4530
{
    template <typename T>
    class Stack
    {
    public:
        Stack();                // constructor
        ~Stack();               // destructor
        Stack(const Stack<T> &);   // Copy Constructor
        Stack(Stack<T> &&);         // Move constructor
        Stack<T> & operator=(const Stack<T>&); // Copy assignment operator
        Stack<T> & operator=(Stack<T> &&); // move assignment operator
        bool empty() const; // checks if stack is empty
        void clear();       // deletes elements from the stack
        void push(const T& x); // Copy version of adding an element to the stack
        void push(T && x); // Move version of adding an element to the stack
        void pop(); // Removes the most recently added element of the stack
        T & top(); // mutator that returns a reference to the most added element to the stack
        const T & top() const; // accessor that returns the most recently added element
        int size() const; // returns the number of elements within the stack
        void print(std:: ostream& os, char ofc = ' ') const; // prints the stack
        
    private:
        std::vector<T> StackArray;
    };
    
    template <typename T>
    std::ostream& operator<< (std::ostream& os, const Stack<T>& a);
    
    template <typename T>
    bool operator== (const Stack<T>&, const Stack <T>&);
    
    template <typename T>
    bool operator!= (const Stack<T>&, const Stack <T>&);
    
    template <typename T>
    bool operator<= (const Stack<T>& a, const Stack <T>& b);
    
#include "Stackz.hpp"
}



#endif /* pro3_h */

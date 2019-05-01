//
//  stack.hpp
//  proj3
//
//  Created by Gregory Moncayo on 2/25/19.
//  Copyright © 2019 Gregory Moncayo. All rights reserved.
//

#ifndef stack_h
#define stack_h
// constructor
template <class T>
Stack<T> :: Stack()
{
    
}

// destructor
template <class T>
Stack<T>:: ~Stack()
{
    clear();
}

// Copy Constructor
template <class T>
Stack<T>:: Stack(const Stack<T> & S)
{
    StackArray = S.StackArray;
}

// Move constructor
template <class T>
Stack<T>:: Stack(Stack<T> && S)
{
    StackArray = S.StackArray;
    S.StackArray = nullptr;
}

// Copy assignment operator
template <class T>
Stack<T> & Stack<T>:: operator=(const Stack<T> & S)
{
    if (this != &S)
    {
        StackArray = S.StackArray;
    }
    
    return *this;
}

// move assignment operator
template <class T>
Stack<T> & Stack<T>:: operator=(Stack<T> && S)
{
    std::swap(S.StackArray, StackArray);
}

// checks if stack is empty
template <class T>
bool Stack<T>:: empty() const
{
    return size() == 0;
}


// deletes elements from the stack
template <class T>
void Stack<T>:: clear()
{
    while (!empty())
    {
        pop();
    }
}

// Copy version of adding an element to the stack
template <class T>
void Stack<T>:: push(const T & x)
{
    StackArray.push_back(x);
}

// Move version of adding an element to the stack
template <class T>
void Stack<T>:: push(T && x)
{
    StackArray.push_back(std:: move(x));
}


// Removes the most recently added element of the stack
template <class T>
void Stack<T>:: pop()
{
    StackArray.pop_back();
}

// mutator that returns a reference to the most added element to the stack
template <class T>
T & Stack<T>:: top()
{
    return StackArray.back();
}

// accessor that returns the most recently added element
template <class T>
const T & Stack<T>:: top() const
{
    return StackArray.back();
}


// returns the number of elements within the stack
template <class T>
int Stack<T>:: size() const
{
    return StackArray.size();
}

// prints the stack
template <class T>
void Stack<T>:: print(std:: ostream& os, char ofc) const
{
    auto itr = StackArray.begin();
    
    while (itr != StackArray.end())
    {
        os << *itr << ofc;
        ++itr;
    }
}

// outside member function that prints the stack

template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
    a.print(os);
    
    return os;
}

// outside member function that determines whether two stacks are equal, returns false otherwise

template <typename T>
bool operator== (const Stack<T>& S1, const Stack <T>& S2)
{
    Stack<T> a = S1;
    Stack<T> b = S2;
    
    if (a.size() == b.size())
    {
        while (!a.empty() && !b.empty())
        {
            if (a.top() == b.top())
            {
                return true;
            }
            
            a.pop();
            b.pop();
        }
        
    }
    
    return false;
}

// outside member function that determines whether two stacks are not equal, returns false otherwise

template <typename T>
bool operator!= (const Stack<T>& S1, const Stack <T>& S2)
{
    if (operator==(S1, S2) == false)
    {
        return true;
    }
    
    return false;
}

// outside member function that determines whether stack a is less than or equal to stack b, returns false otherwise

template <typename T>
bool operator<= (const Stack<T>& a, const Stack <T>& b)
{
    Stack<T> S1 = a;
    Stack<T> S2 = b;
    
    if (S2.size() > S1.size())
    {
        while (!S1.empty())
        {
            if (S1.top() > S2.top())
            {
                return false;
            }
            
            S1.pop();
            S2.pop();
        }
    }
    
    return true;
}


#endif /* stack_h */

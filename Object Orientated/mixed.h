//
//  mixed.h
//  mixed numbers
//
//  Created by Gregory Moncayo on 6/9/18.
//  Copyright © 2018 Gregory Moncayo. All rights reserved.
//

#include <iostream>
using namespace std;

class Mixed
{
    //operator overloads standard input and output
    friend ostream & operator<<(ostream & s, const Mixed & m);  // for output
    friend istream & operator>>(istream & i, Mixed & m);  // for input
    
    // operator overloads comparisons operators
    friend bool operator==(const Mixed & M1, const Mixed & M2);   // whether first & second param are equal
    friend bool operator!=(const Mixed & M1, const Mixed & M2);  // whether first & second param aren't equal
    friend bool operator<=(const Mixed & M1, const Mixed & M2); // if first param is less than/equal to 2nd param
    friend bool operator>=(const Mixed & M1, const Mixed & M2); // if first param is greater than/ equal to 2nd param
    friend bool operator<(const Mixed & M1, const Mixed & M2);  // if first param is less than 2nd param
    friend bool operator>(const Mixed & M1, const Mixed & M2);  // whether first parameter is greater than 2nd param
    
    
    //operator overloads arthimetic operations
    friend Mixed operator+(const Mixed & M1, const Mixed & M2); // adds first paramater & second parameter
    friend Mixed operator-(const Mixed & M1, const Mixed & M2); // Subtracts first parameter from second parameter
    friend Mixed operator*(const Mixed & M1, const Mixed & M2); // Multiplies first parameter to second parameter
    friend Mixed operator/(const Mixed & M1, const Mixed & M2); // Divides first parameter to second parameter
    
    public:
    Mixed(int value = 0);           // Default constructor with one parameter
    Mixed(int i, int n, int d);     // Constructor with three parameters to represent the whole number & fraction
    double Evaluate();               // Evalutes the fraction
    void ToFraction();              // Converts the mixed number into fraction form
    void Simplify();                // Simplifies the fraction
    Mixed & operator++();           // pre increment
    Mixed & operator++(int);        // post increment
    Mixed & operator--();           // pre increment
    Mixed & operator--(int);        // post increment
    
    // Accessors
    int GetInteger();       // Returns integer
    int ReturnNum();        // Returns numerator
    int ReturnDenom();      // Returns denominator
    
    
    private:
    int integer;
    int numerator;
    int denominator;
};

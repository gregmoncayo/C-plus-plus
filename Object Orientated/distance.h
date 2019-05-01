//------------------Distance.H--------------------

#include <iostream>

using namespace std;

class Distance
{
    // Friend operators & Arithmetic operators
    
    friend ofstream& operator << (ostream & m, Distance & c);
    friend ifstream& operator >> (ifstream & z, Distance & l);
    friend Distance operator+(const Distance & add1, const Distance & add2);
    friend Distance operator-(const Distance & sub1, const Distance & sub2);
    friend Distance operator*(const Distance & mult1, const Distance & mult2);
    
    public:
    Distance();                                     // Default Constructor
    Distance(int inch);                            // Constructor with parameter
    Distance(int m, int y, int f, int i);         // Constructor with three parameters.
    Distance & operator++();                     // pre increment.
    Distance & operator++(int);                 // post increment.
    Distance & operator--();                   // pre increment.
    Distance & operator--(int);               // post increment.
    
    // Comparisons operators
    
    bool Equals(Distance x, Distance y);
    bool lessthan(Distance x, Distance y);
    bool greaterthan(Distance x, Distance y);
    bool LessThanEqualtoo(Distance x, Distance y);
    bool GreaterThanEqualtoo(Distance x, Distance y);
    bool DoesNotEqualTo(Distance x, Distance y);
    
    private:
    int miles;
    int yards;
    int feet;
    int inches;
};

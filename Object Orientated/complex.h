#include <iostream>		// for "ostream", "istream" below
using namespace std;

class Complex
{
    friend Complex operator+(const Complex& , const Complex& );
    friend Complex operator-(const Complex& , const Complex& );
    friend Complex operator*(const Complex& , const Complex& );
    friend Complex operator/(const Complex& , const Complex& );
    
    friend ostream& operator<<(ostream& , const Complex& );
    friend istream& operator>>(istream& , Complex& );
    
public:
    Complex(double r = 0.0, double im = 0.0);
    // note that this constructor acts as:
    //   - default constructor (sets to 0 + 0i)
    //   - conversion constructor (double to Complex)
    //   - and constructor with 2 params (r + im * i)
    
    ~Complex();		// destructor.  Not really needed here.
    
    // accessors
    double getReal() const;	// return real part
    double getImaginary() const;	// return imaginary part
    
    // mutator
    void set(double r, double im = 0.0);	// sets to r + im * i
    
    // increment and decrement operations
    Complex& operator++();	// prefix increment
    Complex operator++(int);	// postfix increment
    Complex& operator--();	// prefix decrement
    Complex operator--(int);	// postfix decrement
    
private:
    double real;		// real part.  Can be any double
    double imag;		// imaginary part.  Can be any double
};

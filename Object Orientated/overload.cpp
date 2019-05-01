#include "complex.h"		// note that iostream was already
//  #included in the header file

// FRIEND FUNCTIONS

Complex operator+(const Complex& c1, const Complex& c2)
{
    // this is an explicit call to the constructor
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
    
    /* Note:  the above code is a SHORTER way of saying this:
     *
     *   Complex result;			 // build object to store result
     *   result.real = c1.real + c2.real;  // add the real parts
     *   result.imag = c1.imag + c2.imag;	 // add the imaginary parts
     *   return result;			 // return the result
     */
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
    double realPart = c1.real * c2.real - c1.imag * c2.imag;
    double imagPart = c1.imag * c2.real + c1.real * c2.imag;
    
    return Complex(realPart, imagPart);
}

Complex operator/(const Complex& c1, const Complex& c2)
{
    double realPart = (c1.real * c2.real + c1.imag * c2.imag)
    / (c2.real * c2.real + c2.imag * c2.imag);
    double imagPart = (c1.imag * c2.real - c1.real * c2.imag)
    / (c2.real * c2.real + c2.imag * c2.imag);
    
    return Complex(realPart, imagPart);
}

ostream& operator<<(ostream& os, const Complex& c)
{
    if (c.imag == 0)
        return (os << c.real);		// no imaginary part
    
    if (c.real == 0)
        return (os << c.imag << 'i');	// no real part
    
    os << c.real;			// both parts
    if (c.imag > 0)
        os << " + " << c.imag << 'i';
    else
        os << " - " << -c.imag << 'i';
    
    return os;
}

/* Allows input in this format:  RL + IMi or RL - IMi
 *   where RL is the real part
 *         IM is the imaginary part
 *         and i is square root of -1
 */
istream& operator>>(istream& is, Complex& c)
{
    char symbol, iMarker;
    is >> c.real >> symbol >> c.imag >> iMarker;
    if (symbol == '-')
        c.imag = -c.imag;
    
    return is;
}

// MEMBER FUNCTIONS

/* Constructor sets object to r for the real part, im for the imaginary
 * part.  Notice that this also acts as a default constructor (0 parameters),
 * as well as a conversion constructor (enabling auto-conversions from
 * double to Complex, where the double is the real part)
 */
Complex::Complex(double r, double im)
{
    real = r;
    imag = im;
}

/* Destructor has no real work to do here.  Object has no dynamically
 managed memory inside */
Complex::~Complex()
{
}

double Complex::getReal() const
{  return real;  }

double Complex::getImaginary() const
{  return imag;  }

/* set function will set object to r + im * i, where i represents square
 root of -1.  im is an optional parameter.  */
void Complex::set(double r, double im)
{
    real = r;
    imag = im;
}

/* For the increment and decrement operators, we're simply defining the
 * incrementing of an imaginary number to be an increment of the REAL
 * part by 1, and decrementing as a decrement of the real part by 1
 */

Complex& Complex::operator++()	// pre-fix increment
{
    real = real + 1;		// increment the real part
    return *this;		// return reference to calling object
}

Complex Complex::operator++(int)	// post-fix increment
{
    Complex temp = *this;	// copy current object to temp
    real = real + 1;		// increment
    return temp;			// return OLD value
}

Complex& Complex::operator--()	// pre-fix decrement
{
    real = real - 1;		// decrement the real part
    return *this;		// return reference to calling object
}

Complex Complex::operator--(int)
{
    Complex temp = *this;	// copy current object to temp
    real = real - 1;		// decrement
    return temp;			// return OLD value
}

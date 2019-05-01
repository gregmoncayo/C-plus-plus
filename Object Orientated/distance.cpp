//----------------------Distance.h--------------------

#include <iostream>
#include "distance.h"

using namespace std;

Distance:: Distance()
{
    if (miles < 0)
    {
        miles = 0;
    }
    
    if (yards < 0)
    {
        miles = 0;
    }
    
    if (feet < 0)
    {
        feet = 0;
    }
    
    if (inches < 0)
    {
        inches = 0;
    }
}

Distance:: Distance(int inch)
{
    
    Distance();
    
    inch = inches;
    
    if (inch < 0)
    {
        inches = 0;
    }
    
    if (inch > 11)
    {
        feet++;
        inches = 0;
    }

    if (feet > 2)
    {
        yards++;
        feet = 0;
    }
    
    if (yards > 1759)
    {
        miles++;
        yards = 0;
    }
    
}

Distance:: Distance(int m, int y, int f, int i)
{
    Distance();
    
    m = miles;
    y = yards;
    f = feet;
    i = inches;
    
    if (i > 11)
    {
        f++;
        i = i % 12;
    }
    
    if (f > 2)
    {
        y++;
        f = f % 2;
    }
    
    if (y > 1759)
    {
        m++;
        y = y % 1759;
    }
    
}

ofstream& operator << (ostream & m, Distance c)
{
    m << c.miles << " miles" << c.yards << " yards" << c.feet << " feet" << c.inches << " inches" << endl;
    
    return m;
}

ifstream& operator >> (ifstream & z, Distance & l)
{
    char temp;
    
    z >> l.miles >> temp >> l.yards >> temp >> l.feet >> temp >> l.inches;
    
    return z;
}

Distance operator+(const Distance & add1, const Distance & add2)
{
   return ((add1.miles + add2.miles) + (add1.yards + add2.yards) + (add1.feet + add2.feet) + (add1.inches) + (add2.inches));
}

Distance operator-(const Distance & sub1, const Distance & sub2)
{
    return ((sub1.miles - sub2.miles) - (sub1.yards - sub2.yards) - (sub1.feet - sub2.feet) - (sub1.inches - sub2.inches));
}

Distance operator*(const Distance & mult1, const Distance & mult2)
{
    return mult1.feet * mult2.feet;
}

Distance:: Distance & operator++()
{
    inches = inches + 1;
    return *this;
}

Distance:: Distance & operator++(int)
{
    Distance temp = *this;
    inches = inches + 1;
    return temp;
}

Distance:: Distance & operator--()
{
    inches = inches - 1;
    return *this;
}

Distance:: Distance & operator--(int)
{
    Distance temp = *this;
    inches = inches - 1;
    return temp;
}

bool Equals(Distance x, Distance y)
{
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet == y.feet)
            {
                if (x.inches == y.inches)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool lessthan(Distance x, Distance y)
{
    if (x.miles < y.miles)
    {
        return true;
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards < y.yards)
        {
            return true;
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet < y.feet)
            {
                return true;
            }
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet == y.feet)
            {
                if (x.inches < y.inches)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool greaterthan(Distance x, Distance y)
{
    if (x.miles > y.miles)
    {
        return true;
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards > y.yards)
        {
            return true;
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet > y.feet)
            {
                return true;
            }
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet == y.feet)
            {
                if (x.inches > y.inches)
                {
                    return false;
                }
            }
        }
    }
    
    return false;
}

bool LessThanEqualtoo(Distance x, Distance y)
{
    if (x.miles <= y.miles)
    {
        return true;
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards <= y.yards)
        {
            return true;
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet <= y.feet)
            {
                return true;
            }
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet == y.feet)
            {
                if (x.inches <= y.inches)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool GreaterThanEqualtoo(Distance x, Distance y)
{
    if (x.miles >= y.miles)
    {
        return true;
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards >= y.miles)
        {
            return true;
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet >= y.feet)
            {
                return true;
            }
        }
    }
    
    if (x.miles == y.miles)
    {
        if (x.yards == y.yards)
        {
            if (x.feet == x.feet)
            {
                if (x.inches >= y.inches )
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool DoesNotEqualTo(Distance x, Distance y)
{
    if (x.miles != y.miles)
    {
        if (x.yards != y.yards)
        {
            if (x.feet != y.feet)
            {
                if (x.inches != y.inches)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

// starter file for MyInt class header

/*
 Name: Gregory Moncayo
 Course: COP 3330
 Assignment: Assignment # 5
 Due Date: 03/26/2018
 About this Project: To learn more about dynamic allocation.
 */


using namespace std;

class MyInt
{
    // these overload starters are declared as friend functions
    
    friend MyInt operator+(const MyInt & x, const MyInt & y);       // friend function to add two objects.
    friend MyInt operator-(const MyInt & x, const MyInt & y);       // friend function to subtract two objects.
    friend MyInt operator*(const MyInt & x, const MyInt & y);       // friend function to add two objects.
    friend MyInt operator%(const MyInt & x, const MyInt & y);       // friend function to modify two objects.
    
    friend ostream & operator << (ostream & f, MyInt i);            // to output the data of the object.
    friend istream & operator >> (istream & s,  MyInt & i);         // to input new data into the object.
    
    friend bool operator< (const MyInt & x, const MyInt & y);       // to determine whether object X is less than object Y.
    friend bool operator> (const MyInt & x, const MyInt & y);       // to determine whether object X is greater than object Y.
    friend bool operator>= (const MyInt & x, const MyInt & y);      // whether object X is greater than/equal to object Y.
    friend bool operator<= (const MyInt & x, const MyInt & y);      // whether object X is less than/equal to object Y.
    friend bool operator== (const MyInt & x, const MyInt & y);      // to determine whether object X is equal to object Y.
    friend bool operator != (const MyInt & x, const MyInt & y);     // to determine whether object X is not equal to object Y.
    
    // add in the other comparison overloads, as well
    
    // declare overloads for input and output (MUST be non-member functions)
    //  you may make them friends of the class
    
public:
    MyInt(int n = 0);                      // first constructor
    MyInt(char s[]);                      // string constructor
    ~MyInt();                            // destructor
    MyInt(const MyInt & i);               // copy constructor
    MyInt & operator=(const MyInt & i);    // assignment constructor
    int C2I(char c);                        // convertor from character to integer
    char I2C(int x);                        // convertor from integer to character
    // be sure to add in the second constructor, and the user-defined
    //  versions of destructor, copy constructor, and assignment operator
    
    MyInt & operator++();       // pre increment
    MyInt operator++(int);      // post increment
    int GetArr();               // returns the value of the pointer
    int GetSize();              // returns the size of the array
    
    
private:
    int * arr;                  // pointer to access our data within the array.
    unsigned int size;          // to count the size of each array.
    // member data (suggested:  use a dynamic array to store the digits)
    
};

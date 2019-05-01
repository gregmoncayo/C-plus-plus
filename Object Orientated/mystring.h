#include <iostream>
using namespace std;

class MyString
{
    friend ostream& operator<< (ostream& , const MyString& );   // Displays the data
    friend istream& operator>> (istream& , MyString& );         // Inputs data until whitespace
    friend istream& getline (istream& , MyString& , char);      // Inputs data
    
    friend MyString operator+ (const MyString& , const MyString& ); // Adds data together
    
    friend bool operator< (const MyString& , const MyString& );      // Compares data & determines whether less than
    friend bool operator> (const MyString& , const MyString& );     // Compares data & determines whether greater than
    friend bool operator<=(const MyString& , const MyString& );    // Compares data & determines whether less/equal
    friend bool operator>=(const MyString& , const MyString& );   // Compares data & determines whether greater/equal
    friend bool operator==(const MyString& , const MyString& );  // Compares data & determines whether equal to
    friend bool operator!=(const MyString& , const MyString& ); // Compares data & determines whether not equal to
    
public:
    MyString();                // empty string
    MyString(const char* );        // conversion from c-string
    MyString(int );            // conversion from int
    ~MyString();                // destructor
    MyString(const MyString& );        // copy constructor
    MyString& operator=(const MyString& );   // assignment operator
    
    MyString& operator+=(const MyString& );  // concatenation/assignment
    
    // bracket operators to access char positions
    char& operator[] (unsigned int index);
    const char& operator[] (unsigned int index) const;
    
    // insert s into the string at position "index"
    MyString& insert(unsigned int index, const MyString& s);
    
    // find index of the first occurrence of s inside the string
    //  return the index, or -1 if not found
    int indexOf(const MyString& s) const;
    
    int getLength() const;        // return string length
    const char* getCString() const;    // return c-string equiv
    int GetCurrent() const;             // returns current size of the array
    
    MyString substring(unsigned int , unsigned int ) const; // concentrates from the index a to index b
    MyString substring(unsigned int ) const;                // concentrates from index a & on
    
    void Grow();                // Grows the array
    
private:
    int length;         // Maximum length of the array
    char * str;         // character pointer
    int CurrentSize;    // Keeps track of the current array
    
};

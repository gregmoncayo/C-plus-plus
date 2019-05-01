#include <iostream>
using namespace std;

class votes
{
    friend ostream& operator<< (ostream &, const votes &);
    
    public:
    votes(const char cand[]);   // Constructor
    votes(const votes& x);  // copy constructor
    ~votes();               // destructor
    void AddPrecinct(int c);    // inserts one vote count in list
    
    private:
    int * counts;   // pointer to a dynamic array of vote counts
    int numReported;    // Number of precinct counts reported/stored
    char candidate[26]; // Fixed storage for candidate name (c-string)
};

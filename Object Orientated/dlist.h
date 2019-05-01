const int MAX = 10;

class DList
{
public:
    DList();			// initialize empty list
    bool Insert(double item);	// inserts item into list (if room)
    double GetElement(unsigned int n) const;	// returns element at index n
    void Print() const;		// prints the list
    int GetSize() const;		// returns number of elements in list
    
    bool Delete(int n);  // delete the nth element of the list
                        //  return true for success, false if n not a valid position
    
    double Sum();        // return the sum of the elements of the list
    double Average();    // return the average of the elements of the list
    double Max();        // return the maximum value in the list
    void Clear();        // reset the list to empty
    int Greater(double x); // count how many values in th
    
private:
    double array[MAX];
    int current;		// number of stored items (max is 10)
    
};

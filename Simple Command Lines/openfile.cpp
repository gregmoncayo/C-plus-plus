//  Bob Myers
//
//  count.cpp
//  Example that reads in any file consisting of ANY number of integers,
//   separated by any amount of white space.  The program will read in
//   all the integers, and compute their sum and their average

#include <iostream>
#include <iomanip>    // for setw
#include <fstream>    // for ifstream, ofstream

using namespace std;

int main()
{
    char filename[25];      // a string for filename entry
    
    int val;		   // for reading integers from file
    int sum = 0, count = 0;
    double average;
    
    ifstream in1;        // create an input file stream
    
    do
    {
        in1.clear();
        cout << "Please enter the name of the input file.\n";
        cout << "Filename:  ";
        cin >> setw(25) >> filename;
        
        in1.open(filename);
        if (!in1)
            cout << "That is not a valid file.  Try again!\n";
        
    } while (!in1);
    
    // PROCESS THE INPUT FILE
    //  Read all integer values and compute average
    
    while (!in1.eof())	     // while not end of file
    {
        in1 >> val;	     // read an integer from file
        
        if (!in1.fail())	     // in case last call failed to read an int
        {			     //  due to trailing white space at end of file
            count++;
            sum += val;
        }
    }
    
    average = static_cast<double>(sum) / count;
    
    cout << "There were " << count << " numbers in the file\n";
    cout << "Sum = " << sum << "\t\tAverage = " << average << "\n\n";
    
    in1.close();
    
    return 0;
}

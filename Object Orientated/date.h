//-------------------DATE.H---------------------

class Date
{

    public:
        Date();         // Constructor
        Date(int mth, int dy, int yr);       // Constructor with parameters to help figure out the month, day, and year
        bool Set(int m, int d, int y);      // Function that returns true if the m,d, & y are in the correct format.
        bool SetFormat(char f);            // Function that helps set three different types of date format to the computer.
        int compare(const Date & d);  // Function that compares two dates and returns a certain value whether a date comes first.
        void Increment(int numDays = 1); // Adds one or more days to the calendar when called.
        void Input();                       // Function used for user entry and input.
        void Show();                        // Function to display the calendar and days.

    // Accessors
    int GetMonth();                 // Retrieves the month from the computer.
    int GetDay();                   // Retrieves the day from the user.
    int GetYear();                  // Retrieves the year from the program.
    
    private:
        int day;                    // Variable to help retrieve what day of the year it is.
        int month;                  // Variable to help retrieve what month of the year it is.
        int year;                   // Variable to help retrieve what year it is.
        char format;                // Variable that helps retrieve the certain format of the different types of displays.
};

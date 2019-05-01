/*
 Name: Gregory Moncayo
 Course: COP 3330
 Section: 3
 Assignment: 2
 Due Date: 02/5/2018
 About this Project: To help us gain a better understanding on objects and implementing classes.
 */

class Temperature
{
    public:
        Temperature(double temp = 0, char letter = 'C');        // Constructor with parameters.
        void Input();                                           // Input function to gather data.
        const void Show();                                      // Summary function.
        bool set(double deg, char s);                           // Set function to scale and temperature.
        double GetDegrees();                                    // Accessors
        char GetScale();                                        // Accessors
        bool SetFormat(char f);                                 // Set Format function to display different formats.
        bool convert(char sc);                                  // Converts the temperature to different types.
        int compare(const Temperature & d);                     // Compares the different temperatures to one another.
    
    private:
        char format;                                            // Variable to store the format type.
        char Scale;                                             // Variable to hold temperature Scale.
        double degrees;                                         // Variable to store the temperature.
};

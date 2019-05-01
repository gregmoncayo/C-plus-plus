#include <iostream>
class Money
{
public:
    Money();
    
    
    // Mutators
    void Input();
    void Summary() const;
    
    // Accesors
    int ReturnDollar() const;
    int ReturnCents() const;
private:
    int dollars;
    int cents;
};

//-----------House.H-----------

class House
{
    public:
        House(int size2, char charac = 'X', char fill = '*');
    
    // Standard Input/Output
        void summary();
        void draw();
    
    // Member functions
        int GetSize();
        int perimeter();
        double area();
        const int Grow();
        const int Shrink();
        void setborder(char bord);
        void SetFill(char fill);
    
    private:
        int size;
        int base;
        char border;
        char filler;
};

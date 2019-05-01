#include <iostream>

using namespace std;

class FFF
{
public:
    FFF() { a =5; c = 11;};
    virtual int GetValue() {return c;};
    
    int Fetch() {return a; };
    
protected:
    int a;
    
private:
    int c;
};

class GGG: public FFF
{
public:
    GGG()   {m=7; d=16;};
    int GetValue()  {return m;};
    virtual int Fetch() {return d;};
    
protected:
    int m;
    
private:
    int d;
};

class HHH : public GGG
{
public:
    HHH() {h=14;};
    int GetValue() {return (h + FFF::GetValue());};
    int fetch() {return 40;};
    
private:
    int h;
    
};

class MMM : public GGG
{
public:
    MMM()   {t = -1; m = m + 9;};
protected:
    int t;
    
};

class PPP: public FFF
{
public:
    PPP() {b=15;};
    int GetValue() {return (b+a);};
    int Fetch() {return b;};
    
private:
    int b;
    
};

int main()
{
    FFF * p1, *p2, *p3;
    GGG *p4;
    FFF f;
    HHH h;
    MMM m;
    p1 = new GGG;
    p2 = &h;
    p3 = new PPP;
    p4 = new HHH;
    cout << f.GetValue() << '\t' << m.GetValue() << '\n' << p1->GetValue() << '\t' << p2->GetValue() << '\n' << p3->GetValue() << '\n';
    cout << p3->Fetch() << '\t' << p4->Fetch();
}


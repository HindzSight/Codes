#include<iostream>
using namespace std;
class FLOAT
{
    float f;
    public:
    FLOAT(float a=0):f(a){}
    float operator +(FLOAT);
    float operator -(FLOAT);
    float operator *(FLOAT);
    float operator /(FLOAT);
    void Display()
    {
        cout<<"The number after calculation is : "<<f;
    }

};

float FLOAT:: operator +(FLOAT f1)
{
    return (f+f1.f);
}

float FLOAT:: operator -(FLOAT f1)
{
    return (f-f1.f);
}

float FLOAT:: operator *(FLOAT f1)
{
    return (f*f1.f);
}

float FLOAT:: operator /(FLOAT f1)
{
    return (f/f1.f);
}

int main()
{
    FLOAT n1(5.5),n2(10.5),n3;
    n3=n1/n2;
    n3.Display();
    
}
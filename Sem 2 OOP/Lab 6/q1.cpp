#include<iostream>
using namespace std;
class Distance
{
    int feet,inches;
    public:
        Distance():feet(0),inches(0){}
        Distance(int a,int b)
        {
            if(b>=12)
            {
            feet++;
            inches=(b%12);
            }
            else
            inches=b;
            feet=a;
        }
        Distance operator +(Distance D)
        {
            if((inches+D.inches)>=12)
            {
                feet=feet+1;
                inches=(inches+D.inches)%12;
            }
            else
            inches=inches+D.inches;
            feet=feet+D.feet;
            return *this;
        }
        Distance operator -(Distance D)
        {
            inches=inches-D.inches;
            feet=feet-D.feet;
            return *this;
        }

        void out() const
        {
            cout<<"The Distance is "<<feet<<" ft "<<inches<<" in !"<<endl;
        }
};

int main()
{
    Distance D1(5,10),D2(6,2);
    Distance D3;
    D1.out();
    D2.out();
    D3=D1-D2;
    D3.out();
}

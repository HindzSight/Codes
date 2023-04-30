#include<iostream>
using namespace std;
class Demo
{
    int x,y;
    public:
        Demo(int a,int b):x(a),y(b){}
        int operator >(Demo&);
        void display();
    
};

int Demo::operator >(Demo& ob)
{
    if (ob.x>x || (ob.x>x && ob.y>y) )
    {
        cout<<"1";
        return 1; 
    }
    else
    cout<<"0";
    return 0;   
}
int main()
{
    Demo ob1(10,20), ob2(11,21);
    ob1>ob2;
}
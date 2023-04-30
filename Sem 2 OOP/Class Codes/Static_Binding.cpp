#include<iostream>
using namespace std;

class Parent
{
    public:
        void display(){cout<<"Parent Display"<<endl;}
};
class Child : public Parent
{
    public:
        void display(){cout<<"Child Display"<<endl;}
};
int main()
{
    Parent p, *pp;
    Child c, *cp;
    pp = &p;
    pp->display();
    cp = &c;
    cp->display();
    pp = &c;
    pp->display();
    // pp->display();
    // cp->display();
    return 0;
}

/* :::::: NOTES ::::::
1. Output of 18 to 23 will be 
Parent Display
Child Display
Parent Display
2.Line 24 and 25 without any address storing gives output
Parent Display
Child Display
*/
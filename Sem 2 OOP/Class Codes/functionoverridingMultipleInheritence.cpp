#include<iostream>
using namespace std;
class Base1
{
    public:
        void display(){cout<<"Base1 Display"<<endl;}
        
};
class Base2
{
    public:
        void display(){cout<<"Base2 Display"<<endl;}
        
};
class Child: public Base1,Base2
{
    public:
        void display(){Base1::display();Base2::display();cout<<"Child Display"<<endl;}      
};

int main()
{
    Child c;
    c.display();
    return 0;
}

/*
1.In case of Multiple inheritence we will use scope resolution inside child display() to call base1 and base2 display()
We get
Base1 Display
Base2 Display
Child Display

*/
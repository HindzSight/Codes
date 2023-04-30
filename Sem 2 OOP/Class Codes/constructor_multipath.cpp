#include<iostream>
using namespace std;
class Base1
{
    public:
        Base1(){cout<<"Base 1 Constructor"<<endl;}
        
};
class Base2
{
    public:
        Base2(){cout<<"Base 2 Constructor"<<endl;}
        
};
class Child: public Base2,public virtual Base1
{
    public:
        Child(){cout<<"Child Constructor"<<endl;}      
};

int main()
{
    Child c;
    return 0;
}

/*
When we use virtual inheritence the constructor of that class will be called first see line 15 
even if we declare it later
*/
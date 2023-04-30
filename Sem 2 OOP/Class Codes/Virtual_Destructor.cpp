#include<iostream>
using namespace std;

class A
{
    public:
        A(){cout<<"A constructor "<<endl;}
        ~A(){cout<<"A destructor"<<endl;} // To prevent memory leak we create this destructor Virtual !
};

class B : public A
{
    public:
        B(){cout<<"B constructor "<<endl;}
        ~B(){cout<<"B destructor"<<endl;}
};

int main()
{   
    A a;             // A cons A Des
    B b;             // A cons B cons B des A des
    A *ap = new A(); // With delete ap gives A cons A des
    delete ap;       // A des
    A *ap = new B(); // With delete ap A cons B cons A des
    B *bp = new B(); // With delete bp gives A cons B cons B des A des
    delete bp;       // B des
    return 0;
}

/*::::::: NOTES :::::::
1.In C++ constructor cannot be virtual but destructor can be made Virtual of the Base class !
2.In case of delete bp will only call the Base class destructor which is undesirable as then, the object
of Derieved class remains undestructed, because its destructor os never called Which results in memory leak !
Solution : To destroy the object of derieved class the destructor of parent class should be declared as VIRTUAL !
then if virtual output wil be
A *ap= new B();
delete ap
A constructor 
B constructor
B destructor
A destructor


*/
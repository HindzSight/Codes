#include<iostream>
using namespace std;
class Super
{
    protected:
        int a ;
    // public:
        // void display(){cout<<"Super display";}
};

class Base1: public virtual Super
{
    // public:
        // void display(){cout<<"Base1 Display"<<endl;}
};

class Base2: virtual public Super
{
    // public:
        // void display(){cout<<"Base2 Display"<<endl;}
};

class Child: public Base1,public Base2
{
    public:
        void get(){cin>>a;}
        void put(){cout<<a;}
    // public:
        // void display(){Super::display();cout<<"Child Display"<<endl;}      
};

int main()
{
    Child c;
    // c.display();
    c.get();
    c.put();
    return 0;
}

/*
1.Having duplicate set of members when inheriting from single base class
arises when multiple and hierarchy inheritence (Multipath Inheritence)
2.Ambiguity Error for display() function
3.Solution is VIRTUAL INHERITENCE
4.Using virtual we get only one copy of display() funtion of parent class in child class
Now we get 
Super Display
5.Virtually inheritence in base1 and base2
6.Only one copy of data members and data function in child class from parent. 
If not error will be Reference to a is ambiguous!
7.Compiler will create a VIRTUAL TABLE !(Runtime Polymorphism)

*/
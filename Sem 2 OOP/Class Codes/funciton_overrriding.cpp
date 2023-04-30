#include<iostream>
using namespace std;
class Parent
{
    public:
        void display(){cout<<"Parent Display"<<endl;}
        void display(int a ){cout<<"Parent Parameterized Display"<<endl;}
};

class Child: public Parent
{
    public:
        void display(){cout<<"Child Display"<<endl;}
        void display(int a){cout<<"Child Overloaded overridden Display"<<endl;} 
        //void display(){display();cout<<"Child Display"<<endl;}  // Error D1 infinite recursion
};

int main()
{
    Child c;
    c.display(3); //1
    c.Parent::display(3); //2
    return 0;
}

/*
Function Overridding
1.When using only parent inside display() function of child we get error leading to infinite recursion 
2.To fix this we either use Scope resolution inside display() of child like Parent::display() or we use the same in main 
as c.Parent::display()[ D1 error ]
3. When using 1 and 2 at same time we get
 Child Display
 Parent display
4.We can override an overloaded function
When using 1 and 2 at same time we get
 Child overloaded overriden Display
 Parent Parameterized display
5.We can call public function of parent class using object of child class

*/
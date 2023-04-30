//Multiple Inheritence
#include<iostream>
using namespace std;
class Base1
{   
    protected:
        int x,y;
    public:
         Base1(){cout<<"Base 1 Default "<<endl;}  //1.1
         Base1(int a,int b):x(a),y(b){cout<<"Base 1 parameterized "<<endl;}  //1.2
        // ~Base(){cout<<"Base Destructor "<<endl;} 
};

class Base2
{   
    protected:
        int p,q;
    public:
         Base2(){cout<<"Base 2 Default "<<endl;}  //2.1
         Base2(int a,int b):p(a),q(b){cout<<"Base 2 parameterized "<<endl;}  //2.2
        // ~Base(){cout<<"Base Destructor "<<endl;} 
};

class Derieved : public Base1,public Base2
{
    protected:
        int a,b;
    public:
         Derieved(){cout<<"Derieved Default "<<endl;}  //3.1
         Derieved(int a ,int b,int c,int d,int e,int f ):Base1(a,b),Base2(c,d),a(e),b(f)  //3.2
         {cout<<"Derieved Parameterized "<<endl;}
         void display()
         {
             cout<<x<<" "<<y<<" "<<p<<" "<<q<<" "<<a<<" "<<b<<endl;
         }  //3.3
        // ~Derieved(){cout<<"Derieved Destructor "<<endl;}
};

int main()
{
    Derieved d(1,2,3,4,5,6); 
    // Derieved d;
    d.display();
    return 0;
}

/*
1.Sequence of heritence (line 20) matters it calls constructors accordingly
if we write base2 first and base1 afterwards we will get :
Base 2 Default
Base 1 Default 
Derieved Default 
2.To initialize all data members of parent class x y p q a b call explicitly all constructor 
in Derieved Class parameterized constructors 
In line 30 We pass 6 arguments in Derieved class Object
3.We will need only one display function in derieved class to display all data members 
as all will be inheroted in Class Derieved 
4.We need to use initializer list in parameterized constructor of Base1 and Base2 class.
*/
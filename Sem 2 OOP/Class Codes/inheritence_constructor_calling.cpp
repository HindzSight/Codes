#include<iostream>
using namespace std;
class Base
{   
    public:
        //  Base(){cout<<"Base Default "<<endl;}  //1
         Base(int a){cout<<"Base parameterized "<<endl;}  //2
        // ~Base(){cout<<"Base Destructor "<<endl;} 
};

class Derieved : public Base
{
    public:
         Derieved(){cout<<"Derieved Default "<<endl;}  //3
         Derieved(int a ):Base(a){cout<<"Derieved Parameterized "<<endl;}  //4
        // ~Derieved(){cout<<"Derieved Destructor "<<endl;}
};

int main()
{
    Derieved d(2); 
    return 0;
}
/*Notes

1.When Constructor of base class is defined and object of derieved class is created it calls the constructor of base class
Here no constructor of Derieved class is defined 
2.First base class Constructor will be called In case of destructors Derieved will be called first then base will be called
3.If we comment base default constructor we will get erro as no default constructor is present.
also derieved parameterized is called and it will search for default in base
4.We need to explicitly call base class contructor without making object of Base using parameterized constructor of Derieved Class

When 2 3 are commented we get :
Base Default 
Derieved Parameterized

When 1 2 3 are commented we get :
Derieved parameterized 
as compiler adds its own default constructor in base class

When 1 3 are commented we get : 
Error No default constructor of parent class found.(Compiler will not add its own default constructor in base 
cause whrn we define parameterized constructor we have to explicitly add default constructot)

When 1 is commented we get :
Derireved default searches for Base Default Screenshot add;;

*/
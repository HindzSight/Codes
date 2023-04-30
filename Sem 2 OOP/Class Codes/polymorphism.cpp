#include<iostream>
using namespace std;

class Demo
{
    public:
        int x;
        void display(){cout<<"Display"<<endl;}
};

class child : public Demo
{
    public:
        int y;
        void show(){cout<<"Show"<<endl;}
};
int main()
{
    Demo ob;
    child c;
    Demo *ptr=&ob;
    child *cp=&c;
    cout<<ptr->x<<endl;
    ptr->display();
    cout<<cp->y<<endl;
    cp->show();
    cout<<((Demo*)cp)->y; // Typcasting Child class pointer to parent class pointer  Accessing child class member is not allowed
    ((Demo*)cp)->show();  // Error from this statement|| with pointer of parent class
    cout<<((Demo*)cp)->x; // Typcasting Child class pointer to parent class pointer No Error
    ((Demo*)cp)->display();// No Error
    cout<<((child*)ptr)->y;// No Error 
    ((child*)ptr)->show();//  No Error
    cout<<((child*)ptr)->x;     //These line 33 and 34 is allowed and can access data member and function of both 
    ((child*)ptr)->display();   //class upcated to and class upcasted from.  |/!/|
    ptr = &c;  // Upcasting !!! ALLOWED !!!
    // cp  = &ob; // Downcasting !!! NOT ALLOWED !!!
    // cout<<ptr->y<<endl; // Error line 37 and 38
    // ptr->show(); //        Error line 37 and 38
    return 0;
}

/*::::::::: NOTES ::::::::::
1.Example of compile time polymorphism!
2.Upcasting : Assigning the address of child class object to a pointer of Parent class and vice versa called downcasting
3.Upcasting is allowed and downcasting is not allowed.
4.In case of compile time polymorphism ptr can't access y and show()
the content doesn't matter the type matters 
ptr is of type Demo(parent class).
Can't access child class data memeber and functions.
5.If content of pointer matters then it is known is Run time polymorphism.
6.Can convert child class pointer to parent class but then can only access data members of parent class or class upcasted to.
7.Line 27 and 28 will give error Point 6!
8.Type casting of pointer is allowed both ways but assigning address of object are not allowed.
*/
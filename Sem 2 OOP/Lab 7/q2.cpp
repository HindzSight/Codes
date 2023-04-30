#include<iostream>
using namespace std;
class Student 
{
    protected:
        string school;
        string Degree;
    public:
        void get()
        {      
            cout<<"Enter School Details School and Degree : ";
            getline(cin,school);
            getline(cin,Degree);
        }
        void display()
        {
            cout<<"School : "<<school<<endl;
            cout<<"Degree : "<<Degree<<endl;
        }
};

class Employee : protected Student
{
    protected:
        string Name;
        int Emp_no;
    public:
        void setE()
        {
            get();
            cout<<"Enter Name and Employee No : ";
            getline(cin,Name);
            cin>>Emp_no;
        }
        void displayE()
        {
            display();
            cout<<"Name : "<< Name <<endl;
            cout<<"Employee Number : "<<Emp_no<<endl;
        }

};

class Manager : protected Employee
{
    protected :
        string Title;
        float dues;
    public:
        void setM()
        {
            get();
            cout<<"Enter Title and Dues : ";
            getline(cin,Title);
            cin>>dues;
        }
        void displayM()
        {
            display();
            cout<<"Title : "<<Title<<endl;
            cout<<"Dues :$"<<dues<<endl;
        }
};

class Scientist : protected Employee
{
    protected:
        int no_publications;
    public:
        void setS()
        {   
            get();
            cout<<"Enter number of publications : ";
            cin>>no_publications;

        }
        void displayS()
        {
            display();
            cout<<"No of publications : "<<no_publications;
        }
    
};

class Laborer : protected Employee
{
    public:
        void setL()
        {
            get();
        }
        void displayL()
        {
            display();
        }
};

int main()
{
    Manager m1;
    m1.setM();
    m1.displayM();
    Scientist s1;
    s1.setS();
    s1.displayS();
    Laborer L1;
    L1.setL();
    L1.displayL();
    return 0;
}
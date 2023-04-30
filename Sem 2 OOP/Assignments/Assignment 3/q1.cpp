#include<iostream>
#include<string.h>
using namespace std;
class Student 
{
    protected:
        int Branch_number;
        string name;
    public:
        Data(int a,string n)
        {
            Branch_number=a;
        }
        void put()
        {
            cout<<"Branch Code : "<<Branch_number<<" Name : "<<name<<endl;
        }
};

class CSE : protected Student
{
    int CSE_sub1,CSE_sub2,CSE_sub3;
    public:
        CSE()
        { cout<<"Enter name : ";
        getline(cin,name);
        Data(1,name);
        }
        void get_dataCSE()
        {
        cout<<"Enter Marks of Subject 1 : ";
        cin>>CSE_sub1;
        cout<<"Enter Marks of Subject 2 : ";
        cin>>CSE_sub2;
        cout<<"Enter Marks of Subject 3 : ";
        cin>>CSE_sub3;
        }
        void displayCSE()
        {   
            put();
            cout<<"Marks Obtained by "<<name<<" are as follows :"<<endl;
            cout<<"Marks of Subject 1 : "<<CSE_sub1<<endl;
            cout<<"Marks of Subject 2 : "<<CSE_sub2<<endl;
            cout<<"Marks of Subject 3 : "<<CSE_sub3<<endl;
        }
};

class ECE : protected Student
{
    int ECE_sub1,ECE_sub2,ECE_sub3;
    public:
        ECE()
        { 
        getline(cin,name);
        cout<<"Enter name : ";
        Data(2,name);
        }
        void get_dataECE()
        {
        cout<<"Enter Marks of Subject 1 : ";
        cin>>ECE_sub1;
        cout<<"\nEnter Marks of Subject 2 : ";
        cin>>ECE_sub2;
        cout<<"\nEnter Marks of Subject 3 : ";
        cin>>ECE_sub3;
        }
        void displayECE()
        {
            put();
            cout<<"Marks Obtained by "<<name<<" are as follows :"<<endl;
            cout<<"Marks of Subject 1 : "<<ECE_sub1<<endl;
            cout<<"Marks of Subject 2 : "<<ECE_sub2<<endl;
            cout<<"Marks of Subject 3 : "<<ECE_sub3<<endl;
        }
};
int main()
{
    CSE stu1;
    stu1.get_dataCSE();
    stu1.displayCSE();
    CSE stu2;
    stu2.get_dataCSE();
    stu2.displayCSE();
    ECE stu3;
    stu3.get_dataECE();
    stu3.displayECE();
    ECE stu4;
    stu4.get_dataECE();
    stu4.displayECE();
    ECE stu5;
    stu5.get_dataECE();
    stu5.displayECE();
    return 0;
}
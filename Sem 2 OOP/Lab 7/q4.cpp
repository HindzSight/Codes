#include<iostream>
using namespace std;
class staff
{
    protected:
        int code;
        string name;
    public:
        void setstaff()
        {
            cout<<"Enter Name and Code";
            cin>>name>>code;
        }

        void displaystaff()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Code : "<<code<<endl;

        }

};

class teacher : protected staff
{
    protected:
        string sub;
        string publication;
    public:
        void setteacher()
        {
            setstaff();
            cout<<"Enter Subject and Publication";
            cin>>sub>>publication;
        }

        void displayteacher()
        {   
            displaystaff();
            cout<<"Subject     : "<<sub<<endl;
            cout<<"Publication : "<<publication<<endl;

        }
};

class typist : protected staff
{
    protected:
        int speed;
    public:
        void settypist()
        {
            setstaff();
            cout<<"Enter Speed in WPM :";
            cin>>speed;
        }

        void displaytypist()
        {   
            displaystaff();
            cout<<"Speed : "<<speed<<endl;
        }
};

class officer : protected staff
{
    protected:
        char grade;
    public:
        void setofficer()
        {
            setstaff();
            cout<<"Enter grade : ";
            cin>>grade;
        }

        void displayofficer()
        {   
            displaystaff();
            cout<<"Grade : "<<grade<<endl;
        }
};

class regular : protected typist
{

};

class casual : protected typist
{
    protected :
        int dailywage;
    public:
        void setcasual()
        {
            setstaff();
            cout<<"Enter Wage :$";
            cin>>dailywage;
        }

        void displaycasual()
        {   
            displaystaff();
            cout<<"Wage :$"<<dailywage<<endl;
        }
};

int main()
{
    teacher t1;
    t1.setteacher();
    t1.displayteacher();
    regular r1;
    casual c1;
    c1.setcasual();
    c1.displaycasual();
    officer o1;
    o1.setofficer();
    o1.displayofficer();
}
#include<iostream>
using namespace std;
class Student 
{
    protected:
        int roll_no;
        string Name;
    void set()
    {
        cout<<"Enter Roll no and name:";
        cin>>roll_no;
        cin.ignore();
        getline(cin,Name);
    }

};

class Exam : protected Student
{
    protected:
        int s1,s2,s3,s4,s5,s6;
        void entry()
        {
            cout<<"Enter Marks obtained in 6 subjects : ";
            cin>>s1>>s2>>s3>>s4>>s5>>s6;

        }
};

class Result : protected Exam
{
    int total_marks;
    public:
    void setdata()
    {
        set();
        entry();
    }

    void total()
    {
    total_marks=s1+s2+s3+s4+s5+s6;
    cout<<"Total marks obtained by "<<roll_no<<". "<<Name<<" is "<<total_marks; 
    }
};

int main()
{
    Result R1;
    R1.setdata();
    R1.total();
}
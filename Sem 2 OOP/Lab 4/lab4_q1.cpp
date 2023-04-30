#include<iostream>
using namespace std;
class ExamResult
{
    
    int RollNo;
    int subject1,subject2, subject3;
    public:
        void entry();
        void highest();
        void totalmarks();
        void tothighest();
};

void ExamResult :: entry()
{
    cout<<"Enter the Roll No : ";
    cin>>RollNo;
    cout<<"Enter the marks obtained in subject 1 :";
    cin>>subject1;
	cout<<"Enter the marks obtained in subject 2 :";
    cin>>subject2;
    cout<<"Enter the marks obtained in subject 3 :";
    cin>>subject3;
    cout<<endl;
}
    
void ExamResult ::highest()
{   int max=0;
	if(subject1<subject2)
	max=subject2;
	else{
	(subject1>subject2);
	max=subject1;
		}
	if(max<subject3)
	max=subject3;
	cout<<"Highest marks obtained is "<<max<<endl;
}
void ExamResult ::totalmarks()
{
	int total=0;
	total=subject1+subject2+subject3;	
}

//void ExamResult::tothighest()
//{
//	    
//}

int main()
{
	int i;
	ExamResult student[10] ;
	for(i=0;i<10;i++)
	{
	student[i].entry();
	student[i].highest();
	student[i].totalmarks();
	}
}


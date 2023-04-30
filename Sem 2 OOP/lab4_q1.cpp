#include<iostream>
using namespace std;
class ExamResult
{
    
    char RollNo[10];
    int marks[3];
    public:
        void entry();
        void highest();
        void tothighest();
        void totalmarks();
};

void ExamResult :: entry()
{
    int i;
    cout<<"Enter the Roll No : ";
    cin>>RollNo;
    for (i = 0; i < 3; i++)
    {
    cout<<"\n Enter the marks obtained in subject" >>i>> ":";
    cin>>marks[i];
    }
}
    
void ExamResult ::highest()
{   
    int max;
    for(int i=0;i<10;i++)
    {
        for(j=0;j<3;j++)
        max=RollNo[0].marks[0];
        if(max<RollNo[i].marks[j])
        max=RollNo[i].marks[j];
    }
}
void ExamResult ::totalmarks()
{

    int i,total,a[10],j;
    for(i = 0; i < n; i++) 
    {
		total = 0;
		for (j = 0; j < 3; j++) 
        {
			total = total + RollNo[i].marks[j];
		}
		cout<<"Total marks obtained by student "<<RollNo[i]<<"are"<<total;
		a[i] = total;
    }	
}

void ExamResult::tothighest()
{
    int max = 0;
	for (int i = 0; i < n; i++)
    {
		if (max < a[i])
			max = a[i];
	}
}

int main()
{
    ExamResult students[10];
    for(i=0;i<10;i++)
    students[i].entry();
}

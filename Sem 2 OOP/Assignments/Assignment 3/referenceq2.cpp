#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<string, vector<pair<long int, char>>>m;


class student{

	protected:
		string name;
		int marks;
		int t1, t2, t3, p1, p2;
		char grade;
		long int rollno;
	public:
		
		void getGrade(int m)
		{
			if(m>80)
			{
				grade = 'A';
			}
			else if(m>70 && m<=80)
			{
				grade = 'B';
			}
			else if(m>60 && m<=70)
			{
				grade = 'C';
			}
			else if(m>50 && m<=60)
			{
				grade = 'D';
			}
			else{
				grade ='E';
			}
			
		}
		
		void input()
		{
			cout<<"Enter name of student : "<<endl;
			cin>>name;
			cout<<"Enter Roll no : "<<endl;
			cin>>rollno;
			cout<<"Enter marks in T1 : "<<endl;
			cin>>t1;
			cout<<"Enter marks in T2 : "<<endl;
			cin>>t2;
			cout<<"Enter marks in T3 : "<<endl;
			cin>>t3;
			cout<<"Enter marks in P1 : "<<endl;
			cin>>p1;
			cout<<"Enter marks in P2 : "<<endl;
			cin>>p2;
			int sum = (t1+t2+t3+p1+p2)/5;
			marks = sum;
			getGrade(marks);
			m[name].push_back(make_pair(rollno, grade));
		}
		
		void display()
		{
			cout<<"Name of student : "<<name<<endl;
			cout<<"Roll No : "<<rollno<<endl;
			cout<<"Marks obtained : "<<marks<<endl;
			cout<<"Grade : "<<grade<<endl;
		}
	friend bool compareGrade(student,student);
	friend bool compareName(student,student);

		
};


bool compareGrade(student a, student b)
{
	if(a.grade == b.grade)
	{
		return a.name < b.name;
	}
	return a.grade < b.grade;
}


bool compareName(student a, student b)
{
	return a.name < b.name;
}


void searchGrade(string nm)
		{
			bool ans = false;
			for(auto it = m.begin(); it!= m.end(); it++)
			{
				if(it->first == nm)
				{
					ans = true;
					for(int i=0; i < (it->second).size(); i++)
					{
						cout<<"Name of Student : "<<nm<<endl;
						cout<<"Roll No : "<<(it->second)[i].first<<endl;
						cout<<"Grade : "<<(it->second)[i].second<<endl;
						cout<<endl;
					}
				}
			}
			
			if(ans == false)
			{
				cout<<"This name is not found"<<endl;
			}
		}
		
		
int main()
{
	cout<<"Enter no. of students : "<<endl;
	int n;
	cin>>n;
	student s[n];
	
	for(int i=0; i<n; i++)
	{
		s[i].input();
		cout<<endl;
	}
	
	sort(s, s+n, compareGrade);
	cout<<endl<<endl;
	cout<<"Displaying student details in acsending order by Grade"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	for(int i=0; i<n; i++)
	{
		s[i].display();
		cout<<endl;
	}
	sort(s, s+n, compareName);
	cout<<endl<<endl;
	cout<<"Displaying student details in acsending order by Name"<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
	for(int i=0; i<n; i++)
	{
		s[i].display();
		cout<<endl;
	}	


	cout<<endl<<endl;
	cout<<"Enter the name you want to see grade : "<<endl;
	string nm;
	cin>>nm;
	cout<<"Details of asked name : "<<endl;
	cout<<"--------------------------"<<endl;
	searchGrade(nm);
	
	cout<<endl<<endl;
	cout<<"Displaying Student info"<<endl;
	cout<<"----------------------------"<<endl;
	for(int i=0; i<n; i++)
	{
		s[i].display();
		cout<<endl;
	}
}
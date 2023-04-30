//Write C++ Program to swap two variable using reference variables
#include<iostream>
using namespace std;
int swap(int &a,int &b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int a,b;
	int &ref1=a;
	int &ref2=b;
	cout<<"Enter A:";
	cin>>a;
	cout<<"Enter B:";
	cin>>b;
	swap(ref1,ref2);
	cout<<"A:"<<a;
	cout<<"B:"<<b;
}

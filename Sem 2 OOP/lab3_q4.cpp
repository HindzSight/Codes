#include<iostream>
using namespace std;
int addition(int , int , int ,int );
int subtraction(int , int, int, int);
int multiplication(int , int, int, int );
int division(int , int, int, int);
int main()
{
	char ch;
	int a,b,c,d;
	cout<<"enter the value of a,b,c,d"<<endl;
cin>>a>>b>>c>>d;
cout<<"enter the operation you want";
cin>>ch;
if(ch=='+')
    {
	    addition(a,b,c,d);
    }
else if(ch=='-')
    {
	    subtraction(a,b,c,d);
    }
else if(ch=='*')
    {
	    multiplication(a,b,c,d);
    }
else if(ch=='/')
    {
	    division(a,b,c,d);
    }
return 0;
}
int addition( int m, int n, int o, int p)
{
	cout<< (m*p + n*o)<<"/"<<(n*p);
return 0;
}
int subtraction( int m, int n, int o, int p)
{
cout<<(m*p - n*o)<<"/"<< (n*p);
return 0;
}
int multiplication( int m, int n, int o, int p)
{
cout<<(m*o)<<"/"<<(n*p);
return 0;
}
int division( int m, int n, int o, int p)
{
cout<<(m*p)<<"/"<<(n*o);
return 0;
}
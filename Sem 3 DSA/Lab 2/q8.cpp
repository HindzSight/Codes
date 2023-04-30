#include<iostream>
using namespace std;
int fact(int n)
{
if(n==0)
return 1;
else return n*fact(n-1);
}
int main()
{
int n,r;
cout<<"Enter the n and r :";
cin>>n>>r;
cout<<"n C r : "<<((fact(n))/(fact(n-r)*fact(r)));

}
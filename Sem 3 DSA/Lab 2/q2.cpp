#include<iostream>
using namespace std;

int squaresum(int n)
{
    return (((n)*(n+1)*(2*n+1))/6);
}

int main()
{
    int n;
    cout<<"Enter the Number : ";
    cin>>n;
    cout<<"The sum is : "<<squaresum(n);
    return 0;
}
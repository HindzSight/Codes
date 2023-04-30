#include<iostream>
using namespace std;

int fibbo(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else
    return (fibbo(n-1)+fibbo(n-2));
}

int main()
{
    int n,i=0,c;
    cout<<"Enter the Number : ";
    cin>>n;
    for(c=1;c<=n;c++)
    {
        cout<<fibbo(i)<<" ";
        i++;
    }
    return 0;
}
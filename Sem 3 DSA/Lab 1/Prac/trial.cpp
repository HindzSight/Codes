#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int change(int a[],int n)
{
    int i=0;
    while(a[i]<a[i+1])
    {
        i++;
    }
    return ++i;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<change(a,n);
}
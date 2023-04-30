#include<iostream>
#include "rdm.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int* a=rdm(n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
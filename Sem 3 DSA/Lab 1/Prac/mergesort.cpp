#include<bits/stdc++.h>
#include "rdm.h"
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    int size=(r-l+1);
    int temp[size];
    
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    for(int p=l;p<=r;p++)  
    {
        a[p]=temp[p];
    }
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int* arr=rdm(n);
    cout<<"BEFORE SORTING : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);
    cout<<"\nAFTER SORTING : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
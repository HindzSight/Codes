#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
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
	int m=1;
	cout<<"Merge Sort Time Complexity Verification"<<endl;
	while(m==1)
	{
		int n;
		cout<<"Enter the number of elements:";
		cin>>n;
		int a[n];
		for(int k =0 ; k<n;k++)
		{
			a[k]=rand();
		}
		clock_t start= clock();
		mergesort(a,0,n-1);
		clock_t ending=clock();
		cout<<"Time : "<<(ending-start)<<" ms"<<endl;
		cout<<"0-Exit \n1-Redo"<<endl;
		cin>>m;
	}
	return 0;
}

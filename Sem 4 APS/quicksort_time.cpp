#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int split(int a[],int low,int high)
{
    int pivot=a[low];
    int left=low+1;
    int right=high;
    while(left<=right)
    {
        while(left<=right && a[left]<=pivot)
            left=left+1;
        while(a[right]>pivot)
            right=right-1;
        if(left<right)
        {
            int temp=a[right];
            a[right]=a[left];
            a[left]=temp;
        }
    }
    int temp1=a[right];
    a[right]=a[low];
    a[low]=temp1;
    return right;
}

void quick_sort(int a[],int low,int high)
{
    int p=split(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
}

int main()
{
	int m=1;
	cout<<"Quick Sort Time Complexity Verification"<<endl;
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
		quick_sort(a,0,n-1);
		clock_t ending=clock();
		cout<<"Time : "<<(ending-start)<<" ms"<<endl;
		cout<<"0-Exit \n1-Redo"<<endl;
		cin>>m;
	}
	return 0;
}

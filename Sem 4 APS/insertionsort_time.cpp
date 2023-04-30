#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int m=1;
	cout<<"Insertion Sort Time Complexity Verification"<<endl;
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
		/*Write Logic here*/
		for(int i=1;i<n;i++)
    	{
        	int key=a[i];
        	int j=i-1;
        	while(j>=0 && a[j]>key)
        		{
            		a[j+1]=a[j];
            		j--;
        		}
        	a[j+1]=key;
    	}
		clock_t ending=clock();
		cout<<"Time : "<<(ending-start)<<" ms"<<endl;
		cout<<"0-Exit \n1-Redo"<<endl;
		cin>>m;
	}
	return 0;
}

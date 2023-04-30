#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int m=1;
	cout<<"Selection Sort Time Complexity Verification"<<endl;
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
		for(int i=0;i<n-1;i++)
    	{
        	int mini=i;
        	for(int j=i+1;j<n;j++)
        		{
            		if(a[mini]>a[j])
           			mini=j;
       		 	}
        	if(mini!=i)
        	{
            	int temp=a[mini];
            	a[mini]=a[i];
            	a[i]=temp;
        	}
    	}
		clock_t ending=clock();
		cout<<"Time : "<<(ending-start)<<" ms"<<endl;
		cout<<"0-Exit \n1-Redo"<<endl;
		cin>>m;
	}
	return 0;
}

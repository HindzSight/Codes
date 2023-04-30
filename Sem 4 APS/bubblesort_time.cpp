#include<iostream>
#include<time.h>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int m=1;
	cout<<"Bubble Sort Time Complexity Verification"<<endl;
	while(m==1)
	{
		int n;
		cout<<"Enter the number of elements:";
		cin>>n;
		int arr[n];
		for(int k =0 ; k<n;k++)
		{
			arr[k]=rand();
		}
		clock_t start= clock();
		/*Write Logic here*/
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp=arr[j+1];
					arr[j+1]=arr[j];
					arr[j]=temp;
				}
			}
		}
		clock_t ending=clock();
		cout<<"Time : "<<(ending-start)<<" ms"<<endl;
		cout<<"0-Exit \n1-Redo"<<endl;
		cin>>m;
	}
	return 0;
}

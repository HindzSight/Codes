#include<bits/stdc++.h>
using namespace std;

int binaryseach(int arr[],int left,int right,int x)
{
    while(left<=right)
    {
        int mid=left + (right-left)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[10];
    int num,output;
    cout<<"Enter Array in Ascending order : ";
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter number to be searched : ";
    cin>>num;
    output=binaryseach(arr,0,9,num);
    if(output==-1)
    {
        cout<<"Number not in array!"<<endl;
    }
    else
    cout<<"Number found at index : "<<output<<endl;
    return 0;
}
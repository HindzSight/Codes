#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


int main()
{
        int pagesize;
        int n;
        int v_add;
        cout<<"Enter the Virtual address : ";
        cin>>v_add;
        cout<<"Enter the page size (bytes) : ";
        cin>>pagesize;
        cout<<"Enter no of pages:";
        cin>>n;
        int n1=log2(pagesize);
        int n2=log2(n);
        int ans[n1+n2];
        int pagetable[n];
        cout<<"Enter the Page table entries : ";
        for(int i=0;i<n;i++)
        {
                cin>>pagetable[i];
        }

        for(int j=0;j<n1+n2;j++)
    {
        ans[j]=0;
    }
    for(int i=0; v_add>0; i++)
    {
        ans[i]=v_add%2;
        v_add= v_add/2;
    }
//      rvereseArray(ans,0,n1+n2-1);
//    for(int i=0;i<n1+n2;i++)
  //  {
//          cout<<ans[i]<<" ";
  //  }
cout<<endl;


    int offset = 0;
    int place = 1;
    int k;
    for(k=0 ; k<n1 ; k++)
    {
        offset = offset + place*ans[k];
        place = place * 2 ;
    }
    place = 1;
    int frameNo = 0;
    for(k=n1;k<(n2+n1);k++)
    {
        frameNo += place*ans[k];
        place = place*2;
    }

    int padd = pagetable[frameNo]*pagesize + offset;
cout<<"Physical address : "<<padd<<endl;
cout<<"\nFrame:"<<frameNo<<"      Offset:"<<offset<<endl;

return 0;
}

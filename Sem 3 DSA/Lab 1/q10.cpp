#include<iostream>
using namespace std;

int LinearSearch(int a[],int length,int value)
{
    bool flag;
    int i;
    for(i=0;i<length;i++)
    {
        if(a[i]==value)
            {
            flag=true;
            break;
            }
        else
            flag=false;

    }
    if(flag==true)
        return i;
    else
        return -1;
}

int main()
{
   int length,x,ans;
   cout<<"Enter the length :";
   cin>>length;
   int a[length];
   cout<<"Enter the elements :";
   for(int i=0;i<length;i++)
   {
       cin>>a[i];
   }
   cout<<"Enter the element to be searched :";
   cin>>x;
   ans=LinearSearch(a,length,x);
   if(ans==-1)
    cout<<"Element not found!";
   else
    cout<<"Element found at "<<ans<<" Index";
}

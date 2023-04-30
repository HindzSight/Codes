#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp ;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int x,y;
    cout<<"Enter the values of X and Y"<<endl;
    cin>>x>>y;
    swap(x,y);
    cout<<"The swapped values of X and Y are:"<<x<<y;
    return 0;
}

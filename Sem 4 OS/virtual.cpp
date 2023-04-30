#include<iostream>
using namespace std;

int main()
{
    float v_add;
    float base;
    cout<<"Enter the Virtual Address to be relocated(in Bytes):";
    cin>>v_add;
    cout<<"Enter the base Address of the block(in KB) :";
    cin>>base;

    /*
    code 0 to 4 KB
    heap 4KB to 8KB
    stack 16KB to 12KB
    */

    if(v_add > 0 && v_add < 2*1024)
    {
      float offset;
      offset = v_add ;
    if(offset > 2*1024 )
    {
        cout<<"Segmentation fault"<<endl;
    }
    else
    {
        float p_add = base*1024 + offset;
        cout<<"Physical Address : (in B)"<< p_add<<endl;
    }
    }

    else if(v_add > 4*1024 && v_add < 7*1024)
    {
      float offset;
      offset = v_add - 4*1024;
    if(offset > 4*1024 )
    {
        cout<<"Segmentation fault"<<endl;
    }
    else
    {
        float p_add = base*1024 + offset;
        cout<<"Physical Address : (in B)"<< p_add<<endl;
    }
    }

    else if(v_add > 14*1024 && v_add < 16*1024)
    {
      float offset;
      offset = v_add - 16*1024;
    if(offset > 14*1024 )
    {
        cout<<"Segmentation fault"<<endl;
    }
    else
    {
        float p_add = base*1024 + offset;
        cout<<"Physical Address : (in B)"<< p_add<<endl;
    }
    }
    else
    {
        cout<<"Segmentation Fault"<<endl;
    }

    return 0;
}

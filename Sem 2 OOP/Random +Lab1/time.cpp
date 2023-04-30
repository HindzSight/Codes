#include<iostream>
using namespace std;
struct time{
    int hour,min,sec;
}t1,t2,t3;
int main()
{   t3.hour=t3.min=t3.hour=0;
     cout<<"Enter time 1:"<<endl;
     cout<<"Enter seconds"<<endl;
     cin>>t1.sec;
     cout<<"Enter min"<<endl;
     cin>>t1.min;
     cout<<"Enter hour"<<endl;
     cin>>t1.hour;
     cout<<"Enter time 2:"<<endl;
     cout<<"Enter seconds"<<endl;
     cin>>t2.sec;
     cout<<"Enter min"<<endl;
     cin>>t2.min;
     cout<<"Enter hour"<<endl;
     cin>>t2.hour;
     cout<<"The entered time 1 is  "<<t2.hour<<":"<<t2.min<<":"<<t2.sec<<endl;
     cout<<"The entered time 2 is  "<<t1.hour<<":"<<t1.min<<":"<<t1.sec<<endl;
     if((t1.sec+t2.sec)>60)
     {
         t3.sec=((t1.sec+t2.sec)%60);
         t3.min=t3.min+1;
        }
        else
        {
            t3.sec=t1.sec+t2.sec;
        }
        if((t1.min+t2.min)>60)
        {
            t3.min=(((t2.min+t1.min)%60)+t3.min);
            t3.hour=t3.hour+1;
        }
        else
        {
            t3.min=t1.min+t2.min+t3.min;
        }
        t3.hour=(t1.hour+t2.hour+t3.hour);
        cout<<"The added time is  "<<t3.hour<<":"<<t3.min<<":"<<t3.sec;
    return 0;
    }
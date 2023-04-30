#include<iostream>
using namespace std;
class Time 
{
        int hours , minutes , seconds;
    public:
        Time()
        {
            hours=0;
            minutes=0;
            seconds=0;
        }
        Time(int h,int m,int s):hours(h),minutes(m),seconds(s){}
        void display() const;
        Time operator +(Time);
};

void Time::display() const
{
    cout<<"Time : "<<hours<<":"<<minutes<<":"<<seconds<<endl;

}

Time Time::operator+(Time t)
{
    int tmp=0;
        seconds = t.seconds + seconds;
         if(seconds > 59){
            seconds = seconds-60;
            tmp++;
       }  
       minutes = t.minutes + minutes+tmp;
       tmp=0;
       if(minutes > 59){
          minutes-=60;
          tmp++;
       }
          hours = t.hours + hours+tmp;
       if(hours >= 24)
          hours-=24;
          return *this;
 
}

int main()
{
    Time t1(2,30,12),t2(20,53,52),t3;
    t1.display();
    t2.display();
    t3=t1+t2;
    t3.display();
    return 0;
}
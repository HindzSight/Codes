#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void show(){cout<<"In Base"<<endl;}
};
class der1 : public Base
{
    public:
        void show(){cout<<"In Derived 1"<<endl;}
};
class der2 : public Base
{
    public:
        void show(){cout<<"In Derived 2"<<endl;}
};
int main()
{
    Base *bp;
    Base bo;
    der1 do1;
    der2 do2;
    bp=&bo;
    bp->show();
    bp=&do1;
    bp->show();
    bp=&do2;
    bp->show();
    return 0;
}
/*:::::: NOTES ::::::

1.To do binding according to content of pointer we need Virtual Functions called Runtime Binding /Late Binding
2.Since binding was delayed the content of Pointer matters therefore Output will be  
In Base
In Derieved 1
In Derieved 2
3.By making a function virtual of base class the compiler delays binding till RUNTIME
4.Derieved class funtion need derieved class pointer to call them can't call them using base class pointer /|!|/ 

*/
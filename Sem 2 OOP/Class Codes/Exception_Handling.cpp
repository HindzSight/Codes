#include<iostream>
using namespace std;
void fun(int a,int b)
{
    if(b==0) throw 'e';
    cout<<a/b<<endl;
}
int main()
{
    try
    {
        fun(10,0);
        fun(10,10);
    }
    catch(char a)
    {
        cout<<"Division by zero error ocurred !"<<endl;
    }
    cout<<"Hello!"<<endl;
    return 0;
}

/*
1.Runtime generated is handled using TRY CATCH THROW blocks.
2.Once control is transferred to catch block it can not return to try block.
3. When executing 
 fun(10,0);
 fun(10,10);
 we get 
 Division by zero error ocurred !
 Hello 
4. When executing 
f(10,10);
f(10,0);
 1
 we get Division by zero error ocurred !
 Hello
5.Data type of value thrown must be same as catch block argument to execute catch block.
6.Catch statement with ellipses catch(...) should come at last in multiple catches.
7.
*/
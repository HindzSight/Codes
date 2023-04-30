#include<iostream>
using namespace std;

class A
{
    public:
        void f(){cout<<"A::f()"<<endl;}
        virtual void g(){cout<<"A::g()"<<endl;}
        void h(){cout<<"A::h()"<<endl;}
};

class B : public A
{
    public:
        void f(){cout<<"B::f()"<<endl;}
        void g(){cout<<"B::g()"<<endl;}
        virtual void h(){cout<<"B::h()"<<endl;}
};

class C : public B
{
    public:
        void f(){cout<<"C::f()"<<endl;}
        void g(){cout<<"C::g()"<<endl;}
        void h(){cout<<"C::h()"<<endl;}
};

int main()
{
    B *q= new c;
    A *p=q;


}
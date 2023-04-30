#include<iostream>
#include<cstdlib>
using namespace std;
class Complex
{
	int real,img;
	public:
		void complexSum(Complex&,Complex&);
		Complex();
		Complex(int);
		Complex(int,int);
		void display();
};

Complex::Complex()
{
	real=0;
	img=0;
}

Complex::Complex(int temp)
{
	real=temp;
	img=temp;
}

Complex::Complex(int r,int i)
{
	real=r;
	img=i;
}

void Complex::complexSum(Complex& ob1,Complex& ob2)
{
	real=ob1.real+ob2.real;
	img=ob1.img+ob2.img;
}

void Complex::display()
{
	cout<<"\nComplex Number : "<<real;
	if(img>0)
	cout<<"+i";
	else
	cout<<"-i";
	cout<<abs(img);
}

int main()
{
	Complex c1;
	Complex c2(10);
	Complex c3(5,-7);
	c1.display();
	c2.display();
	c3.display();
	c1.complexSum(c2,c3);
	c1.display();
	return 0;
}

#include<iostream>
using namespace std;
class Shape
{
	protected:
		double l1,l2;
	public:
		void get_data(double a,double b=0)
		{
			l1=a;
			l2=b;
		}
		virtual void display_area()=0;
//		{
//			cout<<"Shape Display called(Wasn't Expecting This!)"<<endl;
//		}
};

class Triangle : public Shape
{
	public:
		void display_area()
		{
			cout<<"The area of Triangle  : "<<(0.5*l1*l2)<<" units."<<endl;
		}	
};

class Rectangle : public Shape
{
	public:
		void display_area()
		{
			cout<<"The area of Rectangle : "<<(l1*l2)<<" units."<<endl;
		}	
};

class Cirlce : public Shape
{
	public:
		void display_area()
		{
			cout<<"The area of Cirlce    : "<<(3.14*l1*l1)<<" units."<<endl;
		}	
};

int main()
{	
	Shape *rectangle1;
	Shape *triangle1;
	Shape *circle1;
	Triangle t1;
	triangle1 = &t1;
	triangle1->get_data(7.6,10);
	triangle1->display_area();
	Rectangle r1;
	rectangle1 = &r1;
	rectangle1->get_data(5,2.2);
	rectangle1->display_area();
	Cirlce c1;
	circle1 = &c1;
    circle1->get_data(5);
	circle1->display_area();
}

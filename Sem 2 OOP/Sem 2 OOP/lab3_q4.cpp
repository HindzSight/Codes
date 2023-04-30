#include<iostream>
using namespace std;
class rectangle
{
		int l,w,a,p;
	public:
		void perimeter();
		void area();
		void getlw();
		void print();
};
void rectangle::getlw()
{
	int l,w;
	cout<<"Enter lenght of rectangle : ";
	cin>>l;
	cout<<"Enter width of rectangle  : ";
	cin>>w;
}
void rectangle::perimeter()
{
	p=2*(l+w);
}
void rectangle::area()
{
	a=l*w;
}

void rectangle::print()
{	
	cout<<"The area is      : "<<a<<endl;
	cout<<"The perimeter is : "<<p<<endl;
}
int main()
{
	rectangle r;
	r.getlw();
	r.area();
	r.perimeter();
	r.print();
	return 0;
}

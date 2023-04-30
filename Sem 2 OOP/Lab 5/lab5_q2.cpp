#include<iostream>
#define temp 1000
using namespace std;
class Point
{
	int x,y;
	public:
	 	 Point(int,int);
		~Point();
		 void display();
};

Point :: Point(int a,int b)
{
	cout<<"Constructor called"<<endl;
	x=a;
	y=b;
}

Point ::~Point()
{
	cout<<"Destructor Called"<<endl;
}
void Point::display()
{
	cout<<"The x coordinate : "<<x<<endl;
	cout<<"The y coordinate : "<<y<<endl;
}
Point p3(5,4);
class Rectangle
{
	int top_left,bottom_right;
	public:
		 Rectangle(int,int);
		~Rectangle();
		 void display();
};

Rectangle :: Rectangle(int a,int b)
{
	cout<<"Constructor called"<<endl;
	top_left=a;
	bottom_right=b;
}

Rectangle ::~Rectangle()
{
	cout<<"Destructor Called"<<endl;
}
void Rectangle::display()
{
	cout<<"The Top-left coordinate : "<<top_left<<endl;
	cout<<"The Bottom-right coordinate : "<<bottom_right<<endl;
}

Rectangle r3(343,234);
int main()
{
	Point p1(2,4);
	p1.display();
	{
		cout<<"CodeBlock#1"<<endl;
		Point p2(5,1);
		p2.display();
		
	}
	Rectangle r1(45,54);
	r1.display();
	{
		cout<<"CodeBlock#2"<<endl;
		Rectangle r2(23,56);
		r2.display();
	}
	return 0;
}

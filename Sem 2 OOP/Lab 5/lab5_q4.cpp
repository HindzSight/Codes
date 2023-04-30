#include<iostream>
using namespace std;
class Demo
{
	int x,y;
	public:
		Demo();
		Demo(int ,int );
		void display();	
};

Demo::Demo()
{
	x=0;
	y=0;
}

Demo::Demo(int a=10,int b=10)
{
	x=a;
	y=b;
}
void Demo::display()
{
	cout<<"X : "<<x<<endl;
	cout<<"Y : "<<y<<endl;
}
int main()
{
	Demo ob1(420,1337);
	ob1.display();
	Demo ob2;
	ob2.display();
	return 0;
}

#include<iostream>
using namespace std;
class order
{
	static float table_minimum_charge;
	static float mincharge();
	public:
		void getdata();
		int table_number;
		char server[50];
		int patron_number;
		void display();
};
void order::getdata()
{
	cout<<"Enter yout table number : "<<endl;
	cin>>table_number;
	cout<<"Number of patrons : "<<endl;
	cin>>patron_number;
	cout<<"Enter your server's name : ";
	gets(server);
}
float order::table_minimum_charge = 4.75;
float order::mincharge()
{		
	cout<<"Minimum bill is : "<<table_minimum_charge<<endl;
}
/*void order::display()
{
	cout<<"The minimum charge is : "<<table_minimum_charge;
}*/
int main()
{
	cout<<order::mincharge();
}

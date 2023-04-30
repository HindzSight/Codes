#include<iostream>
using namespace std;
class DM;
class DB;
class DM
{
	float meters,centimeters;
	public:
		void mentry();	
		friend DM add(DM&,DB&);
		// friend DB add1(DM&,DB&);
	
		void display();	
};
void DM::display()
{
	cout<<"Meters      :"<<meters<<endl;
	cout<<"Centimeters :"<<centimeters<<endl;
}
class DB
{
	float feets,inches;
	public:
		void fentry();
		friend DM add(DM&,DB&);
		// friend DB add1(DM&,DB&);
	
};
DM add(DM & dm,DB & db)
{
	DM temp;
	temp.meters=dm.meters+(0.3048*db.feets);
	temp.centimeters=dm.centimeters+(2.54*db.inches);
	return temp;
}

// DB add1(DM & dm,DB & db)
// {
// 	DB temp;
// 	temp.feets=db.feets+(3.2808*dm.meters);
// 	temp.inches=db.inches+(0.3937*dm.centimeters);
// 	return temp;
// }
void DM::mentry()
{
	cout<<"Enter in m  : ";
	cin>>meters;
	cout<<"Enter in cm : ";
	cin>>centimeters;

}
void DB::fentry()
{
	cout<<"Enter in f  : ";
	cin>>feets;
	cout<<"Enter in in : ";
	cin>>inches;

}

int main()
{
	DM m,m1;
	DB f,f1;
	m1.mentry();
	f1.fentry();
	m1=add(m,f);
	m1.display();
	// f1=add(m,f);
	return 0;
}

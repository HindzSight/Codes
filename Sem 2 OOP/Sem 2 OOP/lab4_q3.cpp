#include<iostream>
using namespace std;
class DM;
class DB;
DM add(DB&);
class DM
{
	int meters,centimeters;
	float total;
	public:
		void mentry();	
		DM add(DB&);
		friend class DB;	
};

class DB
{
	int feets,inches;
	public:
		void fentry();
		friend DM add(DB&);
	
};

void DM::add(DB& ob) 
{
	meters=30*(ob.feets)+meters;
	centimeters=centimeters+2.5*(ob.inches)	
	cout<<"The Distance is"<<meters<<"and"<<centimeters<<"cm";
}

void DM::mentry()
{
	cout<<"Enter in m";
	cin>>meters;
	cout<<"Enter in cm";
	cin>>centimeters;

}
void DB::fentry()
{
	cout<<"Enter in f";
	cin>>feets;
	cout<<"Enter in in";
	cin>>inches;

}

int main()
{
	DM m1;
	DB f1;
	m1.mentry();
	f1.fentry();
	m1.add(f1);
}

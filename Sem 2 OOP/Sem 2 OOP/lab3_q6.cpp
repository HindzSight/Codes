#include<iostream>
using namespace std;

class shirt
{
	public:
		int collarsize,sleeveLength;
		void displayClothingFacts();
};

class pants
{
	public:
		int waistSize,inSeam;
		void displayClothingFacts();
		
};
void shirt::displayClothingFacts()
{
	cout<<"The collar size is "<<collarsize<<endl;
	cout<<"The Sleeve length is "<<sleeveLength<<endl;
}
void pants::displayClothingFacts()
{
	cout<<"The waist size is "<<waistSize<<endl;
	cout<<"The In seam is "<<inSeam<<endl;
}
int main()
{
	shirt s1;
	pants p1;
	s1.collarsize=42;
	s1.sleeveLength=12;
	p1.waistSize=36;
	p1.inSeam=30;
	s1.displayClothingFacts();
	p1.displayClothingFacts();
}



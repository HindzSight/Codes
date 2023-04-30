#include<iostream>
#include<stdio.h>
using namespace std;

class Movie
{
	char Title[50],Director[50];
	int Year;
	public :
		void display();
		void setTitle();
		void setYear();
		void setDirector();
};
void Movie::setTitle()
{
	cout<<"Enter the title : ";
	gets(Title);
}
void Movie::setDirector()
{
	cout<<"Enter the name of Director : ";
	gets(Director);
}
void Movie::setYear()
{
	cout<<"Enter the Year of release : ";
	cin>>Year;
}
void Movie::display()
{
	cout<<"Title 	: "<<Title<<endl;
	cout<<"Year     : "<<Year<<endl;
	cout<<"Director : "<<Director<<endl;
}
int main()
{
	Movie myFavouriteMovie;
	myFavouriteMovie.setTitle();
	myFavouriteMovie.setDirector();
	myFavouriteMovie.setYear();
	myFavouriteMovie.display();
	return 0;
}


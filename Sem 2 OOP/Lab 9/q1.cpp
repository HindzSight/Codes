#include<iostream>
#include<fstream>
using namespace std;
int main()
{	
	int count=0,words=0;
	char ch;
	ofstream file("TEXT.txt");
	if(file.good())
	cout<<"All G!"<<endl;
	else
	{
		cout<<"Error Occured"<<endl;
		exit(0);
	}
	file<<"Hello File created\n";
	file<<"Second line\n";
	file<<"Third Line\n";
	int position=file.tellp();
	// cout<<"The Position of put Pointer is : "<<position<<endl;
	cout<<"Number of Characters are : "<<((position)/sizeof(char))<<endl;
	file.close();
	ifstream f;
	f.open("TEXT.txt");
	string line;
	while(getline(f,line))
	{
		count++;
	}
	f.seekg(0,ios::beg);
	while(f)
	{
		f.get(ch);
		if(ch==' ' || ch=='\n')
		++words;
	}
	cout<<"Number of Lines are : "<<count<<endl;
	cout<<"Number of Words are : "<<words<<endl; 
	f.close();
	return 0;
}

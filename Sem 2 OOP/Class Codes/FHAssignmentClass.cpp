//Write number into a file from user and then in same file on the next line find sum of digit in next line using file handling;
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream file;
    int N;
    cout<<"Enter A number : ";
    cin>>N;
    file.open("Digit.txt");
    file<<N<<"\n";
    file.close();
    ifstream file1;
    int No;
    file1.open("Digit.txt",ios::in);
    file1>>No;
    cout<<"Number Captured!"<<endl;
    int sum=0;
    while(No != 0)
    {
        sum=sum+(No%10);
        No=No/10;
    }
    cout<<"Check Text File ! "<<endl;
    file1.close();
    file.open("Digit.txt",ios::app);
    file<<sum;
    file.close();
    return 0;
}
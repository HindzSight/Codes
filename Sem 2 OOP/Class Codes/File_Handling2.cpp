#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string L;
    ofstream fout;
    fout.open("country.txt");
    fout<<"Hello World";
    int p= fout.tellp();    
    cout<<p;
    fout.close();
    return 0;

}
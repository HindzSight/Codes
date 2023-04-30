#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string L;
    ofstream fout;
    fout.open("country.txt");
    fout<<"United States of America\n";
    fout<<"United Kingdom\n";
    fout<<"South Korea\n";
    fout.close();
    fout.open("capital.txt");
    fout<<"Washington\n";
    fout<<"London\n";
    fout<<"Seoul\n";
    fout.close();
    ifstream fin;
    fin.open("country.txt");
    while(fin)
    {
        getline(fin,L);
        cout<<L<<endl;
        
    }
    fin.close();
    fin.open("capital.txt");
    while(fin)
    {
        getline(fin,L);
        cout<<L<<endl;
    }

    return 0;

}

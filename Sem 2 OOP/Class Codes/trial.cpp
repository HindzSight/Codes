#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f;
    f.open("trial.txt",ios::app);
    // f<<"Hello World";
    // cout<<f.tellp();
    string L;
    f.seekg(0);
    while(f)
    {
        getline(f,L);
    }
    cout<<L<<endl;
    f.close();
    return 0;
}


//Find special characters in a string using get and put function by reading character by character ?

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f;
    f.open("file.txt",ios::app);
    // f<<"Hello World";
    cout<<f.tellp();
    f.close();
    return 0;
}

/*
Compiler Problem in the reading format 
*/
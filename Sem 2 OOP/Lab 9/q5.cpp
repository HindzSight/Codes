#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char ch;
    fstream fp,ft;
    fp.open("Sample.txt",ios::in);
    ft.open("tmp.txt",ios::out);
    while(fp>>ch)
    {
        ch=ch+25;
        ft<<ch;
    }
    fp.close();
    ft.close();
    fp.open("Sample.txt",ios::out);
    ft.open("tmp.txt",ios::in);
    while(ft>>ch)
    {
        fp<<ch;
    }
    fp.close();
    ft.close();
    cout<<"File Encrypted!";
    return 0;
}
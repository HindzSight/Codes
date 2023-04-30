#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream of1;
    ofstream of2;
    of1.open("imp1.txt");
    of2.open("inf2.txt");
    if (of1.good())
    {
        cout << "first file is created" << endl;
    }
    else
    {
        cout << "first file is not created";
        return 0;
    }
    if (of2.good())
    {
        cout << "second file is created";
    }
    else
    {
        cout << "second file is not created";
        return 0;
    }
    char line1[100];
    cout << endl
         << "input the content in first file:- ";
    cin.getline(line1, 100);
    of1 << line1;
    char line2[100];
    cout << endl
         << "input the content in second file:- ";
    cin.getline(line2, 100);
    of2 << line2;
    of1.close();
    of2.close();
    ifstream if1;
    if1.open("imp1.txt");
    ifstream if2;
    if2.open("inf2.txt");
    ofstream of3;
    of3.open("combine.txt");
    char line3[100];
    if (if1)
    {
        if1.getline(line3, 100);
        of3 << line3;
    }
    char line4[100];
    if (if2)
    {
        if2.getline(line4, 100);
        of3 << line4;
    }
    of3.close();
    if1.close();
    if2.close();
    ifstream file;
    file.open("combine.txt");
    char data[100];
    if (file)
    {
        file.getline(data, 100);
        cout << data;
    }
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream of1;
    of1.open("q2.txt");
    if (of1.good())
    {
        cout << "All G!" << endl;
    }
    else
    {
        cout << "Error Occured!" << endl;
        return 0;
    }
    char line[100];
    cout << "input in file:- ";
    cin.getline(line, 100);
    of1 << line;
    of1.close();
    ifstream if1;
    if1.open("q2.txt");
    char line1[100];
    if1.getline(line1, 100);
    cout << endl<< "output" << endl<< line1;
    return 0;
}

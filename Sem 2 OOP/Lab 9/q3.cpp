#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char l1[100];
    char l2[100];
    ofstream f;
    f.open("mydata.txt");
    if (f.good())
    {
        cout << "File 1 is created" << endl;
    }
    else
    {
        cout << "File 1 is not created" << endl;
        return 0;
    }
    cout << "Input the file content:- ";
    cin.getline(l2, 100);
    f << l2;
    f.close();
    ifstream f1;
    f1.open("mydata.txt");
    if (f1)
    {
        f1.getline(l1, 100);
    }
    f1.close();
    ofstream file;
    file.open("Important.txt");
    if (file.good())
    {
        cout << "Second file is created" << endl;
    }
    else
    {
        cout << "Second file doesnot created" << endl;
        return 0;
    }
    file << l1;
    file.close();
    ifstream file2;
    char line2[100];
    file2.open("Important.txt");
    if (file2)
    {
        file2.getline(line2, 100);
        cout << endl << line2;
    }
    return 0;
}

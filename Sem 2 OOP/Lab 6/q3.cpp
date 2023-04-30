#include <iostream>
#include <string.h>
using namespace std;

class String
{
    char str[20];

public:
    void entry()
    {
        cout << "Enter String                  :   ";
        cin >> str;
    }
    void display()
    {
        cout << str;
    }
    String operator+(String x)
    {
        String s;
        strcat(str, x.str);
        strcpy(s.str, str);
        return s;
    }
};
int main()
{
    String s1, s2, s3;

    s1.entry();
    s2.entry();
    cout << "First String is             :  ";
    s1.display();
    cout << "\nSecond String is          :  ";
    s2.display();
    s3 = s1 + s2;
    cout << "\nConcatenated String is    :  ";
    s3.display();
    return 0;
}
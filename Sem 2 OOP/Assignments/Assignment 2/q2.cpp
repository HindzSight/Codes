#include <iostream>
using namespace std;
int main()
{
    int i, j,length,count = 0;
    string s1,s2;
    cout << "Enter First string  : ";
    cin >> s1;
    cout << "Enter Second String : ";
    cin >> s2;
    length=s1.length();
    for (i = 0; i < length; i++)
    {   
        if (s1[0] == s2[i])
        {
            for (j = 0; j < length; j++)
                if (s1[j] == s2[(i + j)%length])
                {
                    count++;
                }
        }
    }
    if (count == length)
        cout << "TRUE";
    else
        cout << "FALSE";
}
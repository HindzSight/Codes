#include <iostream>
using namespace std;
void Concatenate()
{
    char str1[50], str2[50];
    char * s1 = str1;
    char * s2 = str2;
    cout<<"Enter 1st string: ";
    cin>>str1;
    cout<<"Enter 2nd string: ";
    cin>>str2;
    while(*(++s1));
    while(*(s1++) = *(s2++));
    cout<<"Concatenated string:"<<str1;
}
int main()
{
    Concatenate();
return 0;
}
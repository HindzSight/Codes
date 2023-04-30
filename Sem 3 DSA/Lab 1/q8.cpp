#include <bits/stdc++.h>
using namespace std;

bool isWordPresent(string sentence, string word)
{

    stringstream s(sentence);
    string temp;
    while (s >> temp) {


        if (temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}
 
int main()
{
    string s,word;
    cout<<"Enter the string:";
    getline(cin,s);
    cout<<"Enter the word to be searched :";
    getline(cin,word);
    if (isWordPresent(s, word))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
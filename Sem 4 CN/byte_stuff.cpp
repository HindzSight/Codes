#include <iostream>
#include<bits/stdc++.h>
#include <string>

using namespace std;

string byteStuffing(string s) {
    const char escByte = 'E';
    const char flagByte = 'F';
    string stuffedString = "";
    for (char c : s) {
        if (c == escByte || c == flagByte) {
            stuffedString += escByte;
        }
        stuffedString += c;
    }
    return stuffedString;
}

string byteDestuffing(string s) {
    const char escByte = 'E';
    const char flagByte = 'F';
    string destuffedString;
    bool escaped = false;
    for (char c : s) {
        if (escaped) {
            destuffedString += c ^ 0x20;
            escaped = false;
        } else if (c == escByte) {
            escaped = true;
        } else {
            destuffedString += c;
        }
    }
    return destuffedString;
}

int main() {
    string s = "DDEDFFDE";
    string stuffed = byteStuffing(s);
    string destuffed = byteDestuffing(s);
    cout << "Original string: " << s << endl;
    cout << "Byte-stuffed string: " << stuffed << endl;
    cout << "Byte-destuffed string: " << destuffed << endl;
    return 0;
}

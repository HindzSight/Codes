#include<bits/stdc++.h>

using namespace std;

int main() {
    int w;
    cin >> w;
    while (w--) {
        string t = "";
        cin>>t;
        int temp = t[0] - '0';
        int arr[10] ;
        arr[1] = 13;arr[2] = 23;arr[3] = 31;arr[4] = 41;arr[5] = 53; arr[6] = 67;arr[7] = 73;arr[8] = 83;arr[9] = 97;
        cout<<arr[temp]<<endl; 
        }
    return 0;
}

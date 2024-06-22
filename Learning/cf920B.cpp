#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string f;
        cin >> f;
        int ans = 0;
        int count1 = 0,count2 = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( (s[i] ^ f[i]) == 1 ){
                ++ans;
                if( s[i] == '1' ) ++count1;
                if( f[i] == '1' ) ++count2;
            }
        }
        if( count1 > count2 ){
            ans = count1;
        }
        else{
            ans = count2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

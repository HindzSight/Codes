#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = "#" + s + "#";

        int ans = 0;
        int f = 0;

        for(int i = 1 ; i < n + 1 ; i++)
        {
            if(s[i] == '.'){
                if( s[i - 1] == '.' && s[i + 1] == '.') {
                    cout << 2 << endl;
                    f = 1;
                    break;
                }else{
                    // s[i] = '#';
                    ans += 1;
                }
            }
        }
        if(!f) cout << ans << endl;
    }
    return 0;
}

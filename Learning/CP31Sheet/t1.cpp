#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,q;
        string s;
        cin >> n >> q >> s;
        int curr = 1;
        int ans = 1;
        for(int i = 1 ; i < n ;i++){
            if(s[i] == s[i - 1]){
                curr++;
                ans = max(ans,curr);
            }else{
                curr = 1;
            }
        }
        cout << ans << " ";
        for(int i = n ; i < (n + q) ; i++){
            char c;
            cin >> c;
            s += c;
            if(s[i] == s[i - 1]){
                curr++;
                ans = max(curr,ans);
            }else{
                curr = 1;
            }
            cout << ans << " ";
        }
        cout << endl;
        
    }
    return 0;
}

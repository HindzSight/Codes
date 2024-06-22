#include <bits/stdc++.h>

using namespace std;

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    int n;
    cin >> n;
    int ans = 1000000;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a = abs(a);
        ans = min(ans,a);
        
    }
    cout << ans << endl;
    // }
    return 0;
}

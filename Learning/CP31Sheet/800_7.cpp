#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin >> n >> k;
        bool ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if( a == k ) ans = 1;
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}

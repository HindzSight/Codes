#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r1,r2,r3,r4,r5;
        cin >> r1 >> r2 >> r3 >> r4 >> r5;
        int s = r1 + r2 + r3 + r4 + r5;
        if(s>= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

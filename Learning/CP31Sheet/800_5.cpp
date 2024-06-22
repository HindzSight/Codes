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
        int arr[n];
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        sort(arr,arr+n);

        if(s.size() > 2) cout << "No" << endl;
        else if(s.size() == 1) cout << "Yes" << endl;
        else{
            int cnt1 = 0, cnt2 = 0;
            for(int i = 0 ; i < n; i++){
                if(arr[i] == arr[0]) cnt1++;
                if(arr[i] == arr[n-1]) cnt2++;
            }
            if(cnt1 == cnt2 || abs(cnt1-cnt2) == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    
    }
    return 0;
}

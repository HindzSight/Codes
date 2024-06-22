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
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(int i = 0; i < n; i++){
            if(arr[i] >= k){
                arr[i] = arr[i] % k;
            }
            else{
                arr[i] = -1;
            }
        }

        int ans = 0;
        int ansr = INT_MAX;
        for(int i = 0; i < n; i++){
            if(arr[i] == -1) ans++;
            else{
                ansr = min(ansr,arr[i]);
            }
        }
        if(ans == n) cout << -1 << endl;
        else{
            cout << ansr <<endl;
        }
    }
    return 0;
}

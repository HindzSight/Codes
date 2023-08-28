#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> ini(n);
        for(int i = 0 ; i < n ; i++) cin>>ini[i];
        vector<int> temp;
        for(int i = 0 ; i < n - 1 ; i++) temp.push_back(ini[i] - ini[i+1]);
        temp.push_back(ini[n-1]);
        // for(int x : temp) cout<<x<<" ";
        // cout<<endl;
        vector<int> ans;
        int cnt = 1;
        for(int x : temp){
            while(x > 0){
                ans.push_back(cnt);
                x--;
            }
            cnt++;
        }
        reverse(ans.begin(),ans.end());
        if(ans == ini) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

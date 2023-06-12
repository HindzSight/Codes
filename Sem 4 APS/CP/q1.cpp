#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t,n;
    string s;
    cin>>t;
    // cout<<"T"<<endl;
    while(t>0){
        cin>>n;
        // cout<<"N"<<endl;
        set<string> ans;
        cin>>s;
        // cout<<"S"<<endl;
        for(int i = 1 ; i < n ; i++){
            string s1 = "" ;
            // cout<<"LOL"<<endl;
            s1 = s.substr(i-1, 2);
            // cout<<s1;
            ans.insert(s1);

        }
        // for(auto& i : ans) cout<<i<<" ";
        cout<<ans.size()<<endl;
        t--;
    }
    return 0;
}
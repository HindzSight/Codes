/*CountAndSay -- https://leetcode.com/problems/count-and-say/ */

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> counter(string ans){
    vector<pair<int,int>> cval;
    int n = ans.length();
    int i = 0;
    while( i < n )
    {
        int count = 1;
        int j = i + 1;
        while(ans[j] == ans[j-1] && j < n)
        {
            count++;
            j++;
        }
        cval.push_back(make_pair(count,int(ans[i])-48));
        i = i + count;
    }
    return cval;    
}

string tostr(vector<pair<int,int>> cval){
    string ans = ""; 
    vector<pair<int,int>>::iterator itr;
    for(itr = cval.begin(); itr != cval.end(); itr++){
        ans += to_string(itr->first) + to_string(itr->second);
    }
    return ans;
}

string countAndSay(int n){
    string ans = "1";
    string ans2= "";
    if(n > 1) {
        for(int i = 0 ; i < n - 1; i++)
        {
            ans2 = tostr(counter(ans));
            ans = ans2;
        }
        return ans2;
    }
    return ans;
        
}
    /*string ans = "1";
    ans = tostr(counter(ans));
    if(n > 1) {
        return countAndSay(n-1);
    }
    else
        return "1";
        */


int main()
{
    // string ans = "11";
    // cout<<tostr(counter(ans));
    cout<<countAndSay(4);
    return 0;
}
    // vector<pair<int,int>> check = counter(ans);
    // vector<pair<int,int>>::iterator itr;
    // for(itr = check.begin(); itr != check.end(); itr++){
    //     cout<<"["<<itr->first<<","<<itr->second<<"]"<<endl;
    // }

    // vector<pair<int,int>> cval = {{2,2},{3,2},{1,1},{4,5},{1,2}};
    // cout<<tostr(cval);

/*
1 - 1
4 - 1211
20 - ?

1 <= n <= 30

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

*/
/*

Using hash

class Solution {
public:
    string conv(string s){
        int size = s.size(), cnt = 1;
        string ans = "";

        for(int i = 1; i < size; i++){
            if(s[i] == s[i - 1]) cnt++;
            else{
                ans.push_back(48 + cnt);
                cnt = 1;
                ans.push_back(s[i - 1]);
            }
        }

        ans.push_back(48 + cnt);
        ans.push_back(s[size - 1]);

        return ans;
    }

    string countAndSay(int n) {
        vector<string> hash(31);
        hash[1] = "1";

        for(int i = 2; i < 31; i++){
            hash[i] = conv(hash[i - 1]);
        }

        return hash[n];
    }
};

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> memo;

int countB(string s, int n) {
    if (n == 0)
        return 0;
    
    if (memo.count(s))
        return memo[s];
    
    int ans = 1;
    int curr_max = 1;
    char last_char = s[0];

    for (int i = 1; i < n; i++) {
        if (s[i] == last_char) {
            ans++;
        } else {
            last_char = s[i];
            ans = 1;
        }
        curr_max = max(curr_max, ans);
    }
    
    memo[s] = curr_max;
    return curr_max;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        
        int max_beautifulness = countB(s, n);
        cout << max_beautifulness << " ";
        
        for (int i = 0; i < q; i++) {
            char c;
            cin >> c;
            s += c;
            
            if (c == s[s.length() - 2]) {
                max_beautifulness++;
            }
            
            cout << max_beautifulness << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
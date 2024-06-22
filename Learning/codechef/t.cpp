#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to update streak based on current character
int updateStreak(int currentStreak, char prevChar, char currentChar) {
    if (prevChar == currentChar) {
        return currentStreak + 1;
    } else {
        return 1;
    }
}

// Find the longest beautiful substrings for a given string and queries
vector<int> findLongestBeautifulSubstrings(string s, const vector<string>& queries) {
    vector<int> results;

    // Calculate longest substring in original string
    int currentStreak = 1;
    int longestBeautifulSubstring = 1;
    for (int i = 1; i < s.length(); ++i) {
        currentStreak = updateStreak(currentStreak, s[i - 1], s[i]);
        longestBeautifulSubstring = max(longestBeautifulSubstring, currentStreak);
    }
    results.push_back(longestBeautifulSubstring);

    // Update longest substring for each query
    for (const string& query : queries) {
        s += query;
        currentStreak = updateStreak(currentStreak, s[s.length() - 2], s.back());
        longestBeautifulSubstring = max(longestBeautifulSubstring, currentStreak);
        results.push_back(longestBeautifulSubstring);
    }

    return results;
}

int main() {
    // Input
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<string> queries(q);
        for (int j = 0; j < q; ++j) {
            cin >> queries[j];
        }

        // Output
        vector<int> results = findLongestBeautifulSubstrings(s, queries);
        for (int result : results) {
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}
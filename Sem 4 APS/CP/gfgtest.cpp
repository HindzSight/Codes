#include <bits/stdc++.h>
using namespace std;

int countBeautifulPairs(vector<string>& box) {
    int count = 0;

    for (int i = 0; i < box.size(); ++i) {
        for (int j = i + 1; j < box.size(); ++j) {
            string concat = box[i] + box[j];
            bool isBeautiful = true;
            map<char, int> charFreq;
            for (char ch : concat) {
                ++charFreq[ch];
            }
            int oddCount = 0;
            for (auto& p : charFreq) {
                if (p.second % 2 != 0) {
                    ++oddCount;
                }
                if (oddCount > 1) {
                    isBeautiful = false;
                    break;
                }
            }

            if (isBeautiful) {
                ++count;
            }
        }
    }
    return count;
}
int main() {
    vector<string> box = {"bbcb","abccc","abc"};
    cout<<countBeautifulPairs(box);
    return 0;
}

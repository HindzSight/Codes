#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        int max_teleports = 0;
        for (int i = 0; i < n; ++i) {
            max_teleports = max(max_teleports, c[i] - i);
        }

        cout << max_teleports << endl;
    }

    return 0;
}

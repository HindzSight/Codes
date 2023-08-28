#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }

        bool found = false;

        // Iterate through each column and count the occurrences of 'v', 'i', 'k', and 'a'
        for (int c1 = 0; c1 < m; ++c1) {
            for (int c2 = c1 + 1; c2 < m; ++c2) {
                for (int c3 = c2 + 1; c3 < m; ++c3) {
                    for (int c4 = c3 + 1; c4 < m; ++c4) {
                        int v_count = 0, i_count = 0, k_count = 0, a_count = 0;
                        for (int r = 0; r < n; ++r) {
                            if (carpet[r][c1] == 'v') v_count++;
                            if (carpet[r][c2] == 'i') i_count++;
                            if (carpet[r][c3] == 'k') k_count++;
                            if (carpet[r][c4] == 'a') a_count++;
                        }
                        if (v_count > 0 && i_count > 0 && k_count > 0 && a_count > 0) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}

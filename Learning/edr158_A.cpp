#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> stations(n);
        for (int i = 0; i < n; ++i) {
            cin >> stations[i];
        }

        int maxDistance = max(2*(x-stations[n-1]),stations[0]);
        for (int i = 1; i < n; i++) {
            maxDistance = max(maxDistance, stations[i] - stations[i - 1]);
        }
        // int minTankVolume = max(maxDistance, max(stations[0], x - stations[n - 1]));

        cout << maxDistance << endl;
    }

    return 0;
}

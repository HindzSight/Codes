#include<bits/stdc++.h>

using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        double a, b, c; 
        cin >> a >> b >> c;
        double moves = 0; 
        if (a == b) {
            cout << "0\n";
            continue;
        }
        bool dir = (a > b);
        double diff = abs(a - b);

        while (diff > 0) {
            double x = min(diff, c); 
            diff -= x;

            if (dir) {
                a -= x;
                b += x;
            } else {
                a += x;
                b -= x;
            }
            moves++;
        }
        cout << ceil(moves/2) << "\n";
    }

    return 0;
}
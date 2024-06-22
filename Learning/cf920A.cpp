#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(x1 == x2) cout << (y2-y1)*(y2-y1) << endl;
        else if(x1 == x3) cout << (y3-y1)*(y3-y1) << endl;
        else if(x1 == x4) cout << (y4-y1)*(y4-y1) << endl;
        else if(x2 == x3) cout << (y2-y3)*(y2-y3) << endl;
        else if(x2 == x4) cout << (y4-y2)*(y4-y2) << endl;
        else if(x3 == x4) cout << (y3-y4)*(y3-y4) << endl;
    }

    return 0;
}

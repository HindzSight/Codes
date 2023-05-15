//Assembly Line Scheduling Lab 14

#include <iostream>
#include <vector>

using namespace std;

int AssemblyLineScheduling(int n, vector<int> a1, vector<int> a2, vector<int> t1, vector<int> t2, int e1, int e2, int x1, int x2) {
    vector<int> T1(n), T2(n);

    T1[0] = e1 + a1[0];
    T2[0] = e2 + a2[0];

    for (int i = 1; i < n; i++) {
        T1[i] = min(T1[i-1] + a1[i], T2[i-1] + t2[i-1] + a1[i]);
        T2[i] = min(T2[i-1] + a2[i], T1[i-1] + t1[i-1] + a2[i]);
    }

    return min(T1[n-1] + x1, T2[n-1] + x2);
}

int main() {
    int n = 6;
    vector<int> a1 = {7, 9, 3, 4, 8, 4};
    vector<int> a2 = {8, 5, 6, 4, 5, 7};
    vector<int> t1 = {2, 3, 1, 3, 4};
    vector<int> t2 = {2, 1, 2, 2, 1};
    int e1 = 2, e2 = 4, x1 = 3, x2 = 2;

    cout << "Minimum time to complete production: " << AssemblyLineScheduling(n, a1, a2, t1, t2, e1, e2, x1, x2) << endl;

    return 0;
}

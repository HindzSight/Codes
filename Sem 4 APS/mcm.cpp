//MCM
#include <iostream>
#include <vector>

using namespace std;

void printOptimalParens(vector<vector<int>> s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }
}

void matrixChainOrder(vector<int> p) {
    int n = p.size() - 1;
    vector<vector<int>> m(n, vector<int>(n));
    vector<vector<int>> s(n, vector<int>(n));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: " << m[0][n-1] << endl;
    cout << "Optimal Parentheses: ";
    printOptimalParens(s, 0, n-1);
    cout << endl;
}

int main() {
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    matrixChainOrder(p);

    return 0;
}

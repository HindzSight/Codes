#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

bool findPair(int l, int r) {
  if (l > r) {
    return false;
  }

  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (gcd(i, j) != 1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;

    if (findPair(l, r)) {
      cout << l << " " << r << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
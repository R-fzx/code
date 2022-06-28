#include <iostream>

using namespace std;

const int kN = 1e5 + 2;

int t, n, a[kN], b[kN], c[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = n - 1; i >= 0; --i) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    if (a[n - 1] == 9) {              // a >= 900
      for (int i = 0; i <= n; ++i) {  // 1111 即可
        b[i] = 1;
      }
    } else {                         // a < 900
      for (int i = 0; i < n; ++i) {  // 999 即可
        b[i] = 9;
      }
    }
    for (int i = 0; i < n; ++i) {  // 高精减
      if (b[i] < a[i]) {
        --b[i + 1], b[i] += 10;
      }
      c[i] = b[i] - a[i];
    }
    for (int i = n - 1; i >= 0; --i) {  // 输出
      cout << c[i];
    }
    cout << '\n';
  }
  return 0;
}
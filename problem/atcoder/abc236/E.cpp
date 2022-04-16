#include <iostream>

using namespace std;

const int kN = 1e5 + 1;
const double kE = 1e-6;

int n, a[kN];
double b[kN], f[kN][2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  {
    double l = 0, r = 1e9;
    while (r - l > kE) {
      double m = (l + r) / 2;
      for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - m;
      }
      for (int i = 1; i <= n; ++i) {
        f[i][0] = f[i - 1][1], f[i][1] = max(f[i - 1][0], f[i - 1][1]) + b[i];
      }
      (max(f[n][0], f[n][1]) >= 0 ? l : r) = m;
    }
    cout << l << endl;
  }
  {
    int l = 1, r = 1e9;
    while (l < r) {
      int m = l + r + 1 >> 1;
      for (int i = 1; i <= n; ++i) {
        b[i] = (a[i] >= m ? 1 : -1);
      }
      for (int i = 1; i <= n; ++i) {
        f[i][0] = f[i - 1][1], f[i][1] = max(f[i - 1][0], f[i - 1][1]) + b[i];
      }
      if (max(f[n][0], f[n][1]) > 0) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    cout << r;
  }
  return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ull = unsigned long long;
const int kN = 5e5 + 5, kH = 19491001;

ull h[kN], f[kN], b[kN];
int n, a[kN], ans, l, r, d, s, q[kN];
int main () {
  freopen ("snowman.in", "r", stdin);
  freopen ("snowman.out", "w", stdout);
  ios :: sync_with_stdio (false);
  cin.tie (0), cout.tie (0);

  cin >> n, b[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], b[i] = b[i - 1] * kH, h[i] = h[i - 1] * kH + ull (a[i] - a[i - 1] + 1e9);
  }
  for (l = 0, r = n / 2 + 1; l < r; ) {
    d = l + r + 1 >> 1;
    bool t = false;
    for (int i = 1, j = d - 1; j <= n; i++, j++) {
      f[i] = h[j] - h[i - 1] * b[j - i + 1], q[i] = i;
    }
    sort (q + 1, q + n - d + 3, [&] (int &x, int &y) { return (f[x] < f[y]) || (f[x] == f[y] && x < y); });
    for (int i = 1, j = 1; i <= n - d + 2; i = j) {
      for ( ; f[q[i]] == f[q[j]] && j <= n - d + 2; j++) {}
      s = q[j - 1] - q[i];
      if (s >= d) {
        t = true;
        break;
      }
    }
    (t) ? l = d : r = d - 1;
  }
  cout << l << '\n';
  return 0;
}
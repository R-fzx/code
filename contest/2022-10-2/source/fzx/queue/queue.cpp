#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001;

int n, c[kN];
double s, _s, __s;

int main() {
  RF("queue");
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x, ++c[x];
  }
  for (int i = 0, k = 0; i < kN; ++i) {
    _s = 0;
    for (int u = 1; u <= n; ++u) {
      __s = n - u + 1;
      for (int j = k + 1; j < n; ++j) {
        __s /= j + u;
      }
      _s += __s;
    }
    double x = n + k - 1;
    for (int j = k + 1; j <= n; ++j) {
      x /= j;
    }
    s += _s * x, k += c[i];
  }
  cout << fixed << setprecision(2) << s;
  return 0;
}
/*
123
111
011
001
-------
132
101
010
001
-------
213
101
011
001
-------
231
100
011
001
-------
312
110
010
001
-------
321
100
010
001
*/
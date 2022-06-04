#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#define lt(x) (x * m + 1)
#define rt(x) ((x + 1) * m)

using namespace std;
using LL = long long;

const int kN = 100500;
const int kB = 320;

int n, m, q, o, l, r, v, d[kN];
LL a[kN], s[kB], t[kB];

int main() {
  // freopen("P3372.in", "r", stdin);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  m = sqrt(n) + 1, n = m * m;
  for (int i = 0; i < m; ++i) fill(d + lt(i), d + rt(i) + 1, i), s[i] = accumulate(a + lt(i), a + rt(i) + 1, 0);
  while (q--) {
    cin >> o >> l >> r;
    if (o == 1) {
      cin >> v;
      for (int i = l; i <= rt(d[l]); ++i) a[i] += v, s[d[i]] += v;
      if (d[l] != d[r])
        for (int i = lt(d[r]); i <= r; ++i) a[i] += v, s[d[i]] += v;
      for (int i = d[l] + 1; i < d[r]; ++i) t[i] += v;
    } else {
      LL _s = 0;
      for (int i = l; i <= rt(d[l]); ++i) _s += a[i] + t[d[i]];
      if (d[l] != d[r])
        for (int i = lt(d[r]); i <= r; ++i) _s += a[i] + t[d[i]];
      for (int i = d[l] + 1; i < d[r]; ++i) _s += s[i] + t[i] * m;
      cout << _s << endl;
    }
  }
  return 0;
}
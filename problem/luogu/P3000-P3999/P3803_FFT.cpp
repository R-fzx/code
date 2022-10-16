#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2097152;

struct C {
  double r, i;
  C() {}
  C(double _r, double _i) : r(_r), i(_i) {}
  const C operator+(const C &o) const { return C(r + o.r, i + o.i); }
  const C operator-(const C &o) const { return C(r - o.r, i - o.i); }
  const C operator*(const C &o) const { return C(r * o.r - i * o.i, r * o.i + i * o.r); }
} f[kN], g[kN];
int n, m, r[kN], l, cl;

void FFT(C *a, int l, bool iv) {
  for (int i = 0; i < l; ++i) {
    if (i < r[i]) {
      swap(a[i], a[r[i]]);
    }
  }
  for (int _l = 1; _l < l; _l <<= 1) {
    C wi = C(cos(M_PI / _l), (iv ? -1 : 1) * sin(M_PI / _l));
    for (int i = 0; i < l; i += _l << 1) {
      C w = C(1, 0);
      for (int j = i; j < i + _l; ++j, w = w * wi) {
        C _w = w * a[j + _l];
        a[j + _l] = a[j] - _w, a[j] = a[j] + _w;
      }
    }
  }
  if (iv) {
    for (int i = 0; i < l; ++i) {
      a[i].r /= l;
    }
  }
}

int main() {
  // RF("P3803");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (l = 1; l <= n + m; l <<= 1, ++cl) {
  }
  for (int i = 0; i < l; ++i) {
    r[i] = r[i >> 1] >> 1 | ((i & 1) << cl - 1);
  }
  for (int i = 0; i <= n; ++i) {
    cin >> f[i].r;
  }
  for (int i = 0; i <= m; ++i) {
    cin >> g[i].r;
  }
  FFT(f, l, 0), FFT(g, l, 0);
  for (int i = 0; i < l; ++i) {
    f[i] = f[i] * g[i];
  }
  FFT(f, l, 1);
  for (int i = 0; i <= n + m; ++i) {
    cout << int(f[i].r + 0.5) << ' ';
  }
  return 0;
}
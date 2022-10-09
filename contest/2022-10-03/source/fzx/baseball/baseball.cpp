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
using LL = __int128_t;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

LL G(LL x, LL y) { return y ? G(y, x % y) : x; }
struct F {
  LL x, y;

  F(LL _x, LL _y = 1) {
    LL g = G(_x, _y);
    x = _x / g, y = _y / g;
    if (y < 0) {
      x = -x, y = -y;
    }
  }
  F() { x = 0, y = 1; }
  const F operator+(const F &o) const { return F(x * o.y + o.x * y, y * o.y); }
  const F operator-(const F &o) const { return F(x * o.y - o.x * y, y * o.y); }
  const F operator*(const F &o) const { return F(x * o.x, y * o.y); }
  const F operator/(const F &o) const { return F(x * o.y, y * o.x); }
  const F operator^(const F &o) const { return F(x + o.x, y + o.y); }
  bool operator>(const F &o) const { return x * o.y > o.x * y; }
  bool operator>=(const F &o) const { return x * o.y >= o.x * y; }
} x, l, r, m;
int n;

void W(LL x) {
  if (!x) {
    return;
  }
  if (x < 0) {
    putchar('-'), W(-x);
    return;
  }
  W(x / 10), putchar(x % 10 + '0');
}

int main() {
  RF("baseball");
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (; cin >> n;) {
    for (x = F(); getchar() != '.';) {
    }
    // debug("%lld/%lld\n", x.x, x.y);
    for (int i = 0; i < n; ++i, x.x = x.x * 10 + getchar() - '0', x.y *= 10) {
    }
    if (!x.x) {
      cout << "1\n";
      continue;
    }
    // debug("%lld/%lld\n", x.x, x.y);
    for (l = F(), r = F(1); (m = l ^ r) > x ? m - x >= F(1, 2 * x.y) : x - m > F(1, 2 * x.y);) {
      // debug("%lld/%lld %lld/%lld %lld/%lld\n", l.x, l.y, m.x, m.y, r.x, r.y);
      // W(l.x), putchar(' '), W(l.y), putchar(' '), W(m.x), putchar(' '), W(m.y), putchar(' '), W(r.x), putchar(' '), W(r.y), puts("");
      if (x > m) {
        F _x = x - F(1, 2 * x.y);
        F y = (F(m.x) - _x * m.y) / (_x * r.y - r.x);
        // W(y.x), putchar(' '), W(y.y), puts("");
        // W(_x.x), putchar(' '), W(_x.y), puts("");
        LL k;
        F _i = _x * r.y - r.x;
        // W(_i.x), putchar(' '), W(_i.y), puts("");
        // cout << "114514\n";
        if (_x * r.y - r.x > 0) {
          k = y.x / y.y - 1;
        } else {
          // cout << "114514\n";
          k = (y.x + y.y - 1) / y.y - 1;
        }
        // W(k), puts("");
        l = F(m.x + k * r.x, m.y + k * r.y);
      } else {
        F _x = x + F(1, 2 * x.y);
        F y = (F(m.x) - _x * m.y) / (_x * l.y - l.x);
        // W(y.x), putchar(' '), W(y.y), puts("");
        // W(_x.x), putchar(' '), W(_x.y), puts("");
        LL k;
        if (_x * l.y - l.x > 0) {
          k = y.x / y.y;
        } else {
          k = (y.x - 1) / y.y - 1;
        }
        // W(k), puts("");
        r = F(m.x + k * l.x, m.y + k * l.y);
      }
    }
    // W(m.x), putchar('/'), W(m.y), puts("");
    // W(m.x), puts("");
    W(m.y), puts("");
    // cout << m.x << ' ' << m.y << '\n';
  }
  return 0;
}
/*
15 0.000401721710919
0.001946158112810
*/
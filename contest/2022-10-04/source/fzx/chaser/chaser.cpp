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
using db = double;

const db kE = 1e-8;

struct P {
  db x, y;

  P() {}
  P(db x, db y) : x(x), y(y) {}
  const P operator-() const { return {-x, -y}; }
  const P operator+(const P &o) const { return {x + o.x, y + o.y}; }
  const P operator-(const P &o) const { return *this + (-o); }
  const P operator*(const db &a) const { return {x * a, y * a}; }
  const P operator/(const db &a) const { return {x / a, y / a}; }
  db operator*(const P &o) const { return x * o.y - y * o.x; }
  db operator^(const P &o) const { return x * o.x + y * o.y; }
};
int S(db x) { return x > kE ? 1 : (x < -kE ? -1 : 0); }
db D(const P &o) { return hypot(o.x, o.y); }
db D(const P &o, const P &a, const P &b) {
  P oa = o - a, ob = o - b, p = a - b;
  if (S(D(p))) {
    if (S(-p ^ oa) == -1) {
      return D(oa);
    }
    if (S(p ^ ob) == -1) {
      return D(ob);
    }
    return fabs(p * ob / D(p));
  } else {
    return D(oa);
  }
}
const P kO = {0, 0};
P w1, w2, t1, t2, pw, pt;
db vw, vt, d1, d2, t, ans;

int main() {
  RF("chaser");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (; cin >> w1.x >> w1.y >> w2.x >> w2.y >> vw >> t1.x >> t1.y >> t2.x >> t2.y >> vt >> d1 >> d2;) {
    t = D(t1 - t2) / vt;
    pw = (w1 - w2) / D(w1 - w2) * vw, pt = (t2 - t1) / t, ans = 1e18;
    // cout << pw.x << ' ' << pw.y << ' ' << pt.x << ' ' << pt.y << '\n';
    // cout << ans << ' ';
    int l1 = 1, r1 = 1e9;
    while (l1 + 5 < r1) {
      int m1 = l1 + (r1 - l1) / 3, m2 = l1 + 2 * (r1 - l1) / 3;
      db d1 = D(w1, t1 + pw * 2 * (m1 - 1) * t, t1 + pw * 2 * (m1 - 1) * t + (pw + pt) * t);
      db d2 = D(w1, t1 + pw * 2 * (m2 - 1) * t, t1 + pw * 2 * (m2 - 1) * t + (pw + pt) * t);
      ans = min({ans, d1, d2});
      // cout << l1 << ' ' << m1 << ' ' << m2 << ' ' << r1 << '\n';
      if (d1 < d2) {
        r1 = m2;
      } else {
        l1 = m1;
      }
    }
    // cout << ans << '\n';
    for (int i = l1; i <= r1; ++i) {
      db d = D(w1, t1 + pw * 2 * (i - 1) * t, t1 + pw * 2 * (i - 1) * t + (pw + pt) * t);
      // cout << i << ' ' << d << '\n';
      ans = min(ans, d);
    }
    // cout << ans << ' ';
    int l2 = 1, r2 = 1e9;
    while (l2 + 5 < r2) {
      int m1 = l2 + (r2 - l2) / 3, m2 = m1 + (r2 - l2) / 3;
      db d1 = D(w1, t1 + pw * 2 * (m1 - 1) * t + (pw + pt) * t, t1 + pw * 2 * m1 * t);
      db d2 = D(w1, t1 + pw * 2 * (m2 - 1) * t + (pw + pt) * t, t1 + pw * 2 * m2 * t);
      ans = min({ans, d1, d2});
      if (d1 < d2) {
        r2 = m2;
      } else {
        l2 = m1;
      }
    }
    for (int i = l2; i <= r2; ++i) {
      db d = D(w1, t1 + pw * 2 * (i - 1) * t + (pw + pt) * t, t1 + pw * 2 * i * t);
      ans = min(ans, d);
    }
    cout << (ans < d1 ? "Dangerous" : (ans > d2 ? "Miss" : "Perfect")) << '\n';
  }
  return 0;
}
/*
叉积(x*y) 点积(x^y):
>0 | >0
<0 | >0
--------x
<0 | <0
<0 | >0
*/
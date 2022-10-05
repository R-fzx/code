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
  db operator*(const P &o) const { return x * o.y - y * o.x; }
  db operator^(const P &o) const { return x * o.x + y * o.y; }
};
int S(db x) { return x > kE ? 1 : (x < -kE ? -1 : 0); }
db L(const P &o) { return hypot(o.x * o.x, o.y * o.y); }
db L(const P &o, const P &a, const P &b) {
  P oa = o - a, ob = o - b, p = a - b;
  if (S(L(p))) {
    if (S(-p ^ oa) == -1) {
      return L(oa);
    }
    if (S(p ^ ob) == -1) {
      return L(ob);
    }
    return fabs(ob * p / L(p));
  } else {
    return L(oa);
  }
}
P w1, w2, t1, t2;
db vw, vt, d1, d2;

int main() {
  RF("chaser");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (; cin >> w1.x >> w1.y >> w2.x >> w2.y >> vw >> t1.x >> t1.y >> t2.x >> t2.y >> vt >> d1 >> d2;) {
    
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
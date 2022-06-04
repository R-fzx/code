#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 101;
const LD kV = 1e5;

int n, h, t;
Pdd p[kN];
Vec a[kN + 4];
pair<Vec, Pdd> e[kN + 4];

Pdd operator+(Pdd x, Pdd y) { return {x.first + y.first, x.second + y.second}; }
Pdd operator-(Pdd x, Pdd y) { return {x.first - y.first, x.second - y.second}; }
Pdd operator*(Pdd x, LD y) { return {x.first * y, x.second * y}; }
LD operator*(Pdd x, Pdd y) { return x.first * y.second - x.second * y.first; }
LD operator*(Vec x, Vec y) { return (x.second - x.first) * (y.second - y.first); }
LD operator*(Vec x, Pdd y) { return (x.second - x.first) * (y - x.first); }

bool Up(Pdd x) { return x.second < 0 || x.second == 0 && x.first < 0; }
Pdd P(Vec x, Vec y) {
  LD _d = -(y * x.first), d = _d / (_d + y * x.second);
  return x.first + (x.second - x.first) * d;
}
bool S() {
  p[0] = p[n];
  for (int i = 1; i <= n; ++i) {
    a[i] = {p[i - 1], p[i]};
  }
  a[++n] = {{kV, kV}, {-kV, kV}}, a[++n] = {{-kV, kV}, {-kV, -kV}}, a[++n] = {{-kV, -kV}, {kV, -kV}}, a[++n] = {{kV, -kV}, {kV, kV}};
  sort(a + 1, a + n + 1, [](Vec x, Vec y) {
    LD ux = Up(x.second - x.first), uy = Up(y.second - y.first), v = x * y;
    return ux == uy ? (v > 0 || !v && x * y.first < 0) : ux < uy;
  });
  e[h = t = 1] = {a[1], {-1e12, a[1].first.second}};
  for (int i = 2; i <= n; ++i) {
    if (a[i] * a[i - 1]) {
      for (; h <= t && a[i] * e[t].second < 0; --t) {
      }
      if (h > t) {
        return 0;
      }
      ++t, e[t] = {a[i], P(a[i], e[t - 1].first)};
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int _ = 1; (cin >> n) && n; ++_) {
    for (int i = n; i >= 1; --i) {
      cin >> p[i].first >> p[i].second;
    }
    printf("Room #%d:\nSurveillance is %spossible.\n\n", _, S() ? "" : "im");
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
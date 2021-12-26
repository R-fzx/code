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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = long double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 505;
const LD kV = 1e5;

int q, n, h, t;
Vec a[kN];
pair<Vec, Pdd> e[kN];

Pdd operator-(Pdd x, Pdd y) { return {x.first - y.first, x.second - y.second}; }
Pdd operator+(Pdd x, Pdd y) { return {x.first + y.first, x.second + y.second}; }
Pdd operator*(Pdd x, LD y) { return {x.first * y, x.second * y}; }
LD operator*(Pdd x, Pdd y) { return x.first * y.second - x.second * y.first; }
LD operator*(Vec x, Vec y) { return (x.second - x.first) * (y.second - y.first); }
LD operator*(Vec x, Pdd y) { return (x.second - x.first) * (y - x.first); }

bool Up(Pdd x) { return x.second < 0 || x.second == 0 && x.first < 0; }
bool operator<(Vec x, Vec y) {
  LD ux = Up(x.second - x.first), uy = Up(y.second - y.first);
  return ux == uy ? (x * y > 0 || x * y == 0 && x * y.first < 0) : ux < uy;
}
Pdd P(Vec x, Vec y) {
  LD _d = -(y * x.first), d = _d / (_d + y * x.second);
  return x.first + (x.second - x.first) * d;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  a[++n] = {{kV, kV}, {-kV, kV}}, a[++n] = {{-kV, kV}, {-kV, -kV}}, a[++n] = {{-kV, -kV}, {kV, -kV}}, a[++n] = {{kV, -kV}, {kV, kV}};
  cin >> q;
  for (int _ = 1, m; _ <= q; ++_) {
    cin >> m;
    Pdd x, y, p;
    cin >> p.first >> p.second;
    x = p;
    for (int i = 1; i < m; ++i) {
      cin >> y.first >> y.second;
      a[++n] = {x, y}, x = y;
    }
    a[++n] = {x, p};
  }
  sort(a + 1, a + n + 1), e[h = t = 1] = {a[1], {-kV, a[1].first.second}};
  for (int i = 2; i <= n; ++i) {
    if (a[i] * a[i - 1]) {
      for (; h < t && a[i] * e[t].second < 0; --t) {
      }
      ++t, e[t] = {a[i], P(a[i], e[t - 1].first)};
      for (; h + 1 < t && e[t].first * e[h + 1].second < 0; ++h) {
      }
    }
  } 
  for (; h + 1 < t && e[h].first * e[t].second < 0; --t) {
  }
  e[h].second = P(e[h].first, e[t].first);
  LD ans = e[t].second * e[h].second;
  for (int i = h; i < t; ++i) {
    ans += e[i].second * e[i + 1].second;
  }
  cout << fixed << setprecision(3) << ans / 2;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
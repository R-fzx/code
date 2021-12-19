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
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 301;
const double kEps = 1e-11, kInf = 1e18;

int n;
Pdd a[kN];
double ans = kInf, l, r;

double Cross(Pdd o, Pdd x, Pdd y) {
  return (x.first - o.first) * (y.second - o.second) - (x.second - o.second) * (y.first - o.first);
}
Pdd P(Pdd x, Pdd y, Pdd i, Pdd j) {
  double _d = Cross(x, i, y), d = _d / (_d + Cross(x, y, j));
  return {i.first + (j.first - i.first) * d, i.second + (j.second - i.second) * d};
}
double C(Pdd x) {
  double m = -kInf;
  for (int i = 1; i < n; ++i) {
    m = max(m, P(a[i], a[i + 1], {x.first, -kInf}, {x.first, kInf}).second);
  }
  ans = min(ans, m - x.second);
  return m - x.second;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
  }
  for (int i = 1; i < n; ++i) {
    double l = a[i].first, r = a[i + 1].first;
    for (int _ = 1; _ <= 100; ++_) {
      double m0 = l + (r - l) / 3, m1 = r - (r - l) / 3;
      C(P(a[i], a[i + 1], {m0, -kInf}, {m0, kInf})) < C(P(a[i], a[i + 1], {m1, -kInf}, {m1, kInf})) ? (r = m1) : (l = m0);
    }
    C(P(a[i], a[i + 1], {(l + r) / 2, -kInf}, {(l + r) / 2, kInf}));
  }
  cout << fixed << setprecision(3) << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
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
#include <random>
// #define TIME

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 301;
const double kEps = 1e-9, kInf = 1e7, kD = 0.99;

int n;
Pdd a[kN];
double ans = -1e18, l, r, ansx;
random_device rd;
mt19937 rnd(rd());

double Cross(Pdd o, Pdd x, Pdd y) {
  return (x.first - o.first) * (y.second - o.second) - (x.second - o.second) * (y.first - o.first);
}
bool Cp(Pdd x, Pdd y, Pdd i, Pdd j) {
  return Cross(x, y, i) * Cross(x, y, j) < 0 && Cross(i, j, x) * Cross(i, j, y) < 0;
}
Pdd P(Pdd x, Pdd y, Pdd i, Pdd j) {
  double _d = Cross(x, i, y), d = _d / (_d + Cross(x, y, j));
  return {i.first + (j.first - i.first) * d, i.second + (j.second - i.second) * d};
}
double C(double x) {
  double y = 0;
  for (int i = 1; i < n; ++i) {
    if (Cp(a[i], a[i + 1], {x, -kInf}, {x, kInf})) {
      y = P(a[i], a[i + 1], {x, -kInf}, {x, kInf}).second;
      break;
    }
  }
  double m = -kInf;
  for (int i = 1; i < n; ++i) {
    m = max(m, P(a[i], a[i + 1], {x, -kInf}, {x, kInf}).second);
  }
  if (ans < y - m) {
    ans = y - m, ansx = x;
  }
  return y - m;
}
void SA(int x) {
  for (double T = 20000; T > kEps; T *= kD) {
    double nx = x + uniform_real_distribution<double>(-1, 1)(rnd) * T, d = C(nx) - C(x);
    if (exp(-d / T) > uniform_real_distribution<double>(0, 1)(rnd)) {
      x = nx;
    }
  }
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
  for (ansx = (a[1].first + a[n].first) / 2; clock() <= 990; SA(ansx)) {
  }
  printf("%.3lf", -ans);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
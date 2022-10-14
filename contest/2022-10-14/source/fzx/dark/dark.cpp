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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;
const auto C = [](const Pll &i, const Pll &j) { return i.second < j.second; };

int n;
Pll a[kN];

double D(int i, int j) { return hypot(a[i].first - a[j].first, a[i].second - a[j].second); }
double S(int l, int r) {
  if (l >= r) {
    return 1e9;
  }
  int m = l + r >> 1;
  LL mx = a[m].first;
  double d = min(S(l, m), S(m + 1, r));
  inplace_merge(a + l, a + m + 1, a + r + 1, C);
  vector<int> b;
  for (int i = l; i <= r; ++i) {
    if (abs(mx - a[i].first) <= d) {
      b.push_back(i);
    }
  }
  for (int i = 0; i < b.size(); ++i) {
    for (int j = i + 1; j < b.size() && a[b[j]].second - a[b[i]].second <= d; ++j) {
      d = min(d, D(b[i], b[j]));
    }
  }
  return d;
}

int main() {
  RF("dark");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  cout << fixed << setprecision(3) << S(1, n) / 2;
  return 0;
}
/*
i j
sqrt((i.x-j.x)^2+(i.y-j.y)^2)/2
*/
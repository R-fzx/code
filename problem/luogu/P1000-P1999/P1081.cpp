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

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1, kL = 17;

int n, m, t[kN][kL][2];
LL a[kN], x, al[kN][kL][2], bl[kN][kL][2];
multiset<Pll> s;

Pll C(int s, LL x) {
  LL la = 0, lb = 0;
  for (int i = kL - 1; i >= 0; --i) {
    if (t[s][i][0] && la + lb + al[s][i][0] + bl[s][i][0] <= x) {
      la += al[s][i][0], lb += bl[s][i][0], s = t[s][i][0];
    }
  }
  return {la, lb};
}

int main() {
  freopen("P1081_2.in", "r", stdin);
  freopen("P1081.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  s.insert({-1e9, 0}), s.insert({-1e9, 0}), s.insert({1e9, 0}), s.insert({1e9, 0});
  for (int i = n; i >= 1; --i) {
    auto p = --s.lower_bound({a[i], 0});
    Pll l[4];
    for (int j = 0; j < 4; ++p, ++j) {
      l[j] = {abs(p->first - a[i]), p->second};
    }
    sort(l, l + 4, [](const Pii &i, const Pii &j) { return i.first < j.first || i.first == j.first && a[i.second] < a[j.second]; });
    tie(al[i][0][0], t[i][0][0]) = l[1], tie(bl[i][0][1], t[i][0][1]) = l[0];
    // debug("%lld %lld %lld %lld\n", t[i][0][0], t[i][0][1], al[i][0][0], bl[i][0][1]);
    s.insert({a[i], i});
  }
  for (int j = 1; j < kL; ++j) {
    for (int i = 1; i <= n; ++i) {
      for (int k = 0; k < 2; ++k) {
        int _k = k ^ (j == 1), _t = t[i][j - 1][k];
        t[i][j][k] = t[_t][j - 1][_k];
        al[i][j][k] = al[i][j - 1][k] + al[_t][j - 1][_k];
        bl[i][j][k] = bl[i][j - 1][k] + bl[_t][j - 1][_k];
      }
    }
  }
  cin >> x;
  int ans = 0;
  a[0] = -1e10;
  LL ansa = 1, ansb = 0;
  for (int i = 1; i <= n; ++i) {
    Pll y = C(i, x);
    if (!y.second) {
      y.first = 1;
    }
    // debug("%lld %lld\n", y.first, y.second);
    if (y.first * ansb < y.second * ansa || y.first * ansb == y.second * ansa && a[ans] < a[i]) {
      ans = i, tie(ansa, ansb) = y;
    }
  }
  cout << ans << '\n';
  cin >> m;
  for (int s; m--; ) {
    cin >> s >> x;
    Pll y = C(s, x);
    cout << y.first << ' ' << y.second << '\n';
  }
  return 0;
}
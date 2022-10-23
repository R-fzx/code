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

const int kN = 1e5 + 1, kL = 17;

int n, m, h[kN], x, ne[kN][kL][2];
Pll d[kN][kL][2];
using A = pair<LL, Pll>;
A ans0 = {0, {1, 0}};
struct C {
  int _h;
  C() {}
  C(int _h) : _h(_h) {}
  bool operator()(int x, int y) const { return x && (!y || make_pair(abs(h[x] - _h), h[x]) < make_pair(abs(h[y] - _h), h[y])); }
};
const auto cmp = [](int i, int j) { return h[i] < h[j]; };
set<int, decltype(cmp)> s(cmp);

bool operator<(const A &x, const A &y) { // x优于y
  if (x.second.second || y.second.second) {
    if (!y.second.second) {
      return 1;
    }
    if (!x.second.second) {
      return 0;
    }
    return make_pair(x.second.first * y.second.second, -h[x.first]) < make_pair(y.second.first * x.second.second, -h[y.first]);
  } else {
    return h[x.first] > h[y.first];
  }
}
const Pll operator+(const Pll &x, const Pll &y) { return {x.first + y.first, x.second + y.second}; }
Pll S(int s, int x) {
  Pll ans = {0, 0};
  for (int i = kL - 1; i >= 0; --i) {
    int y = ne[s][i][0];
    Pll d = ::d[s][i][0];
    if (y && x >= d.first + d.second) {
      s = y, x -= d.first + d.second, ans = ans + d;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = n; i >= 1; --i) {
    // cerr << "i=" << i << '\n';
    // for (int j : s) {
    //   cerr << j << ' ';
    // }
    // cerr << '\n';
    auto p = s.lower_bound(i);
    // cerr << "p=" << *p << '\n';
    auto _p = p;
    int d[4] = {0};
    if (p != s.end()) {
      d[0] = *p;
      if (++p != s.end()) {
        d[1] = *p;
      }
    }
    if (_p != s.begin()) {
      d[2] = *--_p;
      if (_p != s.begin()) {
        d[3] = *--_p;
      }
    }
    // cerr << d[0] << ' ' << d[1] << ' ' << d[2] << ' ' << d[3] << '\n';
    sort(d, d + 4, C(h[i]));
    ne[i][0][0] = d[1], ne[i][0][1] = d[0];
    ::d[i][0][0] = {abs(h[i] - h[d[1]]), 0}, ::d[i][0][1] = {0, abs(h[i] - h[d[0]])};
    // cerr << ne[i][0][0] << ' ' << ne[i][0][1] << '\n';
    s.insert(i);
  }
  for (int i = 1; i < kL; ++i) {
    for (int j = 1; j <= n; ++j) {
      ne[j][i][0] = ne[ne[j][i - 1][0]][i - 1][i == 1];
      ne[j][i][1] = ne[ne[j][i - 1][1]][i - 1][i != 1];
      d[j][i][0] = d[j][i - 1][0] + d[ne[j][i - 1][0]][i - 1][i == 1];
      d[j][i][1] = d[j][i - 1][1] + d[ne[j][i - 1][1]][i - 1][i != 1];
    }
  }
  cin >> x;
  for (int i = 1; i <= n; ++i) {
    A v = {i, S(i, x)};
    if (v < ans0) {
      ans0 = v;
    }
  }
  cout << ans0.first << '\n';
  cin >> m;
  for (int s; m--;) {
    cin >> s >> x;
    Pll v = S(s, x);
    cout << v.first << ' ' << v.second << '\n';
  }
  return 0;
}
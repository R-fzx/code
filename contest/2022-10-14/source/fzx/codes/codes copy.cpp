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

const int kN = 21;

int n, m, d[kN * kN], p[kN * kN];
string s[kN];
bool f[kN][kN][kN];
vector<Pii> e[kN * kN];
priority_queue<Pii, vector<Pii>, greater<Pii>> q;

int E(int x, int y) { return y * n + x; }
bool L(int x, int y) {
  return s[(x - 1) % n + 1] < s[(y - 1) % n + 1];
}
void R(int x, int _d, int _p) {
  if (_d < d[x]) {
    p[x] = _p, d[x] = _d, q.emplace(_d, x);
  } else if (_d == d[x] && L(_p, p[x])) {
    p[x] = _p;
  }
}
void P(int x) {
  if (~x) {
    P(p[x]);
    cout << s[(x - 1) % n + 1];
  }
}

int main() {
  RF("codes");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s[i].size(); ++j) {
      f[i][j][s[i].size() - j] = 1;
      for (int k = s[i].size() - j; k >= 0; --k) {
        if (f[i][j][k]) {
          for (int x = 1; x <= n; ++x) {
            if (s[x].size() <= k && x != i && s[i].substr(s[i].size() - k, s[x].size()) == s[x]) {
              f[i][j][k - s[x].size()] = 1;
            }
          }
        }
      }
    }
    f[i][0][0] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s[i].size(); ++j) {
      m = max(m, E(i, j));
      for (int k = 1; k <= n; ++k) {
        for (int y = 0; y <= s[k].size(); ++y) {
          for (int x = 0; x <= s[k].size() - y; ++x) {
            if (f[k][x][y] && count(s + 1, s + n + 1, s[i].substr(s[i].size() - j) + s[k].substr(0, x))) {
              e[E(i, j)].emplace_back(E(k, y), s[k].size());
              break;
            }
          }
        }
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 0; j <= s[i].size(); ++j) {
  //     for (int x : e[E(i, j)]) {
  //       cout << i << ',' << j << ' ' << (x - 1) % n + 1 << ',' << (x - 1) / n << '\n';
  //     }
  //   }
  // }
  ++m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s[i].size(); ++j) {
      if (f[i][0][j]) {
        e[0].emplace_back(E(i, j), s[i].size());
      }
    }
    e[E(i, 0)].emplace_back(m, 1);
  }
  fill(d, d + m + 1, 1e9);
  for (R(0, 0, -1); !q.empty();) {
    int x = q.top().second, _d = q.top().first;
    q.pop();
    if (d[x] == _d) {
      for (Pii i : e[x]) {
        R(i.first, i.second + d[x], x);
      }
    }
  }
  cout << d[m] - 1 << '\n';
  P(p[m]);
  return 0;
}
/*
f[i][j][k - sz[x]] |= f[i][j][k] && s[i].substr(sz[i] - k, sz[x]) == s[x]
g[k][y] |= g[i][j] && f[k][x][y] && Has(s[i].substr(sz[i] - j) + s[k].substr(0, x))
O(n^6)
*/
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
using Pil = pair<int, LL>;

const int kN = 5e4 + 1, kL = 16;

int n, m, c[kN], f[kN][kL], t;
bool v[kN];
Pll p[kN];
LL d[kN][kL];
vector<Pil> e[kN];

void I(int x, int _f, LL _d) {
  f[x][0] = _f, d[x][0] = _d;
  for (int i = 0; i < kL - 1; ++i) {
    f[x][i + 1] = f[f[x][i]][i], d[x][i + 1] = d[x][i] + d[f[x][i]][i];
  }
  for (Pil i : e[x]) {
    if (i.first != _f) {
      I(i.first, x, i.second);
    }
  }
}
bool C(LL x) {
  t = 0, fill_n(v + 1, n, 0);
  for (int i = 1; i <= n; ++i) {
    if (c[i]) {
      int y = i;
      LL t = x;
      for (int j = kL - 1; j >= 0; --j) {
        int _f = f[y][j];
        LL _d = d[y][j];
        if (_f && _f != 1 && t >= _d) {
          y = _f, t -= _d;
        }
      }
      if (f[y][0] == 1) {
        p[++t] = {t, y}, v[y] = 1;
      }
    }
  }
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y, w; i < n; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  cin >> m;
  for (int i = 1, x; i <= m; ++i) {
    cin >> x;
    ++c[x];
  }
  I(1, 0, 0);
  LL l = 0, r = 5e13;
  while (l < r) {
    LL m = l + r >> 1;

  }
  cout << (l == 5e13 ? -1 : l);
  return 0;
}
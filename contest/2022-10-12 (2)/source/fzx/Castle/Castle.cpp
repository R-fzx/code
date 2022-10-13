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

const int kN = 1001;
const LL kM = INT32_MAX;

int n, m;
vector<Pll> e[kN];
LL l[kN][kN];
LL d[kN], c[kN], ans = 1;
priority_queue<Pll, vector<Pll>, greater<Pll>> q;

void R(int x, LL _d) {
  if (_d < d[x]) {
    c[x] = 0, d[x] = _d, q.emplace(_d, x);
  }
  if (_d == d[x]) {
    ++c[x];
  }
}

int main() {
  RF("Castle");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    LL w;
    cin >> x >> y >> w;
    if (!l[x][y] || l[x][y] > w) {
      l[x][y] = l[y][x] = w;
    }
    // e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (l[i][j]) {
        e[i].emplace_back(j, l[i][j]);
      }
    }
  }
  fill_n(d + 1, n, 1e18);
  for (R(1, 0); !q.empty();) {
    int x = q.top().second;
    if (d[x] < q.top().first) {
      q.pop();
      continue;
    }
    q.pop();
    // cout << x << ' ' << d[x] << '\n';
    for (auto i : e[x]) {
      R(i.first, d[x] + i.second);
    }
  }
  // cout << c[1] << ' ';
  for (int i = 2; i <= n; ++i) {
    ans = ans * c[i] % kM;
    // cout << c[i] << ' ';
  }
  // cout << '\n';
  // for (int i = 1; i <= n; ++i) {
  //   cout << d[i] << ' ';
  // }
  // cout << '\n';
  cout << ans;
  return 0;
}
/*
7 7
4 3 2
7 6 7
5 2 3
4 7 4
2 4 4
3 7 2
6 1 2

7 9
4 3 2
7 6 7
5 2 3
7 4 9
4 7 4
4 7 8
2 4 4
3 7 2
6 1 2
*/
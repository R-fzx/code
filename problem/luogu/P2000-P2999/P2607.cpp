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

const int kN = 1e6 + 1;

int n, p[kN], f[kN];
LL g[kN][2], ans;
vector<int> e[kN];
vector<Pii> l;

int F(int x) { return f[x] == x ? x : (f[x] = F(f[x])); }
void D(int x, int f) {
  g[x][0] = 0, g[x][1] = p[x];
  for (int i : e[x]) {
    if (i != f) {
      D(i, x), g[x][0] += max(g[i][0], g[i][1]), g[x][1] += g[i][0];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  iota(f + 1, f + n + 1, 1);
  for (int i = 1, x; i <= n; ++i) {
    cin >> p[i] >> x;
    if (F(x) == F(i)) {
      l.emplace_back(x, i);
    } else {
      f[f[x]] = f[i], e[x].push_back(i), e[i].push_back(x);
    }
  }
  for (Pii i : l) {
    LL s = 0;
    int _ = exchange(p[i.first], -1e13);
    D(i.second, 0), s = max({s, g[i.second][0], g[i.second][1]});
    p[i.first] = _, _ = exchange(p[i.second], -1e13);
    D(i.first, 0), p[i.second] = _, ans += max(s, g[i.first][1]);
  }
  cout << ans;
  return 0;
}
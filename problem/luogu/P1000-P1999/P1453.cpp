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

const int kN = 1e5 + 1;

int n, p[kN], f[kN], l[2];
LL g[kN][2], ans;
vector<int> e[kN];
double k;

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
  for (int i = 1; i <= n; ++i) {
    cin >> p[i], f[i] = i;
  }
  for (int i = 1, x, y; i <= n; ++i) {
    cin >> x >> y;
    ++x, ++y;
    if (F(x) == F(y)) {
      l[0] = x, l[1] = y;
    } else {
      f[f[x]] = f[y], e[x].push_back(y), e[y].push_back(x);
    }
  }
  // cout << l[0] << ' ' << l[1] << '\n';
  for (int i = 0; i < 2; ++i) {
    int _ = exchange(p[l[i]], -1e9);
    D(l[!i], 0), ans = max({ans, g[l[!i]][0], g[l[!i]][1]});
    p[l[i]] = _;
  }
  cin >> k;
  cout << fixed << setprecision(1) << k * ans;
  return 0;
}
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

const int kN = 52, kM = 401;

int n, m, a[kN][kM], l[kN], c[kN][kN], p[kN];
vector<Pii> ans;

int B(int x) { return a[x][l[x]]; }
void M(int x, int y) { --c[x][B(x)], ++c[y][B(x)], a[y][++l[y]] = a[x][l[x]--], ans.emplace_back(x, y); }
void S(int x, int t1, int t0, int v) {
  for (; l[t1] + c[x][v] < m; M(t0, t1)) {
  }
  for (; l[t1] + c[x][v] > m; M(t1, t0)) {
  }
  for (; l[x]; M(x, B(x) == v ? t1 : t0)) {
  }
}
void M(int x, int y, int v) {
  for (; l[x] && l[y] < m && (B(x) == v || !v); M(x, y)) {
  }
}

int main() {
  // freopen("ball3.in", "r", stdin);
  // freopen("ball.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    l[i] = m, p[i] = i;
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      ++c[i][a[i][j]];
    }
  }
  p[n + 1] = n + 1;
  for (int i = 1; i < n - 1; ++i) {
    S(p[i], p[n], p[n + 1], i), S(p[i + 1], p[n + 1], p[i], i), swap(p[i], p[n]), swap(p[i + 1], p[n + 1]);
    for (int j = i; j < n; ++j) {
      S(p[j], p[n], p[n + 1], i), swap(p[j], p[n]), swap(p[n], p[n + 1]);
    }
    for (int j = i; j < n; ++j) {
      M(p[j], p[n + 1], i);
    }
    for (int j = i + 1; j < n; ++j) {
      M(p[i], p[j], 0);
    }
    swap(p[i], p[n + 1]);
  }
  S(p[n - 1], p[n], p[n + 1], n - 1);
  M(p[n], p[n - 1], n - 1), M(p[n + 1], p[n - 1], n), M(p[n + 1], p[n], 0), M(p[n - 1], p[n + 1], n);
  S(p[n], p[n - 1], p[n + 1], n - 1);
  cout << ans.size() << '\n';
  for (Pii &i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
  return 0;
}
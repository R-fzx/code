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

const int kN = 2e5 + 1, kK = 801;

int n, m, k, b[kK], l;
LL d[kK][kK];
pair<LL, Pii> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].second.first >> e[i].second.second >> e[i].first;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= k && i <= m; ++i) {
    b[++l] = e[i].second.first, b[++l] = e[i].second.second;
  }
  sort(b + 1, b + l + 1);
  l = unique(b + 1, b + l + 1) - b;
  for (int i = 1; i < l; ++i) {
    for (int j = 1; j < l; ++j) {
      d[i][j] = 1e18;
    }
  }
  for (int i = 1; i <= k && i <= m; ++i) {
    int x = lower_bound(b + 1, b + l, e[i].second.first) - b, y = lower_bound(b + 1, b + l, e[i].second.second) - b;
    d[x][y] = d[y][x] = min(d[x][y], e[i].first);
  }
  for (int k = 1; k < l; ++k) {
    for (int i = 1; i < l; ++i) {
      for (int j = 1; j < l; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  vector<LL> p;
  for (int i = 1; i < l; ++i) {
    for (int j = 1; j < i; ++j) {
      p.push_back(d[i][j]);
    }
  }
  sort(p.begin(), p.end());
  cout << p[k - 1];
  return 0;
}
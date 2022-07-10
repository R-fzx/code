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

const int kN = 4e6 + 1;

int n, m, k, l[kN][2], b[kN], s[kN], r, c, t;
vector<int> e[kN];

void D(int x) {
  l[x][0] = l[x][1] = ++r, b[x] = -1, s[++t] = x;
  for (int i : e[x]) {
    if (!b[i]) {
      D(i), l[x][1] = min(l[x][1], l[i][1]);
    } else if (!~b[i]) {
      l[x][1] = min(l[x][1], l[i][0]);
    }
  }
  if (l[x][0] == l[x][1]) {
    for (b[x] = ++c; s[t] != x; b[s[t--]] = c) {
    }
    --t;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    e[i].push_back(i + n * 2), e[i + n * 3].push_back(i + n);
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x + n].push_back(y), e[y + n].push_back(x);
  }
  for (int i = 1, c, p; i <= k; ++i) {
    cin >> c >> p;
    for (int j = 1, x; j < c; p = x, ++j) {
      cin >> x;
      e[p + n * 2].push_back(x + n * 2), e[x + n * 3].push_back(p + n * 3), e[x].push_back(p + n * 3), e[p + n * 2].push_back(x + n);
    }
  }
  for (int i = 1; i <= n * 4; ++i) {
    if (!b[i]) {
      D(i);
    }
  }
  bool f = 0;
  for (int i = 1; i <= n; ++i) {
    f |= b[i] == b[i + n];
  }
  cout << (f ? "NIE" : "TAK");
  return 0;
}
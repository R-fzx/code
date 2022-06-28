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

const int kN = 2e6 + 2;

int n, m, r, c, t, d[kN][2], s[kN], b[kN];
vector<int> e[kN], e2[kN];

void D(int x) {
  d[x][0] = d[x][1] = ++r, s[++t] = x, b[x] = -1;
  for (int i : e[x]) {
    if (!b[i]) {
      D(i), d[x][1] = min(d[x][1], d[i][1]);
    } else if (b[i] == -1) {
      d[x][1] = min(d[x][1], d[i][0]);
    }
  }
  if (d[x][0] == d[x][1]) {
    for (b[x] = ++c; s[t] != x; b[s[t--]] = c) {
    }
    --t;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y, a, b; i <= m; ++i) {
    cin >> x >> a >> y >> b;
    e[x + (a ^ 1) * n].push_back(y + b * n), e[y + (b ^ 1) * n].push_back(x + a * n);
  }
  for (int i = 1; i <= n * 2; ++i) {
    if (!b[i]) {
      D(i);
    }
  }
  bool f = 0;
  for (int i = 1; i <= n; ++i) {
    f |= b[i] == b[i + n];
  }
  if (f) {
    cout << "IMPOSSIBLE";
  } else {
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) {w
      cout << (b[i] > b[i + n]) << " ";
    }
  }
  return 0;
}
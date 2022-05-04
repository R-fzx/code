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

const int kN = 2e5 + 5;

int n, k, x, d[kN], p[kN], s[kN], t, c, ld[kN], q[kN], h = 1, pc[kN], a[kN];
vector<int> e[kN], e2[kN];
vector<vector<int>> l;
bool v[kN];

void D(int x) {
  p[x] = d[x] = ++c, s[++t] = x, v[x] = 1;
  for (int i : e[x]) {
    if (!d[i]) {
      D(i), p[x] = min(p[x], p[i]);
    } else if (v[i]) {
      p[x] = min(p[x], d[i]);
    }
  }
  if (p[x] == d[x]) {
    vector<int> _l;
    do {
      _l.push_back(s[t]), ld[s[t]] = l.size() + 1;
    } while (s[t--] != x);
    l.push_back(_l);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int _ = 0; _ < 2; ++_) {
    cin >> x;
    for (int i = 2, y; i <= n; ++i) {
      cin >> y;
      e[x].push_back(y), x = y;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!d[i]) {
      D(i);
    }
  }
  if (k > l.size()) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  int c = 0;
  for (int i = 0; i < l.size(); ++i) {
    c += l[i].size();
    for (auto &j : l[i]) {
      debug("%d:\n", j);
      for (int k : e[j]) {
        if (i + 1 != ld[k]) {
          debug("%d %d %d\n", i + 1, k, ld[k]);
          e2[i + 1].push_back(ld[k]), ++pc[ld[k]];
        }
      }
    }
    debug("\n");
  }
  debug("\n");
  if (c != n) {
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", ld[i]);
  }
  debug("\n");
  t = 0;
  for (int i = 1; i <= l.size(); ++i) {
    if (!pc[i]) {
      q[++t] = i;
    }
    for (int j : e2[i]) {
      debug("%d ", j);
    }
    debug("\n");
  }
  for (; h <= t; ++h) {
    for (int i : e2[q[h]]) {
      if (!--pc[i]) {
        q[++t] = i;
      }
    }
  }
  if (t != l.size()) {
    return 0;
  }
  for (int i = 1; i <= t; ++i) {
    debug("%d ", q[i]);
    for (int j : l[q[i] - 1]) {
      a[j] = min(i, k);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << char(a[i] - 1 + 'a');
  }
  return 0;
}
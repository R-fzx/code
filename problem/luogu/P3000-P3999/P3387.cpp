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

const int kN = 1e4 + 1;

int n, m, a[kN], b[kN], c, s[kN], t, l[kN][2], r, f[kN], v[kN];
vector<int> e[kN], e2[kN];

// -1: 访问过在栈中，0: 没访问过，>0: 所在scc编号
void D(int x) {
  l[x][0] = l[x][1] = ++r, s[++t] = x, b[x] = -1;
  for (int i : e[x]) {
    if (!b[i]) {  // 非返祖边
      D(i), l[x][1] = min(l[x][1], l[i][1]);
    } else if (b[i] == -1) {  // 返祖边
      l[x][1] = min(l[x][1], l[i][0]);
    }
  }
  if (l[x][0] == l[x][1]) {
    b[x] = ++c;
    for (; s[t] != x; b[s[t--]] = c) {
    }
    --t;
  }
}
int S(int x) {
  if (~f[x]) {
    return f[x];
  }
  f[x] = v[x];
  for (int i : e2[x]) {
    f[x] = max(f[x], S(i) + v[x]);
  }
  return f[x];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      D(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    v[b[i]] += a[i];
    for (int j : e[i]) {
      if (b[i] != b[j]) {
        e2[b[i]].push_back(b[j]);
      }
    }
  }
  f[0] = -1;
  for (int i = 1; i <= c; ++i) {
    e2[0].push_back(i), f[i] = -1;
  }
  cout << S(0);
  return 0;
}
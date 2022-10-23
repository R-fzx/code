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

const int kN = 5001;

int n, m, ans[kN], p[kN], t;
vector<int> e[kN];
bool v[kN];

void D(int x, int f, int _x, int _y) {
  if (v[x]) {
    return;
  }
  // cerr << x << ' ' << f << ' ' << _x << ' ' << _y << '\n';
  v[p[++t] = x] = 1;
  for (int i : e[x]) {
    if ((x != _x || i != _y) && (x != _y || i != _x) && i != f) {
      D(i, x, _x, _y);
    }
  }
}
void C(int x, int y) {
  // cerr << x << ' ' << y << '\n';
  fill_n(v + 1, n, 0), t = 0, D(1, 0, x, y);
  if (t == n) {
    int i = 1;
    for (; i <= n && p[i] == ans[i]; ++i) {
    }
    if (i <= n && p[i] < ans[i]) {
      for (i = 1; i <= n; ++i) {
        ans[i] = p[i];
      }
    }
  }
}
int R() {
  int x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
  }
  for (; isdigit(c); x = x * 10 + c - '0', c = getchar()) {
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  n = R(), m = R();
  ans[1] = 1e9;
  for (int i = 1, x, y; i <= m; ++i) {
    x = R(), y = R();
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
  }
  if (m == n - 1) {
    C(0, 0);
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j : e[i]) {
        C(i, j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
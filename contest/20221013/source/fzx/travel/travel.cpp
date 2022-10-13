#pragma GCC optimize("-Ofast")
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

const int kN = 1001, kM = 6001;

struct E {
  int x, y, l, r;
} _e[kM];
struct Q {
  int x, l, d;
  bool operator<(const Q &o) const {
    return d > o.d;
  }
};
int n, m, b[kM], v, d[kN][kM];
vector<E> e[kN];
priority_queue<Q> q;

void R(int x, int l, int s) {
  if (s > d[x][l]) {
    d[x][l] = s, q.push({x, l, s});
  }
}

int main() {
  RF("travel");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y, l, r; i <= m; ++i) {
    cin >> _e[i].x >> _e[i].y >> _e[i].l >> _e[i].r;
    b[i] = _e[i].l, b[i + m] = _e[i].r;
  }
  sort(b + 1, b + m + m + 1), v = unique(b + 1, b + m + m + 1) - b - 1;
  for (int i = 1; i <= m; ++i) {
    _e[i].l = lower_bound(b + 1, b + v + 1, _e[i].l) - b;
    _e[i].r = lower_bound(b + 1, b + v + 1, _e[i].r) - b;
    e[_e[i].x].push_back(_e[i]), e[_e[i].y].push_back({_e[i].y, _e[i].x, _e[i].l, _e[i].r});
  }
  for (R(1, 1, v); !q.empty();) {
    Q x = q.top();
    q.pop();
    for (E i : e[x.x]) {
      if (i.l > x.l) {
        R(i.y, i.l, min(i.r, x.l + x.d - 1) - i.l + 1);
      } else {
        R(i.y, x.l, min(i.r, x.l + x.d - 1) - x.l + 1);
      }
    }
  }
  int ml = 1;
  for (int i = 2; i <= v; ++i) {
    if (b[i + d[n][i] - 1] - b[i] > b[ml + d[n][ml] - 1] - b[ml]) {
      ml = i;
    }
  }
  cout << max(0, b[ml + d[n][ml] - 1] - b[ml] + 1) << '\n';
  for (int i = b[ml]; i <= b[ml + d[n][ml] - 1]; ++i) {
    cout << i << ' ';
  }
  return 0;
}
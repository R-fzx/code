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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 2e5 + 1;

struct R {
  int u, d, l, r;
} a[kN];
struct E {
  int x, d, i;
  bool operator<(const E &o) const {
    return x < o.x || x == o.x && d > o.d;
  }
} l[kN << 1];
struct T {
  LL d, s, t;
} e[kN << 3];
int n, m, p[kN << 1], _t;
LL ans;

void Build(int x, Pll o) {
  if (o.first + 1 == o.second) {
    e[x].d = p[o.second] - p[o.first];
    return;
  }
  LL m = o.first + o.second >> 1;
  Build(x * 2, {o.first, m}), Build(x * 2 + 1, {m, o.second});
  e[x].d = e[x * 2].d + e[x * 2 + 1].d;
}
void Do(int ty, int x, Pll o, Pll t) {
  if (t.first == t.second || o.first == o.second) {
    return;
  }
  if (o == t) {
    e[x].t += ty, e[x].s = e[x].t ? e[x].d : e[x * 2].s + e[x * 2 + 1].s;
    return;
  }
  LL m = o.first + o.second >> 1;
  if (t.first <= m) {
    Do(ty, x * 2, {o.first, m}, {t.first, min(m, t.second)});
  }
  if (m <= t.second) {
    Do(ty, x * 2 + 1, {m, o.second}, {max(m, t.first), t.second});
  }
  e[x].s = e[x].t ? e[x].d : e[x * 2].s + e[x * 2 + 1].s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].d >> a[i].r >> a[i].u;
    l[i] = {a[i].l, 1, i}, l[i + n] = {a[i].r, -1, i}, p[i] = a[i].d, p[i + n] = a[i].u;
  }
  sort(l + 1, l + n * 2 + 1), sort(p + 1, p + n * 2 + 1), m = unique(p + 1, p + n * 2 + 1) - p - 1, Build(1, {1, m});
  for (int i = 1; i <= n; ++i) {
    a[i].d = lower_bound(p + 1, p + m + 1, a[i].d) - p, a[i].u = lower_bound(p + 1, p + m + 1, a[i].u) - p;
  }
  for (int i = 1; i <= n * 2; ++i) {
    ans += e[1].s * (l[i].x - l[i - 1].x);
    Do(l[i].d, 1, {1, m}, {a[l[i].i].d, a[l[i].i].u});
  }
  cout << ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
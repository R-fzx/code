#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e4 + 1;

struct E {
  LL x, y1, y2, v;
} a[kN << 1];
struct L {
  LL x, i, v;
  bool operator<(const L &o) const {
    return x < o.x || x == o.x && v < o.v;
  }
} l[kN << 1];
struct T {
  LL m, a;
} e[kN << 3];
int t, n, w, h, p[kN << 1], m;
LL ans;

void Do(int x, Pll o, Pll t, LL v) {
  if (o == t) {
    e[x].m += v, e[x].a += v;
    return;
  }
  LL m = o.first + o.second >> 1;
  if (t.first <= m) {
    Do(x * 2, {o.first, m}, {t.first, min(t.second, m)}, v);
  }
  if (m < t.second) {
    Do(x * 2 + 1, {m + 1, o.second}, {max(t.first, m + 1), t.second}, v);
  }
  e[x].m = max(e[x * 2].m, e[x * 2 + 1].m) + e[x].a;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> w >> h;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].x >> a[i].y1 >> a[i].v;
      l[i] = {a[i].x, i, a[i].v}, l[i + n] = {a[i].x + w, i, -a[i].v}, p[i] = a[i].y1, p[i + n] = a[i].y1 + h - 1;
    }
    sort(l + 1, l + n * 2 + 1), sort(p + 1, p + n * 2 + 1), m = unique(p + 1, p + n * 2 + 1) - p;
    for (int i = 1; i <= n; ++i) {
      a[i].y2 = lower_bound(p + 1, p + m, a[i].y1 + h - 1) - p, a[i].y1 = lower_bound(p + 1, p + m, a[i].y1) - p;
    }
    ans = 0;
    for (int i = 1; i <= n * 2; ++i) {
      Do(1, {1, n * 2}, {a[l[i].i].y1, a[l[i].i].y2}, l[i].v);
      ans = max(ans, e[1].m);
    }
    cout << ans << endl;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
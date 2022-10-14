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

const int kN = 1001, kM = 3001;

struct E {
  int x, y, l, r;

  bool operator<(const E &o) const { return tie(r, l, x, y) > tie(o.r, o.l, o.x, o.y); }
} e[kM];
int n, m, f[kN];
Pii ans;
set<E> l;

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  RF("travel");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].l >> e[i].r;
  }
  sort(e + 1, e + m + 1, [](E i, E j) { return i.l < j.l; });
  for (int i = 1, j = 1; i <= m; i = j) {
    for (; j <= m && e[j].l == e[i].l; l.insert(e[j]), ++j) {
    }
    iota(f + 1, f + n + 1, 1);
    // cout << i << ' ' << j << ' ' << e[i].x << ' ' << e[i].y << ' ' << e[i].l << ' ' << e[i].r << '\n';
    for (auto p = l.begin(), k = p; p != l.end(); p = k) {
      // cout << p->x << ' ' << p->y << ' ' << p->l << ' ' << p->r << '\n';
      for (; k != l.end() && k->r == p->r; f[F(k->x)] = F(k->y), ++k) {
        // cout << k->x << ' ' << k->y << ' ' << k->l << ' ' << k->r << '\n';
      }
      // cout << '\n';
      if (F(1) == F(n)) {
        ans = max(ans, {p->r - e[i].l + 1, -e[i].l});
        break;
      }
    }
  }
  cout << ans.first << '\n';
  for (int i = 0; i < ans.first; ++i) {
    cout << i - ans.second << ' ';
  }
  return 0;
}
/*
4 4
1 2 1 5
1 3 6 10
2 4 2 5
3 4 7 10
*/
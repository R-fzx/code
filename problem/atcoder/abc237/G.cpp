#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 2e5 + 1;

int n, q, x, a[kN];
struct T {
  struct E {
    int s, t = -1;
  } e[kN << 2];

  void Build(int x, int l, int r, int d) {
    if (l == r) {
      e[x].s = (a[l] >= ::x + d);
      return;
    }
    int m = l + r >> 1;
    Build(x * 2, l, m, d), Build(x * 2 + 1, m + 1, r, d);
    e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  }
  void E(int x, int l, int r, int v) {
    if (~v) {
      e[x].s = v * (r - l + 1), e[x].t = v;
    }
  }
  Pii Do(int x, int l, int r, int tl, int tr, int v) {
    if (tl > tr) {
      return {0, 0};
    }
    if (l == tl && r == tr) {
      E(x, l, r, v);
      return {r - l + 1 - e[x].s, e[x].s};
    }
    int m = l + r >> 1;
    E(x * 2, l, m, e[x].t), E(x * 2 + 1, m + 1, r, e[x].t), e[x].t = -1;
    Pii ans = {0, 0};
    if (tl <= m) {
      Pii p = Do(x * 2, l, m, tl, min(tr, m), v);
      ans.first += p.first, ans.second += p.second;
    }
    if (m < tr) {
      Pii p = Do(x * 2 + 1, m + 1, r, max(tl, m + 1), tr, v);
      ans.first += p.first, ans.second += p.second;
    }
    e[x].s = e[x * 2].s + e[x * 2 + 1].s;
    return ans;
  }
} t[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  t[0].Build(1, 1, n, 0), t[1].Build(1, 1, n, 1);
  while (q--) {
    int o, l, r;
    cin >> o >> l >> r;
    if (o == 1) {
      Pii p = t[0].Do(1, 1, n, l, r, -1);
      t[0].Do(1, 1, n, l, l + p.first - 1, 0), t[0].Do(1, 1, n, l + p.first, r, 1);
      p = t[1].Do(1, 1, n, l, r, -1);
      t[1].Do(1, 1, n, l, l + p.first - 1, 0), t[1].Do(1, 1, n, l + p.first, r, 1);
    } else {
      Pii p = t[0].Do(1, 1, n, l, r, -1);
      t[0].Do(1, 1, n, l, l + p.second - 1, 1), t[0].Do(1, 1, n, l + p.second, r, 0);
      p = t[1].Do(1, 1, n, l, r, -1);
      t[1].Do(1, 1, n, l, l + p.second - 1, 1), t[1].Do(1, 1, n, l + p.second, r, 0);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (t[0].Do(1, 1, n, i, i, -1).second && !t[1].Do(1, 1, n, i, i, -1).second) {
      cout << i;
      break;
    }
  }
  return 0;
}
/*
y=x -> y>=x && !(y>=x+1)
*/
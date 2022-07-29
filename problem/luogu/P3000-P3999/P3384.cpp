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

const int kN = 1e5 + 1;

struct T {
  LL s, b;
} e[kN << 4];
struct E {
  int f, s, d, h, t, i;
  LL a, _a;
  vector<int> n;
} a[kN];
int n, m, r, p, c;

void I(int x, int f) {
  a[x].f = f, a[x].d = a[f].d + 1, a[x].s = 1;
  for (int i : a[x].n) {
    if (i != f) {
      I(i, x), a[x].s += a[i].s;
      if (a[i].s > a[a[x].h].s) {
        a[x].h = i;
      }
    }
  }
}
void G(int x, int t) {
  a[a[x].i = ++c]._a = a[x].a, a[x].t = t;
  if (a[x].h) {
    G(a[x].h, t);
  }
  for (int i : a[x].n) {
    if (i != a[x].f && i != a[x].h) {
      G(i, i);
    }
  }
}
void A(int x, int l, int r, LL v) {
  e[x].s = (e[x].s + (r - l + 1) * v) % p, e[x].b = (e[x].b + v) % p;
}
void B(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l]._a;
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  e[x].s = (e[x * 2].s + e[x * 2 + 1].s) % p;
}
LL U(int x, int l, int r, int tl, int tr, LL v) {
  if (l == tl && r == tr) {
    A(x, l, r, v);
    return e[x].s;
  }
  int m = l + r >> 1;
  LL s = 0;
  A(x * 2, l, m, e[x].b), A(x * 2 + 1, m + 1, r, e[x].b), e[x].b = 0;
  if (tl <= m) {
    s = (s + U(x * 2, l, m, tl, min(m, tr), v)) % p;
  }
  if (m < tr) {
    s = (s + U(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v)) % p;
  }
  e[x].s = (e[x * 2].s + e[x * 2 + 1].s) % p;
  return s;
}

int main() {
  // freopen("P3384_2.in", "r", stdin);
  // freopen("P3384.out", "w", stdout);
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> r >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].a;
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    a[x].n.push_back(y), a[y].n.push_back(x);
  }
  I(r, 0), G(r, r);
  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i].h << " " << a[i].t << " " << a[i].i << '\n';
  // }1
  B(1, 1, n);
  for (int o, x, y, z; m--; ) {
    cin >> o >> x;
    if (o == 1) {
      cin >> y >> z;
      for (; a[x].t != a[y].t; x = a[a[x].t].f) {
        if (a[a[x].t].d < a[a[y].t].d) {
          swap(x, y);
        }
        U(1, 1, n, a[a[x].t].i, a[x].i, z);
      }
      if (a[x].i < a[y].i) {
        swap(x, y);
      }
      U(1, 1, n, a[y].i, a[x].i, z);
    } else if (o == 2) {
      cin >> y;
      LL s = 0;
      for (; a[x].t != a[y].t; x = a[a[x].t].f) {
        if (a[a[x].t].d < a[a[y].t].d) {
          swap(x, y);
        }
        s = (s + U(1, 1, n, a[a[x].t].i, a[x].i, 0)) % p;
      }
      if (a[x].i < a[y].i) {
        swap(x, y);
      }
      cout << (s + U(1, 1, n, a[y].i, a[x].i, 0)) % p << '\n';
    } else if (o == 3) {
      cin >> z;
      U(1, 1, n, a[x].i, a[x].i + a[x].s - 1, z);
    } else {
      cout << U(1, 1, n, a[x].i, a[x].i + a[x].s - 1, 0) << '\n';
    }
    // for (int i = 1; i <= n; ++i) {
    //   cout << U(1, 1, n, a[i].i, a[i].i, 0) << ' ';
    // }
    // cout << '\n';
  }
  return 0;
}
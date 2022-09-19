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

struct E {
  int s, lc[2], rc[2], c[2], ta = -1;
  bool tr;
} e[kN << 2];
struct Q {
  int x, l, r;
  Q() {}
  Q(int x, int l, int r) : x(x), l(l), r(r) {}
};
int n, q;

void A(int x, int l, int r, int v) {
  int p = r - l + 1, g0 = !v * p, g1 = v * p;
  e[x] = {g1, {g0, g1}, {g0, g1}, {g0, g1}, v, 0};
}
void R(int x, int l, int r) {
  int p = r - l + 1;
  e[x].s = p - e[x].s, swap(e[x].lc[0], e[x].lc[1]), swap(e[x].rc[0], e[x].rc[1]), swap(e[x].c[0], e[x].c[1]), e[x].tr ^= 1;
}
void Pu(int x, int l, int m, int r) {
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  for (int k = 0; k < 2; ++k) {
    e[x].lc[k] = e[x * 2].lc[k] + e[x * 2 + 1].lc[k] * (e[x * 2].lc[k] == m - l + 1);
    e[x].rc[k] = e[x * 2 + 1].rc[k] + e[x * 2].rc[k] * (e[x * 2 + 1].rc[k] == r - m);
    e[x].c[k] = max({e[x * 2].rc[k] + e[x * 2 + 1].lc[k], e[x * 2].c[k], e[x * 2 + 1].c[k]});
  }
}
void Pd(int x, int l, int m, int r) {
  ~e[x].ta && (A(x * 2, l, m, e[x].ta), A(x * 2 + 1, m + 1, r, e[x].ta), e[x].ta = -1);
  e[x].tr && (R(x * 2, l, m), R(x * 2 + 1, m + 1, r), e[x].tr = 0);
}
void B(int x, int l, int r) {
  if (l == r) {
    cin >> e[x].s;
    e[x].lc[e[x].s] = e[x].rc[e[x].s] = e[x].c[e[x].s] = 1;
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  Pu(x, l, m, r);
}
void Assign(int x, int l, int r, int tl, int tr, int v) {
  if (l == tl && r == tr) {
    A(x, l, r, v);
    return;
  }
  int m = l + r >> 1;
  Pd(x, l, m, r);
  if (tl <= m) {
    Assign(x * 2, l, m, tl, min(m, tr), v);
  }
  if (m < tr) {
    Assign(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  Pu(x, l, m, r);
}
void Rev(int x, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    R(x, l, r);
    return;
  }
  int m = l + r >> 1;
  Pd(x, l, m, r);
  if (tl <= m) {
    Rev(x * 2, l, m, tl, min(m, tr));
  }
  if (m < tr) {
    Rev(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
  }
  Pu(x, l, m, r);
}
int Sum(int x, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    return e[x].s;
  }
  int m = l + r >> 1, s = 0;
  Pd(x, l, m, r);
  if (tl <= m) {
    s += Sum(x * 2, l, m, tl, min(m, tr));
  }
  if (m < tr) {
    s += Sum(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
  }
  Pu(x, l, m, r);
  return s;
}
void Query(int x, int l, int r, int tl, int tr, vector<Q> &s) {
  if (l == tl && r == tr) {
    s.emplace_back(x, l, r);
    return;
  }
  int m = l + r >> 1;
  Pd(x, l, m, r);
  if (tl <= m) {
    Query(x * 2, l, m, tl, min(m, tr), s);
  }
  if (m < tr) {
    Query(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, s);
  }
  Pu(x, l, m, r);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  B(1, 1, n);
  for (int o, l, r; q--;) {
    cin >> o >> l >> r;
    ++l, ++r;
    if (o == 0) {
      Assign(1, 1, n, l, r, 0);
    } else if (o == 1) {
      Assign(1, 1, n, l, r, 1);
    } else if (o == 2) {
      Rev(1, 1, n, l, r);
    } else if (o == 3) {
      cout << Sum(1, 1, n, l, r) << '\n';
    } else {
      vector<Q> s;
      Query(1, 1, n, l, r, s);
      // for (Q i : s) {
      //   cout << i.x << ' ' << i.l << ' ' << i.r << '\n';
      // }
      // cout << '\n';
      int ans = 0;
      for (Q i : s) {
        ans = max(ans, e[i.x].c[1]);
      }
      for (int i = 0, j = 0; i < s.size(); i = j) {
        int v = e[s[i].x].rc[1];
        for (++j; j < s.size() && e[s[j].x].lc[1] == s[j].r - s[j].l + 1; v += e[s[j].x].lc[1], ++j) {
        }
        if (j < s.size()) {
          v += e[s[j].x].lc[1];
        }
        ans = max(ans, v);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
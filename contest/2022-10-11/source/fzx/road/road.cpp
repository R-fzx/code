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

const int kN = 201, kM = 50001;

struct LCT {
  struct E {
    int f, c[2], v, s;
    bool r;
  } e[kN + kM];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) {
    e[x].s = max({Pii{e[x].v, x}, Pii{e[e[e[x].c[0]].s].v, e[e[x].c[0]].s}, Pii{e[e[e[x].c[1]].s].v, e[e[x].c[1]].s}}).second;
  }
  void Pr(int x) { e[x].r ^= 1, swap(e[x].c[0], e[x].c[1]); }
  void Pd(int x) {
    if (e[x].r) {
      Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0;
    }
  }
  void R(int x) {
    int y = e[x].f, z = e[y].f, k = W(x), w = e[x].c[!k];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[k] = w, e[x].c[!k] = y;
    if (w) {
      e[w].f = y;
    }
    e[y].f = x, e[x].f = z, Pu(y);
  }
  void S(int x) {
    int y, z = 0;
    static int l[kN + kM];
    for (y = x; nR(y); l[++z] = y, y = e[y].f) {
    }
    for (Pd(y); z; Pd(l[z--])) {
    }
    for (; nR(x); R(x)) {
      y = e[x].f;
      if (nR(y)) {
        R(W(x) == W(y) ? y : x);
      }
    }
    Pu(x);
  }
  void A(int x) {
    for (int y = 0; x; y = x, x = e[x].f) {
      S(x), e[x].c[1] = y, Pu(x);
    }
  }
  void M(int x) { A(x), S(x), Pr(x); }
  void S(int x, int y) { M(x), A(y), S(y); }
  void L(int x, int y) { M(x), e[x].f = y; }
  void C(int x, int y) { S(x, y), e[x].f = e[y].c[0] = 0, Pu(y); }
} t;
struct E {
  int x, y;
  LL p, q;

  bool operator<(const E &o) const { return p < o.p; }
} e[kM];
int n, m, f[kN], c;
LL p, q, ans = 1e18;

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }
void L(int i) { t.L(e[i].x, n + i), t.L(n + i, e[i].y); }
void C(int i) { t.C(e[i].x, n + i), t.C(n + i, e[i].y); }

int main() {
  RF("road");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> p >> q;
  iota(f + 1, f + n + 1, 1);
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].p >> e[i].q;
  }
  sort(e + 1, e + m + 1);
  for (int i = 1, j = 1; i <= m; i = j) {
    for (; j <= m && e[j].p == e[i].p; ++j) {
      t.e[n + j].v = e[j].q;
      int rx = F(e[j].x), ry = F(e[j].y);
      if (rx == ry) {
        t.S(e[j].x, e[j].y);
        if (t.e[t.e[e[j].y].s].v > e[j].q) {
          C(t.e[e[j].y].s - n), L(j);
        }
      } else {
        ++c, f[rx] = ry, L(j);
      }
    }
    if (c == n - 1) {
      int mq = 0;
      for (int j = 2; j <= n; ++j) {
        t.S(1, j);
        mq = max(mq, t.e[t.e[j].s].v);
      }
      ans = min(ans, p * e[i].p + q * mq);
    }
  }
  cout << (c == n - 1 ? ans : -1);
  return 0;
}
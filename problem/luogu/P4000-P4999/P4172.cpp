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

const int kN = 1e3 + 1, kM = 1e5 + 1;

struct LCT {
  struct E {
    int v, f, c[2];
    Pii s;
    bool r;
  } e[kN + kM];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) {
    Pii b[3] = {{e[x].v, x}, e[e[x].c[0]].s, e[e[x].c[1]].s};
    sort(b, b + 3), e[x].s = b[2];
  }
  void Pr(int x) { e[x].r ^= 1, swap(e[x].c[0], e[x].c[1]); }
  void Pd(int x) { e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0); }
  void R(int x) {
    int y = e[x].f, z = e[y].f, w = W(x), k = e[x].c[!w];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[w] = k, e[x].c[!w] = y;
    if (k) {
      e[k].f = y;
    }
    e[y].f = x, e[x].f = z, Pu(y);
  }
  void S(int x) {
    int y = x, z = 0;
    static int l[kN + kM];
    for (; nR(y); l[++z] = y, y = e[y].f) {
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
  int F(int x) {
    A(x), S(x);
    for (; e[x].c[0]; Pd(x), x = e[x].c[0]) {
    }
    S(x);
    return x;
  }
  void S(int x, int y) { M(x), A(y), S(y); }
  void L(int x, int y) { M(x), e[x].f = y; }
  void C(int x, int y) { S(x, y), e[x].f = e[y].c[0] = 0, Pu(y); }
} t;
struct E {
  int x, y, w;
  bool v;
} e[kM];
struct Q {
  int o, x, y, s;
} l[kN];
int n, m, q;
map<Pii, int> f;

void C(int i) { t.C(e[i].x, n + i), t.C(n + i, e[i].y); }
void L(int i) {
  if (t.F(e[i].x) != t.F(e[i].y)) {
    t.L(e[i].x, n + i), t.L(n + i, e[i].y);
  } else {
    t.S(e[i].x, e[i].y);
    if (t.e[e[i].y].s.first >= e[i].w) {
      C(t.e[e[i].y].s.second - n), t.L(e[i].x, n + i), t.L(n + i, e[i].y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y >> e[i].w;
    t.e[n + i].v = e[i].w, f[make_pair(e[i].x, e[i].y)] = f[make_pair(e[i].y, e[i].x)] = i;
  }
  for (int i = 1; i <= q; ++i) {
    cin >> l[i].o >> l[i].x >> l[i].y;
    if (l[i].o == 2) {
      e[l[i].s = f[make_pair(l[i].x, l[i].y)]].v = 1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!e[i].v) {
      L(i);
    }
  }
  for (int i = q; i >= 1; --i) {
    if (l[i].o == 1) {
      t.S(l[i].x, l[i].y), l[i].s = t.e[l[i].y].s.first;
    } else {
      L(l[i].s);
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (l[i].o == 1) {
      cout << l[i].s << '\n';
    }
  }
  return 0;
}
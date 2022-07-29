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

const int kC = 10;

struct LCT {
  static const int kN = 1e4 + 1;

  struct E {
    int f, c[2], v, s;
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) { e[x].s = max({e[x].v, e[e[x].c[0]].s, e[e[x].c[1]].s}); }
  void Pr(int x) { swap(e[x].c[0], e[x].c[1]), e[x].r ^= 1; }
  void Pd(int x) { e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0); }
  void R(int x) {
    if (nR(x)) {
      int y = e[x].f, z = e[y].f, k = W(x), w = e[x].c[!k];
      if (nR(y)) {
        e[z].c[W(y)] = x;
      }
      e[y].c[k] = w, e[x].c[!k] = y;
      if (w) {
        e[w].f = y;
      }
      e[x].f = z, e[y].f = x, Pu(y), Pu(x);
    }
  }
  void S(int x) {
    static int st[kN];
    int y, z = 0;
    for (y = x; nR(y); st[++z] = y, y = e[y].f) {
    }
    for (Pd(y); z; Pd(st[z--])) {
    }
    for (; nR(x); R(x)) {
      y = e[x].f;
      if (nR(y)) {
        R(W(x) == W(y) ? y : x);
      }
    }
  }
  void A(int x) {
    for (int y = 0; x; y = x, x = e[x].f) {
      S(x), e[x].c[1] = y, Pu(x);
    }
  }
  void M(int x) {
    A(x), S(x), Pr(x);
  }
  int F(int x) {
    for (A(x), S(x); e[x].c[0]; Pd(x), x = e[x].c[0]) {
    }
    S(x);
    return x;
  }
  void S(int x, int y) {
    M(x), A(y), S(y);
  }
  void L(int x, int y) {
    M(x);
    if (F(y) != x) {
      e[x].f = y;
    }
  }
} t[kC];
int n, m, c, q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}
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

struct LCT {
  struct E {
    int vc, lc, rc, cc, f, c[2], tc;
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pr(int x) { e[x].r ^= 1, swap(e[x].c[0], e[x].c[1]), swap(e[x].lc, e[x].rc); }
  void Pc(int x, int c) { x && (e[x].tc = e[x].lc = e[x].rc = e[x].vc = c, e[x].cc = 1); }
  void Pd(int x) {
    e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0);
    e[x].tc && (Pc(e[x].c[0], e[x].tc), Pc(e[x].c[1], e[x].tc), e[x].tc = 0);
  }
  void Pu(int x) {
    e[x].lc = (e[x].c[0] ? e[e[x].c[0]].lc : e[x].vc), e[x].rc = (e[x].c[1] ? e[e[x].c[1]].rc : e[x].vc);
    e[x].cc = e[e[x].c[0]].cc + e[e[x].c[1]].cc + 1 - (e[x].c[0] && e[e[x].c[0]].rc == e[x].vc) - (e[x].c[1] && e[e[x].c[1]].lc == e[x].vc);
  }
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
    static int l[kN];
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
  void S(int x, int y) { M(x), A(y), S(y); }
  void L(int x, int y) { M(x), e[x].f = y; }
} t;

int n, q, x, y, c;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    t.Pc(i, x);
  }
  // for (int i = 1; i <= n; ++i) {
  //   debug("vc=%d lc=%d rc=%d cc=%d f=%d c0=%d c1=%d tc=%d r=%d\n", t.e[i].vc, t.e[i].lc, t.e[i].rc, t.e[i].cc, t.e[i].f, t.e[i].c[0], t.e[i].c[1], t.e[i].tc, t.e[i].r);
  // }
  // debug("====================================================\n");
  for (int i = 1; i < n; ++i) {
    cin >> x >> y;
    t.L(x, y);
  }
  // for (int i = 1; i <= n; ++i) {
  //   debug("vc=%d lc=%d rc=%d cc=%d f=%d c0=%d c1=%d tc=%d r=%d\n", t.e[i].vc, t.e[i].lc, t.e[i].rc, t.e[i].cc, t.e[i].f, t.e[i].c[0], t.e[i].c[1], t.e[i].tc, t.e[i].r);
  // }
  // debug("====================================================\n");
  for (char o; q--;) {
    cin >> o >> x >> y;
    t.S(x, y);
    // for (int i = 1; i <= n; ++i) {
    //   debug("vc=%d lc=%d rc=%d cc=%d f=%d c0=%d c1=%d tc=%d r=%d\n", t.e[i].vc, t.e[i].lc, t.e[i].rc, t.e[i].cc, t.e[i].f, t.e[i].c[0], t.e[i].c[1], t.e[i].tc, t.e[i].r);
    // }
    // debug("====================================================\n");
    if (o == 'C') {
      cin >> c;
      t.Pc(y, c);
    } else {
      cout << t.e[y].cc << '\n';
    }
  }
  return 0;
}
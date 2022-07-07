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

struct LCT {
  static const int kN = 1e4 + 1;

  struct E {
    int f, c[2];
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pr(int x) { swap(e[x].c[0], e[x].c[1]), e[x].r ^= 1; }
  void Pd(int x) { e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0); }
  void R(int x) {
    int y = e[x].f, z = e[y].f, k = W(x), w = e[x].c[!k];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[k] = w, e[x].c[!k] = y;
    if (w) {
      e[w].f = y;
    }
    e[x].f = z, e[y].f = x;
  }
  void S(int x) {
    static int s[kN];
    int y, z = 0;
    for (y = x; nR(y); s[++z] = y, y = e[y].f) {
    }
    for (Pd(y); z; Pd(s[z--])) {
    }
    for (; nR(x); R(x)) {
      y = e[x].f, z = e[y].f;
      if (nR(y)) {
        R(W(x) == W(y) ? y : x);
      }
    }
  }
  void A(int x) {
    for (int y = 0; x; y = x, x = e[x].f) {
      S(x), e[x].c[1] = y;
    }
  }
  void M(int x) { A(x), S(x), Pr(x); }
  int F(int x) {
    A(x), S(x);
    for (; e[x].c[0]; x = e[x].c[0]) {
    }
    S(x);
    return x;
  }
  void L(int x, int y) {
    M(x);
    if (F(y) != x) {
      e[x].f = y;
    }
  }
  void C(int x, int y) {
    M(x);
    if (F(y) == x && e[y].f == x && !e[y].c[0]) {
      e[y].f = e[x].c[1] = 0;
    }
  }
} t;
int n, m, x, y;
string o;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> n >> m; m--; ) {
    cin >> o >> x >> y;
    if (o == "Connect") {
      t.L(x, y);
    } else if (o == "Destroy") {
      t.C(x, y);
    } else {
      cout << (t.F(x) == t.F(y) ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
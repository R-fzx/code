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
    int s, f, c[2];
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) { e[x].s = e[e[x].c[0]].s + e[e[x].c[1]].s + 1; }
  void Pr(int x) { swap(e[x].c[0], e[x].c[1]), e[x].r ^= 1; }
  void Pd(int x) { e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0); }
  void R(int x) {
    int y = e[x].f, z = e[y].f, w = W(x), u = e[x].c[!w];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[w] = u, e[x].c[!w] = y;
    if (u) {
      e[u].f = y;
    }
    e[y].f = x, e[x].f = z, Pu(y);
  }
  void S(int x) {
    int y, z = 0;
    static int l[kN];
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
} t[2];
int n, q, a[kN];
vector<int> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x), t[0].L(x, y);
  }
  cin >> q;
  for (int o, x; q--; ) {
    cin >> o >> x;
    if (o) {
      for (int i : e[x]) {
        if (a[i] == a[x]) {
          t[a[x]].C(i, x);
        } else {
          t[a[i]].L(i, x);
        }
      }
      a[x] ^= 1;
    } else {
      t[a[x]].M(x);
      cout << t[a[x]].e[x].s << '\n';
    }
  }
  return 0;
}
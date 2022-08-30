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

const int kC = 10, kN = 1e4 + 1;

struct LCT {
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
  void M(int x) { A(x), S(x), Pr(x); }
  int F(int x) {
    for (A(x), S(x); e[x].c[0]; Pd(x), x = e[x].c[0]) {
    }
    S(x);
    return x;
  }
  void S(int x, int y) { M(x), A(y), S(y); }
  void L(int x, int y) { M(x), e[x].f = y; }
  void C(int x, int y) { S(x, y), e[x].f = e[y].c[0] = 0, Pu(y); }
} t[kC];
int n, m, c, q, d[kC][kN];
unordered_map<int, int> e[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> c >> q;
  // cout << '1' << endl;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    for (int j = 0; j < c; ++j) {
      t[j].e[i].v = x;
    }
  }
  // cout << '2' << endl;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    e[x][y] = e[y][x] = w, t[w].L(x, y), ++d[w][x], ++d[w][y];
  }
  // cout << '3' << endl;
  for (int o, x, y, w; q--;) {
    cin >> o >> x >> y;
    if (o == 0) {
      for (int i = 0; i < c; ++i) {
        t[i].S(x), t[i].e[x].v = y;
      }
    } else if (o == 1) {
      cin >> w;
      if (e[x].find(y) == e[x].end()) {
        cout << "No such edge.\n";
      } else if (w == e[x][y]) {
        cout << "Success.\n";
      } else if (d[w][x] == 2 || d[w][y] == 2) {
        cout << "Error 1.\n";
      } else if (t[w].F(x) == t[w].F(y)) {
        cout << "Error 2.\n";
      } else {
        cout << "Success.\n";
        int v = e[x][y];
        t[v].C(x, y), --d[v][x], --d[v][y], e[x][y] = e[y][x] = w, t[w].L(x, y), ++d[w][x], ++d[w][y];
      }
    } else {
      w = x, x = y;
      cin >> y;
      if (t[w].F(x) != t[w].F(y)) {
        cout << "-1\n";
      } else {
        t[w].S(x, y);
        cout << t[w].e[y].s << '\n';
      }
    }
  }
  return 0;
}
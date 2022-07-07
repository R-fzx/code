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

const LL kM = 51061;

struct LCT {
  static const int kN = 1e5 + 1;

  struct E {
    int f, c[2], sz;
    LL v = 1, s, a, m = 1;
    bool r;
  } e[kN];

  int W(int x) { return e[e[x].f].c[1] == x; }
  bool nR(int x) { return e[e[x].f].c[W(x)] == x; }
  void Pu(int x) { e[x].s = (e[e[x].c[0]].s + e[e[x].c[1]].s + e[x].v) % kM, e[x].sz = e[e[x].c[0]].sz + e[e[x].c[1]].sz + 1; }
  void Pr(int x) { swap(e[x].c[0], e[x].c[1]), e[x].r ^= 1; }
  void Pa(int x, LL v) { e[x].s = (e[x].s + v * e[x].sz) % kM, e[x].v = (e[x].v + v) % kM, e[x].a = (e[x].a + v) % kM; }
  void Pm(int x, LL v) { e[x].s = e[x].s * v % kM, e[x].v = e[x].v * v % kM, e[x].a = e[x].a * v % kM, e[x].m = e[x].m * v % kM; }
  void Pd(int x) {
    e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0);
    Pm(e[x].c[0], e[x].m), Pm(e[x].c[1], e[x].m), e[x].m = 1;
    Pa(e[x].c[0], e[x].a), Pa(e[x].c[1], e[x].a), e[x].a = 0;
  }
  void R(int x) {
    int y = e[x].f, z = e[y].f, w = W(x), u = e[x].c[!w];
    if (nR(y)) {
      e[z].c[W(y)] = x;
    }
    e[y].c[w] = u, e[x].c[!w] = y;
    if (u) {
      e[u].f = y;
    }
    e[x].f = z, e[y].f = x, Pu(y), Pu(x);
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
      S(x), e[x].c[1] = y, Pu(x);
    }
  }
  void M(int x) { A(x), S(x), Pr(x); }
  void S(int x, int y) { M(x), A(y), S(y); }
  void L(int x, int y) { M(x), e[x].f = y; }
  void C(int x, int y) { S(x, y), e[x].f = e[y].c[0] = 0; }
} t;
int n, q, a, b, c, d;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    t.L(a, b);
  }
  for (char o; q--; ) {
    cin >> o >> a >> b;
    if (o == '+') {
      cin >> c;
      t.S(a, b), t.Pa(b, c);
    } else if (o == '-') {
      cin >> c >> d;
      t.C(a, b), t.L(c, d);
    } else if (o == '*') {
      cin >> c;
      t.S(a, b), t.Pm(b, c);
    } else {
      t.S(a, b);
      cout << t.e[b].s << '\n';
    }
  }
  return 0;
}
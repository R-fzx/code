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

const int kN = 4e6 + 3, kL = 5e5 + 1;

struct E {
  int v, f, c[2], s, sm, ms = -1e9, ls, rs, t = 1919;
  bool r;
} e[kN];
int n, m, c, r;

int N(int v) {
  e[++c] = {v, 0, {0, 0}, 1, v, v, max(0, v), max(0, v), 1919, 0};
  return c;
}
void Pu(int x) {
  e[x].s = e[e[x].c[0]].s + e[e[x].c[1]].s + 1;
  e[x].sm = e[e[x].c[0]].sm + e[e[x].c[1]].sm + e[x].v;
  e[x].ms = max({e[e[x].c[0]].ms, e[e[x].c[1]].ms, e[e[x].c[0]].rs + e[x].v + e[e[x].c[1]].ls});
  e[x].ls = e[e[x].c[0]].ls + (e[e[x].c[0]].ls == e[e[x].c[0]].sm ? max(0, e[x].v + max(0, e[e[x].c[1]].ls)) : 0);
  e[x].rs = e[e[x].c[1]].rs + (e[e[x].c[1]].rs == e[e[x].c[1]].sm ? max(0, e[x].v + max(0, e[e[x].c[0]].rs)) : 0);
}
// assign > reverse
void Pr(int x) { swap(e[x].c[0], e[x].c[1]), swap(e[x].ls, e[x].rs), e[x].r ^= 1; }
void Pa(int x, int v) {
  e[x].v = v, e[x].sm = v * e[x].s, e[x].ms = max(e[x].sm, v), e[x].ls = e[x].rs = max(e[x].sm, 0);
  e[x].r = 0, e[x].t = v;
}
void Pd(int x) {
  e[x].t != 1919 && (Pa(e[x].c[0], e[x].t), Pa(e[x].c[1], e[x].t), e[x].t = 1919);
  e[x].r && (Pr(e[x].c[0]), Pr(e[x].c[1]), e[x].r = 0);
}
int W(int x) { return e[e[x].f].c[1] == x; }
void C(int x, int y, int w) { x && (e[x].f = y), y && (e[y].c[w] = x); }  // x 接到 y 的 w 儿子
void R(int x) {
  int y = e[x].f, z = e[y].f, w = W(x), k = e[x].c[!w];
  C(x, z, W(y)), C(y, x, !w), C(k, y, w), Pu(y);
}
void Sy(int x, int f) {
  int y = x, z = 0;
  static int st[kL];
  for (; y; st[++z] = y, y = e[y].f) {
  }
  for (; z; Pd(st[z--])) {
  }
  for (; (y = e[x].f) != f; R(x)) {
    if (e[y].f != f) {
      R(W(x) == W(y) ? y : x);
    }
  }
  Pu(x), !f && (r = x);
}
int B() {
  int v;
  cin >> v;
  return N(v);
}
int B(int l, int r) {
  if (l > r) {
    return 0;
  }
  int m = l + r >> 1, x = B(l, m - 1), y = B(), z = B(m + 1, r);
  C(x, y, 0), C(z, y, 1), Pu(y);
  return y;
}
int F(int k) {
  int x = r;
  for (int s; (s = e[e[x].c[0]].s + 1) != k;) {
    Pd(x);
    if (s < k) {
      k -= s, x = e[x].c[1];
    } else {
      x = e[x].c[0];
    }
  }
  return x;
}
int& St(int l, int r) {
  int x = F(l), y = F(r + 2);
  Sy(x, 0), Sy(y, x);
  return e[y].c[0];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m, c = 2;
  C(2, 1, 1), C(B(1, n), 2, 0), Pu(2), Pu(1), r = 1;
  for (int x, l, v; m--; ) {
    string s;
    cin >> s;
    if (s == "INSERT") {
      cin >> x >> l;
      St(x + 1, x) = B(1, l);
    } else if (s == "DELETE") {
      cin >> x >> l;
      St(x, x + l - 1) = 0;
    } else if (s == "MAKE-SAME") {
      cin >> x >> l >> v;
      Pa(St(x, x + l - 1), v);
    } else if (s == "REVERSE") {
      cin >> x >> l;
      Pr(St(x, x + l - 1));
    } else if (s == "GET-SUM") {
      cin >> x >> l;
      cout << e[St(x, x + l - 1)].sm << endl;
    } else {
      cout << e[St(1, n)].ms << endl;
    }
  }
  return 0;
}
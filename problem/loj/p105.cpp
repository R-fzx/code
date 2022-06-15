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

struct FHQ {
  static const int kN = 1e5 + 1;

  struct E {
    int v, l, r, s, t;
    unsigned int p;
  } e[kN];
  int rt, c;
  mt19937 rd;

  FHQ() : rd(random_device()()) {}
  int C(int v) { return e[++c] = {v, 0, 0, 1, 0, rd()}, c; }
  void Pu(int x) { e[x].s = e[e[x].l].s + e[e[x].r].s + 1; }
  void Pd(int x) {
    if (e[x].t) {
      e[e[x].l].t ^= 1, e[e[x].r].t ^= 1, swap(e[x].l, e[x].r), e[x].t = 0;
    }
  }
  void S(int x, int s, int &a, int &b) {
    if (!x) {
      a = b = 0;
      return;
    }
    Pd(x);
    if (e[e[x].l].s + 1 <= s) {
      a = x, S(e[x].r, s - e[e[x].l].s - 1, e[x].r, b);
    } else {
      b = x, S(e[x].l, s, a, e[x].l);
    }
    Pu(x);
  }
  int M(int a, int b) {
    if (!a || !b) {
      return a | b;
    }
    if (e[a].p > e[b].p) {
      Pd(a), e[a].r = M(e[a].r, b), Pu(a);
      return a;
    } else {
      Pd(b), e[b].l = M(a, e[b].l), Pu(b);
      return b;
    }
  }
  void R(int l, int r) {
    int a, b, c;
    S(rt, l - 1, a, b), S(b, r - l + 1, b, c), e[b].t ^= 1, rt = M(M(a, b), c);
  }
  void P(int x) {
    if (x) {
      Pd(x), P(e[x].l), cout << e[x].v << " ", P(e[x].r);
    }
  }
} t;
int n, m, l, r;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    t.rt = t.M(t.rt, t.C(i));
  }
  for (cin >> m; m--;) {
    cin >> l >> r;
    t.R(l, r);
  }
  t.P(t.rt);
  return 0;
}
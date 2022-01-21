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
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using LD = double;
using Pll = pair<LL, LL>;
using Pdd = pair<LD, LD>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;
using Vec = pair<Pdd, Pdd>;

const int kN = 1e5 + 3;

struct T {
  int v, s, c, l[2], f;
  bool r;
} e[kN];
int rt, c, n, q, l, r, a[kN];

int Create(int v) { return e[++c] = {v, 1, 1, {0, 0}, 0, 0}, c; }
int Where(int x) { return x == e[e[x].f].l[1]; }
void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
void Connect(int x, int y, int w) { e[x].l[w] = y, e[y].f = x; }
void Rotate(int x) {
  int y = e[x].f, z = e[y].f, w = Where(x);
  Connect(z, x, Where(y)), Connect(y, e[x].l[w ^ 1], w), Connect(x, y, w ^ 1), PushUp(y), PushUp(x);
}
void Splay(int x, int t) {
  for (; e[x].f != t; Rotate(x)) {
    if (e[e[x].f].f != t) {
      Rotate(Where(x) == Where(e[x].f) ? e[x].f : x);
    }
  }
  !t && (rt = x);
}
void PushDown(int x) {
  if (x && e[x].r) {
    swap(e[x].l[0], e[x].l[1]), e[e[x].l[0]].r ^= 1, e[e[x].l[1]].r ^= 1, e[x].r = 0;
  }
}
int Build(int l, int r, int f, int _ = 0) {
  // for (int i = 1; i <= _; ++i) {
  //   fprintf(stderr, " ");
  // }
  // fprintf(stderr, "Build(%d, %d, %d) Start.\n", l, r, f);
  if (l > r) {
    return 0;
  }
  int m = l + r >> 1, x = Create(a[m]);
  e[x].f = f, e[x].l[0] = Build(l, m - 1, x, _ + 1), e[x].l[1] = Build(m + 1, r, x, _ + 1), PushUp(x);
  // for (int i = 1; i <= _; ++i) {
  //   fprintf(stderr, " ");
  // }
  // fprintf(stderr, "Build(%d, %d, %d) End.\n", l, r, f);
  return x;
}
int Find(int r) {
  for (int x = rt;;) {
    PushDown(x);
    if (r <= e[e[x].l[0]].s) {
      x = e[x].l[0];
    } else if (r <= e[e[x].l[0]].s + 1) {
      return x;
    } else {
      r -= e[e[x].l[0]].s + 1, x = e[x].l[1];
    }
  }
}
void Reverse(int l, int r) {
  // fprintf(stderr, "Reverse %d and %d Start.\n", l, r);
  Splay(l = Find(l - 1), 0), Splay(r = Find(r + 1), l), e[e[r].l[0]].r ^= 1;
  // fprintf(stderr, "Reverse %d and %d End.\n", l, r);
}
void Print(int x, int t = 0) {
  // for (int i = 1; i <= t; ++i) {
  //   fprintf(stderr, " ");
  // }
  // fprintf(stderr, "Print(%d) Start. e[%d] = {%d, %d, %d, {%d, %d}, %d, %d}\n", x, x, e[x].v, e[x].s, e[x].c, e[x].l[0], e[x].l[1], e[x].f, e[x].v);
  if (x) {
    PushDown(x);
    Print(e[x].l[0], t + 1);
    if (e[x].v >= 1 && e[x].v <= n) {
      cout << e[x].v << " ";
    }
    Print(e[x].l[1], t + 1);
  }
  // for (int i = 1; i <= t; ++i) {
  //   fprintf(stderr, " ");
  // }
  // fprintf(stderr, "Print(%d) End. e[%d] = {%d, %d, %d, {%d, %d}, %d, %d}\n", x, x, e[x].v, e[x].s, e[x].c, e[x].l[0], e[x].l[1], e[x].f, e[x].v);
}

int main() {
  // freopen("splay.in", "r", stdin);
  // freopen("splay.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  iota(a + 1, a + n + 3, 0), rt = Build(1, n + 2, 0);
  while (q--) {
    cin >> l >> r;
    Reverse(l + 1, r + 1);
  }
  Print(rt);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
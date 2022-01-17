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

const int kN = 1e5 + 1;

struct T {
  int v, s, c, l[2], f;
  bool r;
} e[kN];
int rt, c, n, q, l, r;

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
  if (e[x].r) {
    swap(e[x].l[0], e[x].l[1]), e[e[x].l[0]].r ^= 1, e[e[x].l[1]].r ^= 1, e[x].r = 0;
  }
}
void Print(int x, int t) {
  for (int i = 1; i <= t; ++i) {
    fprintf(stderr, " ");
  }
  fprintf(stderr, "Print(%d) Start. e[%d] = {%d, %d, %d, {%d, %d}, %d, %d}\n", x, x, e[x].v, e[x].s, e[x].c, e[x].l[0], e[x].l[1], e[x].f, e[x].v);
  if (x) {
    PushDown(x);
    Print(e[x].l[0], t + 1);
    if (x > 2) {
      cout << x - 2 << " ";
    }
    Print(e[x].l[1], t + 1);
  }
  for (int i = 1; i <= t; ++i) {
    fprintf(stderr, " ");
  }
  fprintf(stderr, "Print(%d) End. e[%d] = {%d, %d, %d, {%d, %d}, %d, %d}\n", x, x, e[x].v, e[x].s, e[x].c, e[x].l[0], e[x].l[1], e[x].f, e[x].v);
}

int main() {
  // freopen("splay.in", "r", stdin);
  // freopen("splay.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;

  while (q--) {
    cin >> l >> r;
    Splay(l + 1, 0), Splay(r + 3, l + 1), e[e[r + 2].l[0]].r ^= 1;
  }
  Print(rt, 0);
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
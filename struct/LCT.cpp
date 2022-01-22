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

struct E {
  int v, l[2], f, s, r;
} e[kN];
int n, q, o, x, y;

bool NotRoot(int x) { return e[e[x].f].l[0] == x || e[e[x].f].l[1] == x; }
void PushUp(int x) { e[x].s = e[e[x].l[0]].s ^ e[e[x].l[1]].s ^ e[x].v; }
void PushRev(int x) { swap(e[x].l[0], e[x].l[1]), e[x].r ^= 1; }
void PushDown(int x) {
  if (e[x].r) {
    e[x].l[0] && (PushRev(e[x].l[0]), 0), e[x].l[1] && (PushRev(e[x].l[1]), 0), e[x].r = 0;
  }
}
int Which(int x) { return NotRoot(x) ? e[e[x].f].l[1] == x : -1; }
void Connect(int x, int y, int w) { w != -1 && (e[x].l[w] = y), y && (e[y].f = x); }
void Rotate(int x) {
  int y = e[x].f, z = e[y].f, w = Which(x);
  Connect(y, e[x].l[w ^ 1], w), Connect(z, x, Which(y)), Connect(x, y, w ^ 1), PushUp(y);
}
void Splay(int x) {
  static int st[kN];
  int y = x, t = 0;
  for (st[++t] = y; NotRoot(y); st[++t] = y = e[y].f) {
  }
  for (; t; PushDown(st[t--])) {
  }
  for (; NotRoot(x); Rotate(x)) {
    if (NotRoot(y = e[x].f)) {
      Rotate(Which(x) == Which(y) ? y : x);
    }
  }
  PushUp(x);
}
void Access(int x) {
  for (int y = 0; x; Splay(x), e[x].l[1] = y, PushUp(x), y = x, x = e[x].f) {
  }
}
void MakeRoot(int x) { Access(x), Splay(x), PushRev(x); }
int FindRoot(int x) {
  for (Access(x), Splay(x); e[x].l[0]; PushDown(x), x = e[x].l[0]) {
  }
  return Splay(x), x;
}
void Split(int x, int y) { MakeRoot(x), Access(y), Splay(y); }
void Link(int x, int y) { MakeRoot(x), FindRoot(y) != x && (e[x].f = y); }
void Cut(int x, int y) { MakeRoot(x), FindRoot(y) == x && e[y].f == x && !e[y].l[0] && (e[y].f = e[x].l[1] = 0, PushUp(x), 0); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i].v;
  }
  while (q--) {
    cin >> o >> x >> y;
    if (o == 0) {
      Split(x, y);
      cout << e[y].s << endl;
    } else if (o == 1) {
      Link(x, y);
    } else if (o == 2) {
      Cut(x, y);
    } else {
      Splay(x), e[x].v = y;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
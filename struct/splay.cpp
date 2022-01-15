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
} e[kN];
int rt, c;

int Create(int v) { return e[++c] = {v, 1, 1, {0, 0}, 0}, c; }
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
void MakeRoot(int v) {
  if (!rt) {
    return;
  }
  int x = rt;
  for (; e[x].l[e[x].v < v] && e[x].v != v; x = e[x].l[e[x].v < v]) {
  }
  Splay(x, 0);
}
void Insert(int v) {
  int x = rt, f = 0;
  for (; x && e[x].v != v; f = x, x = e[x].l[e[x].v < v]) {
  }
  if (x) {
    ++e[x].c;
  } else {
    x = Create(v);
    if (f) {
      Connect(f, x, e[f].v < v);
    }
  }
  Splay(x, 0);
}
int Near(int v, int t) {
  MakeRoot(v);
  int x = rt;
  if (e[x].v < v && !t || e[x].v > v && t) {
    return x;
  }
  for (x = e[x].l[t]; e[x].l[t ^ 1]; x = e[x].l[t ^ 1]) {
  }
  return x;
}
void Delete(int v) {
  int p = Near(v, 0), n = Near(v, 1);
  Splay(p, 0), Splay(n, p);
  int x = e[n].l[0];
  if (--e[x].c) {
    Splay(x, 0);
  } else {
    e[n].l[0] = 0;
  }
}
int At(int r) {
  for (int x = rt; e[rt].s >= r;) {
    int l = e[x].l[0];
    if (r > e[l].s + e[x].c) {
      r -= e[l].s + e[x].c, x = e[x].l[1];
    } else if (r > e[l].s) {
      return e[x].v;
    } else {
      x = l;
    }
  }
  return -1;
}

int q, o, x;

int main() {
  // freopen("splay.in", "r", stdin);
  // freopen("splay.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Insert(INT32_MAX), Insert(INT32_MIN);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      Insert(x);
    } else if (o == 2) {
      Delete(x);
    } else if (o == 3) {
      MakeRoot(x);
      cout << e[e[rt].l[0]].s << endl;
    } else if (o == 4) {
      cout << At(x + 1) << endl;
    } else {
      cout << e[Near(x, o == 6)].v << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
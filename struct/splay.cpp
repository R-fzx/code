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
  int v, c, s, f, l[2];
} e[kN];
int q, o, x, c, rt;

int Create(int v) { return e[++c] = {v, 1, 1, 0, {0, 0}}, c; }
void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
int Which(int x) { return x == e[e[x].f].l[1]; }
void Connect(int x, int y, int w) { e[x].l[w] = y, e[y].f = x; }
void Rotate(int x) {
  int y = e[x].f, z = e[y].f, w = Which(x);
  Connect(z, x, Which(y)), Connect(y, e[x].l[w ^ 1], w), Connect(x, y, w ^ 1), PushUp(y), PushUp(x);
}
void SplayE(int x, int t = 0) {
  for (int y; (y = e[x].f) != t; Rotate(x)) {
    if (e[y].f != t) {
      Rotate(Which(x) == Which(y) ? y : x);
    }
  }
  !t && (rt = x);
}
void SplayV(int v, int t = 0) {
  if (!rt) {
    return;
  }
  int x = rt;
  for (; e[x].l[e[x].v < v] && v != e[x].v; x = e[x].l[e[x].v < v]) {
  }
  SplayE(x, t);
}
int Near(int v, int w /* 0 Pre 1 Next */) {
  SplayV(v);
  if (e[rt].v < v && !w || e[rt].v > v && w) {
    return rt;
  }
  int x = e[rt].l[w];
  for (; e[x].l[w ^ 1]; x = e[x].l[w ^ 1]) {
  }
  return x;
}
int FindV(int v) { return SplayV(v), e[e[rt].l[0]].s; }
int FindR(int r) {
  for (int x = rt; e[rt].s >= r; ) {
    int ls = e[e[x].l[0]].s;
    if (r > ls + e[x].c) {
      r -= ls + e[x].c, x = e[x].l[1];
    } else if (r > ls) {
      return x;
    } else {
      x = e[x].l[0];
    }
  }
  return -1;
}
void Insert(int v) {
  int x = rt, y = 0;
  for (; x && e[x].v != v; y = x, x = e[x].l[e[x].v < v]) {
  }
  if (x) {
    ++e[x].c;
  } else {
    x = Create(v), y && (Connect(y, x, e[y].v < v), 0);
  }
  SplayE(x);
}
void Delete(int v) {
  int p = Near(v, 0), n = Near(v, 1);
  SplayE(p), SplayE(n, p);
  int x = e[n].l[0];
  --e[x].c ? (SplayE(x), 0) : (e[n].l[0] = 0);
}

int main() {
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
      cout << FindV(x) << endl;
    } else if (o == 4) {
      cout << e[FindR(x + 1)].v << endl;
    } else {
      cout << e[Near(x, o == 6)].v << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
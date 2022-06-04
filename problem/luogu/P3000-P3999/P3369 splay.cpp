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
  struct E {
    int v, f, c, s, l[2];
  } e[kN];
  int r, c;

  int Create(int v) { return e[++c] = {v, 0, 1, 1, {0, 0}}, c; }
  void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
  int Where(int x) { return e[e[x].f].l[1] == x; }
  void Connect(int x, int y, int w) { e[x].l[w] = y, e[y].f = x; }
  void Rotate(int x) {
    int y = e[x].f, z = e[y].f, w = Where(x);
    Connect(z, x, Where(y)), Connect(y, e[x].l[w ^ 1], w), Connect(x, y, w ^ 1), PushUp(y), PushUp(x);
  }
  void Splay(int x, int t) {
    for (int y, z; e[x].f != t; y = e[x].f, z = e[y].f, z != t && (Rotate(Where(x) == Where(y) ? y : x), 0), Rotate(x)) {
    }
    !t && (r = x);
  }
  void Splay(int v) {
    if (!r) {
      return;
    }
    int x = r;
    for (; e[x].l[v > e[x].v] && v != e[x].v; x = e[x].l[v > e[x].v]) {
    }
    Splay(x, 0);
  }
  void Insert(int v) {
    int x = r, f = 0;
    for (; x && e[x].v != v; f = x, x = e[x].l[v > e[x].v]) {
    }
    x ? ++e[x].c : (Connect(f, Create(v), v > e[f].v), 0), Splay(x, 0);
  }
  int Next(int v, int t) {
    Splay(v);
    int x = r;
    if (e[x].v > v && t || e[x].v < v && !t) {
      return x;
    }
    for (x = e[x].l[t]; e[x].l[t ^ 1]; x = e[x].l[t ^ 1]) {
    }
    return x;
  }
  void Delete(int v) {
    int p = Next(v, 0), n = Next(v, 1);
    Splay(p, 0), Splay(n, p);
    int &x = e[n].l[0];
    --e[x].c ? (Splay(x, 0), 0) : (x = 0);
  }
  int Rank(int v) {
    Splay(v);
    return e[e[r].l[0]].s;
  }
  int kth(int v) {
    for (int x = r; e[r].s >= v;) {
      int y = e[x].l[0];
      if (v > e[y].s + e[x].c) {
        v -= e[y].s + e[x].c, x = e[x].l[1];
      } else {
        if (e[y].s >= v) {
          x = y;
        } else {
          return e[x].v;
        }
      }
    }
    return 0;
  }
} t;
int q, o, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  t.Insert(INT32_MIN), t.Insert(INT32_MAX);
  cin >> q;
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      t.Insert(x);
    } else if (o == 2) {
      t.Delete(x);
    } else if (o == 3) {
      cout << t.Rank(x) << endl;
    } else if (o == 4) {
      cout << t.kth(x + 1) << endl;
    } else {
      cout << t.e[t.Next(x, o - 5)].v << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
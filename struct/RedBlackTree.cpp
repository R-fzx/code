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
  int f, l[2], v, c, s;
} e[kN];
int q, o, x, rt;

void PushUp(int x) { e[x].s = e[e[x].l[0]].s + e[e[x].l[1]].s + e[x].c; }
int Which(int x) { return e[e[x].f].l[1] == x; }
void Connect(int x, int y, int w) { (x ? e[x].l[w] : rt) = y, y && (e[y].f = x); }
void Rotate(int x, int t) {
  int l = e[x].l[!t];
  Connect(x, e[l].l[t], !t);
  // e[x].l[!t] = e[l].l[t];
  // if (e[l].l[t]) {
  //   e[e[l].l[t]].f = x;
  // }
  Connect(e[x].f, l, Which(x));
  // (e[x].f ? e[e[x].f].l[Which(x)] : rt) = l, e[l].f = e[x].f;
  Connect(l, x, t);
  // e[l].l[t] = x, e[x].f = l;
  PushUp(x), PushUp(l);
}
int Rank(int v) {
  int r = 0;
  for (int x = rt; x;) {
    if (e[x].v < v) {
      r += e[e[x].l[0]].s + e[x].c, x = e[x].l[1];
    } else {
      x = e[x].l[0];
    }
  }
  return r + 1;
}
int At(int k) {
  for (int x = rt; x; ) {
    int ls = e[e[x].l[0]].s;
    if (k <= ls) {
      x = e[x].l[0];
    } else if (k <= ls + e[x].c) {
      return e[x].v;
    } else {
      k -= ls + e[x].c, x = e[x].l[1];
    }
  }
  return -1;
}
int Next(int v) {
  int s = INT32_MAX;
  for (int x = rt; x; ) {
    if (e[x].v <= v) {
      x = e[x].l[1];
    } else {
      s = min(s, e[x].v), x = e[x].l[0];
    }
  }
  return s;
}
int Pre(int v) {
  int s = INT32_MIN;
  for (int x = rt; x; ) {
    if (e[x].v >= v) {
      x = e[x].l[0];
    } else {
      s = max(s, e[x].v), x = e[x].l[1];
    }
  }
  return s;
}
void Insert(int v) {
  
}
void InsFix() {
}
void Delete(int v) {
}
void DelFix() {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
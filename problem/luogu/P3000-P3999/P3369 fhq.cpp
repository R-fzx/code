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

template <typename T, int kN>
struct FHQ {
  struct E {
    T v;
    int s, l, r;
    unsigned int p;
  } e[kN];
  int rt, c;
  mt19937 rd;

  FHQ() : rd(random_device{}()) {}
  int C(T v) { return e[++c] = {v, 1, 0, 0, rd()}, c; }
  void Pu(int x) { e[x].s = e[e[x].l].s + e[e[x].r].s + 1; }
  void S(int o, T v, int &x, int &y) { // <v to x, >=v to y
    if (!o) {
      x = y = 0;
      return;
    }
    if (e[o].v < v) {
      x = o, S(e[o].r, v, e[o].r, y);
    } else {
      y = o, S(e[o].l, v, x, e[o].l);
    }
    Pu(o);
  }
  int M(int x, int y) { // x < y
    if (!x || !y) {
      return x | y;
    }
    if (e[x].p < e[y].p) {
      e[x].r = M(e[x].r, y), Pu(x);
      return x;
    } else  {
      e[y].l = M(x, e[y].l), Pu(y);
      return y;
    }
  }
  void I(T v) {
    int x, y;
    S(rt, v, x, y), rt = M(M(x, C(v)), y);
  }
  void D(T v) {
    int x, y, z;
    S(rt, v, x, y), S(y, v + 1, y, z), y = M(e[y].l, e[y].r), rt = M(x, M(y, z));
  }
  int R(T v) {
    int x, y, s;
    S(rt, v, x, y), s = e[x].s + 1, rt = M(x, y);
    return s;
  }
  int A(int k) {
    for (int x = rt; x; ) {
      int s = e[e[x].l].s + 1;
      if (s < k) {
        k -= s, x = e[x].r;
      } else if (s == k) {
        return x;
      } else {
        x = e[x].l;
      }
    }
    return -1;
  }
  int P(T v) {
    int x, y, i;
    S(rt, v, x, y);
    for (i = x; e[i].r; i = e[i].r) {
    }
    rt = M(x, y);
    return i;
  }
  int N(T v) {
    int x, y, i;
    S(rt, v + 1, x, y);
    for (i = y; e[i].l; i = e[i].l) {
    }
    rt = M(x, y);
    return i;
  }
};

FHQ<int, 100001> t;
int q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  for (int o, x; q--; ) {
    cin >> o >> x;
    if (o == 1) {
      t.I(x);
    } else if (o == 2) {
      t.D(x);
    } else if (o == 3) {
      cout << t.R(x) << '\n';
    } else if (o == 4) {
      cout << t.e[t.A(x)].v << '\n';
    } else if (o == 5) {
      cout << t.e[t.P(x)].v << '\n';
    } else {
      cout << t.e[t.N(x)].v << '\n';
    }
  }
  return 0;
}
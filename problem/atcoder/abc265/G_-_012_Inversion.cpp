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

const int kN = 1e5 + 1;

struct T {
  using A = array<int, 3>;
  struct E {
    A s, t;
  } e[kN << 2];

  void Pu(int x) {
    for (int i = 0; i < 3; ++i) {
      e[x].s[0] = e[x * 2].s[0] + e[x * 2 + 1].s[0];
    }
  }
  void B(int x, int l, int r) {
    if (l == r) {
      int v;
      cin >> v;
      e[x].s[v] = 1, iota(e[x].t.begin(), e[x].t.end(), 0);
      return;
    }
    int m = l + r >> 1;
    B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
    Pu(x);
  }
  void Pd(int x) {
    for (int i = 0; i < 3; ++i) {
      e[x].t[i] = e[x / 2].t[e[x].t[i]];
    }
    A _s;
    copy(e[x].s.begin(), e[x].s.end(), _s.begin()), fill(e[x].s.begin(), e[x].s.end(), 0);
    for (int i = 0; i < 3; ++i) {
      e[x].s[i] += _s[e[x].t[i]];
    }
  }
  void U(int x, int l, int r, int tl, int tr, int y, int v) {
    if (l == tl && r == tr) {
      if (y != v) {
        e[x].s[v] += e[x].s[y], e[x].s[y] = 0;
        for (int i = 0; i < 3; ++i) {
          if (e[x].t[i] == y) {
            e[x].t[i] = v;
          }
        }
      }
      return;
    }
    Pd(x * 2), Pd(x * 2 + 1), iota(e[x].t.begin(), e[x].t.end(), 0);
    int m = l + r >> 1;
    if (tl <= m) {
      U(x * 2, l, m, tl, min(m, tr), y, v);
    }
    if (m < tr) {
      U(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y, v);
    }
    Pu(x);
  }
  using tQ = pair<A, LL>;
  tQ Q(int x, int l, int r, int tl, int tr) {
    if (l == tl && r == tr) {
      return {e[x].s, };
    }
  }
} t;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}
/*
1 0
2 0
2 1
*/
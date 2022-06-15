#include <algorithm>
#include <bitset>
#include <chrono>
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
  int r, c;
  mt19937 rd;

  FHQ() : rd(random_device()()) {}
  int C(int v) { return e[++c] = {v, 0, 0, 1, 0, rd()}, c; }
  void Pu(int x) { e[x].s = e[e[x].l].s + e[e[x].r].s + 1; }
  void Pd(int x) {
    if (e[x].t) {
      e[x].t = 0, swap(e[x].l, e[x].r), e[e[x].l].t ^= 1, e[e[x].r].t ^= 1;
    }
  }
  void S(int x, int v, int &a, int &b) {  // 把 x 按照 v 分裂，<=v 在 a，>v 在 b
    if (!x) {
      a = b = 0;
      return;
    }
    if (e[x].v <= v) {
      a = x, S(e[x].r, v, e[x].r, b);
    } else {
      b = x, S(e[x].l, v, a, e[x].l);
    }
    Pu(x);
  }
  int M(int a, int b) {  // 把 a 和 b 合并，保证 a <= b
    if (!a || !b) {
      return a | b;
    }
    if (e[a].p < e[b].p) {
      e[b].l = M(a, e[b].l), Pu(b);
      return b;
    } else {
      e[a].r = M(e[a].r, b), Pu(a);
      return a;
    }
  }
  void I(int v) {
    int a, b;
    S(r, v, a, b), r = M(a, M(C(v), b));
  }
  void D(int v) {
    int a, b, c;
    S(r, v - 1, a, b), S(b, v, b, c), b = M(e[b].l, e[b].r), r = M(a, M(b, c));
  }
  int R(int v) {
    int a, b, s;
    S(r, v - 1, a, b), s = e[a].s + 1, r = M(a, b);
    return s;
  }
  int A(int k) {
    int x = r;
    for (int s; (s = e[e[x].l].s + 1) != k; x = (s < k ? e[x].r : e[x].l), k -= (s < k) * s) {
    }
    return x;
  }
  int P(int v) {
    int a, b, x;
    for (S(r, v - 1, a, b), x = a; e[x].r; x = e[x].r) {
    }
    return r = M(a, b), x;
  }
  int N(int v) {
    int a, b, x;
    for (S(r, v, a, b), x = b; e[x].l; x = e[x].l) {
    }
    return r = M(a, b), x;
  }
} t;
int n, o, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> n; n--;) {
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
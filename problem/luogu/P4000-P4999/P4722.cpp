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

const int kN = 1202, kM = 120001;

struct E {
  int y, w, n;
} e[kM << 1];
struct V {
  int h, v, d = -1;
} a[kN];
int n, m, s, t, c = 1, q[kN], _h = 1, _t, g[kN];
auto f = [](int i, int j) { return a[i].d < a[j].d; };
priority_queue<int, vector<int>, decltype(f)> p(f);
bool v[kN];

void _A(int x, int y, int w) { e[++c] = {y, w, a[x].h}, a[x].h = c; }
void A(int x, int y, int w) { _A(x, y, w), _A(y, x, 0); }
void R(int x, int d) {
  if (!~a[x].d) {
    ++g[a[x].d = d], q[++_t] = x;
  }
}
bool B() {
  for (R(t, 0); _h <= _t; ++_h) {
    int x = q[_h];
    for (int i = a[x].h; i; i = e[i].n) {
      if (e[i ^ 1].w) {
        R(e[i].y, a[x].d + 1);
      }
    }
  }
  if (~a[s].d) {
    --g[a[s].d], ++g[a[s].d = n];
    return 1;
  } else {
    return 0;
  }
}
void P(int x) {
  for (int i = a[x].h; i; i = e[i].n) {
    if (e[i].w && a[x].d == a[e[i].y].d + 1) {
      int f = min(a[x].v, e[i].w);
      e[i].w -= f, e[i ^ 1].w += f, a[x].v -= f, a[e[i].y].v += f;
      if (e[i].y != s && e[i].y != t && !v[e[i].y]) {
        p.push(e[i].y), v[e[i].y] = 1;
      }
      if (!a[x].v) {
        break;
      }
    }
  }
}
void R(int x) {
  if (x != s && x != t) {
    if (!--g[a[x].d]) {
      for (int i = 1; i <= n; ++i) {
        if (i != s && i != t && a[i].d > a[x].d) {
          a[i].d = n + 1;
        }
      }
    }
    a[x].d = n + 1;
    for (int i = a[x].h; i; i = e[i].n) {
      if (e[i].w) {
        a[x].d = min(a[x].d, a[i].d + 1);
      }
    }
    ++g[a[x].d];
  }
}
void S() {
  if (B()) {
    for (int i = a[s].h; i; i = e[i].n) {
      a[e[i].y].v += e[i].w, e[i ^ 1].w += e[i].w, e[i].w = 0;
      if (e[i].y != s && e[i].y != t && !v[e[i].y]) {
        p.push(e[i].y), v[e[i].y] = 1;
      }
    }
    for (int x; !p.empty();) {
      x = p.top(), p.pop(), v[x] = 0;
      P(x);
      if (a[x].v) {
        R(x), p.push(x), v[x] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> s >> t;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    A(x, y, w);
  }
  S();
  cout << a[t].v;
  return 0;
}
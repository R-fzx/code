#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

struct MF {
  static const int kN = 201, kM = 20001;

  struct V {
    int h, _h, d;
    bool v;
  } a[kN];
  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  int n, s, t, c = 1, q[kN], _h, _t;
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
  void R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      int x = q[_h];
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + 1);
        }
      }
    }
    return a[t].d;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, 1e18)) {
    }
  }
  void _P(int x) {
    if (a[x].v) {
      return;
    }
    a[x].v = 1;
    for (int i = a[x].h; i; i = e[i].n) {
      if (e[i].w) {
        _P(e[i].y);
      }
    }
  }
  void P() {
    _P(s);
    vector<int> l;
    n /= 2;
    for (int i = 1; i <= n; ++i) {
      debug("%d ", a[i].v);
      if (a[i].v && !a[i + n].v) {
        l.push_back(i);
      }
    }
    debug("\n");
    cout << l.size() << endl;
    for (int i : l) {
      cout << i << " ";
    }
  }
} sl;

int n, m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  sl.n = n * 2, sl.s = 1, sl.t = sl.n;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    sl.A(x + n, y, 1e18);
    sl.A(y + n, x, 1e18);
  }
  for (int i = 1; i <= n; ++i) {
    LL x;
    cin >> x;
    sl.A(i, i + n, i == 1 || i == n ? 1e18 : x);
  }
  sl.S();
  cout << sl.mf << endl;
  sl.P();
  return 0;
}
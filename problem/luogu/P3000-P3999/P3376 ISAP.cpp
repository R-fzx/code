#include <iostream>
#include <limits>

using namespace std;
using LL = long long;

template <typename F, int kN, int kM>
struct MF {
  struct E {
    int y, n;
    F w;
  } e[kM << 1];
  struct V {
    int h, _h, d = 1;
  } a[kN];
  int n, s, t, c = 1, g[kN];
  F mf;

  void _A(int x, int y, F w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, F w) { _A(x, y, w), _A(y, x, 0); }
  F D(int x, F f) {
    if (x == t) {
      return f;
    }
    F _s = f, r;
    for (int &i = a[x]._h; _s && i; _s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d + 1 == a[x].d && (r = D(e[i].y, min(e[i].w, _s)))) {
        _s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    if (_s) {
      if (!--g[a[x].d]) {
        a[s].d = n + 1;
      }
      ++g[++a[x].d];
    }
    return f - _s;
  }
  void S() {
    g[1] = n;
    do {
      for (int i = 1; i <= n; ++i) {
        a[i]._h = a[i].h;
      }
      mf += D(s, numeric_limits<F>::max());
    } while (a[s].d <= n);
  }
};

MF<LL, 203, 5001> s;
int m;

int main() {
  cin >> s.n >> m >> s.s >> s.t;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    s.A(x, y, w);
  }
  s.S();
  cout << s.mf;
  return 0;
}
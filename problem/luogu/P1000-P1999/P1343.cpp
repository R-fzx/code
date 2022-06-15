#include <iostream>

using namespace std;
using LL = long long;

struct MF {
  static const int kN = 203, kM = 2001;

  struct E {
    int y, n;
    LL w;
  } e[kM << 1];
  struct V {
    int h, _h, d = 1;
  } a[kN];
  int n, s, t, c = 1, g[kN];
  LL mf;

  void _A(int x, int y, LL w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, LL w) { _A(x, y, w), _A(y, x, 0); }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    LL _s = f, r;
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
      mf += D(s, 1e10);
    } while (a[s].d <= n);
  }
} s;
int m, x;

int main() {
  cin >> s.n >> m >> x;
  s.s = 1, s.t = s.n;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    s.A(x, y, w);
  }
  s.S();
  if (s.mf) {
    cout << s.mf << " " << (x + s.mf - 1) / s.mf;
  } else {
    cout << "Orz Ni Jinan Saint Cow!";
  }
  return 0;
}
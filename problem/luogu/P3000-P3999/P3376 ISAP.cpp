#include <iostream>

using namespace std;

struct MF {
  static const int kV = 205, kM = 5001;

  struct V {
    int h, _h, d = 1;
  } a[kV];
  struct E {
    int y, n;
    long long w;
  } e[kM << 1];
  int n, s, t, c = 1, g[kV];
  long long mf;

  void _A(int x, int y, long long w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, long long w) { _A(x, y, w), _A(y, x, 0); }
  long long D(int x, long long f) {
    if (x == t) {
      return f;
    }
    long long _s = f, r;
    for (int &i = a[x]._h; _s && i; _s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d + 1 == a[x].d && (r = D(e[i].y, min(_s, e[i].w)))) {
        e[i].w -= r, _s -= r, e[i ^ 1].w += r;
      }
    }
    if (_s) {
      if (!--g[a[x].d++]) {
        a[s].d = n + 1;
      }
      ++g[a[x].d];
    }
    return f - _s;
  }
  void S() {
    g[1] = n;
    do {
      for (int i = 1; i <= n; ++i) {
        a[i]._h = a[i].h;
      }
      mf += D(s, 1e18);
    } while (a[s].d <= n);
  }
} s;

int m;

int main() {
  cin >> s.n >> m >> s.s >> s.t;
  for (int i = 1, x, y, w; i <= m; ++i) {
    cin >> x >> y >> w;
    s.A(x, y, w);
  }
  s.S();
  cout << s.mf;
}
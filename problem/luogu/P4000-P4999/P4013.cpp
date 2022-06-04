#include <iostream>

using namespace std;
using LL = long long;

struct MCMF {
  static const int kN = 1203, kM = 18001;

  struct E {
    int y, n;
    LL w, c;
  } e[kM << 1];
  struct V {
    int h, _h;
    LL d;
    bool v;
  } a[kN];
  int n, s, t, _c = 1, q[kN], _h, _t;
  LL mc, mf;

  void _A(int x, int y, LL w, LL c) { e[++_c] = {y, a[x].h, w, c}, a[x].h = _c; }
  void A(int x, int y, LL w, LL c) { _A(x, y, w, c), _A(y, x, 0, -c); }
  void R(int x, int d) {
    if (a[x].d > d) {
      a[x].d = d;
      if (!a[x].v) {
        a[x].v = 1, q[_t = (_t + 1) % kN] = x;
      }
    }
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = INT32_MAX;
    }
    for (R(s, 0); _h != _t;) {
      int x = q[_h = (_h + 1) % kN];
      a[x].v = 0;
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w) {
          R(e[i].y, a[x].d + e[i].c);
        }
      }
    }
    return a[t].d != INT32_MAX;
  }
  LL D(int x, LL f) {
    if (x == t) {
      return f;
    }
    a[x].v = 1;
    LL s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && !a[e[i].y].v && a[e[i].y].d == a[x].d + e[i].c && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r, mc += r * e[i].c;
      }
    }
    a[x].v = 0;
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, INT32_MAX)) {
    }
  }
} sl1, sl2, sl3;
const int kN = 41;
int n, m, c;
LL a[kN][kN];

int T(int x, int y, int t) { return y + (m + (m + x - 2)) * (x - 1) / 2 + t * c; }
LL G(MCMF &sl, LL x, LL y) {
  sl.s = (sl.t = sl.n = c + c + 2) - 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m + i; ++j) {
      if (i == 1) {
        sl.A(sl.s, T(1, j, 0), 1, 0);
      }
      if (i ^ n) {
        sl.A(T(i, j, 1), T(i + 1, j, 0), y, 0), sl.A(T(i, j, 1), T(i + 1, j + 1, 0), y, 0);
      } else {
        sl.A(T(n, j, 1), sl.t, INT32_MAX, 0);
      }
      sl.A(T(i, j, 0), T(i, j, 1), x, -a[i][j]);
    }
  }
  return sl.S(), -sl.mc;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  c = T(n, n + m - 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m + i; ++j) {
      cin >> a[i][j];
    }
  }
  cout << G(sl1, 1, 1) << endl
       << G(sl2, INT32_MAX, 1) << endl
       << G(sl3, INT32_MAX, INT32_MAX);
  return 0;
}
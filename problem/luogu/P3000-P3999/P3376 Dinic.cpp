#include <iostream>
#include <limits>

using namespace std;
using LL = long long;

template <typename T, int kN, int kM>
struct MF {
  struct E {
    int y, n;
    T w;
  } e[kM << 1];
  struct V {
    int h, _h, d;
  } a[kN];
  int n, s, t, c = 1, q[kN], _h, _t;
  T mf;

  void _A(int x, int y, T w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void A(int x, int y, T w) { _A(x, y, w), _A(y, x, 0); }
  bool R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
    return x == t;
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i]._h = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(s, 1); _h <= _t; ++_h) {
      int x = q[_h];
      for (int i = a[x].h; i; i = e[i].n) {
        if (e[i].w && R(e[i].y, a[x].d + 1)) {
          return 1;
        }
      }
    }
    return 0;
  }
  T D(int x, T f) {
    if (x == t) {
      return f;
    }
    T s = f, r;
    for (int &i = a[x]._h; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[e[i].y].d == a[x].d + 1 && (r = D(e[i].y, min(s, e[i].w)))) {
        s -= r, e[i].w -= r, e[i ^ 1].w += r;
      }
    }
    return f - s;
  }
  void S() {
    for (; B(); mf += D(s, numeric_limits<T>::max())) {
    }
  }
};
MF<LL, 201, 5001> s;
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
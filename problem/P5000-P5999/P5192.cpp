#include <algorithm>
#include <iostream>

using namespace std;

struct BoundDinic {
  static const int kN = 1401, kM = 5e5 + 1;
  struct E {
    int y, n, w;
  } e[kM];
  struct V {
    int h, d, c, v;
  } a[kN];
  int n, c = 1, s, t, S, T, _h, _t, q[kN];

  void _A(int x, int y, int w) { e[++c] = {y, a[x].h, w}, a[x].h = c; }
  void _A(int x, int y, int w, int t) {
    if (t) {
      a[x].v -= w, a[y].v += w;
    } else {
      _A(x, y, w), _A(y, x, 0);
    }
  }
  void A(int x, int y, int l, int r) { _A(x, y, l, 1), _A(x, y, r - l, 0); }
  bool R(int x, int d) {
    if (!a[x].d) {
      a[x].d = d, q[++_t] = x;
    }
    return x == T;
  }
  bool B() {
    for (int i = 1; i <= n; ++i) {
      a[i].c = a[i].h, a[i].d = 0;
    }
    for (_h = 1, _t = 0, R(S, 1); _h <= _t; ++_h) {
      for (int i = a[q[_h]].h; i; i = e[i].n) {
        if (e[i].w && R(e[i].y, a[q[_h]].d + 1)) {
          return 1;
        }
      }
    }
    return 0;
  }
  int D(int x, int b) {
    if (x == T) {
      return b;
    }
    int s = b, f;
    for (int &i = a[x].c; s && i; s && (i = e[i].n)) {
      if (e[i].w && a[x].d + 1 == a[e[i].y].d && (f = D(e[i].y, min(s, e[i].w)))) {
        e[i].w -= f, e[i ^ 1].w += f, s -= f;
      }
    }
    return b - s;
  }
  int _S() {
    int ans = 0;
    for (; B(); ans += D(S, 1e9)) {
    }
    return ans;
  }
  int Sl() {
    int sv = 0;
    for (int i = 1; i <= n - 2; ++i) {
      if (a[i].v > 0) {
        _A(S, i, a[i].v, 0), sv += a[i].v;
      } else {
        _A(i, T, -a[i].v, 0);
      }
    }
    _A(t, s, 1e9, 0);
    if (_S() != sv) {
      return -1;
    }
    S = s, T = t;
    return _S();
  }
};
int n, m;

int main() {
  // freopen("P5192.in", "r", stdin);
  // freopen("P5192.out", "w", stdout);
  while (cin >> n >> m) {
    // cout << "1" << endl;
    BoundDinic sl;
    sl.n = sl.T = (sl.S = (sl.t = (sl.s = n + m + 1) + 1) + 1) + 1, sl.c = 1;
    for (int i = 1, x; i <= m; ++i) {
      cin >> x;
      sl.A(n + i, sl.t, x, 1e9);
    }
    // cout << "2" << endl;
    for (int i = 1, c, d; i <= n; ++i) {
      cin >> c >> d;
      sl.A(sl.s, i, 0, d);
      for (int x, l, r; c--;) {
        cin >> x >> l >> r;
        sl.A(i, n + x + 1, l, r);
      }
    }
    // cout << "3" << endl;
    cout << sl.Sl() << "\n\n";
    // cout << "4" << endl;
  }
  return 0;
}
#include <iostream>
#include <vector>

using namespace std;
using uLL = unsigned long long;

const int kN = 1e5 + 1;

struct D {
  uLL a[2];
  bool e;

  D() { e = 1; }
  D(uLL a0, uLL a1) { a[0] = a0, a[1] = a1, e = 0; }
  const D &operator=(const D &o) {
    a[0] = o.a[0], a[1] = o.a[1], e = o.e;
    return *this;
  }
  const D operator+(const D &o) const {
    if (e) {
      return o;
    }
    if (o.e) {
      return *this;
    }
    D x;
    x.a[0] = a[0] & o.a[1] | ~a[0] & o.a[0], x.a[1] = a[1] & o.a[1] | ~a[1] & o.a[0], x.e = 0;
    return x;
  }
};
struct T {
  D a, ia;  // 丢一个 i 进去出来的是 a[i]，ia 表示区间反向

  T() { a = D(), ia = D(); }
  const T operator+(const T &o) const {
    T x;
    x.a = a + o.a, x.ia = o.ia + ia;
    return x;
  }
} e[kN << 2];
struct E {
  int f, d, s, h, t, i, o, _o;
  uLL v, _v;
  vector<int> n;
} a[kN];
int n, q, k, c;
uLL ki;

void I(int x, int f) {
  a[x].f = f, a[x].d = a[f].d + 1, a[x].s = 1;
  for (int i : a[x].n) {
    if (i != f) {
      I(i, x), a[x].s += a[i].s;
      if (a[i].s > a[a[x].h].s) {
        a[x].h = i;
      }
    }
  }
}
void G(int x, int t) {
  a[x].i = ++c;
  a[c]._o = a[x].o, a[c]._v = a[x].v, a[x].t = t;
  if (a[x].h) {
    G(a[x].h, t);
  }
  for (int i : a[x].n) {
    if (i != a[x].f && i != a[x].h) {
      G(i, i);
    }
  }
}
void S(T &x, int o, uLL v) {
  if (o == 1) {
    x.a = D(0, v), x.ia = D(0, v);
  } else if (o == 2) {
    x.a = D(v, ki), x.ia = D(v, ki);
  } else {
    x.a = D(v, ki ^ v), x.ia = D(v, ki ^ v);
  }
}
void B(int x, int l, int r) {
  if (l == r) {
    S(e[x], a[l]._o, a[l]._v);
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r), e[x] = e[x * 2] + e[x * 2 + 1];
}
void U(int x, int l, int r, int t, int o, uLL v) {
  if (l == r) {
    S(e[x], o, v);
    return;
  }
  int m = l + r >> 1;
  if (t <= m) {
    U(x * 2, l, m, t, o, v);
  } else {
    U(x * 2 + 1, m + 1, r, t, o, v);
  }
  e[x] = e[x * 2] + e[x * 2 + 1];
}
void Q(int x, int l, int r, int tl, int tr, T &v) {
  if (l == tl && r == tr) {
    v = e[x];
    return;
  }
  int m = l + r >> 1;
  v = T();
  T a;
  if (tl <= m) {
    Q(x * 2, l, m, tl, min(m, tr), a), v = v + a;
  }
  if (m < tr) {
    Q(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, a), v = v + a;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> k;
  if (k == 64) {
    ki = UINT64_MAX;
  } else {
    ki = (1uLL << k) - 1;
  }
  // cout << ki << '\n';
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].o >> a[i].v;
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    a[x].n.push_back(y), a[y].n.push_back(x);
  }
  I(1, 0), G(1, 1), B(1, 1, n);
  for (int o, x, y; q--;) {
    uLL z;
    cin >> o >> x >> y >> z;
    if (o == 1) {
      D sx = D(), sy = D();
      T s = T();
      while (a[x].t != a[y].t) {
        if (a[a[x].t].d >= a[a[y].t].d) {
          Q(1, 1, n, a[a[x].t].i, a[x].i, s), sx = sx + s.ia, x = a[a[x].t].f;
        } else {
          Q(1, 1, n, a[a[y].t].i, a[y].i, s), sy = s.a + sy, y = a[a[y].t].f;
        }
      }
      if (a[x].i >= a[y].i) {
        Q(1, 1, n, a[y].i, a[x].i, s), sx = sx + s.ia;
      } else {
        Q(1, 1, n, a[x].i, a[y].i, s), sy = s.a + sy;
      }
      sx = sx + sy;
      // cout << sx.a[0] << " " << sx.a[1] << '\n';
      uLL ans = 0, x = 0;
      for (uLL i = 1uLL << k - 1; i; i >>= 1) {
        if (sx.a[0] & i) {
          ans |= i;
        } else if ((sx.a[1] & i) && (x | i) <= z) {
          ans |= i, x |= i;
        }
      }
      cout << ans << '\n';
    } else {
      U(1, 1, n, a[x].i, y, z);
    }
  }
  return 0;
}
/*
^1^2^1^2^3
01
10
01
10
11
*/
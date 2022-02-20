#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

int n, q, r, f[kN], d[kN], t[kN], c, s[kN], h[kN], l[kN], o, x, y, _d[kN];
LL p, a[kN], b[2][kN], v;
vector<int> e[kN];

void A(int o, int x, LL v) {
  v %= p;
  for (; x <= n; x += x & -x) {
    b[o][x] = (b[o][x] + v) % p;
  }
}
LL S(int o, int x) {
  LL _s = 0;
  for (; x; x -= x & -x) {
    _s = (_s + b[o][x]) % p;
  }
  return _s;
}
LL Do(int l, int r, LL v = 0) {
  v %= p;
  A(0, l, v), A(1, l, v * (l - 1)), A(0, r + 1, p - v), A(1, r + 1, (p - v) * r);
  return ((r * S(0, r) % p - S(1, r) + p) % p - (l - 1) * S(0, l - 1) % p + S(1, l - 1) + p) % p;
}
void D(int x, int _f) {
  s[x] = 1, f[x] = _f, d[x] = d[_f] + 1;
  for (int i : e[x]) {
    if (i != _f) {
      D(i, x), s[x] += s[i], (s[i] > s[h[x]]) && (h[x] = i);
    }
  }
}
void H(int x, int _t) {
  if (x) {
    l[_d[x] = ++c] = x, t[x] = _t, H(h[x], _t);
    for (int i : e[x]) {
      if (i != f[x] && i != h[x]) {
        H(i, i);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> r >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(r, 0), H(r, r);
  for (int i = 1; i <= n; ++i) {
    Do(i, i, a[l[i]]);
  }
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      cin >> y >> v;
      for (; t[x] ^ t[y];) {
        if (d[t[x]] < d[t[y]]) {
          swap(x, y);
        }
        Do(_d[t[x]], _d[x], v), x = f[t[x]];
      }
      if (d[x] > d[y]) {
        swap(x, y);
      }
      Do(_d[x], _d[y], v);
    } else if (o == 2) {
      cin >> y;
      LL s = 0;
      for (; t[x] ^ t[y];) {
        if (d[t[x]] < d[t[y]]) {
          swap(x, y);
        }
        s = (s + Do(_d[t[x]], _d[x])) % p, x = f[t[x]];
      }
      if (d[x] > d[y]) {
        swap(x, y);
      }
      cout << (s + Do(_d[x], _d[y])) % p << endl;
    } else if (o == 3) {
      cin >> v;
      Do(_d[x], _d[x] + s[x] - 1, v);
    } else {
      cout << Do(_d[x], _d[x] + s[x] - 1) << endl;
    }
  }
  return 0;
}
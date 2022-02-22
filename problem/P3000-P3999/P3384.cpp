#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

int n, q, r, f[kN], d[kN], t[kN], c, s[kN], h[kN], o, x, y, _d[kN];
LL p, a[kN], b[2][kN], v;
vector<int> e[kN];

void A(int o, int x, LL v) {
  for (v %= p; x <= n; b[o][x] = (b[o][x] + v) % p, x += x & -x) {
  }
}
LL S(int o, int x) {
  LL _s = 0;
  for (; x; _s = (_s + b[o][x]) % p, x -= x & -x) {
  }
  return _s;
}
LL Do(int l, int r, LL v = 0) { return v %= p, A(0, l, v), A(1, l, v * (l - 1)), A(0, r + 1, p - v), A(1, r + 1, (p - v) * r), ((r * S(0, r) % p - S(1, r) + p) % p - (l - 1) * S(0, l - 1) % p + S(1, l - 1) + p) % p; }
void D(int x, int _f) {
  s[x] = 1, f[x] = _f, d[x] = d[_f] + 1;
  for (int i : e[x]) {
    i != _f && (D(i, x), s[x] += s[i], s[i] > s[h[x]] && (h[x] = i));
  }
}
void H(int x, int _t) {
  if (x) {
    _d[x] = ++c, t[x] = _t, H(h[x], _t);
    for (int i : e[x]) {
      i != f[x] && i != h[x] && (H(i, i), 0);
    }
  }
}
LL P(int x, int y, LL v = 0) {
  LL s = 0;
  for (; t[x] ^ t[y]; d[t[x]] < d[t[y]] && (swap(x, y), 0), s = (s + Do(_d[t[x]], _d[x], v)) % p, x = f[t[x]]) {
  }
  return d[x] > d[y] && (swap(x, y), 0), (s + Do(_d[x], _d[y], v)) % p;
}

int main() {
  for (int i = (cin >> n >> q >> r >> p, 1); i <= n; cin >> a[i++]) {
  }
  for (int i = 1, x, y; i < n; cin >> x >> y, e[x].push_back(y), e[y].push_back(x), ++i) {
  }
  for (int i = (D(r, 0), H(r, r), 1); i <= n; Do(_d[i], _d[i], a[i]), ++i) {
  }
  for (; q--; ) {
    cin >> o >> x;
    if (o == 1) {
      cin >> y >> v, P(x, y, v);
    } else if (o == 2) {
      cin >> y, cout << P(x, y) << endl;
    } else if (o == 3) {
      cin >> v, Do(_d[x], _d[x] + s[x] - 1, v);
    } else {
      cout << Do(_d[x], _d[x] + s[x] - 1) << endl;
    }
  }
  return 0;
}
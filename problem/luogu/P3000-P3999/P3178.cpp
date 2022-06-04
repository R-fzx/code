#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, q, o, x, d[kN], h[kN], c, s[kN], f[kN], t[kN];
LL a[kN], b[2][kN], y;
vector<int> e[kN];

void D(int x, int _f) {
  f[x] = _f, s[x] = 1;
  for (int i : e[x]) {
    if (i ^ _f) {
      D(i, x), s[x] += s[i], s[i] > s[h[x]] && (h[x] = i);
    }
  }
}
void T(int x, int _t) {
  if (x) {
    d[x] = ++c, t[x] = _t, T(h[x], _t);
    for (int i : e[x]) {
      if ((i ^ f[x]) && (i ^ h[x])) {
        T(i, i);
      }
    }
  }
}
void A(int o, int x, LL v) {
  for (; x <= n; x += x & -x) {
    b[o][x] += v;
  }
}
LL S(int o, int x) {
  LL s = 0;
  for (; x; x -= x & -x) {
    s += b[o][x];
  }
  return s;
}
LL Do(int l, int r, LL v = 0) {
  A(0, l, v), A(1, l, (l - 1) * v), A(0, r + 1, -v), A(1, r + 1, -r * v);
  return r * S(0, r) - S(1, r) - (l - 1) * S(0, l - 1) + S(1, l - 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0), T(1, 1);
  for (int i = 1; i <= n; ++i) {
    Do(d[i], d[i], a[i]);
  }
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      cin >> y;
      Do(d[x], d[x], y);
    } else if (o == 2) {
      cin >> y;
      Do(d[x], d[x] + s[x] - 1, y);
    } else {
      LL s = 0;
      for (; x; x = f[t[x]]) {
        s += Do(d[t[x]], d[x]);
      }
      cout << s << endl;
    }
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
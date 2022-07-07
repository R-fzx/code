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
#include <random>
#include <set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const LL kM = 998244353;

struct M {
  int n, m;
  LL a[4][4];

  M() { fill(&a[0][0], &a[4][0], 0); }
  const M operator*(const M &o) const {
    M s;
    s.n = n, s.m = o.m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < o.m; ++j) {
        for (int k = 0; k < m; ++k) {
          s.a[i][j] = (s.a[i][j] + a[i][k] * o.a[k][j] % kM) % kM;
        }
      }
    }
    return s;
  }
  const M operator+(const M &o) const {
    M s;
    s.n = n, s.m = m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        s.a[i][j] = (a[i][j] + o.a[i][j]) % kM;
      }
    }
    return s;
  }
};
M B(int o = 0, LL v = 0) {
  M s;
  s.n = s.m = 4, s.a[0][0] = s.a[1][1] = s.a[2][2] = s.a[3][3] = 1;
  if (o >= 1 && o <= 3) {
    s.a[o % 3][o - 1] = 1;
  } else if (o) {
    s.a[o == 5 ? 1 : 3][o - 4] = v, s.a[2][2] = o != 6;
  }
  return s;
}

const int kN = 2.5e5;

struct E {
  M x, t;
} e[kN << 2];
void B(int x, int l, int r) {
  if (l == r) {
    e[x].t = B(), e[x].x.n = 1, e[x].x.m = 4;
    cin >> e[x].x.a[0][0] >> e[x].x.a[0][1] >> e[x].x.a[0][2];
    e[x].x.a[0][3] = 1;
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  e[x].t = B(), e[x].x = e[x * 2].x + e[x * 2 + 1].x;
}
void Mu(int x, const M &o) { e[x].x = e[x].x * o, e[x].t = e[x].t * o; }
const M Do(int x, int l, int r, int tl, int tr, const M &v, int t = 0) {
  if (l == tl && r == tr) {
    Mu(x, v);
    return e[x].x;
  }
  Mu(x * 2, e[x].t), Mu(x * 2 + 1, e[x].t), e[x].t = B();
  int m = l + r >> 1;
  M s;
  s.n = 1, s.m = 4;
  if (tl <= m) {
    s = s + Do(x * 2, l, m, tl, min(m, tr), v);
  }
  if (m < tr) {
    s = s + Do(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  e[x].x = e[x * 2].x + e[x * 2 + 1].x;
  return s;
}

int n, q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  B(1, 1, n);
  cin >> q;
  for (int o, l, r, v; q--;) {
    cin >> o >> l >> r;
    if (o >= 4 && o <= 6) {
      cin >> v;
    }
    if (o == 7) {
      const M s = Do(1, 1, n, l, r, B());
      cout << s.a[0][0] << ' ' << s.a[0][1] << ' ' << s.a[0][2] << '\n';
    } else {
      Do(1, 1, n, l, r, B(o, v));
    }
  }
  return 0;
}
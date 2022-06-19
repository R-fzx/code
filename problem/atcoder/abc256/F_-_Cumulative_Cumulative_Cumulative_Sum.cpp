#include <algorithm>
#include <atcoder/all>
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
using mL = atcoder::modint998244353;

const int kN = 2e5 + 1;

struct E {
  mL s, t;
} e[kN << 2];
int n, q;
mL a[kN];

void B(int x, int l, int r) {
  if (l == r) {
    e[x].s = a[l];
    return;
  }
  int m = l + r >> 1;
  B(x * 2, l, m), B(x * 2 + 1, m + 1, r);
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
}
void A(int x, int l, int r, mL v) { e[x].s += (r - l + 1) * v, e[x].t += v; }
mL Do(int x, int l, int r, int tl, int tr, mL v) {
  if (l == tl && r == tr) {
    A(x, l, r, v);
    return e[x].s;
  }
  int m = l + r >> 1;
  mL s = 0;
  A(x * 2, l, m, e[x].t), A(x * 2 + 1, m + 1, r, e[x].t), e[x].t = 0;
  if (tl <= m) {
    s += Do(x * 2, l, m, tl, min(m, tr), v);
  }
  if (m < tr) {
    s += Do(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, v);
  }
  e[x].s = e[x * 2].s + e[x * 2 + 1].s;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
  }
  B(1, 1, n);
  for (int o, x, v; q--; ) {
    cin >> o >> x;
    if (o == 1) {

    } else {
      cout << Do(1, 1, n, 1, x, 0).val() << '\n';
    }
  }
  return 0;
}
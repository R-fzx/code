#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using namespace atcoder;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1, kQ = 1e6 + 1, kB = 500;

int n, m, a[kN], ans[kQ], c[kN], s;
struct Q {
  int l, r, d;
  bool operator<(const Q& y) const {
    return l / kB != y.l / kB ? l < y.l : r < y.r;
  }
} q[kQ];

void A(int x) { s += c[x]++ & 1; }
void D(int x) { s -= --c[x] & 1; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].l >> q[i].r;
    q[i].d = i;
  }
  sort(q + 1, q + m + 1);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    for (; r < q[i].r; A(a[++r])) {
    }
    for (; l > q[i].l; A(a[--l])) {
    }
    for (; r > q[i].r; D(a[r--])) {
    }
    for (; l < q[i].l; D(a[l++])) {
    }
    ans[q[i].d] = s;
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
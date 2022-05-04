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
using mL = modint998244353;

const int kN = 2e5 + 1, kV = 1e6 + 1;

int n, q, a[kN], _c[kV];
map<int, int> c[kV];
bool v[kV];
mL f[kN], p[kV] = {1}, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 2; i < kV; ++i) {
    if (!v[i]) {
      for (int j = i; j < kV; j += i) {
        v[j] = 1;
        for (int k = j; k % i == 0; k /= i) {
          ++c[j][i];
        }
      }
    }
  }
  for (int i = 1; i < kV; ++i) {
    p[i] = p[i - 1] * 19260817;
  }
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (auto [p, c] : ::c[a[i]]) {
      c %= 3;
      debug("%d %d\n", p, c);
      x -= ::p[p] * _c[p], _c[p] = (_c[p] + c) % 3, x += ::p[p] * _c[p];
    }
    f[i] = x;
    debug("%u\n", f[i].val());
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (f[l - 1] == f[r] ? "Yes" : "No") << endl;
  }
  return 0;
}
/*

*/
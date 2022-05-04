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

const int kN = 1e7 + 1;

int n, x, y, z;
mL f[kN] = {1}, vf[kN], ans;

mL C(int n, int m) { return n >= m && n >= 0 && m >= 0 ? f[n] * vf[m] * vf[n - m] : 0; }
mL S(int n, int x) { return (n - x & 1) ? 0 : C(n, (n - x) / 2); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x >> y >> z;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i;
  }
  vf[n] = 1;
  mL b = f[n];
  for (int e = 998244351; e; e >>= 1, b *= b) {
    if (e & 1) {
      vf[n] *= b;
    }
  }
  for (int i = n - 1; ~i; --i) {
    vf[i] = vf[i + 1] * (i + 1);
  }
  for (int i = 0; i <= n; ++i) {
    ans += C(n, i) * S(i, z) * S(n - i, x + y) * S(n - i, x - y);
  }
  cout << ans.val();
  return 0;
}
/*
(x,y) -> (x+y,x-y)
(0,-1)-> (-1,1)
(0,1) -> (1,-1)
(-1,0)-> (-1,-1)
(1,0) -> (1,1)

*/
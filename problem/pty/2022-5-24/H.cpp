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

const int kN = 1e5 + 1;

int t;
LL x, f[kN] = {0, 1}, s[kN] = {0, 1};

LL C(LL x) {
  LL y = sqrt(x);
  return y - (y * y > x);
}

int main() {
  for (int i = 2; i < kN; ++i) {
    f[i] = s[C(i)], s[i] = s[i - 1] + f[i];
  }
  cin >> t;
  while (t--) {
    cin >> x;
    LL sx = C(x), ssx = C(sx), ans = 0;
    for (LL i = 1; i <= ssx; ++i) {
      ans += (sx - i * i + 1) * f[i];
    }
    cout << ans << endl;
  }
}

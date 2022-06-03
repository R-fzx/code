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
using B = bitset<26>;

const int kN = 18;

int n, l;
B a[kN];
mL ans;

mL C(B x) { return mL(x.count()).pow(l); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> l;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) {
      a[i][c - 'a'] = 1;
    }
  }
  for (int i = 1; i < 1 << n; ++i) {
    int c = 0;
    B x = 0;
    x.flip();
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        c ^= 1, x &= a[j];
      }
    }
    debug("%d %d %u\n", i, c, C(x));
    ans += C(x) * (c ? 1 : -1);
  }
  cout << ans.val();
  return 0;
}
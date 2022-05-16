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

int t, n;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int l = 0;
    string _s(n, ' ');
    for (int i = 0, j = n - 1; i <= j; ++i, --j, ++l) {
      _s[i] = _s[j] = s[i];
    }
    mL ans = 0;
    for (int i = 0; i < l; ++i) {
      ans = ans * 26 + s[i] - 'A';
    }
    ans += _s <= s;
    cout << ans.val() << endl;
  }
  return 0;
}
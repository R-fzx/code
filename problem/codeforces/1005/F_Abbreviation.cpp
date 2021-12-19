#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
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
using ULL = unsigned long long;
using Pll = pair<LL, LL>;
using Pdd = pair<double, double>;
using Vl = vector<LL>;
using Mll = map<LL, LL>;

const int kN = 301;

int n, ans, a[kN], _s[kN], f[kN][kN];
string s[kN], b[kN];

int main() {
  // freopen("F.in", "r", stdin);
  // freopen("F.out", "w", stdout);
  // freopen("F.log", "w", stderr);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    b[i] = s[i], _s[i] = _s[i - 1] + s[i].size();
  }
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - b;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(b + 1, b + m, s[i]) - b;
  }
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      for (; r + f[l][r] <= n && a[l + f[l][r]] == a[r + f[l][r]]; ++f[l][r]) {
      }
    }
  }
  for (int l = 1; l <= n; ++l) {
    for (int _l = 1, r; (r = l + _l - 1) <= n; ++_l) {
      int c = 0;
      for (int i = l; i <= n; ++i) {
        if (f[l][i] >= _l) {
          ++c, i += _l - 1;
        }
      }
      ans = max(ans, (c > 1) * c * (_s[r] - _s[l - 1] - 1));
    }
  }
  cout << _s[n] + n - 1 - ans;
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
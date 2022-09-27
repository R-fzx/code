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

const int kN = 1e6 + 1;

int t, n;
string s;
bool v[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> s;
    s = " " + s, fill_n(v + 1, n, 0);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n && s[j] == '0'; j += i) {
        if (!v[j]) {
          v[j] = 1, ans += i;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
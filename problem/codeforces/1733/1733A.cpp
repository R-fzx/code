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

const int kN = 101;

int t, n, k, c[kN];
LL a[kN], ans;
vector<int> b[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
      b[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      b[i % k].push_back(a[i]);
    }
    for (int i = 0; i < k; ++i) {
      sort(b[i].begin(), b[i].end(), greater<int>());
    }
    ans = 0;
    for (int i = 1; i + k <= n + 1; ++i) {
      fill_n(c, k, 0);
      LL s = 0;
      for (int j = i; j < i + k; ++j) {
        s += b[j % k][c[j % k]++];
      }
      ans = max(ans, s);
    }
    cout << ans << '\n';
  }
  return 0;
}
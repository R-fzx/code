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

const int kN = 2e5 + 1;

int t, n, a[kN], b[kN], c;
LL ans;

int F(int x) {
  return b[x] == x ? x : (b[x] = F(b[x]));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      c += !a[i];
    }
    c -= !a[n];
    b[n] = n;
    for (int i = 1; i < n; ++i) {
      b[i] = i + (!!a[i]);
    }
    ans = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i]) {
        while (c && a[i]) {
          ++ans, --a[i], --c, ++a[F(i)], b[F(i)] = F(F(i) + 1);
        }
        ans += a[i], a[F(i)] += a[i], a[i] = 0;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
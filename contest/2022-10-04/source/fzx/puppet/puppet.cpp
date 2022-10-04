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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 104;

int n, a[kN], _a[kN], ans;

int main() {
  RF("puppet");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (; cin >> n;) {
    fill(a + 1, a + kN, 0);
    for (int i = 1, x; i <= n; ++i) {
      cin >> x, ++a[x];
    }
    ans = 0;
    for (int i = 1; i <= 3; ++i) {
      int s = 0;
      for (int j = i; j <= n; j += 5) {
        int x = min(a[j + 1], a[j - 1] + a[j + 3]);
        s += x;
      }
      ans = max(ans, s);
    }
    cout << ans << '\n';
  }
  return 0;
}
/*
1 2 3 4 5
1 2 2 2 1
1 2 2 2 1

0 2 0 0 1
0 0 0 2 1

1 0 1
0 0 2

x y z
x y z

x y 0
x y 0

t x y z v
t x y z v
min(y,t+v)>=p: cost p

a 0 p 0 b
t 0 0 0 v
*/
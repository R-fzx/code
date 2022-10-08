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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;
const string kT[4] = {"impossible", "row", "column", "both"};

int n, m, t, a[kN], b[kN], at;
LL s, c[kN];

int main() {
  RF("tanabata");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> t;
  for (int i = 1, x, y; i <= t; ++i) {
    cin >> x >> y;
    ++a[x], ++b[y];
  }
  if (t % n == 0) {
    at |= 1;
    int p = t / n;
    for (int i = 2; i <= n; ++i) {
      c[i] = c[i - 1] + p - a[i];
    }
    sort(c + 1, c + n + 1);
    int x = c[(n + 1) / 2];
    for (int i = 1; i <= n; ++i) {
      s += abs(x - c[i]);
    }
  }
  if (t % m == 0) {
    at |= 2;
    int p = t / m;
    for (int i = 2; i <= m; ++i) {
      c[i] = c[i - 1] + p - b[i];
    }
    sort(c + 1, c + m + 1);
    int x = c[(m + 1) / 2];
    for (int i = 1; i <= m; ++i) {
      s += abs(x - c[i]);
    }
  }
  cout << kT[at];
  if (at) {
    cout << ' ' << s;
  }
  return 0;
}
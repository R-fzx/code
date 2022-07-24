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

const int kN = 2e5 + 1, kM = 1602;

int t, n, m, q, c;
string s;
Pll a[kM];
LL b[kM];

int F(LL x) {
  int l = 1, r = c;
  while (l < r) {
    int m = l + r >> 1;
    if (b[m] >= x) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> q >> s;
    s = " " + s, a[c = 1] = {1, n}, b[1] = n;
    for (int i = 1, j, k; i <= m; ++i) {
      LL l, r;
      cin >> l >> r;
      j = F(l), k = F(r);
      l -= b[j - 1], r -= b[k - 1];
      if (j == k) {
        a[++c] = {l + a[j].first - 1, r + a[k].first - 1};
        b[c] = b[c - 1] + a[c].second - a[c].first + 1;
      } else {
        a[++c] = {l + a[j].first - 1, a[j].second};
        b[c] = b[c - 1] + a[c].second - a[c].first + 1;
        for (++j; j < k; ++j) {
          a[++c] = a[j];
          b[c] = b[c - 1] + a[c].second - a[c].first + 1;
        }
        a[++c] = {a[k].first, r + a[k].first - 1};
        b[c] = b[c - 1] + a[c].second - a[c].first + 1;
      }
    }
    for (int i = 1; i <= q; ++i) {
      LL x;
      cin >> x;
      int j = F(x);
      cout << s[x - b[j - 1] + a[j].first - 1] << '\n';
    }
  }
  return 0;
}
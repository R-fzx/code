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

const int kM = 101, kT = 2001;

struct E {
  int a, b, t;
  bool operator<(const E &o) const { return a < o.a; }
} a[kM];
int n, k, m, mt, fl[kM][kM][kT], fr[kM][kM][kT], ans;

int main() {
  RF("go");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].t;
    mt = max(mt, a[i].t);
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 1; k <= mt; ++k) {
        fl[i][j][k] = fr[i][j][k] = -1e6;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = abs(k - a[i].a) + 1; j <= mt; ++j) {
      ans = max(ans, fl[i][i][j] = fr[i][i][j] = (j <= a[i].t) * a[i].b);
    }
  }
  for (int l = 2; l <= m; ++l) {
    for (int i = 1, j = l; j <= m; ++i, ++j) {
      for (int k = 1; k <= mt; ++k) {
        // fl[i+1][j][k-(a[i+1]-a[i])] -> fl[i][j][k]
        if (k > a[i + 1].a - a[i].a) {
          fl[i][j][k] = max(fl[i][j][k], fl[i + 1][j][k - (a[i + 1].a - a[i].a)] + (k <= a[i].t) * a[i].b);
        }
        // fr[i][j-1][k-(a[j]-a[j-1])] -> fr[i][j][k]
        if (k > a[j].a - a[j - 1].a) {
          fr[i][j][k] = max(fr[i][j][k], fr[i][j - 1][k - (a[j].a - a[j - 1].a)] + (k <= a[j].t) * a[j].b);
        }
        // fl[i][j-1][k-(a[j]-a[i])] -> fr[i][j][k]
        // fr[i+1][j][k-(a[j]-a[i])] -> fl[i][j][k]
        if (k > a[j].a - a[i].a) {
          fr[i][j][k] = max(fr[i][j][k], fl[i][j - 1][k - (a[j].a - a[i].a)] + (k <= a[j].t) * a[j].b);
          fl[i][j][k] = max(fl[i][j][k], fr[i + 1][j][k - (a[j].a - a[i].a)] + (k <= a[i].t) * a[i].b);
        }
        ans = max({ans, fl[i][j][k], fr[i][j][k]});
      }
    }
  }
  // for (int i = 1; i <= m; ++i) {
  //   for (int j = i; j <= m; ++j) {
  //     for (int k = 1; k <= mt; ++k) {
  //       cout << fl[i][j][k] << ' ';
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
  // cout << "===========================\n";
  // for (int i = 1; i <= m; ++i) {
  //   for (int j = i; j <= m; ++j) {
  //     for (int k = 1; k <= mt; ++k) {
  //       cout << fr[i][j][k] << ' ';
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
  cout << ans;
  return 0;
}
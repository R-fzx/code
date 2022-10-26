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

const int kN = 201, kK = 41, kM = 7;

int n, k, m, f[kN][kK], b[kN];
string s, a[kM];

int C(int i, int j) {
  int c = 0;
  for (int k = i; k <= j; ++k) {
    c += b[k] <= j;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    string _s;
    cin >> _s;
    s += _s;
  }
  n *= 20;
  fill_n(b + 1, n, 1000);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    for (int j = 1; j <= n; ++j) {
      if (s.substr(j - 1, a[i].size()) == a[i]) {
        b[j] = min(b[j], (int)a[i].size() + j - 1);
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cerr << b[i] << ' ';
  // }
  // cerr << '\n';
  fill_n(f[0] + 1, k, -1000);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      f[i][j] = -1000;
      for (int x = i; x >= 1; --x) {
        f[i][j] = max(f[i][j], f[x - 1][j - 1] + C(x, i));
      }
    }
  }
  cout << f[n][k];
  return 0;
}
/*
1 3
thisisabookyouareaoh
4
is
a
ok
sab

00202310020000100100
thisisabookyouareaoh
  isis
      a       a  a
         ok
     sab
*/
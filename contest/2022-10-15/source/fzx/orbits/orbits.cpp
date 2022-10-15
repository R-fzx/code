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

const int kN = 3001, kC = 6501, kM = 10007;

int n, m, k, f[kC], g[kN][kC];
vector<int> lk, plk;
vector<vector<int>> llk;
map<int, int> d;

int main() {
  RF("orbits");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      lk.push_back(i);
    }
  }
  for (int i = lk.size() - 1; i >= 0; --i) {
    if (k / lk[i] != lk[i]) {
      lk.push_back(k / lk[i]);
    }
  }
  int x = k;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      plk.push_back(i);
      for (; x % i == 0; x /= i) {
      }
    }
  }
  if (x > 1) {
    plk.push_back(x);
  }
  for (int i = 0; i < lk.size(); ++i) {
    int x = lk[i], _m = m / x;
    d[x] = i;
    for (int j = 0; j < 1 << plk.size(); ++j) {
      int c = 0, s = 1;
      for (int k = 0; k < plk.size(); ++k) {
        if (j >> k & 1) {
          ++c, s *= plk[k];
        }
      }
      f[i] = (f[i] + ((c & 1) ? -1 : 1) * (_m / s) % kM) % kM;
    }
    g[1][i] = f[i];
  }
  for (int i = 0; i < lk.size(); ++i) {
    vector<int> _l;
    for (int j = 0; j <= i; ++j) {
      if (lk[i] % lk[j] == 0) {
        _l.push_back(j);
      }
    }
    llk.push_back(_l);
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j < lk.size(); ++j) {
      for (int k : llk[j]) {
        g[i][j] = (g[i][j] + g[i - 1][k] * f[d[lk[j] / lk[k]]] % kM) % kM;
      }
    }
  }
  cout << g[n][lk.size() - 1];
  return 0;
}
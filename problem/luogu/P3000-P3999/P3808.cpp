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

int n, e[kN][26], c[kN], p[kN], _c, q[kN], h = 1, t, ans;

int main() {
  // freopen("P3808_2.in", "r", stdin);
  // freopen("P3808.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    string s;
    cin >> s, x = 0;
    for (char j : s) {
      int &y = e[x][j - 'a'];
      !y && (y = ++_c), x = y;
    }
    ++c[x];
  }
  for (int i = 0; i < 26; ++i) {
    if (e[0][i]) {
      q[++t] = e[0][i];
    }
  }
  for (; h <= t; ++h) {
    int x = q[h];
    for (int i = 0; i < 26; ++i) {
      if (e[x][i]) {
        p[e[x][i]] = e[p[x]][i], q[++t] = e[x][i];
      } else {
        e[x][i] = e[p[x]][i];
      }
    }
  }
  string t;
  cin >> t;
  int x = 0;
  for (char i : t) {
    x = e[x][i - 'a'];
    for (int y = x; y && ~c[y]; y = p[y]) {
      ans += c[y], c[y] = -1;
    }
  }
  cout << ans;
  return 0;
}
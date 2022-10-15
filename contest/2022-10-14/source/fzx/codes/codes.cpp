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

const int kN = 21;

int n, l = kN * kN;
string s[kN], ans;

void D(string x, string y) {
  if (x.size() > l || y.size() > l) {
    return;
  }
  if (x.size() == y.size()) {
    if (x.size() < l) {
      l = x.size(), ans = x;
    } else if (x.size() == l && x < ans) {
      ans = x;
    }
  }
  if (x.size() > y.size()) {
    swap(x, y);
  }
  /*
  abcd
  abcdbc
  */
  for (int i = 1; i <= n; ++i) {
    int _l = min(y.size() - x.size(), s[i].size());
    if (y.substr(x.size(), _l) == s[i].substr(0, _l)) {
      D(x + s[i], y);
    }
  }
}

int main() {
  RF("codes");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j && s[i].size() <= s[j].size() && s[i] == s[j].substr(0, s[i].size())) {
        D(s[i], s[j]);
      }
    }
  }
  cout << l << '\n'
       << ans;
  return 0;
}
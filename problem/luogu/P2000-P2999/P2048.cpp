#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, r[kN], d[kN], sa[kN], h[kN], ht[kN];
string s;
Pii a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s;
  s = " " + s;
  iota(d + 1, d + n + 1, 1);
  stable_sort(d + 1, d + n + 1, [](int i, int j) { return s[i] < s[j]; });
  for (int i = 1; i <= n; ++i) {
    r[d[i]] = r[d[i - 1]] + (s[d[i]] != s[d[i - 1]]);
  }
  for (int l = 1; l <= n; l <<= 1) {
    for (int i = 1; i <= n; ++i) {
      a[i] = {r[i], i + l <= n ? r[i + l] : 0};
    }
    iota(d + 1, d + n + 1, 1);
    stable_sort(d + 1, d + n + 1, [](int i, int j) { return a[i] < a[j]; });
    for (int i = 1; i <= n; ++i) {
      r[d[i]] = r[d[i - 1]] + (a[d[i]] != a[d[i - 1]]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    sa[r[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", sa[i]);
  }
  debug("\n");
  for (int i = 1, j = 0; i <= n; ++i) {
    for (j -= !!j; s[i + j] == s[sa[r[i] - 1] + j]; ++j) {
    }
    h[i] = ht[r[i]] = j;
  }
  LL s = 1LL * n * (n + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    s -= ht[i];
  }
  cout << s;
  return 0;
}
/*
banana:

a 0
ana 1
anana 3
banana 0
na 0
nana 2

h: 0 3 2 1 0 0

height[i] = LCP(sa[i], sa[i + 1])
h[i] = height[rk[i]]
h[i] >= h[i - 1] - 1
*/
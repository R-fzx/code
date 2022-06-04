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
#include <set>
#include <string>
#include <vector>
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

const int kN = 1e6 + 1;

string s;
int n, r[kN], d[kN], sa[kN];
Pii a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size(), s = " " + s;
  iota(d + 1, d + n + 1, 1);
  stable_sort(d + 1, d + n + 1, [](int i, int j) { return s[i] < s[j]; });
  for (int i = 1; i <= n; ++i) {
    r[d[i]] = r[d[i - 1]] + (s[d[i]] != s[d[i - 1]]);
  }
  for (int i = 1; i <= n; ++i) {
    debug("%d ", r[i]);
  }
  debug("\n");
  for (int l = 1; l <= n << 1; l <<= 1) {
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
    debug("%d ", r[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << sa[i] << " ";
  }
  return 0;
}
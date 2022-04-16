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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 2;

int t, n;
LL p[kN], s[kN], a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
      a[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    for (int _ = 1; _ <= 1000; ++_) {
      int c = 0;
      for (int i = 1; i <= n; ++i) {
        if (~p[i - 1] && ~p[i] && !~a[i]) {
          a[i] = p[i] ^ p[i - 1], ++c;
        }
      }
      for (int i = n; i >= 1; --i) {
        if (~s[i + 1] && ~s[i] && !~a[i]) {
          a[i] = s[i] ^ s[i + 1], ++c;
        }
      }
      if (!c) {
        bool f = 0;
        for (int i = 1; i <= n; ++i) {
          if (!~a[i]) {
            a[i] = 0, f = 1;
            break;
          }
        }
        if (!f) {
          break;
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (~a[i] && ~p[i - 1]) {
          p[i] = p[i - 1] ^ a[i];
        }
      }
      for (int i = n; i >= 1; --i) {
        if (~a[i] && ~s[i + 1]) {
          s[i] = s[i + 1] ^ a[i];
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
      debug("%d %d\n", p[i], s[i]);
    }
  }
  return 0;
}
/*
 */
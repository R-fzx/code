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

int t, a0, a1, b0, b1;
map<int, int> la0, la1, lb0, lb1, l;
LL ans;

void C(int x, map<int, int> &l) {
  l.clear();
  for (int i = 2; i * i <= x; ++i) {
    int c = 0;
    for (; x % i == 0; x /= i, ++c) {
    }
    if (c) {
      l[i] = c;
    }
  }
  if (x > 1) {
    l[x] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> a0 >> a1 >> b0 >> b1;
    C(a0, la0), C(a1, la1), C(b0, lb0), C(b1, lb1);
    l.clear();
    for (Pii i : la0) {
      // cerr << i.first << ' ';
      l[i.first] = 1;
    }
    // cerr << '\n';
    for (Pii i : lb1) {
      // cerr << i.first << ' ';
      l[i.first] = 1;
    }
    // cerr << '\n';
    ans = 1;
    // for (Pii i : l) {
    //   cerr << i.first << ' ';
    // }
    // cerr << '\n';
    for (auto [i, _] : l) {
      // cerr << i << ' ' << la0[i] << ' ' << la1[i] << ' ' << lb0[i] << ' ' << lb1[i] << '\n';
      a0 = la0[i], a1 = la1[i], b0 = lb0[i], b1 = lb1[i];
      if (a0 == a1 && b0 == b1) {
        if (b0 < a0) {
          ans = 0;
          break;
        }
        ans *= b0 - a0 + 1;
      } else if (a0 == a1) {
        if (b1 < a0) {
          ans = 0;
          break;
        }
      } else if (b0 == b1) {
        if (a1 > b0) {
          ans = 0;
          break;
        }
      } else {
        if (a1 != b1) {
          ans = 0;
          break;
        }
      }
    }
    // cerr << '\n';
    cout << ans << '\n';
  }
  return 0;
}
/*
1
24843 1 999998980 1999997960
*/
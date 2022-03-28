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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int t;
LL x, z;
map<LL, Pii> m;

LL P(LL b, LL e) {
  LL s = 1;
  for (; e; e >>= 1, b = b * b) {
    if (e & 1) {
      s = s * b;
    }
  }
  return s;
}
LL S() {
  LL y = 1;
  for (auto &p : m) {
    int _x = p.second.first, _z = p.second.second, v = INT32_MAX;
    if (_z >= 3 * _x) {
      v = _z - _x - _x;
    } 
    if (_z >= _x && (_z - _x) % 2 == 0) {
      v = min(v, _z - _x >> 1);
    }
    if (v == INT32_MAX) {
      return -1;
    }
    y *= P(p.first, v);
  }
  return y;
}

int main() {
#define FILEIO(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout);
  FILEIO("math")
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    m.clear();
    cin >> x >> z;
    for (LL i = 2; i <= x; ++i) {
      int c = 0;
      for (; x % i == 0; x /= i, ++c) {
      }
      if (c) {
        m[i].first = c;
      }
    }
    for (LL i = 2; i <= z; ++i) {
      int c = 0;
      for (; z % i == 0; z /= i, ++c) {
      }
      if (c) {
        m[i].second = c;
      }
    }
    cout << S() << '\n';
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
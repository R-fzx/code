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
using Pil = pair<int, LL>;

const int kN = 5e4 + 1;

struct L {
  static const int kL = 60;

  LL a[kL];

  void I(LL x) {
    for (int i = kL - 1; ~i; --i) {
      if (x >> i & 1) {
        if (!a[i]) {
          a[i] = x;
          break;
        }
        x ^= a[i];
      }
    }
  }
  LL M(LL r) {
    for (int i = kL - 1; ~i; --i) {
      r = max(r, r ^ a[i]);
    }
    return r;
  }
} l;
int n, m, f[kN], q[kN], h = 1, t;
vector<Pil> e[kN];
LL d[kN];

void R(int x, int y, LL _d) {
  if (f[x] ^ y) {
    if (f[y]) {
      l.I(d[y] ^ _d);
    } else {
      f[y] = x, d[y] = _d, q[++t] = y;
    }
  }
}
void B() {
  for (R(-1, 1, 0); h <= t; ++h) {
    for (auto [y, w] : e[q[h]]) {
      R(q[h], y, d[q[h]] ^ w);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    LL w;
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  B();
  cout << l.M(d[n]);
  return 0;
}
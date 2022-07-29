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

const int kN = 1e5 + 1;

int n, m, p[kN];
string _;
LL a[kN], f[kN][2], s;
vector<int> e[kN];

void D(int x, int _f) {
  p[x] = _f;
  int y = 0;
  f[0][1] = 1e11;
  for (int i : e[x]) {
    if (i != _f) {
      D(i, x);
      f[x][1] += min(f[i][0], f[i][1]);
      if (f[i][1] < f[y][1]) {
        y = i;
      }
    }
  }
  
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> _;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i], s += a[i];
  }
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0);
    for (int i = 1; i <= n; ++i) {
      debug("%lld %lld\n", f[i][0], f[i][1]);
    }
    debug("%lld\n\n", s);
  for (int a, b; m--; ) {
    LL x, y;
    cin >> a >> x >> b >> y;
    x = (x ? -1e11 : 1e11), y = (y ? -1e11 : 1e11), ::a[a] += x, ::a[b] += y, s += max(x, 0LL) + max(y, 0LL);
    for (int j = a; j; j = p[j]) {
      f[j][1] = ::a[j], f[j][0] = 0;
      for (int i : e[j]) {
        if (i != p[j]) {
          f[j][0] += max(f[i][0], f[i][1]), f[j][1] += f[i][0];
        }
      }
    }
    for (int j = b; j; j = p[j]) {
      f[j][1] = ::a[j], f[j][0] = 0;
      for (int i : e[j]) {
        if (i != p[j]) {
          f[j][0] += max(f[i][0], f[i][1]), f[j][1] += f[i][0];
        }
      }
    }
    LL _s = s - max(f[1][0], f[1][1]);
    cout << (_s > 1e11 ? -1 : _s) << '\n';
    s -= max(x, 0LL) + max(y, 0LL), ::a[a] -= x, ::a[b] -= y;
  }
  return 0;
}
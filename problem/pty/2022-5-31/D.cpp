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

const int kN = 2e5 + 1;

int n, d[kN], x, y, z, s, p[kN];
vector<int> e[kN], l;

void D(int x, int f) {
  d[x] = d[f] + 1, p[x] = f;
  for (int i : e[x]) {
    if (i ^ f) {
      D(i, x);
    }
  }
}
Pii S(int x, int f) {
  int d = 0, y = x;
  for (int i : e[x]) {
    if (i ^ f) {
      Pii v = S(i, x);
      if (v.first > d) {
        d = v.first, y = v.second;
      }
    }
  }
  return {d, y};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  D(1, 0), x = max_element(d + 1, d + n + 1) - d, D(x, 0), y = max_element(d + 1, d + n + 1) - d, s += d[y] - 1;
  debug("%d\n", s);
  for (int i = y; i != x; i = p[i]) {
    l.push_back(i);
  }
  l.push_back(x);
  for (int i : l) {
    debug("%d ", i);
  }
  debug("\n");
  int _s = 0;
  for (int i = 0; i < l.size(); ++i) {
    int d = 0, y = -1;
    for (int j : e[l[i]]) {
      if ((!i || j != l[i - 1]) && (i + 1 == l.size() || j != l[i + 1])) {
        Pii x = S(j, l[i]);
        debug("(%d,%d) ", x.first, x.second);
        if (x.first + 1 > d) {
          d = x.first + 1, y = x.second;
        }
      }
    }
    debug("%d %d\n", d, y);
    if (d > _s) {
      _s = d, z = y;
    }
  }
  printf("%d\n%d %d %d", s + _s, x, y, z ? z : l[1]);
  return 0;
}
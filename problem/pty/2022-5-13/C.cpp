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

const int kN = 2e5 + 2;

int n, m, x, y;
LL a[kN];

void A(int x, LL v) {
  for (; x <= n; a[x] += v, x += x & -x) {
  }
}
void A(int l, int r, LL v) {
  debug("Range [%d, %d], %lld\n", l, r, v);
  A(l, v), A(r + 1, -v);
}
LL Q(int x) {
  LL s = 0;
  for (; x; s += a[x], x -= x & -x) {
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> x;
  for (int i = 1; i < m; ++i, x = y) {
    cin >> y;
    int _x = x, _y = y;
    if (x == y) {
      continue;
    } else if (x > y) {
      swap(_x, _y);
    }
    A(1, _x - 1, abs(_x - _y)), A(_x, _x, abs(1 - _y)), A(_x + 1, _y - 1, abs(_x + 1 - _y)), A(_y, _y, _x), A(_y + 1, n, abs(_x - _y));
    debug("\n");
  }
  for (int i = 1; i <= n; ++i) {
    cout << Q(i) << ' ';
  }
  return 0;
}
/*
1,2,3,4
2,1,3,4
3,1,2,4
4,1,2,3

x y
0 x-y
1 y-x
p[1]~p[x-1]: x->x
p[x]: x->1
p[x+1]~p[n]: x->x+1

x<y
p[1]~p[x-1]: |x-y|
p[x]: |1-y|
p[x+1]~p[y-1]: |x+1-y|
p[y]: |x+1-1| = x
p[y+1]~p[n]: |x+1-y-1| = |x-y|
*/
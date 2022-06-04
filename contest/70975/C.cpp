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

const int kN = 20;

LL n, ans, f[kN][2];
int a[kN], l;

LL S(int x, bool m) {
  debug("%d %d\n", x, m);
  if (!x) {
    return 1;
  }
  if (~f[x][m]) {
    return f[x][m];
  }
  LL ans = 0;
  for (int i = 0, _m = m ? a[x] : 9; i <= _m; ++i) {
    if (i != 4) {
      ans += S(x - 1, m && i == _m);
    }
  }
  return f[x][m] = ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (; n; n /= 10) {
    a[++l] = n % 10;
  }
  fill(&f[0][0], &f[l][1] + 1, -1);
  cout << S(l, 1) - 1;
  return 0;
}
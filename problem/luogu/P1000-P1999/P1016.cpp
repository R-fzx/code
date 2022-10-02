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

const int kN = 8;

int n;
double d1, c, d2, p[kN], d[kN], ans = 1e9;

void D(int x, double t, double s, int _t = 0) {
  debug("% *s%d %lf %lf\n", _t, "", x, t, s);
  if (x == n + 1) {
    ans = min(ans, s);
    return;
  }
  for (int i = x + 1; i <= n + 1; ++i) {
    if ((d[i] - d[x]) / d2 <= c) {
      if ((d[i] - d[x]) / d2 >= t) {
        D(i, 0, s + ((d[i] - d[x]) / d2 - t) * p[x], _t + 1);
      }
      D(i, c - (d[i] - d[x]) / d2, s + (c - t) * p[x], _t + 1);
    }
    if (t * d2 >= d[i] - d[x]) {
      D(i, t - (d[i] - d[x]) / d2, s, _t + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> d1 >> c >> d2 >> p[0] >> n, d[n + 1] = d1;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i] >> p[i];
  }
  D(0, 0, 0);
  if (ans == 1e9) {
    cout << "No Solution";
  } else {
    cout << fixed << setprecision(2) << ans;
  }
  return 0;
}
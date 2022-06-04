#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
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

int n;
double f[kN], a[kN], b[kN], r[kN], p[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> f[0];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> r[i];
    p[i] = r[i] * a[i] + b[i];
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    for (int j = 1; j < i; ++j) {
      f[i] = max(f[i], f[j] * ( r[j] * a[i] + b[i]) / p[j]);
    }
    debug("%.3lf %.3lf %.3lf %.3lf\n", f[i], a[i], b[i], r[i]);
  }
  cout << fixed << setprecision(3) << f[n];
  return 0;
}
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

const int kN = 1e4 + 1;

int n;
LL c, p[kN], s[kN], f[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] + s[i];
    for (int j = i - 1; j >= 1; --j) {
      f[j] = min(f[j - 1] + s[i], f[j] + p[i] + c * j);
    }
    f[0] = f[0] + p[i];
  }
  LL m = 1e18;
  for (int i = 0; i <= n; ++i) {
    m = min(m, f[i]);
  }
  cout << m;
  return 0;
}
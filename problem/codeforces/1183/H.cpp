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

const int kN = 101;

int n, p[26];
char a[kN];
LL k, f[kN][kN], s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  scanf("%d %lld %s", &n, &k, a + 1);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x = a[i] - 'a';
    for (int j = 0; j <= i; ++j) {
      f[i][j] = f[i - 1][j] + (j ? f[i - 1][j - 1] : 0);
      if (p[x] && j >= i - p[x]) {
        f[i][j] -= f[p[x] - 1][j - i + p[x]];
      }
    }
    p[x] = i;
  }
  for (int i = 0; i <= n; ++i) {
    s += min(k, f[n][i]) * i, k -= min(k, f[n][i]);
    if (!k) {
      break;
    }
  }
  cout << (k ? -1 : s);
  return 0;
}
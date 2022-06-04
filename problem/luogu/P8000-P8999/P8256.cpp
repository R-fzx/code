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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 402;
const LL kM = 1e9 + 7;

int t, n, m;
string a, b;
LL f[kN][kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--;) {
    cin >> n >> m >> a >> b;
    a = " " + a, b = " " + b;
    int l = count(a.begin(), a.end(), '-');
    debug("%d\n", l);
    debug("%d %d\n", n, m);
    debug("%s %s\n", a.c_str(), b.c_str());
    if (n - l * 2 != m) {
      cout << 0 << endl;
    } else {
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
          for (int k = 0; k <= m; ++k) {
            f[i][j][k] = 0;
          }
        }
      }
      f[0][0][0] = 1;
      for (int i = 1, c = 0; i <= n; ++i) {
        c += (a[i] == '-' ? -1 : 1);
        for (int j = 0; j <= l; ++j) {
          for (int k = 0; j <= l; ++k) {
            if (a[i] == '-') {
              f[i][j][k] = (f[i - 1][j + 1][k] + f[i - 1][j][k + 1]) % kM;
            } else {
              if (k > 0) {
                f[i][j][k] = f[i - 1][j][k - 1];
              } else if (a[i] == b[c - j]) {
                f[i][j][k] = f[i - 1][j][k];
              }
              if (c == j) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % kM;
              }
            }
          }
        }
      }
      cout << f[n][0][0] << endl;
    }
  }
  return 0;
}
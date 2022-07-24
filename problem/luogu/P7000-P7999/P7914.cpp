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

const int kN = 502;
const LL kM = 1e9 + 7;

int n, k;
string s;
LL f[kN][kN][6];

bool C(int v, char c) { return s[v] == c || s[v] == '?'; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> s;
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    f[i][i - 1][0] = 1;
  }
  for (int l = 1; l <= n; ++l) {
    for (int i = 1, j = l; j <= n; ++i, ++j) {
      bool _f = l <= k;
      for (int k = i; k <= j; ++k) {
        _f &= C(k, '*');
      }
      f[i][j][0] = _f, f[i][j][1] = (C(i, '(') && C(j, ')')) * (f[i + 1][j - 1][0] + f[i + 1][j - 1][2] + f[i + 1][j - 1][3] + f[i + 1][j - 1][4]) % kM;
      f[i][j][2] = f[i][j][1], f[i][j][5] = f[i][j][0];
      for (int k = i; k < j; ++k) {
        f[i][j][2] = (f[i][j][2] + (f[i][k][2] + f[i][k][4]) * f[k + 1][j][1] % kM) % kM;
        f[i][j][3] = (f[i][j][3] + (f[i][k][3] + f[i][k][5]) * f[k + 1][j][1] % kM) % kM;
        f[i][j][4] = (f[i][j][4] + f[i][k][2] * f[k + 1][j][0] % kM) % kM;
        f[i][j][5] = (f[i][j][5] + f[i][k][3] * f[k + 1][j][0] % kM) % kM;
      }
    }
  }
  cout << f[1][n][2];
  return 0;
}
/*
0: *****************
1: (...)
2: (...)...(...)
3: ***...(...)
4: (...)...***
5: ***...***
*/
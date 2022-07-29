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

const int kN = 51;

LL f[kN][kN][kN * kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  f[0][0][0] = 1;
  for (int i = 1; i <= 50; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= 2500; ++k) {
        f[i][j][k] = f[i - 1][j][k] + (j && k >= i ? f[i - 1][j - 1][k - i] : 0);
        // cout << f[i][j][k] << ' ';
      }
      // cout << '\n';
    }
    // cout << '\n';
  }
  LL s = 0;
  for (int i = 1; i <= 50; ++i) {
    s += f[50][i][36 * i];
    cout << f[50][i][36 * i] << '\n';
  }
  cout << s;
  return 0;
}
/*
1 2 3 ... 50
Sum = 36 * i
*/
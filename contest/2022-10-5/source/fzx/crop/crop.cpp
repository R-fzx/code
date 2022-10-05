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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n;
LL A, B, C, D, M, ans, c[9], x, y;

int main() {
  RF("crop");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> A >> B >> C >> D >> x >> y >> M;
  for (int i = 1; i <= n; ++i) {
    ++c[x % 3 * 3 + y % 3], x = (A * x + B) % M, y = (C * y + D) % M;
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = i; j < 9; ++j) {
      for (int k = j; k < 9; ++k) {
        if ((i / 3 + j / 3 + k / 3) % 3 == 0 && (i % 3 + j % 3 + k % 3) % 3 == 0) {
          if (i == j && j == k) {
            ans += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
          } else {
            ans += c[i] * c[j] * c[k];
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
/*
10
11
12
20
21
22
*/
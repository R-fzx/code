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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	LL s = 0;
	for (int i = 1; i <= 1000000; ++i) {
		int x = i, c = 0;
    for (int j = 2; ++c, j * j <= x; ++j, ++c) {
      if (x % j == 0) {
        for (; ++c, x % j == 0; x /= j, ++c) {
        }
      }
    }
    s += c;
  }
  cout << s;
	return 0;
}
/*
f[i][k][j] 前 i 个小朋友发水果，第 i 个小朋友发水果 j，恰好有 k 个小朋友拿到的水果和其左边相邻小朋友拿到的水果不同
s[i][k] = f[i][k][x];
f[i][k][j] = f[i - 1][k][j] + s[i - 1][k - 1] - f[i - 1][k - 1][j];
gs[k] = g[k][x]
g[k][j] += gs[k - 1] - g[k - 1][j]
0:
g01 g02 g03 g04
g11 g12 g13 g14
g21 g22 g23 g24
g31 g32 g33 g34
g41 g42 g43 g44
1:
g01 g02 g03 g04
g11 g12 g13 g14 +s0
g21 g22 g23 g24 +s1
g31 g32 g33 g34 +s2
g41 g42 g43 g44 +s3
*/
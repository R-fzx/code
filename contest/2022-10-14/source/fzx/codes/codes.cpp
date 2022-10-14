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
#define RF(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int main() {
  RF("codes");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  return 0;
}
/*
f[i][j][k - sz[x]] |= f[i][j][k] && s[i].substr(sz[i] - k, sz[x]) == s[x]
O(n^5)
g[i + sz[k]][y] |= g[i][j] && f[k][x][y] && Has(j + s[k].substr(0, x))
O(n^5*2^n)
*/
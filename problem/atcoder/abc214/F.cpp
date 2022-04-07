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

const int kN = 2e5 + 1;
const LL kM = 1e9 + 7;

int n, l[256];
string s;
LL f[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size(), s = " " + s;
  f[0] = 1, f[1] = 2, l[s[1]] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = (f[i - 1] + f[i - 2] - (l[s[i]] >= 2 ? f[l[s[i]] - 2] : l[s[i]]) + kM) % kM, l[s[i]] = i;
  }
  cout << f[n] - 1;
  return 0;
}
/*
f[i]: 1-i的本质不同子序列个数
i不选：
f[i] = f[i - 1]
i选：
f[i] = f[i - 2]
去重：
f[i] -= f[l[s[i]] - 2]
*/
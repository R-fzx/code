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

const int kN = 401;
const LL kM = 1e9 + 7;

int t, n, m;
string a, b;
LL f[kN][kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; ) {
    cin >> n >> m >> a >> b;
    a = " " + a, b = " " + b;
    
  }
  return 0;
}
/*
f[i][j][k]: 现在在s的第i个字符，r前面还要删j个字符，后面还要删k个字符，求方案数
s[i] == '-'时：
  f[i][j][k]->f[i+1][j-1][k],f[i+1][j][k-1]
s[i] != '-'时：
  f[i][j][k]->f[i+1][j][k+(s[i]!=t[i-j-k])]
*/
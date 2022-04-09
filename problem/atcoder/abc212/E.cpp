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

const int kN = 5001;
const LL kM = 998244353;

int n, m, k;
vector<int> e[kN];
LL f[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    e[x].push_back(y), e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    e[i].push_back(i);
  }
  f[0][1] = 1;
  for (int i = 1; i <= k; ++i) {
    LL s = 0;
    for (int j = 1; j <= n; ++j) {
      s = (s + f[i - 1][j]) % kM;
    }
    for (int j = 1; j <= n; ++j) {
      f[i][j] = s;
      for (int k : e[j]) {
        f[i][j] = (f[i][j] - f[i - 1][k] + kM) % kM;
      }
    }
  }
  cout << f[k][1];
  return 0;
}
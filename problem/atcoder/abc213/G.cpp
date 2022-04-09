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

const int kN = 17;
const LL kM = 998244353;

int n, m;
Pii e[kN * kN];
LL c[1 << kN], f[1 << kN], p[kN * kN] = {1};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    p[i] = p[i - 1] * 2 % kM;
    cin >> e[i].first >> e[i].second;
    --e[i].first, --e[i].second;
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 1; j <= m; ++j) {
      c[i] += (i >> e[j].first) & 1 && (i >> e[j].second) & 1;
    }
  }
  f[1] = 1;
  for (int i = 3; i < 1 << n; i += 2) {
    f[i] = p[c[i]];
    for (int j = i - 1 & i; j; j = j - 1 & i) {
      if (j & 1) {
        debug("  %d %d\n", i, j);
        f[i] = (f[i] - f[j] * p[c[i - j]] % kM + kM) % kM;
      }
    }
    debug("%d %lld\n", i, f[i]);
  }
  for (int i = 1; i < n; ++i) {
    LL ans = 0;
    for (int j = 1; j < 1 << n; j += 2) {
      if (j >> i & 1) {
        ans = (ans + f[j] * p[c[(1 << n) - 1 - j]] % kM) % kM;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
/*
011
001
*/
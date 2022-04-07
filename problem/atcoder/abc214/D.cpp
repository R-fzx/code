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
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e5 + 1;

int n, f[kN];
pair<LL, Pii> e[kN];
LL ans, s[kN];

int F(int x) { return x == f[x] ? x : (f[x] = F(f[x])); }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> e[i].second.first >> e[i].second.second >> e[i].first;
  }
  sort(e + 1, e + n);
  for (int i = 1; i <= n; ++i) {
    f[i] = i, s[i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    int fx = F(e[i].second.first), fy = F(e[i].second.second);
    ans += 1LL * s[fx] * s[fy] * e[i].first;
    s[fx] += s[fy];
    f[fy] = fx;
  }
  cout << ans;
  return 0;
}
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

const int kN = 7e5 + 1;

int n;
LL v, a[kN], s[kN];
Pll ans = {1e18, 1e9};
vector<Pii> e[kN];

void D(int x, int f) {
  s[x] = 1;
  for (Pii i : e[x]) {
    if (i.first != f) {
      D(i.first, x), s[x] += s[i.first], v += (i.second - a[x]) * s[i.first];
    }
  }
}
void S(int x, int f) {
  ans = min(ans, {v, x});
  for (Pii i : e[x]) {
    if (i.first != f) {
      v += (i.second - a[i.first]) * (n - s[i.first]) - (i.second - a[x]) * s[i.first];
      S(i.first, x);
      v -= (i.second - a[i.first]) * (n - s[i.first]) - (i.second - a[x]) * s[i.first];
    }
  }
}

int main() {
  RF("yggdrasil");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, x, y, w; i < n; ++i) {
    cin >> x >> y >> w;
    e[x].emplace_back(y, w), e[y].emplace_back(x, w);
  }
  D(1, 0), S(1, 0);
  cout << ans.second << '\n' << ans.first;
  return 0;
}
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

const int kN = 1e5 + 1, kL = 17;

int n, m, t[kN][kL][2], na[kN], nb[kN];
LL a[kN], x, al[kN][kL][2], bl[kN][kL][2];
multiset<Pii> s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  s.insert({-1e9, 0}), s.insert({-1e9, 0}), s.insert({1e9, 0}), s.insert({1e9, 0});
  for (int i = n; i >= 1; --i) {
    auto p = --s.lower_bound({a[i], 0});
    Pii l[4];
    for (int j = 0; j < 4; ++p, ++j) {
      l[j] = {abs(p->first - a[i]), p->second};
    }
  }
  return 0;
}
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

const int kV = 1001;

Pii a[7];
bitset<kV> b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  a[1].first = 1, a[2].first = 2, a[3].first = 3, a[4].first = 5, a[5].first = 10, a[6].first = 20;
  cin >> a[1].second >> a[2].second >> a[3].second >> a[4].second >> a[5].second >> a[6].second;
  b[0] = 1;
  for (int i = 1; i <= 6; ++i) {
    for (int j = 1; j <= a[i].second; ++j) {
      b |= b << a[i].first;
    }
  }
  cout << "Total=" << b.count() - 1;
  return 0;
}
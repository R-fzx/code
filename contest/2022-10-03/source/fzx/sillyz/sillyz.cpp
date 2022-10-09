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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kV = 1e7 + 1;

LL a, b, c[kV];

int main() {
  RF("sillyz");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  for (LL i = 1; i <= b; ++i) {
    LL s = i;
    for (LL j = i; j; s *= j % 10, j /= 10) {
    }
    if (s < kV) {
      ++c[s];
    }
  }
  for (LL i = 1; i <= b; ++i) {
    c[i] += c[i - 1];
  }
  cout << c[b] - c[a - 1];
  return 0;
}
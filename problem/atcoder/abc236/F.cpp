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

const int kN = 16;

int n, l, d[1 << kN];
LL s, a[1 << kN];
bool v[1 << kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  l = 1 << n;
  for (int i = 1; i < l; ++i) {
    cin >> a[i];
    d[i] = i;
  }
  sort(d + 1, d + l, [](int i, int j) { return a[i] < a[j]; });
  v[0] = 1;
  for (int i = 1; i < l; ++i) {
    if (!v[d[i]]) {
      s += a[d[i]];
      for (int j = 1; j < l; ++j) {
        v[j] |= v[j ^ d[i]];
      }
    }
  }
  cout << s;
  return 0;
}
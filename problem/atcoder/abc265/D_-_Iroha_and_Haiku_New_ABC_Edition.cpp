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

const int kN = 2e5 + 1;

int n;
LL p, q, r, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> p >> q >> r;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int x = 1, y = 1, z = 1, w = 1; x <= n; ++x) {
    for (; y <= n && a[y - 1] - a[x - 1] < p; ++y) {
    }
    for (; z <= n && a[z - 1] - a[y - 1] < q; ++z) {
    }
    for (; w <= n && a[w - 1] - a[z - 1] < r; ++w) {
    }
    if (a[y - 1] - a[x - 1] == p && a[z - 1] - a[y - 1] == q && a[w - 1] - a[z - 1] == r) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
/*
(x,y,z,w)
s[y-1]-s[x-1]=P
s[z-1]-s[y-1]=Q
s[w-1]-s[z-1]=R
*/
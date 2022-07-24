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
using uLL = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e6 + 1, kK = 64;

int n, m, c, k, s;
uLL a[kN], v, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // freopen("P7076_13.in", "r", stdin);
  // freopen("P7076.out", "w", stdout);
  cin >> n >> m >> c >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    v |= a[i];
  }
  for (int x, y; m--; ) {
    cin >> x >> y;
    b |= 1uLL << x;
  }
  c = 0;
  for (int i = 0; i < k; ++i) {
    c += !(b >> i & 1) || (v >> i & 1);
  }
  if (c == 64 && !n) {
    cout << "18446744073709551616";
  } else {
    cout << (1uLL << c) - n;
  }
  return 0;
}
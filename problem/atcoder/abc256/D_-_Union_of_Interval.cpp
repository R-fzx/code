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

const int kN = 4e5 + 1;

int n, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, l, r; i <= n; ++i) {
    cin >> l >> r;
    ++a[l * 2], --a[r * 2];
  }
  for (int i = 1; i < kN; ++i) {
    a[i] += a[i - 1];
  }
  for (int i = 1, p = 1; i < kN;) {
    for (; i < kN && !a[i]; ++i) {
    }
    p = i;
    for (; i < kN && a[i]; ++i) {
    }
    if (i < kN) {
      cout << p / 2 << ' ' << i / 2 << '\n';
    }
  }
  return 0;
}
/*
0 0 0 0
0 1 1 0
0 1 0 -1
*/
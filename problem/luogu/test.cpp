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

const int kN = 1e5 + 1;

int n, a[kN], b[kN];

void P() {
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
bool C() {
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i) {
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  iota(a + 1, a + n + 1, 1);
  do {
    P();
    for (int i = 1; i <= n; i += 2) {
      b[i] = a[i / 2 + 1 + n / 2];
    }
    for (int i = 2; i <= n; i += 2) {
      b[i] = a[i / 2];
    }
    copy_n(b + 1, n, a + 1);
  } while (C());
  return 0;
}
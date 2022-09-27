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

int n;

void P(int x) {
  if (!x || x == 2) {
    cout << x;
    return;
  }
  bool f = 0;
  for (int i = 14; i >= 0; --i) {
    if (x >> i & 1) {
      cout << (f ? "+" : "") << '2';
      if (i != 1) {
        cout << '(', P(i), cout << ')';
      }
      f = 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  P(n);
  return 0;
}
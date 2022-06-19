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

const int kN = 4;

int n, s;
bool v[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    v[0] = 1;
    for (int j = 0; j < 4; ++j) {
      debug("%d ", v[j]);
    }
    debug("\n");
    for (int j = 3; j >= 0; --j) {
      if (v[j]) {
        if (j + x < 4) {
          v[j + x] = 1;
        } else {
          ++s;
        }
        v[j] = 0;
      }
    }
    for (int j = 0; j < 4; ++j) {
      debug("%d ", v[j]);
    }
    debug("\n");
  }
  cout << s;
  return 0;
}
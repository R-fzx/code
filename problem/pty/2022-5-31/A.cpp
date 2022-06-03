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

const int kN = 2e5 + 2;

int n, c[kN], _c[kN];

int Ss() {
  int s = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    for (; i <= n && !c[i]; ++i) {
    }
    if (i > n) {
      break;
    }
    for (j = i; j <= n && c[j]; ++j) {
    }
    --j;
    s += (j - i + 3) / 3;
  }
  return s;
}
int Sm() {
  if (n == 1) {
    return 1;
  }
  copy_n(c + 1, n, _c + 1);
  for (int i = 1; i <= n; ++i) {
    if (c[i] >= 3) {
      _c[i] -= 2, ++_c[i - 1], ++_c[i + 1];
    } else if (c[i] == 2) {
      --_c[i];
      if (_c[i - 1]) {
        ++_c[i + 1];
      } else {
        ++_c[i - 1];
      }
    } else if (c[i] == 1 && !_c[i - 1]) {
      --_c[i], ++_c[i - 1];
    }
  }
  for_each(_c, _c + n + 2, [](int x) { debug("%d ", x); });
  debug("\n");
  return n + 2 - count(_c, _c + n + 2, 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each(c + 1, c + n + 1, [](int x) { cin >> x, ++c[x]; });
  for_each(c, c + n + 2, [](int x) { debug("%d ", x); });
  debug("\n");
  cout << Ss() << " " << Sm();
  return 0;
}
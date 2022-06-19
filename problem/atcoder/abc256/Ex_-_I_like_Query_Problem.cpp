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

const int kN = 5e5 + 1;

int n, q, a[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int o, l, r, x; q--; ) {
    cin >> o >> l >> r;
    if (o == 1) {
      cin >> x;
      for (int i = l; i <= r; ++i) {
        a[i] /= x;
      }
    } else if (o == 2) {
      cin >> x;
      for (int i = l; i <= r; ++i) {
        a[i] = x;
      }
    } else {
      LL s = 0;
      for (int i = l; i <= r; ++i) {
        s += a[i];
      }
      cout << s << '\n';
    }
  }
  return 0;
}
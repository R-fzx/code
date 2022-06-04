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

const int kN = 2e5 + 1;

int n, a[kN], c;
bitset<kN> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for_each(a + 1, a + n + 1, [](int &x) { cin >> x; }), sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (v[a[i]] || v[a[i] - 1] || v[a[i] + 1]) {
      continue;
    }
    ++c, v[a[i] + 1] = 1;
  }
  cout << c << " ";
  c = 0, v = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (!v[a[i] + j]) {
        ++c, v[a[i] + j] = 1;
        break;
      }
    }
  }
  cout << c;
  return 0;
}
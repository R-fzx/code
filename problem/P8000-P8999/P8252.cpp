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
#include <set>
#include <string>
#include <vector>
#define _DEBUG
#ifdef _DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1e6 + 1;

int t, n, k[kN], l[kN], c[kN], d[kN];
vector<int> a[kN];

Pii S() {
  sort(d + 1, d + n + 1, [](int x, int y) { return k[x] < k[y]; });
  for (int _ = 1, i; _ <= n; ++_) {
    i = d[_];
    for (int j : a[i]) {
      ++c[l[j]];
    }
    for (int j : a[i]) {
      int x = l[j];
      if (x && c[x] < k[x] && c[x] < k[i]) {
        return {x, i};
      }
    }
    for (int j : a[i]) {
      --c[l[j]], l[j] = i;
    }
  }
  return {0, 0};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> k[i];
      a[i].resize(k[i]), d[i] = i, l[i] = c[i] = 0;
      for (int &j : a[i]) {
        cin >> j;
      }
    }
    Pii x = S();
    if (x.first) { 
      cout << "YES\n" << x.first << ' ' << x.second << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
/*
2
5
1 2 3 5
1 2 3
1 2
1
4

4
1 2 3
2 3 4

1 2 3 4

3
1
2
4

lst: 1 1 1 0
*/
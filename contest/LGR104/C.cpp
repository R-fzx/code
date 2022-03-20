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
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 101;

int n, m, a[kN][kN];
vector<Pii> p;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // cout << "NO";
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] != j) {
        p.emplace_back(i, j);
      }
    }
  }
  if (p.empty()) {
    cout << "YES\n0";
  } else if (p.size() == 2) {
    if (p[0].first == p[1].first) {
      if (p[0].second + p[1].second == m + 1 && a[p[0].first][p[0].second] == p[1].second && a[p[1].first][p[1].second] == p[0].second) {
        cout << "YES\n1\n0 " << p[0].first;
      } else {
        cout << "NO";
      }
    } else {
      if (n + 1 - p[0].first == p[1].first) {
        if (abs(p[0].second - p[1].second) == 1) {
          
        }
      } else {
        cout << "NO";
      }
    }
  } else {
    cout << "NO";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
/*
1 2 3 4 ... n
1 2 3 4 ... n

1 2 3 4 ... n
n ... 4 3 2 1

1 ...                           m
1 ...                           m
1 ...                           m
...
1 ... j       ... i   x i+2 ... m
1 ... j       ... i i+1 i+2 ... m
1 ... j       ... i i+1 i+2 ... m
...
1 ... j y j+2 ... i         ... m
...
1 ...                           m
1 ...                           m
1 ...                           m
*/
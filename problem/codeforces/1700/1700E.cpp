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

const int kN = 4e5 + 1, kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
Pii p[kN];
vector<vector<int>> a;

bool C0() {
  for (int i = 1; i <= n * m; ++i) {
    if (p[i].first) {
      for (int j = 0; j < 4; ++j) {
        int x = p[i].first + kD[j][0], y = p[i].second + kD[j][1];
        if (x >= 1 && x <= n && y >= 1 && y <= m) {
          p[a[x][y]] = {x, y};
        }
      }
    } else {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  a = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        p[1] = {i, j};
      }
    }
  }
  if (C0()) {
    cout << 0;
  } else {
    
  }
  return 0;
}
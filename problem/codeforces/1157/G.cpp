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
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 201;

int n, m, a[kN][kN], b[kN][kN], r[kN], c[kN];

void IR(int x) {
  r[x] ^= 1;
  for (int i = 1; i <= m; ++i) {
    b[x][i] ^= 1;
  }
}
void IC(int x) {
  c[x] ^= 1;
  for (int i = 1; i <= n; ++i) {
    b[i][x] ^= 1;
  }
}
bool C(int x) {
  for (int i = 1; i <= n; ++i) {
    if (i != x) {
      int _c[2] = {0, 0};
      for (int j = 1; j <= m; ++j) {
        ++_c[b[i][j]];
      }
      if (!_c[0]) {
        IR(i);
      } else if (_c[1]) {
        return 0;
      }
      if (i > x) {
        IR(i);
      }
    } else {
      bool f = 1, _f = 1;
      for (int j = 1; j < m; ++j) {
        f &= b[i][j] <= b[i][j + 1];
      }
      for (int j = 1; j < m; ++j) {
        _f &= b[i][j] >= b[i][j + 1];
      }
      if (_f) {
        IR(i);
      } else if (!f) {
        return 0;
      }
    }
  }
  return 1;
}
bool S() {
  if (n == 1) {
    for (int i = 1; i <= m; ++i) {
      c[i] = a[1][i];
    }
    return 1;
  }
  for (int i = 1; i <= n; ++i) {
    fill(r + 1, r + n + 1, 0), fill(c + 1, c + m + 1, 0);
    copy(&a[1][1], &a[n][m] + 1, &b[1][1]);
    for (int j = 1; j <= m; ++j) {
      if (b[(i == 1) + 1][j]) {
        IC(j);
      }
    }
    if (C(i)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  if (S()) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      cout << r[i];
    }
    cout << endl;
    for (int i = 1; i <= m; ++i) {
      cout << c[i];
    }
  } else {
    cout << "NO";
  }
  return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
// #define TIME

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1001;

int n, a[kN][kN];

bool C() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j + 5 <= n; ++j) {
      int c = 0;
      for (int k = j; k < j + 6; ++k) {
        c += a[i][k];
      }
      if (c > 3) {
        return 1;
      }
    }
  }
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i + 5 <= n; ++i) {
      int c = 0;
      for (int k = i; k < i + 6; ++k) {
        c += a[k][j];
      }
      if (c > 3) {
        return 1;
      }
    }
  }
  for (int i = 1; i + 5 <= n; ++i) {
    for (int j = 1; j + 5 <= n; ++j) {
      int c = 0;
      for (int k = 0; k < 6; ++k) {
        c += a[i + k][j + k];
      }
      if (c > 3) {
        return 1;
      }
    }
  }
  for (int i = 6; i <= n; ++i) {
    for (int j = 1; j + 5 <= n; ++j) {
      int c = 0;
      for (int k = 0; k < 6; ++k) {
        c += a[i - k][j + k];
      }
      // cout << i << " " << j << " " << c << endl;
      if (c > 3) {
        return 1;
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << a[i][j];
  //   }
  //   cout << endl;
  // }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = ch == '#';
    }
  }
  cout << (C() ? "Yes" : "No");
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
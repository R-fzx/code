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

const int kN = 1501;

int n, m, a[kN][kN], c[kN * kN], _c, ans[2];
char ch;
bool v[kN][kN];

void D(int x, int y) {
  // cerr << x << " " << y << endl;
  if (x < 1 || x > n || y < 1 || y > m || v[x][y] || !a[x][y]) {
    return;
  }
  v[x][y] = 1, ++_c;
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (i || j) {
        D(x + i, y + j);
      }
    }
  }
}

int main() {
  freopen("star.in", "r", stdin);
  freopen("star.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> ch;
      a[i][j] = ch == '*';
      // cerr << a[i][j];
    }
    // cerr << endl;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      _c = 0, D(i, j), ++c[_c];
      // cerr << _c << " ";
    }
    // cerr << endl;
  }
  for (int i = 1; i <= n * m; ++i) {
    ans[0] += !!c[i], ans[1] = max(ans[1], c[i] * i);
  }
  cout << ans[0] << " " << ans[1];
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
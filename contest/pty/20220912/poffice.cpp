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
#include <random>
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
using i128 = __int128_t;

const int kN = 101;

int t, n, m, k, v[kN], b, s[kN];
vector<int> p[2];
bool e[kN][kN], _v[2][kN];
i128 c[kN][kN], f[2][kN][kN];

void W(i128 x) {
  if (x) {
    W(x / 10), putchar(x % 10 + '0');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  c[0][0] = 1;
  for (int i = 1; i < kN; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  for (cin >> t; t--;) {
    cin >> n >> m >> k, b = 0;
    p[0].assign(1, 0), p[1].assign(1, 0);
    for (int i = 1; i <= n; ++i) {
      v[i] = s[i] = 0, fill_n(e[i] + 1, n, 0), e[i][i] = 1;
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     debug("%d ", e[i][j]);
    //   }
    //   debug("\n");
    // }
    // debug("------------------------------\n");
    for (int i = 1, x, y; i <= m; ++i) {
      cin >> x >> y;
      e[x][y] = 1;
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     debug("%d ", e[i][j]);
    //   }
    //   debug("\n");
    // }
    // debug("------------------------------\n");
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          e[i][j] |= e[i][k] & e[k][j];
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     debug("%d ", e[i][j]);
    //   }
    //   debug("\n");
    // }
    // debug("------------------------------\n");
    for (int i = 1; i <= n; ++i) {
      if (!v[i]) {
        v[i] = ++b;
        for (int j = 1; j <= n; ++j) {
          if (e[i][j] && e[j][i]) {
            ++s[v[j] = b];
          }
        }
      }
      for (int j = 1; j <= n; ++j) {
        if (e[i][j] && e[j][i]) {
          e[i][j] = e[j][i] = 0;
        }
      }
    }
    // for (int i = 1; i <= n; ++i) {
    //   debug("%d ", v[i]);
    // }
    // debug("\n");
    // for (int i = 1; i <= b; ++i) {
    //   debug("%d ", s[i]);
    // }
    // debug("\n");
    if (b == 1) {
      W(c[n][k]), puts("");
      continue;
    }
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= n; ++j) {
    //     debug("%d ", e[i][j]);
    //   }
    //   debug("\n");
    // }
    // debug("------------------------------\n");
    fill(_v[0] + 1, _v[1] + b + 1, 1);
    for (int i = 1; i <= n; ++i) {
      bool f = 0;
      for (int j = 1; j <= n; ++j) {
        f |= e[i][j];
      }
      _v[1][v[i]] &= !f;
      f = 0;
      for (int j = 1; j <= n; ++j) {
        f |= e[j][i];
      }
      _v[0][v[i]] &= !f;
    }
    for (int j = 1; j <= b; ++j) {
      if (_v[0][j]) {
        p[0].push_back(j);
      } else if (_v[1][j]) {
        p[1].push_back(j);
      }
    }
    int _s = 0;
    for (int i = 1; i <= b; ++i) {
      if (!_v[0][i] && !_v[1][i]) {
        _s += s[i];
      }
    }
    for (int u = 0; u < 2; ++u) {
      for (int i = 0; i < p[u].size(); ++i) {
        for (int j = 1; j <= k; ++j) {
          f[u][i][j] = 0;
        }
      }
    }
    for (int u = 0; u < 2; ++u) {
      f[u][0][0] = 1;
      for (int i = 1; i < p[u].size(); ++i) {
        for (int j = 1; j <= k; ++j) {
          for (int x = 1; x <= j; ++x) {
            f[u][i][j] += f[u][i - 1][j - x] * c[s[p[u][i]]][x];
          }
        }
      }
    }
    i128 ans = 0;
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; i + j < k; ++j) {
        ans += f[0][p[0].size() - 1][i] * c[_s][j] * f[1][p[1].size() - 1][k - i - j];
      }
    }
    if (ans) {
      W(ans), puts("");
    } else {
      puts("0");
    }
  }
  return 0;
}
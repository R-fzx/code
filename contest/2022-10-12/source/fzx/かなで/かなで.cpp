#pragma GCC optimize(3)
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
#include <unordered_set>
#include <vector>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 7, kM = 9, kK = 11, kL = 2500;
using A = array<bitset<kK>, kK>;

int n, m, k, t, s;
bool a[kN][kM];
A v, _v, __v;
set<A> l;

bool operator<(const A &x, const A &y) {
  for (int i = 1; i <= k; ++i) {
    if (x[i].to_ullong() != y[i].to_ullong()) {
      return x[i].to_ullong() < y[i].to_ullong();
    }
  }
  return 0;
}

bool C() {
  /*
  11 12 13 14 15
  21 22 23 24 25
  31 32 33 34 35
  41 42 43 44 45
  51 52 53 54 55

  51 41 31 21 11
  52 42 32 22 12
  53 43 33 23 13
  54 44 34 24 14
  55 45 35 25 15
  */
  _v = v;
  for (int __ = 0; __ < 2; ++__) {
    for (int _ = 0; _ < 4; ++_) {
      if (l.find(_v) != l.end()) {
        return 1;
      }
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
          __v[k - j + 1][i] = _v[i][j];
        }
      }
      int l = k, u = k;
      for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
          if (__v[i][j]) {
            l = min(l, j);
            break;
          }
        }
      }
      for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= k; ++i) {
          if (__v[i][j]) {
            u = min(u, i);
            break;
          }
        }
      }
      _v.fill(0);
      for (int i = u; i <= k; ++i) {
        for (int j = l; j <= k; ++j) {
          _v[i - u + 1][j - l + 1] = __v[i][j];
        }
      }
    }
    int r = 1;
    for (int i = 1; i <= k; ++i) {
      for (int j = k; j >= 1; --j) {
        if (_v[i][j]) {
          r = max(j, r);
          break;
        }
      }
    }
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= r; ++j) {
        __v[i][j] = _v[i][r - j + 1];
      }
    }
    for (int i = 1; i <= k; ++i) {
      for (int j = 1; j <= r; ++j) {
        _v[i][j] = __v[i][j];
      }
    }
  }
  return 0;
}
void D(int x, int y, int c) {
  if (c == k + 1) {
    // for (int i = 1; i < kK; ++i) {
    //   for (int j = 1; j < kK; ++j) {
    //     cout << a[i][j];
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
    if (!C()) {
      l.insert(v);
    }
    return;
  }
  if (y == x + 1) {
    D(x + 1, 1, c);
    return;
  }
  if (x == k + 1) {
    return;
  }
  int i = x + 1 - y, j = y;
  if (v[i - 1][j] || v[i][j - 1]) {
    v[i][j] = 1, D(x, y + 1, c + 1);
  }
  v[i][j] = 0, D(x, y + 1, c);
}

int main() {
  RF("¤«¤Ê¤Ç");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  // cout << t << endl;
  v[1][1] = 1, D(2, 1, 2);
  // cout << t << endl;
  // for (int i = 1; i <= t; ++i) {
  //   for (int j = 1; j <= k; ++j) {
  //     for (int u = 1; u <= k; ++u) {
  //       cout << l[i][j][u];
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
  // cout << "=================\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (auto _v : l) {
    bool f = 0;
    for (int __ = 0; !f && __ < 2; ++__) {
      for (int _ = 0; !f && _ < 4; ++_) {
        bool _f = 0;
        // for (int x = 1; !_f && x <= k; ++x) {
        //   for (int y = 1; !_f && y <= k; ++y) {
            // cout << _v[x][y];
            // for (int u = 1; _f && u <= n; ++u) {
            //   for (int v = 1; _f && v <= m; ++v) {
            //     if (_v[x][y] && (u + x - 1 > n || v + y - 1 > m || !a[u + x - 1][v + y - 1])) {
            //       _f = 0;
            //     }
            //   }
            // }
          // }
          // cout << '\n';
        // }
        // cout << '\n';
        for (int u = 1; !_f && u <= n; ++u) {
          for (int v = 1; !_f && v <= m; ++v) {
            bool __f = 1;
            for (int x = 1; __f && x <= k; ++x) {
              for (int y = 1; __f && y <= k; ++y) {
                // cout << _v[x][y];
                if (_v[x][y] && (u + x - 1 > n || v + y - 1 > m || !a[u + x - 1][v + y - 1])) {
                  __f = 0;
                }
              }
            }
            if (__f) {
              _f = 1;
              break;
            }
          }
          // cout << '\n';
        }
        // cout << '\n';
        if (_f) {
          f = 1;
          break;
        }
        for (int _i = 1; _i <= k; ++_i) {
          for (int _j = 1; _j <= k; ++_j) {
            __v[k - _j + 1][_i] = _v[_i][_j];
          }
        }
        int l = k, u = k;
        for (int _i = 1; _i <= k; ++_i) {
          for (int _j = 1; _j <= k; ++_j) {
            if (__v[_i][_j]) {
              l = min(l, _j);
              break;
            }
          }
        }
        for (int _j = 1; _j <= k; ++_j) {
          for (int _i = 1; _i <= k; ++_i) {
            if (__v[_i][_j]) {
              u = min(u, _i);
              break;
            }
          }
        }
        for (int _i = 1; _i <= k; ++_i) {
          for (int _j = 1; _j <= k; ++_j) {
            _v[_i][_j] = 0;
          }
        }
        for (int _i = u; _i <= k; ++_i) {
          for (int _j = l; _j <= k; ++_j) {
            _v[_i - u + 1][_j - l + 1] = __v[_i][_j];
          }
        }
      }
      int r = 1;
      for (int _i = 1; _i <= k; ++_i) {
        for (int _j = k; _j >= 1; --_j) {
          if (_v[_i][_j]) {
            r = max(_j, r);
            break;
          }
        }
      }
      for (int _i = 1; _i <= k; ++_i) {
        for (int _j = 1; _j <= r; ++_j) {
          __v[_i][_j] = _v[_i][r - _j + 1];
        }
      }
      for (int _i = 1; _i <= k; ++_i) {
        for (int _j = 1; _j <= r; ++_j) {
          _v[_i][_j] = __v[_i][_j];
        }
      }
    }
    if (f) {
      ++s;
    }
    // cout << "==================\n";
  }
  cout << s;
  // cout << '\n' << clock();
  return 0;
}
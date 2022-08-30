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

const int kN = 52;

int n, m, k, q, ans;
Pii a[kN][kN];
void clear(int x, int y);
const int kD[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const function<void(int, int, int)> special[7] = {
    [](int x, int y, int c) {},
    [](int x, int y, int c) {
      for (int i = 1; i <= m; ++i) {
        clear(x, i);
      }
    },
    [](int x, int y, int c) {
      for (int i = 1; i <= n; ++i) {
        clear(i, y);
      }
    },
    [](int x, int y, int c) {
      for (int i = 1; i <= m; ++i) {
        clear(x, i);
      }
      for (int i = 1; i <= n; ++i) {
        clear(i, y);
      }
    },
    [](int x, int y, int c) {
      for (int i = max(1, x - 1); i <= min(n, x + 1); ++i) {
        for (int j = max(1, y - 1); j <= min(m, y + 1); ++j) {
          clear(i, j);
        }
      }
    },
    [](int x, int y, int c) {
      for (int i = max(1, x - 2); i <= min(n, x + 2); ++i) {
        for (int j = max(1, y - 2); j <= min(m, y + 2); ++j) {
          clear(i, j);
        }
      }
    },
    [](int x, int y, int c) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (a[i][j].first == c) {
            clear(i, j);
          }
        }
      }
    }};
int sc;
void clear(int x, int y) {
  int t = a[x][y].second, c = a[x][y].first;
  sc += c, a[x][y] = {0, 0}, special[t](x, y, c);
}
void fall() {
  for (int j = 1; j <= m; ++j) {
    int p = n;
    for (int i = n; i >= 1; --i) {
      if (a[i][j].first) {
        a[p--][j] = a[i][j];
      }
    }
    for (int i = 1; i <= p; ++i) {
      a[i][j] = {0, 0};
    }
  }
}
bool check(int x, int y) {
  if (a[x][y].first) {
    for (int i = 0; i < 2; ++i) {
      int c = -1;
      for (int _x = x, _y = y; a[_x][_y].first == a[x][y].first; _x += i, _y += !i, ++c) {
      }
      for (int _x = x, _y = y; a[_x][_y].first == a[x][y].first; _x -= i, _y -= !i, ++c) {
      }
      if (c >= 3) {
        return 1;
      }
    }
  }
  return 0;
}
int vis[kN][kN], t;
vector<Pii> pos;
int find(int x, int y, int c) {
  if (a[x][y].first != c || vis[x][y] == t) {
    return 0;
  }
  vis[x][y] = t, pos.emplace_back(x, y);
  int s = 1;
  for (int i = 0; i < 4; ++i) {
    s += find(x + kD[i][0], y + kD[i][1], c);
  }
  return s;
}
bool remove() {
  bool f = 0;
  pos.clear(), ++t;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (vis[i][j] != t && check(i, j)) {
        int x = find(i, j, a[i][j].first);
        ans += 50 * (x - 3) * (x - 3), f = 1;
      }
    }
  }
  for (Pii &i : pos) {
    clear(i.first, i.second);
  }
  return f;
}
const int kK = 101;
int cntc[kK], mainc[5][2];
vector<int> lc[6];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j].first;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j].second;
    }
  }
  int f = 1000;
  for (int x1, y1, x2, y2, i = 0; q--;) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) + abs(y1 - y2) == 1 && a[x1][y1].first && a[x2][y2].first) {
      swap(a[x1][y1], a[x2][y2]);
      if (check(x1, y1) || check(x2, y2)) {
        mainc[i][0] = check(x1, y1) ? a[x1][y1].first : a[x2][y2].first;
        mainc[i][1] = check(x2, y2) ? a[x2][y2].first : a[x1][y1].first;
        int c = 0;
        for (; sc = 0, remove(); fall()) {
          ans += ++c * sc;
        }
        ans += 80 * (c - 1) * (c - 1);
        if (++i == 5) {
          i = 0;
          int _m = 0;
          for (int j = 0; j < 32; ++j) {
            fill(cntc + 1, cntc + k + 1, 0);
            for (int k = 0; k <= 5; ++k) {
              lc[k].clear();
            }
            for (int k = 0; k < 5; ++k) {
              ++cntc[mainc[k][j >> k & 1]];
            }
            for (int x = 1; x <= k; ++x) {
              lc[cntc[x]].push_back(x);
            }
            if (lc[1].size() == 5) {
              _m = max(_m, 50 + *max_element(lc[1].begin(), lc[1].end()));
            } else if (lc[1].size() == 3 && lc[2].size() == 1) {
              _m = max(_m, 100 + lc[2][0] * 2);
            } else if (lc[1].size() == 1 && lc[2].size() == 2) {
              _m = max(_m, 200 + lc[2][0] + lc[2][1] + max(lc[2][0], lc[2][1]));
            } else if (lc[1].size() == 2 && lc[3].size() == 1) {
              _m = max(_m, 300 + lc[3][0] * 3);
            } else if (lc[2].size() == 1 && lc[3].size() == 1) {
              _m = max(_m, 500 + lc[3][0] * 3 + lc[2][0]);
            } else if (lc[1].size() == 1 && lc[4].size() == 1) {
              _m = max(_m, 750 + lc[4][0] * 5);
            } else if (lc[5].size() == 1) {
              _m = max(_m, 1000 + lc[5][0] * 10);
            }
          }
          ans += _m;
        }
      } else {
        f = 0;
        swap(a[x1][y1], a[x2][y2]);
      }
    } else {
      f = 0;
    }
    debug("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        debug("%d ", a[i][j].first);
      }
      debug("\n");
    }
    debug("----------------\n");
  }
  ans += f, f = 10000;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j].first) {
        f = 0;
        break;
      }
    }
    if (!f) {
      break;
    }
  }
  cout << ans + f;
  return 0;
}
/*
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 4
0 0 0 0 0 0 0 4
0 4 4 0 0 2 4 2
0 2 4 0 5 2 4 5
0 4 2 5 2 1 1 2

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 6 0 0 3 1
0 0 0 0 3 0 0 0
0 0 0 0 0 0 1 4

b[1]=a[1]
b[i]=a[i]^a[i-1]
a 0 1 1 0 0 1 1
b 0 1 0 1 0 1 0

a 0 1 0 1 1 1 1
b 0 1 1 1 0 0 0
*/
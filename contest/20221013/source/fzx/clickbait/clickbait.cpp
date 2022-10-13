#include <algorithm>
#include <bitset>
#include <cctype>
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
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 1002, kT = 1e5 + 1;

struct E {
  int x, y, n, m, p;
  vector<Pii> e;
} p[kT];
int n, m, c, d[kT], t, b[kN][kN];
char a[kN][kN];

Pii F(int x, int y, int px, int py) {
  int c = a[px][py], nc = a[x][y];
  if (nc == '-') {
    return F(x, y + (py + 1 == y ? 1 : -1), x, y);
  } else if (nc == '+') {
    if (c == '-') {
      return F(x - 1, y, x, y);
    } else {
      return F(x, y + (a[x][y + 1] == '-' ? 1 : -1), x, y);
    }
  } else {
    if (c == '-') {
      return {b[x][y], x - p[b[x][y]].x};
    } else {
      return F(x - 1, y, x, y);
    }
  }
}
void B(int x, int y, int d) {
  c = max(c, d);
  for (; x <= n && a[x][y] == '.'; ++x) {
  }
  for (--x; x && a[x][y] == '.'; --x, ++p[d].n) {
  }
  for (++x; y <= m && a[x][y] == '.'; ++y) {
  }
  for (--y; y && a[x][y] == '.'; --y, ++p[d].m) {
  }
  p[d].x = x, p[d].y = ++y;
  for (int i = 0; i < p[d].n; ++i) {
    b[x + i][y - 1] = b[x + i][y + p[d].m] = d;
  }
}
void D(int x) {
  for (Pii i : p[x].e) {
    D(i.second);
  }
  d[++t] = x;
}

int main() {
  RF("clickbait");
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] + 1;
  }
  // cerr << "114514" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (isdigit(a[i][j])) {
        int x = a[i][j] - '0';
        a[i][j] = '.';
        for (++j; j <= m && isdigit(a[i][j]); x = x * 10 + a[i][j] - '0', a[i][j] = '.', ++j) {
        }
        // cerr << x << ' ';
        B(i, --j, x);
      }
    }
    // cerr << '\n';
  }
  // cerr << "114514" << endl;
  for (int d = 2; d <= c; ++d) {
    for (int i = 0; i < p[d].m; ++i) {
      if (a[p[d].x - 2][p[d].y + i] != '.') {
        Pii r = F(p[d].x - 3, p[d].y + i, p[d].x - 2, p[d].y + i);
        p[d].p = r.first, p[r.first].e.emplace_back(r.second, d);
      }
    }
  }
  for (int i = 1; i <= c; ++i) {
    sort(p[i].e.begin(), p[i].e.end(), greater<Pii>());
    // cout << p[i].x << ' ' << p[i].y << ' ' << p[i].n << ' ' << p[i].m << ' ' << p[i].p << "\ne:";
    // for (Pii j : p[i].e) {
    //   cout << j.first << ',' << j.second << ' ';
    // }
    // cout << '\n';
  }
  D(1);
  for (int i = 1; i <= t; ++i) {
    cout << d[i] << '\n';
  }
  return 0;
}
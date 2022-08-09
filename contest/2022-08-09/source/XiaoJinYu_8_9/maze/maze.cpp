#include <bits/stdc++.h>

const int MAXN = 25;

inline void r(int &s) {
  s = 0;
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 3) + (s << 1) + c - 48, c = getchar();
}

void w(long long x) {
  if (x > 9) w(x / 10);
  putchar(x % 10 + 48);
}

std::map<int, long long> f[MAXN][MAXN];

int a[MAXN][MAXN];

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  int n, m, x;
  r(n), r(m), r(x);
  ++n, ++m;
  for (int i(1); i < n; ++i) {
    for (int j(1); j < m; ++j) {
      r(a[i][j]);
    }
  }
  f[1][1].insert({a[1][1], 1});
  for (int i(1); i < n; ++i) {
    for (int j(1); j < m; ++j) {
      if (j + 1 < m && a[i][j + 1]) {
        for (auto k : f[i][j]) {
          f[i][j + 1][k.first ^ a[i][j + 1]] += k.second;
        }
      }
      if (i + 1 < n && a[i + 1][j]) {
        for (auto k : f[i][j]) {
          f[i + 1][j][k.first ^ a[i + 1][j]] += k.second;
        }
      }
    }
  }
  --n, --m;
  w(f[n][m][x]);
  return 0;
}
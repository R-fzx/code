#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;

inline void r(int &s) {
  s = 0;
  int c(getchar());
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

int a[3][3];
int k, n, m, xx, yy;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

bool check1() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if ((i != xx || j != yy) && a[i][j] == 1) {
        return 0;
      }
    }
  }
  return a[xx][yy] == 1;
}

set<int> vis;

bool check() {
  if (check1()) {
    return 1;
  }
  int x = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      x = x * 10 + a[i][j];
    }
  }
  if (vis.find(x) != vis.end()) {
    return 0;
  }
  vis.insert(x);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i][j]) {
        for (int k = 0; k < 8; ++k) {
          int nx1 = (i + dx[k] + 3) % 3, ny1 = (j + dy[k] + 3) % 3, nx2 = (i + dx[k] * 2 + 9) % 3, ny2 = (j + dy[k] * 2 + 9) % 3;
          if (a[nx1][ny1]) {
            --a[nx1][ny1];
            ++a[nx2][ny2];
            if (check()) return 1;
            ++a[nx1][ny1];
            --a[nx2][ny2];
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  freopen("galaxy.in", "r", stdin);
  freopen("galaxy.out", "w", stdout);
  while (cin >> k) {
    r(n), r(m), r(xx), r(yy);
    xx %= 3, yy %= 3;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        a[i][j] = 0;
      }
    }
    for (int i = 0, x, y; i < k; ++i) {
      r(x), r(y);
      ++a[x % 3][y % 3];
    }
    if (check()) {
      putchar('Y'), putchar('E'), putchar('S');
    } else {
      putchar('N'), putchar('O');
    }
    putchar(10);
  }
  return 0;
}
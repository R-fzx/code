#include <bits/stdc++.h>
#define min(a, b) (a > b ? a : b)

using namespace std;

const int MAXN = 1005;

inline int r() {
  int c = getchar(), s = 0;
  while (c < 48 || c > 57) c = getchar();
  while (c > 47 && c < 58) s = (s << 3) + (s << 1) + c - 48, c = getchar();
  return s;
}

inline void w(int x) {
  if (x > 9) {
    w(x / 10);
  }
  putchar(x % 10 + 48);
}

int a[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, m;

int shit(int x, int y) {
  bool f[5] = {0, 0, 0, 0, 0};
  for (int i(0), nx, ny; i < 4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    if (min(nx, ny) > -1 && nx < n && ny < m && a[nx][ny] < 5) {
      f[a[nx][ny]] = 1;
    }
  }
  for (int i(1); i < 5; ++i) {
    if (f[i] == 0) {
      return i;
    }
  }
  return 114514;
}

void fillshit(int x, int y, int cnt, int z) {
  for (int i(0); i < cnt; ++i) {
    for (int j(0); j < cnt; ++j) {
      a[i + x][j + y] = z;
    }
  }
}

int main() {
  freopen("chongjg.in", "r", stdin);
  freopen("chongjg.out", "w", stdout);
  n = r(), m = r();
  for (int j(0); j < m; ++j) {
    for (int i(0), nc, f(0), cnt, fi, fj; i < n; ++i) {
      if (!a[i][j]) {
        nc = shit(i, j);
        if (f) {
          if (nc > a[i - 1][j] && m - j > cnt) {  //扩展矩形
            ++cnt;
            nc = a[i - 1][j];
          } else {
            fillshit(fi, fj, cnt, a[i - 1][j]);
            f = 0;
          }
        }
        a[i][j] = nc;
        if (!f) {
          f = cnt = 1;
          fi = i, fj = j;
        }
        if (i + 1 == n || a[i + 1][j]) {
          fillshit(fi, fj, cnt, a[i][j]);
          f = 0;
        }
      }
    }
  }
  for (int i(0); i < n; ++i) {
    for (int j(0); j < m; ++j) {
      putchar(64 + a[i][j]);
    }
    putchar(10);
  }
  return 0;
}
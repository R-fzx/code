# include <stdio.h>

using namespace std;

int n, m, x, y, N, M;
char ans[1010][1010], u, l;

int main() {
  freopen("chongjg.in", "r", stdin);
  freopen("chongjg.out", "w", stdout);
  scanf("%d%d", &n, &m);
  N = n;
  M = m;
  while (n && m) {
    char now = 'A';
    while (l == now || u == now) {
      ++now;
    }
    if (n < m) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          ans[x + i][y + j] = now;
        }
      }
      y += n;
      l = now;
      m -= n;
    } else {
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
          ans[x + i][y + j] = now;
        }
      }
      x += m;
      u = now;
      n -= m;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }
}
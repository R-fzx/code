#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int N, L, K, v[209], cnt1, cnt2, tot;
double p[209], a[209], b[209][109], ans;
inline int read() {
  char ch(getchar());
  int r(0), w(1);
  while (ch < '0' || ch > '9') w = ch == '-' ? -1 : w, ch = getchar();
  while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r * w;
}
inline void work1(double p) {
  double c[210];
  fill(&c[0], &c[cnt1 + 2], 0.0);
  c[0] = a[0] * (1 - p);
  cnt1++;
  for (int i(1); i <= cnt1; i++) {
    c[i] = a[i - 1] * p + a[i] * (1 - p);
  }
  for (int i(0); i <= cnt1; i++) {
    a[i] = c[i];
  }
}
inline void work2(double p, int w) {
  double c[209][109];
  tot++, cnt2 += w;
  fill(&c[0][0], &c[tot + 1][min(cnt2, 100) + 1], 0);
  for (int j(0); j <= min(cnt2, 99); j++) c[0][j] = b[0][j] * (1 - p);
  for (int i(1); i <= tot; i++) {
    for (int j(0); j <= min(cnt2, 99); j++) {
      c[i][j] = j >= w ? (b[i - 1][j - w] * p + b[i][j] * (1 - p)) : b[i][j] * (1 - p);
    }
  }
  for (int i(1); i <= tot; i++) {
    // cout << i << '\n';
    if (cnt2 < 100) break;
    c[i][100] = b[i][100] * (1 - p);
    for (int j(100); j >= max(0, 100 - w); j--) {
      // cout << b[i - 1][j] << ' ' << i - 1 << ' ' << j << '\n';
      c[i][100] += b[i - 1][j] * p;
    }
  }
  for (int i(0); i <= tot; i++) {
    for (int j(0); j <= min(cnt2, 100); j++) {
      b[i][j] = c[i][j];
    }
  }
}
/*
7 2 2
11 45 14 19 19 81 0
-1 2 1 -1 -1 3 1 -1
*/
int main() {
  freopen("guard.in", "r", stdin), freopen("guard.out", "w", stdout);
  N = read(), L = read(), K = read();
  for (int i(0); i < N; i++) {
    p[i] = read() / 100.0;
  }
  for (int i(0); i < N; i++) {
    v[i] = read();
  }
  fill(&a[0], &a[102], 0), fill(&b[0][0], &b[209][109], 0);
  a[0] = 1, b[0][0] = 1;
  for (int i(0); i < N; i++) {
    if (v[i] < 0) {
      work1(p[i]);
    } else {
      work2(p[i], v[i]);
    }
    // cout << i << '\n';
    // for (int j(0); j <= cnt1; j++) {
    // cout << j << ' ' << a[j] << '\n';
    //}
    // cout << tot << ' ' << b[tot][100] << '\n';
    // for (int k(0); k <= tot; k++) {
    //   for (int j(0); j <= cnt2; j++) {
    //     cout << b[k][j] << ' ';
    //   }
    //   puts("");
    // }
    // puts(":::::");
    // getch();
  }
  // cout << b[3][100] << '\n';
  for (int i(0); i <= tot; i++) {
    for (int j(0); j <= min(cnt2, 100); j++) {
      for (int k(max(0, L - i)); k <= min(j + K, cnt1); k++) {
        ans += a[k] * b[i][j];
      }
    }
  }
  printf("%0.6f", ans);
  return 0;
}
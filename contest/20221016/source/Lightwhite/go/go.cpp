/**
 * @file go.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Go (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

using namespace std;
const int kN = 105, kM = 2e3 + 5;

struct Edge {
  int v, nxt;
} ed[kN];
int n, m, k, f[kN][kN][kM], a[kM], b[kM], t[kM], p[kN], h[kM], M, tot, s, T, ans, mid;
void A(int u, int v) {
  ed[++tot] = {v, h[u]};
  h[u] = tot;
}
int F(int x, int y) {
  return abs(p[x] - p[y]);
}
int E(int x, int y) {
  int r = 0;
  for (int i = h[p[y]]; i; i = ed[i].nxt) {
    if (t[ed[i].v] > x) {
      r += b[ed[i].v];
    }
  }
  return r;
}
int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> t[i];
    M = max (M, t[i]);
    A (a[i], i);
  }
  for (int i = 1; i <= n; i++) {
    if (h[i] || i == k) {
      p[++s] = i;
      if (i == k) {
        mid = s;
      }
    }
  }
  f[mid][mid][0] = E(0, mid);
  for (T = 1; T <= M; T++) {
    for (int i = 1; i <= s; i++) {
      if (F(i, mid) > T || i == mid) {
        continue;
      }
      if (i < mid) {
        for (int j = mid; j <= s && F(i, j) + F(j, mid) <= T; j++) {
          f[i][j][T] = max (f[i + 1][j][T - F(i, i + 1)], f[j][i + 1][T - F(i, j)]) + E(T, i);
          ans = max (ans, f[i][j][T]);
        }
      } else {
        for (int j = mid; j && F(i, j) + F(j, mid) <= T; j--) {
          f[i][j][T] = max (f[i - 1][j][T - F(i, i - 1)], f[j][i - 1][T - F(i, j)]) + E(T, i);
          ans = max (ans, f[i][j][T]);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
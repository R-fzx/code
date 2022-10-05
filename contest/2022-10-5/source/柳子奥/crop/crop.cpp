#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

#define int long long

using namespace std;

const int kMaxN = 1e5 + 5;

int n, a, b, c, d, m, ans;
int x[kMaxN], y[kMaxN], cnt[3][3];
bool vis[10][10][10];

signed main() {
  freopen("crop.in", "r", stdin);
  freopen("crop.out", "w", stdout);
  cin >> n >> a >> b >> c >> d >> x[1] >> y[1] >> m;
  for (int i = 2; i <= n; ++i) {
    x[i] = (a * x[i - 1] + b) % m;
    y[i] = (c * y[i - 1] + d) % m;
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[x[i] % 3][y[i] % 3];
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = i; j < 9; ++j) {
      for (int k = j; k < 9; ++k) {
        if (vis[i][j][k]) continue ;
        vis[i][j][k] = 1;
        int i1 = i / 3, i2 = i % 3;
        int j1 = j / 3, j2 = j % 3;
        int k1 = k / 3, k2 = k % 3;
        if ((i1 + j1 + k1) % 3 || (i2 + j2 + k2) % 3) continue ;
        if (i == j && j == k) {
          ans += cnt[i1][i2] * (cnt[i1][i2] - 1) * (cnt[i1][i2] - 2) / 6;
        } else if (i == j) {
          ans += cnt[i1][i2] * (cnt[i1][i2] - 1) / 2 * cnt[k1][k2];
        } else if (j == k) {
          ans += cnt[i1][i2] * cnt[j1][j2] * (cnt[j1][j2] - 1) / 2;
        } else {
          ans += cnt[i1][i2] * cnt[j1][j2] * cnt[k1][k2];
        }
      }
    }
  }
  cout << ans << endl;
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << 's' << endl;
  return 0;
}
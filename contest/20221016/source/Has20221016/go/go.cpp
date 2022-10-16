#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int M = 101, T = 1001;

int n, m, k, id[M], f[2][M][M][T], a[M], b[M], t[M], l, r, _t, ans;

int main() {
  freopen("go.in", "r", stdin);
  freopen("go.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> t[i];
    id[i] = i;
  }
  sort(id + 1, id + m + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= m; ++i) {
    if (a[id[i]] <= k && t[id[i]] >= k - a[id[i]] + 1) {
      l = id[i];
    }
    if (a[id[i]] > k && t[id[i]] >= a[id[i]] - k + 1) {
      r = id[i];
      break;
    }
  }
  if (l) {
    f[0][l][l][k - a[l] + 1] = f[1][l][l][k - a[l] + 1] = b[l];
  }
  if (r) {
    f[0][r][r][a[r] - k + 1] = f[1][r][r][a[r] - k + 1] = b[r];
  }
  for (int k = 1; k <= 2000; ++k) {
    for (int i = 1; i <= m; ++i) {
      for (int j = i + 1; j <= m; ++j) {
        l = id[i], r = id[j];
        if (k >= (_t = a[id[l + 1]] - a[l]) && f[0][id[l + 1]][r][k - _t]) {
          if (t[l] >= k) {
            f[0][l][r][k] = max(f[0][l][r][k], f[0][id[l + 1]][r][k - _t] + b[l]);
          } else {
            f[0][l][r][k] = max(f[0][l][r][k], f[0][id[l + 1]][r][k - _t]);
          }
        }
        if (k >= (_t = a[r] - a[id[r - 1]]) && f[1][l][id[r - 1]][k - _t]) {
          if (t[r] >= k) {
            f[1][l][r][k] = max(f[1][l][r][k], f[1][l][id[r - 1]][k - _t] + b[r]);
          } else {
            f[1][l][r][k] = max(f[1][l][r][k], f[1][l][id[r - 1]][k - _t]);
          }
        }
        if (k >= (_t = a[r] - a[l]) && f[1][id[l + 1]][r][k - _t]) {
          if (t[l] >= k) {
            f[0][l][r][k] = max(f[0][l][r][k], f[1][id[l + 1]][r][k - _t] + b[l]);
          } else {
            f[0][l][r][k] = max(f[0][l][r][k], f[1][id[l + 1]][r][k - _t]);
          }
        }
        if (k >= (_t = a[r] - a[l]) && f[0][l][id[r - 1]][k - _t]) {
          if (t[r] >= k) {
            f[1][l][r][k] = max(f[1][l][r][k], f[0][l][id[r - 1]][k - _t] + b[r]);
          } else {
            f[1][l][r][k] = max(f[1][l][r][k], f[0][l][id[r - 1]][k - _t]);
          }
        }
        ans = max(ans, max(f[0][l][r][k], f[1][l][r][k]));
      }
    }
  }
  cout << ans;
  return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int N = 1005, kInf = 0x7f7f7f7f;

struct V {
  int x, b, t;
} v[N];
int ans, sum[N], dp[N][N][2];
int n, k, m;

bool C (const V &x, const V &y) {
  return x.x < y.x;
}

signed main () {
  freopen ("go.in", "r", stdin);
  freopen ("go.out", "w", stdout);
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i].x >> v[i].b >> v[i].t;
  }
  sort (v + 1, v + 1 + m, C);
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + v[i].b;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == j && abs (k - v[i].x) < v[j].t) {
        dp[i][j][0] = dp[i][j][1] = abs (k - v[i].x) + 1;
      } else {
        dp[i][j][0] = dp[i][j][1] = kInf;
      }
    }
  }
  for (int len = 2; len <= m; len++) {
    for (int i = 1; i + len - 1 <= m; i++) {
      int j = i + len - 1;
      if (min (dp[i + 1][j][0] + v[i + 1].x - v[i].x,
          dp[i + 1][j][1] + v[j].x - v[i].x) <= v[i].t) {
        dp[i][j][0] = min (dp[i][j][0], min (dp[i + 1][j][0] + v[i + 1].x - v[i].x, 
                                             dp[i + 1][j][1] + v[j].x - v[i].x));
      }
      if (min (dp[i][j - 1][0] + v[j].x - v[i].x,
          dp[i][j - 1][1] + v[j].x - v[j - 1].x) <= v[j].t) {
        dp[i][j][1] = min (dp[i][j][1], min (dp[i][j - 1][0] + v[j].x - v[i].x, 
                                             dp[i][j - 1][1] + v[j].x - v[j - 1].x));
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j][0] != kInf || dp[i][j][1] != kInf) {
        ans = max (ans, sum[j] - sum[i - 1]);
      }
    }
  }
  cout << ans;
  return 0;
}
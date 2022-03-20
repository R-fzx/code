#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

#define N 410
#define ll long long
#define MOD 998244353
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
  int n, m;
  int a, b;
  ll x, y, z;
  bool can[N][N];
  ll dp[N][(N / 2)];
    ll binom[N][N];
  binom[0][0] = 1;
  for (int i = 1; i < N; i++) {
    binom[i][0] = 1;
    binom[i][i] = 1;
    rep(j, i - 1) {
      binom[i][j + 1] = (binom[i - 1][j] + binom[i - 1][j + 1]) % MOD;
    }
  }

  cin >> n >> m;
  rep(i, 2 * n)rep(j, 2 * n)can[i][j] = false;
  rep(i, m) {
    cin >> a >> b;
    can[a - 1][b - 1] = true;
    can[b - 1][a - 1] = true;
  }
  rep(i, 2 * n + 1)dp[i][0] = 1;
  for (int j = 1; j <= n; j++) {
    rep(i, 2 * (n - j) + 1) {
      dp[i][j] = 0;
      rep(k, j) {
        if (can[i][i + (2 * k) + 1]) {
          x = (dp[i + 1][k] * dp[i + (2 * k) + 2][j - k - 1]) % MOD;
          dp[i][j] = ((x*binom[j][k + 1]) + dp[i][j]) % MOD;
        }
      }
    }
  }
  cout << dp[0][n] << endl;

  return 0;
}


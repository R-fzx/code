#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

constexpr ll N = 4005, mod = 10007;

ll n, m, k, s, _s, q, m1, ans, p[N], _p[N], l[N], _m[N * N], f[N][N], dp[N][N];

void dfs(ll x, ll y, ll res) {
  if (x > _s) {
    ans += m1 / res * y;
    return;
  }
  dfs(x + 1, y, res);
  dfs(x + 1, -y, res * _p[x]);
}

void sb() {
  sort(p + 1, p + 1 + s);
  ll _k = k;
  for (ll i = 2; i <= q; i++) {
    if (_k == 1) {
      break;
    }
    if (_k % i == 0) {
      _p[++_s] = i;
      for (; _k % i == 0; _k /= i) {
      }
    }
  }
  if (_k != 1) {
    _p[++_s] = _k;
  }
}

int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  cin >> n >> m >> k;
  q = sqrt(k);
  for (ll i = 1; i <= q; i++) {
    if (k % i == 0) {
      p[++s] = i;
      if (k / i > q) {
        p[++s] = k / i;
      }
    }
  }
  sb();
  sort(_p + 1, _p + 1 + _s);
  for (ll i = 1; i <= s; i++) {
    _m[p[i]] = i;
    ans = 0;
    m1 = m / p[i];
    dfs(1, 1, 1);
    dp[1][i] = ans % mod;
  }
  for (ll i = 1; i <= s; i++) {
    for (ll j = 1; j <= i; j++) {
      if (p[i] % p[j] == 0) {
        f[i][++l[i]] = j;
      }
    }
  }
  for (ll i = 2; i <= n; i++) {
    for (ll j = 1; j <= s; j++) {
      for (ll k = 1; k <= l[j]; k++) {
        (dp[i][j] += dp[i - 1][f[j][k]] * dp[1][_m[p[j] / p[f[j][k]]]]) %= mod;
      }
    }
  }
  cout << dp[n][s];
  return 0;
}
# include <bits/stdc++.h>
# define ll long long
# define mod 1000000007

using namespace std;

int n, m;
ll mid, len, k, ans;
ll n1[1001000];
ll invn1[1001000];
ll lenp[1001000];

inline ll mi(ll x, ll y) {
  ll re = 1;
  while (y) {
    if (y & 1) {
      re = (re * x) % mod;
    }
    x = (x * x) % mod;
    y >>= 1;
  }
  return re;
}

inline ll inv(ll x) {
  return mi(x, mod - 2);
}

inline ll C(ll x, ll y) {
  return n1[x] * invn1[x - y] % mod * invn1[y] % mod;
}

int main() {
  freopen("painting.in", "r", stdin);
  freopen("painting.out", "w", stdout);
  n1[0] = 1;
  invn1[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    n1[i] = n1[i - 1] * i % mod;
    invn1[i] = inv(n1[i]);
  }
  scanf("%d%d%lld", &n, &m, &k);
  if (m == 1) {
    printf("%lld", mi(k, n));
    return 0;
  }
  mid = (m - 2) * n;
  len = n;
  lenp[1] = 1;
  for (int i = 2; i <= len; i++) {
    lenp[i] = mi(i, len);
    for (int j = 1; j < i; j++) {
      lenp[i] = (lenp[i] + mod - C(i, j) * lenp[j] % mod) % mod;
    }
  }
  for (int i = 0; i <= min(k, len); i++) {
    for (int j = 0; i + j <= len && i + j + j <= k; j++) {
      // printf("%d %d %d\n", i, j, (C(k, i) * C(k - i, j) % mod * C(k - i - j, j) % mod * lenp[i + j] % mod * lenp[i + j] % mod) * mi(i, mid) % mod);
      ans = (ans + (C(k, i) * C(k - i, j) % mod * C(k - i - j, j) % mod * lenp[i + j] % mod * lenp[i + j] % mod) * mi(i, mid) % mod) % mod;
    }
  }
  printf("%lld", ans);
}

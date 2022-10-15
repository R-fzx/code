#include <bits/stdc++.h>

#define int long long
#define db(x) cerr << #x << '=' << x << endl

using namespace std;

const int kMaxN = 2005, kMaxK = 1e6 + 5, kMod = 1e9 + 7;

int n, m, k, ans;
int f[kMaxN], g[kMaxN], fac[kMaxK], ifac[kMaxK], inv[kMaxK], S[kMaxN];

int qpow(int bs, int idx) {
  if (!idx) return 1;
  int ret = 1;
  for (; idx; idx >>= 1, bs = bs * bs % kMod) {
    if (idx & 1) ret = ret * bs % kMod;
  }
  return ret;
}

int A(int m, int n) {
  return fac[m] * ifac[m - n] % kMod;
}
int C(int m, int n) {
  if (m < n) return 0;
  return fac[m] * ifac[m - n] % kMod * ifac[n] % kMod;
}

signed main() {
  freopen("painting.in", "r", stdin);
  freopen("painting.out", "w", stdout);
  cin >> n >> m >> k;
  fac[0] = ifac[0] = 1;
  fac[1] = ifac[1] = inv[1] = 1;
  for (int i = 2; i <= k; ++i) {
    inv[i] = (-(kMod / i) * inv[kMod % i] % kMod + kMod) % kMod;
    fac[i] = fac[i - 1] * i % kMod;
    ifac[i] = ifac[i - 1] * inv[i] % kMod;
  }
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j; --j) {
      f[j] = (f[j] * j % kMod + f[j - 1] * (k - j + 1) % kMod) % kMod;
    }
    f[0] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    g[i] = f[i] * qpow(C(k, i), kMod - 2) % kMod;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      S[i] = (S[i] + g[j] * C(i, j) % kMod) % kMod;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ans = (ans + f[i] % kMod * C(i, j) % kMod * qpow(S[j], m - 2) % kMod * g[i] % kMod * C(k - i, i - j) % kMod) % kMod;
    }
  }
  cout << ans << endl;
  return 0;
}
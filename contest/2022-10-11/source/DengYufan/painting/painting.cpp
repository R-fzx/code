#include <iostream>
#define LL long long

using namespace std;

const LL kMod = 1000000007;
LL n, m, k, ans, fact[1000001] = {1}, _fact[1000001] = {1}, f[2001][2001] = {1};

LL Pow(LL x, LL y) {
  LL ans = 1;
  for (LL i = 1; i <= y; i <<= 1) {
    if (i & y) {
      ans = ans * x % kMod;
    }
    x = x * x % kMod;
  }
  return ans;
}

LL C(LL x, LL y) {
  return fact[x] * _fact[y] % kMod * _fact[x - y] % kMod;
}

int main() {
  freopen("painting.in", "r", stdin);
  freopen("painting.out", "w", stdout);
  cin >> n >> m >> k;
  for (LL i = 1; i <= 1000000; i++) {
    fact[i] = fact[i - 1] * i % kMod;
  }
  _fact[1000000] = Pow(fact[1000000], kMod - 2);
  for (LL i = 999999; i >= 1; i--) {
    _fact[i] = _fact[i + 1] * (i + 1) % kMod;
  }
  for (LL i = 1; i <= 2000; i++) {
    for (LL j = 1; j <= 2000; j++) {
      f[i][j] = (f[i - 1][j] * j % kMod + f[i - 1][j - 1] * j % kMod) % kMod;
    }
  }
  for (LL i = 1; i <= min(n, k); i++) {
    if (m == 1) {
      ans = (ans + f[n][i] * C(k, i) % kMod) % kMod;
    } else if (m == 2) {
      ans = (ans + f[n][i] * C(k, i) % kMod * f[n][i] % kMod * C(k, i) % kMod) % kMod;
    } else {
      for (LL j = max(i * 2 - k, 1LL); j <= i; j++) {
        ans = (ans + f[n][i] * C(k, i) % kMod * f[n][i] % kMod * C(k - j, i - j) % kMod * Pow(j, n * (m - 2)) % kMod) % kMod;
      }
    }
  }
  cout << ans;
  return 0;
}

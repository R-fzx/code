#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 5, Mod = 1000000007;

int ksm(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  int shit1 = ksm(x, y >> 1);
  return (((1ll * shit1 * shit1) % Mod) * (y & 1 ? x : 1)) % Mod;
}

int a[MAXN]; //阶乘
int f[MAXN];

int C(int x, int y) {
  return (1ll * a[y] * ksm((1ll * a[y - x] * a[x]) % Mod, Mod - 2)) % Mod;
}

int main() {
  freopen("painting.in", "r", stdin);
  freopen("painting.out", "w", stdout);
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  a[0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = (1ll * a[i - 1] * i) % Mod;
  }
  int minnk = n < k ? n : k;
  f[1] = 1;
  int sum = 2;
  for (int i = 2; i <= k; ++i) {
    f[i] = (1ll * ksm(i, n) - sum + Mod) % Mod;//*C(i - 1, i)
    sum = (1ll * (f[i] * C(i, i + 1)) % Mod + (1ll * sum * ksm(i, Mod - 2) * (i + 1)) % Mod) % Mod;
    // cout << f[i] << ' ' << sum << '\n';
  }
  for (int i = 1; i <= minnk; ++i) {
    int shit = (1ll * C(i, k) * f[i]) % Mod;
    // cout << shit << ' ' << 1ll * a[i] * C(i, k) * C(i, n) * ksm(i, n - i) << '\n';
    ans = (ans + (((1ll * shit * shit) % Mod) * ksm(i, m - 2)) % Mod) % Mod;
  }
  cout << ans;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int aa[114514];
int anss[114514];

const int MAXN = 2e3 + 5, Mod = 1000000007;
int n, k;

void check() {
  int cnt = 0;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    if (st.find(aa[i]) == st.end()) {
      ++cnt;
      st.insert(aa[i]);
    }
  }
  ++anss[cnt];
}

int ksm(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  int shit1 = ksm(x, y >> 1);
  return (((1ll * shit1 * shit1) % Mod) * (y & 1 ? x : 1)) % Mod;
}

int a[114514]; //阶乘

int C(int x, int y) {
  return (1ll * a[y] * ksm((1ll * a[y - x] * a[x]) % Mod, Mod - 2)) % Mod;
}

int ans;

void dfs(int x) {
  if (x == n) {
    check();
    return;
  }
  for (int i = 1; i <= k; ++i) {
    aa[x] = i;
    dfs(x + 1);
  }
}

int f[MAXN];

int main() {
  cin >> n >> k;
  dfs(0);
  a[0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = (1ll * a[i - 1] * i) % Mod;
  }
  f[1] = 1;
  int sum = 2;
  for (int i = 2; i <= k; ++i) {
    f[i] = (1ll * ksm(i, n) - sum + Mod) % Mod;//*C(i - 1, i)
    sum = (1ll * (f[i] * C(i, i + 1)) + (sum / i * (i + 1))) % Mod;
    cout << f[i] << ' ' << sum << '\n';
  }
  cout << '\n';
  for (int i = 1; i <= k; ++i) {
    int shit = (1ll * C(i, n) * ksm(i, n - i) * ksm(n - i + 1, Mod - 2)) % Mod * a[i];
    int shit1 = (1ll * f[i]) % Mod;
    cout << 1.0 * anss[i] / C(i, k) << ' ' << shit << ' ' << shit1 << '\n';
  }
  return 0;
}
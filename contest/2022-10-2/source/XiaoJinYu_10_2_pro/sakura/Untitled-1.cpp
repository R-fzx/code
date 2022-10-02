#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5, Mod = 1e9 + 7;

int a[MAXN], b[MAXN], cnt;
bool f[MAXN];

int main() {
    freopen("fucku.txt", "w", stdout);
  int n, ans = 2;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (!f[i]) {
      b[cnt++] = i;
      for (int j = 2; i * j <= n; ++j) {
        f[i * j] = 1;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    int _i = i;
    for (int j = 0; _i > 1; ++j) {
      while (_i % b[j] == 0) {
        _i /= b[j];
        ++a[b[j]];
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    ans = (1ll * ans * (a[i] + 1)) % Mod;
    cout << a[i] << '\n';
  }
  cout << '\n';
  cout << ans - 1;
  return 0;
}
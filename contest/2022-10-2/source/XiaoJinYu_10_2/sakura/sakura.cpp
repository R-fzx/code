#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5, Mod = 1e9 + 7;

int a[MAXN], b[MAXN], cnt;
bool f[MAXN];

int main() {
  freopen("sakura.in", "r", stdin);
  freopen("sakura.out", "w", stdout);
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
  for (int i = 0; i < cnt; ++i) {
    for (long long j = b[i]; j <= n; j *= b[i]) {
      a[b[i]] += n / j;
    }
  }
  int sum = 0;
  for (int i = 2; i <= n; ++i) {
    ans = (1ll * ans * (a[i] + 1)) % Mod;
  }
  cout << (ans - 1 + Mod) % Mod;
  return 0;
}
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3001;

int n, m, k, ans, a[N];

void Dfs(int x, long long s) {
  if (x == n + 1) {
    if (s % k == 0) {
      if (__gcd(s / k, (long long)k) != 1) {
        return;
      }
      ans++, ans %= 10007;
    }
    return;
  }
  for (int i = 1; i <= m; ++i) {
    a[x] = i;
    Dfs(x + 1, s * i);
  }
}

int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  Dfs(1, 1);
  cout << ans;
  return 0;
}
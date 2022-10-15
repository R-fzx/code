#include <iostream>
#include <cstdio>
#pragma GCC optimize("Ofast")

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N];

long long ans;

int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    ans += min(a[u], a[v]);
  }
  cout << ans;
  return 0;
}

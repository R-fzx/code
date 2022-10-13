#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 1;

int T, n, q;
long long x[N], y[N], s, t, ans;

int main() {
  freopen("simple.in", "r", stdin);
  freopen("simple.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= q; ++i) {
      cin >> s >> t;
      ans = 0;
      for (int j = 1; j <= n; ++j) {
        ans += max(abs(x[j] - s), abs(y[j] - t));
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
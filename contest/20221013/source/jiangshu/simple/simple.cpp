#pragma GCC optimize ("Ofast")
#include <iostream>
#define int long long

using namespace std;
using Pii = pair <int, int>;

const int N = 1e6 + 5;

Pii a[N];
int T, ans, n, q;

signed main () {
  freopen ("simple.in", "r", stdin);
  freopen ("simple.out", "w", stdout);
  ios_base::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  for (cin >> T; T--; ) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    for (int x, y; q--; ) {
      cin >> x >> y; ans = 0;
      for (int i = 1; i <= n; i++) {
        ans += max (abs (x - a[i].first), abs (y - a[i].second));
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
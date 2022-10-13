#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5;

struct D{
  ll x, y;
} d[N];

ll t, n, q, dx, dy, ans;

int main() {
  freopen("simple.in", "r", stdin);
  freopen("simple.out", "w", stdout);
  ios :: sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> d[i].x >> d[i].y;
    }
    for (int i = 1; i <= q; i++) {
      ans = 0;
      cin >> dx >> dy;
      for (int j = 1; j <= n; j++) {
        ans += max(abs(d[j].x - dx), abs(d[j].y - dy));
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
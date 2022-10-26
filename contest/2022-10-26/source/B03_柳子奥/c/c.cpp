#include <bits/stdc++.h>

#define int long long

using namespace std;

const int kMaxN = 1e5 + 5;

int n;
int a[kMaxN];

int get(int x) {
  int ret = 0;
  for (int i = 1; i <= n; ++i) ret += __builtin_popcount(x - a[i]);
  return ret;
}

signed main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int ans = 1e18;
  for (int i = mx; i <= mx + 500; ++i) {
    ans = min(ans, get(i));
  }
  cout << ans << endl;
  return 0;
}
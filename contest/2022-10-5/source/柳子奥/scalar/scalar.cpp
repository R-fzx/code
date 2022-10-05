#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

#define int long long

using namespace std;

const int kMaxN = 805;

int n, ans;
int x[kMaxN], y[kMaxN];

signed main() {
  freopen("scalar.in", "r", stdin);
  freopen("scalar.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
  }
  sort(x + 1, x + 1 + n), sort(y + 1, y + 1 + n);
  for (int i = 1, j = n; i <= n; ++i, --j) {
    ans += x[i] * y[j];
  }
  cout << ans << endl;
  return 0;
}
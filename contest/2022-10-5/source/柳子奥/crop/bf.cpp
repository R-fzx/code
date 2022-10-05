#include <bits/stdc++.h>

#ifdef ORZXKR
#include <debug.h>
#else
#define debug(...) 114514
#define pass 114514
#endif

#define int long long

using namespace std;

const int kMaxN = 1e5 + 5;

int n, a, b, c, d, m, ans;
int x[kMaxN], y[kMaxN];

signed main() {
  freopen("crop.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> n >> a >> b >> c >> d >> x[1] >> y[1] >> m;
  for (int i = 2; i <= n; ++i) {
    x[i] = (a * x[i - 1] + b) % m;
    y[i] = (c * y[i - 1] + d) % m;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0) ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
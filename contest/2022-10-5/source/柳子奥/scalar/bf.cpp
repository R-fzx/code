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
int x[kMaxN], y[kMaxN], id[kMaxN];

signed main() {
  freopen("scalar.in", "r", stdin);
  freopen("bf.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    id[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
  }
  ans = 1e18;
  sort(x + 1, x + 1 + n), sort(y + 1, y + 1 + n);
  do {
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
      tmp += x[id[i]] * y[i];
    }
    ans = min(ans, tmp);
  } while (next_permutation(id + 1, id + 1 + n));
  cout << ans << endl;
  return 0;
}
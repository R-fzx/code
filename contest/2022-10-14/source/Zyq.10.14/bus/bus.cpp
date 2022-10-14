#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, a[100009];
pair<int, int> b[100009];
inline int read() {
  int r(0);
  char ch(getchar());
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    r = (r << 1) + (r << 3) + ch - '0', ch = getchar();
  return r;
}
inline void work(int r, int p) {
  if (p == n) {
    return;
  }
  if (b[p].second < r) {
    ans += b[p].first * (r - b[p].second), r = b[p].second;
  }
  work(r, p + 1);
}
signed main() {
  freopen("bus.in", "r", stdin), freopen("bus.out", "w", stdout);
  n = read();
  for (int i(0); i < n; i++) {
    b[i] = {(a[i] = read()), i};
  }
  sort(b, b + n);
  work(n, 0);
  cout << ans;
  return 0;
}
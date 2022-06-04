#include <iostream>

using namespace std;
using LL = long long;

const int kT = 4e6 + 101;

int n, m, mv;
LL f[kT], s[kT], c[kT], ans = INT64_MAX;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    mv = max(mv, x), ++c[x], s[x] += x;
  }
  mv += m;
  for (int i = 0; i <= mv; ++i) {
    if (i) {
      c[i] += c[i - 1], s[i] += s[i - 1];
    }
    if (i >= m && c[i] == c[i - m]) {
      f[i] = f[i - m];
    } else {
      f[i] = i * c[i] - s[i];
      for (int j = max(0, i - m - m + 1); j <= i - m; ++j) {
        f[i] = min(f[i], f[j] + i * (c[i] - c[j]) - (s[i] - s[j]));
      }
    }
  }
  for (int i = mv - m; i <= mv; ++i) {
    ans = min(ans, f[i]);
  }
  cout << ans;
  return 0;
}
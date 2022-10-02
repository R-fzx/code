#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int kMaxL = 2e2 + 1, kMaxN = 4e4 + 1;
int n, m, k, a[kMaxN], b[kMaxN], _b[kMaxN], l[kMaxN], c[kMaxL][kMaxN];
pair<int, int> d[kMaxL][kMaxL];

int main() {
  freopen("dandelion.in", "r", stdin);
  freopen("dandelion.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = i;
  }
  k = sqrt(n);
  sort(l + 1, l + n + 1, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= n; i++) {
    b[l[i]] = b[l[i - 1]] + (a[l[i]] != a[l[i - 1]]);
  }
  for (int i = 1; i <= n; i++) {
    _b[b[i]] = a[i];
  }
  for (int i = 1; i <= n; i += k) {
    for (int j = i, mx = 0; j <= n; j++) {
      int _i = (i - 1) / k + 1, _j = (j - 1) / k + 1;
      if (++c[_i][b[j]] > c[_i][d[_i][_j].first] || c[_i][b[j]] == c[_i][d[_i][_j].first] && b[j] < d[_i][_j].first) {
        d[_i][_j] = {b[j], c[_i][b[j]]};
      }
    }
  }
  for (int i = 1, p = 0, l, r; i <= m; i++) {
    cin >> l >> r;
    l = (l + p - 1) % n + 1, r = (r + p - 1) % n + 1;
    if (l > r) {
      swap(l, r);
    }
    int _l = (l - 1) / k + 1, _r = (r - 1) / k + 1, ans = d[_l + 1][_r - 1].first, mx = d[_l + 1][_r - 1].second, t[kMaxN] = {};
    for (int j = l; j <= _l * k; j++) {
      int v = ++t[b[j]] + c[_l + 1][b[j]] - c[_r][b[j]];
      if (v > mx || v == mx && b[j] < ans) {
        ans = b[j], mx = v;
      }
    }
    for (int j = r; j >= _r * k - k + 1; j--) {
      int v = ++t[b[j]] + c[_l + 1][b[j]] - c[_r][b[j]];
      if (v > mx || v == mx && b[j] < ans) {
        ans = b[j], mx = v;
      }
    }
    cout << (p = _b[ans]) << '\n';
  }
  return 0;
}

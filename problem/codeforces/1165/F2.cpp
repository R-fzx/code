#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int kN = 2e5 + 1;

int n, m, a[kN], s, d[kN], p[kN];
vector<int> l[kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  for (int d, t; m--;) {
    cin >> d >> t;
    l[t].push_back(d);
  }
  for_each(l + 1, l + n + 1, [](vector<int> &x) { sort(x.begin(), x.end(), greater<int>()), x.push_back(0); });
  int _l = 1, _r = 2 * s;
  while (_l <= _r) {
    int m = _l + _r >> 1;
    for (int i = 1; i <= n; ++i) {
      for (p[i] = 0; l[i][p[i]] > m; ++p[i]) {
      }
      d[i] = i, p[i] = l[i][p[i]];
    }
    sort(d + 1, d + n + 1, [](int i, int j) { return p[i] < p[j]; });
    int c = s, t = 0, x = m;
    for (int i = 1, _m; i <= n; ++i) {
      _m = min(a[d[i]], p[d[i]] - t), c -= _m, t += _m, x -= _m;
    }
    if (x >= c * 2) {
      _r = m - 1;
    } else {
      _l = m + 1;
    }
  }
  cout << _l;
  return 0;
}
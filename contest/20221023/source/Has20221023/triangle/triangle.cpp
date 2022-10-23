#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 1;

int n, a[N], b[N], q, l, r, _n;

int main() {
  freopen("triangle.in", "r", stdin);
  freopen("triangle.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; ++i) {
    cin >> l >> r;
    _n = r - l + 1;
    if (_n < 3) {
      cout << "No\n";
      continue;
    }
    for (int j = 1; j <= _n; ++j) {
      b[j] = a[j + l - 1];
    }
    sort(b + 1, b + 1 + _n);
    bool f = 0;
    for (int i = 3; i <= _n; ++i) {
      if (b[i] < b[i - 1] + b[i - 2]) {
        f = 1;
        break;
      }
    }
    cout << (f ? "Yes" : "No") << '\n';
  }
  return 0;
}
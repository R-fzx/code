#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 1;

int n, m, q, a[N], ans;

int main() {
  freopen("section.in", "r", stdin);
  freopen("section.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1, o, l; i <= q; ++i) {
    cin >> o >> l;
    if (o == 1) {
      for (int j = 1; j <= m / 2; ++j) {
        swap(a[l + j - 1], a[l + m - j]);
      }
    } else {
      ans ^= a[l];
    }
  }
  cout << ans;
  return 0;
}
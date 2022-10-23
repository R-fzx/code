#pragma GCC optimize ("Ofast")
#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int a[N];
int n, m, q;
int ans;

int main () {
  freopen ("section.in", "r", stdin);
  freopen ("section.out", "w", stdout);
  ios_base::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int o, l, r; q--; ) {
    cin >> o >> l;
    if (o == 1) {
      r = l + m - 1;
      for (int i = l, j = r; i <= j; i++, j--) {
        swap (a[i], a[j]);
      }
    } else {
      ans ^= a[l];
    }
  }
  cout << ans;
  return 0;
}
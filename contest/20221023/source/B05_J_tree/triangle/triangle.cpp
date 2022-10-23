#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int n, m;

int main () {
  freopen ("triangle.in", "r", stdin);
  freopen ("triangle.out", "w", stdout);
  ios_base::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1, l, r, flag; i <= m; i++) {
    cin >> l >> r; flag = 0;
    for (int x = l; x <= r && !flag; x++) {
      for (int y = x + 1; y <= r && !flag; y++) {
        for (int z = y + 1; z <= r && !flag; z++) {
          if (a[z] > abs (a[x] - a[y]) && a[z] < a[x] + a[y]) {
            flag = 1;
          }
        }
      }
    }
    cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
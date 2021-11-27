#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

const int kN = 101;

int t, n, l, r, k, a[kN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int c = 0;
    for (int i = 1; i <= n; ++i) if (l <= a[i] && a[i] <= r && a[i] <= k) ++c, k -= a[i];
    cout << c << endl; 
  }
  return 0;
}
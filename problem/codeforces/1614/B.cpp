#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

const int kN = 7;

int t, n, a[kN], p[kN], d[kN];

int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], d[i] = i;
    sort(d + 1, d + n + 1, [](int i, int j) { return a[i] > a[j]; });
    p[0] = 0;
    for (int i = 1; i + 1 <= n; i += 2) {
      p[d[i]] = i / 2 + 1, p[d[i + 1]] = - i / 2 - 1;
    }
    if (n & 1) p[d[n]] = n / 2 + 1;
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
      s += 2LL * (p[0] > p[i] ? p[0] - p[i] : p[i] - p[0]) * a[i];
    }
    cout << s << endl;
    for (int i = 0; i <= n; ++i) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
#include <iostream>

using namespace std;
using LL = long long;

int t;
LL a[6], b[6];

int main() {
  // freopen("G.in", "r", stdin);
  // freopen("G.out", "w", stdout);
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 5; ++i) cin >> b[i];
    for (int i = 1; i <= 5; ++i) cin >> a[i], a[i] -= b[i];
    cout << (!(a[5] < 0 || -a[4] > a[5] || (a[4] < 0 && (a[1] -= a[4], a[5] += a[4], a[4] = 0), a[3] += a[5], a[2] += a[5], -a[3] > a[4])) && (a[3] < 0 && (a[1] -= a[3], a[4] += a[3], a[3] = 0), a[2] += a[4] << 1, a[1] += a[3], a[2] += a[3], a[2] >= 0 && a[1] + a[2] * 2 >= 0) ? "Yes" : "No") << endl;
  }
  return 0;
}
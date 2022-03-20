#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 5001;
const LL kM = 998244353;

int n;
Pii a[kN];
LL f[kN][kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= a[i].first - a[i].second; ++j) {
      ans = (ans + f[i - 1][j]) % kM;
    }
    for (int j = 0; j < kN; ++j) {
      f[i][j] = (f[i - 1][j] + (j >= a[i].second ? f[i - 1][j - a[i].second] : 0)) % kM;
    }
  }
  cout << ans;
  return 0;
}
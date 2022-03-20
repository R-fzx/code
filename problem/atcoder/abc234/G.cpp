#include <iostream>

using namespace std;
using LL = long long;
using Pll = pair<LL, LL>;

const int kN = 3e5 + 1;
const LL kM = 998244353;

int n, t[2] = {1, 1};
Pll q[2][kN];
LL a[kN], f[kN] = {1}, s[2], sf[kN] = {1};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  q[0][1] = {INT32_MAX, 0}, q[1][1] = {INT32_MIN, 0};
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (; j ? q[j][t[j]].first >= a[i] : q[j][t[j]].first <= a[i]; --t[j]) {
        s[j] = (s[j] - q[j][t[j]].first * (sf[q[j][t[j]].second - 1] - sf[q[j][t[j] - 1].second - 1] + kM) % kM + kM) % kM;
      }
      s[j] = (s[j] + a[i] * (sf[i - 1] - max(0LL, sf[q[j][t[j]].second - 1]) + kM) % kM) % kM, q[j][++t[j]] = {a[i], i};
    }
    f[i] = (s[0] - s[1] + kM) % kM, sf[i] = (sf[i - 1] + f[i]) % kM;
  }
  cout << f[n];
  return 0;
}
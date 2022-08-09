#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kN = 500001;

int n, ans, a[kN];

int main() {
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
  RF("snowman");
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int l = 1; l < n; ++l) {
    for (int i = 1; i + l <= n + 1; ++i) {
      for (int j = i; j + l <= n + 1; ++j) {
        bool f = 1;
        for (int k = 1; k < l; ++k) {
          f &= a[i + k] - a[j + k] == a[i] - a[j];
        }
        if (f) {
          ans = max(ans, min(j - i, l));
        }
      }
    }
  }
  cout << ans;
  return 0;
}
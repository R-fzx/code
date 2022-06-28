#include <iostream>

using namespace std;
using LL = long long;

int t, n, m;
LL ans;

int main() {
  for (cin >> t; t--;) {
    cin >> n >> m;
    ans = 0;
    for (int i = 1; i <= m; ++i) { // 向右走
      ans += i;
    }
    for (int i = 2; i <= n; ++i) { // 向下走
      ans += i * m;
    }
    cout << ans << '\n';
  }
}
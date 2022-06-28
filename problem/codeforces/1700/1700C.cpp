#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 2;

int t, n;
LL ans, b[kN], p;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    p = ans = 0;
    for (int i = 1, x; i <= n; ++i) {
      cin >> x;
      b[i] = x - p, p = x;  // 计算差分序列
    }
    b[n + 1] = -p;                      // b[n + 1] = -a[n]
    for (int i = 2; i <= n; ++i) {      // 考虑每个数
      if (b[i] > 0) {                   // 如果是正数
        b[n + 1] += b[i], ans += b[i];  // 执行 b[i] 次操作二
      } else if (b[i] < 0) {            // 如果是负数
        b[1] += b[i], ans -= b[i];      // 执行 -b[i] 次操作一
      }
      b[i] = 0;
    }
    if (b[1] > 0) {  // 如果 b[1] > 0
      b[n + 1] += b[1], ans += b[1], b[1] = 0;
    }
    cout << ans - b[1] << '\n';  // 统计要进行多少次操作三
  }
  return 0;
}
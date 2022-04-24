#include <iostream>

using namespace std;

const int kN = 2e5 + 1;

int t, n, k, a[kN], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    ans = 0;
    for (int i = 30; i >= 0; --i) {  // 从高到低枚举答案的第 i 位
      int c = 0;
      for (int j = 1; j <= n; ++j) {
        c += a[j] >> i & 1 ^ 1;  // 统计数列中有多少个数这一位为 0（即统计需要操作多少次）
      }
      if (k >= c) {             // 如果可以把这一位变成 1
        k -= c, ans |= 1 << i;  // 那么把这一位变成 1 肯定会更优
      }
    }
    cout << ans << endl;
  }
  return 0;
}
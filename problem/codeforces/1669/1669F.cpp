#include <iostream>

using namespace std;

const int kN = 2e5 + 1;

int t, n, a[kN], m;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    m = 0;
    for (int i = 1, j = n, si = 0, sj = 0; i <= j; ++i) {  // 双指针
      si += a[i];                                          // 枚举 Alice 吃了到了第几颗糖
      for (; i <= j && sj < si; sj += a[j], --j) {         // Bob 需要吃几块糖才能使得代价不小于 Alice 的代价
      }
      if (sj == si && i <= j) {  // 若代价相等
        m = max(m, i + n - j);   // 更新答案
      }
    }
    cout << m << endl;
  }
  return 0;
}
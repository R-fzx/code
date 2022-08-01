#include <iostream>

using namespace std;
using LL = long long;

const int kN = 1e5 + 1;

int n;
LL a[kN], x, s, k;

int main() {
  cin >> n;
  bool f = 1;
  for (int i = 1; i <= n; ++i) {  // 输入
    cin >> a[i];
    f &= a[i] % LL(1e12) == 0;
  }
  string _;
  cin >> _;
  if (_.size() > 18 && f) {  // 处理 x<=1e30 但 x 和 ai 都是 1e12 的倍数的情况
    for (int i = 0; i < _.size() - 12; ++i) {
      x = x * 10 + _[i] - '0';
    }
    for (int i = 1; i <= n; ++i) {
      a[i] /= LL(1e12);
    }
  } else {
    for (int i = 0; i < _.size(); ++i) {
      x = x * 10 + _[i] - '0';
    }
  }
  for (int i = 1; i <= n; ++i) {  // 统计数列和
    s += a[i];
  }
  k = x / s * n, x %= s;              // 计算有多少个整块序列
  for (int i = 1; x > 0; ++i, ++k) {  // 暴力计算剩下部分
    x -= a[i];
  }
  cout << k;
  return 0;
}
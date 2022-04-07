#include <cstdio>
#include <iostream>

using namespace std;
using LL = long long;

const int kMaxN = 3001, kM = 1e9 + 7;

int a[kMaxN], p[kMaxN], e[kMaxN], n, x, t;
LL f[kMaxN][kMaxN], s[kMaxN][kMaxN], g[kMaxN], ans, v = 1;

int C(LL w) {  // 求w逆元
  LL r = 1;
  for (int i = 1; i <= kM - 2; i <<= 1) {
    if (kM - 2 & i) {
      r = r * w % kM;
    }
    w = w * w % kM;
  }
  return r;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    e[i] = C(i);  // 预处理逆元
  }
  for (int i = 1; i <= n; i++) {  // 将两个排列合并成置换
    cin >> x;
    a[p[i]] = x;
  }
  // 预处理n个元素分m段的代价和
  f[0][0] = g[0] = 1;
  fill(s[0], s[0] + n + 1, 1);  // 初始化前缀和
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = (f[i][j - 1] + s[i - 1][j - 1]) % kM;
      s[i][j] = (s[i][j - 1] + f[i][j]) % kM;
    }
  }
  for (int i = 1; i <= n; i++) {  // 寻找所有环
    if (p[i]) {
      x = 0;
      for (int j = i; p[j]; j = a[j]) {  // 寻找当前环
        p[j] = 0, x++, t++;
      }
      for (int j = t; j >= 1; j--) {                // 枚举已选择的边数
        for (int k = min(x - 1, j); k >= 1; k--) {  // 枚举分配给当前环的边数
          g[j] = (g[j] + g[j - k] * f[x - k][x] % kM * x % kM * e[x - k]) % kM;
        }
        if (j >= x) {                                        // 选择整个环
          g[j] = (g[j] + g[j - x] * (x == 1 ? 1 : 2)) % kM;  // 判断是否为单点
        }
      }
    }
  }
  for (int i = n; i >= 0; i--) {                     // 枚举确定的位置数
    ans = (ans + g[i] * (i % 2 ? kM - v : v)) % kM;  // 容斥计算方案
    v = v * (n - i + 1) % kM;                        // 计算阶乘
  }
  cout << ans;
  return 0;
}
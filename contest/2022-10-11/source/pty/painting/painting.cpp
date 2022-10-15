#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("painting.in");
ofstream fout("painting.out");

const int kMaxN = 2001, kMaxK = 1e6 + 1, kM = 1000000007;

int n, m, k, t;
LL w[kMaxK] = {1}, _w[kMaxK] = {1}, vf[kMaxN], vg[kMaxN], f[kMaxN], ans, tot;

LL P(LL w, int n) {
  LL r = 1;
  for (int i = 1; i <= n; i <<= 1) {
    if (n & i) {
      r = r * w % kM;
    }
    w = w * w % kM;
  }
  return r;
}

LL C(int n, int m) { return w[n] * _w[m] % kM * _w[n - m] % kM; }

int main() {
  fin >> n >> m >> k;
  if (m == 1) {
    fout << P(k, n);
    return 0;
  }
  t = max(n, k);
  for (int i = 1; i <= t; i++) {  // 计算阶乘
    w[i] = w[i - 1] * i % kM;
  }
  _w[t] = P(w[t], kM - 2);       // 初始化阶乘倒数
  for (int i = t; i > 1; i--) {  // 计算阶乘倒数
    _w[i - 1] = _w[i] * i % kM;
  }
  vg[0] = m == 2;                 // 特殊处理中间有0种颜色的方案数
  for (int i = 1; i <= n; i++) {  // 预处理次方
    vf[i] = P(i, n);              // n次方
    vg[i] = P(i, (m - 2) * n);    // (m - 2) * n次方
  }
  for (int i = 1; i <= n; i++) {   // 预处理有i种颜色均出现的方案
    for (int j = 0; j < i; j++) {  // 有j种颜色没出现
      f[i] = (f[i] + C(i, j) * vf[i - j] % kM * (j % 2 ? -1 : 1) + kM) % kM;
    }
  }
  for (int i = 0; i <= n && i * 2 <= k; i++) {            // 只在左或者右出现的颜色数量
    for (int j = 0; i + j <= n && i * 2 + j <= k; j++) {  // 枚举左右都出现的颜色数量
      if (i + j) {
        ans = (ans + C(k, i) * C(k - i, i) % kM * C(k - 2 * i, j) % kM * f[i + j] % kM * f[i + j] % kM * vg[j]) % kM;
      }
    }
  }
  fout << ans;
  return 0;
}
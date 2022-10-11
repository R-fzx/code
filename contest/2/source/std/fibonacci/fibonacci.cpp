#include <iostream>

using namespace std;

const int kN = 1.5e4, kM = 1e4;

int t, x, y, f[kN + 1];

int main() {
  freopen("fibonacci.in", "r", stdin);
  freopen("fibonacci.out", "w", stdout);
  // 预处理
  f[1] = 1, f[2] = 1;
  for (int i = 3; i <= kN; ++i) {  // 循环节
    f[i] = (f[i - 1] + f[i - 2]) % kM;
  }
  for (int i = 2; i <= kN; ++i) {  // 循环节
    f[i] = (f[i] + f[i - 1]) % kM;
  }
  f[0] = f[kN];  // f[0] = f[15000]
  for (cin >> t; t--;) {
    cin >> x >> y;
    cout << (f[y % kN] - f[(x - 1) % kN] + kM) % kM << '\n';
  }
  return 0;
}

/**
 * author :  bykem
 * time :  2022/10/10 15:53
 */
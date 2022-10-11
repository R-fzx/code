#include <iostream>

using namespace std;

const int kM = 1e4;

int f[kM * kM];
bool v[kM * kM];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  f[1] = f[2] = 1;
  for (int i = 3; i < kM * kM; ++i) {
    f[i] = (f[i - 1] + f[i - 2]) % kM;
  }
  for (int i = 1; i < kM * kM; ++i) {  // 暴力找循环节
    f[i] = (f[i] + f[i - 1]) % kM;
    if (v[f[i] * kM + f[i - 1]]) {
      cout << i << '\n';
      break;
    } else {
      v[f[i] * kM + f[i - 1]] = 1;
    }
  }
  return 0;
}
/*
sf[1]=sf[15001]
sf[0]=sf[15000]
sf[15001]-sf[15000]=sf[1]-sf[0]
f[15001]=f[1]
f[15000]=f[0]
*/

/**
 * author :  bykem
 * time :  2022/10/10 15:47
 */
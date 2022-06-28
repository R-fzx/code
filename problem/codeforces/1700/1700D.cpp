#include <iostream>

using namespace std;
using LL = long long;

const int kN = 2e5 + 1;

int n, q, a[kN];
LL l, r, s;

bool C(LL x) {  // 判断每个水龙头开 x 秒有没有解
  LL y = 0;     // 当前可以流到下一个桶的水量
  for (int i = 1; i <= n; ++i) {
    y += x;           // 把所有水龙头都打开
    if (a[i] <= y) {  // 如果可以装满
      y -= a[i];      // 减去这一部分，剩下的流到下一个桶里
    } else {          // 否则无解
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  l = 0, r = 1e9;
  for (LL m; l < r;) {  // 二分 y
    m = l + r + 1 >> 1;
    if (C(m)) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  cin >> q;
  for (int x; q--;) {
    cin >> x;
    cout << (x <= l ? -1 : (s + x - 1) / x) << '\n';
  }
  return 0;
}
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int n, k;
ll a[25], l, r, mid, ans, s;
ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;  // 切记先除后乘防止溢出
}
void D(ll x, ll s, ll c) {
  if (x > n) {
    if (c > 0) {
      if (c % 2 == 0) {  // 容斥
        ans -= mid / s * c;
      } else {
        ans += mid / s * c;
      }
    }
    return;
  }
  D(x + 1, s, c);  // 分治
  ll w = lcm(s, a[x]);
  if (w <= mid) {  // 特别的，如果 lcm 超过了 mid 一定要退出，否则会炸
    D(x + 1, w, c + 1);
  }
}
int main() {
  freopen("number.in", "r", stdin);  // 注释了的人紫菜
  freopen("number.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  l = 1, r = 1ll * 1e15;  // 二分初始化
  while (l < r) {         // 二分答案
    mid = (l + r) / 2;
    ans = 0;
    D(1, 1, 0);  // 分治
    if (ans < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l << '\n';
  return 0;
}

/**
 * author :  Lightwhite
 * time :  2022/10/10 19:39
 */
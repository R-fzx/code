/**
 * @file simple.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Too simple (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int kN = 1e6 + 5;

ll T, n, q, x[kN], y[kN], sx[kN], sy[kN];
int main() {
  freopen("simple.in", "r", stdin);
  freopen("simple.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  for (cin >> T; T; T--) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      ll X, Y;
      cin >> X >> Y;
      x[i] = X + Y;
      y[i] = X - Y;
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i <= n; i++) {
      sx[i] = sx[i - 1] + x[i];
      sy[i] = sy[i - 1] + y[i];
    }
    for (int i = 1; i <= q; i++) {
      ll _x, _y, X, Y;
      cin >> _x >> _y;
      X = _x + _y;
      Y = _x - _y;
      _x = upper_bound(x + 1, x + n + 1, X) - x - 1;
      _y = upper_bound(y + 1, y + n + 1, Y) - y - 1;
      cout << (_x * X * 2 - sx[_x] * 2 + sx[n] - n * X + _y * Y * 2 - sy[_y] * 2 + sy[n] - n * Y) / 2 << '\n';
    }
  }
  return 0;
}
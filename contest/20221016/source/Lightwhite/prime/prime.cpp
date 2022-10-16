/**
 * @file prime.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief Prime (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int T;
bool f1, f2, f3, t;
ll n, l, r, c, x, g;
int main() {
  freopen("prime.in", "r", stdin);
  freopen("prime.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  for (cin >> T; T; T--) {
    cin >> n;
    t = true;
    for (int i = 2; t && i * i <= n; i++) {
      t = n % i;
    }
    if (t) {
      for (r = n + 1; r; r++) {
        f1 = true;
        for (int i = 2; f1 && i * i <= r; i++) {
          f1 = r % i;
        }
        if (f1) {
          break;
        }
      }
      x = n * r - r * 2 + 2;
      c = n * r * 2;
      g = __gcd (x, c);
      cout << x / g << '/' << c / g << '\n';
    } else {
      for (l = n - 1; l; l--) {
        f2 = true;
        for (int i = 2; f2 && i * i <= l; i++) {
          f2 = l % i;
        }
        if (f2) {
          break;
        }
      }
      for (r = n + 1; r; r++) {
        f3 = true;
        for (int i = 2; f3 && i * i <= r; i++) {
          f3 = r % i;
        }
        if (f3) {
          break;
        }
      }
      x = l * r - l * 2 - r * 2 + n * 2 + 2;
      c = l * r * 2;
      g = __gcd(x, c);
      cout << x / g << '/' << c / g << '\n';
    }
  }
  return 0;
}
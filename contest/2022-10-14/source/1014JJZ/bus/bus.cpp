/**
 * @file bus.cpp
 * @author Lightwhite (Lwchicky@q.com)
 * @brief Bus (problem of 0class contest)
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

ll n, ans, m = LLONG_MAX, x;
int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    m = min(m, x);
    ans += m;
  }
  cout << ans << '\n';
  return 0;
}
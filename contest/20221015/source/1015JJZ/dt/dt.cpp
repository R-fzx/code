/**
 * @file dt.cpp
 * @author Lightwhite (Lwchicky@q.com)
 * @brief Dt (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <algorithm>
#include <iostream>

using namespace std;

long long n, m, ans, a[int(1e5 + 5)];
int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for_each(a + 1, a + n + 1, [&](long long &x) { cin >> x; });
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    ans += min (a[u], a[v]);
  }
  cout << ans << '\n';
  return 0;
}
#pragma GCC optimize ("Ofast")
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 1005;

ll dp[N], a[N];
int n;

int main () {
  freopen ("graph.in", "r", stdin);
  freopen ("graph.out", "w", stdout);
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort (a + 1, a + 1 + n, [](int x, int y) { return x > y; });
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int j = 1; j < i; j++) {
      if ((a[i] & a[j]) == 0) {
        dp[i] += a[j];
        break;
      }
    }
  }
  cout << dp[n];
  return 0;
}
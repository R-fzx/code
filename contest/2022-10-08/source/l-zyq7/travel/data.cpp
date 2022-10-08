#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  freopen("travel.in", "w", stdout);
  n = 200, m = 861;
  cout << n << ' ' << m << '\n';
  for (int i(1); i <= n; i++) {
    for (int j(i + 14); j <= n; j++) {
      if (j % i) continue;
      cout << i << ' ' << j << '\n';
    }
  }
  return 0;
}
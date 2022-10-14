#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  int n, minn;
  long long ans;
  cin >> n >> minn;
  ans = minn;
  for (int i = 1, x; i < n; ++i) {
    cin >> x;
    if (x < minn) minn = x;
    ans += minn;
  }
  cout << ans;
  return 0;
}
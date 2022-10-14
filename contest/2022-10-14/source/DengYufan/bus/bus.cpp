#include <iostream>
#define LL long long

using namespace std;

LL n, ans, a[100002];

int main() {
  freopen("bus.in", "r", stdin);
  freopen("bus.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = -114514;
  for (LL i = 1, p = 1; i <= n;) {
    for (i++; i <= n && a[i] >= a[p]; i++) {
    }
    ans += (i - p) * a[p], p = i;
  }
  cout << ans;
  return 0;
}

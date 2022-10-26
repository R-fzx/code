#include <iostream>
#define LL long long

using namespace std;

LL n, t, ans = 1e18, a[100001];

LL Calc(LL x) {
  LL c = 0;
  for (; x; x >>= 1) {
    c += x & 1;
  }
  return c;
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin >> n;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
    t = max(t, a[i]);
  }
  for (LL i = t; i <= t + 500; i++) {
    LL c = 0;
    for (LL j = 1; j <= n; j++) {
      c += Calc(i - a[j]);
    }
    ans = min(ans, c);
  }
  cout << ans;
  return 0;
}

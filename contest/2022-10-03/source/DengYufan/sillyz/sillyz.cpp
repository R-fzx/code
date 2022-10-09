#include <ctime>
#include <iostream>
#define LL long long

using namespace std;

LL l, r, ans;

LL M(LL x) {
  LL ans = 1;
  while (x) {
    ans *= x % 10, x /= 10;
  }
  return ans;
}

int main() {
  freopen("sillyz.in", "r", stdin);
  freopen("sillyz.out", "w", stdout);
  cin >> l >> r;
  for (LL i = 1; i <= r && clock() < 950; i++) {
    LL t = i * M(i);
    ans += t >= l && t <= r;
  }
  cout << ans;
  return 0;
}

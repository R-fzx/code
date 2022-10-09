#include <iostream>

using namespace std;

unsigned long long n, num = 1, ans;
long double v;

unsigned long long Find(unsigned long long _l, unsigned long long _r) {
  for (int i = 1; i <= 10001; i++) {
    if ((num * i) / _l > (num * i) / _r) {
      return (num * i) / _l;
    }
  }
}

int main() {
  freopen("baseball.in", "r", stdin);
  freopen("baseball.out", "w", stdout);
  while (cin >> n >> v) {
    num = 1;
    for (unsigned long long i = 0; i <= n; i++) {
      v *= 10;
      num *= 10;
    }
    for (unsigned long long i = -5; i < 4; i++) {
      ans = min(ans, Find(v + i, v + 4));
    }
    cout << ans << endl;
  }
  return 0;
}
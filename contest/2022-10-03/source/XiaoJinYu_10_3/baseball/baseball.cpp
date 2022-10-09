#include <bits/stdc++.h>

using namespace std;

void shit(int n, double r) {
  long long minn = 1145141919810114514, li = 0;
  long long shit = 1;
    for (int i = 0; i < n; ++i) {
      shit *= 10;
    }
    r *= shit;
    if (r == 0) {
      cout << 1 << '\n';
      return;
    }
    for (long long i = 2; i < 11451; ++i) {
      long long xx = 1.0 * i * (r + 0.5) / shit, xx2 = 1.0 * i * (r - 0.5) / shit;
      long long a = 1145141919810114514;
      for (long long j = xx2; j <= xx; ++j) {
        long long x = 1.0 * j / i * shit + 0.5;
        if (x == r) {
          cout << i << '\n';
          return;
        }
          if (abs(x - r) < a) {
            a = abs(x - r);
          }
      }
      if (minn > a) {
        minn = a;
      }
      }
}

int main() {
  freopen("baseball.in", "r", stdin);
  freopen("baseball.out", "w", stdout);
  int n;
  long double r;
  while (cin >> n >> r) {
    shit(n, r);
  }
  return 0;
}
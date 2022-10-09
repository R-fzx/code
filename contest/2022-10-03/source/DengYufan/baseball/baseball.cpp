#include <cmath>
#include <iostream>
#define LL long long

using namespace std;

LL n, ans;
double m, d[16] = {1};

int main() {
  freopen("baseball.in", "r", stdin);
  freopen("baseball.out", "w", stdout);
  for (LL i = 1; i < 16; i++) {
    d[i] = d[i - 1] * 10.0;
  }
  while (cin >> n) {
    cin >> m;
    for (ans = 1;; ans++) {
      LL _c = (double)(ans) / m + 0.5;
      double t = (double)(ans) / (double)(_c) * d[n];
      if ((LL)(t + 0.5) == (LL)(m * d[n] + 0.5) && (t - floor(t) < 0.5 || ceil(t) - t < 0.5)) {
        break;
      }
    }
    cout << (LL)((double)(ans) / m + 0.5) << '\n';
  }
  return 0;
}

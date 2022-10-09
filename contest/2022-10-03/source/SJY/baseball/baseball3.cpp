#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
double r;

int main() {
  freopen("baseball.in", "r", stdin);
  freopen("baseball.out", "w", stdout);
  while (~scanf("%d%lf", &n, &r)) {
    double temp = 1;
    long long sum = 1;
    for (int i = 1; i <= n; ++i) {
      temp /= 10.0;
      sum *= 10;
    }
    long long t = r * sum;
    long long ans = sum;
    for (int i = 2; i * i <= t; ++i) {
      while (t % i) {
        ans /= i;
        t /= i;
      }
    }
    double a = t / 100.0;
    cout << t << ' ' << ans;
    for (int i = 1; i <= ans; ++i) {
      cout << i / ans * t << '\n';
    }
  }
}
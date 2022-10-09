#include <iostream>
#include <cmath>

using namespace std;

int n;
double r;

int main() {
  while (~scanf("%d%lf", &n, &r)) {
    double temp = 1;
    long long sum = 1;
    for (int i = 1; i <= n; ++i) {
      temp /= 10.0;
      sum *= 10;
    }
    // cout << temp;
    for (int i = 2; i <= 1000; ++i) {
      double t = 1 * 1.0 / i;
      double num = int(int(r / t + 0.5) * t * sum + 0.5) * 1.0 / sum;
      if (num == r) {
        cout << i << '\n';
        break;
      }
    }
  }
}
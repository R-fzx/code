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
    long long le = 1, ri = sum;
    while (le < ri) {
      int mid = (le + ri) >> 1;
      double t = 1 * 1.0 / mid;
      double num = int(int(r / t + 0.5) * t * sum + 0.5) * 1.0 / sum;
      if (num != r) {
        le = mid + 1;
      } else {
        ri = mid;
      }
    }
    cout << le << '\n';
  }
}
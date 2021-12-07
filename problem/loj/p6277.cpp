#include <iostream>
#include <cmath>
#define lt(x) (x * b + 1)
#define rt(x) ((x + 1) * b)

using namespace std;
using LL = long long;

const int kN = 50001, kB = 255;

int n, o, l, r, c, b;
LL a[kN], p[kN], t[kB];

int main() {
  // freopen("p6277.in", "r", stdin);
  // freopen("p6277.out", "w", stdout);
  cin >> n;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = (i - 1) / b;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> o >> l >> r >> c;
    if (o == 0) {
      if (p[l] == p[r]) {
        for (int j = l; j <= r; ++j) {
          a[j] += c;
        }
      } else {
        for (int j = l; j <= rt(p[l]); ++j) {
          a[j] += c;
        }
        for (int j = lt(p[r]); j <= r; ++j) {
          a[j] += c;
        }
        for (int j = p[l] + 1; j < p[r]; ++j) {
          t[j] += c;
        }
      }
    } else {
      cout << a[r] + t[p[r]] << endl;
    }
  }
  return 0;
}
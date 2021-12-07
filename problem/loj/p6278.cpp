#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#define lt(x) (x * b + 1)
#define rt(x) min(n, (x + 1) * b)

using namespace std;
using LL = long long;

const int kN = 50001, kB = 255;

int n, b, o, l, r, p[kN];
LL a[kN], f[kN], t[kB], c;

void R(int k) {
  copy(a + lt(k), a + rt(k) + 1, f + lt(k));
  sort(f + lt(k), f + rt(k) + 1);
}

int main() {
  cin >> n;
  b = sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i] = (i - 1) / b;
  }
  for (int i = 0; i <= (n - 1) / b; ++i) {
    R(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> o >> l >> r >> c;
    if (o == 0) {
      if (p[l] == p[r]) {
        for (int j = l; j <= r; ++j) {
          a[j] += c;
        }
        R(p[l]);
      } else {
        for (int j = l; j <= rt(p[l]); ++j) {
          a[j] += c;
        }
        R(p[l]);
        for (int j = lt(p[r]); j <= r; ++j) {
          a[j] += c;
        }
        R(p[r]);
        for (int j = p[l] + 1; j < p[r]; ++j) {
          t[j] += c;
        }
      }
    } else {
      c *= c;
      int _c = 0;
      if (p[l] == p[r]) {
        for (int j = l; j <= r; ++j) {
          _c += a[j] + t[p[l]] < c;
        }
      } else {
        for (int j = l; j <= rt(p[l]); ++j) {
          _c += a[j] + t[p[l]] < c;
        }
        for (int j = lt(p[r]); j <= r; ++j) {
          _c += a[j] + t[p[r]] < c;
        }
        for (int j = p[l] + 1; j < p[r]; ++j) {
          _c += lower_bound(f + lt(j), f + rt(j) + 1, c - t[j]) - f - lt(j);
        }
      }
      cout << _c << endl;
    }
  }
  return 0;
}
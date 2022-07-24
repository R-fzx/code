#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 201;

int n;
struct BigInt {
  int a[kN * 3], n;

  BigInt() { n = 0, fill(a, a + kN * 3, 0); }
  BigInt(int o) { *this = o; }
  const BigInt &operator=(const BigInt &o) {
    n = o.n, copy(o.a, o.a + n, a);
    return *this;
  }
  const BigInt &operator=(LL o) {
    n = 0;
    for (; o; a[n++] = o % 10, o /= 10) {
    }
    return *this;
  }
  const BigInt &operator=(int o) {
    n = 0;
    for (; o; a[n++] = o % 10, o /= 10) {
    }
    return *this;
  }
  const BigInt operator+(const BigInt &o) const {
    BigInt s;
    s.n = max(n, o.n) + 1;
    for (int i = 0, p = 0; i < s.n; ++i) {
      s.a[i] = a[i] + o.a[i] + p, p = s.a[i] / 10, s.a[i] %= 10;
    }
    for (; !s.a[s.n - 1]; --s.n) {
    }
    return s;
  }
  const BigInt operator-(const BigInt &o) const {
    BigInt s;
    s.n = max(n, o.n) + 1;
    for (int i = 0, p = 0; i < s.n; ++i, p /= 10) {
      if (a[i] - p < o.a[i]) {
        s.a[i] = a[i] - p + 10 - o.a[i], p = 10;
      } else {
        s.a[i] = a[i] - p - o.a[i];
      }
    }
    for (; !s.a[s.n - 1]; --s.n) {
    }
    return s;
  }
  const BigInt operator*(const BigInt &o) const {
    BigInt s;
    s.n = n + o.n + 5;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < o.n; ++j) {
        s.a[i + j] += a[i] * o.a[j];
      }
    }
    for (int i = 0, p = 0; i < s.n; ++i) {
      s.a[i] += p, p = s.a[i] / 10, s.a[i] %= 10;
    }
    for (; !s.a[s.n - 1]; --s.n) {
    }
    return s;
  }
  void print() const {
    for (int i = n - 1; i >= 0; --i) {
      cout << a[i];
    }
  }
};
BigInt f[kN], ans, c[kN][kN];

int main() {
  freopen("t3.in", "r", stdin);
  freopen("t3.out", "w", stdout);
  cin >> n;
  f[0] = 1, c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i, c[i][0] = 1;
    for (int j = 1, x; j <= n; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1]; 
    }
  }
  for (int i = 0; i <= n; i += 2) {
    ans = ans + c[n][i] * f[n - i];
  }
  for (int i = 1; i <= n; i += 2) {
    ans = ans - c[n][i] * f[n - i];
  }
  ans.print();
  return 0;
}
#include <iostream>

using namespace std;
using LL = long long;

LL l, r, f[18][28][10], p[18];
int a[18], t;

LL S(LL n, int c) {
  for (t = 0; n; a[++t] = n % 10, n /= 10) {
  }
  LL s = 0, m = 0;
  for (int i = t - 1; i >= 1; --i) {
    s += f[i][0][c];
  }
  for (int i = t; i >= 1; --i) {
    for (int j = 1; j < a[i]; ++j) {
      m = (m + p[i]) % 28, s += f[i - 1][28 - m][c];
    }
    m = (m + p[i]) % 28;
  }
  return s;
}

int main() {
  cin >> l >> r;
  for (int i = p[0] = 1; i < 18; p[i] = p[i - 1] * 10, ++i) {
  }
  for (int i = 0; i < 17; ++i) {
    for (int j = 0; j < 28; ++j) {
      for (int c = 0; c < 10; ++c) {
        for (int k = 0; k < 10; ++k) {
          f[i + 1][(10 * j + k) % 28][c] += f[i][j][c] + (k == c);
        }
      }
    }
  }
  for (int i = 0; i <= 9; ++i) {
    cout << S(r, i) - S(l - 1, i) << ' ';
  }
  return 0;
}
/*
f[i+1][(10*j+k)%28][c]=f[i][j][c]+(k==c)
*/
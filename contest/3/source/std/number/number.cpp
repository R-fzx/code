#include <iostream>

using namespace std;
using LL = long long;

const int kN = 18;

LL l, r, p[kN], f[kN][4][7][10], g[kN][4][7];
int a[kN], t;

LL S(LL n, int c) {
  for (t = 0; n; a[++t] = n % 10, n /= 10) {
  }
  int _c = 0, m4 = 0, m7 = 0;
  LL s = 0;
  for (int i = t; i; --i) {
    for (int j = 0; j < a[i]; ++j) {
      _c += j == c, m4 = (m4 + j * p[i - 1] % 4) % 4, m7 = (m7 + j * p[i - 1] % 7) % 7;
      for (int k = 0; k < 4; ++k) {
        s += f[i - 1][k][(7 - m7) % 7][c] + _c * g[i - 1][k][(7 - m7) % 7];
      }
      for (int k = 0; k < 7; ++k) {
        s += f[i - 1][(4 - m4) % 4][k][c] + _c * g[i - 1][(4 - m4) % 4][k];
      }
      s -= f[i - 1][(4 - m4) % 4][(7 - m7) % 7][c] + _c * g[i - 1][(4 - m4) % 4][(7 - m7) % 7];
      _c -= j == c, m4 = (m4 - j * p[i - 1] % 4 + 4) % 4, m7 = (m7 - j * p[i - 1] % 7 + 7) % 7;
    }
    _c += a[i] == c, m4 = (m4 + a[i] * p[i - 1]) % 4, m7 = (m7 + a[i] * p[i - 1]) % 7;
  }
  if (!m4 || !m7) {
    s += _c;
  }
  if (!c) {
    for (int i = t; i; --i) {
      for (int j = 0; j < 4; ++j) {
        s -= g[i - 1][j][0];
      }
      for (int j = 0; j < 7; ++j) {
        s -= g[i - 1][0][j];
      }
      s += g[i - 1][0][0];
    }
  }
  return s;
}

int main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  cin >> l >> r;
  for (int i = p[0] = 1; i < kN; p[i] = p[i - 1] * 10, ++i) {
  }
  g[0][0][0] = 1;
  for (int i = 0; i + 1 < kN; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int x = 0; x < 10; ++x) {
          g[i + 1][(j * 10 + x) % 4][(k * 10 + x) % 7] += g[i][j][k];
        }
      }
    }
  }
  for (int i = 0; i + 1 < kN; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (int c = 0; c < 10; ++c) {
          for (int x = 0; x < 10; ++x) {
            f[i + 1][(j * 10 + x) % 4][(k * 10 + x) % 7][c] += f[i][j][k][c] + (x == c) * g[i][j][k];
          }
        }
      }
    }
  }
  for (int i = 0; i <= 9; ++i) {
    cout << S(r, i) - S(l - 1, i) << ' ';
  }
  return 0;
}
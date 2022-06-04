#include <cmath>
#include <iostream>

using namespace std;

const int kN = 1 << 21;
const double kPi = 2 * acos(-1);

struct C {
  double r, i;
  const C operator+(const C& o) const { return {r + o.r, i + o.i}; }
  const C operator-(const C& o) const { return {r - o.r, i - o.i}; }
  const C operator*(const C& o) const { return {r * o.r - i * o.i, r * o.i + i * o.r}; }
} f[kN], g[kN], t[kN];

int n, m, r[kN];

void FFT(C* f, int s) {
  for (int i = 0; i < n; ++i) i < r[i] && (swap(f[i], f[r[i]]), 0);
  for (int l = 2, _l = 1; l <= n; l <<= 1, _l <<= 1) {
    C u = {cos(kPi / l), s * sin(kPi / l)};
    for (int i = 0; i < n; i += l) {
      C w = {1, 0}, x;
      for (int j = i; j < i + _l; w = w * u, ++j) x = w * f[j + _l], f[j + _l] = f[j] - x, f[j] = f[j] + x;
    }
  }
}

int main() {
  // freopen("P3803.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) cin >> f[i].r;
  for (int i = 0; i <= m; ++i) cin >> g[i].r;
  for (m += n, n = 1; n <= m;) n <<= 1;
  for (int i = 0; i < n; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
  FFT(f, 1), FFT(g, 1);
  for (int i = 0; i < n; ++i) f[i] = f[i] * g[i];
  FFT(f, -1);
  for (int i = 0; i <= m; ++i) cout << int(f[i].r / n + 0.49) << " ";
  return 0;
}
/*
(r+iI)(o.r+o.iI)
r*o.r+r*o.iI+i*o.rI-i*o.i
*/
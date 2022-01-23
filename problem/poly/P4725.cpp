#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using Poly = vector<int>;

const int kM = 998244353, kG = 3;

int Add(int x, int y) { return x + y >= kM ? x + y - kM : x + y; }
void Addi(int &x, int y) { x = Add(x, y); }
int Sub(int x, int y) { return x >= y ? x - y : x - y + kM; }
void Subi(int &x, int y) { x = Sub(x, y); }
int Mul(int x, int y) { return 1LL * x * y >= kM ? 1LL * x * y % kM : x * y; }
void Muli(int &x, int y) { x = Mul(x, y); }
int Pow(int b, int e, int s = 1) {
  for (; e; e >>= 1, b = Mul(b, b)) {
    (e & 1) && (Muli(s, b), 0);
  }
  return s;
}

const Poly operator+(Poly x, Poly y) {
  int l = max(x.size(), y.size());
  Poly c(l);
  x.resize(l), y.resize(l);
  for (int i = 0; i < l; ++i) {
    c[i] = Add(x[i], y[i]);
  }
  return c;
}
const Poly operator-(Poly x, Poly y) {
  int l = max(x.size(), y.size());
  Poly c(l);
  x.resize(l), y.resize(l);
  for (int i = 0; i < l; ++i) {
    c[i] = Sub(x[i], y[i]);
  }
  return c;
}
const Poly operator*(Poly x, int y) {
  for (int &i : x) {
    Muli(i, y);
  }
  return x;
}
const Poly operator/(Poly x, int y) { return x * Pow(y, kM - 2); }

const double kPi = acos(-1);

struct Complex {
  double r, i;

  Complex(double _r = 0, double _i = 0) : r(_r), i(_i) {}
  Complex operator+(const Complex &o) const { return {r + o.r, i + o.i}; }
  Complex operator-(const Complex &o) const { return {r - o.r, i - o.i}; }
  Complex operator*(const Complex &o) const { return {r * o.r - i * o.i, r * o.i + i * o.r}; }
  Complex operator/(const double &o) const { return {r / o, i / o}; }
};

vector<int> r;
void Init_r(int n) {
  r.clear(), r.push_back(0);
  for (int i = 1; i < n; ++i) {
    r.push_back((r[i >> 1] >> 1) | ((i & 1) * (n >> 1)));
  }
}
void FFT(Complex f[], int n, int t) {
  for (int i = 0; i < n; ++i) {
    if (r[i] > i) {
      swap(f[i], f[r[i]]);
    }
  }
  for (int l = 1; l < n; l <<= 1) {
    Complex w(cos(kPi / l), t * sin(kPi / l));
    for (int i = 0; i < n; i += l << 1) {
      Complex u(1, 0);
      for (int j = 0; j < l; ++j, u = u * w) {
        Complex x = f[i + j], y = u * f[i + j + l];
        f[i + j] = x + y, f[i + j + l] = x - y;
      }
    }
  }
  if (t == -1) {
    for (int i = 0; i < n; ++i) {
      f[i] = f[i] / n;
    }
  }
}
const int kC = 21;
vector<int> w[kC + 1];
void Init_w() {
  for (int i = 1; i <= kC; ++i) {
    w[i].resize(1 << i - 1);
  }
  int _w = Pow(kG, (kM - 1) / (1 << kC));
  w[kC][0] = 1;
  for (int i = 1; i < (1 << kC - 1); ++i) {
    w[kC][i] = Mul(w[kC][i - 1], _w);
  }
  for (int i = kC - 1; i; --i) {
    for (int j = 0; j < (1 << i - 1); ++j) {
      w[i][j] = w[i + 1][j << 1];
    }
  }
}
void NTT(Poly &f, int n, int t) {
  for (int i = 0; i < n; ++i) {
    if (r[i] > i) {
      swap(f[i], f[r[i]]);
    }
  }
  for (int l = 1, _l = 1; l < n; l <<= 1, ++_l) {
    for (int i = 0; i < n; i += l << 1) {
      for (int j = 0; j < l; ++j) {
        int x = f[i + j], y = Mul(f[i + j + l], w[_l][j]);
        f[i + j] = Add(x, y), f[i + j + l] = Sub(x, y);
      }
    }
  }
  if (t == -1) {
    reverse(f.begin() + 1, f.begin() + n);
    for (int i = 0, iv = Pow(n, kM - 2); i < n; ++i) {
      Muli(f[i], iv);
    }
  }
}
Poly operator*(Poly x, Poly y) {
  int n = x.size() + y.size() - 1, l = 1;
  static const int kL = 128;
  if (n <= kL) {
    Poly c(n, 0);
    for (int i = 0; i < x.size(); ++i) {
      for (int j = 0; j < y.size(); ++j) {
        Addi(c[i + j], Mul(x[i], y[j]));
      }
    }
    return c;
  }
  for (; l < n; l <<= 1) {
  }
  Init_r(l), x.resize(l), y.resize(l), NTT(x, l, 1), NTT(y, l, 1);
  for (int i = 0; i < l; ++i) {
    Muli(x[i], y[i]);
  }
  NTT(x, l, -1), x.resize(n);
  return x;
}
Poly Inv(Poly f, int n) {
  Poly a(1, Pow(f[0], kM - 2)), b;
  for (int l = 4; l < (n << 2); l <<= 1) {
    Init_r(l), b = f, b.resize(l >> 1), a.resize(l), b.resize(l), NTT(a, l, 1), NTT(b, l, 1);
    for (int i = 0; i < l; ++i) {
      Muli(a[i], Sub(2, Mul(a[i], b[i])));
    }
    NTT(a, l, -1), a.resize(l >> 1);
  }
  return a.resize(n), a;
}
Poly Sqrt(Poly f, int n) {
  Poly a(1, 1), b;
  for (int l = 4, i2 = Pow(2, kM - 2); l < (n << 2); l <<= 1) {
    b = f, b.resize(l >> 1), Init_r(l), b = b * Inv(a, l >> 1), a.resize(l);
    for (int i = 0; i < l; ++i) {
      a[i] = Mul(i2, Add(a[i], b[i]));
    }
  }
  return a.resize(n), a;
}
Poly operator/(Poly x, Poly y) {
  int l = 1, n = x.size() - y.size() + 1;
  reverse(x.begin(), x.end()), reverse(y.begin(), y.end());
  for (; l <= n; l <<= 1) {
  }
  y = Inv(y, l), y.resize(n), x = x * y, x.resize(n), reverse(x.begin(), x.end());
  return x;
}
Poly operator%(Poly x, Poly y) {
  Poly a = x - x / y * y;
  a.resize(y.size() - 1);
  return a;
}
Poly Deriv(Poly x) {
  for (int i = 0; i < x.size() - 1; ++i) {
    x[i] = Mul(x[i + 1], i + 1);
  }
  return x.pop_back(), x;
}
vector<int> inv{0, 1};
void Init_iv(int n) {
  if (inv.size() <= n) {
    for (int i = inv.size(); i <= n; ++i) {
      inv.push_back(Mul(kM - kM / i, inv[kM % i]));
    }
  }
}
Poly Integ(Poly x) {
  Init_iv(x.size() - 1), x.push_back(0);
  for (int i = x.size() - 1; i; --i) {
    x[i] = Mul(x[i - 1], inv[i]);
  }
  return x[0] = 0, x;
}
Poly Ln(Poly f, int n) { return f = Integ(Deriv(f) * Inv(f, n)), f.resize(n), f; }
Poly Exp(Poly f, int n) {
  Poly a(1, 1), b;
  int m = f.size();
  for (int l = 2; l < (n << 1); l <<= 1) {
    b = Ln(a, l);
    for (int i = 0; i < l; ++i) {
      b[i] = Sub(i < m ? f[i] : 0, b[i]);
    }
    Add(b[0], 1), a = a * b, a.resize(l);
  }
  return a.resize(n), a;
}

int n;
Poly a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Init_w();
  cin >> n;
  a.resize(n);
  for (int &i : a) {
    cin >> i;
  }
  for (int i : Ln(a, n)) {
    cout << i << " ";
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
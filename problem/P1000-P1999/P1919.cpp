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

vector<int> r;
void Init_r(int n) {
  r.clear(), r.push_back(0);
  for (int i = 1; i < n; ++i) {
    r.push_back((r[i >> 1] >> 1) | ((i & 1) * (n >> 1)));
  }
}
const int kC = 23;
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
    if (i > r[i]) {
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

string a, b;
Poly x, y;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Init_w();
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (char i : a) {
    x.push_back(i - '0');
  }
  for (char i : b) {
    y.push_back(i - '0');
  }
  x = x * y;
  vector<int> l;
  int j = 0;
  for (int i = 0; i < x.size(); ++i) {
    j += x[i], l.push_back(j % 10), j /= 10;
  }
  if (j) {
    cout << j;
  }
  reverse(l.begin(), l.end());
  for (int i : l) {
    cout << i;
  }
#ifdef TIME
  fprintf(stderr, "\nTIME: %dms", clock());
#endif
  return 0;
}
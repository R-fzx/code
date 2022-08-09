#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kC = 4001, kN = 201, kK = 1001;

int n, ne[kC][26], fa[kC], d[kC], _d[2][kN], c[kN], _c, q[kC], h = 1, t, k;
double p, f[kK][kN];

void I(const string &s, int id) {
  int x = 0;
  for (char i : s) {
    int &y = ne[x][i - 'a'];
    if (!y) {
      y = ++_c;
    }
    x = y;
  }
  d[x] = id;
}
void G() {
  for (int i = 0; i < 26; ++i) {
    if (ne[0][i]) {
      q[++t] = ne[0][i];
    }
  }
  for (; h <= t; ++h) {
    int x = q[h];
    for (int i = 0; i < 26; ++i) {
      if (ne[x][i]) {
        fa[ne[x][i]] = ne[fa[x]][i], q[++t] = ne[x][i];
      } else {
        ne[x][i] = ne[fa[x]][i];
      }
    }
  }
}
void I() {
  char c;
  for (c = getchar(); c == '\n' || c == '\r'; c = getchar()) {
  }
  int x = 0;
  for (; c != '\n' && c != '\r'; c = getchar()) {
    if (c >= 'A' && c <= 'Z') {
      c += 'a' - 'A';
    }
    if (c >= 'a' && c <= 'z') {
      x = ne[x][c - 'a'];
      for (int y = x; y; y = fa[y]) {
        ++::c[d[y]];
      }
    }
  }
}

int main() {
#define RF(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
  // RF("ppfish0");
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string x;
    cin >> x;
    I(x, i);
  }
  G();
  // cout << _c << '\n';
  // for (int i = 0; i <= _c; ++i) {
  //   cout << i << ' ' << d[i] << ' ' << fa[i] << ' ';
  //   for (int j = 0; j < 26; ++j) {
  //     if (ne[i][j]) {
  //       cout << char(j + 'a') << ne[i][j] << ' ';
  //     }
  //   }
  //   cout << '\n';
  // }
  I();
  // for (int i = 1; i <= n; ++i) {
  //   cout << c[i] << ' ';
  // }
  // cout << '\n';
  cin >> p >> k;
  for (int i = 1; i <= n; ++i) {
    _d[0][i] = i;
  }
  sort(_d[0] + 1, _d[0] + n + 1, [](int i, int j) { return c[i] < c[j]; });
  for (int i = 1; i <= n; ++i) {
    _d[1][_d[0][i]] = i;
  }
  for (int i = 0; i <= n; ++i) {
    f[0][i] = 1;
  }
  // cout << fixed << setprecision(3);
  // cout << p << '\n';
  for (int i = 1; i <= k; ++i) {
    // double x = 1;
    for (int j = 1, u = 1; j <= n;) {
      for (; u <= n && c[_d[0][j]] == c[_d[0][u]]; ++u) {
      }
      double y = f[i - 1][j - 1];
      for (; j < u; ++j) {
        // x *= 1 - f[j];
        // f[j] *= 1 - y + y * p;
        f[i][j] = f[i - 1][j] * (1 - y) * p + y;
        // cout << f[j] << ' ';
      }
      // cout << '#';
    }
    // cout << '\n';
  }
  for (int i = 1; i <= n; ++i) {
    cout << fixed << setprecision(3) << f[k][_d[1][i]] << ' ';
  }
  return 0;
}
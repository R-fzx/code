#include <iostream>

using namespace std;

const int kN = 101;

struct M {
  int n, m, a[kN][kN];

  const M operator*(const M &o) const {
    M s;
    s.n = n, s.m = o.m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= o.m; ++j) {
        s.a[i][j] = 1e9;
        for (int k = 1; k <= m; ++k) {
          s.a[i][j] = min(s.a[i][j], max(a[i][k], o.a[k][j]));
        }
      }
    }
    return s;
  }
} e, f;
int n, t, l;

M P(M b, int e) {
  M s;
  s.n = s.m = n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      s.a[i][j] = (i == j ? -1e9 : 1e9);
    }
  }
  for (; e; e >>= 1, b = b * b) {
    if (e & 1) {
      s = s * b;
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> t >> l;
  e.n = e.m = n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      e.a[i][j] = 1e9;
    }
  }
  for (int i = 1, x, y; i <= t; ++i) {
    cin >> x >> y;
    e.a[x][y] = i;
  }
  f.n = 1, f.m = n;
  for (int i = 2; i <= n; ++i) {
    f.a[1][i] = 1e9;
  }
  f = f * P(e, l);
  for (int i = 1; i <= n; ++i) {
    cout << (f.a[1][i] == 1e9 ? -1 : f.a[1][i]) << " ";
  }
  return 0;
}
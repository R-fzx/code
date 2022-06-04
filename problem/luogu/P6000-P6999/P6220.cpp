#include <iostream>
#include <vector>

using namespace std;

const int kN = 501, kV = 2 * kN * kN;

int n, m, p[kV], v[kV], t, s, _[kV];
bool a[kN][kN], f[kV];
vector<int> ne[kV];

int Encode(int x, int y) {
  return (x - 1) * m + y;
}
bool F(int x) {
  if (v[x] ^ t) {
    v[x] = t;
    for (int i : ne[x]) {
      if (!p[i] || F(p[i])) {
        return p[i] = x, p[x] = i;
      }
    }
  }
  return 0;
}
void M(int x) {
  if (f[x]) {
    return;
  }
  f[x] = 1;
  for (int i : ne[x]) {
    if (p[i] && !f[i]) {
      f[i] = 1, M(p[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = ch == '1';
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m;) {
      for (int _j = j++; j <= m && !a[i][j]; ++j) {
        _[Encode(i, j)] = Encode(i, _j);
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n;) {
      for (int _i = i++; i <= n && !a[i][j]; ++i) {
        ne[_[Encode(i, j)]].push_back(Encode(_i + n, j));
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        ++t, s += F(Encode(i, j));
      }
    }
  }
  cout << s << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] && !p[Encode(i, j)]) {
        M(Encode(i, j));
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        if (!f[Encode(i, j)]) {
          cout << i << " " << j << " DESNO" << endl;
        }
        if (f[Encode(i + n, j)]) {
          cout << i << " " << j << " DOLJE" << endl;
        }
      }
    }
  }
  return 0;
}
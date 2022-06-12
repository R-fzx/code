#include <iostream>
#include <vector>

using namespace std;
using Vi = vector<int>;
using VVi = vector<Vi>;

const int kN = 2e5 + 1;

int n, m, c[kN], s;
VVi a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  a = VVi(n + 1, Vi(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= m; ++j) {
    fill_n(c, n, 0);
    for (int i = 1; i <= n; ++i) {
      c[(i - (a[i][j] - j) / m - 1 + n) % n] += (a[i][j] <= n * m && !((a[i][j] - j) % m));
    }
    int _s = 1e9;
    for (int i = 0; i < n; ++i) {
      _s = min(_s, i + n - c[i]);
    }
    s += _s;
  }
  cout << s;
  return 0;
}
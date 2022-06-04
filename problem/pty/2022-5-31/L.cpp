#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mL = modint998244353;

const int kN = 1e5 + 1;

struct M {
  int n, m;
  mL a[2][2];

  const M operator*(const M &o) const {
    M s = {n, o.m};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < o.m; ++j) {
        for (int k = 0; k < m; ++k) {
          s.a[i][j] += a[i][k] * o.a[k][j];
        }
      }
    }
    return s;
  }
} e[kN << 2];
const M kM[3] = {{2, 2, {{1, 1}, {0, 1}}}, {2, 2, {{1, 0}, {1, 1}}}, {2, 2, {{1, 1}, {1, 1}}}}, kF = {2, 1, {{1}, {1}}};
int n, q, x;
string s;

void B(int x, int l, int r, int m = 0) {
  if (l == r) {
    e[x] = kM[s[l] == '?' ? 2 : s[l] - '0'];
    return;
  }
  m = l + r >> 1, B(x * 2, l, m), B(x * 2 + 1, m + 1, r), e[x] = e[x * 2] * e[x * 2 + 1];
}
void U(int x, int l, int r, int t, char v, int m = 0) {
  if (l == r) {
    e[x] = kM[v == '?' ? 2 : v - '0'];
    return;
  }
  m = l + r >> 1, t <= m ? U(x * 2, l, m, t, v) : U(x * 2 + 1, m + 1, r, t, v), e[x] = e[x * 2] * e[x * 2 + 1];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q >> s, s = "#" + s;
  B(1, 1, n);
  for (char c; q--;) {
    cin >> x >> c;
    U(1, 1, n, x, c);
    M f = e[1] * kF;
    cout << (f.a[0][0] + f.a[1][0] - 2).val() << '\n';
  }
  return 0;
}
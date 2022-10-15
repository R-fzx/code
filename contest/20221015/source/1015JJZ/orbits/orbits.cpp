#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
const int kN = 4e3 + 5, kM = 1e4 + 7, kP = 1e7 + 5;

int n, m, k, fac[kN], a[kN], b[kN][kN], map[kP], M, s, f[kN][kN], sq, r;
void D(int x, int q, int e) {
  if (x > a[0]) {
    s += M / e * q;
    return;
  }
  D(x + 1, q, e);
  D(x + 1, -q, e * a[x]);
}
int main() {
  freopen("orbits.in", "r", stdin);
  freopen("orbits.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m >> k;
  sq = sqrt(k);
  for (int i = 1; i <= sq; i++) {
    if (k % i == 0) {
      fac[++fac[0]] = i;
      if (k / i > sq) {
        fac[++fac[0]] = k / i;
      }
    }
  }
  sort(fac + 1, fac + 1 + fac[0]);
  r = k;
  for (int i = 2; i <= sq && r != 1; i++) {
    if (r % i == 0) {
      for (a[++a[0]] = i; r % i == 0; r /= i) {
      }
    }
  }
  if (r != 1) {
    a[++a[0]] = r;
  }
  sort(a + 1, a + 1 + a[0]);
  for (int i = 1; i <= fac[0]; i++) {
    map[fac[i]] = i;
    s = 0;
    M = m / fac[i];
    D(1, 1, 1);
    f[1][i] = s % kM;
  }
  for (int i = 1; i <= fac[0]; i++) {
    for (int j = 1; j <= i; j++) {
      if (fac[i] % fac[j] == 0) {
        b[i][++b[i][0]] = j;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= fac[0]; j++) {
      if (b[j][0]) {
        for (int k = 1; k <= b[j][0]; k++) {
          (f[i][j] += f[i - 1][b[j][k]] * f[1][map[fac[j] / fac[b[j][k]]]]) %= kM;
        }
      }
    }
  }
  cout << f[n][fac[0]] << '\n';
  return 0;
}
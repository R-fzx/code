#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("guard.in");
ofstream fout("guard.out");

const int kMaxN = 202;

int a[kMaxN], n, l, _k;
double p[kMaxN], f[2][kMaxN][2 * kMaxN], ans;

int main() {
  fin >> n >> l >> _k;
  _k = min(n, _k);
  for (int i = 1; i <= n; i++) {
    fin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  f[0][0][_k + kMaxN] = 1;
  for (int i = 0; i < n; i++) {
    fill(f[1][0], f[1][kMaxN], 0);
    for (int j = 0; j <= i; j++) {
      for (int k = -n; k <= n; k++) {
        f[1][j][k + kMaxN] += f[0][j][k + kMaxN] * (100 - p[i + 1]) / 100;
        int _k = min(k + a[i + 1], n);
        f[1][j + 1][_k + kMaxN] += f[0][j][k + kMaxN] * p[i + 1] / 100;
      }
    }
    copy(f[1][0], f[1][kMaxN], f[0][0]);
  }
  for (int j = l; j <= n; j++) {
    for (int k = 0; k <= n; k++) {
      ans += f[1][j][k + kMaxN];
    }
  }
  fout << setprecision(6) << fixed << ans;
  return 0;
}
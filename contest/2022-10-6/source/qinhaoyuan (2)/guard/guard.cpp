#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

ifstream fin("guard.in");
ofstream fout("guard.out");

const int kMaxN = 2e5 + 1;
const int kM = 1e9 + 7;

int n, l, k;
int fa[kMaxN];
ld f[201][201][401];
int p[201], type[201];
ld ans;

int main() {
  fin >> n >> l >> k;
  f[0][0][200 + k] = 1;
  for (int i = 1; i <= n; i++) {
    fin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    fin >> type[i];
    for (int j = 0; j < i; j++) {
      for (int k = 0; k <= 400; k++) {
        f[i][j + 1][min(400, max(0, k + type[i]))] +=
            f[i - 1][j][k] * p[i] / 100.0;
        f[i][j][k] += f[i - 1][j][k] * (100 - p[i]) / 100.0;
        0;
      }
    }
  }
  for (int i = l; i <= n; i++) {
    for (int j = 200; j <= 400; j++) {
      ans += f[n][i][j];
    }
  }
  fout << fixed << setprecision(6) << ans << endl;
  return 0;
}
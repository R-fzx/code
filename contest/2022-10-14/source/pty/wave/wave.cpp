#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("wave.in");
ofstream fout("wave.out");

const int kN = 20;

int a[kN], n, m, s;
long long f[1 << kN][kN][2], c;

void I() {
  for (a[0] = 0; a[0] < n; a[0]++) {
    for (a[1] = 0; a[1] < n; a[1]++) {
      if (a[0] != a[1]) {
        if (f[s | 1 << a[0] | 1 << a[1]][a[1]][a[1] > a[0]] >= c) {
          s |= 1 << a[0] | 1 << a[1];
          return;
        }
        c -= f[s | 1 << a[0] | 1 << a[1]][a[1]][a[1] > a[0]];
      }
    }
  }
}

int main() {
  for (int j = 0; j < kN; j++) {
    f[(1 << kN) - 1][j][0] = f[(1 << kN) - 1][j][1] = 1;
  }
  for (int i = (1 << kN) - 2; i >= 1; i--) {
    for (int j = 0; j < kN; j++) {
      if (i >> j & 1) {
        for (int k = 0; k < kN; k++) {
          if (!(i >> k & 1)) {
            f[i][j][k < j] += f[i | 1 << k][k][k > j];
          }
        }
      }
    }
  }
  for (fin >> m; m; m--) {
    fin >> n >> c;
    if (n == 1) {
      fout << "1\n";
      continue;
    }
    s = ((1 << kN) - (1 << n));
    I();
    for (int i = 2; i < n; i++) {
      for (a[i] = 0; a[i] < n; a[i]++) {
        if (!(s >> a[i] & 1) && (a[i - 1] > a[i - 2]) == (a[i - 1] > a[i])) {
          if (f[s | 1 << a[i]][a[i]][a[i] > a[i - 1]] >= c) {
            s |= 1 << a[i];
            break;
          }
          c -= f[s | 1 << a[i]][a[i]][a[i] > a[i - 1]];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      fout << a[i] + 1 << ' ';
    }
    fout << '\n';
  }
  return 0;
}
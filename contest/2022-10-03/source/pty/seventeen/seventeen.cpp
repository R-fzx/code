#include <algorithm>
#include <fstream>

using namespace std;

const int kMaxN = 201;

ifstream fin("seventeen.in");
ofstream fout("seventeen.out");

int a[2][kMaxN], f[kMaxN * kMaxN], n, ans;

void D(int o) {
  fill(f, f + a[o][0], 0);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = a[o][0]; j >= a[o][i]; j--) {
      f[j] |= f[j - a[o][i]];
    }
  }
  int s = a[o][0];
  for (int i = 0; i <= a[o][0]; i++) {
    if (f[i]) {
      s = min(s, abs(a[o][0] - 2 * i));
    }
  }
  ans += s * s;
}

int main() {
  fin >> n; 
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      fin >> a[j][i];
      ans -= a[j][i] * a[j][i];
      a[j][0] += a[j][i];
    }
  }
  D(0), D(1);
  fout << ans / 2 << ".00";
  return 0;
}
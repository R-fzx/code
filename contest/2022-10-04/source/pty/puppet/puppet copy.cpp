#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("puppet.in");
ofstream fout("puppet.out");

const int kMaxN = 52, kMaxV = 103;

short f[kMaxV][kMaxN][kMaxN][2][2];
int c[kMaxV], d[kMaxN], n, m, ans;

int S(int i, int b0, int b1) {
  if (i > m) {
    return d[i - 1] && b0 ? n : 0;
  }
  if (f[i][d[i - 1]][d[i]][b0][b1]) {
    return f[i][d[i - 1]][d[i]][b0][b1];
  }
  f[i][d[i - 1]][d[i]][b0][b1] = n;
  for (int x = 0; x <= min(d[i], c[i]); x++) {
    for (int y = 0; y <= min(d[i + 1], c[i] - x); y++) {
      int z = min(c[i] - x - y, d[i - 1]);
      if (!b0 || z == d[i - 1]) && (!b1 || )
      
    }
  }
  
}
int main() {
  while (fin >> n) {
    fill(c, c + kMaxV, 0);
    m = 0;
    for (int i = 1, x; i <= n; i++) {
      fin >> x;
      c[x]++;
      m = max(m, x);
    }
    copy(c, c + kMaxV, d);
    fill(f[0][0][0], f[kMaxV][0][0], -1);
    fout << S(1, 0, 0) << '\n';
  }
  return 0;
}

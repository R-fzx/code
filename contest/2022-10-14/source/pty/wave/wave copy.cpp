#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("wave.in");
ofstream fout("wave.out");

const int kMaxM = 101, kMaxN = 20;

struct Q {
  int a[kMaxN], n;
  long long c;
} q[kMaxM];
int l[kMaxM], m;
long long f[1 << kMaxN][kMaxN][2], shit;

void F(int n) {
  for (int j = 0; j < n; j++) {
    f[(1 << n) - 1][j][0] = f[(1 << n) - 1][j][1] = 1;
  }
  for (int i = (1 << n) - 2; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        f[i][j][0] = f[i][j][1] = 0;
        for (int k = 0; k < n; k++) {
          if (!(i >> k & 1)) {
            f[i][j][k < j] += f[i | 1 << k][k][k > j];
          }
        }
      }
    }
  }
}

void I(int o) {
  for (int x = 0; x < q[o].n; x++) {
    for (int y = 0; y < q[o].n; y++) {
      if (x != y) {
        if (f[1 << x | 1 << y][y][y > x] < q[o].c) {
          q[o].c -= f[1 << x | 1 << y][y][y > x];
        } else {
          q[o].a[0] = x, q[o].a[1] = y;
          return;
        }
      }
    }
  }
}

void W(int o) {
  I(o);
  for (int i = 2, s = 1 << q[o].a[0] | 1 << q[o].a[1]; i < q[o].n; i++) {
    for (int j = 0; j < q[o].n; j++) {
      if (!(s >> j & 1) && ((q[o].a[i - 1] > q[o].a[i - 2]) ^ (j > q[o].a[i - 1]))) {
        if (f[s | 1 << j][j][j > q[o].a[i - 1]] < q[o].c) {
          q[o].c -= f[s | 1 << j][j][j > q[o].a[i - 1]];
        } else {
          q[o].a[i] = j;
          s |= 1 << j;
          break;
        }
      }
    }
  }
}

int main() {
  fin >> m;
  for (int i = 1; i <= m; i++) {
    fin >> q[i].n >> q[i].c;
    l[i] = i;
  }
  sort(l + 1, l + 1 + m, [](int i, int j) { return q[i].n < q[j].n; });
  for (int i = 1; i <= m; i++) {
    if (q[l[i]].n > 1) {
      if (q[l[i]].n != q[l[i - 1]].n) {
        F(q[l[i]].n);
      }
      W(l[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < q[i].n; j++) {
      fout << q[i].a[j] + 1 << ' ';
    }
    fout << '\n';
  }
  return 0;
}
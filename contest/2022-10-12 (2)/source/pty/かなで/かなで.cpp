#include <fstream>
#include <unordered_set>

using namespace std;
using LL = long long;

ifstream fin("かなで.in");
ofstream fout("かなで.out");

const int kMaxN = 101, kD[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

unordered_set<LL> s;
int a[kMaxN][kMaxN], b[kMaxN][kMaxN], c[kMaxN][kMaxN], p[kMaxN][kMaxN], q[kMaxN][kMaxN], l[kMaxN * kMaxN][2], n, m, k, ans;
char ch;

LL C(int n, int m) {
  if (n > m) {
    return 0;
  }
  LL r = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (p[i][j]) {
        r |= 1LL << ((i - 1) * 10 + j - 1);
      }
    }
  }
  return r;
}

void R(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      q[i][j] = p[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      p[j][n - i + 1] = q[i][j];
    }
  }
}

void Check2(int n, int m) {
  for (int i = 0; i < 4; i++) {
    s.insert(C(n, m));
    R(n, m), swap(n, m);
  }
}

void Check() {
  int xl = 1000, yl = 1000, xr = 0, yr = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[i][j]) {
        xl = min(xl, i), xr = max(xr, i);
        yl = min(yl, j), yr = max(yr, j);
      }
    }
  }
  for (int i = xl; i <= xr; i++) {
    for (int j = yl; j <= yr; j++) {
      p[i - xl + 1][j - yl + 1] = b[i][j];
    }
  }
  int n = xr - xl + 1, m = yr - yl + 1;
  if (n > m) {
    R(n, m), swap(n, m);
  }
  if (s.count(C(n, m))) {
    return;
  }
  ans++;
  Check2(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m - j + 1; j++) {
      swap(p[i][j], p[i][m - j + 1]);
    }
  }
  Check2(n, m);
}

void S(int i, int ll, int rr) {
  if (i > k) {
    Check();
    return;
  }
  for (int j = ll; j <= rr; j++) {
    int rr2 = rr;
    b[l[j][0]][l[j][1]] = 1;
    for (int k = 0; k < 4; k++) {
      int nx = l[j][0] + kD[k][0], ny = l[j][1] + kD[k][1];
      if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny]) {
        if (++c[nx][ny] == 1) {
          ++rr2, l[rr2][0] = nx, l[rr2][1] = ny;
        }
      }
    }
    S(i + 1, j + 1, rr2);
    for (int k = 0; k < 4; k++) {
      int nx = l[j][0] + kD[k][0], ny = l[j][1] + kD[k][1];
      if (nx > 0 && nx <= n && ny > 0 && ny <= m && a[nx][ny]) {
        --c[nx][ny];
      }
    }
    b[l[j][0]][l[j][1]] = 0;
  }
}

int main() {
  fin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      fin >> ch;
      a[i][j] = ch == '1';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        c[i][j] = 1;
        l[1][0] = i, l[1][1] = j;
        S(1, 1, 1);
        a[i][j] = 0;
        c[i][j] = 0;
      }
    }
  }
  fout << ans;
  return 0;
}

#include <fstream>

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

const int kMaxN = 401;

int a[kMaxN][kMaxN], b[kMaxN][kMaxN], p[kMaxN], t[kMaxN], n, m, ans;

void S(int r, int x) {
  if (r != x) {
    b[r][x + n] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (a[x][i]) {
      S(r, i);
    }
  }
}

bool M(int r, int x) {
  if (t[x] == r) {
    return 0;
  }
  t[x] = r;
  for (int i = n + 1; i <= 2 * n; i++) {
    if (b[x][i] && (!p[i] || M(r, p[i]))) {
      p[i] = x;
      return 1;
    }
  }
  return 0;
}

int main() {
  fin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
    fin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 1; i <= n; i++) {
    S(i, i);
  }
  for (int i = 1; i <= n; i++) {
    ans += M(i, i);
  }
  fout << n - ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (!p[i + n]) {
      fout << i << ' ';
    }
  }
  return 0;
}
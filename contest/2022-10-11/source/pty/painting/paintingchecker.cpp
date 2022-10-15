#include <fstream>

using namespace std;
using LL = long long;

ifstream fin("painting.in");
ofstream fout("painting.out");

const int kMaxN = 2001, kMaxK = 1e6 + 1, kM = 1000000007;

int n, m, k, t, ans, tag;
int a[kMaxN][kMaxN], c[kMaxN];

int P(int l, int r) {
  ++ tag;
  for (int i = 1; i <= n; i++) {
    for (int j = l; j <= r; j++) {
      c[a[i][j]] = tag;
    }
  }
  int tot = 0;
  for (int i = 1; i <= k; i++) {
    tot += c[i] == tag;
  }
  return tot;
}


bool C() {
  for (int i = 1; i < m; i++) {
    if (P(1, i) != P(i + 1, m)) {
      return 0;
    }
  }
  return 1;
}

void S(int x, int y) {
  if (x == n + 1) {
    ans += C();
    return;
  }
  for (a[x][y] = 1; a[x][y] <= k; a[x][y]++) {
    if (y == m) {
      S(x + 1, 1);
    } else {
      S(x, y + 1);
    }
  }
}


int main() {
  fin >> n >> m >> k;
  S(1, 1);
  fout << ans;
  return 0;
}
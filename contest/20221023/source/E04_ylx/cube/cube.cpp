#include <bits/stdc++.h>

#include <fstream>
#pragma GCC optimize("Ofast")

using namespace std;
using ll = long long;
using Pii = pair<int, int>;

ifstream fin("cube.in");
ofstream fout("cube.out");

const int N = 1e2 + 5;

int n, a[N][N][N], r;

int main() {
  fin >> n;
  for (int i = 1, c, d, e, f, g, h; i <= n; i++) {
    fin >> c >> d >> e >> f >> g >> h;
    for (int j = c; j <= f; j++) {
      for (int k = d; k <= g; k++) {
        for (int o = e; o <= h; o++) {
          a[j + 50][k + 50][o + 50]++;
        }
      }
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= 100; k++) {
        r += a[i][j][k] > n - 2;
      }
    }
  }
  fout << r;
  return 0;
}
/*
 */
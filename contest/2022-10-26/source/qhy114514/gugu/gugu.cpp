#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const int kM = 1e9 + 7;
const int kMaxN = 3001;

int n, m, t;
int f[kMaxN][kMaxN];
int v[kMaxN][kMaxN];

int main() {
  ifstream cin("gugu.in");
  ofstream cout("gugu.out");
  
  cin >> n >> m >> t;
  for (int i = 1; i <= t; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == a + 1) {
      v[a][b + 1]++;
    }
    if (d == b + 1) {
      v[a + 1][b] += 2;
    }
    if (c == a && b == d) {
      v[a][b + 1]++, v[a + 1][b] += 2;
    }
  }
  f[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1) {
        continue;
      }
      f[i][j] = ((v[i][j] == 1 || !v[i][j]) * f[i - 1][j] + (v[i][j] == 2 || !v[i][j]) * f[i][j - 1]) % kM;
    }
  }
  cout << f[n][m] << '\n';
  return 0;
}

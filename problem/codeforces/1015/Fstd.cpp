#include <iostream>

using namespace std;

const int kMaxN = 201, kM = 1e9 + 7;

string s;
int ne[kMaxN][2], f[kMaxN][kMaxN][kMaxN], n, m;

int main() {
  cin >> n >> s;
  m = s.length();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      if (s[j] == '(' && s.substr(0, j) == s.substr(i - j, j)) {
        ne[i][0] = j + 1;
      }
      if (s[j] == ')' && s.substr(0, j) == s.substr(i - j, j)) {
        ne[i][1] = j + 1;
      }
    }
  }
  ne[m][0] = ne[m][1] = m;
  f[0][0][0] = 1;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= m; k++) {
        for (int l = 0; l <= 1; l++) {
          int _j = j + (l ? -1 : 1), _k = ne[k][l];
          if (_j >= 0) {
            f[i + 1][_j][_k] = (f[i + 1][_j][_k] + f[i][j][k]) % kM;
          }
        }
      }
    }
  }
  cout << f[2 * n][0][m];
  return 0;
}

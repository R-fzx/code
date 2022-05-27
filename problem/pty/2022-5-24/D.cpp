#include <iostream>
#include <tuple>

using namespace std;

const int kN = 201;

struct F {
  int x = 1e9;
  tuple<int, int, int> p;
  char c;
} f[kN][kN][kN * 2]; // f[i][j][k]: a匹配完了前i个字符，b匹配完了前j个字符，ans左括号比右括号多k个，最短的ans长度
int n, m, t;
string a, b;
char l[kN * 2];

void U(int i, int j, int k, int o) { // o=1: 左括号, o=-1: 右括号
  int ni = i + (i < n && a[i] == ") ("[o + 1]), nj = j + (j < m && b[j] == ") ("[o + 1]);
  if (k + o >= 0 && k + o <= n + m && f[i][j][k].x + 1 < f[ni][nj][k + o].x) {
    f[ni][nj][k + o] = {f[i][j][k].x + 1, {i, j, k}, ") ("[o + 1]};
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  n = a.size(), m = b.size(), f[0][0][0].x = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= n + m; ++k) {
        U(i, j, k, 1), U(i, j, k, -1);
      }
    }
  }
  tuple<int, int, int> p;
  int mk = 0;
  for (int k = 1; k <= n + m; ++k) {
    mk = max(mk, k, [](int i, int j) { return f[n][m][i].x + i > f[n][m][j].x + j; });
  }
  for (int i = n, j = m, k = mk; i || j || k; l[++t] = f[i][j][k].c, tie(i, j, k) = f[i][j][k].p) {
  }
  for (; t; cout << l[t--]) {
  }
  cout << string(mk, ')');
  return 0;
}
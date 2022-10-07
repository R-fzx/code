#include <iostream>

using namespace std;

int n, m[11], ans[11], c[11], f[100001][11], g[100001][11];
string l, r, s;

void W(int n) {
  int m = 0;
  for (int i = 0; i <= 9; i++) {
    m += c[i] > 0;
  }
  for (int i = 0; i + m <= 10; i++) {
    ans[i + m] += f[n][i];
  }
}

void M() {
  fill(c, c + 11, 0);
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i] - '0'; j++) {
      c[j]++;
      W(s.size() - i - 1);
      c[j]--;
    }
    c[s[i] - '0']++;
  }
  W(0);
}

int main() {
  cin >> l >> r;
  for (n = l.size() - 1; n >= 0 && l[n] == '0'; n--) {
    l[n] = '9';
  }
  l[n]--, f[0][0] = 1, g[1][1] = 9;
  for (int i = 1; i <= 100000; i++) {
    for (int j = 1; j <= 10; j++) {
      f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1] * (11 - j);
    }
  }
  for (int i = 1; i <= 100000; i++) {
    for (int j = 1; j <= 10; j++) {
      g[i][j] = g[i - 1][j] * j + g[i - 1][j - 1] * (11 - j);
    }
  }
  s = l, M();
  copy(ans, ans + 11, m), fill(ans, ans + 11, 0);
  s = r, M();
  for (int i = 1; i < 11; i++) {
    cout << ans[i] - m[i] << ' ';
  }
  return 0;
}

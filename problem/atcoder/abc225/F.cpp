#include <algorithm>
#include <iostream>

using namespace std;

const int kN = 101;

int n, k;
string s[kN], f[kN][kN];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  sort(s + 1, s + n + 1, [](string i, string j) { return i + j < j + i; });
  f[n][1] = s[n];
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 1; j <= min(k, n - i + 1); ++j) {
      f[i][j] = s[i] + f[i + 1][j - 1], (i + j <= n) && (f[i][j] = min(f[i + 1][j], f[i][j]), 0);
    }
  }
  cout << f[1][k];
  return 0;
}
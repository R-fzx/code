#include <iostream>

using namespace std;

const int kL = 20, kM = (1 << kL) - 1;

int f[1 << kL], g[1 << kL], l[1 << kL], n, ans;
string s;

int main() {
  cin >> s, n = s.size();
  for (int i = 0; i < n; i++) {
    s[i] -= 'a';
    for (int j = i, v = 0; j >= 0 && !(v & 1 << s[j]); j--) {
      f[v |= 1 << s[j]] = 1;
      ans = max(ans, i - j + 1);
    }
  }
  for (int i = 1; i < 1 << kL; i++) {
    l[i] = l[i - (i & -i)] + 1;
    g[i] = f[i] * l[i];
    for (int j = 0; j < kL; j++) {
      (i >> j & 1) && (g[i] = max(g[i], g[i ^ (1 << j)]));
    }
  }
  for (int i = 1; i < 1 << kL; i++) {
    ans = max(ans, f[i] * (l[i] + g[kM - i]));
  }
  cout << ans;
  return 0;
}

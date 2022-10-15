#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1e5 + 1;
int n, m, s[kMaxN], c[kMaxN], tot;
bool f[kMaxN];
bool F(int c[]) {
  for (int i = 1; i <= n; i++) {
    if (c[i] != c[s[1]]) {
      return false;
    }
  }
  return true;
}
int main() {
  freopen("vote.in", "r", stdin);
  freopen("vote.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
    c[s[i]]++;
  }
  if (F(c)) {
    cout << "0.0000";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (!f[s[i]]) {
      tot++, f[s[i]] = 1;
    }
  }
  cout << fixed << setprecision(4) << 1.0 / (tot * 1.0);
  return 0;
}
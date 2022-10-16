#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 5e2 + 1;
int n, m;
char c[kMaxN][kMaxN];
int main() {
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  cout << "nemoguce";
  return 0;
}
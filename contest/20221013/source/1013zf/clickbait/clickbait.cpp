#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
char c;

int main() {
  freopen("clickbait.in", "r", stdin);
  freopen("clickbait.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      cnt += isdigit(c);
    }
  }
  for (int i = cnt; i >= 1; i--) {
    cout << i << '\n';
  }
  return 0;
}
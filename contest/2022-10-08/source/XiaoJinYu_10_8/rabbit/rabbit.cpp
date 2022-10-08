#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];
int b[1000][3];
int ans1[1000][3];
int n;
int ans;

void dfs(int x) {
  if (ans == n * (n - 1) / 2) {
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if (a[i][j] < 3 && a[i][k] < 3 && a[j][k] < 3) {
          ++a[i][j], ++a[i][k], ++a[j][k];
          b[x][0] = i, b[x][1] = j, b[x][2] = k;
          dfs(x + 1);
          --a[i][j], --a[i][k], --a[j][k];
        }
      }
    }
  }
  if (x > ans) {
    ans = x;
    cout << ans << '\n';
    for (int i = 0; i < x; ++i) {
      ans1[i][0] = b[i][0], ans1[i][1] = b[i][1], ans1[i][2] = b[i][2];
    }
    for (int i = 0; i < ans; ++i) {
      cout << ans1[i][0] << ' ' << ans1[i][1] << ' ' << ans1[i][2] << '\n';
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}

int main() {
  freopen("rabbit.in", "r", stdin);
  freopen("rabbit.out", "w", stdout);
  cin >> n;
  dfs(0);
  cout << ans << '\n';
  for (int i = 0; i < ans; ++i) {
    cout << ans1[i][0] << ' ' << ans1[i][1] << ' ' << ans1[i][2] << '\n';
  }
  
  return 0;
}
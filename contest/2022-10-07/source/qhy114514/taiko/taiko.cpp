#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int k, n;
int ans[2500];
bool vis[2500];

bool dfs(int now, int x) {
  if (vis[now]) {
    return 0;
  }
  vis[now] = 1, ans[x] = now & 1;
  if (x == n) {
    return 1;
  } else if (dfs(now << 1 & (n - 1), x + 1)) {
    return 1;
  } else if (dfs((now << 1 | 1) & (n - 1), x + 1)) {
    return 1;
  }
  vis[now] = 0;
  return 0;
}

int main() {
  ifstream cin("taiko.in");
  ofstream cout("taiko.out");

  cin >> k;
  n = 1 << k;
  dfs(n - 1, 1);
  cout << n << ' ';
  for (int i = 2; i <= n; ++i) {
    cout << ans[i];
  }
  cout << ans[1] << '\n';
  return 0;
}
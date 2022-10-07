#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2048 + 5;

bool ans[MAXN], vis[MAXN];
int k, n, cnt;

bool dfs(int x) {
  if (vis[x]) {
    return 0;
  }
  if (x == n) {
    cout << n + 1;
    putchar(32);
    for (int i = 0; i < k; ++i) {
      putchar(48);
    }
    for (int i = 0; i < cnt; ++i) {
      putchar(ans[i] + 48);
    }
    return 1;
  }
  vis[x] = 1;
  ans[cnt++] = 0;
  if (dfs((x << 1) & n)) {
    return 1;
  }
  --cnt;
  ans[cnt++] = 1;
  if (dfs(((x << 1) + 1) & n)) {
    return 1;
  }
  --cnt;
  vis[x] = 0;
  return 0;
}

int main() {
  freopen("taiko.in", "r", stdin);
  freopen("taiko.out", "w", stdout);
  cin >> k;
  n = (1 << k) - 1;
  dfs(0);
  return 0;
}
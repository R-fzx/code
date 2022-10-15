#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 1;

struct E {
  int x;
  vector<int> e;
} v[N];

int n, m, x, y, f[N], ans = 1e9;

void Dfs(int x, int s) {
  if (x == n + 1) {
    ans = min(ans, s);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      int sum = 0;
      for (int j : v[i].e) {
        if (f[j]) {
          continue;
        }
        sum += v[j].x;
      }
      f[i] = 1;
      Dfs(x + 1, s + sum);
      f[i] = 0;
    }
  }
}

int main() {
  freopen("dt.in", "r", stdin);
  freopen("dt.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i].x;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    v[x].e.push_back(y), v[y].e.push_back(x);
  }
  Dfs(1, 0);
  cout << ans;
  return 0;
}
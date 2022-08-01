#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, ans;
int in[N], out[N];

vector<int> v[N];

void bfs() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (!out[cur]) {
      ans++;
    }
    for (int i = 0; i < v[cur].size(); i++) {
      q.push(v[cur][i]);
    }
  }
}

int main() {
  freopen("lyx.in", "r", stdin);
  freopen("lyx.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i <= m; i++) {
    scanf("%d%d", &x, &y);
    in[y]++, out[x]++;
    v[x].push_back(y);
  }
  bfs();
  printf("%d", ans);
  return 0;
}
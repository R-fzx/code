#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

const int kMaxN = 1e5 + 1;

int n, m, ans;
int dep[kMaxN], num[kMaxN], cnt[kMaxN];
vector<int> g[kMaxN];
bool vis[kMaxN];

void BFS1() {
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) {
      q.push({i, 0});
    }
  }
  for (; !q.empty(); q.pop()) {
    int x = q.front().first, stp = q.front().second;
    dep[x] = stp;
    for (int i : g[x]) {
      q.push({i, stp + 1});
    }
  }
}

void BFS2() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) {
      num[i] = 1, q.push(i);
    }
  }
  for (; !q.empty(); q.pop()) {
    int x = q.front();
    if (vis[x]) {
      continue;
    }
    vis[x] = 1;
    for (int i : g[x]) {
      num[i] += num[x];
      if (dep[i] == dep[x] + 1) {
        q.push(i);
      }
    }
  }
}

int main() {
  ifstream cin("lyx.in");
  ofstream cout("lyx.out");
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), cnt[y]++;
  }
  BFS1(), BFS2();
  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) {
      ans += num[i];
    }
  }
  cout << ans << endl;
  return 0;
}
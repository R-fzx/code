#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll N = 1e3 + 10;

ll n, m, ans;
ll a[N][N];
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};

ll x;

struct Node {
  ll x, y;
  ll s;
};

void bfs() {
  queue<Node> q;
  Node cur = {1, 1, a[1][1]};
  q.push(cur);
  while (!q.empty()) {
    Node cur = q.front();
    q.pop();
    if (cur.x == n && cur.y == m && cur.s == x) {
      ans++;
    }
    for (ll i = 0; i < 2; i++) {
      ll nx = cur.x + dx[i];
      ll ny = cur.y + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny]) {
        Node ne = {nx, ny, cur.s ^ a[nx][ny]};
        q.push(ne);
      }
    }
  }
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> x;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  bfs();
  cout << ans;
  return 0;
}
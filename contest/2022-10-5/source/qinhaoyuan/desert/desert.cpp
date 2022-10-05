#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

string mapn[51];
int n, m, bx, by, now, ans = -INT32_MAX;
bool vis[51][51];
struct node {
  int x, y, day;
};

bool operator<(node x, node y) { return x.day > y.day; }

int dij() {
  priority_queue<node> q;
  memset(vis, 0, sizeof(vis));
  for (q.push({bx, by, 0}); !q.empty(); q.pop()) {
    int x = q.top().x, y = q.top().y, day = q.top().day;
    if (x < 0 || y < 0 || x >= n || y >= m || mapn[x][y] == 'X' || vis[x][y]) {
      continue;
    }
    if (mapn[x][y] == '*') {
      return day;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
      q.push({x + dx[i], y + dy[i], day + (now == i ? 3 : 1)});
    }
  }
  return -1;
}

int main() {
  ifstream cin("desert.in");
  ofstream cout("desert.out");

  cin >> n;
  char temp = getchar();
  for (int i = 0; i < n; i++) {
    for (char c = getchar(); c != '\n'; c = getchar()) {
      if (c != ' ' && c != '\n') {
        mapn[i] += c;
      }
    }
    for (int j = 0; j < mapn[i].size(); j++) {
      if (mapn[i][j] == '@') {
        bx = i, by = j;
      }
    }
  }
  m = mapn[0].size();
  for (now = 0; now < 8; now++) {
    ans = max(ans, dij());
  }
  cout << ans << endl;
  return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

constexpr int N = 505, d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int n, m, x, y, ans, a[N][N], v[N][N];

vector<pii> u;

struct AC {
  int x, y, t;
};

queue<AC> q;

void walk(int x, int y, int dx, int dy) {
  int i, j;
  for (i = x, j = y; i <= n && j <= m && i >= 1 && j >= 1 && a[i][j];
       i += dx, j += dy) {
  }
  if (i <= n && i >= 1 && j >= 1 && j <= m) {
    u.push_back({i - dx, j - dy});
  }
}

void bfs() {
  for (q.push({x, y, 0}); q.size(); q.pop()) {
    AC t = q.front();
    if (a[t.x][t.y] == 2) {
      ans = t.t;
      break;
    }
    walk(t.x, t.y, 1, 0);
    walk(t.x, t.y, 0, 1);
    walk(t.x, t.y, -1, 0);
    walk(t.x, t.y, 0, -1);
    for (auto&& i : d) {
      int _x = t.x + i[0], _y = t.y + i[1];
      if (_x >= 1 && _x <= n && _y >= 1 && _y <= m) {
        if (!a[_x][_y]) {
          for (auto&& i : u) {
            if (t.t + 1 < v[i.first][i.second]) {
              q.push({i.first, i.second, t.t + 1});
              v[i.first][i.second] = t.t + 1;
            }
          }
        } else {
          if (t.t + 1 < v[_x][_y]) {
            q.push({_x, _y, t.t + 1});
            v[_x][_y] = t.t + 1;
          }
        }
      }
    }
  }
}

int main() {
  freopen("portal.in", "r", stdin);
  freopen("portal.out", "w", stdout);
  fill(v[0], v[N - 1] + N, 1e9);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == 'C') {
        x = i;
        y = j;
      } else if (c == 'F') {
        a[i][j] = 1;
      }
      a[i][j] += c != '#';
    }
  }
  bfs();
  if (!ans) {
    cout << "nemoguce";
  } else {
    cout << ans;
  }
  return 0;
}
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

string mapn[101];
int t, n, m;
double l;
pair<int, int> s;
bool vis[101][101];
struct node {
  pair<int, int> dire;
  double dis;
};

bool operator<(node x, node y) { return x.dis > y.dis; }

int main() {
  ifstream cin("maze.in");
  ofstream cout("maze.out");
  for (cin >> t; t--;) {
    cin >> l >> n >> m;
    getline(cin, mapn[0]);
    for (int i = 0; i < n; i++) {
      getline(cin, mapn[i]);
      for (int j = 0; j < m; j++) {
        if (mapn[i][j] == 'S') {
          s = {i, j};
        }
      }
    }
    double ld = 0, rd = 10;
    for (double mid; rd - ld > 1e-7;) {
      mid = (ld + rd) / 2;
      priority_queue<node> q;
      memset(vis, 0, sizeof(vis));
      double tmpdis;
      for (q.push({s, 0}); !q.empty(); q.pop()) {
        int x = q.top().dire.first, y = q.top().dire.second;
        double dis = q.top().dis;
        if (x < 0 || y < 0 || x >= n || y >= m || mapn[x][y] == '#' ||
            vis[x][y]) {
          continue;
        }
        if (mapn[x][y] == 'E') {
          tmpdis = dis;
          break;
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
          q.push({{x + dx[i], y + dy[i]}, dis + (i % 2 ? 1 : mid)});
        }
      }
      if (tmpdis > l) {
        rd = mid;
      } else {
        ld = mid;
      }
    }
    cout << fixed << setprecision(5) << ld << '\n';
  }
  return 0;
}
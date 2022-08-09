#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, int> > map[21][21];
int n, m;
long long k, X;

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m >> X;
  map[0][1].push_back({(long long)0, 1});
  for (int i(1); i <= n; i++) {
    for (int j(1); j <= m; j++) {
      cin >> k;
      for (int z(0); z < map[i - 1][j].size() + map[i][j - 1].size(); z++) {
        long long a(0), b(0);
        pair<long long, int> temp_1, temp_2;
        if (a < map[i - 1][j].size()) {
          temp_1 = {map[i - 1][j][a].first ^ k, map[i - 1][j][a].second};
        }
        if (b < map[i][j - 1].size()) {
          temp_2 = {map[i][j - 1][b].first ^ k, map[i][j - 1][b].second};
        }
        if (a < map[i - 1][j].size() && (temp_1 <= temp_2 || b >= map[i][j - 1].size())) {
          if (map[i][j].size() > 0 && temp_1.first == map[i][j][map[i][j].size() - 1].first) {
            map[i][j][map[i][j].size() - 1].second += temp_1.second;
          } else {
            map[i][j].push_back(temp_1);
          }
          a++;
        }
        if (b < map[i][j - 1].size() && (temp_2 < temp_1 || a >= map[i - 1][j].size())) {
          if (map[i][j].size() > 0 && temp_2.first == map[i][j][map[i][j].size() - 1].first) {
            map[i][j][map[i][j].size() - 1].second += temp_2.second;
          } else {
            map[i][j].push_back(temp_2);
          }
          b++;
        }
      }
    }
  }
  for (int i(0); i < map[n][m].size(); i++) {
    if (map[n][m][i].first == X) {
      cout << map[n][m][i].second;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
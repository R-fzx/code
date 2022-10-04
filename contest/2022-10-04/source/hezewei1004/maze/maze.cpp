#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

char Map[101][101];
int n, m, t, x, y;
pair<int, int> M[101][101];
long double l;
list<pair<int, int>> F;

void Find() {
  while (!F.empty()) {
    int x = F.front().first, y = F.front().second;
    F.pop_front();
    if (M[x][y].first <= l) {
      int val_1 = M[x][y].first, val_2 = M[x][y].second;
      if (x > 1 && Map[x - 1][y] != '#') {
        if (M[x - 1][y].first != 0) {
          if (M[x - 1][y].first > val_1 || (M[x - 1][y].first == val_1 && M[x - 1][y].second > val_2 + 1)) {
            M[x - 1][y] = {val_1, val_2 + 1};
          }
        } else {
          M[x - 1][y] = {val_1, val_2 + 1};
          F.push_back({x - 1, y});
        }
      }
      if (y > 1 && Map[x][y - 1] != '#') {
        if (M[x][y - 1].first != 0) {
          if (M[x][y - 1].first > val_1 + 1 || (M[x][y - 1].first == val_1 + 1 && M[x][y - 1].second > val_2)) {
            M[x][y - 1] = {val_1 + 1, val_2};
          }
        } else {
          M[x][y - 1] = {val_1 + 1, val_2};
          F.push_back({x, y - 1});
        }
      }
      if (x < n && Map[x + 1][y] != '#') {
        if (M[x + 1][y].first != 0) {
          if (M[x + 1][y].first > val_1 || (M[x + 1][y].first == val_1 && M[x + 1][y].second > val_2 + 1)) {
            M[x + 1][y] = {val_1, val_2 + 1};
          }
        } else {
          M[x + 1][y] = {val_1, val_2 + 1};
          F.push_back({x + 1, y});
        }
      }
      if (y < m && Map[x][y + 1] != '#') {
        if (M[x][y + 1].first != 0) {
          if (M[x][y + 1].first > val_1 + 1 || (M[x][y + 1].first == val_1 + 1 && M[x][y + 1].second > val_2)) {
            M[x][y + 1] = {val_1 + 1, val_2};
          }
        } else {
          M[x][y + 1] = {val_1 + 1, val_2};
          F.push_back({x, y + 1});
        }
      }
    }
  }
}

void Reset(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      M[i][j] = {0, 0};
    }
  }
}

int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
      getchar();
      for (int j = 1; j <= m; j++) {
        Map[i][j] = getchar();
        if (Map[i][j] == 'S') {
          F.push_back({i, j});
          M[i][j] = {1, 1};
        } else if (Map[i][j] == 'E') {
          x = i, y = j;
        }
      }
    }
    Find();
    cout << fixed << setprecision(5) << (long double)(l - M[x][y].first + 1) / (M[x][y].second - 1) << endl;
    Reset(n, m);
  }
  return 0;
}
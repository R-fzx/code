/**
 * @file clickbait.cpp
 * @author Lightwhite (Lwchicky@qq.com)
 * @brief clickbait (problem of 1class contest)
 * @version 0.1
 * @date 2022-10-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>

using namespace std;
const int kN = 1e3 + 5, kM = 1e5 + 5, kD[2][2][2] = {{{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}}};

struct Node {
  int x1, y1, x2, y2;
} p[kM];
char map[kN][kN];
int n, m, a[kN][kN];
int D(int x, int y, int r, int k) {
  if (a[x][y]) {
    return a[x][y];
  }
  if (map[x][y] == '+') {
    int d = 1 - r;
    char c = map[x + kD[d][0][0]][y + kD[d][0][1]];
    if (d == 0 && c == '-' || d == 1 && c == '|') {
      return D(x + kD[d][0][0], y + kD[d][0][1], d, 0);
    } else {
      return D(x + kD[d][1][0], y + kD[d][1][1], d, 1);
    }
  }
  return D(x + kD[r][k][0], y + kD[r][k][1], r, k);
}
void P(int x) {
  Node p = ::p[x];
  for (int i = p.x2; i >= p.x1; i--) {
    if (p.y1 > 1 && map[i][p.y1 - 1] == '-') {
      P(D(i, p.y1 - 1, 0, 0));
    }
    if (p.y2 < m && map[i][p.y2 + 1] == '-') {
      P(D(i, p.y2 + 1, 0, 1));
    }
  }
  cout << x << '\n';
}
int main() {
  freopen("clickbait.in", "r", stdin);
  freopen("clickbait.out", "w", stdout);
  ios ::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for_each(map + 1, map + n + 1, [&](char *M) { cin >> M; });
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j] && isdigit(map[i][j])) {
        int r = j, d = map[i][j] - 48;
        for (; r < m && isdigit(map[i][r + 1]); d = d * 10 + map[i][++r] - 48) {
        }
        Node p = {i, j, i, j};
        for (; p.x1 > 1 && map[p.x1][j] != '-'; p.x1--) {
        }
        for (; p.y1 > 1 && map[i][p.y1] != '|'; p.y1--) {
        }
        for (; p.x2 < n && map[p.x2][j] != '-'; p.x2++) {
        }
        for (; p.y2 < m && map[i][p.y2] != '|'; p.y2++) {
        }
        ::p[d] = p;
        for (int _i = p.x1; _i <= p.x2; _i++) {
          for (int _j = p.y1; _j <= p.y2; _j++) {
            a[_i][_j] = d;
          }
        }
      }
    }
  }
  P(1);
  return 0;
}
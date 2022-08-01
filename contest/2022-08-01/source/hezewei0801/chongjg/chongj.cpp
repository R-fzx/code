// 贪心：最大化A, 最小化B,C, 优先放A,其次B,最后C;
#include <iostream>

using namespace std;

int n, m;
char color[101][101];

int main() {
  freopen("chongjg.in", "r", stdin);
  freopen("chongjg.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (color[i][j] != 'A' && color[i][j] != 'B' && color[i][j] != 'C') {  // 未被覆盖
        if (color[i - 1][j] != 'A' && color[i][j - 1] != 'A') {              // 可以使用A
          int Max = min(n - i, m - j);                                       // 矩阵最大边长
          for (int x = 0; x <= Max; x++) {
            for (int y = 0; y <= Max; y++) {
              color[i + x][j + y] = 'A';  // 染色
            }
          }
        } else {
          if (color[i][j - 1] == 'B' || color[i - 1][j] == 'B') {  // 不可使用A,B
            color[i][j] = 'C';                                     // 染色
          } else {                                                 // 仅有A不可使用
            color[i][j] = 'B';                                     // 染色
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << color[i][j];
    }
    cout << endl;
  }
  return 0;
}
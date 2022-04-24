#include <iostream>

using namespace std;

const int kN = 51;

int t, n, m;
char a[kN][kN];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> a[i][j];
      }
    }
    for (int j = 1; j <= m; ++j) {  // 对于每一列
      int c = 0;
      for (int i = 1; i <= n; ++i) {          // 从上至下处理
        if (a[i][j] == '*') {                 // 如果这里是石头
          ++c, a[i][j] = '.';                 // 累加石头数量，将此处设为空
        } else if (a[i][j] == 'o') {          // 如果碰到了障碍
          for (int k = i - 1; c; --k, --c) {  // 往上堆石头
            a[k][j] = '*';
          }
        }
      }
      for (int k = n; c; --k, --c) {  // 把剩下的石头从第 n 行开始堆
        a[k][j] = '*';
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cout << a[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
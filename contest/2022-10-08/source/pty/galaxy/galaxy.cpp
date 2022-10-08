#include <fstream>
#include <unordered_set>

using namespace std;
using LL = long long;

ifstream fin("galaxy.in");
ofstream fout("galaxy.out");

const int kK = 11, kD[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

unordered_set<LL> s;
LL w[9] = {1}, t;
int k, n, m, x0, y0;

bool V(int i, int j, int ni, int nj) {  // 判断两组坐标能够同时位于棋盘内部
  if (i >= n || ni >= n) {              // 行越上界
    i -= 3, ni -= 3;                    // 整体下移
  }
  if (i < 0 || ni < 0) {  // 行越下界
    i += 3, ni += 3;      // 整体上移
  }
  if (j >= m || nj >= m) {  // 列越上界
    j -= 3, nj -= 3;        // 整体下移
  }
  if (j < 0 || nj < 0) {  //列越下界
    j += 3, nj += 3;      //整体上移
  }
  return min(i, ni) >= 0 && max(i, ni) < n && min(j, nj) >= 0 && max(j, nj) < m;  // 两点均在棋盘内
}

bool S(LL v) {    // 当前状态v
  if (v == x0) {  // 目标状态
    return 1;
  }
  if (s.count(v)) {  // 重复状态
    return 0;
  }
  s.insert(v);  // 标记状态
  int a[3][3];
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {                                // 解压状态
      int limit = (n / 3 + (n % 3 > i)) * (m / 3 + (m % 3 > j));  // 最多数量
      a[i][j] = v / w[i * 3 + j] % kK;
      if (a[i][j] > limit) {
        return 0;
      }
    }
  }
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      if (a[i][j]) {                                                                                                                         // 当前位置有棋子可以移动
        for (int d = 0; d < 8; d++) {                                                                                                        // 枚举方向
          if (V(i, j, i + kD[d][0] * 2, j + kD[d][1] * 2)) {                                                                                 // 判断棋盘是否支持该移动
            int i1 = (i + kD[d][0] + 3) % 3, i2 = (i + kD[d][0] * 2 + 3) % 3, j1 = (j + kD[d][1] + 3) % 3, j2 = (j + kD[d][1] * 2 + 3) % 3;  // 计算相关位置
            if (a[i1][j1] && S(v - w[i * 3 + j] - w[i1 * 3 + j1] + w[i2 * 3 + j2])) {                                                        // 有棋子可以消掉
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  for (int i = 1; i < 9; i++) {  // 计算位权
    w[i] = w[i - 1] * kK;
  }
  while (fin >> k >> n >> m >> x0 >> y0) {
    x0 = w[(--x0 % 3) * 3 + --y0 % 3];  // 偏移坐标，计算终点状态
    t = 0;                              // 初始化起始状态
    s.clear();                          // 清空标记
    for (int i = 1, x, y; i <= k; i++) {
      fin >> x >> y;
      t += w[(--x % 3) * 3 + --y % 3];  // 累加位权计算起始状态
    }
    fout << (S(t) ? "Yes\n" : "No\n");
  }
  return 0;
}
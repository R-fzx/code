#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;
using Piii = pair<int, pair<int, int>>;

const int kMaxN = 50, kInf = 1e9, kD[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

ifstream fin("desert.in");
ofstream fout("desert.out");

string s[kMaxN];
int d[kMaxN][kMaxN], n, m, t, ans = -1, sx, sy;

int C() {
  priority_queue<Piii, vector<Piii>, greater<Piii>> h;                           // 小根堆
  fill(d[0], d[n], kInf);                                                        // 初始化距离
  for (h.push({0, {sx, sy}}); !h.empty();) {                                     // 加入初始状态，不断处理状态
    int x = h.top().second.first, y = h.top().second.second, l = h.top().first;  // 最短距离
    h.pop();
    if (l < d[x][y]) {       // 是新状态
      d[x][y] = l;           // 记录距离
      if (s[x][y] == '*') {  // 到达终点
        return l;
      }
      for (int i = 0; i < 8; i++) {                                        // 枚举转移
        int nx = x + kD[i][0], ny = y + kD[i][1];                          // 计算相邻位置
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && s[nx][ny] != 'X') {  // 判断位置合法
          h.push({l + (i == t ? 3 : 1), {nx, ny}});                        // 加入状态
        }
      }
    }
  }
  return -1;  // 无解
}

int main() {
  fin >> n;
  for (int i = 0; i < n; i++) {
    fin >> s[i];                             // 读入整行
    for (int j = 0; j < s[i].size(); j++) {  // 检查每个字符
      if (s[i][j] == '@') {                  // 记录起点
        sx = i, sy = j;
      }
    }
  }
  m = s[0].size();           // 计算列数
  for (t = 0; t < 8; t++) {  // 枚举风向
    ans = max(ans, C());     // 更新答案
  }
  fout << ans;
  return 0;
}